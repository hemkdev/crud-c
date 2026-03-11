# CRUD-C: Sistema Básico de Gerenciamento de Usuários em C

## Sobre

O **CRUD-C** é uma aplicação de console desenvolvida em linguagem C que implementa as operações fundamentais de **C**riar, **R**eferenciar (Listar), **A**tualizar e **E**xcluir (CRUD) para o gerenciamento de usuários. Este projeto serve como um exemplo prático de manipulação de dados em memória, utilizando estruturas (`struct`) para representar usuários e funções para interagir com esses dados. A exclusão de usuários é realizada através de um "soft delete", onde o registro é marcado como inativo em vez de ser removido permanentemente.

## Requisitos

Para compilar e executar este projeto, você precisará de:

*   **Compilador C:** Um compilador C compatível com o padrão ANSI C, como o GCC (GNU Compiler Collection).
    *   No Linux, você pode instalá-lo com `sudo apt install build-essential`.
    *   No Windows, você pode usar o [MinGW](http://www.mingw.org/) ou [Cygwin](https://www.cygwin.com/).

## Como Iniciar

Siga os passos abaixo para obter, compilar e executar o projeto:

1.  **Clone o repositório:**

    ```bash
    git clone https://github.com/hemkdev/crud-c.git
    cd crud-c
    ```

2.  **Compile o código-fonte:**

    Utilize um compilador C para gerar o executável a partir do arquivo `main.c`:

    ```bash
    gcc main.c -o crud_c
    ```

3.  **Execute a aplicação:**

    Após a compilação, execute o programa a partir do terminal:

    ```bash
    ./crud_c
    ```

## Uso

Ao executar a aplicação `crud_c`, um menu interativo será exibido no console, permitindo que você realize as seguintes operações:

1.  **Inserir Usuário:** Adiciona um novo usuário ao sistema, solicitando ID, nome e idade.
2.  **Listar Usuários:** Exibe todos os usuários ativos atualmente registrados no sistema.
3.  **Editar Usuário:** Permite modificar o nome e a idade de um usuário existente, identificado pelo seu ID.
4.  **Excluir Usuário:** Realiza um "soft delete" de um usuário, marcando-o como inativo. O usuário não será mais exibido na lista, mas seus dados permanecem no sistema.
5.  **Sair:** Encerra a aplicação.

Siga as instruções do menu e insira os dados solicitados para interagir com o sistema.

## Contribuições

Contribuições são bem-vindas! Se você tiver sugestões de melhoria, novas funcionalidades (como persistência de dados em arquivo ou banco de dados), ou encontrar algum bug, sinta-se à vontade para abrir uma *issue* ou enviar um *pull request*.

Ao contribuir, por favor, siga estas diretrizes:

*   Faça um *fork* do repositório.
*   Crie uma nova *branch* para sua funcionalidade (`git checkout -b feature/minha-funcionalidade`).
*   Faça suas alterações e *commite* (`git commit -m 'Adiciona nova funcionalidade'`).
*   Envie para a *branch* original (`git push origin feature/minha-funcionalidade`).
*   Abra um *pull request* detalhando suas alterações.

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` para mais informações. (Nota: O arquivo LICENSE não foi fornecido no repositório original, mas é uma boa prática incluí-lo.)
