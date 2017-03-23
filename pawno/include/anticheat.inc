#include "a_samp.inc"

#define Sec(%0) (%0*1000)
enum SFP_ANTICHEAT
{
	_NOVAC,
	Float:_HELTI,
};

new
	SFP[MAX_PLAYERS][SFP_ANTICHEAT];

resetVarijabli(playerid = -1)
{
	if(playerid == -1)
	{
		for(new i = 0; i < MAX_PLAYERS; ++ i)
		{
	    	SFP[i][_NOVAC] = 0; SFP[i][_HELTI] = 100;
		}
	}
	else if(playerid != -1)
	{
	    new i = playerid;
	    SFP[i][_NOVAC] = 0; SFP[i][_HELTI] = 100;
	}
}
sfp_gameInit() // resetiramo sve varijable s kojima usporedjujemo prave funkcije na nulu
{
	resetVarijabli();
	SetTimer("sfp_ac", Sec(1), true);
}
sfp_playerDisconnect(playerid)
{
    resetVarijabli(playerid);
}
forward sfp_ac();
public sfp_ac()
{
	for(new i = 0; i < MAX_PLAYERS; ++ i)
	{
	    new Float:helti;
	    GetPlayerHealth(i, helti);
	    
		if(GetPlayerMoney(i) != SFP[i][_NOVAC]) { // ANTICHEAT NOVAC NIJE ISTI SA PRAVIM NOVCEM
			ResetPlayerMoney(i);
			GivePlayerMoney(i, SFP[i][_NOVAC]);
		}
		
		if(helti > SFP[i][_HELTI]) { // PRAVI HELT JE VECI OD ANTICHEATOVOG
		    SetPlayerHealth(i, SFP[i][_HELTI]);
		}
	}
}

GetPlayerMoneyEx(playerid)
{
	return SFP[playerid][_NOVAC];
}

ResetPlayerMoneyEx(playerid)
{
	SFP[playerid][_NOVAC] = 0;
}

GivePlayerMoneyEx(playerid, iznos)
{
	if(iznos > 0) {
		SFP[playerid][_NOVAC] += iznos;
	}
	else if(iznos < 0) {
	    SFP[playerid][_NOVAC] -= iznos;
	}
}
