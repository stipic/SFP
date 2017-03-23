#include "foreach"
#include "a_samp"

/*
	 * VERZIJA : 1.0
	 
	 SetPlayerLanguage(playerid, bool:jezik)
     SCM(playerid, boja,balkan[], engleski[])
     ScmToAll(boja, balkan[], engleski[])
     GameText(playerid, balkan[], engleski[], vrijeme, stil)
     GameTextToAll(balkan[], engleski[], vrijeme, stil)
     
     * VERZIJA : 2.0
     
     GetPlayerLanguage(playerid, jezik)
     TextSet(Text:FNC, balkan[], engleski[])
     CreateDialog(id,dialogid,stil, balkanHeader[], balkanInfo[], balkanGumb[], balkanGumb2[], engHeader[], engleskiInfo[], engGumb[], engGumb2[])
     PlayerTextSet(playerid, PlayerText:FNC, balkan[], english[])
     
     * VARZIJA : 2.1
     
	 GetPlayerLanguage > IsPlayerLanguage
	 Varijabla PLAYER_JEZIK je optimizirana sa 'char'
	 Napravljena kompaktibilnost sa h_start INC - om
	 Ubacen GetPlayerLanguage za formatiranje jezika
	 
     Autor: [H]265
*/

#define  JEZIK_BALKAN   (1)
#define  JEZIK_ENGLISH  (2)

#define  SCMEx(%0,%1) \
             SendClientMessage(%0,-1,%1) // by [H]265

#define  ScmToAllEx(%0) \
             SendClientMessageToAll(-1,%0) // by [H]265

new
   PLAYER_JEZIK[MAX_PLAYERS char] = 0;

SetPlayerLanguage(id, bool:jezik) {
	 if(jezik == true)
	 {
		 PLAYER_JEZIK{id} = JEZIK_BALKAN;
		 
	 }
	 else if(jezik == false)
	 {
         PLAYER_JEZIK{id} = JEZIK_ENGLISH;
	 }
	 return true;
}

SCM(id, balkan[], english[]) {
	 if(PLAYER_JEZIK{id} == JEZIK_BALKAN) // balkan
	 {
         SCMEx(id, balkan);
	 }
	 else if(PLAYER_JEZIK{id} == JEZIK_ENGLISH) // engleski
	 {
         SCMEx(id, english);
	 }
	 return true;
}

ScmToAll(const balkan[], english[]) {
	 foreach(Player, i)
	 {
		 if(PLAYER_JEZIK{i} == JEZIK_BALKAN) // balkan
		 {
             SCMEx(i, balkan);
		 }
		 else if(PLAYER_JEZIK{i} == JEZIK_ENGLISH) // english
		 {
             SCMEx(i, english);
		 }
	 }
	 return true;
}

PlayerTextSet(playerid, PlayerText:text, balkan[], english[]) {
    if(PLAYER_JEZIK{playerid} == JEZIK_BALKAN) // balkan
	 {
        PlayerTextDrawSetString(playerid, PlayerText:text, balkan);
	 }
	 else if(PLAYER_JEZIK{playerid} == JEZIK_ENGLISH) // english
	 {
	    PlayerTextDrawSetString(playerid, PlayerText:text, english);
	 }
	return true;
}


GameText(id, balkan[], english[], vrijeme, stil) {
	 if(PLAYER_JEZIK{id} == JEZIK_BALKAN) // balkan
	 {
        GameTextForPlayer(id, balkan, vrijeme, stil);
	 }
	 else if(PLAYER_JEZIK{id} == JEZIK_ENGLISH) // english
	 {
	    GameTextForPlayer(id, english, vrijeme, stil);
	 }
	 return true;
}

GameTextToAll(balkan[], english[], vrijeme, stil) {
	 foreach(Player, i)
	 {
		if(PLAYER_JEZIK{i} == JEZIK_BALKAN) // balkan
		{
           GameTextForPlayer(i, balkan, vrijeme, stil);
		}
		else if(PLAYER_JEZIK{i} == JEZIK_ENGLISH) // english
		{
           GameTextForPlayer(i, english, vrijeme, stil);
		}
	 }
	 return true;
}

CreateDialog(id,dialogid,stil, bH[], b[], bg[], bg2[], eh[], e[], eg[], eg2[]) {
     if(PLAYER_JEZIK{id} == JEZIK_BALKAN) // balcan
     {
        ShowPlayerDialog(id,dialogid,stil,bH,b,bg,bg2);
     }
     else if(PLAYER_JEZIK{id} == JEZIK_ENGLISH) // english
     {
        ShowPlayerDialog(id,dialogid,stil,eh,e,eg,eg2);
     }
     return true;
}

TextSet(Text:FNC, b[], e[]) {
	 foreach(Player, i)
	 {
		if(PLAYER_JEZIK{i} == JEZIK_BALKAN) // balkan
		{
            TextDrawSetString(Text:FNC, b);
		}
		else if(PLAYER_JEZIK{i} == JEZIK_ENGLISH) // english
		{
            TextDrawSetString(Text:FNC, e);
		}
	 }
	 return true;
}

bool:IsPlayerLanguage(id, jezik) {
	if(PLAYER_JEZIK{id} == jezik)
	{
	   return true;
	}
	return false;
}

GetPlayerLanguage(id) {
	new
	   iText[8];
	if(IsPlayerLanguage(id, JEZIK_BALKAN))
	{
	    iText = "Balkan";
	}
	else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
	{
	    iText = "English";
	}
	return iText;
}
