# 🌐 Player Selector - Biblioteca para Interação entre Jogadores no SA:MP e OpenMP

**Player Selector** é uma biblioteca desenvolvida para servidores de SA:MP (San Andreas Multiplayer) e OpenMP que permite a interação entre jogadores de maneira simples e eficiente. A biblioteca contém duas versões: uma para SA:MP e outra para OpenMP. Ambas as versões têm funcionalidades semelhantes, mas com pequenas adaptações para cada ambiente de servidor. 

## ✨ Funcionalidades

- **Seleção de Jogadores:** Permite que jogadores selecionem outros jogadores através de um clique.
- **Interação Entre Jogadores:** Após a seleção, os jogadores podem interagir entre si.
- **Compatibilidade:** Disponível para servidores SA:MP e OpenMP. Ambas as versões têm a mesma funcionalidade básica, mas com pequenas diferenças no código para adaptar aos dois tipos de servidores.
- **Fácil Integração:** A biblioteca é fácil de integrar no seu servidor com funções simples.
  
## 📚 Como Usar

### 🛠️ Instalação

1. Baixe ou clone o repositório.
2. Inclua o arquivo `player_selector.inc` no seu projeto.
3. Para SA:MP, utilize a versão destinada ao SA:MP. Para OpenMP, utilize a versão destinada ao OpenMP.

Ambas as versões podem ser usadas de forma semelhante, com apenas pequenas alterações no código. A função de seleção de jogadores e a lógica de interação entre eles permanecem as mesmas.

### 🖥️ Exemplo de Uso

#### Para SA:MP

```pawn
#include <player_selector>

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys == KEY_NO) {
        ActiveSelectPlayer(playerid);
    }
    return true;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, CLICK_SOURCE:source) {
    if(source == CLICK_SOURCE_SKIN) {
        new 
            message[30 + MAX_PLAYER_NAME + 3 + 1];
        format(message, sizeof message, "Jogador Selecionado: %s(ID:%d)", GetPlayerNameEx(clickedplayerid), clickedplayerid);
        SendClientMessage(playerid, -1, message);
    }
    return true;
}
```

## 🔧 Funções Principais

- **`ActiveSelectPlayer(playerid)`** - Ativa a funcionalidade de seleção de jogador.
- **`DisableSelectPlayer(playerid)`** - Desativa a funcionalidade de seleção de jogador.
- **`HasActivedSelection(playerid)`** - Verifica se o jogador tem uma seleção ativa.
- **`OnPlayerClickPlayer(playerid, targetid, clickSource)`** - Função para implementar a lógica de interação após o clique em um jogador.

## 🎥 Demonstração

Assista ao vídeo de demonstração [aqui](https://youtu.be/1iIK-_E0kU4) para ver como o sistema de seleção de jogadores funciona em tempo real no servidor SA:MP e OpenMP.

## 🤝 Contribuições

Se você tiver sugestões, correções ou melhorias para a biblioteca, fique à vontade para abrir uma *issue* ou enviar um *pull request*.
