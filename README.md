# Algoritmos de Dados

Este repositório contém implementações em Python de vários algoritmos de dados comumente usados em ciência da computação, incluindo:

- [Pilha](#Pilha)
- [Listas Encadeadas](#Listas_Encadeadas)
- [Listas Duplamente Encadeadas](#instruções_de_instalação)
- [Árvore Binária](#Árvore_Binária)

## Pilha<br>


<br>
Uma pilha é uma estrutura de dados em que os elementos são armazenados em uma ordem "last-in, first-out" (LIFO), ou seja, o último elemento adicionado é o primeiro a ser removido. As pilhas são usadas em muitos algoritmos de processamento de linguagens naturais, como a análise sintática.<br><br>



## Listas Encadeadas<br>


<br>
Uma lista encadeada é uma estrutura de dados em que cada elemento da lista é um nó que contém um valor e um ponteiro para o próximo elemento da lista. As listas encadeadas são usadas em muitos algoritmos de pesquisa e ordenação.<br><br>



## Listas Duplamente Encadeadas<br>


<br>
Uma lista duplamente encadeada é uma estrutura de dados em que cada elemento da lista é um nó que contém um valor, um ponteiro para o próximo elemento e um ponteiro para o elemento anterior. As listas duplamente encadeadas permitem a navegação na lista em ambas as direções, o que pode ser útil em muitos algoritmos de processamento de texto.

Esperamos que essas implementações sejam úteis para quem está aprendendo sobre algoritmos de dados e sua implementação em Python. Sinta-se à vontade para contribuir com novas implementações e melhorias!<br>


## Árvore Binária<br>

<br>
Uma árvore binária é uma estrutura de dados em que cada nó pode ter até dois filhos, chamados de filho esquerdo e filho direito. Cada nó pode ser visto como a raiz de sua própria subárvore. Árvores binárias são usadas em muitos algoritmos de busca, como árvores de busca binária.

*Mais informações*: 

Para o método "show_tree()" da class ArvoreBinariaBusca, é necessário instalar o Path: Graphviz
- Esse método fornecerá uma imagem para visualização da árvore instanciada.<br>


### Siga as instruções:


<br>

1. Acesse o site do [graphviz](https://graphviz.org/download/) para download.

2. Baixe o arquivo: graphviz-8.0.2 (32-bit) EXE installer [sha256] - Versão windows

3. Instale-o com a opção "Path" para Usuário, assim não será necessário realizar essa configuração manual
    - Essa configuração permitirá que o seu terminal execute o comando: dot -Tpng nome_do_arquivo.dot -o nome_da_imagem_gerada.png
    - O manual para entender o que essa pode ser acessado em: [Documentação Graphviz](http://webgraphviz.com/)
