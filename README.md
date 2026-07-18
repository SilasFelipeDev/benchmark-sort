# benchmark-sort 

Um projeto de estudos em C voltado para a implementação, análise e comparação de algoritmos de ordenação.

O objetivo deste repositório não é servir como portfólio, mas como uma biblioteca pessoal de consulta e um laboratório para aprofundar conhecimentos em algoritmos, análise de complexidade e organização de projetos em C.

## Objetivos 
- Implementar diversos algoritmos de ordenação do zero.
- Comparar desempenho entre algoritmos.
- Medir tempo de execução.
- Contabilizar comparações e trocas.
- Estudar complexidade de tempo e espaço.
- Organizar o código em múltiplos arquivos seguindo boas práticas.

## Como baixar (sem precisar compilar)

Se você só quer rodar o programa, sem instalar GCC, Make ou qualquer ambiente de desenvolvimento, baixe o executável pronto na página de [Releases](https://github.com/SilasFelipeDev/benchmark-sort/releases).

1. Baixe o arquivo correspondente ao seu sistema operacional:
   - **Windows:** `benchmark-sort-windows.exe`
   - **Linux:** `benchmark-sort-linux`
2. **Windows:** dê dois cliques no arquivo para executar ("executar assim mesmo" caso o microsoft defender bloqueie), ou execute via terminal (navegue até o diretório do arquivo):
```bash
.\benchmark-sort-windows.exe
```
    
3. **Linux:** abra um terminal na pasta onde baixou o arquivo e rode:
```bash
   chmod +x benchmark-sort-linux
   ./benchmark-sort-linux
```

> Quer entender o código, modificar algo ou compilar você mesmo? Veja a seção [Como executar (desenvolvimento)](#como-executar) abaixo.

## Como executar

### Pré-requisitos

- GCC (compilador C)
- Make

### Compilando

No terminal, na raiz do projeto:

```bash
make
```

Isso vai compilar os arquivos-fonte (gerando os `.o` dentro de `build/`) e criar o executável `benchmark.exe` na raiz do projeto.

Para limpar os artefatos gerados (arquivos `.o` e o executável):

```bash
make clean
```

### ⚠️ Atenção, usuários Windows

Se você instalou o Make via MinGW, é bem provável que o comando `make` **não seja reconhecido**, porque o executável se chama `mingw32-make` em vez de `make`.

Se isso acontecer, você tem duas opções:
1. Rodar `mingw32-make` no lugar de `make` sempre que este README indicar `make`.
2. Localizar o executável `mingw32-make` (geralmente dentro da pasta `bin` da instalação do MinGW), copiá-lo e colar a cópia na mesma pasta, com o nome `make.exe`.

Se nenhuma das opções funcionar, pesquise por `"mingw32-make vs make"` - é um problema comum e bem documentado.

**Nota: Linux / macOS**

Não testado ainda nesse projeto, mas o comando `make` deve funcionar nativamente, sem os ajustes acima.

### Executando

Após compilar, rode: 

**Windows:**
```bash
.\benchmark
```

**Linux / macOS:**
```bash
./benchmark
```

## Algoritmos

### Simples

- [x] Bubble Sort
- [x] Selection Sort
- [x] Insertion Sort

### Intermediários 

- [ ] Shell Sort
- [x] Merge Sort 
- [x] Quick Sort
- [ ] Heap Sort 

### Não baseados em comparação

- [ ] Counting Sort
- [ ] Radix Sort 
- [ ] Bucket Sort

## Estrutura
```text
benchmark-sort/
├── build/
├── include/
├── src/
├── README.md
├── Makefile
└── .gitignore
```

## Solucionando problemas (desenvolvimento)

### VS Code não encontra os headers (`benchmark.h`, `utils.h`, etc.)

Se ao abrir o projeto no VS Code você notar `vetor`, `bench`, `TAMANHO_MIN` e outros identificadores sublinhados em vermelho - mesmo o projeto compilando normalmente pelo terminal - o problema não é o código, é de configuração do editor. 

O IntelliSense do VS Code (responsável por sublinhar erros em tempo real) não lê o `Makefile`. Ele tem sua própria lista de pastas onde procurar por headers, configurada separadamente, e por padrão não sabe que deve olhar dentro de `include/`. Sem achar `benchmark.h` e `utils.h`, ele trata os tipos e protótipos vindo de lá como desconhecidos e sublinha tudo que depende deles. 

**Solução:** criar um arquivo de configuração do IntelliSense apontando para a pasta `include/`: 

1. No VS Code, abra a paleta de comandos (`Ctrl+Shift+P`)
2. Busque por `C/C++: Edit Configurations (UI)` 
3. Em **"includePath"**, escreva `include`, que é a pasta com os arquivos .h
4. Isso vai gerar um arquivo `.vscode/c_cpp_properties.json`

> **Nota:** a pasta `.vscode/` está no `.gitignore` propositalmente, porque esse arquivo de configuração costuma conter caminhos específicos da sua máquina (como a localização do compilador). Por isso cada pessoa que for desenvolver no projeto precisa gerar a sua própria configuração - ela não vem pronta no repositório.

## Funcionalidades implementadas

- Geração de diferentes tipos de vetores (aleatório, ordenado, invertido)
- Estatísticas de execução (comparações, trocas e tempo)
- Interface em terminal com menu interativo

## Futuras funcionalidades

- Comparação entre algoritmos (rodar o mesmo vetor em dois algoritmos diferentes e comparar os resultados lado a lado)
- Exportar relatório de benchmark para arquivo `.txt`
- Documentação individual de cada algoritmo (pasta `docs/`, explicando a lógica e complexidade de cada um de forma didática)

## Licença 

MIT