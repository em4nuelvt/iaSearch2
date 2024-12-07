# Comparação de Desempenho entre Algoritmos A* e Busca Gulosa

# Introdução
Na Inteligência Artificial, algoritmos de busca informada utilizam conhecimento específico do problema para encontrar soluções de forma mais eficiente. Diferentemente das buscas cegas, estes algoritmos usam heurísticas para estimar o custo até o objetivo, permitindo decisões mais inteligentes sobre qual caminho seguir.

# Objetivo 
Implementar e comparar dois diferentes algoritmos de busca informada (A* e Busca Gulosa) aplicados ao problema do labirinto.

<a name="labirinto"></a>
<p align="center">
  <img src="./img/tabuleiro.png" alt="Labirinto">
  <br>
  <em>Figura 1: Disposição do labirinto</em>
</p>


Observa-se pela disposição do labirinto que o melhor/menor caminho a ser encontrado, partindo de 'U' e alcançando 'E', é: 
U V Q L M N I H C D E

# Implementação
A implementação foi realizada em C++. O labirinto foi modelado como um grafo não direcionado onde cada posição representa um nó. A função heurística utilizada calcula a distância euclidiana entre cada nó e o objetivo.


## Características do grafo
Para aplicar algoritmos de busca informada foi nessário ajustar a estrutura do grafo. Como os algortimos de busca ordenada utilizam as informações do problema para encotrar a solução, foi necessário adicinar o peso às arestas do grafo, simulando a distancia de uma posição até outra. Dessa forma, o grafo utilizado é um grafo não direcionado, ponderado com arestas de peso 1 para qualquer nó vizinho.

## Calculo da função h(n)
A funão h(n) indica a distância em linha reta do nó n até a meta,ou seja, a estimativa de custo de n até a meta.
Para calcular a função h(n), utilizou-se a distância euclidiana, calculada a partir dos valores das variações na vertical(y) e na horizontal(x) de uma posição qualquer do labirinto até a meta estabelecida (no caso 'E'), considerando que 1 quadrado em x ou em y representam 1 unidade de distância, assim como os pesos das arestas do grafo. 

<a name="labirinto"></a>
<p align="center">
  <img src="./img/deuclidiana.png" alt="Labirinto">
  <br>
  <em>Figura 2: Fórmula para calcular a distância euclidiana</em>
</p>


Dessa forma, ao calcular as respectivas distancias para os pares [x,y], foi atribuido os valores a uma estrutura de hash que, dado o valor de uma posição do labirinto (representada por um caractere) é atribuida como chave para um valor real de distância, representando assim a função h(n). Isso foi feito no C++ com a estrutura unordered_map da biblioteca padrão (STL), com um tipo representado por <char,double>. 

## Descrição dos Algoritmos Implementados

### A* (A Estrela)
O A* é um algoritmo de busca que combina informações do custo do caminho já percorrido (g) e uma estimativa do custo até o objetivo (h).

- **Funcionamento**:
  1. **Função de Avaliação**: f(n) = g(n) + h(n)
     - g(n): custo real do caminho do início até o nó n
     - h(n): estimativa heurística do custo de n até o objetivo
  2. **Estruturas**: 
     - Fila de prioridade (openSet) ordenada por f(n)
     - Conjunto de nós visitados (closedSet)
     - Mapas para custos (gScore) e reconstrução do caminho
  3. **Garantias**:
     - Completude: Sempre encontra uma solução se existir
     - Otimalidade: Garante o caminho ótimo se h(n) for admissível

### Busca Gulosa
A Busca Gulosa é um algoritmo que toma decisões baseando-se apenas na heurística, ignorando o custo do caminho já percorrido.

- **Funcionamento**:
  1. **Função de Avaliação**: f(n) = h(n)
     - h(n): estimativa heurística do custo até o objetivo
  2. **Estruturas**:
     - Fila de prioridade ordenada por h(n)
     - Conjunto de nós visitados
     - Mapa para reconstrução do caminho
  3. **Características**:
     - Mais simples e rápido que o A*
     - Não garante caminho ótimo

# Medições de Desempenho

## Tempo de Execução
- Medido usando a biblioteca chrono
- Contabilizado em microsegundos

## Consumo de Memória
Para ambos os algoritmos, foi calculado:
- Número máximo de nós na fila de prioridade
- Número de nós visitados
- Tamanho dos mapas auxiliares
- Memória total utilizada em bytes

## Completude e Optimalidade
- Verificação se encontram solução
- Análise da qualidade do caminho encontrado

# Análise dos Resultados

## Testes para Análise de Desempenho

#### Teste 1:
- **A***
  - Máximo de nós na fila: 4
  - Nós visitados: 21
  - Tamanho dos mapas: 41
  - Memória total: 518 bytes
  - Caminho: U V Q L M N I H C D E
  - Tempo: 131 microsegundos

- **Busca Gulosa**
  - Máximo de nós na fila: 5
  - Nós visitados: 16
  - Tamanho dos mapas: 15
  - Memória total: 151 bytes
  - Caminho: U V Q L M N I H C D E
  - Tempo: 90 microsegundos

#### Teste 1:
- **A***
  - Máximo de nós na fila: 4
  - Nós visitados: 21
  - Tamanho dos mapas: 41
  - Memória total: 518 bytes
  - Caminho: U V Q L M N I H C D E
  - Tempo: 131 microsegundos

- **Busca Gulosa**
  - Máximo de nós na fila: 5
  - Nós visitados: 16
  - Tamanho dos mapas: 15
  - Memória total: 151 bytes
  - Caminho: U V Q L M N I H C D E
  - Tempo: 90 microsegundos



## Observações Encontradas
- **Optimalidade**: Ambos algoritmos encontraram o caminho ótimo neste caso específico
- **Tempo de Execução**: Busca Gulosa foi mais rápida que o A*
- **Consumo de Memória**: A* consumiu mais memória devido ao controle adicional de custos
- **Completude**: Ambos encontraram solução em todos os testes

## Análise Comparativa dos Algoritmos
- **Tempo**: Busca Gulosa mostrou-se mais rápida por sua simplicidade
- **Memória**: A* utilizou mais memória devido aos mapas adicionais
- **Completude**: Ambos completos para este problema
- **Optimalidade**: Ambos ótimos neste caso específico

### Razões para o Comportamento Observado
1. **Estrutura do Problema**:
   - Labirinto relativamente pequeno
   - Heurística bem informada (distância euclidiana)
   - Poucos obstáculos e caminhos alternativos

2. **Características do A***:
   - Maior overhead por controlar g(n)
   - Garantia de otimalidade com custo de memória
   - Exploração mais sistemática

3. **Características da Busca Gulosa**:
   - Mais leve por usar apenas h(n)
   - Menor overhead de processamento
   - Pode falhar em problemas mais complexos

# Conclusão
A implementação e análise dos algoritmos A* e Busca Gulosa mostrou que, para este problema específico, a Busca Gulosa apresentou melhor desempenho em tempo e memória. No entanto, é importante notar que isso se deve às características particulares do problema e da heurística utilizada.


# Compilação e Execução

O projeto possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

---

# Autores
- **Anielly Gonçalves**: anielly@aluno.cefetmg.br
- **Emanuel Vieira Tavares**:emanuel@aluno.cefetmg.br 

  DECOM-DV/CEFET-MG.
  2024/2.