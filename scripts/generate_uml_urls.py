#!/usr/bin/env python3
"""将 PlantUML 源码编码为 PlantUML 在线服务的 URL，并生成对应的图片链接。"""

import zlib
import base64
import os

# PlantUML 自定义 base64 编码表
PLANTUML_BASE64 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"

def encode_plantuml(text: str) -> str:
    """将 PlantUML 源码编码为 URL 安全的压缩字符串。"""
    # 移除 BOM（如果存在）
    if text.startswith('\ufeff'):
        text = text[1:]
    
    data = text.encode('utf-8')
    compressed = zlib.compress(data)
    # 去掉 zlib 头部（2字节）和尾部（4字节），只保留 raw deflate
    compressed = compressed[2:-4]
    
    # 转换为 PlantUML 自定义 base64
    result = []
    for i in range(0, len(compressed), 3):
        chunk = compressed[i:i+3]
        b0 = chunk[0] if len(chunk) > 0 else 0
        b1 = chunk[1] if len(chunk) > 1 else 0
        b2 = chunk[2] if len(chunk) > 2 else 0
        
        n = (b0 << 16) | (b1 << 8) | b2
        
        result.append(PLANTUML_BASE64[(n >> 18) & 0x3F])
        result.append(PLANTUML_BASE64[(n >> 12) & 0x3F])
        if len(chunk) > 1:
            result.append(PLANTUML_BASE64[(n >> 6) & 0x3F])
        if len(chunk) > 2:
            result.append(PLANTUML_BASE64[n & 0x3F])
    
    return ''.join(result)


def generate_md_links(docs_dir: str, output_md: str):
    """读取 docs/ 目录下的 .puml 文件，生成带图片链接的 Markdown 片段。"""
    lines = []
    
    for name in ["use_case", "class_diagram", "sequence_diagram"]:
        puml_path = os.path.join(docs_dir, f"{name}.puml")
        if not os.path.exists(puml_path):
            print(f"警告：{puml_path} 不存在，跳过")
            continue
        
        with open(puml_path, "r", encoding="utf-8") as f:
            content = f.read()
        
        encoded = encode_plantuml(content)
        url = f"http://www.plantuml.com/plantuml/png/{encoded}"
        
        # 中文标题映射
        titles = {
            "use_case": "用例图",
            "class_diagram": "类图（MVC架构）",
            "sequence_diagram": "序列图（双人对战流程）"
        }
        
        title = titles.get(name, name)
        
        lines.append(f"### {title}")
        lines.append(f"![{title}]({url})")
        lines.append("")
        lines.append(f"> PlantUML 源码见 `docs/{name}.puml`")
        lines.append("")
    
    return "\n".join(lines)


if __name__ == "__main__":
    # 项目根目录是 scripts/ 的上一级
    project_root = os.path.dirname(os.path.dirname(__file__))
    docs_dir = os.path.join(project_root, "docs")
    result = generate_md_links(docs_dir, "")
    print(result)
