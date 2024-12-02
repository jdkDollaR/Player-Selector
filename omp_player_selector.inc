/*


⠀⠀⠀⢸⣦⡀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣏⠻⣶⣤⡶⢾⡿⠁⠀⢠⣄⡀⢀⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣀⣼⠷⠀⠀⠁⢀⣿⠃⠀⠀⢀⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠴⣾⣯⣅⣀⠀⠀⠀⠈⢻⣦⡀⠒⠻⠿⣿⡿⠿⠓⠂⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠉⢻⡇⣤⣾⣿⣷⣿⣿⣤⠀⠀⣿⠁⠀⠀⠀⢀⣴⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠸⣿⡿⠏⠀⢀⠀⠀⠿⣶⣤⣤⣤⣄⣀⣴⣿⡿⢻⣿⡆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠟⠁⠀⢀⣼⠀⠀⠀⠹⣿⣟⠿⠿⠿⡿⠋⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢳⣶⣶⣿⣿⣇⣀⠀⠀⠙⣿⣆⠀⠀⠀⠀⠀⠀⠛⠿⣿⣦⣤⣀⠀⠀
⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⠿⠋⠁⠀⣹⣿⠳⠀⠀⠀⠀⠀⠀⢀⣠⣽⣿⡿⠟⠃
⠀⠀⠀⠀⠀⢰⠿⠛⠻⢿⡇⠀⠀⠀⣰⣿⠏⠀⠀⢀⠀⠀⠀⣾⣿⠟⠋⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠀⠀⣰⣿⣿⣾⣿⠿⢿⣷⣀⢀⣿⡇⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠉⠁⠀⠀⠀⠀⠙⢿⣿⣿⠇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀
        Criador/Desenvolvedor ['jdkDollar'] - 02/12/2024


        Informações de contato/Contact Information:
        Discord: @jdkdollar
        Github: github.com/jdkDollaR


        // --
        Descrição em Português sobre a include:
        O *Player Selector* é um sistema projetado para servidores SA:MP que facilita a interação entre jogadores ao permitir que objetos sejam clicados para selecionar um alvo.  
        Cada jogador recebe um objeto dinâmico anexado a ele, que pode ser clicado para realizar ações específicas. O sistema utiliza a Streamer Plugin para gerenciar os objetos e oferece suporte para personalização.  

        Description in English about include:
        The *Player Selector* is a system designed for SA:MP servers, enabling players to interact with each other by clicking on dynamic objects assigned to each user.  
        Each player has a dynamic object attached to them, which can be clicked to perform specific actions. The system leverages the Streamer Plugin for object management and supports customization.  



*/

#include    <streamer>                          // Version: 2.9.6 | Download: https://github.com/samp-incognito/samp-streamer-plugin/releases


#define     CLICK_SOURCE_SKIN       (CLICK_SOURCE:2)

static enum PLAYER_CLICK_STRUCT {
    STREAMER_TAG_OBJECT:Click_Object_ID,
    bool:Click_Active
}
static PlayerClick_Data[MAX_PLAYERS][PLAYER_CLICK_STRUCT];
static const CLICK_OBJECT_MODEL = 18963;

/*
 ___      _    _ _       
| _ \_  _| |__| (_)__ ___
|  _/ || | '_ \ | / _(_-<
|_|  \_,_|_.__/_|_\__/__/
                         
*/
public OnPlayerConnect(playerid) {
    
    if(!IsValidDynamicObject(PlayerClick_Data[playerid][Click_Object_ID])) {
        PlayerClick_Data[playerid][Click_Object_ID] = CreateDynamicObject(CLICK_OBJECT_MODEL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    }
    for(new i = 0; i < 10; i++) SetDynamicObjectMaterial(PlayerClick_Data[playerid][Click_Object_ID], i, 0, "none", "none", 0x00000000);
    
    AttachDynamicObjectToPlayer(PlayerClick_Data[playerid][Click_Object_ID], playerid, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    Streamer_SetIntData(STREAMER_TYPE_OBJECT, PlayerClick_Data[playerid][Click_Object_ID], E_STREAMER_EXTRA_ID, playerid);

    #if defined PlayerSelector_OnPlayerConnect
        PlayerSelector_OnPlayerConnect(playerid);
    #endif
    return true;
}

public OnPlayerDisconnect(playerid, reason) {
    #pragma unused reason

    if(IsValidDynamicObject(PlayerClick_Data[playerid][Click_Object_ID])) DestroyDynamicObject(PlayerClick_Data[playerid][Click_Object_ID]);
    PlayerClick_Data[playerid][Click_Active] = false;

    #if defined PlayerSelector_OnPlayerDisconnect
        PlayerSelector_OnPlayerDisconnect(playerid, reason);
    #endif
    return true;
}

public OnPlayerSelectDynamicObject(playerid, STREAMER_TAG_OBJECT:objectid, modelid, Float:x, Float:y, Float:z) {
    if(PlayerClick_Data[playerid][Click_Active]) {
        new 
            targetid = Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_EXTRA_ID);
 
        if(IsPlayerConnected(targetid)) {
            if(PlayerClick_Data[targetid][Click_Object_ID] == objectid) {
                PlayerClick_Data[playerid][Click_Active] = false;
                
                CancelEdit(playerid);
                CallLocalFunction("OnPlayerClickPlayer", "ddd", playerid, targetid, CLICK_SOURCE_SKIN);
            }
        }
        return true; 
    }

    #if defined PlayerSelector_OnPlayerSelectDynamicObject
        PlayerSelector_OnPlayerSelectDynamicObject(playerid, objectid, modelid, x, y, z);
    #endif
    return true;
}


/*
 ___ _           _       
/ __| |_ ___  __| |__ ___
\__ \  _/ _ \/ _| / /(_-<
|___/\__\___/\__|_\_\/__/
                         
*/
stock bool:HasActivedSelection(playerid) {
    if(PlayerClick_Data[playerid][Click_Active]) return true;
        else return false;
}

stock ActiveSelectPlayer(playerid) {
    PlayerClick_Data[playerid][Click_Active] = true;
    SelectObject(playerid);
    return true;
}
stock DisableSelectPlayer(playerid) {
    PlayerClick_Data[playerid][Click_Active] = false;
    CancelEdit(playerid);
    return true;
}

/*
 __  __                    
|  \/  |__ _ __ _ _ ___ ___
| |\/| / _` / _| '_/ _ (_-<
|_|  |_\__,_\__|_| \___/__/
                           
*/

// OnPlayerConnect
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect PlayerSelector_OnPlayerConnect

#if defined PlayerSelector_OnPlayerConnect
    forward PlayerSelector_OnPlayerConnect(playerid);
#endif


// OnPlayerDisconnect
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect PlayerSelector_OnPlayerDisconnect

#if defined PlayerSelector_OnPlayerDisconnect
    forward PlayerSelector_OnPlayerDisconnect(playerid, reason);
#endif

// OnPlayerSelectDynamicObject
#if defined _ALS_OnPlayerSelectDynObject
    #undef OnPlayerSelectDynamicObject
#else
    #define _ALS_OnPlayerSelectDynObject
#endif
#define OnPlayerSelectDynamicObject PlayerSelector_OnPlayerSelectDynamicObject

#if defined PlayerSelector_OnPlayerSelectDynamicObject
    forward PlayerSelector_OnPlayerSelectDynamicObject(playerid, STREAMER_TAG_OBJECT objectid, modelid, Float:x, Float:y, Float:z);
#endif