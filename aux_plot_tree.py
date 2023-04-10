import os
import subprocess

# Cria o modelo correto que o Graphviz utiliza para poder gerar a imagem do gravo.
# elementos tem uma formatação específica.
def graphviz(elementos):
    conteudo = "digraph G {\n"
    for elemento in elementos:
        conteudo += "    " + elemento + "\n"
    conteudo += "}"
    return conteudo

# Função que executa um comando do terminal via código.
# Este comando gera a imagem da arvore binária.
def image_tree(dot_file, output_file):
    comando = f"dot -Tpng {dot_file} -o {output_file}"
    try:
        subprocess.run(comando, shell=True, check=True)
        # print(f"Imagem gerada com sucesso: {output_file}")
    except subprocess.CalledProcessError as e:
        print(f"Erro ao gerar imagem: {e}")


# Crie a função que irá excluir o arquivo dot
def delete_file_dot(arquivo):
    try:
        os.remove(arquivo)
        # print(f"Arquivo {arquivo} excluído com sucesso!")
    except FileNotFoundError:
        print(f"Arquivo {arquivo} não encontrado.")