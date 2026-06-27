"""通过 Kroki API 下载 PlantUML 渲染的 UML 图到本地 figures/ 目录。"""
import os, requests

os.makedirs('figures', exist_ok=True)

files = {
    'use_case': '用例图',
    'class_diagram': '类图（MVC架构）',
    'sequence_diagram': '序列图（双人对战流程）'
}

for name, title in files.items():
    puml_path = f'docs/{name}.puml'
    with open(puml_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    print(f'渲染 {title}...')
    resp = requests.post('https://kroki.io/plantuml/png',
                         data=content.encode('utf-8'),
                         headers={'Content-Type': 'text/plain; charset=utf-8'},
                         timeout=30)
    
    if resp.status_code == 200:
        out_path = f'figures/{name}.png'
        with open(out_path, 'wb') as f:
            f.write(resp.content)
        print(f'  OK {out_path} ({len(resp.content)} bytes)')
    else:
        print(f'  FAIL HTTP {resp.status_code}: {resp.text[:200]}')

print('完成！')
