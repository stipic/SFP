/*
	======================= SERVER FOR PILOTS =======================
	by: Kristijan Stipić
	Date: 01.08.2012. (started)

	Links:

	http://balkan-samp.com/forum/index.php?topic=61961.0
	http://balkan-samp.com/forum/index.php?topic=70336.0
	
*/

#tryinclude "a_samp"
#tryinclude "a_mysql"
#tryinclude "vehicles"
#tryinclude "jezik"
#tryinclude "sscanf2"
#tryinclude "flood"
#tryinclude "foreach"
#tryinclude "YSI\y_commands"
#tryinclude "YSI\y_master"
#tryinclude "YSI\y_ini"

#define SQL_HOST "127.0.0.1"
#define SQL_KORISNIK "root"
#define SQL_LOZINKA ""
#define SQL_BAZA "sfp"

#undef MAX_PLAYERS
#define MAX_PLAYERS (50)
#define MAXAFK (900) // 15 minuta

#define CAR_BAZA ("Cars/%d.ini")
#define AVIO_BAZA ("Aviokompanije/%d.ini")
#define EVIDENCIJA_ADMINA ("Evidencija/AdminKomande.log")
#define EVIDENCIJA_PRIJAVA ("Evidencija/Prijave.log")
#define EVIDENCIJA_PORUKA ("Evidencija/PrivatnePoruke.log")
#define EVIDENCIJA_ADMIN_CHAT ("Evidencija/AdminChat.log")
#define EVIDENCIJA_NOVAC_SLANJE ("Evidencija/SlanjeNovca.log")
#define EVIDENCIJA_CHEATERS ("Evidencija/CheatLog.log")
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))
#define randomEx(%0,%1) \
           (random((%1) - (%0)) + (%0)) // randomEx(minimalno,maksimalno)
#define Freeze(%0,%1) \
           TogglePlayerControllable((%0), !(%1))
#define MAX_LOGIN_POKUSAJA (3)
#define MAX_FUEL (100)
#define MAX_HOUSES (1500)
#define INVALID_HOUSE_ID (-1)
#define MAX_CARS (1000)
#define INVALID_CAR_ID (-1)
#define MAX_XMASTREES (100)
#define MAX_SNOW_OBJECTS (5)
#define UPDATE_INTERVAL  (750)
#define MAX_AIRLINES (6)
#define TEXT_VRIJEME (15)

#define siva "{B4B4B4}"
#define error "{F50000}"
#define bijela "{FFFFFF}"
#define zuta "{FFFF00}"
#define ljubicasta "{A000FF}"
#define zelena "{00FF3C}"
#define narancasta "{FF6E00}"

#define TEAM_CIVILNI_PILOTI 0xFFFFFFFF
#define TEAM_MEDICINSKI_PILOTI 0xBEBEBEFF
#define TEAM_VOJNI_PILOTI 0xFF9600FF
#define TEAM_TAXI 0xEBFF00FF
#define TEAM_KAMIONI 0x007DFFFF
#define TEAM_MOREPLOVAC 0x00FFF0FF

enum _BAZA_PODATAKA_
{
	ID,
	Nick[MAX_PLAYER_NAME],
	Email[50],
	Lozinka[200],
	Spol,
	Grupa,
	Iskljucen,
	Preporuka,
	Admin,
	Novac,
	Bodovi,
	Bodovi_[3],
	Radio[3],
	Ubrzanje[3],
	Sati,
	Minute,
	Zadnji_Login,
	Kljuc_Kuca,
	Kljuc_Vozilo[3],
	Registracija,
	Logiran,
	Tankirao[2],
	Popravio[2],
	Smrt,
	Prekid,
	Upozorenja,
	Pohvale,
	Float:Pozicija[3],
	Vip,
	HouseSpawn,
	Vlasnik_Kompanije,
	Vip_Vrijeme,
	Fix,
	Fill,
	AvioSpawn,
	AirlineUgovor,
	Shamal,
	Dodo,
	Beagle,
	Hydra,
    Nevada,
    At400s,
    Andromada,
    Float:trenutnaX,
    Float:trenutnaY
};

enum _KUCA_BAZA_
{
	ID,
	Float:h_Pi[3],
	Float:h_In[3],
	h_Vlasnik[MAX_PLAYER_NAME],
	h_Locked,
	h_Cijena,
	h_Vw,
	h_Int
};

enum _CAR_BAZA_
{
	ID,
    v_Vlasnik[MAX_PLAYER_NAME],
    Float:v_Pos[4],
    v_Cijena,
    v_Model,
    v_Locked,
    v_Boja[2],
    v_PaintJob,
    v_Airline,
    v_Posao
};

enum XmasTrees
{
    XmasTreeX,
    Float:XmasX,
    Float:XmasY,
    Float:XmasZ,
    XmasObject1,
    XmasObject2,
    XmasObject3,
    XmasObject4,
    XmasObject5,
    XmasObject6,
    XmasObject7,
    XmasObject8,
    XmasObject9,
    XmasObject10

};

enum _AVIO_KOMPANIJE_
{
	ID,
	av_Vlasnik[MAX_PLAYER_NAME],
	av_Ime[24],
	av_Zaposlenik_1[MAX_PLAYER_NAME],
	av_Zaposlenik_2[MAX_PLAYER_NAME],
	av_Zaposlenik_3[MAX_PLAYER_NAME],
	av_Zaposlenik_4[MAX_PLAYER_NAME],
	av_Zaposlenik_5[MAX_PLAYER_NAME],
	av_Baza,
	av_Novac,
	Float:av_Spawn[4],
	av_Bodovi,
	av_Vozilo[15],
	av_Upgrade,
	av_Zaposlenik_6[MAX_PLAYER_NAME],
	av_Zaposlenik_7[MAX_PLAYER_NAME],
	av_Zaposlenik_8[MAX_PLAYER_NAME],
	av_Zaposlenik_9[MAX_PLAYER_NAME],
	av_Zaposlenik_10[MAX_PLAYER_NAME],
	av_Inicijali[5]
};

enum _TDINFO_
{
	 _TD@INFO[256],
	 _TD@PRIKAZANI[256],
	 _TD@TIMER,
	 Text:_TD@TEXTDRAW,
	 _TD@BROJAC,
	 _TD@BRZINA,
	 _TD@KORAK
};

new
   PlayerInfo[MAX_PLAYERS][_BAZA_PODATAKA_], Data[50], FailLogin[MAX_PLAYERS char], bool:posao[MAX_PLAYERS char], CP[MAX_PLAYERS], bool:snowOn[MAX_PLAYERS char],
   bool:PlayerLogin[MAX_PLAYERS char], Team[MAX_PLAYERS char], bool:playerSmrt[MAX_PLAYERS char], LOCAL_TIMER, TIMER_LOAD[MAX_PLAYERS], Treepos[MAX_XMASTREES][XmasTrees], cTime,
   PlayerText:TABLA[13][MAX_PLAYERS], Float:Udaljenost[MAX_PLAYERS][3], Gorivo[MAX_VEHICLES], TIMER_GORIVO[MAX_VEHICLES], Bonus[MAX_PLAYERS char], snowObject[MAX_PLAYERS][MAX_SNOW_OBJECTS],
   Text:INFO_BOX[MAX_PLAYERS][2], info_box[MAX_PLAYERS char], online_sec[MAX_PLAYERS char], Text:Sat, sat_ = (0), min_ = (0), work_vehicle[MAX_PLAYERS] = (-1), av_call_avio[MAX_PLAYERS char],
   zadnje_vozilo[MAX_PLAYERS] = (-1), upozorenje[MAX_PLAYERS char] = (0), bool:mute[MAX_PLAYERS char] = (false), inhouse[MAX_PLAYERS], av_call_time[MAX_PLAYERS char], Float:RUTA_DUZINA[MAX_PLAYERS],
   bool:freeze[MAX_PLAYERS char], Float:SPEC_POS[MAX_PLAYERS][3], SPEC_VW[MAX_PLAYERS], SPEC_INT[MAX_PLAYERS char], bool:IsSpecing[MAX_PLAYERS char], updateTimer[MAX_PLAYERS char], PlayerText:con__,
   bool:IsBeingSpeced[MAX_PLAYERS char], spectatorid[MAX_PLAYERS], bool:block_pm[MAX_PLAYERS char], bool:nevidljiv[MAX_PLAYERS char], vrijemeEx_ = (-1), otkaz_slot[MAX_PLAYERS char], a_b__[MAX_PLAYERS char],
   ruta_min[MAX_PLAYERS char], ruta_sec[MAX_PLAYERS char], HouseIcon[MAX_HOUSES], AvioKompanija[MAX_AIRLINES][_AVIO_KOMPANIJE_], PlayerText:MONEY_BAR[3], hydraFire[MAX_PLAYERS char], Float:load_bar[MAX_PLAYERS],
   bool:move[MAX_PLAYERS char], bool:moveON[MAX_PLAYERS char], HouseInfo[MAX_HOUSES][_KUCA_BAZA_], HousePickup[MAX_HOUSES], Text3D:HouseLabel[MAX_HOUSES], dm[MAX_PLAYERS char], serverRestart,
   CarInfo[MAX_CARS][_CAR_BAZA_], COS_VOZILA[MAX_CARS], Text:work_Info[MAX_PLAYERS], vMods[MAX_CARS][12], vrijeme__ = (0), vrijemeTime[2], bool:cheatLog[MAX_PLAYERS char], timerFreeze[MAX_PLAYERS char],
   bool:prijaveLog[MAX_PLAYERS char], bool:adminLog[MAX_PLAYERS char], bool:pmLog[MAX_PLAYERS char], bool:sendMoneyLog[MAX_PLAYERS char], av_call_vlasnik[MAX_PLAYERS] = (INVALID_PLAYER_ID), Float:bonus__[MAX_PLAYERS],
   LOCAL_TIMER_2, Float:bonus_[MAX_PLAYERS], mySQL,
   bool:antiTAB[MAX_PLAYERS char], Text:MainMenu[4], Text:Nagib[MAX_PLAYERS], Area, l_connect[MAX_PLAYER_NAME], Zastita__[MAX_PLAYERS char], bool:playerSpawned[MAX_PLAYERS char], Text:loading_[MAX_PLAYERS][3],
   Float:AutoHelti[MAX_PLAYERS], AFK[MAX_PLAYER_NAME char], bool:AFK2[MAX_PLAYER_NAME char], AVR = (0), AAFK = (1), Sekunde = (0), bool:izbjegavanje_[MAX_PLAYERS char], bool:v_fix__[MAX_PLAYERS char],
   bool:anti_Kicker[MAX_PLAYERS char], Float:AC_oldPos[MAX_PLAYERS][3], AC_oldPlayerState[MAX_PLAYERS], CanCheckABX[MAX_PLAYERS], bool:CanCheckAirBreak[MAX_PLAYERS], NeedCheckTuningAB[MAX_PLAYERS], txtTime[MAX_PLAYERS char],
   PlayerText:langOdabir[MAX_PLAYERS][2], PlayerText:naslov__, PlayerText:posaoOdabir[MAX_PLAYERS][8], choosePosao[MAX_PLAYERS char], INFOBOX[MAX_PLAYERS][_TDINFO_], Text:sfpInfo[MAX_PLAYERS], txtS[MAX_PLAYERS char];

new balcanInfo[26][256] =
{
	 "Dobrodosli na server, koristite /help za listu komandi",
	 "Ovaj server je otvoren 15.12.2012. godine rekord servera je 30 igraca",
	 "Na ovom serveru deathmatch je strogo zabranjen!",
	 "Koristenje cheata, iskoristavanje bugova ili koristenje zabranjenih modova je zabranjeno!",
	 "Avion, kamion ili taxi vam je spor? Kupite si boost na /store",
	 "Trebate brzi popravak ili gorivo kupite si kitove za popravke i gorivo na /store",
	 "Za bolji uzitak igre koristite /radio",
	 "Lista online administratora se nalazi na komandi /admins",
	 "Zelite kontaktirati drugog igraca anonimno, kucajte /pm",
	 "Lista otvorenih avio kompanija i njihovih vlasnika nazalzi se na komandi /airlines",
	 "Ukoliko uocite nekoga da krsi pravila koristite /report da ga prijavite",
	 "Za svaki posao score vam je drugaciji tj. statistika je odvojena",
	 "Zabranjeno je traziti administrator poziciju!",
	 "Za promjenu spawn mjesta ili lozinke kucajte /account",
	 "Aviokompanije mogu imati vlastitu zracnu luku i vlastite avione!",
	 "Za promjenu posla kucajte /kill",
	 "Kako bi pregledali cijelu statistiku kucajte /stats",
	 "Tagove u nicku imaju samo clanovi avio kompanija!",
	 "Imate viska novca? Kupite si kucu, vozilo ili otvorite vlastitu avio kompaniju",
	 "Avio kompaniju mozete otvoriti samo ako imati 200+ scorova",
	 "Avio kopaniju otvorite tako da kucate komandu /createairline",
	 "Postanite VIP igrac tako sto donirate i pomognete da server ostane upaljen",
	 "Lista vip igraca nalazi se na komandi /vips",
	 "VIP igraci imaju puno povlastica za vise informacija pitajte administratore",
	 "Strogo je zabranjeno reklamiranje drugih servera i stranica na ovom serveru!",
	 "Ovo je zabavni server tako ce i ostati, zabavite se!"
};

new engInfo[7][256] =
{
	 "Welcome to SFP server use /help to see list of some commands",
	 "Deathmatch is not allowed on this server",
	 "If you wanna to change your job use /kill",
	 "Use /store to buy some stuff",
	 "Use /vips to see all online VIP players",
	 "If you saw someone use cheats use /report",
	 "To see list of all airelines use /airlines"
};

enum
{
	DIALOG_LOGIN,
	DIALOG_REGISTER,
	DIALOG_EMAIL,
	DIALOG_SPAWN_MJESTO,
	DIALOG_ADMINS,
	DIALOG_STORE,
	DIALOG_STORE_BUY,
	DIALOG_RADIO,
	DIALOG_STORE_SELL,
	DIALOG_ADMIN_INFO,
	DIALOG_ADMIN_CHECK,
	DIALOG_ADMIN_MUTED,
	DIALOG_ADMIN_TELE,
	DIALOG_HOUSE,
	DIALOG_VEHICLE_CAT,
	DIALOG_VEHICLE_MOTORI,
	DIALOG_VEHICLE_AUTI,
	DIALOG_VEHICLE_AUTI_2,
	DIALOG_PLAYER_KLIK,
	DIALOG_ADMIN_SETTINGS,
	DIALOG_LISTA_KOMPANIJA,
	DIALOG_CREATE_AIRLINE,
	DIALOG_AIRLINE_STATS,
	DIALOG_AIRLINE,
	DIALOG_AIRLINE_OTKAZ,
	DIALOG_EDIT_AIRLINE,
	DIALOG_LISTA,
	DIALOG_ZAPOSLENIK,
	DIALOG_NOVO_IME,
	DIALOG_AIRLINE_INVITE,
	DIALOG_AIRLINE_DELTE,
	DIALOG_MEMBERS,
	DIALOG_DONIRAJ,
	DIALOG_UPGRADE_AIRLINE,
	DIALOG_AIRLINE_VEH,
	DIALOG_USPJESNI_LOGIN,
	DIALOG_ENDROUTE,
	DIALOG_INICIJALI
}

main(){}

stock Float:GetDistanceBetweenPoints(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
    x1 -= (x2);
    y1 -= (y2);
    z1 -= (z2);
    return floatsqroot((x1 * x1) + (y1 * y1) + (z1 * z1));
}

stock createInfo(Text:TD_, playerid, string[256], brzina_ = 100)
{
      KillTimer(INFOBOX[playerid][_TD@TIMER]);
	  INFOBOX[playerid][_TD@TEXTDRAW] = (TD_);
	  INFOBOX[playerid][_TD@BRZINA] = (brzina_);
      if(string[0] == ' ') string[0] = '_';
      format(INFOBOX[playerid][_TD@PRIKAZANI], 256, "%c", string[0]);
	  TextDrawSetString(INFOBOX[playerid][_TD@TEXTDRAW], INFOBOX[playerid][_TD@PRIKAZANI]);
	  TextDrawShowForPlayer(playerid, INFOBOX[playerid][_TD@TEXTDRAW]);
	  INFOBOX[playerid][_TD@KORAK] = (0); strdel(string, 0, 0);
	  format(INFOBOX[playerid][_TD@INFO], 256, "%s", string);
	  INFOBOX[playerid][_TD@BROJAC] = (0);
	  INFOBOX[playerid][_TD@TIMER] = SetTimerEx("_TD_INFO_", INFOBOX[playerid][_TD@BRZINA], true, "i", playerid);
	  return (false);
}

forward _TD_INFO_(playerid);
public _TD_INFO_(playerid)
{
	 if((INFOBOX[playerid][_TD@BROJAC] < strlen(INFOBOX[playerid][_TD@INFO])) && (INFOBOX[playerid][_TD@KORAK] == 0))
	 {
           if(INFOBOX[playerid][_TD@INFO][INFOBOX[playerid][_TD@BROJAC]+1] == ' ') INFOBOX[playerid][_TD@INFO][INFOBOX[playerid][_TD@BROJAC]+1] = '_';
           format(INFOBOX[playerid][_TD@PRIKAZANI], 256, "%s%c", INFOBOX[playerid][_TD@PRIKAZANI], INFOBOX[playerid][_TD@INFO][INFOBOX[playerid][_TD@BROJAC]+1]);
           strdel(INFOBOX[playerid][_TD@INFO], INFOBOX[playerid][_TD@BROJAC], INFOBOX[playerid][_TD@BROJAC]);
	       TextDrawSetString(INFOBOX[playerid][_TD@TEXTDRAW], INFOBOX[playerid][_TD@PRIKAZANI]);
           TextDrawShowForPlayer(playerid, INFOBOX[playerid][_TD@TEXTDRAW]);
           ++ INFOBOX[playerid][_TD@BROJAC];
           return (true);
     }
     else if((INFOBOX[playerid][_TD@BROJAC] >= strlen(INFOBOX[playerid][_TD@INFO])) && (INFOBOX[playerid][_TD@KORAK] == 0))
     {
		   KillTimer(INFOBOX[playerid][_TD@TIMER]);
		   ++ INFOBOX[playerid][_TD@KORAK];
		   INFOBOX[playerid][_TD@BROJAC] = strlen(INFOBOX[playerid][_TD@PRIKAZANI]);
		   INFOBOX[playerid][_TD@TIMER] = SetTimerEx("_TD_INFO_", 2000, true, "i", playerid);
		   return (true);
     }
     else if((INFOBOX[playerid][_TD@BROJAC] <= strlen(INFOBOX[playerid][_TD@PRIKAZANI])) && (INFOBOX[playerid][_TD@KORAK] == 1))
     {
           KillTimer(INFOBOX[playerid][_TD@TIMER]);
           ++ INFOBOX[playerid][_TD@KORAK];
           INFOBOX[playerid][_TD@TIMER] = SetTimerEx("_TD_INFO_", INFOBOX[playerid][_TD@BRZINA], true, "i", playerid);
           return (true);
     }
     else if((INFOBOX[playerid][_TD@BROJAC] <= strlen(INFOBOX[playerid][_TD@PRIKAZANI])) && (INFOBOX[playerid][_TD@KORAK] == 2))
     {
		   format(INFOBOX[playerid][_TD@PRIKAZANI], 128, "%s", INFOBOX[playerid][_TD@PRIKAZANI]);
           strdel(INFOBOX[playerid][_TD@PRIKAZANI], INFOBOX[playerid][_TD@BROJAC]-1, INFOBOX[playerid][_TD@BROJAC]);
		   TextDrawSetString(INFOBOX[playerid][_TD@TEXTDRAW], INFOBOX[playerid][_TD@PRIKAZANI]);
           TextDrawShowForPlayer(playerid, INFOBOX[playerid][_TD@TEXTDRAW]);
           -- INFOBOX[playerid][_TD@BROJAC];
           if(INFOBOX[playerid][_TD@BROJAC] <= 0)
           {
               KillTimer(INFOBOX[playerid][_TD@TIMER]);
               TextDrawHideForPlayer(playerid, INFOBOX[playerid][_TD@TEXTDRAW]);
           }
           return (true);
     }
	 return (false);
}

stock setVehicleScore(playerid)
{
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 519)
	{
		 ++PlayerInfo[playerid][Shamal];
	}
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 593)
	{
		 ++PlayerInfo[playerid][Dodo];
	}
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 511)
	{
		 ++PlayerInfo[playerid][Beagle];
	}
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 520)
	{
		 ++PlayerInfo[playerid][Hydra];
	}
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 553)
	{
		 ++PlayerInfo[playerid][Nevada];
	}
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 577)
	{
		 ++PlayerInfo[playerid][At400s];
	}
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 592)
	{
		 ++PlayerInfo[playerid][Andromada];
	}
	UpdatePlayer(playerid);
}

stock SFP_SetPlayerHealth(playerid,Float:helti)
{
	SetPlayerHealth(playerid,helti);
	return (true);
}
stock SFP_SetPlayerArmour(playerid,Float:armor)
{
	SetPlayerArmour(playerid,armor);
	return (true);
}

stock SFP_SetPlayerPos( playerid, Float:pPosX, Float:pPosY, Float:pPosZ )
{
    CanCheckABX 	[ playerid ] = false;
    CanCheckAirBreak[ playerid ] = false;
    NeedCheckTuningAB [ playerid ] = 5;
	SetPlayerPos( playerid, pPosX, pPosY, pPosZ );
	CanCheckABX 	[ playerid ] = true;
}

stock SFP_PutPlayerInVehicle( playerid, pvehicleid, pseatid )
{
    CanCheckABX 	[ playerid ] = false;
    CanCheckAirBreak[ playerid ] = false;
    NeedCheckTuningAB [ playerid ] = 5;
    PutPlayerInVehicle( playerid, pvehicleid, pseatid );
    CanCheckABX 	[ playerid ] = true;
}

stock AC_AirBreakReset( playerid )
{
	AC_oldPos[playerid][0] = 0.0;
	AC_oldPos[playerid][1] = 0.0;
	AC_oldPos[playerid][2] = 0.0;
}

stock SFP_SetVehicleToRespawn(idvozila)
{
    foreach(Player, i)
   	{
   	    new idvoz = GetPlayerVehicleID(i);
   	    if(idvoz == idvozila)
   	    {
  	    	v_fix__{i} = (true);
  	    	SetVehicleToRespawn(idvozila);
  	    	v_fix__{i} = (true);
  	    	return (true);
   	    }
   	}
   	return (false);
}

stock bool:BigMission(vehicleid)
{
	if(GetVehicleModel(vehicleid) == 577 || GetVehicleModel(vehicleid) == 592) return (true);
	else return (false);
}

stock IsAirlineHaveEmptyVehicleSlot(avio_id)
{
     for(new s=0; s<15; ++s)
     {
		 if(AvioKompanija[avio_id][av_Vozilo][s] == -1)
		 {
			 return (s);
		 }
     }
     return (-1);
}

stock PayCheck(playerid, bool:bonus, duzina)
{
	new vehicleid = GetPlayerVehicleID(playerid), zarada = (0), avio_id = (-1), ukupno = (0);
    avio_id = IsPlayerInAirline(playerid, GetName(playerid));
    if(CivilniAvion(vehicleid) || CarInfo[vehicleid][v_Posao] == 1)
    {
	   if(bonus == true) { GivePlayerMoneyEx(playerid, 1500); ukupno = (1500); }
	   if(avio_id != -1) { zarada = randomEx((duzina*3)+1500, (duzina*3)+6000); ukupno += (zarada); AvioKompanija[avio_id][av_Novac] += (ukupno/2); AvioKompanija[avio_id][av_Bodovi] ++; UpdateAirline(avio_id); }
	   else if(avio_id == -1) { zarada = randomEx(duzina*3, (duzina*3)+3); ukupno += (zarada); }
    }
    else if(MedicinskiAvion(vehicleid) || CarInfo[vehicleid][v_Posao] == 2)
    {
	   if(bonus == true) { GivePlayerMoneyEx(playerid, 2500); ukupno = (2500); }
	   if(avio_id != -1) { zarada = randomEx((duzina*4)+1000, (duzina*4)+5000); ukupno = (ukupno+zarada); AvioKompanija[avio_id][av_Novac] += (ukupno/2); AvioKompanija[avio_id][av_Bodovi] ++; UpdateAirline(avio_id); }
	   else if(avio_id == -1) { zarada = randomEx(duzina*4, (duzina*4)+3); ukupno += (zarada); }
    }
    else if(VojniAvion(vehicleid) || VojniHeli(vehicleid) || CarInfo[vehicleid][v_Posao] == 3)
    {
	   if(bonus == true) { GivePlayerMoneyEx(playerid, 2500); ukupno = (2500); }
	   if(avio_id != -1) { zarada = randomEx((duzina*5)+1500, (duzina*5)+6000); ukupno = (ukupno+zarada); AvioKompanija[avio_id][av_Novac] += (ukupno/2); AvioKompanija[avio_id][av_Bodovi] ++; UpdateAirline(avio_id); }
	   else if(avio_id == -1) { zarada = randomEx(duzina*5, (duzina*5)+3); ukupno += (zarada); }
    }
    else if(TaxiAuto(vehicleid))
	{
	     if(bonus == true)  { GivePlayerMoneyEx(playerid, 1500); ukupno = (1500); }
		 zarada = randomEx(duzina*5, (duzina*5)+1000);
		 ukupno += (zarada);
    }
    else if(Truck(vehicleid))
	{
	    if(bonus == true) { GivePlayerMoneyEx(playerid, 2500); ukupno = (2500); }
		zarada = randomEx(duzina*7, (duzina*7)+1);
		ukupno += (zarada);
	}
    else if(IsABoat(vehicleid))
	{
	    if(bonus == true)  { GivePlayerMoneyEx(playerid, 1500); ukupno = (1500); }
		zarada = randomEx(duzina*7, (duzina*7)+1000);
		ukupno += (zarada);
	}
	novost(GetName(playerid), "je zavrsio svoju rutu");
    GivePlayerMoneyEx(playerid, zarada);
	return (ukupno);
}

forward UpdateSnow(playerid);
public UpdateSnow(playerid)
{
   if(!snowOn{playerid}) return (false);
   new Float:pPos[3];
   GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
   for(new i = 0; i < MAX_SNOW_OBJECTS; i++) SetDynamicObjectPos(snowObject[playerid][i], pPos[0] + random(25), pPos[1] + random(25), pPos[2] - 5);
   return (true);
}

stock IsPlayerInAirline(playerid, ime[])
{
	for(new a=0; a<=MAX_AIRLINES; ++a)
	{
		format(Data, (sizeof Data), AVIO_BAZA, a);
		if(fexist(Data))
		{
			if(strcmp(AvioKompanija[a][av_Zaposlenik_1], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_2], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_3], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_4], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_5], ime, false) == 0 || PlayerInfo[playerid][Vlasnik_Kompanije] == a
			|| strcmp(AvioKompanija[a][av_Zaposlenik_6], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_7], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_8], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_9], ime, false) == 0 || strcmp(AvioKompanija[a][av_Zaposlenik_10], ime, false) == 0)
			{
			   return (a);
			}
		}
	}
	return (-1);
}

stock bool:zabranaParkiranja(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 200, 1905.6875,-2493.8491,13.1953)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, 1433.1927,1461.5234,10.8203)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, -1319.0356,-102.0342,14.1484)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, 12.9164,-44.6520,5.9598)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, 2385.0313,-199.3353,27.9807)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, 274.5427,2500.3860,16.9631)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, 238.3186,-1801.1532,4.5662)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 200, -149.3726,-3191.0906,23.4154)) return (true);
	else return (false);
}

stock CreateChristmasTree2(Float:x,Float:y,Float:z)
{
    for(new i = 0; i < sizeof(Treepos); i++)
    {
      if(Treepos[i][XmasTreeX] == 0)
      {
            Treepos[i][XmasTreeX]=1;
            Treepos[i][XmasX]=x;
            Treepos[i][XmasY]=y;
            Treepos[i][XmasZ]=z;
            Treepos[i][XmasObject1] = CreateDynamicObject(19076, x, y, z-1.0,0,0,300);
            Treepos[i][XmasObject2] = CreateDynamicObject(19054, x, y+1.0, z-0.4,0,0,300);
            Treepos[i][XmasObject3] = CreateDynamicObject(19058, x+1.0, y, z-0.4,0,0,300);
            Treepos[i][XmasObject4] = CreateDynamicObject(19056, x, y-1.0, z-0.4,0,0,300);
            Treepos[i][XmasObject5] = CreateDynamicObject(19057, x-1.0, y, z-0.4,0,0,300);
            Treepos[i][XmasObject6] = CreateDynamicObject(19058, x-1.5, y+1.5, z-1.0,0,0,300);
            Treepos[i][XmasObject7] = CreateDynamicObject(19055, x+1.5, y-1.5, z-1.0,0,0,300);
            Treepos[i][XmasObject8] = CreateDynamicObject(19057, x+1.5, y+1.5, z-1.0,0,0,300);
            Treepos[i][XmasObject9] = CreateDynamicObject(19054, x-1.5, y-1.5, z-1.0,0,0,300);
            Treepos[i][XmasObject10] = CreateDynamicObject(3526, x, y, z-1.0,0,0,300);
            return (true);
       }
    }
    return (false);
}

stock CreateSnow(playerid)
{
    if(snowOn{playerid}) return (false);
    new Float:pPos[3];
    GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
    for(new i = 0; i < MAX_SNOW_OBJECTS; i++) snowObject[playerid][i] = CreateDynamicObject(18864, pPos[0] + random(25), pPos[1] + random (25), pPos[2] - 5, random(100), random(100), random(100), -1, -1, playerid);
    snowOn{playerid} = true;
    updateTimer{playerid} = SetTimerEx("UpdateSnow", UPDATE_INTERVAL, true, "i", playerid);
    return (true);
}

stock DeleteSnow(playerid)
{
    if(!snowOn{playerid}) return (false);
    for(new i = 0; i < MAX_SNOW_OBJECTS; i++) DestroyDynamicObject(snowObject[playerid][i]);
    KillTimer(updateTimer{playerid});
    snowOn{playerid} = false;
    return (true);
}

stock CreateChristmasTree1(Float:X, Float:Y, Float:Z)
{
	CreateDynamicObject(3472,X+0.28564453,Y+0.23718262,Z+27.00000000,0.00000000,0.00000000,230.48021);
	CreateDynamicObject(664,X+0.20312500,Y+0.01171875,Z+-3.00000000,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,X+0.45312500,Y+0.51562500,Z+4.00000000,0.00000000,0.00000000,69.7851562);
	CreateDynamicObject(3472,X+0.65136719,Y+1.84570312,Z+17.00000000,0.00000000,0.00000000,41.863403);
	CreateDynamicObject(7666,X+0.34130859,Y+0.16845703,Z+45.00000000,0.00000000,0.00000000,298.12524);
	CreateDynamicObject(7666,X+0.34082031,Y+0.16796875,Z+45.00000000,0.00000000,0.00000000,27.850342);
	CreateDynamicObject(3472,X+0.45312500,Y+0.51562500,Z+12.00000000,0.00000000,0.00000000,350.02441);
	CreateDynamicObject(3472,X+0.45312500,Y+0.51562500,Z+7.00000000,0.00000000,0.00000000,30.0805664);
	CreateDynamicObject(3472,X+0.45312500,Y+0.51562500,Z+22.00000000,0.00000000,0.00000000,230.47119);
	CreateDynamicObject(1262,X+0.15039062,Y+0.57128906,Z+29.45285416,0.00000000,0.00000000,162.90527);
}

stock udb_hash(buf[])
{
    new length = strlen(buf), s1 = 1, s2 = 0, n;
    for (n=0; n<length; n++)
    {
       s1 = (s1 + buf[n]) % 65521;
       s2 = (s2 + s1)     % 65521;
    }
    return (s2 << 16) + s1;
}

stock GetPlayerMoneyEx(playerid) return PlayerInfo[playerid][Novac];

stock GivePlayerMoneyEx(playerid, iznos)
{
	return (iznos ? PlayerInfo[playerid][Novac] += (iznos) : PlayerInfo[playerid][Novac] -= (iznos));
}

stock ResetPlayerMoneyEx(playerid) return PlayerInfo[playerid][Novac] = (0);

stock bool:IsACosVeh(vehicleid)
{
	if(vehicleid == COS_VOZILA[vehicleid]) return (true);
	else return (false);
}

stock buyVehicle(playerid, modelid, bool:motor)
{
   new Float:Pos[3], vehicleid;
   if(motor == true)
   {
	  new cijena = motoriCijena(modelid);
      if(GetPlayerMoneyEx(playerid) < cijena) return SCM(playerid, ""#siva"Nemas dovoljno novaca.", ""#siva"You don't have enought money.");
      else if(posao{playerid} == true) return SCM(playerid, ""#siva"* Radis trenutno, koristi /cancel i onda nastavi sa kupnjom.", ""#siva"You work right now, use /cancel and then use /vehicles");
      else if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"* U vozilu si, izadi prvo!", ""#siva"* You are in vehicle!");
      else if(inhouse[playerid] != (MAX_HOUSES+1)) return SCM(playerid, ""#siva"* U kuci si!", ""#siva"* You are in house.");
      else if(zabranaParkiranja(playerid) == true) return SCM(playerid, ""#siva"* Ne smijes kupovati vozila blizu zracnoj luci!", ""#siva"* You can't buy vehicle near airports!");
      for(new slot=0;slot<3;++slot)
      {
	     if(PlayerInfo[playerid][Kljuc_Vozilo][slot] == INVALID_CAR_ID)
         {
			GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
			GivePlayerMoneyEx(playerid, -cijena);
			vehicleid = createVehID();
			COS_VOZILA[vehicleid] = AddStaticVehicle(modelid, Pos[0], Pos[1], Pos[2], 0.0000, -1, -1);
			format(CarInfo[COS_VOZILA[vehicleid]][v_Vlasnik], MAX_PLAYER_NAME, "%s", GetName(playerid));
			CarInfo[COS_VOZILA[vehicleid]][v_Pos][0] = (Pos[0]); CarInfo[COS_VOZILA[vehicleid]][v_Pos][1] = (Pos[1]);
			CarInfo[COS_VOZILA[vehicleid]][v_Pos][2] = (Pos[2]);
			CarInfo[COS_VOZILA[vehicleid]][v_PaintJob] = (-1);
			CarInfo[COS_VOZILA[vehicleid]][v_Posao] = (0);
			CarInfo[COS_VOZILA[vehicleid]][v_Airline] = (-1);
			CarInfo[COS_VOZILA[vehicleid]][v_Cijena] = (cijena);
			CarInfo[COS_VOZILA[vehicleid]][v_Model] = (modelid);
			PlayerInfo[playerid][Kljuc_Vozilo][slot] = (COS_VOZILA[vehicleid]);
			SFP_PutPlayerInVehicle(playerid, COS_VOZILA[vehicleid], 0);
			UpdateVehicle(COS_VOZILA[vehicleid]);
			UpdatePlayer(playerid);
			break;
         }
         if(slot == 2 && PlayerInfo[playerid][Kljuc_Vozilo][slot] != INVALID_CAR_ID) return SCM(playerid, ""#siva"Vec imas 3 vozila!", ""#siva"You already have 3 vehicles!");
      }
   }
   else if(motor == false)
   {
	  new cijena = autiCijena(modelid);
      if(GetPlayerMoneyEx(playerid) < cijena) return SCM(playerid, ""#siva"Nemas dovoljno novaca.", ""#siva"You don't have enought money.");
      else if(posao{playerid} == true) return SCM(playerid, ""#siva"* Radis trenutno, koristi /cancel i onda nastavi sa kupnjom.", ""#siva"You work right now, use /cancel and then use /vehicles");
      else if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"* U vozilu si, izadi prvo!", ""#siva"* You are in vehicle!");
      else if(inhouse[playerid] != (MAX_HOUSES+1)) return SCM(playerid, ""#siva"* U kuci si!", ""#siva"* You are in house.");
      else if(zabranaParkiranja(playerid) == true) return SCM(playerid, ""#siva"* Ne smijes kupovati vozila blizu zracnoj luci!", ""#siva"* You can't buy vehicle near airports!");
	  for(new slot=0;slot<3;++slot)
      {
	     if(PlayerInfo[playerid][Kljuc_Vozilo][slot] == INVALID_CAR_ID)
         {
			GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
			GivePlayerMoneyEx(playerid, -cijena);
			vehicleid = createVehID();
			COS_VOZILA[vehicleid] = AddStaticVehicle(modelid, Pos[0], Pos[1], Pos[2], 0.0000, -1, -1);
			format(CarInfo[COS_VOZILA[vehicleid]][v_Vlasnik], MAX_PLAYER_NAME, "%s", GetName(playerid));
			CarInfo[COS_VOZILA[vehicleid]][v_Pos][0] = (Pos[0]); CarInfo[COS_VOZILA[vehicleid]][v_Pos][1] = (Pos[1]);
			CarInfo[COS_VOZILA[vehicleid]][v_Pos][2] = (Pos[2]);
			CarInfo[COS_VOZILA[vehicleid]][v_PaintJob] = (-1);
			CarInfo[COS_VOZILA[vehicleid]][v_Posao] = (0);
			CarInfo[COS_VOZILA[vehicleid]][v_Airline] = (-1);
			CarInfo[COS_VOZILA[vehicleid]][v_Cijena] = (cijena);
			CarInfo[COS_VOZILA[vehicleid]][v_Model] = (modelid);
			PlayerInfo[playerid][Kljuc_Vozilo][slot] = (COS_VOZILA[vehicleid]);
			SFP_PutPlayerInVehicle(playerid, COS_VOZILA[vehicleid], 0);
			UpdateVehicle(COS_VOZILA[vehicleid]);
			UpdatePlayer(playerid);
			break;
         }
         if(slot == 2 && PlayerInfo[playerid][Kljuc_Vozilo][slot] != INVALID_CAR_ID) return SCM(playerid, ""#siva"Vec imas 3 vozila!", ""#siva"You already have 3 vehicles!");
      }
   }
   return (true);
}

stock createVehID()
{
	new id;
    for(new i=0;i<MAX_CARS;++i)
    {
       new checkNum;
       checkNum = i+1;
       format(Data, (sizeof Data), CAR_BAZA ,checkNum);
       if(!fexist(Data))
       {
	      id = (checkNum);
	      break;
       }
	}
	return (id);
}

stock createAvio()
{
	new id = (-1);
    for(new i=0;i<=MAX_AIRLINES;++i)
    {
       new checkNum;
       checkNum = i+1;
       format(Data, (sizeof Data), AVIO_BAZA ,checkNum);
       if(!fexist(Data))
       {
	      id = checkNum;
	      break;
       }
	}
	return (id);
}

stock SetPlayerCheckPoint(playerid, Float:X, Float:Y, Float:Z, Float:velicina, cpid)
{
    Udaljenost[playerid][0] = (X); Udaljenost[playerid][1] = (Y); Udaljenost[playerid][2] = (Z);
    CP[playerid] = (cpid);
    return SetPlayerRaceCheckpoint(playerid, 1, X, Y, Z, X, Y, Z, velicina);
}

stock GetPlayerJob(playerid)
{
	new job[50];
	if(Team{playerid} == 1) { job = "C. pilot"; }
	else if(Team{playerid} == 2) { job = "Med. pilot"; }
	else if(Team{playerid} == 3) { job = "Mil. pilot"; }
	else if(Team{playerid} == 4) { job = "Taxi"; }
	else if(Team{playerid} == 6) { job = "Trucker"; }
	else if(Team{playerid} == 7) { job = "Sailor"; }
	
	return (job);
}

stock GivePlayerScore(playerid, bodovi)
{
    if(Team{playerid} == 1) { PlayerInfo[playerid][Bodovi] += (bodovi); UpdatePlayer(playerid); }
	else if(Team{playerid} == 2) { PlayerInfo[playerid][Bodovi] += (bodovi); UpdatePlayer(playerid); }
	else if(Team{playerid} == 3) { PlayerInfo[playerid][Bodovi] += (bodovi); UpdatePlayer(playerid); }
	else if(Team{playerid} == 4) { PlayerInfo[playerid][Bodovi_][0] += (bodovi); UpdatePlayer(playerid); }
	else if(Team{playerid} == 6) { PlayerInfo[playerid][Bodovi_][1] += (bodovi); UpdatePlayer(playerid); }
	else if(Team{playerid} == 7) { PlayerInfo[playerid][Bodovi_][2] += (bodovi); UpdatePlayer(playerid); }
	return (true);
}

stock GetPlayerScoreEx(playerid)
{
    if(Team{playerid} == 1) return PlayerInfo[playerid][Bodovi];
	else if(Team{playerid} == 2) return PlayerInfo[playerid][Bodovi];
	else if(Team{playerid} == 3) return PlayerInfo[playerid][Bodovi];
	else if(Team{playerid} == 4) return PlayerInfo[playerid][Bodovi_][0];
	else if(Team{playerid} == 6) return PlayerInfo[playerid][Bodovi_][1];
	else if(Team{playerid} == 7) return PlayerInfo[playerid][Bodovi_][2];
	return (true);
}

stock bool:IsVehicleInUse(vehicleid)
{
	foreach(Player, i)
	{
	   if(GetPlayerVehicleID(i) == vehicleid || GetVehicleTrailer(GetPlayerVehicleID(i)))
	   {
		  return (true);
	   }
	}
	return (false);
}

stock SetPlayerColorByJob(playerid)
{
	new hex[30];
	if(Team{playerid} == 1) // CIVLILNI
	{
        SetPlayerColor(playerid, TEAM_CIVILNI_PILOTI);
        format(hex, 30, "{FFFFFF}");
	}
	else if(Team{playerid} == 2) // MEDICINSKI
	{
        SetPlayerColor(playerid, TEAM_MEDICINSKI_PILOTI);
        format(hex, 30, "{D1D3D4}");
	}
	else if(Team{playerid} == 3) // VOJNI
	{
         SetPlayerColor(playerid, TEAM_VOJNI_PILOTI);
         format(hex, 30, "{FF9600}");
	}
	else if(Team{playerid} == 4) // TAXI
	{
         SetPlayerColor(playerid, TEAM_TAXI);
         format(hex, 30, "{FFFF00}");
	}
	else if(Team{playerid} == 6) // KAMIJONDJIJA
	{
         SetPlayerColor(playerid, TEAM_KAMIONI);
         format(hex, 30, "{009EEF}");
	}
	else if(Team{playerid} == 7) // MOREPLOVAC
	{
         SetPlayerColor(playerid, TEAM_MOREPLOVAC);
         format(hex, 30, "{00FFEF}");
	}
	return (hex);
}

stock bool:IsPlayerHaveBoost(playerid)
{
	if(strcmp(PlayerInfo[playerid][Ubrzanje], "Da", true) == 0) return (true);
	else return (false);
}

stock GivePlayerBoost(playerid, bool:daj_uzmi)
{
	if(daj_uzmi == true)
	{
       format(PlayerInfo[playerid][Ubrzanje], 3, "Da");
	}
	else if(daj_uzmi == false)
	{
	   format(PlayerInfo[playerid][Ubrzanje], 3, "Ne");
	}
	return (true);
}

stock motoriProdaja(id)
{
	switch (id)
	{
		case (509): return (509);
		case (481): return (481);
		case (510): return (510);
		case (462): return (462);
		case (448): return (448);
		case (581): return (581);
		case (522): return (522);
		case (461): return (461);
		case (521): return (521);
		case (523): return (523);
		case (463): return (463);
		case (586): return (586);
		case (468): return (468);
		case (471): return (471);
	}
	return (-1);
}

stock motoriCijena(id)
{
	switch (id)
	{
		case (509): return (10000);
		case (481): return (15000);
		case (510): return (17000);
		case (462): return (45000);
		case (448): return (45000);
		case (581): return (120000);
		case (522): return (450000);
		case (461): return (250000);
		case (521): return (350000);
		case (523): return (200000);
		case (463): return (250000);
		case (586): return (300000);
		case (468): return (350000);
		case (471): return (170000);
	}
	return (-1);
}

stock autiProdaja(id)
{
	switch(id)
	{
		case (400): return (400);
		case (401): return (401);
		case (402): return (402);
		case (404): return (404);
		case (405): return (405);
		case (410): return (410);
		case (411): return (411);
		case (412): return (412);
		case (413): return (413);
		case (415): return (415);
		case (418): return (418);
		case (419): return (419);
		case (421): return (421);
		case (422): return (422);
		case (424): return (424);
		case (426): return (426);
		case (429): return (429);
		case (434): return (434);
		case (436): return (436);
		case (439): return (439);
		case (440): return (440);
		case (444): return (444);
		case (445): return (445);
		case (451): return (451);
		case (458): return (458);
		case (459): return (459);
		case (466): return (466);
		case (467): return (467);
		case (470): return (470);
		case (474): return (474);
		case (475): return (475);
		case (477): return (477);
		case (478): return (478);
		case (479): return (479);
		case (480): return (480);
		case (482): return (482);
		case (483): return (483);
		case (489): return (489);
		case (491): return (491);
		case (492): return (492);
		case (494): return (494);
		case (495): return (495);
		case (496): return (496);
		case (500): return (500);
		case (506): return (506);
		case (507): return (507);
		case (516): return (516);
		case (517): return (517);
		case (518): return (418);
		case (526): return (526);
		case (527): return (527);
		case (535): return (535);
		case (540): return (540);
		case (541): return (541);
		case (542): return (542);
		case (545): return (545);
		case (547): return (547);
		case (549): return (549);
		case (550): return (550);
		case (554): return (554);
		case (555): return (555);
		case (558): return (558);
		case (559): return (559);
		case (560): return (560);
		case (561): return (561);
		case (562): return (562);
		case (565): return (565);
		case (579): return (579);
		case (580): return (580);
		case (587): return (587);
		case (589): return (589);
		case (602): return (602);
		case (603): return (603);
	}
	return (-1);
}

stock autiCijena(id)
{
	switch(id)
	{
        case (400): return (750000);
		case (401): return (200000);
		case (402): return (1200000);
		case (404): return (100000);
		case (405): return (700000);
		case (410): return (100000);
		case (411): return (1500000);
		case (412): return (360000);
		case (413): return (100000);
		case (415): return (1200000);
		case (418): return (130000);
		case (419): return (390000);
		case (421): return (450000);
		case (422): return (100000);
		case (424): return (500000);
		case (426): return (500000);
		case (429): return (1300000);
		case (434): return (1000000);
		case (436): return (200000);
		case (439): return (340000);
		case (440): return (100000);
		case (444): return (1100000);
		case (445): return (500000);
		case (451): return (1200000);
		case (458): return (600000);
		case (459): return (100000);
		case (466): return (400000);
		case (467): return (400000);
		case (470): return (900000);
		case (474): return (350000);
		case (475): return (320000);
		case (477): return (750000);
		case (478): return (100000);
		case (479): return (120000);
		case (480): return (1200500);
		case (482): return (180000);
		case (483): return (200000);
		case (489): return (950000);
		case (491): return (650000);
		case (492): return (630000);
		case (494): return (1600000);
		case (495): return (1000000);
		case (496): return (320000);
		case (500): return (500000);
		case (506): return (1100000);
		case (507): return (400000);
		case (516): return (500000);
		case (517): return (400000);
		case (518): return (300000);
		case (526): return (250000);
		case (527): return (350000);
		case (535): return (999999);
		case (540): return (450000);
		case (541): return (1250000);
		case (542): return (300000);
		case (545): return (850000);
		case (547): return (650000);
		case (549): return (300000);
		case (550): return (650000);
		case (554): return (900000);
		case (555): return (1000000);
		case (558): return (800000);
		case (559): return (800000);
		case (560): return (800000);
		case (561): return (800000);
		case (562): return (800000);
		case (565): return (800000);
		case (579): return (950000);
		case (580): return (999999);
		case (587): return (750000);
		case (589): return (500000);
		case (602): return (800000);
		case (603): return (1000000);
	}
	return (-1);
}

stock convertNumber(iValue, iDelim[2] = ".", szNum[15] = "", iSize = sizeof(szNum))
{
    format(szNum, iSize, "%d", iValue < 0 ? -iValue : iValue);
    for(new i = strlen(szNum) - 3; i > 0; i -= 3)
	{
        strins(szNum, iDelim, i, iSize);
    }
    if(iValue < 0)
	{
        strins(szNum, "-", 0, iSize);
    }
    return (szNum);
}

stock Set_Vrijeme(id, min, sec)
{
	vrijeme__ = (id);
	vrijemeTime[0] = (sec); vrijemeTime[1] = (min);
	return SetWeather(vrijeme__);
}

stock AdminLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\n",string);
	new File:hFile;
	hFile = fopen(EVIDENCIJA_ADMINA, io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

stock CheatLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\n",string);
	new File:hFile;
	hFile = fopen(EVIDENCIJA_CHEATERS, io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

stock ReportLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\n",string);
	new File:hFile;
	hFile = fopen(EVIDENCIJA_PRIJAVA, io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

stock PorukeLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\n",string);
	new File:hFile;
	hFile = fopen(EVIDENCIJA_PORUKA, io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

stock AdminChatLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\n",string);
	new File:hFile;
	hFile = fopen(EVIDENCIJA_ADMIN_CHAT, io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

stock SlanjeNovcaLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\n",string);
	new File:hFile;
	hFile = fopen(EVIDENCIJA_NOVAC_SLANJE, io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

public OnPlayerFloodControl(playerid, iCount, iTimeSpan)
{
    if(iCount >= 3 && iTimeSpan <= 8000)
	{
        SCM(playerid, ""#error"SERVER: "#bijela"U kratkom vremenu ova se IP adresa previse puta prikljucivala!", ""#error"SERVER: "#bijela"You try to flood this server.");
        Kick(playerid);
    }
	return (true);
}

AntiDeAMX()
{
    new a[][] =
    {
        "Unarmed (Fist)",
        "Brass K"
    };
    #pragma unused a
}

forward UcitajKuce();
public UcitajKuce()
{
    new rows, j, string[256] = "\0", LOKACIJA[128] = "\0";
    cache_get_data(rows, j, mySQL);
    j = 0;
    while(j < rows)
    {
        cache_get_field_content(j, "ID", string);
        HouseInfo[j][ID] = strval(string);
        cache_get_field_content(j, "h_Pi_X", string);
        HouseInfo[j][h_Pi][0] = floatstr(string);
        cache_get_field_content(j, "h_Pi_Y", string);
        HouseInfo[j][h_Pi][1] = floatstr(string);
        cache_get_field_content(j, "h_Pi_Z", string);
        HouseInfo[j][h_Pi][2] = floatstr(string);
        cache_get_field_content(j, "h_In_X", string);
        HouseInfo[j][h_In][0] = floatstr(string);
        cache_get_field_content(j, "h_In_Y", string);
        HouseInfo[j][h_In][1] = floatstr(string);
        cache_get_field_content(j, "h_In_Z", string);
        HouseInfo[j][h_In][2] = floatstr(string);
        cache_get_field_content(j, "h_Vlasnik", string);
        format(HouseInfo[j][h_Vlasnik], MAX_PLAYER_NAME, "%s", string);
        cache_get_field_content(j, "h_Locked", string);
        HouseInfo[j][h_Locked] = strval(string);
        cache_get_field_content(j, "h_Cijena", string);
        HouseInfo[j][h_Cijena] = strval(string);
        cache_get_field_content(j, "h_Vw", string);
        HouseInfo[j][h_Vw] = strval(string);
        cache_get_field_content(j, "h_Int", string);
        HouseInfo[j][h_Int] = strval(string);

        new h = j;
        Get2DZone(HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1],LOKACIJA,128);
	    if(strcmp(HouseInfo[h][h_Vlasnik], "-/-", false) == 0) // PRODAJA
	    {
    		format(string, sizeof(string),""#error"For Sale!\nPrice: "#zelena"$%d\n"#error"ID: "#zelena"%d",HouseInfo[h][h_Cijena], h);
            HouseLabel[h] = Create3DTextLabel(string ,-1, HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1], HouseInfo[h][h_Pi][2]+0.75, 35, 0, 1);
            HousePickup[h] = CreateDynamicPickup(1273, 1, HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1], HouseInfo[h][h_Pi][2]);
            HouseIcon[h] = CreateDynamicMapIcon(HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1], HouseInfo[h][h_Pi][2], 31, 0, -1, -1, -1, 65);
	    }
	    else
	    {
    		format(string, sizeof(string),""#error"Owner: "#zelena"%s\n"#error"Adress: "#zelena"%s\n"#error"ID: "#zelena"%d",HouseInfo[h][h_Vlasnik], LOKACIJA, h);
      		HouseLabel[h] = Create3DTextLabel(string , -1, HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1], HouseInfo[h][h_Pi][2]+0.75, 35, 0, 1);
   			HousePickup[h] = CreateDynamicPickup(1318, 1, HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1], HouseInfo[h][h_Pi][2]);
      		HouseIcon[h] = CreateDynamicMapIcon(HouseInfo[h][h_Pi][0], HouseInfo[h][h_Pi][1], HouseInfo[h][h_Pi][2], 32, 0, -1, -1, -1, 65);
	    }
	    ++ j;
    }
}

public OnGameModeInit()
{
	new string[256];
	serverRestart = (7200);
    DisableInteriorEnterExits();
	EnableStuntBonusForAll(0);
	SetGameModeText("1.2.1 Version");
	SendRconCommand("mapname � San Andreas �");
	LoadVehicles();
	AddPlayerClass(61,-1,-1,-1,-1,0,0,0,0,0,0);
	LOCAL_TIMER = SetTimer("LocalTimer", 1000, true);
	LOCAL_TIMER_2 = SetTimer("LocalTimer_2", 2000, true);
	Area = GangZoneCreate(-2973.969631, -2856.832972, 3000, 2973.969631);
	format(l_connect, MAX_PLAYER_NAME, "\0");
	Sekunde = (0);
	AntiDeAMX();
	
	mySQL = mysql_connect(SQL_HOST, SQL_KORISNIK, SQL_BAZA, SQL_LOZINKA);
	mysql_log(LOG_ALL);
	
	Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 1917.6833,-2433.4207,13.1946+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 1353.5370,1315.1051,10.3609+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1325.4257,-77.8169,13.8069+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 1004.0070,-939.3102,42.1797+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 1944.3260,-1772.9254,13.3906+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -90.5515,-1169.4578,2.4079+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1609.7958,-2718.2048,48.5391+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -2029.4968,156.4366,28.9498+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -2408.7590,976.0934,45.4175+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -2243.9629,-2560.6477,31.8841+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 2202.2349,2474.3494,10.5258+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1328.8250,2677.2173,49.7665+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 2113.7390,920.1079,10.5255+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 656.4265,-559.8610,16.5015+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1676.6323,414.0262,6.9484+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 614.9333,1689.7418,6.6968+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 70.3882,1218.6783,18.5165+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1327.7218,2678.8723,50.0625+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 656.3797,-570.4138,16.5015+2, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 2790.2019,-2318.3320,4.5449+1, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, 2220.2568,523.8825,3.8399+1, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1373.1731,1034.8998,4.3017+1, 100.0, 0, 0);
    Create3DTextLabel(""#error"/repair "#bijela"|| "#error"/refuel", -1, -1372.4905,1050.9585,3.5106+1, 100.0, 0, 0);

    /*CreateChristmasTree2(-1549.0511,585.0486,7.1797);
    CreateChristmasTree2(1272.7268,1241.3511,10.8859); // LV DISCO
	CreateChristmasTree1(-1548.4778,646.2723,7.1875);
	CreateChristmasTree2(-1568.5579,828.9424,7.1875);
	CreateChristmasTree1(-1991.4308,89.8115,27.6799);
	CreateChristmasTree2(-1992.0767,205.6595,27.6875);
	CreateChristmasTree1(-2633.8052,607.2700,14.4531);
	CreateChristmasTree2(-2675.2756,607.2688,14.4545);
	CreateChristmasTree1(-2600.0955,1384.2037,7.1607);
	CreateChristmasTree2(-2608.5371,1348.2877,7.1953);
	CreateChristmasTree1(1929.7019,-2537.5625,13.5469);
	CreateChristmasTree2(1829.1708,-2543.5288,13.5469);
	CreateChristmasTree1(1832.4257,-2523.9629,13.5469);
	CreateChristmasTree2(1803.7493,-2525.9958,13.5469);
	CreateChristmasTree1(1801.5800,-2548.4734,13.5469);
	CreateChristmasTree2(1819.8782,-2568.6160,13.5469);
	CreateChristmasTree1(1780.4879,-2566.6458,13.5469);
	CreateChristmasTree2(1764.1194,-2545.8506,13.5469);
	CreateChristmasTree1(1744.5371,-2521.1199,13.5469);
	CreateChristmasTree2(1727.8925,-2541.2419,13.5469);
	CreateChristmasTree2(1742.2246,-2569.6003,13.5469);
	CreateChristmasTree1(1424.5852,1296.1858,10.8203);
	CreateChristmasTree2(1442.1660,1323.0168,10.8203);
	CreateChristmasTree1(1418.2644,1331.5012,10.8203);
	CreateChristmasTree2(1415.4673,1365.1862,10.8203);
	CreateChristmasTree1(1442.9258,1385.0363,10.8203);
	CreateChristmasTree2(1449.0195,1418.6692,10.8203);
	CreateChristmasTree1(1417.3896,1437.9236,10.8203);
	CreateChristmasTree2(1415.0491,1490.7002,10.8203);
	CreateChristmasTree1(1450.3861,1516.3993,10.8203);
	CreateChristmasTree2(1444.2097,1547.8889,10.8203);
	CreateChristmasTree1(1415.9955,1570.1299,10.8203);
	CreateChristmasTree2(1427.8560,1604.4911,10.8130);
	CreateChristmasTree1(1414.0721,1644.6625,10.8203);
	CreateChristmasTree2(1443.6677,1686.5643,10.8203);
	CreateChristmasTree1(1429.7990,1707.0096,10.8203);
	CreateChristmasTree1(-1266.8883,74.3111,14.1484);
	CreateChristmasTree2(-1279.5452,168.4904,14.5394);
	CreateChristmasTree1(-1305.5808,151.1057,14.5469);
	CreateChristmasTree2(-1301.6862,124.6200,14.5469);
	CreateChristmasTree1(-1325.9222,123.9159,14.5469);
	CreateChristmasTree2(-1366.0045,88.3862,14.5469);
	CreateChristmasTree1(-1364.2079,66.2385,14.5469);
	CreateChristmasTree2(-1373.1035,40.5237,14.5394);
	CreateChristmasTree1(-1395.6534,46.1580,14.5469);
	CreateChristmasTree2(-1419.9653,34.5328,14.5469);
	CreateChristmasTree1(-1453.9463,1.4775,14.5469);
	CreateChristmasTree2(-1453.9454,-31.9024,14.5469);
	CreateChristmasTree1(-1466.7916,-58.7523,14.5469);
	CreateChristmasTree2(-1496.3794,-66.9118,14.5469);
	CreateChristmasTree1(-1518.9456,-58.6463,14.5469);
	CreateChristmasTree2(-1495.2621,-32.2570,14.3795);*/

	Sat = TextDrawCreate(548.000000, 21.000000, "_");
    TextDrawBackgroundColor(Sat, 255);
    TextDrawFont(Sat, 1);
    TextDrawLetterSize(Sat, 0.589999, 1.800000);
    TextDrawColor(Sat, -1);
    TextDrawSetOutline(Sat, 0);
    TextDrawSetProportional(Sat, 1);
    TextDrawSetShadow(Sat, 1);

    for(new a=0; a<=MAX_AIRLINES; ++a)
    {
		format(Data, (sizeof Data), AVIO_BAZA, a);
		if(fexist(Data))
		{
            INI_ParseFile(Data, "LoadAirlines", .bExtra = true, .extra = a);
		}
    }
    mysql_format(mySQL, string, (sizeof string), "SELECT * FROM `kuce`");
    mysql_pquery(mySQL, string, "UcitajKuce", "");
	
	for(new c=0;c<MAX_CARS;c++)
	{
		format(Data, (sizeof Data), CAR_BAZA, c);
		if(fexist(Data))
		{
            INI_ParseFile(Data, "LoadCars", .bExtra = true, .extra = c);
            COS_VOZILA[c] = AddStaticVehicle(CarInfo[c][v_Model], CarInfo[c][v_Pos][0], CarInfo[c][v_Pos][1], CarInfo[c][v_Pos][2], CarInfo[c][v_Pos][3], CarInfo[c][v_Boja][0], CarInfo[c][v_Boja][1]);
            if(CarInfo[c][v_PaintJob] != -1)
            {
                ChangeVehiclePaintjob(c, CarInfo[c][v_PaintJob]);
            }
            for(new iMod = 0; iMod < 12; ++iMod)
			{
				if(vMods[COS_VOZILA[c]][iMod] > 0)
				{
					AddVehicleComponent(COS_VOZILA[c], vMods[COS_VOZILA[c]][iMod]);
				}
			}
		}
	}
	
	for(new i=0;i<MAX_VEHICLES;i++)
	{
       Gorivo[i] = (MAX_FUEL);
	}
    
    // CONNECT
    MainMenu[0] = TextDrawCreate(250.000000, 343.000000, "~n~~n~~n~~n~~n~~n~");
	TextDrawAlignment(MainMenu[0], 2);
	TextDrawBackgroundColor(MainMenu[0], 255);
	TextDrawFont(MainMenu[0], 1);
	TextDrawLetterSize(MainMenu[0], 1.000000, 2.000000);
	TextDrawColor(MainMenu[0], -16776961);
	TextDrawSetOutline(MainMenu[0], 1);
	TextDrawSetProportional(MainMenu[0], 1);
	TextDrawUseBox(MainMenu[0], 1);
	TextDrawBoxColor(MainMenu[0], 255);
	TextDrawTextSize(MainMenu[0], 90.000000, 803.000000);

	MainMenu[1] = TextDrawCreate(250.000000, -12.000000, "~n~~n~~n~~n~~n~~n~");
	TextDrawAlignment(MainMenu[1], 2);
	TextDrawBackgroundColor(MainMenu[1], 255);
	TextDrawFont(MainMenu[1], 1);
	TextDrawLetterSize(MainMenu[1], 1.000000, 2.000000);
	TextDrawColor(MainMenu[1], -16776961);
	TextDrawSetOutline(MainMenu[1], 1);
	TextDrawSetProportional(MainMenu[1], 1);
	TextDrawUseBox(MainMenu[1], 1);
	TextDrawBoxColor(MainMenu[1], 255);
	TextDrawTextSize(MainMenu[1], 90.000000, 918.000000);

	MainMenu[2] = TextDrawCreate(729.000000, 99.000000, "_");
	TextDrawBackgroundColor(MainMenu[2], 255);
	TextDrawFont(MainMenu[2], 1);
	TextDrawLetterSize(MainMenu[2], 50.000000, 0.099999);
	TextDrawColor(MainMenu[2], -16776961);
	TextDrawSetOutline(MainMenu[2], 0);
	TextDrawSetProportional(MainMenu[2], 1);
	TextDrawSetShadow(MainMenu[2], 1);
	TextDrawUseBox(MainMenu[2], 1);
	TextDrawBoxColor(MainMenu[2], 0x1564F5FF);
	TextDrawTextSize(MainMenu[2], -5.000000, 1031.000000);

	MainMenu[3] = TextDrawCreate(729.000000, 340.000000, "_");
	TextDrawBackgroundColor(MainMenu[3], 255);
	TextDrawFont(MainMenu[3], 1);
	TextDrawLetterSize(MainMenu[3], 50.000000, 0.099999);
	TextDrawColor(MainMenu[3], -16776961);
	TextDrawSetOutline(MainMenu[3], 0);
	TextDrawSetProportional(MainMenu[3], 1);
	TextDrawSetShadow(MainMenu[3], 1);
	TextDrawUseBox(MainMenu[3], 1);
	TextDrawBoxColor(MainMenu[3], 0x1564F5FF);
	TextDrawTextSize(MainMenu[3], -5.000000, 1031.000000);
	return (true);
}

stock bool:IsAPlane(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 519 || model == 520 || model == 553 || model == 577 || model == 592 || model == 593) return (true);
	else return (false);
}

stock sendToAdmins(string[])
{
	foreach(Player, i)
	{
		if(PlayerInfo[i][Admin] >= 1 && cheatLog{i} == true)
		{
		   SCM(i, string, string);
		}
	}
}

stock Float:GetDistanceFromPointToPoint(Float:X,Float:Y,Float:Z,Float:tX,Float:tY,Float:tZ) return Float:floatsqroot((tX-X)*(tX-X)+(tY-Y)*(tY-Y)+(tZ-Z)*(tZ-Z));

forward LocalTimer_2();
public LocalTimer_2()
{
    for(new a=0; a<=MAX_AIRLINES; ++a)
    {
		if(AvioKompanija[a][av_Vozilo][0] == 0) { AvioKompanija[a][av_Vozilo][0] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][1] == 0) { AvioKompanija[a][av_Vozilo][1] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][2] == 0) { AvioKompanija[a][av_Vozilo][2] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][3] == 0) { AvioKompanija[a][av_Vozilo][3] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][4] == 0) { AvioKompanija[a][av_Vozilo][4] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][5] == 0) { AvioKompanija[a][av_Vozilo][5] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][6] == 0) { AvioKompanija[a][av_Vozilo][6] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][7] == 0) { AvioKompanija[a][av_Vozilo][7] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][8] == 0) { AvioKompanija[a][av_Vozilo][8] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][9] == 0) { AvioKompanija[a][av_Vozilo][9] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][10] == 0) { AvioKompanija[a][av_Vozilo][10] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][11] == 0) { AvioKompanija[a][av_Vozilo][11] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][12] == 0) { AvioKompanija[a][av_Vozilo][12] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][13] == 0) { AvioKompanija[a][av_Vozilo][13] = (-1); }
		else if(AvioKompanija[a][av_Vozilo][14] == 0) { AvioKompanija[a][av_Vozilo][14] = (-1); }
		UpdateAirline(a);
    }
	return (true);
}

forward LocalTimer();
public LocalTimer()
{
	new
	   string[256] = "\0", string2[256] = "\0", Float:armour;
    min_++;
    if(sat_ == 23 && min_ == 59)
    {
	   sat_ = (0);
	   min_ = (0);
    }
    if(min_ == 59)
    {
       sat_++;
	   min_ = (0);
    }
    serverRestart --;
    if(serverRestart == 300) // 5 MINUTA DO RESTARTA
    {
		ScmToAll(""#zelena"[SERVER RESTART]: "#error"Za 5 minuta server ce se automatski resestirati!", ""#zelena"[SERVER RESTART]: "#error"For 5 minutes the server will be reset!");
    }
    else if(serverRestart == 60) // 1 MINUTA DO RESTARTA
    {
		ScmToAll(""#zelena"[SERVER RESTART]: "#error"Za 1 minutu server ce se automatski resestirati!", ""#zelena"[SERVER RESTART]: "#error"For 1 minute the server will be reset!");
    }
    
    ++Sekunde;
	foreach(Player, i)
	{
	   -- txtTime{i};
	   if(txtTime{i} <= 0)
       {
           txtTime{i} = (TEXT_VRIJEME);
           new ll = txtS{i};
           if(IsPlayerLanguage(i, JEZIK_BALKAN))
           {
              createInfo(sfpInfo[i], i, balcanInfo[ll]);
		      ++ txtS{i};
		      if(txtS{i} > 26) txtS{i} = (0);
		   }
		   else if(IsPlayerLanguage(i, JEZIK_ENGLISH))
           {
              createInfo(sfpInfo[i], i, engInfo[ll]);
		      ++ txtS{i};
		      if(txtS{i} > 6) txtS{i} = (0);
		   }
       }
       ++AFK{i};
	   if(playerSpawned{i} == true && PlayerLogin{i} == true && anti_Kicker{i} == false)
	   {
		  if(Zastita__{i} != 0)
		  {
	    	   ++Zastita__{i};
			   new Float:vhelti;
	 		   GetVehicleHealth(GetPlayerVehicleID(i), vhelti);
     		   if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
			   {
	    		  AutoHelti[i] = vhelti;
			   }
	    	   if(Zastita__{i} == 2)
	    	   {
	    		  Zastita__{i} = (0);
			   }
		  }
	   }
	   if(Sekunde == 2)
       {
     	   new Float:vhelti;
	 	   GetVehicleHealth(GetPlayerVehicleID(i), vhelti);
     	   if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		   {
	    	  AutoHelti[i] = vhelti;
		   }
     	   Sekunde = 0;
       }
	   if(AVR == 1 && PlayerLogin{i} == true && anti_Kicker{i} == false)
	   {
		    if(izbjegavanje_{i} == false)
		    {
			    new Float:vhelti; GetVehicleHealth(GetPlayerVehicleID(i), vhelti);
			    if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
			    {
				    if(vhelti < AutoHelti[i])
				    {
	    			    AutoHelti[i] = vhelti;
				    }
				    if(v_fix__{i} == true)
				    {
				        AutoHelti[i] = vhelti;
				        v_fix__{i} = (false);
				    }
				    if(IsPlayerInRangeOfPoint(i, 15, 719.9484,-457.3498,16.4282) || IsPlayerInRangeOfPoint(i, 15, -1420.6052,2584.6243,55.9356) || IsPlayerInRangeOfPoint(i, 15, -99.7463,1116.9677,19.8340)|| IsPlayerInRangeOfPoint(i, 15, 2063.4375,-1831.9276,13.6391)||
       				IsPlayerInRangeOfPoint(i, 15, -2425.9333,1022.5239,50.4900) || IsPlayerInRangeOfPoint(i, 15, 1974.0004,2162.5266,11.1561) || IsPlayerInRangeOfPoint(i, 15, 487.5558,-1739.5125,11.2265)|| IsPlayerInRangeOfPoint(i, 15, 1025.3940,-1024.2563,32.1938)||
   					IsPlayerInRangeOfPoint(i, 15, 2393.6174,1489.2686,10.9246)||IsPlayerInRangeOfPoint(i, 15, -1905.1163,283.4408,41.1392))
				    {
				        AutoHelti[i] = vhelti;
				        v_fix__{i} = (true);
				    }
 				    if(vhelti > AutoHelti[i] && Zastita__{i} == 0 && GetPlayerInterior(i) == 0 && v_fix__{i} == false)
 				    {
 		    		    if(!IsPlayerInRangeOfPoint(i, 15, 719.9484,-457.3498,16.4282) || !IsPlayerInRangeOfPoint(i, 15, -1420.6052,2584.6243,55.9356) || !IsPlayerInRangeOfPoint(i, 15, -99.7463,1116.9677,19.8340)|| !IsPlayerInRangeOfPoint(i, 15, 2063.4375,-1831.9276,13.6391)||
       				    !IsPlayerInRangeOfPoint(i, 15, -2425.9333,1022.5239,50.4900) || !IsPlayerInRangeOfPoint(i, 15, 1974.0004,2162.5266,11.1561) || !IsPlayerInRangeOfPoint(i, 15, 487.5558,-1739.5125,11.2265)|| !IsPlayerInRangeOfPoint(i, 15, 1025.3940,-1024.2563,32.1938)||
   					    !IsPlayerInRangeOfPoint(i, 15, 2393.6174,1489.2686,10.9246)||!IsPlayerInRangeOfPoint(i, 15, -1905.1163,283.4408,41.1392))
   					    {
 	    				     new dan, mjesec, godina;
		                     getdate(godina, mjesec, dan);
		                     format(string, (sizeof string), "%s koristi popravak vozila cheat (%d.%d.%d)",GetName(i),dan,mjesec,godina);
		                     CheatLog(string);
		                     sendToAdmins(string);
							 Kick(i);
					    }
 				    }
			    }
		    }
	   }
	   if(AAFK == 1 && PlayerLogin{i} == true)
	   {
		    if(izbjegavanje_{i} == false)
		    {
		        if(AFK{i} >= 13 && AFK2{i} == false)
		        {
		            AFK2{i} = (true);
			    }
			    if(AFK{i} > MAXAFK)
			    {
                     new dan, mjesec, godina;
		             getdate(godina, mjesec, dan);
		             format(string, (sizeof string), "%s je kickan zbog AFK-a (%d.%d.%d)",GetName(i),dan,mjesec,godina);
		             CheatLog(string);
		             sendToAdmins(string);
					 Kick(i);
			    }
		    }
	   }
       if(serverRestart <= 0)
       {
		   GameText(i, "~r~SERVER SE RESESTIRA!", "~r~Restarting!", 5000, 3);
		   SendRconCommand("gmx");
       }
       new novac[10];
	   valstr(novac,GetPlayerMoneyEx(i));
	   if(GetPlayerMoneyEx(i) >= 0)
	   {
	      if(strlen(novac) == 0) { format(string, (sizeof string), "$00000000"); }
	      else if(strlen(novac) == 1) { format(string, (sizeof string), "$0000000%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 2) { format(string, (sizeof string), "$000000%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 3) { format(string, (sizeof string), "$00000%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 4) { format(string, (sizeof string), "$0000%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 5) { format(string, (sizeof string), "$000%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 6) { format(string, (sizeof string), "$00%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 7) { format(string, (sizeof string), "$0%d",PlayerInfo[i][Novac]); }
	      else if(strlen(novac) == 8) { format(string, (sizeof string), "$%d",PlayerInfo[i][Novac]); }
	      PlayerTextDrawHide(i, MONEY_BAR[1]);
	   }
	   else if(GetPlayerMoneyEx(i) < 0)
	   {
	      if(strlen(novac) == 2) { format(string, (sizeof string), "~r~$0000000%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 3) { format(string, (sizeof string), "~r~$000000%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 4) { format(string, (sizeof string), "~r~$00000%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 5) { format(string, (sizeof string), "~r~$0000%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 6) { format(string, (sizeof string), "~r~$000%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 7) { format(string, (sizeof string), "~r~$00%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 8) { format(string, (sizeof string), "~r~$0%d",(PlayerInfo[i][Novac]*-1)); }
	      else if(strlen(novac) == 9) { format(string, (sizeof string), "~r~$%d",(PlayerInfo[i][Novac]*-1)); }
	      PlayerTextDrawShow(i, MONEY_BAR[1]);
	   }
	   PlayerTextDrawSetString(i, MONEY_BAR[0], string);
	   if(PlayerInfo[i][AirlineUgovor] >= 1)
	   {
		  --PlayerInfo[i][AirlineUgovor];
		  if(PlayerInfo[i][AirlineUgovor] <= 0)
		  {
              PlayerInfo[i][AirlineUgovor] = (0);
              UpdatePlayer(i);
		  }
	   }
	   updateLokacija(i);
	   if(timerFreeze{i} >= 1)
	   {
		   --timerFreeze{i};
		   if(timerFreeze{i} <= 0)
		   {
			  Freeze(i, 0);
		   }
	   }
	   if(av_call_time{i} >= 1)
	   {
           av_call_time{i} --;
           if(av_call_time{i} <= 0)
           {
               av_call_time{i} = (0);
               av_call_vlasnik[i] = (INVALID_PLAYER_ID);
               av_call_avio{i} = (-1);
           }
	   }
	   SetPlayerScore(i, GetPlayerScoreEx(i));
       GetPlayerArmour(i, armour);
	   if(armour >= 1.0 && PlayerLogin{i} == true)
	   {
           new dan, mjesec, godina;
		   getdate(godina, mjesec, dan);
		   format(string, (sizeof string), "%s posjeduje armour stit (%d.%d.%d)",GetName(i),dan,mjesec,godina);
		   CheatLog(string);
		   sendToAdmins(string);
		   SFP_SetPlayerArmour(i, 0.000);
	   }
	   if(inhouse[i] != (MAX_HOUSES+1) && snowOn{i} == true)
	   {
		   DeleteSnow(i);
	   }
	   if(GetPlayerWeapon(i) != 0 && GetPlayerWeapon(i) != 46 && GetPlayerWeapon(i) != 200 && GetPlayerWeapon(i) != 201 && GetPlayerWeapon(i) != 47 && GetPlayerWeapon(i) != 49 && GetPlayerWeapon(i) != 50 && GetPlayerWeapon(i) != 51 && GetPlayerWeapon(i) != 53 && GetPlayerWeapon(i) != 54 && PlayerLogin{i} == true)
	   {
		   new dan, mjesec, godina, gunname[32];
		   GetWeaponName(GetPlayerWeapon(i), gunname, 32);
		   getdate(godina, mjesec, dan);
		   format(string, (sizeof string), "%s posjeduje oruzje %s (%d.%d.%d)",GetName(i),gunname,dan,mjesec,godina);
		   CheatLog(string);
		   sendToAdmins(string);
		   ResetPlayerWeapons(i);
	   }
	   if(GetPlayerSpecialAction(i) == SPECIAL_ACTION_USEJETPACK && PlayerInfo[i][Admin] <= 0)
       {
           SetPlayerSpecialAction(i, SPECIAL_ACTION_NONE);
       }
	   if(GetPlayerMoney(i) > 1)
	   {
           new dan, mjesec, godina;
		   getdate(godina, mjesec, dan);
		   format(string, (sizeof string), "%s posjeduje vise novaca nego sto bi trebao imati $%d (%d.%d.%d)",GetName(i),GetPlayerMoney(i),dan,mjesec,godina);
		   CheatLog(string);
		   sendToAdmins(string);
		   ResetPlayerMoney(i);
	   }
	   if(move{i} == true && moveON{i} == false)
	   {
		   pickCameraMove(i);
		   moveON{i} = (true);
	   }
	   if(vrijemeTime[0] < 0) { vrijemeTime[0] = (60); }
	   if(vrijemeTime[1] < 0) { vrijemeTime[1] = (0); }
	   vrijemeTime[0] --;
	   if(vrijemeTime[0] <= 0)
	   {
		  vrijemeTime[1] --;
		  if(vrijemeTime[1] <= 0)
		  {
             vrijemeEx_ ++;
             switch(vrijemeEx_)
		     {
			        case (0): { Set_Vrijeme(15, 15, 0);  }
			        case (1): { Set_Vrijeme(15, 15, 0);  }
			        case (2): { Set_Vrijeme(15, 15, 30); }
			        case (3): { Set_Vrijeme(15, 15, 0); }
			        case (4): { Set_Vrijeme(15, 15, 0); }
			        case (5): { Set_Vrijeme(15, 15, 0); }
                    case (6): { Set_Vrijeme(15, 15, 30); vrijemeEx_ = (-1); }
              }
		  }
		  else if(vrijemeTime[1] != 0)
		  {
             vrijemeTime[0] = (60);
		  }
	   }
	   if(ruta_sec{i} >= 1 && posao{i} == true)
	   {
		   ruta_sec{i} ++;
		   if(ruta_sec{i} >= 60)
		   {
			   ruta_min{i} ++;
			   ruta_sec{i} = (1);
		   }
	   }
	   SetPlayerTime(i, sat_, min_);
	   if(sat_ >= 0 && sat_ < 10 && min_ >= 10)
	   {
	      format(string, (sizeof string), "0%d:%d",sat_,min_);
	   }
	   else if(sat_ >= 1 && sat_ < 10 && min_ < 10)
	   {
          format(string, (sizeof string), "0%d:0%d",sat_,min_);
	   }
	   else if(sat_ == 0 && min_ < 10)
	   {
          format(string, (sizeof string), "0%d:0%d",sat_,min_);
	   }
	   else if(sat_ >= 1 && sat_ < 10 && min_ >= 10)
	   {
          format(string, (sizeof string), "0%d:%d",sat_,min_);
	   }
	   else if(sat_ >= 10 && min_ < 10)
	   {
          format(string, (sizeof string), "%d:0%d",sat_,min_);
	   }
	   else if(sat_ >= 10 && min_ >= 10)
	   {
          format(string, (sizeof string), "%d:%d",sat_,min_);
	   }
	   TextSet(Sat, string, string);
	   
	   if(IsPlayerInAirline(i, GetName(i)) == -1)
	   {
		   new NICK__ [1];
		   GetPlayerName(i, NICK__, 1);
		   if(NICK__[0] == '[')
		   {
			  SetPlayerName(i, GetName(i));
		   }
	   }
       if(Bonus{i} >= 1)
	   {
          Bonus{i} --;
          
          PlayerTextDrawDestroy(i, TABLA[4][i]);
          
          bonus_[i] -= (bonus__[i]);
          TABLA[4][i] = CreatePlayerTextDraw(i, 464.000000, 345.000000, "_");
          PlayerTextDrawBackgroundColor(i, TABLA[4][i], 255);
          PlayerTextDrawFont(i, TABLA[4][i], 1);
          PlayerTextDrawLetterSize(i, TABLA[4][i], 0.500000, 1.699999);
          PlayerTextDrawColor(i, TABLA[4][i], -1);
          PlayerTextDrawSetOutline(i, TABLA[4][i], 0);
          PlayerTextDrawSetProportional(i, TABLA[4][i], 1);
          PlayerTextDrawSetShadow(i, TABLA[4][i], 1);
          PlayerTextDrawUseBox(i, TABLA[4][i], 1);
          PlayerTextDrawBoxColor(i, TABLA[4][i], 0xFF0000FF);
          PlayerTextDrawTextSize(i, TABLA[4][i], bonus_[i], 0.000000);
          if(Bonus{i} == 0) { Bonus{i} = (0); }
	   }
	   if(info_box{i} >= 1)
	   {
          info_box{i} --;
          if(info_box{i} == 0)
          {
              SendInfo(i, "_", "_", false);
          }
	   }
	   if(TIMER_LOAD[i] >= 1)
	   {
		  TextDrawDestroy(loading_[i][2]);
		  load_bar[i] += (21.28);
		  loading_[i][2] = TextDrawCreate(242.000000, 173.000000, "_");
    	  TextDrawBackgroundColor(loading_[i][2], 255);
    	  TextDrawFont(loading_[i][2], 1);
    	  TextDrawLetterSize(loading_[i][2], 0.480000, 2.699999);
    	  TextDrawColor(loading_[i][2], -1);
    	  TextDrawSetOutline(loading_[i][2], 0);
    	  TextDrawSetProportional(loading_[i][2], 1);
    	  TextDrawSetShadow(loading_[i][2], 1);
    	  TextDrawUseBox(loading_[i][2], 1);
    	  TextDrawBoxColor(loading_[i][2], 25690);
    	  TextDrawTextSize(loading_[i][2], load_bar[i], 0.000000);
    	  TextDrawShowForPlayer(i, loading_[i][2]);
    	  
		  TIMER_LOAD[i] --;
		  if(TIMER_LOAD[i] == 0)
		  {
             load_bar[i] = (239.00);
             TextDrawHideForPlayer(i, loading_[i][0]);
             TextDrawHideForPlayer(i, loading_[i][1]);
             TextDrawHideForPlayer(i, loading_[i][2]);
             
			 Freeze(i,0);
			 antiTAB{i} = (false);
			 if(CP[i] == 1)
			 {
				if(CivilniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 1)
				{
                    OstavljanjePaketaCivilniPiloti(i);
                    Bonus{i} = (170);
                    bonus__[i] = (0.688);
                    SendInfo(i, "Preuzeo si paket, ukoliko ga dostavis unutar 170 sekundi zaradit ces dodatnih ~g~$1500~w~.", "You took the package, if you deliver a package within 170 seconds you will earn ~g~$1500~w~ of bonus.", true);
				}
				else if(MedicinskiAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 2)
				{
                      OstavljanjePaketaMediPiloti(i);
                      Bonus{i} = (120);
                      bonus__[i] = (0.975);
                      SendInfo(i, "Preuzeo si paket, ukoliko ga dostavis unutar 120 sekundi zaradit ces dodatnih ~g~$2500~w~.", "You took the package, if you deliver a package within 120 seconds you will earn ~g~$2500~w~ of bonus.", true);
				}
				else if(VojniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 3)
				{
                   OstavljanjePaketaCivilniPiloti(i);
                   Bonus{i} = (100);
                   bonus__[i] = (1.17);
                   SendInfo(i, "Preuzeo si paket, ukoliko ga dostavis unutar 100 sekundi zaradit ces dodatnih ~g~$2500~w~.", "You took the package, if you deliver a package within 100 seconds you will earn ~g~$2500~w~ of bonus.", true);
				}
				else if(VojniHeli(GetPlayerVehicleID(i)))
				{
                   OstavljanjePaketaMediPiloti(i);
                   Bonus{i} = (120);
                   bonus__[i] = (0.975);
                   SendInfo(i, "Preuzeo si paket, ukoliko ga dostavis unutar 120 sekundi zaradit ces dodatnih ~g~$2500~w~.", "You took the package, if you deliver a package within 120 seconds you will earn ~g~$2500~w~ of bonus.", true);
				}
				else if(TaxiAuto(GetPlayerVehicleID(i)))
				{
					if(TaxiGrad(i) == 1)//LS
					{
                       OstavljanjePutnikaLS(i);
                       Bonus{i} = (150);
                       bonus__[i] = (0.78);
                       SendInfo(i, "Putnik je sjeo u vozilo i trazi da ga odvezete do lokacije oznacene na radaru crvenom tockom.", "The passenger sitting in your vehicle and he wants you take him to location on your radar.", true);
					}
					else if(TaxiGrad(i) == 2)//LV
					{
                       OstavljanjePutnikaLV(i);
                       Bonus{i} = (150);
                       bonus__[i] = (0.78);
                       SendInfo(i, "Putnik je sjeo u vozilo i trazi da ga odvezete do lokacije oznacene na radaru crvenom tockom.", "The passenger sitting in your vehicle and he wants you take him to location on your radar.", true);
					}
					else if(TaxiGrad(i) == 3)//SF
					{
                       OstavljanjePutnikaSF(i);
                       Bonus{i} = (150);
                       bonus__[i] = (0.78);
                       SendInfo(i, "Putnik je sjeo u vozilo i trazi da ga odvezete do lokacije oznacene na radaru crvenom tockom.", "The passenger sitting in your vehicle and he wants you take him to location on your radar.", true);
					}
	            }
	            else if(Truck(GetPlayerVehicleID(i)))
	            {
					OstavljanjePaketa(i);
                    Bonus{i} = (250);
                    bonus__[i] = (0.468);
                    SendInfo(i, "Preuzeo si paket, ukoliko ga dostavis unutar 200 sekundi zaradit ces dodatnih ~g~$2500~w~.", "You took the package, if you deliver a package within 200 seconds you will earn ~g~$1500~w~ of bonus.", true);
	            }
	            else if(IsABoat(GetPlayerVehicleID(i)))
	            {
					OstavljanjeTereta_Brod(i);
                    SendInfo(i, "Otkrivas more sada ti je zadatak da dostavis podatke na mjesto oznaceno na mapi!", "You are exploring the ocean, now bring all information on location that is on your map.", true);
	            }
			 }
			 else if(CP[i] == 2) // ISTOVAR
			 {
				posao{i} = (false);
				GivePlayerScore(i, 1);
				if(PlayerInfo[i][Vip] >= 1)
				{
                    GivePlayerScore(i, 1);
				}
				setVehicleScore(i);
				work_vehicle[i] = (-1);
				if(Bonus{i} >= 1)
				{
					new zarada = PayCheck(i, true, floatround(RUTA_DUZINA[i]));
					UpdatePlayer(i);
					Bonus{i} = (0);
					if(IsPlayerLanguage(i,JEZIK_BALKAN))
					{
                       if(CivilniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 1) { format(string, (sizeof string), "Dostavio si paket na vrijeme i zaradio ~g~$1500~w~ bonusa! Ukupno si zaradio ~g~$%d~w~ i jedan bod.",zarada); }
                       else if(MedicinskiAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 2) { format(string, (sizeof string), "Dostavio si paket na vrijeme i zaradio ~g~$2500~w~ bonusa! Ukupno si zaradio ~g~$%d~w~ i jedan bod.",zarada); }
                       else if(VojniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 3) { format(string, (sizeof string), "Dostavio si paket na vrijeme i zaradio ~g~$2500~w~ bonusa! Ukupno si zaradio ~g~$%d~w~ i jedan bod.",zarada); }
					   else if(Team{i} == 4) { format(string, (sizeof string), "Dostavio si putnika na vrijeme i zaradio ~g~$1500~w~ bonusa! Ukupno si zaradio ~g~$%d~w~ i jedan bod.",zarada); }
					   else if(Team{i} == 6) { format(string, (sizeof string), "Dostavio si paket na vrijeme i zaradio ~g~$2500~w~ bonusa! Ukupno si zaradio ~g~$%d~w~ i jedan bod.",zarada); }
                       else if(Team{i} == 7) { format(string, (sizeof string), "Zavrsio si misiju i zaradio si ~g~$%d~w~ i jedan bod.",zarada); }
					   SendInfo(i, string, string, true);
					}
					else if(IsPlayerLanguage(i, JEZIK_ENGLISH))
					{
                       if(CivilniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 1) { format(string, (sizeof string), "You deliver a package! You earn bonus of ~g~$1500~w~ altogether you just earn ~g~$%d~w~ and one score.",zarada); }
                       else if(MedicinskiAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 2) { format(string, (sizeof string), "You deliver a package! You earn bonus of ~g~$2500~w~ altogether you just earn ~g~$%d~w~ and one score.",zarada); }
                       else if(VojniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 3) { format(string, (sizeof string), "You deliver a package! You earn bonus of ~g~$2500~w~ altogether you just earn ~g~$%d~w~ and one score.",zarada); }
					   else if(Team{i} == 4) { format(string, (sizeof string), "You drove a passenger to location! You earn bonus of ~g~$1500~w~ altogether you just earn ~g~$%d~w~ and one score.",zarada); }
					   else if(Team{i} == 6) { format(string, (sizeof string), "You deliver a package! You earn bonus of ~g~$2500~w~ altogether you just earn ~g~$%d~w~ and one score.",zarada); }
                       else if(Team{i} == 7) { format(string, (sizeof string), "You complete the mission and you just earn ~g~$%d~w~ and one score.",zarada); }
					   SendInfo(i, string, string, true);
					}
				}
				else if(Bonus{i} <= 0)
				{
                    new zarada_2 = PayCheck(i, false, floatround(RUTA_DUZINA[i]));
					UpdatePlayer(i);
                    if(IsPlayerLanguage(i,JEZIK_BALKAN))
					{
                       if(CivilniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 1) { format(string, (sizeof string), "Dostavio si paket i zaradio ~g~$%d~w~ i jedan bod.",zarada_2); }
                       else if(MedicinskiAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 2) { format(string, (sizeof string), "Dostavio si paket i zaradio ~g~$%d~w~ i jedan bod.",zarada_2); }
                       else if(VojniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 3) { format(string, (sizeof string), "Dostavio si paket i zaradio ~g~$%d~w~ i jedan bod.",zarada_2); }
                       else if(Team{i} == 4) { format(string, (sizeof string), "Dostavio si putnika i zaradio si ~g~$%d~w~ i jedan bod.",zarada_2); }
                       else if(Team{i} == 6) { format(string, (sizeof string), "Dostavio si paket i zaradio si ~g~$%d~w~ i jedan bod.",zarada_2); }
                       else if(Team{i} == 7) { format(string, (sizeof string), "Zavrsio si misiju i zaradio si ~g~$%d~w~ i jedan bod.",zarada_2); }
                       SendInfo(i, string, string, true);
					}
					else if(IsPlayerLanguage(i, JEZIK_ENGLISH))
					{
                       if(CivilniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 1) { format(string, (sizeof string), "You deliver a package! You earn ~g~$%d~w~ and one score.",zarada_2); }
                       else if(MedicinskiAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 2) { format(string, (sizeof string), "You deliver a package! You earn ~g~$%d~w~ and one score.",zarada_2); }
                       else if(VojniAvion(GetPlayerVehicleID(i)) || CarInfo[GetPlayerVehicleID(i)][v_Posao] == 3) { format(string, (sizeof string), "You deliver a package! You earn ~g~$%d~w~ and one score.",zarada_2); }
                       else if(Team{i} == 4) { format(string, (sizeof string), "You drove a passenger to location! You earn ~g~$%d~w~ and one score.",zarada_2); }
                       else if(Team{i} == 6) { format(string, (sizeof string), "You deliver a package! You earn ~g~$%d~w~ and one score.",zarada_2); }
                       else if(Team{i} == 7) { format(string, (sizeof string), "You complete the mission and you just earn ~g~$%d~w~.",zarada_2); }
                       SendInfo(i, string, string, true);
					}
				}
				if(Team{i} == 1) { format(string, (sizeof string), ""#zelena"[PILOT] "#bijela"%s je zavrsio svoju rutu za "#error"%02i:%02i "#bijela"minuta.",GetName(i),ruta_min{i},ruta_sec{i}); format(string2, (sizeof string2), ""#zelena"[PILOT] "#bijela"%s ended mission at a time "#error"%02i:%02i "#bijela"minutes.",GetName(i),ruta_min{i},ruta_sec{i}); }
				else if(Team{i} == 2) { format(string, (sizeof string), ""#zelena"[MED. PILOT] "#bijela"%s je zavrsio svoju rutu za "#error"%02i:%02i "#bijela"minuta.",GetName(i),ruta_min{i},ruta_sec{i}); format(string2, (sizeof string2), ""#zelena"[MEDICAL PILOT] "#bijela"%s ended mission at a time "#error"%02i:%02i "#bijela"minutes.",GetName(i),ruta_min{i},ruta_sec{i}); }
				else if(Team{i} == 3) { format(string, (sizeof string), ""#zelena"[VOJNI PILOT] "#bijela"%s je zavrsio svoju rutu za "#error"%02i:%02i "#bijela"minuta.",GetName(i),ruta_min{i},ruta_sec{i}); format(string2, (sizeof string2), ""#zelena"[MILITARY PILOT] "#bijela"%s ended mission at a time "#error"%02i:%02i "#bijela"minutes.",GetName(i),ruta_min{i},ruta_sec{i}); }
				else if(Team{i} == 4) { format(string, (sizeof string), ""#zelena"[TAKSIST] "#bijela"%s je dovezao putnika za "#error"%02i:%02i "#bijela"minuta.",GetName(i),ruta_min{i},ruta_sec{i}); format(string2, (sizeof string2), ""#zelena"[TAXI] "#bijela"%s drove a passanger at a time "#error"%02i:%02i "#bijela"minutes.",GetName(i),ruta_min{i},ruta_sec{i}); }
				else if(Team{i} == 6) { format(string, (sizeof string), ""#zelena"[VOZAC KAMIONA] "#bijela"%s je dostavio teret za "#error"%02i:%02i "#bijela"minuta.",GetName(i),ruta_min{i},ruta_sec{i}); format(string2, (sizeof string2), ""#zelena"[TRUCKER] "#bijela"%s submitted a package at a time "#error"%02i:%02i "#bijela"minutes.",GetName(i),ruta_min{i},ruta_sec{i}); }
				else if(Team{i} == 7) { format(string, (sizeof string), ""#zelena"[MOREPLOVAC] "#bijela"%s je zavrsio sa misijom u vremenskom periodu od "#error"%02i:%02i "#bijela"minuta.",GetName(i),ruta_min{i},ruta_sec{i}); format(string2, (sizeof string2), ""#zelena"[SAILOR] "#bijela"%s completed mission during the time period "#error"%02i:%02i "#bijela"minutes.",GetName(i),ruta_min{i},ruta_sec{i}); }
				ScmToAll(string,string2);
				if(Team{i} >= 1 && Team{i} < 4)
				{
				   format(string, (sizeof string), ""#zuta"[ KRATKI INFO ]\n"#bijela"DUZINA RUTE: "#zuta"%i metara\n"#bijela"Shamal: "#zuta"%d ruta obavljeno\n"#bijela"Dodo: "#zuta"%d ruta obavljeno\n"#bijela"Beagle: "#zuta"%d ruta obavljeno\n"#bijela"Hydra: "#zuta"%d ruta obavljeno\n"#bijela"Nevada: "#zuta"%d ruta obavljeno\n"#bijela"At400s: "#zuta"%d ruta obavljeno\n"#bijela"Andromada: "#zuta"%d ruta obavljeno",
				   floatround(RUTA_DUZINA[i]), PlayerInfo[i][Shamal], PlayerInfo[i][Dodo], PlayerInfo[i][Beagle], PlayerInfo[i][Hydra], PlayerInfo[i][Nevada], PlayerInfo[i][At400s], PlayerInfo[i][Andromada]);
				   format(string2, (sizeof string2), ""#zuta"[ SHORT INFO ]\n"#bijela"Length of the route: "#zuta"%i meters\n"#bijela"Shamal: "#zuta"%d routs done\n"#bijela"Dodo: "#zuta"%d routs done\n"#bijela"Beagle: "#zuta"%d routs done\n"#bijela"Hydra: "#zuta"%d routs done\n"#bijela"Nevada: "#zuta"%d routs done\n"#bijela"At400s: "#zuta"%d routs done\n"#bijela"Andromada: "#zuta"%d routs done",
				   floatround(RUTA_DUZINA[i]), PlayerInfo[i][Shamal], PlayerInfo[i][Dodo], PlayerInfo[i][Beagle], PlayerInfo[i][Hydra], PlayerInfo[i][Nevada], PlayerInfo[i][At400s], PlayerInfo[i][Andromada]);
				   CreateDialog(i, DIALOG_ENDROUTE, DIALOG_STYLE_MSGBOX, ""#bijela"RUTA", string, "OK", "", ""#bijela"ROUTE", string2, "OK", "");
	            }
				ruta_sec{i} = (0);
                ruta_min{i} = (0);
                bonus_[i] = (578.00);
			 }
		  }
	   }
	   if(PlayerLogin{i} == true)
	   {
           TextDrawShowForPlayer(i, Sat);
           TextDrawShowForPlayer(i, Text:sfpInfo[i]);
           if(posao{i} == false)
           {
			   TextSet(Text:work_Info[i], "/work za pocetak posla!", "/work to start with job!");
			   TextDrawShowForPlayer(i, Text:work_Info[i]);
           }
           else if(posao{i} == true)
           {
               TextSet(Text:work_Info[i], "_", "_");
               TextDrawHideForPlayer(i, Text:work_Info[i]);
           }
		   if(online_sec{i} == 60)
		   {
              online_sec{i} = (0);
              PlayerInfo[i][Minute] ++;
              if(PlayerInfo[i][Minute] == 60)
              {
				  PlayerInfo[i][Sati] ++;
				  PlayerInfo[i][Minute] = (0);
              }
		   }
           online_sec{i} ++;
	   }
	   if(IsPlayerInAnyVehicle(i))
	   {
            if(IsAPlane(GetPlayerVehicleID(i)) && GetSpeed(i) >= 1)
            {
				new Float:v_Q[1];
				GetVehicleZAngle(GetPlayerVehicleID(i), v_Q[0]);
				format(string, (sizeof string), "%i %i [%i] %i %i", randomEx(10,20), randomEx(20,30), floatround(v_Q[0]), randomEx(15,25), randomEx(25,40));
				TextSet(Nagib[i], string, string);
				TextDrawShowForPlayer(i, Nagib[i]);
            }
            else if(!IsAPlane(GetPlayerVehicleID(i)))
            {
                TextDrawHideForPlayer(i, Nagib[i]);
            }
            if(Gorivo[GetPlayerVehicleID(i)] <= 25 && Gorivo[GetPlayerVehicleID(i)] > 0)
		    {
                PlayerPlaySound(i, 1057, 0.0, 0.0, 0.0);
		    }
		    if(Gorivo[GetPlayerVehicleID(i)] >= 1)
			{
                new engine, lights, alarm, doors, bonnet, boot, objective;
                GetVehicleParamsEx(GetPlayerVehicleID(i), engine, lights, alarm, doors, bonnet, boot, objective);
                SetVehicleParamsEx(GetPlayerVehicleID(i), true, lights, alarm, doors, bonnet, boot, objective);
			}
			new Float:vehHelti, Float:Pos[3];
			GetVehiclePos(GetPlayerVehicleID(i), Pos[0], Pos[1], Pos[2]);
			GetVehicleHealth(GetPlayerVehicleID(i), vehHelti);
			if(TIMER_GORIVO{GetPlayerVehicleID(i)} >= 1)
			{
			   TIMER_GORIVO{GetPlayerVehicleID(i)} --;
			   if(TIMER_GORIVO{GetPlayerVehicleID(i)} == 0)
			   {
				  Gorivo[GetPlayerVehicleID(i)] --;
				  if(Gorivo[GetPlayerVehicleID(i)] <= 0)
				  {
                     new engine, lights, alarm, doors, bonnet, boot, objective;
                     GetVehicleParamsEx(GetPlayerVehicleID(i), engine, lights, alarm, doors, bonnet, boot, objective);
                     SetVehicleParamsEx(GetPlayerVehicleID(i), false, lights, alarm, doors, bonnet, boot, objective);
                     GameText(i, "~r~Nema goriva!", "~r~No fuel!", 2500, 3);
				  }
				  else if(Gorivo[GetPlayerVehicleID(i)] >= 1)
				  {
                     TIMER_GORIVO{GetPlayerVehicleID(i)} = (15);
				  }
			   }
			}
			if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
			{
			   new LOCATION_ZONE[2][128],Float:udaljenost;
               Get2DZone(Pos[0],Pos[1],LOCATION_ZONE[0],128);
               Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128);
               if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == -167.7516 && Udaljenost[i][1] == -3155.3875)
               {
                   format(LOCATION_ZONE[1], 128, "Blood Island - Gate D");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == -3569.1108 && Udaljenost[i][1] == 700.9363)
               {
                   format(LOCATION_ZONE[1], 128, "San Fiero - Gate C");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == -1654.4570 && Udaljenost[i][1] == 3174.6089)
               {
                   format(LOCATION_ZONE[1], 128, "BaySide - Gate A");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == 3669.9292 && Udaljenost[i][1] == -2226.7297)
               {
                   format(LOCATION_ZONE[1], 128, "Christmas Island");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == 3538.2097 && Udaljenost[i][1] == -600.5150)
               {
                   format(LOCATION_ZONE[1], 128, "Insular Island");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == 3767.7461 && Udaljenost[i][1] == 1360.0083)
               {
                   format(LOCATION_ZONE[1], 128, "Island of death");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == 1835.7872 && Udaljenost[i][1] == -4033.4573)
               {
                   format(LOCATION_ZONE[1], 128, "Emperor Seamounts Island");
               }
               else if(!Get2DZone(Udaljenost[i][0], Udaljenost[i][1],LOCATION_ZONE[1],128) && Udaljenost[i][0] == -83.8109 && Udaljenost[i][1] == 5041.5020)
               {
                   format(LOCATION_ZONE[1], 128, "Kerguelen Island");
               }
               if(!Get2DZone(Pos[0],Pos[1],LOCATION_ZONE[0],128))
               {
				   format(LOCATION_ZONE[0], 128, "Loading..."); 
               }
               udaljenost=GetDistanceFromPointToPoint(Udaljenost[i][0], Udaljenost[i][1], Udaljenost[i][2], Pos[0],Pos[1],Pos[2]);
			   if(IsPlayerLanguage(i, JEZIK_BALKAN))
			   {
				   if(posao{i} == true)
				   {
						format(string, (sizeof string), "~r~BRZINA~w~: %i km/h~n~~n~~r~GORIVO~w~: %i~n~~n~~r~ZDRAVLJE~w~: %i~n~~n~~r~VISINA~w~: %i m",GetSpeed(i),Gorivo[GetPlayerVehicleID(i)],floatround(vehHelti),floatround(Pos[2]));
						PlayerTextSet(i, PlayerText:TABLA[1][i], string, string);
                        format(string, (sizeof string), "~r~LOKACIJA~w~: %s~n~~n~~r~UDALJENOST~w~: %d m~n~~n~~r~DESTINACIJA~w~: %s~n~~n~~r~VOZILO~w~: %s",LOCATION_ZONE[0],floatround(udaljenost),LOCATION_ZONE[1],VehicleNames[GetVehicleModel(GetPlayerVehicleID(i))-400]);
                        PlayerTextSet(i, PlayerText:TABLA[2][i], string, string);

                        PlayerTextDrawShow(i, PlayerText:TABLA[0][i]); PlayerTextDrawShow(i, PlayerText:TABLA[1][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[2][i]); PlayerTextDrawShow(i, PlayerText:TABLA[3][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[4][i]); PlayerTextDrawShow(i, PlayerText:TABLA[5][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[6][i]); PlayerTextDrawShow(i, PlayerText:TABLA[7][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[8][i]); PlayerTextDrawShow(i, PlayerText:TABLA[9][i]);
				   }
				   else if(posao{i} == false)
				   {
					     format(string, (sizeof string), "~r~BRZINA~w~: %i km/h~n~~n~~r~GORIVO~w~: %i~n~~n~~r~ZDRAVLJE~w~: %i~n~~n~~r~VOZILO~w~: %s",GetSpeed(i),Gorivo[GetPlayerVehicleID(i)],floatround(vehHelti),VehicleNames[GetVehicleModel(GetPlayerVehicleID(i))-400]);
					     PlayerTextSet(i, PlayerText:TABLA[1][i], string, string);
					     
					     PlayerTextDrawShow(i, PlayerText:TABLA[1][i]); PlayerTextDrawHide(i, PlayerText:TABLA[0][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[2][i]); PlayerTextDrawHide(i, PlayerText:TABLA[3][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[4][i]); PlayerTextDrawHide(i, PlayerText:TABLA[5][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[6][i]); PlayerTextDrawHide(i, PlayerText:TABLA[7][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[8][i]); PlayerTextDrawHide(i, PlayerText:TABLA[9][i]);
				   }
			   }
			   else if(IsPlayerLanguage(i, JEZIK_ENGLISH))
			   {
                   if(posao{i} == true)
				   {
						format(string, (sizeof string), "~r~SPEED~w~: %i km/h~n~~n~~r~FUEL~w~: %i~n~~n~~r~HEALTH~w~: %i~n~~n~~r~ALTITUDE~w~: %i m",GetSpeed(i),Gorivo[GetPlayerVehicleID(i)],floatround(vehHelti),floatround(Pos[2]));
						PlayerTextSet(i, PlayerText:TABLA[1][i], string, string);
						format(string, (sizeof string), "~r~LOCATION~w~: %s~n~~n~~r~DISTANCE~w~: %d m~n~~n~~r~DESTINATION~w~: %s~n~~n~~r~VEHICLE~w~: %s",LOCATION_ZONE[0],floatround(udaljenost),LOCATION_ZONE[1],VehicleNames[GetVehicleModel(GetPlayerVehicleID(i))-400]);
                        PlayerTextSet(i, PlayerText:TABLA[2][i], string, string);
                        
                        PlayerTextDrawShow(i, PlayerText:TABLA[0][i]); PlayerTextDrawShow(i, PlayerText:TABLA[1][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[2][i]); PlayerTextDrawShow(i, PlayerText:TABLA[3][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[4][i]); PlayerTextDrawShow(i, PlayerText:TABLA[5][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[6][i]); PlayerTextDrawShow(i, PlayerText:TABLA[7][i]);
                        PlayerTextDrawShow(i, PlayerText:TABLA[8][i]); PlayerTextDrawShow(i, PlayerText:TABLA[9][i]);
				   }
				   else if(posao{i} == false)
				   {
					     format(string, (sizeof string), "~r~SPEED~w~: %i km/h~n~~n~~r~FUEL~w~: %i~n~~n~~r~HEALTH~w~: %i~n~~n~~r~VEHICLE~w~: %s",GetSpeed(i),Gorivo[GetPlayerVehicleID(i)],floatround(vehHelti),VehicleNames[GetVehicleModel(GetPlayerVehicleID(i))-400]);
					     PlayerTextSet(i, PlayerText:TABLA[1][i], string, string);
					     
					     PlayerTextDrawShow(i, PlayerText:TABLA[1][i]); PlayerTextDrawHide(i, PlayerText:TABLA[0][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[2][i]); PlayerTextDrawHide(i, PlayerText:TABLA[3][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[4][i]); PlayerTextDrawHide(i, PlayerText:TABLA[5][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[6][i]); PlayerTextDrawHide(i, PlayerText:TABLA[7][i]);
					     PlayerTextDrawHide(i, PlayerText:TABLA[8][i]); PlayerTextDrawHide(i, PlayerText:TABLA[9][i]);
				   }
			   }
			}
	   }
	   else if(!IsPlayerInAnyVehicle(i))
	   {
		  PlayerTextDrawHide(i, PlayerText:TABLA[0][i]); PlayerTextDrawHide(i, PlayerText:TABLA[1][i]);
		  PlayerTextDrawHide(i, PlayerText:TABLA[2][i]); PlayerTextDrawHide(i, PlayerText:TABLA[3][i]);
		  PlayerTextDrawHide(i, PlayerText:TABLA[4][i]); PlayerTextDrawHide(i, PlayerText:TABLA[5][i]);
		  PlayerTextDrawHide(i, PlayerText:TABLA[6][i]); PlayerTextDrawHide(i, PlayerText:TABLA[7][i]);
		  PlayerTextDrawHide(i, PlayerText:TABLA[8][i]); PlayerTextDrawHide(i, PlayerText:TABLA[9][i]);
		  TextDrawHideForPlayer(i, Nagib[i]);
	   }
	}
	return (true);
}

stock bool:IsPlayerNearAirportPetrol(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 10.0, 1917.6833,-2433.4207,13.1946)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 10.0, 1353.5370,1315.1051,10.3609)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 10.0, -1325.4257,-77.8169,13.8069)) return (true);
	else return (false);
}

stock bool:IsPlayerNearBoatPetrol(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 15.0, 2790.2019,-2318.3320,4.5449)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 2220.2568,523.8825,3.8399)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -1373.1731,1034.8998,4.3017)) return (true);
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -1372.4905,1050.9585,3.5106)) return (true);
	else return (false);
}

stock bool:IsPlayerNearPetrol(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 10.0, 1004.0070,-939.3102,42.1797) || IsPlayerInRangeOfPoint(playerid, 10.0, 1944.3260,-1772.9254,13.3906)) return (true); // LOS SANTOS
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,-90.5515,-1169.4578,2.4079) || IsPlayerInRangeOfPoint(playerid, 10.0,-1609.7958,-2718.2048,48.5391)) return (true); // LOS SANTOS
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,-2029.4968,156.4366,28.9498) || IsPlayerInRangeOfPoint(playerid, 10.0, -2408.7590,976.0934,45.4175)) return (true); // SAN FIERO
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,-2243.9629,-2560.6477,31.8841) || IsPlayerInRangeOfPoint(playerid, 10.0,-1676.6323,414.0262,6.9484)) return (true); // IZMEDU LOS SANTOSA I SAN FIERA
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,2202.2349,2474.3494,10.5258) || IsPlayerInRangeOfPoint(playerid, 10.0,614.9333,1689.7418,6.6968)) return (true); // LAS VENTURAS
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,-1328.8250,2677.2173,49.7665) || IsPlayerInRangeOfPoint(playerid, 10.0,70.3882,1218.6783,18.5165)) return (true); // LAS VENTURAS
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,2113.7390,920.1079,10.5255) || IsPlayerInRangeOfPoint(playerid, 10.0,-1327.7218,2678.8723,50.0625)) return (true); // LAS VENTURAS
    else if(IsPlayerInRangeOfPoint(playerid, 10.0,656.4265,-559.8610,16.5015) || IsPlayerInRangeOfPoint(playerid, 10.0,656.3797,-570.4138,16.5015)) return (true); // DILIMORE
	else return (false);
}

stock PreuzimanjePaketaCivilniPiloti(playerid)
{
	new
	   pickup = random(15);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, 1820.2239,-2445.3677,13.5547, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, 1587.0925,1303.1868,11.3028, 10.0,1); }
        case (2):{ SetPlayerCheckPoint(playerid, 408.3156,2505.4912,16.4844, 10.0,1); }
        case (3):{ SetPlayerCheckPoint(playerid, -1518.5479,-102.2048,14.1484, 10.0,1); }
        case (4):{ SetPlayerCheckPoint(playerid, -167.7516,-3155.3875,22.9567, 10.0,1);  } 
        case (5):{ SetPlayerCheckPoint(playerid, -1983.6591,2152.6338,5.2697, 10.0,1);  }
        case (6):{ SetPlayerCheckPoint(playerid, 2505.6553,601.4269,13.8640, 10.0,1);  }
        case (7):{ SetPlayerCheckPoint(playerid, 1214.2379,2599.4412,14.7700, 10.0,1);  }
        case (8):{ SetPlayerCheckPoint(playerid, -3569.1108,700.9363,4.2666, 10.0,1);  }
        case (9):{ SetPlayerCheckPoint(playerid, -2208.8142,1686.1436,1.7000, 10.0,1);  }
        case (10):{ SetPlayerCheckPoint(playerid, -215.9792,-2264.9004,30.0307, 10.0,1);  }
        case (11):{ SetPlayerCheckPoint(playerid, 868.5050,2281.9983,14.2480, 10.0,1);  }
        case (12):{ SetPlayerCheckPoint(playerid, -83.8109,5041.5020,6.4898, 10.0,1);  }
        case (13):{ SetPlayerCheckPoint(playerid, -1524.1448,2455.7744,66.8577, 10.0,1);  }
        case (14):{ SetPlayerCheckPoint(playerid, 2789.8750,2804.9658,13.2433, 10.0,1);  }
        default: { PreuzimanjePaketaCivilniPiloti(playerid); }
	}
	return (true);
}

stock OstavljanjePaketaCivilniPiloti(playerid)
{
	new
	   pickup = random(14);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -17.7255,-152.6557,5.4964); SetPlayerCheckPoint(playerid, -17.7255,-152.6557,5.4964, 10.0,2); } // BLUBERY
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2445.8621,-201.2445,27.5299); SetPlayerCheckPoint(playerid, 2445.8621,-201.2445,27.5299, 10.0,2);} // PALAMINO
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1654.4570,3174.6089,3.6300); SetPlayerCheckPoint(playerid, -1654.4570,3174.6089,3.6300, 10.0,2); } // BAYSIDE
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 277.8040,-1802.1635,4.5263); SetPlayerCheckPoint(playerid, 277.8040,-1802.1635,4.5263, 10.0,2);  } // MALA LS LUKA
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2477.0676,2550.3010,27.7226); SetPlayerCheckPoint(playerid, -2477.0676,2550.3010,27.7226, 10.0,2);  } // BAYSIDE (Slay)
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2937.3599,859.4731,15.6172); SetPlayerCheckPoint(playerid, -2937.3599,859.4731,15.6172, 10.0,2);  } // SAN FIERO (Slay)
		case (6):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2412.7639,-2781.4104,18.4420); SetPlayerCheckPoint(playerid, -2412.7639,-2781.4104,18.4420, 10.0,2);  } // ..Neno...
		case (7):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 3669.9292,-2226.7297,4.7359); SetPlayerCheckPoint(playerid, 3669.9292,-2226.7297,4.7359, 10.0,2);  }
		case (8):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 3538.2097,-600.5150,29.7257); SetPlayerCheckPoint(playerid, 3538.2097,-600.5150,29.7257, 10.0,2);  }
		case (9):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 731.4704,-396.4431,20.7770); SetPlayerCheckPoint(playerid, 731.4704,-396.4431,20.7770, 10.0,2);  }
		case (10):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1581.8875,-742.7872,85.0813); SetPlayerCheckPoint(playerid, 1581.8875,-742.7872,85.0813, 10.0,2);  }
		case (11):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 3767.7461,1360.0083,6.2433); SetPlayerCheckPoint(playerid, 3767.7461,1360.0083,6.2433, 10.0,2);  }
		case (12):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1835.7872,-4033.4573,6.1844); SetPlayerCheckPoint(playerid, 1835.7872,-4033.4573,6.1844, 10.0,2);  }
		case (13):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1100.5045,-967.1624,132.7859); SetPlayerCheckPoint(playerid, -1100.5045,-967.1624,132.7859, 10.0,2);  }
        default: { OstavljanjePaketaCivilniPiloti(playerid); }
	}
	return (true);
}

stock PreuzimanjePaketaMediPiloti(playerid)
{
    new
	   pickup = random(12);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, 1630.0992,1548.6392,11.6550, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, 133.5327,36.4438,2.8000, 10.0,1); }
        case (2):{ SetPlayerCheckPoint(playerid, 124.2226,10.4405,2.7760, 10.0,1); }
        case (3):{ SetPlayerCheckPoint(playerid, 2383.9475,-132.2205,30.4347, 10.0,1); }
        case (4):{ SetPlayerCheckPoint(playerid, 1765.3400,-2285.1282,26.8983, 10.0,1);  }
        case (5):{ SetPlayerCheckPoint(playerid, 216.6212,-1833.4395,4.5951, 10.0,1);  }
        case (6):{ SetPlayerCheckPoint(playerid, -1579.3621,-655.0008,14.9712, 10.0,1);  }
        case (7):{ SetPlayerCheckPoint(playerid, -2937.3599,859.4731,15.6172, 10.0,1);  }
        case (8):{ SetPlayerCheckPoint(playerid, -2424.5488,-2750.5942,18.4420, 10.0,1);  }
        case (9):{ SetPlayerCheckPoint(playerid, 1186.2920,2555.2507,14.9378, 10.0,1);  }
        case (10):{ SetPlayerCheckPoint(playerid, 880.1456,2337.0542,13.0281, 10.0,1);  }
        case (11):{ SetPlayerCheckPoint(playerid, 2866.8503,2732.9492,15.4679, 10.0,1);  }
        default: { PreuzimanjePaketaMediPiloti(playerid); }
	}
	return (true);
}

stock OstavljanjePaketaMediPiloti(playerid)
{
	new
	   pickup = random(12);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1543.6143,-1352.7667,329.4750); SetPlayerCheckPoint(playerid, 1543.6143,-1352.7667,329.4750, 10.0,2); }
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2227.5637,2327.0232,7.5469);   SetPlayerCheckPoint(playerid, -2227.5637,2327.0232,7.5469, 10.0,2);}
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -181.5977,-3159.1284,22.9567);  SetPlayerCheckPoint(playerid, -181.5977,-3159.1284,22.9567, 10.0,2); }
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2897.6531,459.7366,4.9141);    SetPlayerCheckPoint(playerid, -2897.6531,459.7366,4.9141, 10.0,2);  }
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1679.8584,705.4893,30.6016);   SetPlayerCheckPoint(playerid, -1679.8584,705.4893,30.6016, 10.0,2);  }
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2092.6475,2414.2036,74.5786);   SetPlayerCheckPoint(playerid, 2092.6475,2414.2036,74.5786, 10.0,2);  }
		case (6):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1983.6591,2152.6338,5.2697);   SetPlayerCheckPoint(playerid, -1983.6591,2152.6338,5.2697, 10.0,2);  }
		case (7):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1579.3621,-655.0008,14.9712);  SetPlayerCheckPoint(playerid, -1579.3621,-655.0008,14.9712, 10.0,2);  }
		case (8):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2410.2246,601.6835,13.8459);    SetPlayerCheckPoint(playerid, 2410.2246,601.6835,13.8459, 10.0,2);  }
		case (9):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -241.7056,-2250.5732,28.5594);    SetPlayerCheckPoint(playerid, -241.7056,-2250.5732,28.5594, 10.0,2);  }
		case (10):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -3515.2705,618.6270,4.2635);    SetPlayerCheckPoint(playerid, -3515.2705,618.6270,4.2635, 10.0,2);  }
		case (11):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1166.3108,-1027.1952,135.6281);    SetPlayerCheckPoint(playerid, -1166.3108,-1027.1952,135.6281, 10.0,2);  }
        default: { OstavljanjePaketaMediPiloti(playerid); }
	}
	return (true);
}

stock PreuzimanjeTereta(playerid)
{
    new
	   pickup = random(9);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, -1018.8042,-662.1716,32.6140, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, -148.9576,-209.8777,2.0320, 10.0,1); }
		case (2):{ SetPlayerCheckPoint(playerid, 250.5467,1420.5999,11.1669, 10.0,1); }
		case (3):{ SetPlayerCheckPoint(playerid, 133.2000,1951.2505,20.0045, 10.0,1); }
		case (4):{ SetPlayerCheckPoint(playerid, -367.0289,1580.9894,76.8469, 10.0,1); }
		case (5):{ SetPlayerCheckPoint(playerid, -1735.9423,160.3203,3.5547, 10.0,1); }
		case (6):{ SetPlayerCheckPoint(playerid, -2136.2351,-162.8315,36.0260, 10.0,1); }
		case (7):{ SetPlayerCheckPoint(playerid, 2764.7686,-2453.0420,13.8407, 10.0,1); }
		case (8):{ SetPlayerCheckPoint(playerid, 2602.3999,666.1838,10.8387, 10.0,1); }
        default: { PreuzimanjeTereta(playerid); }
	}
	return (true);
}


stock OstavljanjePaketa(playerid)
{
    new
	   pickup = random(10);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1585.3923,-2715.9014,49.1451); SetPlayerCheckPoint(playerid, -1585.3923,-2715.9014,49.1451, 10.0,2); }
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2063.1611,-2360.0354,31.2388); SetPlayerCheckPoint(playerid, -2063.1611,-2360.0354,31.2388, 10.0,2); }
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2399.3704,-2176.6172,33.8960); SetPlayerCheckPoint(playerid, -2399.3704,-2176.6172,33.8960, 10.0,2); }
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2527.2473,-612.3350,133.1682); SetPlayerCheckPoint(playerid, -2527.2473,-612.3350,133.1682, 10.0,2); }
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -783.6092,1439.3378,14.3942); SetPlayerCheckPoint(playerid, -783.6092,1439.3378,14.3942, 10.0,2); }
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1490.9301,1868.3748,33.1605); SetPlayerCheckPoint(playerid, -1490.9301,1868.3748,33.1605, 10.0,2); }
		case (6):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2262.9834,2292.1509,5.4264); SetPlayerCheckPoint(playerid, -2262.9834,2292.1509,5.4264, 10.0,2); }
		case (7):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 40.8622,-57.8158,3.6468); SetPlayerCheckPoint(playerid, 40.8622,-57.8158,3.6468, 10.0,2); }
		case (8):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1396.2473,381.7361,20.3642); SetPlayerCheckPoint(playerid, 1396.2473,381.7361,20.3642, 10.0,2); }
		case (9):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1921.7617,2193.1479,5.3843); SetPlayerCheckPoint(playerid, -1921.7617,2193.1479,5.3843, 10.0,2); }
        default: { OstavljanjePaketa(playerid); }
	}
	return (true);
}

stock PreuzimanjeTereta_Brod(playerid)
{
    new
	   pickup = random(8);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, 2095.6099,-108.5217,0.0906, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, 2962.5762,2112.8745,-0.0978, 10.0,1); }
		case (2):{ SetPlayerCheckPoint(playerid, 1632.4124,570.5596,0.2104, 10.0,1); }
		case (3):{ SetPlayerCheckPoint(playerid, -649.4985,863.6506,0.1335, 10.0,1); }
		case (4):{ SetPlayerCheckPoint(playerid, -845.2629,1375.2808,0.0931, 10.0,1); }
		case (5):{ SetPlayerCheckPoint(playerid, 49.0052,-1122.2561,-0.5961, 10.0,1); }
		case (6):{ SetPlayerCheckPoint(playerid, -1655.9536,251.3498,-0.4953, 10.0,1); }
        default: { PreuzimanjeTereta_Brod(playerid); }
	}
	return (true);
}

stock OstavljanjeTereta_Brod(playerid)
{
    new
	   pickup = random(9);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2324.8855,2292.7051,-0.4896); SetPlayerCheckPoint(playerid, -2324.8855,2292.7051,-0.4896, 10.0,1); }
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2957.6799,499.1809,-0.7922); SetPlayerCheckPoint(playerid, -2957.6799,499.1809,-0.7922, 10.0,1); }
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 952.2441,-2002.2433,-0.5112); SetPlayerCheckPoint(playerid, 952.2441,-2002.2433,-0.5112, 10.0,1); }
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2934.9385,-2023.6383,-0.3569); SetPlayerCheckPoint(playerid, 2934.9385,-2023.6383,-0.3569, 10.0,1); }
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2693.7971,-2193.7603,-0.4598); SetPlayerCheckPoint(playerid, -2693.7971,-2193.7603,-0.4598, 10.0,1); }
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1351.4539,-2007.1973,-0.5544); SetPlayerCheckPoint(playerid, -1351.4539,-2007.1973,-0.5544, 10.0,1); }
		case (6):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 252.9211,2930.0706,-1.6016); SetPlayerCheckPoint(playerid, 252.9211,2930.0706,-1.6016, 10.0,1); }
		case (7):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2161.4348,1373.4543,-0.7421); SetPlayerCheckPoint(playerid, -2161.4348,1373.4543,-0.7421, 10.0,1); }
        default: { OstavljanjeTereta_Brod(playerid); }
	}
	return (true);
}

stock PreuzimanjePutnikaSF(playerid)
{
    new
	   pickup = random(8);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, -1987.6263,269.1466,35.1837, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, -2240.1270,559.8912,35.0168, 10.0,1); }
		case (2):{ SetPlayerCheckPoint(playerid, -2650.3591,589.7601,14.4575, 10.0,1); }
		case (3):{ SetPlayerCheckPoint(playerid, -2742.2993,742.3940,48.6515, 10.0,1); }
		case (4):{ SetPlayerCheckPoint(playerid, -2518.9429,1222.2988,37.4302, 10.0,1); }
		case (5):{ SetPlayerCheckPoint(playerid, -2618.7810,1377.0566,7.1332, 10.0,1); }
		case (6):{ SetPlayerCheckPoint(playerid, -1954.6575,1314.2142,7.0440, 10.0,1); }
		case (7):{ SetPlayerCheckPoint(playerid, -1973.2982,1117.4620,53.4741, 10.0,1); }
        default: { PreuzimanjePutnikaSF(playerid); }
	}
	return (true);
}

stock OstavljanjePutnikaSF(playerid)
{
    new
	   pickup = random(9);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1599.8751,856.7066,7.5406);   SetPlayerCheckPoint(playerid, -1599.8751,856.7066,7.5406, 10.0,2); }
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -1416.7754,-305.5974,14.0015); SetPlayerCheckPoint(playerid, -1416.7754,-305.5974,14.0015, 10.0,2); }
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2120.4895,-381.4710,35.3404); SetPlayerCheckPoint(playerid, -2120.4895,-381.4710,35.3404, 10.0,2); }
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2315.3464,-165.6680,35.3254); SetPlayerCheckPoint(playerid, -2315.3464,-165.6680,35.3254, 10.0,2); }
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2278.5652,127.4065,35.1664); SetPlayerCheckPoint(playerid, -2278.5652,127.4065,35.1664, 10.0,2); }
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2763.7520,67.2979,6.9347); SetPlayerCheckPoint(playerid, -2763.7520,67.2979,6.9347, 10.0,2); }
		case (6):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2778.8667,-313.7296,7.0444); SetPlayerCheckPoint(playerid, -2778.8667,-313.7296,7.0444, 10.0,2); }
		case (7):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2501.4187,-602.8055,132.5636); SetPlayerCheckPoint(playerid, -2501.4187,-602.8055,132.5636, 10.0,2); }
		case (8):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -2026.2419,-859.1129,32.1771); SetPlayerCheckPoint(playerid, -2026.2419,-859.1129,32.1771, 10.0,2); }
        default: { OstavljanjePutnikaSF(playerid); }
	}
	return (true);
}

stock PreuzimanjePutnikaLV(playerid)
{
    new
	   pickup = random(7);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, 2492.0413,1532.1825,10.4551, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, 2616.3457,1824.6318,10.5992, 10.0,1); }
		case (2):{ SetPlayerCheckPoint(playerid, 2290.5176,2416.5496,10.5220, 10.0,1); }
		case (3):{ SetPlayerCheckPoint(playerid, 2269.8745,2287.2393,10.4522, 10.0,1); }
		case (4):{ SetPlayerCheckPoint(playerid, 2078.0156,2169.7432,10.5990, 10.0,1); }
		case (5):{ SetPlayerCheckPoint(playerid, 1612.4008,2204.0007,10.5990, 10.0,1); }
		case (6):{ SetPlayerCheckPoint(playerid, 1541.5048,2131.5569,11.0205, 10.0,1); }
        default: { PreuzimanjePutnikaLV(playerid); }
	}
	return (true);
}

stock OstavljanjePutnikaLV(playerid)
{
    new
	   pickup = random(8);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 950.6763,1733.1368,8.4274); SetPlayerCheckPoint(playerid, 950.6763,1733.1368,8.4274, 10.0,2); }
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 695.9177,1946.4391,5.3191); SetPlayerCheckPoint(playerid, 695.9177,1946.4391,5.3191, 10.0,2); }
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -540.5273,2589.1887,53.1929); SetPlayerCheckPoint(playerid, -540.5273,2589.1887,53.1929, 10.0,2); }
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -768.1880,2756.8745,45.5421); SetPlayerCheckPoint(playerid, -768.1880,2756.8745,45.5421, 10.0,2); }
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -199.3456,1223.0701,19.5208); SetPlayerCheckPoint(playerid, -199.3456,1223.0701,19.5208, 10.0,2); }
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1489.6350,711.9115,10.5216); SetPlayerCheckPoint(playerid, 1489.6350,711.9115,10.5216, 10.0,2); }
		case (6):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2723.4175,850.3826,10.5277); SetPlayerCheckPoint(playerid, 2723.4175,850.3826,10.5277, 10.0,2); }
		case (7):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2423.3391,1121.8843,10.4494); SetPlayerCheckPoint(playerid, 2423.3391,1121.8843,10.4494, 10.0,2); }
        default: { OstavljanjePutnikaLV(playerid); }
	}
	return (true);
}

stock PreuzimanjePutnikaLS(playerid)
{
    new
	   pickup = random(7);
	switch(pickup)
	{
		case (0):{ SetPlayerCheckPoint(playerid, 1825.3351,-1684.2118,13.1597, 10.0,1); }
		case (1):{ SetPlayerCheckPoint(playerid, 1489.1324,-1735.4082,13.1595, 10.0,1); }
		case (2):{ SetPlayerCheckPoint(playerid, 1244.2435,-2037.6149,59.6554, 10.0,1); }
		case (3):{ SetPlayerCheckPoint(playerid, 1228.4476,-1826.8654,13.1881, 10.0,1); }
		case (4):{ SetPlayerCheckPoint(playerid, 1634.9512,-2321.9961,-3.0739, 10.0,1); }
		case (5):{ SetPlayerCheckPoint(playerid, 2479.9424,-2558.1453,13.3543, 10.0,1); }
		case (6):{ SetPlayerCheckPoint(playerid, 2793.7092,-1834.9034,9.6350, 10.0,1); }
        default: { PreuzimanjePutnikaLS(playerid); }
	}
	return (true);
}

stock OstavljanjePutnikaLS(playerid)
{
    new
	   pickup = random(6);
	switch(pickup)
	{
		case (0):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 2273.6565,-1039.6146,50.3119); SetPlayerCheckPoint(playerid, 2273.6565,-1039.6146,50.3119, 10.0,2); }
		case (1):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1463.2156,-1030.6320,23.4329); SetPlayerCheckPoint(playerid, 1463.2156,-1030.6320,23.4329, 10.0,2); }
		case (2):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 1512.1545,-695.7711,94.5266); SetPlayerCheckPoint(playerid, 1512.1545,-695.7711,94.5266, 10.0,2); }
		case (3):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 293.9854,-1160.3805,80.6868); SetPlayerCheckPoint(playerid, 293.9854,-1160.3805,80.6868, 10.0,2); }
		case (4):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], 367.7097,-2035.6860,7.4500); SetPlayerCheckPoint(playerid, 367.7097,-2035.6860,7.4500, 10.0,2); }
		case (5):{ RUTA_DUZINA[playerid] = GetDistanceFromPointToPoint(Udaljenost[playerid][0], Udaljenost[playerid][1], Udaljenost[playerid][2], -31.1769,-2493.3115,36.4263); SetPlayerCheckPoint(playerid, -31.1769,-2493.3115,36.4263, 10.0,2); }
        default: { OstavljanjePutnikaLS(playerid); }
	}
	return (true);
}

stock bool:IsPlayerHaveRadio(playerid)
{
   if(strcmp(PlayerInfo[playerid][Radio], "Da", true) == 0) return (true);
   else return (false);
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	if(CP[playerid] == 1) // PREUZIMANJE
	{
	   if(GetPlayerVehicleID(playerid) != work_vehicle[playerid]) return GameText(playerid, "~r~Moras biti u istom vozilu!", "~r~You are not in the same vehicle!", 2500, 3);
	   else if(GetSpeed(playerid) >= 50) return GameText(playerid, "~r~USPORI!", "~r~SLOW DOWN!", 2500, 3);
       DisablePlayerRaceCheckpoint(playerid);
	   Freeze(playerid, 1);
	   TIMER_LOAD[playerid] = (8);
	   antiTAB{playerid} = (true);

       TextDrawDestroy(loading_[playerid][2]);
       loading_[playerid][2] = TextDrawCreate(242.000000, 173.000000, "_");
       TextDrawBackgroundColor(loading_[playerid][2], 255);
       TextDrawFont(loading_[playerid][2], 1);
       TextDrawLetterSize(loading_[playerid][2], 0.480000, 2.699999);
       TextDrawColor(loading_[playerid][2], -1);
       TextDrawSetOutline(loading_[playerid][2], 0);
   	   TextDrawSetProportional(loading_[playerid][2], 1);
   	   TextDrawSetShadow(loading_[playerid][2], 1);
   	   TextDrawUseBox(loading_[playerid][2], 1);
   	   TextDrawBoxColor(loading_[playerid][2], 25690);
       TextDrawTextSize(loading_[playerid][2], load_bar[playerid], 0.000000);
       
       TextSet(loading_[playerid][1], "Pricekajte", "Loading...");
	   TextDrawShowForPlayer(playerid, loading_[playerid][0]);
	   TextDrawShowForPlayer(playerid, loading_[playerid][1]);
	   TextDrawShowForPlayer(playerid, loading_[playerid][2]);
	}
	else if(CP[playerid] == 2) // OSTAVLJANJE
	{
       if(GetPlayerVehicleID(playerid) != work_vehicle[playerid]) return GameText(playerid, "~r~Moras biti u istom vozilu!", "~r~You are not in the same vehicle!", 2500, 3);
       else if(GetSpeed(playerid) >= 50) return GameText(playerid, "~r~USPORI!", "~r~SLOW DOWN!", 2500, 3);
	   DisablePlayerRaceCheckpoint(playerid);
	   Freeze(playerid, 1);
	   TIMER_LOAD[playerid] = (8);
	   antiTAB{playerid} = (true);
	   
	   TextDrawDestroy(loading_[playerid][2]);
       loading_[playerid][2] = TextDrawCreate(242.000000, 173.000000, "_");
       TextDrawBackgroundColor(loading_[playerid][2], 255);
       TextDrawFont(loading_[playerid][2], 1);
       TextDrawLetterSize(loading_[playerid][2], 0.480000, 2.699999);
       TextDrawColor(loading_[playerid][2], -1);
       TextDrawSetOutline(loading_[playerid][2], 0);
   	   TextDrawSetProportional(loading_[playerid][2], 1);
   	   TextDrawSetShadow(loading_[playerid][2], 1);
   	   TextDrawUseBox(loading_[playerid][2], 1);
   	   TextDrawBoxColor(loading_[playerid][2], 25690);
       TextDrawTextSize(loading_[playerid][2], load_bar[playerid], 0.000000);
       
	   TextSet(loading_[playerid][1], "Pricekajte", "Loading...");
	   TextDrawShowForPlayer(playerid, loading_[playerid][0]);
	   TextDrawShowForPlayer(playerid, loading_[playerid][1]);
	   TextDrawShowForPlayer(playerid, loading_[playerid][2]);
	}
	return (true);
}
YCMD:ahelp(playerid, params[], help)
{
	new
	   string[800];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
	else if(PlayerInfo[playerid][Admin] == 1)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff");
	}
	else if(PlayerInfo[playerid][Admin] == 2)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted",string);
	}
	else if(PlayerInfo[playerid][Admin] == 3)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted\n",string);
		format(string, (238+110), "%s"#zuta"[LEVEL 3 ADMINISTRATOR]\n"#bijela"/freeze /unfreeze /akill /setint /setvw /blockpm /fill /fillall",string);
	}
	else if(PlayerInfo[playerid][Admin] == 4)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted\n",string);
        format(string, (348), "%s"#zuta"[LEVEL 3 ADMINISTRATOR]\n"#bijela"/freeze /unfreeze /akill /setint /setvw /blockpm /fill /fillall\n",string);
        format(string, (458), "%s"#zuta"[LEVEL 4 ADMINISTRATOR]\n"#bijela"/vrall /vr /update /praise /savepos /gotopos /invisible",string);
	}
	else if(PlayerInfo[playerid][Admin] == 5)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted\n",string);
        format(string, (348), "%s"#zuta"[LEVEL 3 ADMINISTRATOR]\n"#bijela"/freeze /unfreeze /akill /setint /setvw /blockpm /fill /fillall\n",string);
        format(string, (458), "%s"#zuta"[LEVEL 4 ADMINISTRATOR]\n"#bijela"/vrall /vr /update /praise /savepos /gotopos /invisible\n",string);
        format(string, (512), "%s"#zuta"[LEVEL 5 ADMINISTRATOR]\n"#bijela"/ban /heal /healall /time /merge /ip /cs",string);
	}
	else if(PlayerInfo[playerid][Admin] == 6)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted\n",string);
        format(string, (348), "%s"#zuta"[LEVEL 3 ADMINISTRATOR]\n"#bijela"/freeze /unfreeze /akill /setint /setvw /blockpm /fill /fillall\n",string);
        format(string, (458), "%s"#zuta"[LEVEL 4 ADMINISTRATOR]\n"#bijela"/vrall /vr /update /praise /savepos /gotopos /invisible\n",string);
        format(string, (512), "%s"#zuta"[LEVEL 5 ADMINISTRATOR]\n"#bijela"/ban /heal /healall /time /merge /ip /cs\n",string);
        format(string, (650), "%s"#zuta"[LEVEL 6 ADMINISTRATOR]\n"#bijela"/gmx /fakeban /set /setscore /rocketman",string);
	}
	else if(PlayerInfo[playerid][Admin] == 7)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted\n",string);
        format(string, (348), "%s"#zuta"[LEVEL 3 ADMINISTRATOR]\n"#bijela"/freeze /unfreeze /akill /setint /setvw /blockpm /fill /fillall\n",string);
        format(string, (458), "%s"#zuta"[LEVEL 4 ADMINISTRATOR]\n"#bijela"/vrall /vr /update /praise /savepos /gotopos /invisible\n",string);
        format(string, (512), "%s"#zuta"[LEVEL 5 ADMINISTRATOR]\n"#bijela"/ban /heal /healall /time /merge /ip /cs\n",string);
        format(string, (650), "%s"#zuta"[LEVEL 6 ADMINISTRATOR]\n"#bijela"/gmx /fakeban /set /setscore /rocketman\n",string);
        format(string, (750), "%s"#zuta"[LEVEL 7 ADMINISTRATOR]\n"#bijela"/teles /snow /snowoff /gotocord /createhouse",string);
	}
	else if(PlayerInfo[playerid][Admin] == 8)
	{
		format(string, (128), ""#zuta"[LEVEL 1 ADMINISTRATOR]\n"#bijela"/a /cc /say /goto /get /getcar /gotocar /lcar /check /kick /spec /specoff\n");
		format(string, (238), "%s"#zuta"[LEVEL 2 ADMINISTRATOR]\n"#bijela"/text /warn /slap /fix /fixall /mute /unmute /muted\n",string);
        format(string, (348), "%s"#zuta"[LEVEL 3 ADMINISTRATOR]\n"#bijela"/freeze /unfreeze /akill /setint /setvw /blockpm /fill /fillall\n",string);
        format(string, (458), "%s"#zuta"[LEVEL 4 ADMINISTRATOR]\n"#bijela"/vrall /vr /update /praise /savepos /gotopos /invisible\n",string);
        format(string, (512), "%s"#zuta"[LEVEL 5 ADMINISTRATOR]\n"#bijela"/ban /heal /healall /time /merge /ip /cs\n",string);
        format(string, (600), "%s"#zuta"[LEVEL 6 ADMINISTRATOR]\n"#bijela"/gmx /fakeban /set /setscore /rocketman\n",string);
        format(string, (750), "%s"#zuta"[LEVEL 7 ADMINISTRATOR]\n"#bijela"/teles /snow /snowoff /gotocord /createhouse\n",string);
        format(string, (800), "%s"#zuta"[LEVEL 8 ADMINISTRATOR]\n"#bijela"/givemoney /setmoney /settings /setadmin /setvip",string);
	}
	CreateDialog(playerid, DIALOG_ADMIN_INFO, DIALOG_STYLE_MSGBOX, ""#error"Admin panel", string, "Ok", "", ""#error"Admin panel", string, "Ok", "");
	return (true);
}

YCMD:setvip(playerid, params[], help)
{
	new id, level, dan, mjesec, godina, string1[128] = "\0", string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 8) return adminError(playerid, 8);
    else if(sscanf(params, "udddd", id, level, dan, mjesec, godina)) return SCM(playerid, ""#bijela"KORISTI: /setvip [playerid] [level] [dan] [mjesec] [godina]", ""#bijela"USAGE: /setvip [playerid] [day] [month] [year]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(dan < 0 || dan > 31 || mjesec < 0 || mjesec > 12 || godina < 2012) return SCM(playerid, ""#siva"* Error!", ""#siva"* Error!");
    else if(level < 0 || level > 3) return SCM(playerid, ""#siva"* Minimalan level je 0 - maksimalan 3!", ""#siva"* Minimum level is 0 - maximum 3!");
    else
    {
		if(level != 0)
		{
		   PlayerInfo[id][Vip] = (level);
		   PlayerInfo[id][Vip_Vrijeme] = gettime(); /* POPRAVI TJ. DOHVATI UNESENI DATUM U TIMESTAMP */
        }
        else if(level == 0)
        {
			PlayerInfo[id][Vip] = (0);
			PlayerInfo[id][Vip_Vrijeme] = 0;
        }
        
        format(string1, (sizeof string1), ""#ljubicasta"Administrator %s je postavio igracu %s VIP level %d!", GetName(playerid), GetName(id), level);
        format(string2, (sizeof string2), ""#ljubicasta"Administrator %s has set %s VIP level %d!", GetName(playerid), GetName(id), level);
        ScmToAll(string1, string2);
        
        new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string1, (sizeof string1), "%s je postavio %s VIP level na %d (%d.%d.%d)",GetName(playerid),GetName(id),level,dan_, mjesec_, godina_);

		if(level == 1)
		{
			GivePlayerMoneyEx(id, 1000000);
		}
		else if(level == 2)
		{
			GivePlayerMoneyEx(id, 2000000);
		}
		else if(level == 3)
		{
			GivePlayerMoneyEx(id, 3000000);
		}
		UpdatePlayer(id);
		
		foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string1, string1);
			}
		}
		AdminLog(string1);
    }
	return (true);
}

YCMD:rocketman(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 6) return adminError(playerid, 6);
    else
    {
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
    }
    return (true);
}

YCMD:settings(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 8) return adminError(playerid, 8);
	else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH)) return SCM(playerid, ""#siva"Only this command is not for your language :(", ""#siva"Only this command is not for your language :(");
	else
	{
        ShowPlayerDialog(playerid, DIALOG_ADMIN_SETTINGS, DIALOG_STYLE_LIST, "{00AEC8}PREGLED / EVIDENCIJA", "{00AE5B}CITAJ ZADNJE PRIJAVE\n{FFAE5B}GLEDAJ ZADNJE RADNJE ADMINISTRATORA\n{00AE5B}PREGLEDAJ ZADNJE POSLANE PRIVATNE PORUKE\n{FFAE5B}GLEDAJ ZADNJE TRANSAKCIJE NOVCA IGRACA\n{00AE5B}VJEROJATNI CHEATERI", "OK", "ZATVORI");
    }
	return (true);
}

YCMD:setmoney(playerid, params[], help)
{
	new
	   id, iznos = (0), string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 8) return adminError(playerid, 8);
    else if(sscanf(params, "ud", id, iznos)) return SCM(playerid, ""#bijela"KORISTI: /setmoney [playerid] [iznos]", ""#bijela"USAGE: /setmoney [playerid] [ammount]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
	    ResetPlayerMoneyEx(id);
	    GivePlayerMoneyEx(id, iznos);
	    if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Postavio si %s novac na $%d.",GetName(id),iznos);
        }
        else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* You set %s money to $%d.",GetName(id),iznos);
        }
        SCM(playerid, string, string);

	    if(IsPlayerLanguage(id, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s ti je postavio novac na $%d.",GetName(playerid),iznos);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s set your money on $%d.",GetName(playerid),iznos);
        }
	    SCM(id, string, string);
	    UpdatePlayer(id);
	    
	    new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je postavio %s novac na $%d (%d.%d.%d)",GetName(playerid),GetName(id),iznos,dan_, mjesec_, godina_);
		foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

YCMD:givemoney(playerid, params[], help)
{
	new
	   id = (0), iznos = (0), string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 8) return adminError(playerid, 8);
    else if(sscanf(params, "ud", id, iznos)) return SCM(playerid, ""#bijela"KORISTI: /givemoney [playerid] [iznos]", ""#bijela"USAGE: /givemoney [playerid] [ammount]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(iznos <= 0) return SCM(playerid, ""#siva"Iznos mora biti veci od nule.", ""#siva"Ammount must be higer then zero.");
    else
    {
	    GivePlayerMoneyEx(id, iznos);
	    if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Dao si %s $%d.",GetName(id),iznos);
        }
        else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* You gave %s $%d.",GetName(id),iznos);
        }
        SCM(playerid, string, string);

	    if(IsPlayerLanguage(id, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s ti je dao $%d.",GetName(playerid),iznos);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s gave you $%d.",GetName(playerid),iznos);
        }
	    SCM(id, string, string);
	    UpdatePlayer(id);
	    
	    new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je dao %s $%d (%d.%d.%d)",GetName(playerid), GetName(id),iznos,dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

YCMD:gotocord(playerid, params[], help)
{
	new
	   Float:Pos[3], int = (0);
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 7) return adminError(playerid, 7);
    else if(sscanf(params,"fffd",Pos[0], Pos[1], Pos[2], int)) return SCM(playerid, ""#bijela"KORISTI: /gotocord [X] [Y] [Z] [Interior]", ""#bijela"USAGE: /gotocord [X] [Y] [Z] [Interior]");
    else
    {
		SFP_SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SetPlayerInterior(playerid, int);
		SCM(playerid, ""#bijela"* Uspjesno si se teleportirao.", ""#bijela"* You are successfully teleported.");
    }
	return (true);
}

YCMD:createhouse(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 7) return adminError(playerid, 7);
    else
    {
        CreateDialog(playerid,
		DIALOG_HOUSE,
		DIALOG_STYLE_LIST,
		""#error"Odaberi",
		""#zuta"(1): "#bijela"Mala kuca\n"#zuta"(2): "#bijela"Srednja Kuca\n"#zuta"(3): "#bijela"Velika kuca",
		"Odaberi", "Odustani",
		""#error"Choose",
		""#zuta"(1): "#bijela"Little house\n"#zuta"(2): "#bijela"Middle house\n"#zuta"(3): "#bijela"Big house",
		"Accept", "Cancel");
    }
	return (true);
}

YCMD:snow(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 7) return adminError(playerid, 7);
    else
    {
	   foreach(Player, i)
	   {
		  CreateSnow(i);
	   }
    }
	return (true);
}

YCMD:snowoff(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 7) return adminError(playerid, 7);
    else
    {
		foreach(Player, i)
		{
           DeleteSnow(i);
		}
    }
	return (true);
}

YCMD:teles(playerid, params[], help)
{
     if(PlayerLogin{playerid} == false) return logout(playerid);
     else if(PlayerInfo[playerid][Admin] < 7) return adminError(playerid, 7);
	 {
        CreateDialog(playerid, DIALOG_ADMIN_TELE, DIALOG_STYLE_LIST, ""#error"Teleport", "Los Santos\nSan Fiero\nLas Venturas\nArea 51", "Odaberi", "Odustani", ""#error"Teleport", "Los Santos\nSan Fiero\nLas Venturas\nArea 51", "Accept", "Cancel");
     }
	 return (true);
}

YCMD:setscore(playerid, params[], help)
{
	new id, score, string[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 6) return adminError(playerid, 6);
    else if(sscanf(params, "ud",id, score)) return SCM(playerid, ""#bijela"KORISTI: /setscore [playerid] [bodovi]", ""#bijela"USAGE: /setscore [playerid] [score]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		if(Team{id} == 1) { PlayerInfo[id][Bodovi] = (score); }
	    else if(Team{id} == 2) { PlayerInfo[id][Bodovi] = (score); }
	    else if(Team{id} == 3) { PlayerInfo[id][Bodovi] = (score); }
	    else if(Team{id} == 4) { PlayerInfo[id][Bodovi_][0] = (score); }
	    else if(Team{id} == 6) { PlayerInfo[id][Bodovi_][1] = (score); }
	    else if(Team{id} == 7) { PlayerInfo[id][Bodovi_][2] = (score); }
	    
		UpdatePlayer(id);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[BODOVI]: "#ljubicasta"Administrator %s ti je postavio bodove na %d.",GetName(playerid),score);
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#zuta"[SCORES]: "#ljubicasta"Administrator %s set your score on %d.",GetName(playerid),score);
		}
		SCM(id, string, string);
		
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#bijela"* Postavio si %s bodove na %d.",GetName(id),score);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#bijela"* You set %s scores on %d.",GetName(id),score);
		}
		SCM(playerid, string, string);
		
		new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je postavio %s bodove na %d (%d.%d.%d)",GetName(playerid),GetName(id), score, dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

YCMD:set(playerid, params[], help)
{
	new id, menuid[20], set, string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 6) return adminError(playerid, 6);
    else if(sscanf(params, "us[20]d",id,menuid,set)) return SCM(playerid, ""#bijela"KORISTI: /set [playerid] [meni] [iznos]", ""#bijela"USAGE: /set [playerid] [menu id] [value]"), SCM(playerid, ""#bijela"[MENI]: radio ubrzanje veh1 veh2 veh3", ""#bijela"[MENU ID]: radio boost veh1 veh2 veh3");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(strcmp(menuid, "radio", false) == 0)
    {
		if(set < 0 || set > 1) return SCM(playerid, ""#siva"Iznos mora biti 0 ili 1!", ""#siva"Value must be 0 or 1!");
		else if(set == 0)
		{
            if(!IsPlayerHaveRadio(id)) return SCM(playerid, ""#siva"Igrac nema radio.", ""#siva"That player don't have a radio.");
            GivePlayerRadio(id, false);
			if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
			{
				format(string, (sizeof string), ""#bijela"* Uzeo si %s radio.",GetName(id));
			}
			else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
			{
                format(string, (sizeof string), ""#bijela"* You take %s radio.",GetName(id));
			}
			SCM(playerid, string, string);
			
			if(IsPlayerLanguage(id, JEZIK_BALKAN))
			{
				format(string, (sizeof string), ""#bijela"* Administrator %s ti je uzeo radio.",GetName(playerid));
			}
			else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
			{
                format(string, (sizeof string), ""#bijela"* Administrator %s take you a radio.",GetName(playerid));
			}
			SCM(id, string, string);
			
			new dan_, mjesec_, godina_;
	        getdate(godina_, mjesec_, dan_);
	        format(string, (sizeof string), "%s je uezo %s radio (%d.%d.%d)",GetName(playerid),GetName(id), dan_, mjesec_, godina_);
            foreach(Player, i)
		    {
			   if(adminLog{i} == true)
			   {
			      SCM(i, string, string);
			   }
		    }
			AdminLog(string);
		}
		else if(set == 1)
		{
            if(IsPlayerHaveRadio(id)) return SCM(playerid, ""#siva"Igrac vec ima radio.", ""#siva"That player already have a radio.");
            GivePlayerRadio(id, true);
			if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
			{
				format(string, (sizeof string), ""#bijela"* Dao si %s radio.",GetName(id));
			}
			else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
			{
                format(string, (sizeof string), ""#bijela"* You gave %s radio.",GetName(id));
			}
			SCM(playerid, string, string);

			if(IsPlayerLanguage(id, JEZIK_BALKAN))
			{
				format(string, (sizeof string), ""#bijela"* Administrator %s ti je dao radio.",GetName(playerid));
			}
			else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
			{
                format(string, (sizeof string), ""#bijela"* Administrator %s gave you a radio.",GetName(playerid));
			}
			SCM(id, string, string);
			
			new dan_, mjesec_, godina_;
	        getdate(godina_, mjesec_, dan_);
	        format(string, (sizeof string), "%s je dao %s radio (%d.%d.%d)",GetName(playerid),GetName(id), dan_, mjesec_, godina_);
            foreach(Player, i)
		    {
			   if(adminLog{i} == true)
			   {
			      SCM(i, string, string);
			   }
		    }
		    AdminLog(string);
		}
		else if(strcmp(menuid, "ubrzanje", false) == 0 || strcmp(menuid, "boost", false) == 0)
        {
		  if(set < 0 || set > 1) return SCM(playerid, ""#siva"Iznos mora biti 0 ili 1!", ""#siva"Value must be 0 or 1!");
		  else if(set == 0)
		  {
              if(!IsPlayerHaveBoost(id)) return SCM(playerid, ""#siva"Igrac nema ubrzanje.", ""#siva"That player don't have a boost.");
              GivePlayerBoost(id, false);
			  if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
			  {
				  format(string, (sizeof string), ""#bijela"* Uzeo si %s ubrzanje.",GetName(id));
			  }
			  else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
			  {
                  format(string, (sizeof string), ""#bijela"* You take %s boost.",GetName(id));
			  }
			  SCM(playerid, string, string);

			  if(IsPlayerLanguage(id, JEZIK_BALKAN))
			  {
				   format(string, (sizeof string), ""#bijela"* Administrator %s ti je uzeo ubrzanje.",GetName(playerid));
			  }
			  else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		 	  {
                  format(string, (sizeof string), ""#bijela"* Administrator %s take you a boost.",GetName(playerid));
			  }
			  SCM(id, string, string);
			  
			  new dan_, mjesec_, godina_;
	          getdate(godina_, mjesec_, dan_);
	          format(string, (sizeof string), "%s je uezo %s ubrzanje (%d.%d.%d)",GetName(playerid),GetName(id), dan_, mjesec_, godina_);
              foreach(Player, i)
		      {
			     if(adminLog{i} == true)
			     {
			       SCM(i, string, string);
			     }
		      }
			  AdminLog(string);
		  }
		  else if(set == 1)
		  {
              if(IsPlayerHaveBoost(id)) return SCM(playerid, ""#siva"Igrac vec ima radio.", ""#siva"That player already have a radio.");
              GivePlayerBoost(id, true);
			  if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
			  {
				  format(string, (sizeof string), ""#bijela"* Dao si %s ubrzanje.",GetName(id));
			  }
			  else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
			  {
                  format(string, (sizeof string), ""#bijela"* You gave %s boost.",GetName(id));
			  }
			  SCM(playerid, string, string);

			  if(IsPlayerLanguage(id, JEZIK_BALKAN))
			  {
				  format(string, (sizeof string), ""#bijela"* Administrator %s ti je dao ubrzanje.",GetName(playerid));
			  }
			  else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
			  {
                  format(string, (sizeof string), ""#bijela"* Administrator %s gave you a boost.",GetName(playerid));
			  }
			  SCM(id, string, string);
			  
			  new dan_, mjesec_, godina_;
	          getdate(godina_, mjesec_, dan_);
	          format(string, (sizeof string), "%s je dao %s ubrzanje (%d.%d.%d)",GetName(playerid),GetName(id), dan_, mjesec_, godina_);
              foreach(Player, i)
		      {
			     if(adminLog{i} == true)
			     {
			        SCM(i, string, string);
			     }
		      }
			  AdminLog(string);
          }
		}
    }
    else if(strcmp(menuid, "veh1", false) == 0)
    {
		PlayerInfo[id][Kljuc_Vozilo][0] = (set);
		UpdatePlayer(playerid);
		
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Postavio si %s vozilo %d u slot 1.",GetName(id),set);
        }
        else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* You set %s vehicle %d in slot 1.",GetName(id),set);
        }
        SCM(playerid, string, string);

	    if(IsPlayerLanguage(id, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s ti je postavio vozilo %d u slot 1.",GetName(playerid),set);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s set you a vehicle %d in slot 1.",GetName(playerid),set);
        }
	    SCM(id, string, string);
    }
    else if(strcmp(menuid, "veh2", false) == 0)
    {
		PlayerInfo[id][Kljuc_Vozilo][1] = (set);
		UpdatePlayer(playerid);

		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Postavio si %s vozilo %d u slot 2.",GetName(id),set);
        }
        else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* You set %s vehicle %d in slot 2.",GetName(id),set);
        }
        SCM(playerid, string, string);

	    if(IsPlayerLanguage(id, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s ti je postavio vozilo %d u slot 2.",GetName(playerid),set);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s set you a vehicle %d in slot 2.",GetName(playerid),set);
        }
	    SCM(id, string, string);
    }
    else if(strcmp(menuid, "veh3", false) == 0)
    {
		PlayerInfo[id][Kljuc_Vozilo][2] = (set);
		UpdatePlayer(playerid);

		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Postavio si %s vozilo %d u slot 3.",GetName(id),set);
        }
        else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* You set %s vehicle %d in slot 3.",GetName(id),set);
        }
        SCM(playerid, string, string);

	    if(IsPlayerLanguage(id, JEZIK_BALKAN))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s ti je postavio vozilo %d u slot 3.",GetName(playerid),set);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#bijela"* Administrator %s set you a vehicle %d in slot 3.",GetName(playerid),set);
        }
	    SCM(id, string, string);
    }
    else { SCM(playerid, ""#siva"Pogresan meni ID.", ""#siva"Wrong menu ID."); return (true); }
	return (true);
}

YCMD:fakeban(playerid, params[], help)
{
	new string[128] = "\0", id, string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 6) return adminError(playerid, 6);
    else if(sscanf(params, "us[64]", id, params)) return SCM(playerid, ""#bijela"KORISTI: /fakeban [playerid] [razlog]", ""#bijela"USAGE: /fakeban [playerid] [reason]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		format(string2, (sizeof string2), ""#zuta"[BAN]: "#ljubicasta"Administrator %s je banao %s - RAZLOG: %s",GetName(playerid),GetName(id),params);
		format(string, (sizeof string), ""#zuta"[BAN]: "#ljubicasta"Administrator %s has banned %s - REASON: %s",GetName(playerid),GetName(id),params);
		ScmToAll(string2,string);
    }
	return (true);
}

YCMD:gmx(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 6) return adminError(playerid, 6);
    else
    {
		foreach(Player, i)
		{
		   UpdatePlayer(i);
		}
		SendRconCommand("gmx");
    }
	return (true);
}

YCMD:cs(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else
    {
		SetWeather(0);
		SCM(playerid, ""#bijela"* Postavio si cisto vrijeme.", ""#bijela"* You set a clear weather.");
    }
	return (true);
}

YCMD:ip(playerid, params[], help)
{
	new ip[16], string[80], id;
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else if(sscanf(params, "u", id)) return SCM(playerid, ""#bijela"KORISTI: /ip [playerid]", ""#bijela"USAGE: /ip [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		GetPlayerIp(id, ip, (sizeof ip));
		format(string, (sizeof string), ""#zuta"%s | IP: %s",GetName(id),ip);
		SCM(playerid, string, string);
    }
	return (true);
}

YCMD:merge(playerid, params[], help)
{
	new id, id2, string[128] = "\0", Float:Pos[3];
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else if(sscanf(params, "uu",id,id2)) return SCM(playerid, ""#bijela"KORISTI: /merge [playerid] [playerid 2]", ""#bijela"USAGE: /merge [playerid] [playerid 2]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(id2 == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid 2.", ""#siva"Invalid playerid 2.");
    else
    {
		GetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
		SFP_SetPlayerPos(id2, Pos[0], Pos[1], Pos[2]);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[TELEPORT]: "#ljubicasta"Administrator %s je teleportirao igraca %s do tebe.",GetName(playerid),GetName(id2));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
             format(string, (sizeof string), ""#zuta"[TELEPORT]: "#ljubicasta"Administrator %s has teleported %s to you.",GetName(playerid),GetName(id2));
		}
		SCM(id, string, string);
		
		if(IsPlayerLanguage(id2, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[TELEPORT]: "#ljubicasta"Administrator %s te teleportirao do %s.",GetName(playerid),GetName(id));
		}
		else if(IsPlayerLanguage(id2, JEZIK_ENGLISH))
		{
             format(string, (sizeof string), ""#zuta"[TELEPORT]: "#ljubicasta"Administrator %s has teleport you to %s.",GetName(playerid),GetName(id));
		}
		SCM(id2, string, string);
		
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[TELEPORT]: "#bijela"Teleportirao si %s do %s.",GetName(id2),GetName(id));
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
             format(string, (sizeof string), ""#zuta"[TELEPORT]: "#bijela"You teleport %s to %s.",GetName(id2),GetName(id));
		}
		SCM(playerid, string, string);
    }
	return (true);
}

YCMD:time(playerid, params[], help)
{
	new satI = (0), minS = (0);
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else if(sscanf(params, "dd",satI, minS)) return SCM(playerid, ""#bijela"KORISTI: /time [sat] [minuta]", ""#bijela"USAGE: /time [hour] [minute]");
    if(satI >= 24 || satI < 0) return SCM(playerid, ""#siva"Maximalno 23 sata i minimalno 0!", ""#siva"Maximum is 23 hours and minimum is 0!");
    else if(minS >= 60 || minS < 0) return SCM(playerid, ""#siva"Maximalno 59 minuta i minimalno 0!", ""#siva"Maximum is 59 minutes and minimum is 0!");
    else
    {
       sat_ = (satI);
	   min_ = (minS);
	}
	return (true);
}

YCMD:healall(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else
    {
		foreach(Player, i)
		{
			SFP_SetPlayerHealth(i, 100);
		}
		ScmToAll(""#zuta"[HEAL]: "#bijela"Administrator je izlijecio sve igrace na serveru.",""#zuta"[HEAL]: "#bijela"Administrator has cured all players.");
    }
	return (true);
}

YCMD:heal(playerid, params[], help)
{
	new id, Float:Health, string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else if(sscanf(params, "uf",id,Health)) return SCM(playerid, ""#bijela"KORISTI: /heal [playerid] [0-100]", ""#bijela"USAGE: /heal [playerid] [0-100]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(Health < 0 || Health > 100) return SCM(playerid, ""#siva"Ne smije biti manje od 0 ni vece od 100!", ""#siva"Health must be higher then 0 and lower then 101!");
    else
    {
		SFP_SetPlayerHealth(id, Health);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[HEAL]: "#ljubicasta"Administrator %s ti je postavio healte na %f.",GetName(playerid),Health);
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#zuta"[HEAL]: "#ljubicasta"Administrator %s has set your health to %f.",GetName(playerid),Health);
		}
		SCM(id, string, string);
		
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[HEAL]: "#ljubicasta"Postavio si %s healte na %f.",GetName(id),Health);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#zuta"[HEAL]: "#ljubicasta"You set %s health to %f.",GetName(id),Health);
		}
		SCM(playerid, string, string);

    }
	return (true);
}

YCMD:ban(playerid, params[], help)
{
	new string[128] = "\0", id, string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 5) return adminError(playerid, 5);
    else if(sscanf(params, "us[64]", id, params)) return SCM(playerid, ""#bijela"KORISTI: /ban [playerid] [razlog]", ""#bijela"USAGE: /ban [playerid] [reason]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
	else if(PlayerInfo[playerid][Admin] < PlayerInfo[id][Admin]) return SCM(playerid, ""#siva"* Taj administrator je vec level od tebe!", ""#siva"* That admin is higher level then you.");
	else
    {
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#ljubicasta"Administrator %s te banao sa servera - RAZLOG: %s",GetName(playerid),params);
		   SCM(id, string, string);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#ljubicasta"Administrator %s has banned you from server - REASON: %s",GetName(playerid),params);
		   SCM(id, string, string);
        }
		format(string2, (sizeof string2), ""#zuta"[BAN]: "#ljubicasta"Administrator %s je banao %s - RAZLOG: %s",GetName(playerid),GetName(id),params);
		format(string, (sizeof string), ""#zuta"[BAN]: "#ljubicasta"Administrator %s has banned %s - REASON: %s",GetName(playerid),GetName(id),params);
		ScmToAll(string2,string);
        new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je banao %s RAZLOG: %s (%d.%d.%d)",GetName(playerid),GetName(id), params, dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
		Ban(id);
    }
	return (true);
}

YCMD:invisible(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else if(nevidljiv{playerid} == true)
	{
		SetPlayerColorByJob(playerid);
		nevidljiv{playerid} = (false);
		SCM(playerid, ""#bijela"* Sada si vidljiv.", ""#bijela"* You are not invisible anymore.");
	}
	else if(nevidljiv{playerid} == false)
	{
        SetPlayerColor(playerid, 0xFF00A500);
		nevidljiv{playerid} = (true);
		SCM(playerid, ""#bijela"* Sada si nevidljiv.", ""#bijela"* You are invisible now.");
	}
	return (true);
}

YCMD:savepos(playerid, params[], help)
{
	new Float:Pos[3];
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else if(GetPlayerInterior(playerid) != 0) return SCM(playerid, ""#siva"Tvoj interior mora biti 0.", ""#siva"Your interior must be 0.");
    else
    {
		GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		PlayerInfo[playerid][Pozicija][0] = (Pos[0]);
		PlayerInfo[playerid][Pozicija][1] = (Pos[1]);
		PlayerInfo[playerid][Pozicija][2] = (Pos[2]);
		SCM(playerid, ""#bijela"* Pozicija uspjesno spremljena koristi /gotopos da se teleportiras do pozicije.", ""#bijela"* Position is successfully saved, use /gotopos to teleport back on this position.");
		UpdatePlayer(playerid);
    }
	return (true);
}

YCMD:gotopos(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else if(PlayerInfo[playerid][Pozicija][0] == 0.000 && PlayerInfo[playerid][Pozicija][1] == 0.000 && PlayerInfo[playerid][Pozicija][2] == 0.000) return SCM(playerid, ""#siva"Prvo koristi /savepos", ""#siva"First use /savepost then use /gotopos");
    {
		SFP_SetPlayerPos(playerid, PlayerInfo[playerid][Pozicija][0], PlayerInfo[playerid][Pozicija][1], PlayerInfo[playerid][Pozicija][2]);
		SCM(playerid, ""#bijela"* Uspjesno si se teleportirao na svoju poziciju.", ""#bijela"* You have been successfully teleported to your position.");
    }
	return (true);
}

YCMD:praise(playerid, params[], help)
{
	new string[128] = "\0", string2[128] = "\0", id;
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else if(sscanf(params, "u",id)) return SCM(playerid, ""#bijela"KORISTI: /praise [playerid]", ""#bijela"USAGE: /praise [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		PlayerInfo[id][Pohvale] ++;
		UpdatePlayer(id);
		format(string, (sizeof string), ""#zuta"[POHVALA]: "#ljubicasta"Administrator %s je dao pohvalu igracu %s.",GetName(playerid),GetName(id));
		format(string2, (sizeof string2), ""#zuta"[PRAISE]: "#ljubicasta"Administrator %s gave praise to %s.",GetName(playerid),GetName(id));
		ScmToAll(string, string2);
		
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[INFO]: "#bijela"Administrator %s ti je dao pohvalu | Ukupno pohvala: %d.",GetName(playerid),PlayerInfo[id][Pohvale]);
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
             format(string, (sizeof string), ""#zuta"[INFO]: "#bijela"Administrator %s gave you a praise | Total praises: %d.",GetName(playerid),PlayerInfo[id][Pohvale]);
		}
		SCM(id, string, string);
		
		new dan_, mjesec_, godina_;
        getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je dao pohvalu %s (%d.%d.%d)",GetName(playerid),GetName(id), dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

YCMD:update(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else
    {
		foreach(Player, i)
		{
			UpdatePlayer(i);
		}
		ScmToAll(""#zuta"[UPDATE]: "#bijela"Sve postavke tvog racuna su uspjesno spremljene.",""#zuta"[UPDATE]: "#bijela"Your account is successfully updated.");
    }
	return (true);
}

YCMD:vr(playerid, params[], help)
{
	new string[128] = "\0", carid;
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else if(sscanf(params, "i", carid)) return SCM(playerid, ""#bijela"KORISTI: /vr [carid]", ""#bijela"USAGE: /vr [carid]");
    else if(IsVehicleInUse(carid)) return SCM(playerid, ""#siva"To vozilo netko koristi, ne mozes ga respawnati.", ""#siva"That vehicle is in use, you can't respawn it.");
    else
    {
		SFP_SetVehicleToRespawn(carid);
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#bijela"* Uspjesno si respawnao vozilo ID: %d.",carid);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
			format(string, (sizeof string), ""#bijela"Vehicle with ID: %d is respawned.",carid);
		}
		SCM(playerid, string, string);
    }
	return (true);
}

YCMD:vrall(playerid, params[], help)
{
	new string[128] = "\0", string2[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 4) return adminError(playerid, 4);
    else
    {
		for(new v=-1;v<MAX_VEHICLES;v++)
		{
		   if(!IsVehicleInUse(v))
		   {
			  SFP_SetVehicleToRespawn(v);
		   }
		}
		format(string, (sizeof string), ""#zuta"[RESPAWN]: "#ljubicasta"Administrator %s je respawnao sva ne koristena vozila.",GetName(playerid));
		format(string2, (sizeof string2), ""#zuta"[RESPAWN]: "#ljubicasta"Administrator %s respawned all unused vehicles on server.",GetName(playerid));
		ScmToAll(string, string2);
    }
	return (true);
}

YCMD:cc(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else
    {
		for(new i; i<50;i++)
		{
		   ScmToAll("","");
		}
    }
	return (true);
}

YCMD:blockpm(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(block_pm{playerid} == true)  
    {
		block_pm{playerid} = (false);
		SCM(playerid, ""#bijela"* Ukljucio si privatne poruke.", ""#bijela"* You accept private messages now.");
    }
    else if(block_pm{playerid} == false)
    {
        block_pm{playerid} = (true);
        SCM(playerid, ""#bijela"* Iskljucio si privatne poruke.", ""#bijela"* You don't accept private messages anymore.");
    }
	return (true);
}

YCMD:setint(playerid, params[], help)
{
	new int_id,id;
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(sscanf(params, "ui",id,int_id)) return SCM(playerid, ""#bijela"KORISTI: /setint [playerid] [interior id]",""#bijela"USAGE: /setint [playerid] [interior id]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		SetPlayerInterior(id, int_id);
		SCM(playerid, ""#bijela"* Igracu si uspjesno promjenio interior.", ""#bijela"* You change player interior.");
    }
	return (true);
}

YCMD:setvw(playerid, params[], help)
{
	new vw_id,id;
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(sscanf(params, "ui",id,vw_id)) return SCM(playerid, ""#bijela"KORISTI: /setvw [playerid] [virtual world id]",""#bijela"USAGE: /setvw [playerid] [virtual world id]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		SetPlayerVirtualWorld(id, vw_id);
		SCM(playerid, ""#bijela"* Igracu si uspjesno promjenio virtual world.", ""#bijela"* You change player virtual world.");
    }
	return (true);
}

YCMD:spec(playerid, params[],help)
{
    new id;
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params,"u", id))return SCM(playerid, ""#bijela"KORISTI: /spec [playerid]", ""#bijela"USAGE: /spec [playerid]");
    else if(id == playerid) return SCM(playerid,""#siva"Ne mozes promatrati svog lika.",""#siva"You cannot spec yourself.");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(IsSpecing{playerid} == true)return SCM(playerid,""#siva"Vec koristis /spec koristi /specoff za prekid.",""#siva"You are already specing someone.");
    GetPlayerPos(playerid,SPEC_POS[playerid][0],SPEC_POS[playerid][1],SPEC_POS[playerid][2]);
    SPEC_INT{playerid} = GetPlayerInterior(playerid);
    SPEC_VW[playerid] = GetPlayerVirtualWorld(playerid);
    TogglePlayerSpectating(playerid, true);
    if(IsPlayerInAnyVehicle(id))
    {
        if(GetPlayerInterior(id) > 0)
        {
            SetPlayerInterior(playerid,GetPlayerInterior(id));
        }
        if(GetPlayerVirtualWorld(id) > 0)
        {
            SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(id));
        }
        PlayerSpectateVehicle(playerid,GetPlayerVehicleID(id));
    }
    else if(!IsPlayerInAnyVehicle(id))
    {
        if(GetPlayerInterior(id) > 0)
        {
            SetPlayerInterior(playerid,GetPlayerInterior(id));
        }
        if(GetPlayerVirtualWorld(id) > 0)
        {
            SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(id));
        }
        PlayerSpectatePlayer(playerid,id);
    }
    IsSpecing{playerid} = (true);
    IsBeingSpeced{id} = (true);
    spectatorid[playerid] = (id);
    return (true);
}

YCMD:specoff(playerid, params[],help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(IsSpecing{playerid} == false) return SCM(playerid,""#siva"Nikog ne promatras.",""#siva"You are not spectating anyone.");
    else
    {
        TogglePlayerSpectating(playerid, 0);
	}
    return (true);
}

YCMD:akill(playerid, params[], help)
{
	new id, string[128] = "\0", string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(sscanf(params,"u",id)) return SCM(playerid, ""#bijela"KORISTI: /akill [playerid]", ""#bijela"USAGE: /akill [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		SFP_SetPlayerHealth(id, 0.0000);
		SFP_SetPlayerArmour(id, 0.0000);
		format(string, (sizeof string), ""#zuta"[SMRT]: "#ljubicasta"Administrator %s je ubio %s.",GetName(playerid),GetName(id));
		format(string2, (sizeof string2), ""#zuta"[ADMIN KILL]: "#ljubicasta"Administrator %s killed %s.",GetName(playerid),GetName(id));
		ScmToAll(string, string2);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"Administrator %s te ubio.",GetName(playerid));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
			format(string, (sizeof string), ""#zuta"Administrator %s killed you.",GetName(playerid));
		}
		SCM(id, string, string);
		SCM(playerid, ""#bijela"* Igrac je ubijen.", ""#bijela"* Player is now death.");
		
		new dan_, mjesec_, godina_;
        getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je prisilno ubio %s (%d.%d.%d)",GetName(playerid),GetName(id), dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

YCMD:freeze(playerid, params[], help)
{
	new id, string[128] = "\0", string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(sscanf(params, "u",id)) return SCM(playerid, ""#bijela"KORISTI: /freeze [playerid]",""#bijela"USAGE: /freeze [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(freeze{id} == true) return SCM(playerid, ""#siva"Igrac je vec zaleden.", ""#siva"That player is already freezed.");
    else
    {
		Freeze(id, 1);
		freeze{id} = (true);
		format(string, (sizeof string), ""#zuta"[ZALEDJENJE]: "#ljubicasta"Administrator %s je zaledio %s.",GetName(playerid),GetName(id));
		format(string2, (sizeof string2), ""#zuta"[FREEZE]: "#ljubicasta"Administrator %s has freezed %s.",GetName(playerid),GetName(id));
		ScmToAll(string, string2);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"Administrator %s te zaledio.",GetName(playerid));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
		   format(string, (sizeof string), ""#zuta"Administrator %s freeze you.",GetName(playerid));
		}
		SCM(id, string, string);
		SCM(playerid, ""#zuta"Zaledio si igraca.", ""#zuta"That player is now freezed.");
    }
	return (true);
}

YCMD:unfreeze(playerid, params[], help)
{
	new id, string[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(sscanf(params, "u",id)) return SCM(playerid, ""#bijela"KORISTI: /unfreeze [playerid]",""#bijela"USAGE: /unfreeze [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(freeze{id} == false) return SCM(playerid, ""#siva"Igrac nije zaleden.", ""#siva"That player isn't freezed.");
    else
    {
		Freeze(id, 0);
		freeze{id} = (false);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"Administrator %s te odledio.",GetName(playerid));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
		   format(string, (sizeof string), ""#zuta"Administrator %s unfreeze you.",GetName(playerid));
		}
		SCM(id, string, string);
		SCM(playerid, ""#zuta"Odledio si igraca.", ""#zuta"That player is now unfreezed.");
    }
	return (true);
}

YCMD:mute(playerid, params[], help)
{
	new id, string[128] = "\0", string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else if(sscanf(params,"u",id)) return SCM(playerid, ""#bijela"KORISTI: /mute [playerid]", ""#bijela"USAGE: /mute [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(mute{id} == true) return SCM(playerid, ""#siva"Igrac je vec usutkan.", ""#siva"That player is already muted.");
    else
    {
        mute{id} = (true);
        format(string, (sizeof string), ""#zuta"[USUTKANJE]: "#ljubicasta"Administrator %s je usutkao %s.",GetName(playerid),GetName(id));
        format(string2, (sizeof string2), ""#zuta"[MUTE]: "#ljubicasta"Administrator %s has mute %s.",GetName(playerid),GetName(id));
        ScmToAll(string, string2);
    }
	return (true);
}

YCMD:unmute(playerid, params[], help)
{
	new id;
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else if(sscanf(params,"u",id)) return SCM(playerid, ""#bijela"KORISTI: /unmute [playerid]", ""#bijela"USAGE: /unmute [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(mute{id} == false) return SCM(playerid, ""#siva"Igrac nije usutkan.", ""#siva"That player is not muted.");
    else
    {
        mute{id} = (false);
        SCM(playerid, ""#bijela"* Taj igrac vise nije usutkan.", ""#bijela"* That player is not muted anymore.");
        SCM(id, ""#bijela"* Sada mozes koristiti chat.", ""#bijela"* You are not muted anymore.");
    }
	return (true);
}

YCMD:muted(playerid, params[], help)
{
	new string[150], cout = (0);
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else
    {
		cout = (0);
		foreach(Player, i)
		{
		   if(mute{i} == true)
		   {
			  cout ++;
			  format(string, (150), "%s"#zuta"%s"#bijela"(ID:%d)\n",string,GetName(i),i);
		   }
		}
		if(cout == 0)
		{
		    if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
			{
			    format(string, (150), ""#zuta"[SERVER]: "#bijela"Nema usutkanih igraca!");
			}
			else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
			{
			    format(string, (150), ""#zuta"[SERVER]: "#bijela"Nobody silenced!");
			}
		}
		CreateDialog(playerid, DIALOG_ADMIN_MUTED, DIALOG_STYLE_MSGBOX, ""#error"Usutkani igraci", string, "OK", "", ""#error"Muted players", string, "OK", "");
    }
	return (true);
}

YCMD:fill(playerid, params[], help)
{
	new id, string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else if(sscanf(params, "u",id)) return SCM(playerid, ""#bijela"KORISTI: /fill [playerid]", ""#bijela"USAGE: /fill [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(!IsPlayerInAnyVehicle(id)) return SCM(playerid, ""#siva"Igrac nije u vozilu.", ""#siva"That player is not in vehicle.");
    else
    {
		Gorivo[GetPlayerVehicleID(id)] = (MAX_FUEL);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#bijela"* Administrator %s je napunio gorivom tvoje vozilo.",GetName(playerid));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#bijela"* Administrator %s has filled the fuel your vehicle.",GetName(playerid));
		}
		SCM(id, string, string);
		SCM(playerid, ""#bijela"* Napunio si vozilo gorivom", ""#bijela"* You fill vehicle.");
    }
	return (true);
}

YCMD:fillall(playerid, params[], help)
{
    new string[128] = "\0", string2[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 3) return adminError(playerid, 3);
    else
    {
		foreach(Player, i)
		{
		   if(IsPlayerInAnyVehicle(i))
		   {
              Gorivo[GetPlayerVehicleID(i)] = (MAX_FUEL);
		   }
		}
		format(string, (sizeof string), ""#zuta"[FIX]: "#ljubicasta"Administrator %s je napunio svima vozilo gorivom.",GetName(playerid));
		format(string2, (sizeof string2), ""#zuta"[FIX]: "#ljubicasta"Administrator %s has filled with fuel all vehicles.",GetName(playerid));
		ScmToAll(string, string2);
    }
	return (true);
}

YCMD:fix(playerid, params[], help)
{
	new id, string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else if(sscanf(params, "u",id)) return SCM(playerid, ""#bijela"KORISTI: /fix [playerid]", ""#bijela"USAGE: /fix [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(!IsPlayerInAnyVehicle(id)) return SCM(playerid, ""#siva"Igrac nije u vozilu.", ""#siva"That player is not in vehicle.");
    else
    {
		RepairVehicle(GetPlayerVehicleID(id));
		SetVehicleHealth(GetPlayerVehicleID(id), 1000.0);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#bijela"* Administrator %s je popravio tvoje vozilo.",GetName(playerid));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#bijela"* Administrator %s has fix your vehicle.",GetName(playerid));
		}
		SCM(id, string, string);
		SCM(playerid, ""#bijela"* Popravio si vozilo.", ""#bijela"* You fix vehicle");
    }
	return (true);
}

YCMD:fixall(playerid, params[], help)
{
    new string[128] = "\0", string2[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else
    {
		foreach(Player, i)
		{
		   if(IsPlayerInAnyVehicle(i))
		   {
              RepairVehicle(GetPlayerVehicleID(i));
		      SetVehicleHealth(GetPlayerVehicleID(i), 1000.0);
		   }
		}
		format(string, (sizeof string), ""#zuta"[FIX]: "#ljubicasta"Administrator %s je popravio svima vozilo.",GetName(playerid));
		format(string2, (sizeof string2), ""#zuta"[FIX]: "#ljubicasta"Administrator %s has fixed all vehicles.",GetName(playerid));
		ScmToAll(string, string2);
    }
	return (true);
}

YCMD:text(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else if(sscanf(params, "s[60]", params)) return SCM(playerid, ""#bijela"KORISTI: /text [tekst]", ""#bijela"USAGE: /text [text]");
    else
    {
        GameTextToAll(params,params,5000,4);
    }
	return (true);
}

YCMD:warn(playerid, params[], help)
{
	new string[128] = "\0", string2[128] = "\0", id;
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else if(sscanf(params, "us[64]", id, params)) return SCM(playerid, ""#bijela"KORISTI: /warn [playerid] [razlog]", ""#bijela"USAGE: /warn [playerid] [reason]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    {
		format(string, (sizeof string), ""#zuta"[UPOZORENJE]: "#ljubicasta"Administrator %s je upozorio %s. - RAZLOG: "#bijela"%s",GetName(playerid),GetName(id),params);
		format(string2, (sizeof string2), ""#zuta"[WARNING]: "#ljubicasta"Administrator %s has warned %s. - REASON: "#bijela"%s",GetName(playerid),GetName(id),params);
		ScmToAll(string, string2);
		PlayerInfo[id][Upozorenja] ++;
		upozorenje{id} ++;
		if(upozorenje{id} >= 3)
		{
		    Kick(id);
		}
		new dan_, mjesec_, godina_;
        getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je dao upozorenje %s RAZLOG: %s (%d.%d.%d)",GetName(playerid),GetName(id), params, dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

YCMD:slap(playerid, params[], help)
{
	new string[128] = "\0", id, Float:Pos[3];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 2) return adminError(playerid, 2);
    else if(sscanf(params, "u",id)) return SCM(playerid, ""#bijela"KORISTI: /slap [playerid]", ""#bijela"USAGE: /slap [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    {
		GetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
		SFP_SetPlayerPos(id, Pos[0], Pos[1], Pos[2]+3);
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"[SAMAR]: "#bijela"Administrator %s te osamario.",GetName(playerid));
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
           format(string, (sizeof string), ""#zuta"[SLAP]: "#bijela"Administrator %s has slapped you.",GetName(playerid));
		}
		SCM(id, string, string);
		
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"[SAMAR]: "#bijela"Osamario si %s.",GetName(id));
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
           format(string, (sizeof string), ""#zuta"[SLAP]: "#bijela"You slap %s.",GetName(id));
		}
		SCM(playerid, string, string);
		PlayerPlaySound(id, 1190, Pos[0], Pos[1], Pos[2]);
    }
	return (true);
}

YCMD:say(playerid, params[], help)
{
	new string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "s[128]", params)) return SCM(playerid, ""#bijela"KORISTI: /say [tekst]", ""#bijela"USAGE: /say [text]");
    else
    {
		format(string, (sizeof string), ""#ljubicasta"ADMINISTRATOR %s: "#bijela"%s", GetName(playerid), params);
		ScmToAll(string,string);
    }
	return (true);
}

YCMD:goto(playerid, params[], help)
{
    new string[128] = "\0", id, Float:Pos[3];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "u", id)) return SCM(playerid, ""#bijela"KORISTI: /goto [playerid]", ""#bijela"USAGE: /goto [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		GetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
		SFP_SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"Teleportirao si se do igraca %s(%d).",GetName(id),id);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
			format(string, (sizeof string), ""#zuta"You are teleported to %s(%d).",GetName(id),id);
		}
		SCM(playerid, string, string);
    }
	return (true);
}

YCMD:get(playerid, params[], help)
{
    new string[128] = "\0", id, Float:Pos[3];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "u", id)) return SCM(playerid, ""#bijela"KORISTI: /get [playerid]", ""#bijela"USAGE: /get [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SFP_SetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"Teleportirao si igraca %s(%d) do sebe.",GetName(id),id);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
			format(string, (sizeof string), ""#zuta"You are teleported %s(%d) to you.",GetName(id),id);
		}
		SCM(playerid, string, string);
        if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#zuta"Administrator %s(%d) te teleportirao do sebe.",GetName(playerid),playerid);
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
			format(string, (sizeof string), ""#zuta"Administrator %s(%d) has teleported you to himself.",GetName(id),id);
		}
		SCM(id, string, string);
    }
	return (true);
}

YCMD:getcar(playerid, params[], help)
{
	new carid,Float:Pos[3];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "i", carid)) return SCM(playerid, ""#bijela"KORISTI: /getcar [id]", ""#bijela"USAGE: /getcar [carid]");
    else
    {
		GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SetVehiclePos(carid, Pos[0], Pos[1], Pos[2]);
    }
	return (true);
}

YCMD:gotocar(playerid, params[], help)
{
    new carid,Float:Pos[3];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "i", carid)) return SCM(playerid, ""#bijela"KORISTI: /gotocar [id]", ""#bijela"USAGE: /gotocar [carid]");
    else
    {
		GetVehiclePos(carid, Pos[0], Pos[1], Pos[2]);
		SFP_SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    }
	return (true);
}

YCMD:lcar(playerid, params[], help)
{
	new string[60], id = (0);
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "u", id)) return SCM(playerid, ""#bijela"KORISTI: /lcar [playerid]", ""#bijela"USAGE: /lcar [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#bijela"* Zadnje vozilo u kojem je %s bio ID:%d",GetName(id),zadnje_vozilo[id]);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#bijela"* Last vehicle from %s ID is:%d",GetName(id),zadnje_vozilo[playerid]);
		}
		SCM(playerid, string, string);
    }
	return (true);
}

YCMD:a(playerid, params[], help)
{
	new
	   string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "s[128]", params)) return SCM(playerid, ""#bijela"KORISTI: /a [tekst]", ""#bijela"USAGE: /a [text]");
    else
    {
		format(string, (sizeof string), ""#error"[ADMIN CHAT %s]: "#bijela"%s",GetName(playerid),params);
		SAM(string, string, 1);
		
		new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s: %s (%d.%d.%d)",GetName(playerid), params, dan_, mjesec_, godina_);
	    AdminChatLog(string);
    }
	return (true);
}

YCMD:check(playerid, params[], help)
{
	new
	   string[750],id, veh1[20] = "\0", veh2[20] = "\0", veh3[20] = "\0", kuca[5] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "u", id)) return SCM(playerid, ""#bijela"KORISTI: /check [playerid]", ""#bijela"USAGE: /check [playerid]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		if(PlayerInfo[id][Kljuc_Vozilo][0] != INVALID_CAR_ID)
		{
			 format(veh1, (sizeof veh1), "%s (%d)", VehicleNames[GetVehicleModel(PlayerInfo[id][Kljuc_Vozilo][0])-400], PlayerInfo[id][Kljuc_Vozilo][0]);
		}
		else if(PlayerInfo[id][Kljuc_Vozilo][0] == INVALID_CAR_ID) { veh1 = "-/-"; }
		if(PlayerInfo[id][Kljuc_Vozilo][1] != INVALID_CAR_ID)
		{
			 format(veh2, (sizeof veh2), "%s (%d)", VehicleNames[GetVehicleModel(PlayerInfo[id][Kljuc_Vozilo][1])-400], PlayerInfo[id][Kljuc_Vozilo][1]);
		}
		else if(PlayerInfo[id][Kljuc_Vozilo][1] == INVALID_CAR_ID) { veh2 = "-/-"; }
		if(PlayerInfo[id][Kljuc_Vozilo][2] != INVALID_CAR_ID)
		{
			 format(veh3, (sizeof veh3), "%s (%d)", VehicleNames[GetVehicleModel(PlayerInfo[id][Kljuc_Vozilo][2])-400], PlayerInfo[id][Kljuc_Vozilo][2]);
		}
		else if(PlayerInfo[id][Kljuc_Vozilo][2] == INVALID_CAR_ID) { veh3 = "-/-"; }
		
		if(PlayerInfo[id][Kljuc_Kuca] != INVALID_HOUSE_ID)
		{
			format(kuca, (sizeof kuca), "%d", PlayerInfo[id][Kljuc_Kuca]);
		}
		else if(PlayerInfo[id][Kljuc_Kuca] == INVALID_HOUSE_ID) { kuca = "-/-"; }
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
			format(string, 750, ""#zuta"NOVAC: "#bijela"$%d\n"#zuta"BODOVI: "#bijela"%d\n"#zuta"ONLINE: "#bijela"%d:%d\n"#zuta"REGISTRIRAN: "#bijela"%d\n"#zuta"LOGIRAN PUTA: "#bijela"%d\n"#zuta"TANKIRAO PUTA: "#bijela"%d\n"#zuta"POTROSENO NOVACA NA TANK: "#bijela"$%d\n"#zuta"POPRAVIO VOZILO PUTA: "#bijela"%d",
			PlayerInfo[id][Novac],PlayerInfo[id][Bodovi],PlayerInfo[id][Sati],PlayerInfo[id][Minute],PlayerInfo[id][Registracija],PlayerInfo[id][Logiran],PlayerInfo[id][Tankirao][0],PlayerInfo[id][Tankirao][1],PlayerInfo[id][Popravio][0]);
			format(string, 750, "%s\n"#zuta"POTROSENO NOVACA NA POPRAVKE: "#bijela"$%d\n"#zuta"UMRO PUTA: "#bijela"%d\n"#zuta"PREKINUTE RUTE: "#bijela"%d\n"#zuta"UPOZOREN PUTA: "#bijela"%d\n"#zuta"JEZIK: "#bijela"%s\n"#zuta"POHVALA: "#bijela"%d\n"#zuta"POSAO: "#bijela"%s",string,PlayerInfo[id][Popravio][1],PlayerInfo[id][Smrt],PlayerInfo[id][Prekid],PlayerInfo[id][Upozorenja],GetPlayerLanguage(id),PlayerInfo[id][Pohvale],GetPlayerJob(id));
			format(string, 750, "%s\n"#zuta"KUCA: "#bijela"%s\n"#zuta"VOZILO 1: "#bijela"%s\n"#zuta"VOZILO 2: "#bijela"%s\n"#zuta"VOZILO 3: "#bijela"%s",string, kuca,veh1,veh2,veh3);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, 750, ""#zuta"MONEY: "#bijela"$%d\n"#zuta"SCORES: "#bijela"%d\n"#zuta"ONLINE: "#bijela"%d:%d\n"#zuta"REGISTRED: "#bijela"%d\n"#zuta"LOGGED TIMES: "#bijela"%d\n"#zuta"REFUEL TIMES: "#bijela"%d\n"#zuta"MONEY SPENT ON FUEL: "#bijela"$%d\n"#zuta"VEHICLE REPAIRED: "#bijela"%d",
			PlayerInfo[id][Novac],PlayerInfo[id][Bodovi],PlayerInfo[id][Sati],PlayerInfo[id][Minute],PlayerInfo[id][Registracija],PlayerInfo[id][Logiran],PlayerInfo[id][Tankirao][0],PlayerInfo[id][Tankirao][1],PlayerInfo[id][Popravio][0]);
			format(string, 750,"%s\n"#zuta"MONEY SPENT ON REPAIR: "#bijela"$%d\n"#zuta"DEATHS: "#bijela"%d\n"#zuta"ABORTED ROUTES: "#bijela"%d\n"#zuta"WARNED TIMES: "#bijela"%d\n"#zuta"LANGUAGE: "#bijela"%s\n"#zuta"TOTAL PRAISES: "#bijela"%d\n"#zuta"JOB: "#bijela"%s",string,PlayerInfo[id][Popravio][1],PlayerInfo[id][Smrt],PlayerInfo[id][Prekid],PlayerInfo[id][Upozorenja],GetPlayerLanguage(id),PlayerInfo[id][Pohvale],GetPlayerJob(id));
            format(string, 750, "%s\n"#zuta"HOUSE: "#bijela"%s\n"#zuta"VEHICLE 1: "#bijela"%s\n"#zuta"VEHICLE 2: "#bijela"%s\n"#zuta"VEHICLE 3: "#bijela"%s",string, kuca,veh1,veh2,veh3);
		}
		CreateDialog(playerid, DIALOG_ADMIN_CHECK, DIALOG_STYLE_MSGBOX, ""#error"Stats", string, "Ok", "", ""#error"Stats", string, "Ok", "");
    }
	return (true);
}

YCMD:kick(playerid, params[], help)
{
	new string[128] = "\0", id, string2[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 1) return adminError(playerid, 1);
    else if(sscanf(params, "us[64]", id, params)) return SCM(playerid, ""#bijela"KORISTI: /kick [playerid] [razlog]", ""#bijela"USAGE: /kick [playerid] [reason]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else
    {
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
		   format(string, (sizeof string), ""#ljubicasta"Administrator %s te kickao sa servera - RAZLOG: %s",GetName(playerid),params);
		   SCM(id, string, string);
        }
        else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
        {
           format(string, (sizeof string), ""#ljubicasta"Administrator %s has kicked you from server - REASON: %s",GetName(playerid),params);
		   SCM(id, string, string);
        }
		format(string2, (sizeof string2), ""#zuta"[KICK]: "#ljubicasta"Administrator %s je kickao %s - RAZLOG: %s",GetName(playerid),GetName(id),params);
		format(string, (sizeof string), ""#zuta"[KICK]: "#ljubicasta"Administrator %s has kicked %s - REASON: %s",GetName(playerid),GetName(id),params);
		ScmToAll(string2,string);
        new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je kickao %s RAZLOG: %s (%d.%d.%d)",GetName(playerid),GetName(id), params, dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
		Kick(id);
    }
	return (true);
}

YCMD:work(playerid, params[], help)
{
	new
	   vehicleid = GetPlayerVehicleID(playerid);
	if(PlayerLogin{playerid} == false) return logout(playerid);
	else if(posao{playerid} == true) return SCM(playerid, ""#error"[SERVER]: "#bijela"Vec radis! Koristi /cancel za prekid posla.", ""#error"[SERVER]: "#bijela"You already working! Use /cancel to stop working.");
	else if(CivilniAvion(vehicleid) || CarInfo[vehicleid][v_Posao] == 1)
	{
	   if(Team{playerid} == 1 || Team{playerid} == 2 || Team{playerid} == 3)
	   {
             ruta_sec{playerid} = (1);
             ruta_min{playerid} = (0);
             posao{playerid} = (true);
             DisablePlayerRaceCheckpoint(playerid);
             PreuzimanjePaketaCivilniPiloti(playerid);
	         work_vehicle[playerid] = GetPlayerVehicleID(playerid);
	         SendInfo(playerid, "Kreni preuzeti paket! Lokacija ti se nalazi na radaru i oznacena je ~r~crvenom~w~ tockicom.", "Go pick up a package, location is marked on your radar.", true);
	   }
	}
	else if(MedicinskiAvion(vehicleid) || CarInfo[vehicleid][v_Posao] == 2)
	{
	   if(Team{playerid} == 2 || Team{playerid} == 3) 
	   {
              ruta_sec{playerid} = (1);
              ruta_min{playerid} = (0);
		      posao{playerid} = (true);
		      DisablePlayerRaceCheckpoint(playerid);
		      PreuzimanjePaketaMediPiloti(playerid);
		      work_vehicle[playerid] = GetPlayerVehicleID(playerid);
		      SendInfo(playerid, "Kreni preuzeti paket! Lokacija ti se nalazi na radaru i oznacena je ~r~crvenom~w~ tockicom.", "Go pick up a package, location is marked on your radar.", true);
	   }
	}
	else if(VojniAvion(vehicleid) || VojniHeli(vehicleid) || CarInfo[vehicleid][v_Posao] == 3)
	{
	   if(Team{playerid} == 3)
	   {
		   posao{playerid} = (true);
		   DisablePlayerRaceCheckpoint(playerid);
		   ruta_sec{playerid} = (1);
           ruta_min{playerid} = (0);
		   if(VojniAvion(vehicleid) || CarInfo[vehicleid][v_Posao] == 3)
		   {
		      PreuzimanjePaketaCivilniPiloti(playerid);
		   }
		   else if(VojniHeli(vehicleid))
		   {
		      PreuzimanjePaketaMediPiloti(playerid);
		   }
		   work_vehicle[playerid] = GetPlayerVehicleID(playerid);
		   SendInfo(playerid, "Kreni preuzeti paket! Lokacija ti se nalazi na radaru i oznacena je ~r~crvenom~w~ tockicom.", "Go pick up a package, location is marked on your radar.", true);
	   }
	}
	else if(TaxiAuto(vehicleid))
	{
        if(GetPlayerState(playerid) !=  PLAYER_STATE_DRIVER) return (true);
		if(Team{playerid} == 4)
		{
			if(TaxiGrad(playerid) == 1) // LS
			{
			    posao{playerid} = (true);
		        DisablePlayerRaceCheckpoint(playerid);
		        PreuzimanjePutnikaLS(playerid);
		        work_vehicle[playerid] = GetPlayerVehicleID(playerid);
		        SendInfo(playerid, "Putnik te ceka, pozuri ga pokupiti kako bi stigao na vrijeme.", "Client waiting you, hurry up to pick him so he can come on a time.", true);
			}
			else if(TaxiGrad(playerid) == 2) // LV
			{
                posao{playerid} = (true);
		        DisablePlayerRaceCheckpoint(playerid);
		        PreuzimanjePutnikaLV(playerid);
		        work_vehicle[playerid] = GetPlayerVehicleID(playerid);
		        SendInfo(playerid, "Putnik te ceka, pozuri ga pokupiti kako bi stigao na vrijeme.", "Client waiting you, hurry up to pick him so he can come on a time.", true);
			}
			if(TaxiGrad(playerid) == 3) // SF
			{
			    posao{playerid} = (true);
		        DisablePlayerRaceCheckpoint(playerid);
		        PreuzimanjePutnikaSF(playerid);
		        work_vehicle[playerid] = GetPlayerVehicleID(playerid);
		        SendInfo(playerid, "Putnik te ceka, pozuri ga pokupiti kako bi stigao na vrijeme.", "Client waiting you, hurry up to pick him so he can come on a time.", true);
			}
			ruta_sec{playerid} = (1);
            ruta_min{playerid} = (0);
		}
	}
	else if(Truck(vehicleid))
	{
        if(Team{playerid} == 6)
        {
            if(!IsTrailerAttachedToVehicle(vehicleid)) return SCM(playerid, ""#error"[INFO]: "#bijela"Prikolica nije prikvacena za kamion.", ""#error"[INFO]: "#bijela"Trailer is not attached to the truck.");
            else
            {
                work_vehicle[playerid] = GetPlayerVehicleID(playerid);
                posao{playerid} = (true);
		        DisablePlayerRaceCheckpoint(playerid);
		        ruta_sec{playerid} = (1);
                ruta_min{playerid} = (0);
				PreuzimanjeTereta(playerid);
                SendInfo(playerid, "Zapoceo si sa poslom, vozi do ~r~crvene ~w~tocke na tvom radaru!", "You started with a job! Drive to the ~r~red~w~ marker on your radar!", true);
            }
        }
	}
	else if(IsABoat(vehicleid))
	{
        if(Team{playerid} == 7)
        {
            work_vehicle[playerid] = GetPlayerVehicleID(playerid);
            posao{playerid} = (true);
            DisablePlayerRaceCheckpoint(playerid);
            ruta_sec{playerid} = (1);
            ruta_min{playerid} = (0);
	        PreuzimanjeTereta_Brod(playerid);
            SendInfo(playerid, "Zapoceo si sa poslom, vozi do ~r~crvene ~w~tocke na tvom radaru!", "You started with a job! Drive to the ~r~red~w~ marker on your radar!", true);
        }
	}
	else
	{
		return SCM(playerid, ""#error"[SERVER]: "#bijela"Moras biti u vozilu za posao.", ""#error"[SERVER]: "#bijela"You must be in vehicle for work.");
	}
	novost(GetName(playerid), "je zapoceo novu rutu.");
	return (true);
}

YCMD:radio(playerid, params[], help)
{
	new string[512];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(!IsPlayerHaveRadio(playerid)) return SCM(playerid, ""#siva"Nemas radio (/store).", ""#siva"You don't have a radio (/store).");
    else
    {
		format(string, 256, ""#zuta"(1): "#bijela".:: BALKAN DJ ::.\n"#zuta"(2): "#bijela".:: iLoveRadio ::.\n"#zuta"(3): "#bijela".:: 24DubStep ::.\n"#zuta"(4): "#bijela".:: FunTeam Radio ::.\n"#zuta"(5): "#bijela".:: AZ HardCore ::.\n");
		format(string, 512, "%s"#zuta"(6): "#bijela".:: Radio HS ::.\n"#zuta"(7): "#bijela".:: Balkan Hip-Hop ::.\n"#zuta"(8): "#bijela".:: RadioRock1 ::.\n"#zuta"(9): "#bijela".:: Drum&Bass Heaven ::.\n"#zuta"(10): "#bijela".:: Musik Drumstep ::.\n"#zuta"(11): "#bijela".:: Antena Zagreb ::.", string);
        CreateDialog(playerid,
		DIALOG_RADIO,
		DIALOG_STYLE_LIST,
		""#error"Radio stanice",
		string,
		"Play",
		"Odustani",
		""#error"Radio stations", // ENGLISH
		string,
		"Play",
		"Cancel");
    }
	return (true);
}

YCMD:cancel(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(posao{playerid} == false) return SCM(playerid, ""#error"[SERVER]: "#bijela"Nisi zapoceo sa poslom!", ""#error"[SERVER]: "#bijela"You don't work!");
    else
    {
		GivePlayerMoneyEx(playerid, -5000);
		Bonus{playerid} = (0);
		DisablePlayerRaceCheckpoint(playerid);
		work_vehicle[playerid] = (-1);
		PlayerInfo[playerid][Prekid] ++;
		SCM(playerid, ""#error"[SERVER]: "#bijela"Prekinuo si transport.", ""#error"[SERVER]: "#bijela"You cancel a transport.");
		posao{playerid} = (false);
		ruta_sec{playerid} = (0);
        ruta_min{playerid} = (0);
        bonus_[playerid] = (578.00);
        novost(GetName(playerid), "je namjerno prekinuo rutu i izgubio nesto novaca.");
    }
	return (true);
}

YCMD:store(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
        CreateDialog(playerid,
		DIALOG_STORE,
		DIALOG_STYLE_LIST,
		""#error"Online ducan",
		""#zuta"(1): "#bijela"Kupi\n"#zuta"(2): "#bijela"Prodaj",
		"Odaberi",
		"Odustani",
		""#error"Online store", // ENGLISH
		""#zuta"(1): "#bijela"Buy stuff\n"#zuta"(2): "#bijela"Sell stuff",
		"Choose",
		"Cancel");
    }
	return (true);
}

YCMD:buyhouse(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID) return SCM(playerid, ""#siva"* Vec posjedujes kucu!", ""#siva"* You already own a house!");
    else
    {
       for(new i=0; i < MAX_HOUSES; ++i)
	   {
          if(IsPlayerInRangeOfPoint(playerid, 2.5, HouseInfo[i][h_Pi][0], HouseInfo[i][h_Pi][1], HouseInfo[i][h_Pi][2]))
          {
			  //if(!strcmp(HouseInfo[i][h_Vlasnik], "-/-") == 0) return SCM(playerid, ""#siva"* Kuca vec ima vlasnika", ""#siva"* You can't buy this house.");
			  if(GetPlayerMoneyEx(playerid) < HouseInfo[i][h_Cijena]) return SCM(playerid, ""#siva"* Nemas dovoljno novaca.", ""#siva"* You don't have enough money.");
			  format(HouseInfo[i][h_Vlasnik], MAX_PLAYER_NAME, "%s", GetName(playerid));
			  GivePlayerMoneyEx(playerid, -HouseInfo[i][h_Cijena]);
			  PlayerInfo[playerid][Kljuc_Kuca] = (i);
			  UpdatePlayer(playerid);
			  UpdateHouse(i);
			  novost(GetName(playerid), "je kupio kucu.");
			  UpdateHouseLabel(i);
			  GameText(playerid, "~w~Cestitamo na kupnji!~n~~g~ENTER ~w~za ulaz!", "~w~Congratulations!~n~~g~PRESS ENTER", 3000, 3);
          }
	   }
	}
	return (true);
}

YCMD:sellhouse(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Kljuc_Kuca] == INVALID_HOUSE_ID) return SCM(playerid, ""#siva"* Ne posjedujes kucu!", ""#siva"* You don't own a house!");
    else
    {
       for(new i=0;i<MAX_HOUSES;i++)
	   {
           if(IsPlayerInRangeOfPoint(playerid, 2.5, HouseInfo[i][h_Pi][0], HouseInfo[i][h_Pi][1], HouseInfo[i][h_Pi][2]) && strcmp(HouseInfo[i][h_Vlasnik], GetName(playerid), false) == 0)
		   {
			  if(HouseInfo[i][ID] != PlayerInfo[playerid][Kljuc_Kuca]) return SCM(playerid, ""#siva"* Ovo nije tvoja kuca.", ""#siva"* You can't sell this house because you don't own it.");
              format(HouseInfo[i][h_Vlasnik], MAX_PLAYER_NAME, "-/-");
			  GivePlayerMoneyEx(playerid, (HouseInfo[i][h_Cijena]/2));
			  PlayerInfo[playerid][Kljuc_Kuca] = (INVALID_HOUSE_ID);
			  UpdatePlayer(playerid);
			  UpdateHouse(i);
			  novost(GetName(playerid), "je prodao svoju kucu.");
			  UpdateHouseLabel(i);
			  GameText(playerid, "~w~Cestitamo na prodaji!", "~w~Congratulations!", 3000, 3);
		   }
	   }
    }
	return (true);
}

YCMD:lockhouse(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Kljuc_Kuca] == INVALID_HOUSE_ID) return SCM(playerid, ""#siva"* Ne posjedujes kucu!", ""#siva"* You don't own a house!");
    else if(HouseInfo[PlayerInfo[playerid][Kljuc_Kuca]][h_Locked] == 1) return SCM(playerid, ""#siva"* Kuca je vec zakljucana!", ""#siva"* Your house is already locked!");
    else
    {
        novost(GetName(playerid), "je zakljucao svoju kucu.");
		HouseInfo[PlayerInfo[playerid][Kljuc_Kuca]][h_Locked] = (1);
		UpdateHouse(PlayerInfo[playerid][Kljuc_Kuca]);
		GameText(playerid, "~g~Zakljucano!", "~g~Locked!", 2500, 3);
    }
	return (true);
}

YCMD:unlockhouse(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Kljuc_Kuca] == INVALID_HOUSE_ID) return SCM(playerid, ""#siva"* Ne posjedujes kucu!", ""#siva"* You don't own a house!");
    else if(HouseInfo[PlayerInfo[playerid][Kljuc_Kuca]][h_Locked] == 0) return SCM(playerid, ""#siva"* Kuca je vec otkljucana!", ""#siva"* Your house is already unlocked!");
	else
    {
        novost(GetName(playerid), "je otkljucao svoju kucu.");
		HouseInfo[PlayerInfo[playerid][Kljuc_Kuca]][h_Locked] = (0);
		UpdateHouse(PlayerInfo[playerid][Kljuc_Kuca]);
		GameText(playerid, "~w~Otkljucano!", "~w~Unlocked!", 2500, 3);
    }
	return (true);
}

YCMD:vehicles(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(GetPlayerScoreEx(playerid) < 20) return SCM(playerid, ""#siva"* Moras imati 20+ bodova!", ""#siva"* You must have 20+ scores!");
    else
    {
       CreateDialog(playerid,
       DIALOG_VEHICLE_CAT,
	   DIALOG_STYLE_LIST,
       ""#error"Odaberi",
       ""#zuta"(1): "#bijela"Motori\n"#zuta"(2): "#bijela"Auti",
	   "Odaberi", "Odustani",
       ""#error"Choose",
       ""#zuta"(1): "#bijela"Motorcycles\n"#zuta"(2): "#bijela"Cars",
  	   "Accept", "Cancel");
    }
	return (true);
}

YCMD:help(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
		SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
		SCM(playerid, ""#zuta"/work /cancel /rules /admins /report /pm /store /stats /kill", ""#zuta"/work /cancel /rules /admins /report /pm /store /stats /kill");
		SCM(playerid, ""#zuta"/account /at400s /eject /buyhouse /sellhouse /(un)lockhouse", ""#zuta"/account /at400s /eject /buyhouse /sellhouse /(un)lockhouse");
		SCM(playerid, ""#zuta"/vehicles /(un)lockcar /locatecar /parkcar /sellcar /sendmoney", ""#zuta"/vehicles /(un)lockcar /locatecar /parkcar /sellcar /sendmoney");
		SCM(playerid, ""#zuta"/radio /vips /airlines /createairline /company /editcompany /r", ""#zuta"/radio /vips /airlines /createairline /company /editcompany /r");
		SCM(playerid, ""#zuta"/vhelp", ""#zuta"/vhelp");
		SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
    }
	return (true);
}

YCMD:vhelp(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] == 1)
    {
		 SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
		 SCM(playerid, ""#zelena"VIP LEVEL 1 - Dobiva 2 boda po ruti i $1,000,000 na startu!", ""#zelena"VIP LEVEL 1 - Gets 2 scores per route and $1,000,000 at the start");
		 SCM(playerid, ""#zelena"KOMANDE: "#bijela"/v /skin /pmblock", ""#zelena"COMMANDS: "#bijela"/v /skin /pmblock");
		 SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
    }
    else if(PlayerInfo[playerid][Vip] == 2)
    {
		 SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
		 SCM(playerid, ""#zelena"VIP LEVEL 2 - Dobiva 2 boda po ruti i $2,000,000 na startu!", ""#zelena"VIP LEVEL 2 - Gets 2 scores per route and $2,000,000 at the start");
		 SCM(playerid, ""#zelena"KOMANDE: "#bijela"/v /skin /pmblock /vfill /vfix", ""#zelena"COMMANDS: "#bijela"/v /skin /pmblock /vfill /vfix");
		 SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
    }
    else if(PlayerInfo[playerid][Vip] == 3)
    {
		 SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
		 SCM(playerid, ""#zelena"VIP LEVEL 3 - Dobiva 2 boda po ruti i $3,000,000 na startu!", ""#zelena"VIP LEVEL 3 - Gets 2 scores per route and $3,000,000 at the start");
		 SCM(playerid, ""#zelena"KOMANDE: "#bijela"/v /skin /pmblock /vfill /vfix /vgetpos /vgotopos", ""#zelena"COMMANDS: "#bijela"/v /skin /pmblock /vfill /vfix /vgetpos /vgotopos");
		 SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
    }
    else { SCM(playerid, ""#siva"* Samo VIP igraci mogu koristiti ovu komandu!", ""#siva"* Just VIP players can use this command!"); }
	return (true);
}

YCMD:vgetpos(playerid, params[], help)
{
	new Float:Pos[3];
	if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 3) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(GetPlayerInterior(playerid) != 0) return SCM(playerid, ""#siva"Tvoj interior mora biti 0.", ""#siva"Your interior must be 0.");
    else
    {
		GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		PlayerInfo[playerid][Pozicija][0] = (Pos[0]);
		PlayerInfo[playerid][Pozicija][1] = (Pos[1]);
		PlayerInfo[playerid][Pozicija][2] = (Pos[2]);
		SCM(playerid, ""#bijela"* Pozicija uspjesno spremljena koristi /vgotopos da se teleportiras do pozicije.", ""#bijela"* Position is successfully saved, use /vgotopos to teleport back on this position.");
		UpdatePlayer(playerid);
    }
	return (true);
}

YCMD:vgotopos(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 3) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(PlayerInfo[playerid][Pozicija][0] == 0.000 && PlayerInfo[playerid][Pozicija][1] == 0.000 && PlayerInfo[playerid][Pozicija][2] == 0.000) return SCM(playerid, ""#siva"Prvo koristi /vgetpos", ""#siva"First use /savepost then use /vgetpos");
    {
		SFP_SetPlayerPos(playerid, PlayerInfo[playerid][Pozicija][0], PlayerInfo[playerid][Pozicija][1], PlayerInfo[playerid][Pozicija][2]);
		SCM(playerid, ""#bijela"* Uspjesno si se teleportirao na svoju poziciju.", ""#bijela"* You have been successfully teleported to your position.");
    }
	return (true);
}

YCMD:v(playerid, params[], help)
{
	new string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 1) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(sscanf(params, "s[120]", params)) return SCM(playerid, ""#bijela"KORISTI: /v [tekst]", ""#bijela"USAGE: /v [text]");
    else
    {
		foreach(Player, i)
		{
		   if(PlayerInfo[i][Vip] >= 1)
		   {
			  format(string, (sizeof string), ""#zelena"[VIP %s]: "#bijela"%s",GetName(playerid), params);
			  SCM(i, string, string);
		   }
		}
    }
	return (true);
}

YCMD:skin(playerid, params[], help)
{
	new skinid = (0);
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 1) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(sscanf(params, "d", skinid)) return SCM(playerid, ""#bijela"KORISTI: /skin [skin id]", ""#bijela"USAGE: /skin [skin id]");
    else if(skinid < 0 || skinid > 299) return SCM(playerid, ""#siva"* Skin ID mora biti veci od -1 i manji od 300!", ""#siva"* Minimum skin id is 0 - maximum 299!");
    else
    {
		SetPlayerSkin(playerid, skinid);
    }
	return (true);
}

YCMD:pmblock(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 1) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(block_pm{playerid} == true)
    {
		block_pm{playerid} = (false);
		SCM(playerid, ""#bijela"* Ukljucio si privatne poruke.", ""#bijela"* You accept private messages now.");
    }
    else if(block_pm{playerid} == false)
    {
        block_pm{playerid} = (true);
        SCM(playerid, ""#bijela"* Iskljucio si privatne poruke.", ""#bijela"* You don't accept private messages anymore.");
    }
	return (true);
}

YCMD:vfill(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 2) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Moras biti u vozilu!", ""#siva"You must be in vehicle!");
    else
    {
		Gorivo[GetPlayerVehicleID(playerid)] = (MAX_FUEL);
		SCM(playerid, ""#bijela"* Napunio si svoje vozilo gorivom", ""#bijela"* You fill your vehicle.");
    }
	return (true);
}

YCMD:vfix(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vip] < 2) return SCM(playerid, ""#siva"* Ova komanda je samo za VIP igrace!", ""#siva"* This command is just for VIP players!");
    else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Moras biti u vozilu!", ""#siva"You must be in vehicle!");
    else
    {
		RepairVehicle(GetPlayerVehicleID(playerid));
		SetVehicleHealth(GetPlayerVehicleID(playerid), 1000.0);
		SCM(playerid, ""#bijela"* Popravio si svoje vozilo.", ""#bijela"* You fix your vehicle");
    }
	return (true);
}

YCMD:r(playerid, params[], help)
{
	new id = IsPlayerInAirline(playerid, GetName(playerid)), string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(id == -1) return SCM(playerid, ""#siva"* Ne mozes koristiti radio jer nisi u avio kompaniji!", ""#siva"* You can't use this command beacuse you don't work in any airline.");
    else if(sscanf(params, "s[120]", params)) return SCM(playerid, ""#bijela"KORISTI: /r [tekst]", ""#bijela"USAGE: /r [text]");
    else
    {
		foreach(Player, i)
		{
			new id_2 = IsPlayerInAirline(i, GetName(i));
			if(id_2 == id)
			{
			   format(string, (sizeof string), ""#zuta"[%s | %s]: "#bijela"%s", AvioKompanija[id][av_Ime], GetName(playerid), params);
			   SCM(i, string, string);
			}
		}
    }
	return (true);
}

YCMD:accept(playerid, params[], help)
{
	new string1[128] = "\0", string2[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(av_call_avio{playerid} == -1) return SCM(playerid, ""#siva"* Nemas nikakvu pozivnicu.", ""#siva"* You are not invited in any airline.");
    else if(av_call_vlasnik[playerid] == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"* Nemas nikakvu pozivnicu.", ""#siva"* You are not invited in any airline.");
    else if(av_call_time{playerid} == 0) return SCM(playerid, ""#siva"* Nemas nikakvu pozivnicu.", ""#siva"* You are not invited in any airline.");
	else
	{
        new avio_id = av_call_avio{playerid}, id = av_call_vlasnik[playerid];
		if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_1], "-/-", false) == 0)
		{
			format(AvioKompanija[avio_id][av_Zaposlenik_1], MAX_PLAYER_NAME, "%s", GetName(playerid));
			PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_2], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_2], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_3], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_3], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_4], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_4], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_5], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_5], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(AvioKompanija[avio_id][av_Upgrade] == 1 && strcmp(AvioKompanija[avio_id][av_Zaposlenik_6], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_6], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(AvioKompanija[avio_id][av_Upgrade] == 2 && strcmp(AvioKompanija[avio_id][av_Zaposlenik_7], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_7], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(AvioKompanija[avio_id][av_Upgrade] == 3 && strcmp(AvioKompanija[avio_id][av_Zaposlenik_8], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_8], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(AvioKompanija[avio_id][av_Upgrade] == 4 && strcmp(AvioKompanija[avio_id][av_Zaposlenik_9], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_9], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else if(AvioKompanija[avio_id][av_Upgrade] == 5 && strcmp(AvioKompanija[avio_id][av_Zaposlenik_10], "-/-", false) == 0)
		{
            format(AvioKompanija[avio_id][av_Zaposlenik_10], MAX_PLAYER_NAME, "%s", GetName(playerid));
            PlayerInfo[playerid][AirlineUgovor] = (7200);
		}
		else
		{
           SCM(playerid, ""#siva"* Nema slobodnog mjesta u kompaniji!", ""#siva"* Sorry there is no space in this airline for you!");
           av_call_avio{playerid} = (-1); av_call_vlasnik[playerid] = (INVALID_PLAYER_ID); av_call_time{playerid} = (0);
           return (true);
		}
		format(string1, (sizeof string1), ""#narancasta">> "#bijela"%s se prikljucio tvojoj avio kompaniji!", GetName(playerid));
		format(string2, (sizeof string2), ""#narancasta">> "#bijela"%s has joined your airline!", GetName(playerid));
		SCM(id, string1, string2);

		format(string1, (sizeof string1), ""#narancasta">> "#bijela"Cestitamo prikljucio si se kompaniji '%s' - koristi /company", AvioKompanija[avio_id][av_Ime]);
		format(string1, (sizeof string1), ""#narancasta">> "#bijela"Congratulations you joined '%s' airline - use /company", AvioKompanija[avio_id][av_Ime]);
		SCM(playerid, string1, string2);

		UpdateAirline(avio_id);
		UpdatePlayer(playerid);
		av_call_avio{playerid} = (-1); av_call_vlasnik[playerid] = (INVALID_PLAYER_ID); av_call_time{playerid} = (0);
    }
	return (true);
}

YCMD:editcompany(playerid, params[], help)
{
	new string[512];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Vlasnik_Kompanije] == -1) return SCM(playerid, ""#siva"* Nisi vlasnik nikakve avio komanije!", ""#siva"* You don't own any airline company!");
	else
	{
		 if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		 {
			 format(string, 256, ""#zelena"ZAPOSLENICI\n"#zuta"PROMJENI IME\n"#zelena"ZATVORI KOMPANIJU\n"#zuta"POZOVI IGRACA U KOMPANIJU\n");
			 format(string, 512, "%s"#zelena"KUPI PRIVATNU ZRACNU LUKU\n"#zuta"KUPUJ VOZILA ZA KOMPANIJU\n"#zelena"UPGRADE KAPACITET ZAPOSLENIKA\n"#zuta"DODAJ INICIJALE",string);
		 }
		 else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		 {
             format(string, 256, ""#zelena"Employees\n"#zuta"Change name\n"#zelena"Close this airline\n"#zuta"INVITE PLAYER IN AIRLINE\n");
			 format(string, 512, "%s"#zelena"BUY PRIVATE AIRPORT\n"#zuta"BUY VEHICLES FOR AIRLINE\n"#zelena"UPGRADE EMPLOYEES AMOUNT\n"#zuta"ADD INITIALS",string);
		 }
		 CreateDialog(playerid, DIALOG_EDIT_AIRLINE, DIALOG_STYLE_LIST, ""#error"UREDI AVIO KOMPANIJU", string, "OK", "ZATVORI", ""#error"EDIT AIRLINE", string, "OK", "CLOSE");
	}
 	return (true);
}

YCMD:company(playerid, params[], help)
{
	new id = IsPlayerInAirline(playerid, GetName(playerid));
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(id == -1) return SCM(playerid, ""#siva"* Ne radis u nijednoj avio kompaniji!", ""#siva"* You don't work in any aireline!");
    else
    {
		CreateDialog(playerid, DIALOG_AIRLINE, DIALOG_STYLE_LIST, ""#error"AVIO KOMPANIJA", ""#bijela"STATISTIKA\nDAJ OTKAZ\nSPAWNAJ ME U BAZI\nCLANOVI\nDONIRAJ KOMPANIJI", "OK", "Zatvori", ""#error"AIRLINE", ""#bijela"AIRLINE STATS\nLEAVE COMPANY\nSPAWN ME IN COMPANY AIRPORT\nMEMBERS\nDONATE TO AIRLINE", "OK", "CLOSE");
    }
	return (true);
}

YCMD:createairline(playerid, params[], help)
{
    new id = IsPlayerInAirline(playerid, GetName(playerid));
    if(PlayerLogin{playerid} == false) return logout(playerid);
	else if(id != -1) return SCM(playerid, ""#siva"* Vec si clan neke druge kompanije!", ""#siva"* You are already in some other airline.");
	else if(PlayerInfo[playerid][Vlasnik_Kompanije] != -1) return SCM(playerid, ""#siva"* Vec imas avio kompaniju!", ""#siva"* You already own airline!");
    else if(GetPlayerScore(playerid) < 200) return SCM(playerid, ""#siva"* Moras imati 200+ bodova!", ""#siva"* You must have 200+ scores!");
    else if(GetPlayerMoneyEx(playerid) < 5000000) return SCM(playerid, ""#siva"* Trebas imati $5,000,000!", ""#siva"* You don't have $5,000,000!");
    else
    {
		 CreateDialog(playerid, DIALOG_CREATE_AIRLINE, DIALOG_STYLE_INPUT, "Nova avio-kompanija!", ""#bijela"Upisi ime kompanije", "DALJE", "ODUSTANI", "New airline", "Type name of airline", "NEXT", "CANCEL");
    }
	return (true);
}

YCMD:airlines(playerid, params[], help)
{
	new string[285] = "\0", counter = 0;
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
		 for(new a=0; a<=MAX_AIRLINES; ++a)
		 {
			 format(Data, (sizeof Data), AVIO_BAZA, a);
			 if(fexist(Data))
			 {
				 counter ++;
				 format(string, 285, "%s"#narancasta"NAME: "#bijela"%s (Owner: %s)\n",string,AvioKompanija[a][av_Ime], AvioKompanija[a][av_Vlasnik]);
			 }
		 }
		 if(counter == 0) { SCM(playerid, ""#siva"* Nema dostupnih avio kompanija!", ""#siva"* There is no available airlines!"); }
		 else { CreateDialog(playerid, DIALOG_LISTA_KOMPANIJA, DIALOG_STYLE_MSGBOX, "Avio kompanije", string, "ZATVORI", "", "Airlines", string, "Close", ""); }
    }
	return (true);
}

YCMD:stats(playerid, params[], help)
{
	new
	   string[950] = "\0", id = (playerid), veh1[20] = "\0", veh2[20] = "\0", veh3[20] = "\0", kuca[5] = "\0";
    if(PlayerLogin{id} == false) return logout(id);
    else
    {
        if(PlayerInfo[id][Kljuc_Vozilo][0] != INVALID_CAR_ID)
		{
			 format(veh1, (sizeof veh1), "%s (%d)", VehicleNames[GetVehicleModel(PlayerInfo[id][Kljuc_Vozilo][0])-400], PlayerInfo[id][Kljuc_Vozilo][0]);
		}
		else if(PlayerInfo[id][Kljuc_Vozilo][0] == INVALID_CAR_ID) { veh1 = "-/-"; }
		if(PlayerInfo[id][Kljuc_Vozilo][1] != INVALID_CAR_ID)
		{
			 format(veh2, (sizeof veh2), "%s (%d)", VehicleNames[GetVehicleModel(PlayerInfo[id][Kljuc_Vozilo][1])-400], PlayerInfo[id][Kljuc_Vozilo][1]);
		}
		else if(PlayerInfo[id][Kljuc_Vozilo][1] == INVALID_CAR_ID) { veh2 = "-/-"; }
		if(PlayerInfo[id][Kljuc_Vozilo][2] != INVALID_CAR_ID)
		{
			 format(veh3, (sizeof veh3), "%s (%d)", VehicleNames[GetVehicleModel(PlayerInfo[id][Kljuc_Vozilo][2])-400], PlayerInfo[id][Kljuc_Vozilo][2]);
		}
		else if(PlayerInfo[id][Kljuc_Vozilo][2] == INVALID_CAR_ID) { veh3 = "-/-"; }

		if(PlayerInfo[id][Kljuc_Kuca] != INVALID_HOUSE_ID)
		{
			format(kuca, (sizeof kuca), "%d", PlayerInfo[id][Kljuc_Kuca]);
		}
		else if(PlayerInfo[id][Kljuc_Kuca] == INVALID_HOUSE_ID) { kuca = "-/-"; }
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
			format(string, 950, ""#zuta"NOVAC: "#bijela"$%d\n"#zuta"BODOVI (pilot): "#bijela"%d\n"#zuta"ONLINE: "#bijela"%d:%d\n"#zuta"REGISTRIRAN: "#bijela"%d\n"#zuta"LOGIRAN PUTA: "#bijela"%d\n"#zuta"TANKIRAO PUTA: "#bijela"%d\n"#zuta"POTROSENO NOVACA NA TANK: "#bijela"$%d\n"#zuta"POPRAVIO VOZILO PUTA: "#bijela"%d",
			PlayerInfo[id][Novac],PlayerInfo[id][Bodovi],PlayerInfo[id][Sati],PlayerInfo[id][Minute],PlayerInfo[id][Registracija],PlayerInfo[id][Logiran],PlayerInfo[id][Tankirao][0],PlayerInfo[id][Tankirao][1],PlayerInfo[id][Popravio][0]);
			format(string, 950, "%s\n"#zuta"POTROSENO NOVACA NA POPRAVKE: "#bijela"$%d\n"#zuta"UMRO PUTA: "#bijela"%d\n"#zuta"PREKINUTE RUTE: "#bijela"%d\n"#zuta"UPOZOREN PUTA: "#bijela"%d\n"#zuta"JEZIK: "#bijela"%s\n"#zuta"POHVALA: "#bijela"%d\n"#zuta"POSAO: "#bijela"%s",string,PlayerInfo[id][Popravio][1],PlayerInfo[id][Smrt],PlayerInfo[id][Prekid],PlayerInfo[id][Upozorenja],GetPlayerLanguage(id),PlayerInfo[id][Pohvale],GetPlayerJob(id));
			format(string, 950, "%s\n"#zuta"KUCA: "#bijela"%s\n"#zuta"VOZILO 1: "#bijela"%s\n"#zuta"VOZILO 2: "#bijela"%s\n"#zuta"VOZILO 3: "#bijela"%s\n"#zuta"BODOVI (taksista): "#bijela"%d\n"#zuta"BODOVI (vozac slepera): "#bijela"%d\n"#zuta"BODOVI (moreplovac): "#bijela"%d",string, kuca,veh1,veh2,veh3, PlayerInfo[id][Bodovi_][0], PlayerInfo[id][Bodovi_][1], PlayerInfo[id][Bodovi_][2]);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, 950, ""#zuta"MONEY: "#bijela"$%d\n"#zuta"SCORE (pilot): "#bijela"%d\n"#zuta"ONLINE: "#bijela"%d:%d\n"#zuta"REGISTRED: "#bijela"%d\n"#zuta"LOGGED TIMES: "#bijela"%d\n"#zuta"REFUEL TIMES: "#bijela"%d\n"#zuta"MONEY SPENT ON FUEL: "#bijela"$%d\n"#zuta"VEHICLE REPAIRED: "#bijela"%d",
			PlayerInfo[id][Novac],PlayerInfo[id][Bodovi],PlayerInfo[id][Sati],PlayerInfo[id][Minute],PlayerInfo[id][Registracija],PlayerInfo[id][Logiran],PlayerInfo[id][Tankirao][0],PlayerInfo[id][Tankirao][1],PlayerInfo[id][Popravio][0]);
			format(string, 950,"%s\n"#zuta"MONEY SPENT ON REPAIR: "#bijela"$%d\n"#zuta"DEATHS: "#bijela"%d\n"#zuta"ABORTED ROUTES: "#bijela"%d\n"#zuta"WARNED TIMES: "#bijela"%d\n"#zuta"LANGUAGE: "#bijela"%s\n"#zuta"TOTAL PRAISES: "#bijela"%d\n"#zuta"JOB: "#bijela"%s",string,PlayerInfo[id][Popravio][1],PlayerInfo[id][Smrt],PlayerInfo[id][Prekid],PlayerInfo[id][Upozorenja],GetPlayerLanguage(id),PlayerInfo[id][Pohvale],GetPlayerJob(id));
            format(string, 950, "%s\n"#zuta"HOUSE: "#bijela"%s\n"#zuta"VEHICLE 1: "#bijela"%s\n"#zuta"VEHICLE 2: "#bijela"%s\n"#zuta"VEHICLE 3: "#bijela"%s\n"#zuta"SCORE (taxi): "#bijela"%d\n"#zuta"SCORE (trucker): "#bijela"%d\n"#zuta"SCORE (sailor): "#bijela"%d",string, kuca,veh1,veh2,veh3, PlayerInfo[id][Bodovi_][0], PlayerInfo[id][Bodovi_][1], PlayerInfo[id][Bodovi_][2]);
		}
		CreateDialog(id, DIALOG_ADMIN_CHECK, DIALOG_STYLE_MSGBOX, ""#error"Stats", string, "Ok", "", ""#error"Stats", string, "Ok", "");
    }
	return (true);
}

YCMD:sendmoney(playerid, params[], help)
{
	new id = (0), iznos = (0), string[128] = "\0";
	if(PlayerLogin{playerid} == false) return logout(playerid);
	else if(sscanf(params, "ud", id, iznos)) return SCM(playerid, ""#bijela"KORISTI: /sendmoney [playerid] [iznos]", ""#bijela"USAGE: /sendmoney [playerid] [ammount]");
	else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
	else if(GetPlayerScore(id) < 20) return SCM(playerid, ""#siva"Igrac mora biti minimalno level 20!", ""#siva"That player is lower then level 20. You can't send him a money.");
	else if(GetPlayerScore(playerid) < 20) return SCM(playerid, ""#siva"Moras biti level 20+ da mozes slati novac.", ""#siva"You can't use this command. Just players with level 20+ can use this command.");
	else if(iznos > GetPlayerMoneyEx(playerid)) return SCM(playerid, ""#siva"Nemas toliko novaca!", ""#siva"You don't have that much money.");
	else if(iznos > 10000) return SCM(playerid, ""#siva"Najvise mozes poslati $10,000 odjednom.", ""#siva"You can send only $10,000 once.");
	else if(iznos < 1) return SCM(playerid, ""#siva"* Najmanje $1 moze poslati!", ""#siva"* You can't send $0 or less!");
	else if(id == playerid) return SCM(playerid, ""#siva"Ne mozes sebi slati novac!", ""#siva"You can't send money to yourself!");
	else
	{
	    GivePlayerMoneyEx(playerid, -iznos);
	    GivePlayerMoneyEx(id, iznos);

        if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#bijela"* %s ti je poslao $%d.",GetName(playerid), iznos);
			SCM(id, string, "");
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#bijela"* %s has send you $%d.",GetName(playerid), iznos);
            SCM(id, "", string);
		}

		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
            format(string, (sizeof string), ""#bijela"* Poslao si %s $%d.",GetName(id), iznos);
            SCM(playerid, string, "");
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#bijela"* You just send $%d to %s.",iznos,GetName(id));
            SCM(playerid, "", string);
		}
		UpdatePlayer(playerid);
		UpdatePlayer(id);
		
		new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je poslao %s -> $%d (%d.%d.%d)",GetName(playerid),GetName(id),iznos,dan_, mjesec_, godina_);
		foreach(Player, i)
		{
			if(sendMoneyLog{i} == true)
			{
				SCM(i, string, string);
			}
		}
		SlanjeNovcaLog(string);
	}
	return (true);
}

YCMD:sellcar(playerid, params[], help)
{
	new string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Moras biti u svom vozilu.", ""#siva"You must be in your vehicle.");
    for(new i=0;i<3;++i)
    {
       if(PlayerInfo[playerid][Kljuc_Vozilo][i] == GetPlayerVehicleID(playerid))
       {
           if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		   {
			   format(string, (sizeof string), ""#error"[ >> ]: "#bijela"Prodao si vozilo za $%d.",CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Cijena]/2);
			   SCM(playerid, string, "");
		   }
		   else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		   {
               format(string, (sizeof string), ""#error"[ >> ]: "#bijela"You sell your vehicle $%d.",CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Cijena]/2);
               SCM(playerid, "", string);
		   }
		   GivePlayerMoneyEx(playerid, CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Cijena] / 2);
		   CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][0] = (0.0000);
		   CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][1] = (0.0000);
		   CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][2] = (0.0000);
		   CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][3] = (0.0000);
		   vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][0] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][1] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][2] = (0);
	       vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][3] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][4] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][5] = (0);
		   vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][6] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][7] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][8] = (0);
		   vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][9] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][10] = (0); vMods[PlayerInfo[playerid][Kljuc_Vozilo][i]][11] = (0);
		   format(CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]], MAX_PLAYER_NAME, "-/-");
		   PlayerInfo[playerid][Kljuc_Vozilo][i] = (INVALID_CAR_ID);
		   UpdateVehicle(GetPlayerVehicleID(playerid));
		   DestroyVehicle(GetPlayerVehicleID(playerid));
		   UpdatePlayer(playerid);
		   break;
       }
       if(i == 2 && PlayerInfo[playerid][Kljuc_Vozilo][i] != GetPlayerVehicleID(playerid)) return SCM(playerid, ""#siva"Ovo nije tvoje vozilo!", ""#siva"This is not your vehicle.");
    }
	return (true);
}

YCMD:parkcar(playerid, params[], help)
{
	new vehicleid = GetPlayerVehicleID(playerid), Float:Pos[4];
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Moras biti u svom vozilu.", ""#siva"You must be in your vehicle.");
	else if(zabranaParkiranja(playerid) == true) return SCM(playerid, ""#siva"* Ne smijes parkirati blizu zracnih luka!", ""#siva"* You can not park your vehicle near airports!");
	else if(CarInfo[vehicleid][v_Airline] != -1)
	{
		if(PlayerInfo[playerid][Vlasnik_Kompanije] == CarInfo[vehicleid][v_Airline])
		{
            GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
            GetVehicleZAngle(vehicleid, Pos[3]);
            CarInfo[vehicleid][v_Pos][0] = (Pos[0]); CarInfo[vehicleid][v_Pos][1] = (Pos[1]);
            CarInfo[vehicleid][v_Pos][2] = (Pos[2]); CarInfo[vehicleid][v_Pos][3] = (Pos[3]);
            GameText(playerid, "~w~Vozilo ~g~parkirano!", "~w~vehicle ~g~parked!", 2500, 3);
            UpdateVehicle(vehicleid);
            SFP_SetVehicleToRespawn(vehicleid);
            return (true);
		}
		else if(PlayerInfo[playerid][Vlasnik_Kompanije] != CarInfo[vehicleid][v_Airline]) return SCM(playerid, ""#siva"* Samo vlasnik kompanije smije koristiti ovu komandu za ovo vozilo!", ""#siva"* Just owner of airline can use this command on this vehicle!");
	}
	else if(CarInfo[vehicleid][v_Airline] == -1)
	{
	  for(new i=0;i<3;++i)
	  {
		if(PlayerInfo[playerid][Kljuc_Vozilo][i] == vehicleid)
		{
            GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
            GetVehicleZAngle(vehicleid, Pos[3]);
            CarInfo[vehicleid][v_Pos][0] = (Pos[0]); CarInfo[vehicleid][v_Pos][1] = (Pos[1]);
            CarInfo[vehicleid][v_Pos][2] = (Pos[2]); CarInfo[vehicleid][v_Pos][3] = (Pos[3]);
            GameText(playerid, "~w~Vozilo ~g~parkirano!", "~w~vehicle ~g~parked!", 2500, 3);
            UpdateVehicle(vehicleid);
            SFP_SetVehicleToRespawn(vehicleid);
            break;
 		}
		if(i == 2 && PlayerInfo[playerid][Kljuc_Vozilo][i] != vehicleid) return SCM(playerid, ""#siva"Ovo nije tvoje vozilo!", ""#siva"This is not your vehicle.");
      }
    }
	return (true);
}

YCMD:locatecar(playerid,params[], help)
{
   new slot = (0);
   if(PlayerLogin{playerid} == false) return logout(playerid);
   else if(posao{playerid} == true) return SCM(playerid, ""#siva"Trenutno radis, koristi /cancel pa onda /locatecar", ""#siva"You working right now, use /cancel and then use /locatecar");
   else if(sscanf(params, "d", slot)) return SCM(playerid, ""#bijela"KORISTI: /locatecar [slot(1-3)]", ""#bijela"USAGE: /locatecar [slot(1-3)]");
   else if(slot < 1 || slot > 3) return SCM(playerid, ""#siva"Slot mora biti 1 - 2 ili 3!", ""#siva"Slot must be 1 - 2 or 3!");
   else
   {
	   if(PlayerInfo[playerid][Kljuc_Vozilo][slot] == INVALID_CAR_ID) return SCM(playerid, ""#siva"Nemas vozilo u tom slotu.", ""#siva"You don't have vehicle in that slot.");
	   else
	   {
		   SetPlayerCheckpoint(playerid, CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][slot]][v_Pos][0], CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][slot]][v_Pos][1], CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][slot]][v_Pos][2], 5.0);
		   SCM(playerid, ""#bijela"Vozilo je oznaceno na mapi.", ""#bijela"Vehicle is marked on your radar.");
	   }
   }
   return (true);
}

YCMD:lockcar(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
	   for(new i=0;i<3;++i)
	   {
		   if(IsPlayerInRangeOfPoint(playerid, 4.0, CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][0], CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][1], CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][2]) && CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Locked] == 0)
		   {
               CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Locked] = (1);
			   UpdateVehicle(PlayerInfo[playerid][Kljuc_Vozilo][i]);
			   GameText(playerid, "~r~Zakljucan!", "~r~Locked!", 2500, 3);
			   break;
		   }
		   else return SCM(playerid, ""#siva"* Nisi blizu svog vozila ili je vozilo vec zakljucano!", ""#siva"* You need to be near your vehicle or vehicle is already locked!");
	   }
	}
	return (true);
}

YCMD:unlockcar(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else 
    {
	   for(new i=0;i<3;++i)
	   {
		   if(IsPlayerInRangeOfPoint(playerid, 4.0, CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][0], CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][1], CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Pos][2]) && CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Locked] == 1)
		   {
               CarInfo[PlayerInfo[playerid][Kljuc_Vozilo][i]][v_Locked] = (0);
			   UpdateVehicle(PlayerInfo[playerid][Kljuc_Vozilo][i]);
			   GameText(playerid, "~g~Otkljucan!", "~g~Unlocked!", 2500, 3);
			   break;
		   }
		   else return SCM(playerid, ""#siva"* Nisi blizu svog vozila ili je vozilo vec otkljucano!", ""#siva"* You need to be near your vehicle or vehicle is already unlocked!");
	   }
	}
	return (true);
}

YCMD:eject(playerid, params[], help)
{
	new id;
	if(PlayerLogin{playerid} == false) return logout(playerid);
	else if(sscanf(params, "u", id)) return SCM(playerid, ""#bijela"KORISTI: /eject [playerid]", ""#bijela"USAGE: /eject [playerid]");
	else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
	else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Nisi u vozilu.", ""#siva"You are not in vehicle.");
	else if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SCM(playerid, ""#siva"Samo vozaci mogu izbacivati ljude iz vozila.", ""#siva"Just drivers can eject other players from vehicle.");
	else if(GetPlayerVehicleID(id) != GetPlayerVehicleID(playerid))return SCM(playerid, ""#siva"Taj igrac nije u tvom vozilu.", ""#siva"That player is not in a same vehicle as you.");
	else if(GetPlayerState(id) != PLAYER_STATE_PASSENGER) return SCM(playerid, ""#siva"Ne mozes izbaciti tog igraca iz vozila.", ""#siva"You can't eject that player from vehicle.");
	else
	{
		RemovePlayerFromVehicle(id);
		SCM(playerid, ""#bijela"* Izbacio si igraca iz vozila.", ""#bijela"You eject player from vehicle.");
	}
	return (true);
}

YCMD:setadmin(playerid, params[], help)
{
	new id, level, string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(PlayerInfo[playerid][Admin] < 8 && !IsPlayerAdmin(playerid)) return adminError(playerid, 8);
    else if(sscanf(params, "ud",id, level)) return SCM(playerid, ""#bijela"KORISTI: /setadmin [playerid] [level(0-8)]", ""#bijela"USAGE: /setadmin [playerid] [level(0-10)]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Pogresan playerid.", ""#siva"Invalid playerid.");
    else if(level < 0 || level > 8) return SCM(playerid, ""#siva"Level mora biti od 0 do 8.", ""#siva"Wrong level input.");
    else
    {
		if(PlayerInfo[id][Admin] < level)
		{
			GameText(id, "~g~Promoviran!", "~g~Promoted!",3000, 3);
		}
		else if(PlayerInfo[id][Admin] > level)
		{
            GameText(id, "~r~Skinut ti je admin level!", "~r~Demoded!",3000, 3);
		}
		
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
			format(string, (sizeof string), ""#zuta"[ADMIN]: "#ljubicasta"Administrator %s ti je postavio admin level %d.",GetName(playerid), level);
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#zuta"[ADMIN]: "#ljubicasta"Administrator %s set your admin level to %d.",GetName(playerid), level);
		}
		SCM(id, string, string);
		
		if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		{
            format(string, (sizeof string), ""#zuta"[ADMIN]: "#ljubicasta"Postavio si %s admin level %d.",GetName(id), level);
		}
		else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#zuta"[ADMIN]: "#ljubicasta"You set %s admin level to %d.",GetName(id), level);
		}
		SCM(playerid, string, string);
		PlayerInfo[id][Admin] = (level);
		UpdatePlayer(id);
		
		new dan_, mjesec_, godina_;
        getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je dao %s admin level %d (%d.%d.%d)",GetName(playerid),GetName(id), level, dan_, mjesec_, godina_);
        foreach(Player, i)
		{
			if(adminLog{i} == true)
			{
			   SCM(i, string, string);
			}
		}
		AdminLog(string);
    }
	return (true);
}

stock adminError(playerid, level)
{
	new string[100];
    if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
    {
       format(string, (sizeof string), ""#error"[SERVER]: "#bijela"Samo administrator level %d smije koristiti ovu komandu.", level);
    }
    else if(IsPlayerLanguage(playerid,JEZIK_ENGLISH))
    {
       format(string, (sizeof string), ""#error"[SERVER]: "#bijela"Just administrator with level %d can use this command.", level);
    }
	return SCM(playerid, string, string);
}

stock bool:IsPlayerNearVehicle(playerid, Float:radius, vehicleid)
{
	new Float:Pos[3];
	GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
	if(IsPlayerInRangeOfPoint(playerid, radius, Pos[0], Pos[1], Pos[2]))
	{
		return (true);
	}
	return (false);
}

YCMD:at400s(playerid, params[], help)
{
   if(PlayerLogin{playerid} == false) return logout(playerid);
   else if(IsPlayerInAnyVehicle(playerid)) return (true);
   else if(Team{playerid} >= 4) return GameText(playerid, "~r~Samo piloti!", "~r~Just pilots!", 1000, 3);
   else if(GetPlayerScore(playerid) < 400) return GameText(playerid, "~r~Samo piloti ~n~sa 400+ bodova!", "~r~Just pilots ~n~with 400+ scores!", 2500, 3);
   else
   {
	  for(new v=0;v<MAX_VEHICLES;v++)
	  {
          if(IsPlayerNearVehicle(playerid, 25.0, v) && GetVehicleModel(v) == 577)
	      {
			 if(!IsVehicleInUse(v))
			 {
	            SFP_PutPlayerInVehicle(playerid, v, 0);
	            SCM(playerid, ""#narancasta">> "#bijela"Sa ovim avionom nece biti lako stici do cilja!", ""#narancasta">> With this plane will not be easy to reach the goal!");
			 }
          }
	  }
   }
   return (true);
}

YCMD:account(playerid, params[], help)
{
	new
	   menu[20], unos[64], string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(sscanf(params, "s[30]s[64]", menu, unos)) return SCM(playerid, ""#bijela"KORISTI: /account [OPCIJA] [TEKST]", ""#bijela"USAGE: /account [OPTION] [TEXT]"), SCM(playerid, ""#bijela"OPCIJA: password housespawn", ""#bijela"OPTION: password housespawn");
    else if(strcmp(menu, "password", false) == 0)
    {
	   if(strlen(unos) <= 3 || strlen(unos) > 15) return SCM(playerid, ""#siva"Unos mora biti veci od 3 i manji od 15.", ""#siva"Your password must be longer then 3 chars, and lower then 15 chars.");
       PlayerInfo[playerid][Lozinka] = (udb_hash(unos));
	   if(IsPlayerLanguage(playerid, JEZIK_BALKAN)) { format(string, (sizeof string), ""#zuta"[INFO]: "#bijela"Nova lozinka: %s", unos); }
	   else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH)) { format(string, (sizeof string), ""#zuta"[INFO]: "#bijela"New password: %s", unos); }
	   SCM(playerid, string, string);
    }
    else if(strcmp(menu, "housespawn", false) == 0)
    {
	   if(PlayerInfo[playerid][Kljuc_Kuca] == INVALID_HOUSE_ID) return SCM(playerid, ""#siva"* Nemas kucu!", ""#siva"* You don't have a house!");
	   else if(unos[0] == '0' && unos[1] == '\0')
	   {
		   if(PlayerInfo[playerid][HouseSpawn] == 0) return SCM(playerid, ""#siva"Vec si iskljucio spawnanje u kuci!", ""#siva"You already turn off spawning in a house!");
		   else
		   {
			   PlayerInfo[playerid][HouseSpawn] = (0);
			   UpdatePlayer(playerid);
			   SCM(playerid, ""#bijela"* Od sada ces odabirati spawn!", ""#bijela"* From now you will manualy choose spawn place!");
		   }
	   }
	   else if(unos[0] == '1' && unos[1] == '\0')
	   {
		   if(PlayerInfo[playerid][HouseSpawn] == 1) return SCM(playerid, ""#siva"Vec si ukljucio spawnanje u kuci!", ""#siva"You already turn on spawning in a house!");
		   else
		   {
			   PlayerInfo[playerid][HouseSpawn] = (1);
			   UpdatePlayer(playerid);
			   SCM(playerid, ""#bijela"* Od sada ces se spawnati u svojoj kuci!", ""#bijela"* From now your spawn place is your house!");
		   }
	   }
	   else { SCM(playerid, ""#siva"Za ovu opciju mozes odabrati samo 0 ili 1", ""#siva"For this option you can choose just 0 or 1"); }
    }
	return (true);
}

YCMD:kill(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(antiTAB{playerid} == true) return SCM(playerid, ""#siva"* Ne mozes sada koristiti /kill", ""#siva"* You can't use /kill right now!");
    else
    {
	   SFP_SetPlayerHealth(playerid, 0.000);
    }
	return (true);
}

YCMD:rules(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
       SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
       SCM(playerid, ""#zuta"- Zabranjeno je reklamiranje drugih servera.", ""#zuta"- Don't advertising other servers.");
       SCM(playerid, ""#zuta"- Deathmatch je strogo zabranjen.", ""#zuta"- Deathmatch is not allowed.");
       SCM(playerid, ""#zuta"- Zabranjeno je iskoristavanje bugova.", ""#zuta"- Don't exploiting server bugs.");
       SCM(playerid, ""#zuta"- Zabranjeno je koristenje modova ili cheatova.", ""#zuta"- Don't use mods or cheat.");
       SCM(playerid, ""#zuta"- Ukoliko vidis cheatera prijavi ga na /report [id].", ""#zuta"- If you seen a cheater report him /report [id].");
       SCM(playerid, ""#bijela"[============================================================]", ""#bijela"[============================================================]");
	}
	return (true);
}

YCMD:admins(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
		new
		   string[256], count = (0);
		foreach(Player, i)
		{
		   if(PlayerInfo[i][Admin] >= 1 && PlayerInfo[i][Admin] <= 8)
		   {
			   if(nevidljiv{i} == false)
			   {
			      count++;
			      format(string, 256, "%s"#zuta"%s - Level "#error"%i\n",string,GetName(i),PlayerInfo[i][Admin]);
	           }
		   }
		}
		if(count == 0)
		{
			SCM(playerid, ""#siva"Trenutno nema online administratora.", ""#siva"0 online administrators.");
		}
		else
		{
            CreateDialog(playerid, DIALOG_ADMINS, DIALOG_STYLE_MSGBOX, ""#error"Online administratori", string, "Zatvori", "", ""#error"Online administrators", string, "Close", "");
		}
    }
	return (true);
}

YCMD:vips(playerid, params[], help)
{
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else
    {
		new
		   string[256], count = (0);
		foreach(Player, i)
		{
		   if(PlayerInfo[i][Vip] >= 1 && PlayerInfo[i][Vip] <= 3)
		   {
			   if(nevidljiv{i} == false)
			   {
			      count++;
			      format(string, 256, "%s"#zuta"%s - Level "#error"%i\n",string,GetName(i),PlayerInfo[i][Vip]);
	           }
		   }
		}
		if(count == 0)
		{
			SCM(playerid, ""#siva"Niti jedan vip igrac nije online.", ""#siva"There is no vip player online in this moment.");
		}
		else
		{
            CreateDialog(playerid, DIALOG_ADMINS, DIALOG_STYLE_MSGBOX, ""#error"VIP IGRACI", string, "Zatvori", "", ""#error"VIP PLAYERS", string, "Close", "");
		}
    }
	return (true);
}

YCMD:report(playerid, params[], help)
{
	new
	   id,
	   string[128] = "\0", string2[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(sscanf(params, "us[64]", id, params)) return SCM(playerid, ""#bijela"KORISTI: /report [id] [razlog]", ""#bijela"USAGE: /report [id] [reason]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Nevaljan id.", ""#siva"Wrong id.");
    else if(id == playerid) return SCM(playerid, ""#siva"Ne mozes prijaviti samoga sebe.", ""#siva"You can't report yourself.");
    else
    {
		format(string, (sizeof string), ""#error"[PRIJAVA]: "#bijela"%s(%d) je prijavio %s(%d) | RAZLOG: %s.",GetName(playerid),playerid, GetName(id),id,params);
		format(string2, (sizeof string2), ""#error"[REPORT]: "#bijela"%s(%d) has report %s(%d) | REASON: %s.",GetName(playerid),playerid, GetName(id),id,params);
		SAM(string, string2, 1);
		SCM(playerid, ""#bijela"Tvoj report je uspjesno poslan.", ""#bijela"Thank you for reporting.");
		
		new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s je prijavio igraca %s RAZLOG: %s (%d.%d.%d)",GetName(playerid),GetName(id), params, dan_, mjesec_, godina_);
	    foreach(Player, i)
	    {
			if(prijaveLog{i} == true)
			{
				SCM(i, string, string);
			}
	    }
	    ReportLog(string);
    }
	return (true);
}

YCMD:pm(playerid, params[], help)
{
	new
	   id, string[128] = "\0";
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(sscanf(params,"us[128]",id,params)) return SCM(playerid, ""#bijela"KORISTI: /pm [id] [poruka]", ""#bijela"USAGE: /pm [id] [message]");
    else if(id == INVALID_PLAYER_ID) return SCM(playerid, ""#siva"Nevaljan id.", ""#siva"Wrong id.");
    else if(id == playerid) return SCM(playerid, ""#siva"Ne mozes sam sebi poslati poruku.", ""#siva"You can't send a message to yourself.");
    else if(block_pm{id} == true) return SCM(playerid, ""#siva"Administrator je zauzet i trenutno ne prima privatne poruke.", ""#siva"That administrator is too busy and he don't accept private messages at this moment.");
    else
    {
        if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
        {
            format(string, (sizeof string), ""#narancasta"Poslano: "#bijela"%s", params);
            SCM(playerid, string, string);
        }
        else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
        {
            format(string, (sizeof string), ""#narancasta"Message has successfully sent: "#bijela"%s", params);
            SCM(playerid, string, string);
        }
        
		if(IsPlayerLanguage(id, JEZIK_BALKAN))
		{
            format(string, (sizeof string), ""#zuta">> %s(%d) ti je poslao poruku.",GetName(playerid),playerid);
		    SCM(id, string, string);

		    format(string, (sizeof string), ""#zuta"PORUKA: %s",params);
		    SCM(id, string, string);
		}
		else if(IsPlayerLanguage(id, JEZIK_ENGLISH))
		{
            format(string, (sizeof string), ""#zuta">> %s(%d) sent you a private message.",GetName(playerid),playerid);
		    SCM(id, string, string);

		    format(string, (sizeof string), ""#zuta"MESSAGE: %s",params);
		    SCM(id, string, string);
		}
		
		new dan_, mjesec_, godina_;
	    getdate(godina_, mjesec_, dan_);
	    format(string, (sizeof string), "%s -> %s: %s (%d.%d.%d)",GetName(playerid),GetName(id), params, dan_, mjesec_, godina_);
		foreach(Player, i)
		{
			if(pmLog{i} == true)
			{
			   SCM(i, string, string);
            }
		}
		PorukeLog(string);
    }
	return (true);
}

YCMD:refuel(playerid, params[], help)
{
	new
	   tank = (0), cijena = (0), vehicleid = GetPlayerVehicleID(playerid);
    if(PlayerLogin{playerid} == false) return logout(playerid);
    else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Nisi u vozilu.", ""#siva"You must be in vehicle.");
    else if(Gorivo[vehicleid] >= 100) return SCM(playerid, ""#siva"Tvoj tank goriva je pun.", ""#siva"Your gas tank is already full.");
    else
    {
        if(VojniAvion(vehicleid) || MedicinskiAvion(vehicleid) || CivilniAvion(vehicleid))
        {
           if(!IsPlayerNearAirportPetrol(playerid)) return SCM(playerid, ""#siva"Samo na glavnim zracnim lukama mozes koristiti ovu komandu.", ""#siva"Just on few main airports you can use this command.");
		   tank = MAX_FUEL-Gorivo[GetPlayerVehicleID(playerid)];
		   cijena = (tank*30);
		   Gorivo[GetPlayerVehicleID(playerid)] += (tank);
		   GivePlayerMoneyEx(playerid, -cijena);
		   PlayerInfo[playerid][Tankirao][0] ++;
		   PlayerInfo[playerid][Tankirao][1] += (cijena);
		   SCM(playerid, ""#bijela"* Napunio si tank do kraja.", ""#bijela"* You fill your gas tank.");
	    }
	    else if(TaxiAuto(vehicleid) || Truck(vehicleid) || IsACosVeh(vehicleid))
        {
		    if(!IsPlayerNearPetrol(playerid)) return SCM(playerid, ""#siva"Moras biti na benzinskoj.", ""#siva"You must be near petrol station.");
		    tank = MAX_FUEL-Gorivo[GetPlayerVehicleID(playerid)];
		    cijena = (tank*20);
		    Gorivo[GetPlayerVehicleID(playerid)] += (tank);
		    GivePlayerMoneyEx(playerid, -cijena);
		    PlayerInfo[playerid][Tankirao][0] ++;
		    PlayerInfo[playerid][Tankirao][1] += (cijena);
		    SCM(playerid, ""#bijela"* Napunio si tank do kraja.", ""#bijela"* You fill your gas tank.");
        }
        else if(IsABoat(vehicleid))
        {
            if(!IsPlayerNearBoatPetrol(playerid)) return SCM(playerid, ""#siva"Moras biti na benzinskoj.", ""#siva"You must be near petrol station.");
		    tank = MAX_FUEL-Gorivo[GetPlayerVehicleID(playerid)];
		    cijena = (tank*25);
		    Gorivo[GetPlayerVehicleID(playerid)] += (tank);
		    GivePlayerMoneyEx(playerid, -cijena);
		    PlayerInfo[playerid][Tankirao][0] ++;
		    PlayerInfo[playerid][Tankirao][1] += (cijena);
		    SCM(playerid, ""#bijela"* Napunio si tank do kraja.", ""#bijela"* You fill your gas tank.");
        
        }
    }
	return (true);
}

YCMD:repair(playerid, params[], help)
{
   new
	  Float:helti, iznos = (0), string[128] = "\0", string2[128] = "\0", vehicleid = GetPlayerVehicleID(playerid);
   GetVehicleHealth(GetPlayerVehicleID(playerid), helti);
   if(PlayerLogin{playerid} == false) return logout(playerid);
   else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, ""#siva"Nisi u vozilu.", ""#siva"You must be in vehicle.");
   else if(helti >= 1000) return SCM(playerid, ""#siva"Tvoje vozilo ne treba popravak.", ""#siva"Your vehicle don't need repair.");
   else
   {
      if(VojniAvion(vehicleid) || MedicinskiAvion(vehicleid) || CivilniAvion(vehicleid))
      {
         if(!IsPlayerNearAirportPetrol(playerid)) return SCM(playerid, ""#siva"Samo na glavnim zracnim lukama mozes koristiti ovu komandu.", ""#siva"Just on few main airports you can use this command.");
	     iznos = (1000 - floatround(helti));
	     GivePlayerMoneyEx(playerid, -iznos*3);
	     RepairVehicle(GetPlayerVehicleID(playerid));
	     SetVehicleHealth(GetPlayerVehicleID(playerid), 1000);
	     PlayerInfo[playerid][Popravio][0] ++;
  	     PlayerInfo[playerid][Popravio][1] += (iznos*3);
	     format(string, (sizeof string), ""#bijela"* Tvoje vozilo je popravljeno za "#zelena"$%d"#bijela".",(iznos*3));
	     format(string2, (sizeof string2), ""#bijela"* Your vehicle is repaired for "#zelena"$%d"#bijela".",(iznos*3));
	     SCM(playerid, string, string2);
      }
      else if(TaxiAuto(vehicleid) || Truck(vehicleid) || IsACosVeh(vehicleid))
      {
		 if(!IsPlayerNearPetrol(playerid)) return SCM(playerid, ""#siva"Moras biti na benzinskoj.", ""#siva"You must be near petrol station.");
		 iznos = (1000 - floatround(helti));
	     GivePlayerMoneyEx(playerid, -iznos*2);
	     RepairVehicle(GetPlayerVehicleID(playerid));
	     SetVehicleHealth(GetPlayerVehicleID(playerid), 1000);
	     PlayerInfo[playerid][Popravio][0] ++;
  	     PlayerInfo[playerid][Popravio][1] += (iznos*2);
	     format(string, (sizeof string), ""#bijela"* Tvoje vozilo je popravljeno za "#zelena"$%d"#bijela".",(iznos*3));
	     format(string2, (sizeof string2), ""#bijela"* Your vehicle is repaired for "#zelena"$%d"#bijela".",(iznos*3));
	     SCM(playerid, string, string2);
      }
      else if(IsABoat(vehicleid))
      {
         if(!IsPlayerNearBoatPetrol(playerid)) return SCM(playerid, ""#siva"Moras biti na benzinskoj.", ""#siva"You must be near petrol station.");
		 iznos = (1000 - floatround(helti));
	     GivePlayerMoneyEx(playerid, -iznos*4);
	     RepairVehicle(GetPlayerVehicleID(playerid));
	     SetVehicleHealth(GetPlayerVehicleID(playerid), 1000);
	     PlayerInfo[playerid][Popravio][0] ++;
  	     PlayerInfo[playerid][Popravio][1] += (iznos*4);
	     format(string, (sizeof string), ""#bijela"* Tvoje vozilo je popravljeno za "#zelena"$%d"#bijela".",(iznos*3));
	     format(string2, (sizeof string2), ""#bijela"* Your vehicle is repaired for "#zelena"$%d"#bijela".",(iznos*3));
	     SCM(playerid, string, string2);
      }
   }
   return (true);
}

stock SAM(balkan[], english[], level)
{
	foreach(Player, i)
	{
	   if(PlayerInfo[i][Admin] >= level)
	   {
		  SCM(i, balkan, english);
	   }
	}
	return (true);
}

stock logout(playerid) return SCM(playerid, ""#error"[SERVER]: "#bijela"Moras biti ulogiran kako bi koristio ovu komandu.", ""#error"[SERVER]: "#bijela"You must be signed in to use this command.");

public OnGameModeExit()
{
	KillTimer(LOCAL_TIMER);
	KillTimer(LOCAL_TIMER_2);
    KillTimer(cTime);
 	for(new i=0; i<MAX_PLAYERS; i++)
	{
        if(IsPlayerConnected(i))
        {
    	   if(snowOn{i})
           {
			 for(new j = 0; j < MAX_SNOW_OBJECTS; j++) DestroyDynamicObject(snowObject[i][j]);
             KillTimer(updateTimer{i});
           }
        }
 	}
 	mysql_close(mySQL);
	return (true);
}

stock pickCameraMove(playerid)
{
    ERROR:new slika = random(4);
    switch(slika)
    {
	   case (0):
	   {
           InterpolateCameraPos(playerid, 2004.054687, -2267.407958, 61.696010, 1922.426513, -2685.541015, 103.609794, 10000, 1);
           InterpolateCameraLookAt(playerid, 2001.547363, -2269.838867, 59.745483, 1923.556518, -2682.248046, 101.640197, 10000, 1);
	   }
	   case (1):
	   {
           InterpolateCameraPos(playerid, 2536.087646, -197.303436, 87.703689, 2271.487060, -189.967681, 67.256942, 10000, 1);
           InterpolateCameraLookAt(playerid, 2532.521240, -197.087112, 85.905204, 2274.742431, -189.199310, 65.063278, 10000, 1);
	   }
	   case (2):
	   {
           InterpolateCameraPos(playerid, 58.943893, 142.741241, 27.636207, 48.683788, -208.859222, 64.043457, 10000, 1);
           InterpolateCameraLookAt(playerid, 57.996883, 139.076019, 26.344175, 47.018264, -206.229202, 61.531688, 10000, 1);
	   }
	   case (3):
	   {
           InterpolateCameraPos(playerid, 929.899536, 2351.414794, 74.503593, 842.538757, 2051.168945, 42.581970, 10000, 1);
           InterpolateCameraLookAt(playerid, 927.417419, 2349.054931, 72.437088, 843.675964, 2054.523193, 40.722972, 10000, 1);
	   }
	   default: { goto ERROR; }
    }
    return (true);
}

public OnPlayerConnect(playerid)
{
    novost(GetName(playerid), "se prikljucio na server.");
	new string[85], string2[85], NICK____[MAX_PLAYER_NAME];
	txtTime{playerid} = (TEXT_VRIJEME);
    
	SetPlayerLanguage(playerid, true);
	new duzina_imena = strlen(GetName(playerid));
	if(duzina_imena > 16)
	{
		SCM(playerid, ""#bijela"Your nick must have more then 3 and lower then 16 characters", ""#bijela"Your nick must have more then 3 and lower then 16 characters");
		Kick(playerid);
	}
	GetPlayerName(playerid, NICK____, 1);
	if(strcmp(NICK____, "[", false) == 0)
	{
        SCM(playerid, ""#bijela"You can't have "#error"[ "#bijela"on first place in your nickname!", ""#bijela"You can't have "#error"[ "#bijela"on first place in your nickname!");
		Kick(playerid);
	}
	
	new avio_id = IsPlayerInAirline(playerid, GetName(playerid));
	if(avio_id != -1)
	{
		new duzina = strlen(AvioKompanija[avio_id][av_Inicijali]);
		if(duzina > 3)
		{
		   print("PROLAZ!");
		   format(NICK____, MAX_PLAYER_NAME, "%s%s",AvioKompanija[avio_id][av_Inicijali], GetName(playerid));
		   switch(SetPlayerName(playerid, NICK____))
           {
               case (-1): // NETKO IMA TO IME ONLINE
			   {
				  printf("Igrac %s ne moze dobiti inicijale kompanije jer postoji netko online sa istim nickom!", GetName(playerid));
               }
               case (0): // VEC IMA TO IME
               {
                   printf("Igrac %s ne moze dobiti inicijale kompanije jer vec ima taj isti nick!", GetName(playerid));
               }
               case (1): // USPJESNO
               {
				   printf("Dodani inicijali kompanije igracu %s!", GetName(playerid));
               }
           }
        }
	}
	
	if(strcmp(l_connect, GetName(playerid), false) == 0)
	{

    }
    else
    {
       format(string, (sizeof string), ""#narancasta"[%d] "#bijela"%s "#narancasta"has joined the server. Welcome!",playerid,GetName(playerid));
       format(string2, (sizeof string2), ""#narancasta"[%d] "#bijela"%s "#narancasta"se prikljucio na server. Dobrodosao!",playerid,GetName(playerid));
       ScmToAll(string2, string);
    }
    
    // Biranje jezika
    langOdabir[playerid][0] = CreatePlayerTextDraw(playerid,245.000000, 139.000000, "ENGLISH");
    PlayerTextDrawBackgroundColor(playerid,langOdabir[playerid][0], 65535);
    PlayerTextDrawFont(playerid,langOdabir[playerid][0], 2);
    PlayerTextDrawLetterSize(playerid,langOdabir[playerid][0], 0.820000, 3.099999);
    PlayerTextDrawColor(playerid,langOdabir[playerid][0], -1);
    PlayerTextDrawSetOutline(playerid,langOdabir[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid,langOdabir[playerid][0], 1);
    PlayerTextDrawUseBox(playerid,langOdabir[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid,langOdabir[playerid][0], -16843264);
    PlayerTextDrawTextSize(playerid,langOdabir[playerid][0], 390.000000, 25.000000);
    PlayerTextDrawSetSelectable(playerid,langOdabir[playerid][0], 1);

    langOdabir[playerid][1] = CreatePlayerTextDraw(playerid,249.000000, 210.000000, "BALKAN");
    PlayerTextDrawBackgroundColor(playerid,langOdabir[playerid][1], 65535);
    PlayerTextDrawFont(playerid,langOdabir[playerid][1], 2);
    PlayerTextDrawLetterSize(playerid,langOdabir[playerid][1], 0.820000, 3.099999);
    PlayerTextDrawColor(playerid,langOdabir[playerid][1], -1);
    PlayerTextDrawSetOutline(playerid,langOdabir[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid,langOdabir[playerid][1], 1);
    PlayerTextDrawUseBox(playerid,langOdabir[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid,langOdabir[playerid][1], -16843264);
    PlayerTextDrawTextSize(playerid,langOdabir[playerid][1], 385.000000, 25.000000);
    PlayerTextDrawSetSelectable(playerid,langOdabir[playerid][1], 1);
    
    // AVION CONNECT
    con__ = CreatePlayerTextDraw(playerid, 11.000000, 343.000000, "_");
    PlayerTextDrawFont(playerid, con__, TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawUseBox(playerid, con__, 1);
    PlayerTextDrawBoxColor(playerid, con__, 0xDCDCDC00);
	PlayerTextDrawTextSize(playerid, con__, 300.000000, 150.000000);
    PlayerTextDrawSetPreviewModel(playerid, con__, 520);
    PlayerTextDrawSetPreviewRot(playerid, con__, -10.0, 0.0, 20, 1.0);
    // SFP text
    naslov__ = CreatePlayerTextDraw(playerid, 187.000000, 378.000000, "~r~S~w~ERVER ~r~F~w~OR ~r~P~w~ILOTS");
    PlayerTextDrawBackgroundColor(playerid, naslov__, 255);
    PlayerTextDrawFont(playerid, naslov__, 2);
    PlayerTextDrawLetterSize(playerid, naslov__, 0.629999, 2.300000);
    PlayerTextDrawColor(playerid, naslov__, -16776961);
    PlayerTextDrawSetOutline(playerid, naslov__, 0);
    PlayerTextDrawSetProportional(playerid, naslov__, 1);
    PlayerTextDrawSetShadow(playerid, naslov__, 1);
    // INFO SFP
    sfpInfo[playerid] = TextDrawCreate(7.000000, 428.000000, "_");
    TextDrawBackgroundColor(sfpInfo[playerid], 255);
    TextDrawFont(sfpInfo[playerid], 1);
    TextDrawLetterSize(sfpInfo[playerid], 0.310000, 1.799999);
    TextDrawColor(sfpInfo[playerid], 16777215);
    TextDrawSetOutline(sfpInfo[playerid], 1);
    TextDrawSetProportional(sfpInfo[playerid], 1);
    TextDrawSetSelectable(sfpInfo[playerid], 0);
    
    format(l_connect, MAX_PLAYER_NAME, "%s", GetName(playerid));
    FailLogin{playerid} = (0); PlayerLogin{playerid} = (false); Team{playerid} = (0); playerSmrt{playerid} = (false); prijaveLog{playerid} = (false);
    posao{playerid} = (false); TIMER_LOAD[playerid] = (0); CP[playerid] = (0); Bonus{playerid} = (0); info_box{playerid} = (0); adminLog{playerid} = (false);
    online_sec{playerid} = (0); work_vehicle[playerid] = (-1); zadnje_vozilo[playerid] = (-1); upozorenje{playerid} = (0); pmLog{playerid} = (false);
    mute{playerid} = (false); freeze{playerid} = (false); SPEC_POS[playerid][0] = (0.0); SPEC_POS[playerid][1] = (0.0); SPEC_POS[playerid][2] = (0.0);
    SPEC_VW[playerid] = (0); SPEC_INT{playerid} = (0); IsSpecing{playerid} = (false); IsBeingSpeced{playerid} = (false); spectatorid[playerid] = (INVALID_PLAYER_ID);
    block_pm{playerid} = (false); nevidljiv{playerid} = (false); ruta_min{playerid} = (0); ruta_sec{playerid} = (0); sendMoneyLog{playerid} = (false);
    move{playerid} = (true); moveON{playerid} = (false); inhouse[playerid] = (MAX_HOUSES+1); cheatLog{playerid} = (false); RUTA_DUZINA[playerid] = (0.000);
    otkaz_slot{playerid} = (0); av_call_vlasnik[playerid] = (INVALID_PLAYER_ID); av_call_avio{playerid} = (-1); av_call_time{playerid} = (0);
    hydraFire{playerid} = (0); dm{playerid} = (0); PlayerInfo[playerid][Novac] = (0); PlayerInfo[playerid][Bodovi] = (0); antiTAB{playerid} = (false);
    Zastita__{playerid} = (1); AFK{playerid} = (0); AFK2{playerid} = (false); AutoHelti[playerid] = 1000; anti_Kicker{playerid} = (false); CanCheckAirBreak[playerid] = (false);
    CanCheckABX[playerid] = (true); NeedCheckTuningAB [playerid] = (0); load_bar[playerid] = (239.00); bonus_[playerid] = (578.00); bonus__{playerid} = (0.000);
    timerFreeze{playerid} = (0); a_b__{playerid} = (0);
	
	ResetPlayerWeapons(playerid); GangZoneShowForAll(Area, 0xFFA15C5B);
    /*StopAudioStreamForPlayer(playerid);
    PlayAudioStreamForPlayer(playerid, "http://caffetopia.com.hr/ServerForPilots/Bozicne_Pjesme.mp3");*/
    for(new i=0;i<20;++i)
    {
	   SCM(playerid, "", "");
    }
	Set_Vrijeme(vrijeme__, vrijemeTime[1], vrijemeTime[0]);
	TogglePlayerSpectating(playerid,1);
	PlayerInfo[playerid][Admin] = (0);
    
    // ...Neno... RiverSide mapa
    RemoveBuildingForPlayer(playerid, 8562, 2597.3906, 723.2188, 9.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 8784, 2597.3906, 723.2188, 9.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 3459, 2597.2813, 683.4766, 17.3203, 0.25);
    // ...Neno... LV airport kod golf terena
    RemoveBuildingForPlayer(playerid, 3544, 1220.2734, 2590.2969, 16.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 3545, 1220.2734, 2611.2734, 16.3047, 0.25);
    RemoveBuildingForPlayer(playerid, 3487, 1220.2734, 2590.2969, 16.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 3488, 1220.2734, 2611.2734, 16.3047, 0.25);
    RemoveBuildingForPlayer(playerid, 616, 1235.8828, 2620.4063, 9.1328, 0.25);
    // SLAY PLANINA
    RemoveBuildingForPlayer(playerid, 785, -955.1406, -1167.4844, 126.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -962.9922, -941.6094, 126.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -762.2109, -699.4609, 101.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -751.1563, -791.2266, 145.4141, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -875.8672, -662.4453, 106.0859, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -848.7578, -832.6406, 141.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1209.4453, -900.1406, 128.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1188.3203, -895.2891, 126.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1243.3203, -890.7734, 147.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1124.1250, -888.8594, 126.1875, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1101.0391, -871.1328, 132.5938, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1164.7891, -845.8594, 104.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1177.0000, -847.7188, 104.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1129.5469, -854.8828, 121.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -1072.3203, -914.2266, 128.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -1067.3438, -914.2266, 128.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -1062.3750, -914.2266, 128.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -1057.3984, -914.2266, 128.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -1052.4219, -914.2266, 128.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -1047.4531, -914.2266, 128.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1085.1484, -880.1406, 132.6016, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1008.1953, -898.4141, 128.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1032.8516, -882.3984, 135.0391, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -985.9063, -963.8281, 128.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -959.1797, -972.9375, 133.1563, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -962.9922, -941.6094, 126.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -934.2734, -973.9688, 128.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -875.8672, -662.4453, 106.0859, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -848.7578, -832.6406, 141.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -762.2109, -699.4609, 101.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -751.1563, -791.2266, 145.4141, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1239.6406, -1232.2734, 130.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1228.3906, -1213.2813, 130.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1273.5000, -1213.5078, 130.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1314.3984, -1195.8672, 132.4688, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -1210.3203, -1146.4219, 132.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1073.5703, -1187.2266, 128.0078, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1124.4922, -1140.8984, 128.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1081.5938, -1143.2500, 128.3359, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1081.1484, -1162.4844, 128.1719, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1156.6797, -1083.9219, 128.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1105.5078, -1083.4375, 128.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1145.2266, -1071.8984, 128.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1069.4766, -1135.6797, 128.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1022.8750, -1153.4453, 128.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -1026.1406, -1134.8438, 129.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -1032.4453, -1118.1797, 129.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -1032.5000, -1129.6016, 129.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1024.4375, -1088.5703, 128.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -1057.0000, -1091.1484, 128.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -1019.8750, -1163.4453, 129.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 691, -1010.2031, -1146.1016, 127.8438, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -1019.8750, -1152.0234, 129.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -1019.8750, -1140.3359, 129.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -1011.6406, -1101.0547, 128.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -982.1172, -1077.7422, 133.1563, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -984.1641, -1051.5078, 127.6953, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -985.7969, -1001.3906, 128.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -955.1406, -1167.4844, 126.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -963.9531, -992.7500, 133.1563, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -952.6875, -1028.9063, 133.1563, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -943.8359, -1017.9766, 128.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -925.3516, -1007.3281, 133.1563, 0.25);
	
    CreateDynamicMapIcon(-149.3726,-3191.0906,23.4154, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-17.7255,-152.6557,5.4964, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(2445.8621,-201.2445,27.5299, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-1701.4760,3322.4351,3.8859, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(277.8040,-1802.1635,4.5263, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-2046.8789,2016.2086,5.2651, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-2379.2437,2562.3687,27.7117, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-3019.9573,869.6891,15.6172, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(2470.3503,601.4619,13.8562, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-2458.3401,-2787.7900,18.4420, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(1130.5094,2599.0347,14.7700, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-3434.9736,704.3018,4.2700, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(3570.3049,-2226.0706,4.7359, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(3403.8765,-459.9859,29.7047, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-2104.7327,1687.5918,1.7000, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(781.9723,-397.8674,20.7770, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-231.7243,-2194.3228,30.0307, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(1620.0288,-655.4254,85.0813, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(868.8640,2161.8557,14.2480, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(3758.6404,1428.0361,6.5245, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(1885.9393,-4035.0437,6.1844, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(92.2591,5043.4854,6.4898, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-1526.7810,2321.3699,66.8496, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(-1145.7672,-964.7901,132.7859, 57, -1, -1, -1, -1, 500);
    CreateDynamicMapIcon(2775.3394,2702.1196,13.2813, 57, -1, -1, -1, -1, 500);
    
    // BAYSIDE AIRPORT
    RemoveBuildingForPlayer(playerid, 16514, -512.8203, 2919.7109, 54.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 16607, -733.1953, 2751.1953, 46.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 16107, -733.1953, 2751.1953, 46.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 652, -749.2656, 2755.5000, 46.0078, 0.25);
    RemoveBuildingForPlayer(playerid, 652, -749.1875, 2764.6953, 45.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 16159, -512.8203, 2919.7109, 54.9844, 0.25);
    // MALI LS AIRPORT
    RemoveBuildingForPlayer(playerid, 1461, 161.8125, -1813.6328, 3.5547, 0.25);
    RemoveBuildingForPlayer(playerid, 1231, 154.5469, -1799.6406, 5.4688, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 159.3359, -1794.5859, 3.1719, 0.25);
    
    for(new i=0;i<sizeof(ZabranjenaImena);i++)
	{
         if(strfind(GetName(playerid),ZabranjenaImena[i],true)!=-1)
         {
			 SendClientMessage(playerid, 0xFFFFFFF, "Change your nick. | Promjeni svoje ime.");
			 Kick(playerid);
         }
    }
    TextDrawShowForPlayer(playerid, MainMenu[0]); TextDrawShowForPlayer(playerid, MainMenu[1]);
    TextDrawShowForPlayer(playerid, MainMenu[2]); TextDrawShowForPlayer(playerid, MainMenu[3]);
    PlayerTextDrawShow(playerid, con__); PlayerTextDrawShow(playerid, naslov__);
    
    //CreateDialog(playerid, DIALOG_JEZIK, DIALOG_STYLE_LIST, "Language / Jezik", ""#narancasta"1: "#bijela"English\n"#narancasta"2: "#bijela"Balcan","OK","","","","","");
    
    MONEY_BAR[0] = CreatePlayerTextDraw(playerid, 499.000000, 77.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, MONEY_BAR[0], 255);
    PlayerTextDrawFont(playerid, MONEY_BAR[0], 3);
    PlayerTextDrawLetterSize(playerid, MONEY_BAR[0], 0.579999, 2.200000);
    PlayerTextDrawColor(playerid, MONEY_BAR[0], -1);
    PlayerTextDrawSetOutline(playerid, MONEY_BAR[0], 1);
    PlayerTextDrawSetProportional(playerid, MONEY_BAR[0], 1);

    MONEY_BAR[2] = CreatePlayerTextDraw(playerid, 500.000000, 80.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, MONEY_BAR[2], 255);
    PlayerTextDrawFont(playerid, MONEY_BAR[2], 1);
    PlayerTextDrawLetterSize(playerid, MONEY_BAR[2], 0.529999, 1.700000);
    PlayerTextDrawColor(playerid, MONEY_BAR[2], -1);
    PlayerTextDrawSetOutline(playerid, MONEY_BAR[2], 0);
    PlayerTextDrawSetProportional(playerid, MONEY_BAR[2], 1);
    PlayerTextDrawSetShadow(playerid, MONEY_BAR[2], 1);
    PlayerTextDrawUseBox(playerid, MONEY_BAR[2], 1);
    PlayerTextDrawBoxColor(playerid, MONEY_BAR[2], 255);
    PlayerTextDrawTextSize(playerid, MONEY_BAR[2], 607.000000, 18.000000);

    MONEY_BAR[1] = CreatePlayerTextDraw(playerid, 485.000000, 76.000000, "~r~-");
    PlayerTextDrawBackgroundColor(playerid, MONEY_BAR[1], 255);
    PlayerTextDrawFont(playerid, MONEY_BAR[1], 3);
    PlayerTextDrawLetterSize(playerid, MONEY_BAR[1], 0.819999, 2.299999);
    PlayerTextDrawColor(playerid, MONEY_BAR[1], -1);
    PlayerTextDrawSetOutline(playerid, MONEY_BAR[1], 1);
    PlayerTextDrawSetProportional(playerid, MONEY_BAR[1], 1);

	// TABLA
	TABLA[0][playerid] = CreatePlayerTextDraw(playerid, 160.000000, 342.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[0][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[0][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[0][playerid], 0.500000, 10.100000);
    PlayerTextDrawColor(playerid, TABLA[0][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[0][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[0][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[0][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[0][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[0][playerid], -16843254);
    PlayerTextDrawTextSize(playerid, TABLA[0][playerid], 588.000000, 0.000000);

    TABLA[1][playerid] = CreatePlayerTextDraw(playerid, 165.000000, 347.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[1][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[1][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[1][playerid], 0.280000, 1.200000);
    PlayerTextDrawColor(playerid, TABLA[1][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[1][playerid], 1);
    PlayerTextDrawSetProportional(playerid, TABLA[1][playerid], 1);

    TABLA[2][playerid] = CreatePlayerTextDraw(playerid, 266.000000, 347.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[2][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[2][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[2][playerid], 0.280000, 1.200000);
    PlayerTextDrawColor(playerid, TABLA[2][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[2][playerid], 1);
    PlayerTextDrawSetProportional(playerid, TABLA[2][playerid], 1);

    TABLA[3][playerid] = CreatePlayerTextDraw(playerid, 463.000000, 344.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[3][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[3][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[3][playerid], 0.500000, 1.999999);
    PlayerTextDrawColor(playerid, TABLA[3][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[3][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[3][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[3][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[3][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[3][playerid], 255);
    PlayerTextDrawTextSize(playerid, TABLA[3][playerid], 579.000000, 0.000000);

    TABLA[4][playerid] = CreatePlayerTextDraw(playerid, 464.000000, 345.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[4][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[4][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[4][playerid], 0.500000, 1.699999);
    PlayerTextDrawColor(playerid, TABLA[4][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[4][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[4][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[4][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[4][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[4][playerid], 0xFF0000FF);
    PlayerTextDrawTextSize(playerid, TABLA[4][playerid], bonus_[playerid], 0.000000);

    TABLA[5][playerid] = CreatePlayerTextDraw(playerid, 486.000000, 346.000000, "BONUS");
    PlayerTextDrawBackgroundColor(playerid, TABLA[5][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[5][playerid], 2);
    PlayerTextDrawLetterSize(playerid, TABLA[5][playerid], 0.500000, 1.300000);
    PlayerTextDrawColor(playerid, TABLA[5][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[5][playerid], 1);
    PlayerTextDrawSetProportional(playerid, TABLA[5][playerid], 1);

    TABLA[6][playerid] = CreatePlayerTextDraw(playerid, 160.000000, 340.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[6][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[6][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[6][playerid], 0.500000, -0.200000);
    PlayerTextDrawColor(playerid, TABLA[6][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[6][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[6][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[6][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[6][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[6][playerid], 255);
    PlayerTextDrawTextSize(playerid, TABLA[6][playerid], 589.000000, 0.000000);

    TABLA[7][playerid] = CreatePlayerTextDraw(playerid, 160.000000, 435.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[7][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[7][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[7][playerid], 0.500000, -0.200000);
    PlayerTextDrawColor(playerid, TABLA[7][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[7][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[7][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[7][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[7][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[7][playerid], 255);
    PlayerTextDrawTextSize(playerid, TABLA[7][playerid], 589.000000, 0.000000);

    TABLA[8][playerid] = CreatePlayerTextDraw(playerid, 160.000000, 435.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[8][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[8][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[8][playerid], 0.500000, -10.800005);
    PlayerTextDrawColor(playerid, TABLA[8][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[8][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[8][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[8][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[8][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[8][playerid], 255);
    PlayerTextDrawTextSize(playerid, TABLA[8][playerid], 158.000000, 0.000000);

    TABLA[9][playerid] = CreatePlayerTextDraw(playerid, 593.000000, 435.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[9][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[9][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[9][playerid], 0.500000, -10.800005);
    PlayerTextDrawColor(playerid, TABLA[9][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[9][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[9][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[9][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[9][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[9][playerid], 255);
    PlayerTextDrawTextSize(playerid, TABLA[9][playerid], 587.000000, 0.000000);
    
    TABLA[10][playerid] = CreatePlayerTextDraw(playerid, 463.000000, 373.000000, "_");
    PlayerTextDrawBackgroundColor(playerid, TABLA[10][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[10][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[10][playerid], 0.500000, 1.999999);
    PlayerTextDrawColor(playerid, TABLA[10][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[10][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[10][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[10][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[10][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[10][playerid], 255);
    PlayerTextDrawTextSize(playerid, TABLA[10][playerid], 579.000000, 0.000000);

    TABLA[11][playerid] = CreatePlayerTextDraw(playerid, 464.000000, 374.000000, "_"); // POMICNI
    PlayerTextDrawBackgroundColor(playerid, TABLA[11][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[11][playerid], 1);
    PlayerTextDrawLetterSize(playerid, TABLA[11][playerid], 0.479999, 1.699998);
    PlayerTextDrawColor(playerid, TABLA[11][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[11][playerid], 0);
    PlayerTextDrawSetProportional(playerid, TABLA[11][playerid], 1);
    PlayerTextDrawSetShadow(playerid, TABLA[11][playerid], 1);
    PlayerTextDrawUseBox(playerid, TABLA[11][playerid], 1);
    PlayerTextDrawBoxColor(playerid, TABLA[11][playerid], 0xFF0000FF);
    PlayerTextDrawTextSize(playerid, TABLA[11][playerid], 578.000000, 0.000000);

    TABLA[12][playerid] = CreatePlayerTextDraw(playerid, 486.000000, 376.000000, "BOOST");
    PlayerTextDrawBackgroundColor(playerid, TABLA[12][playerid], 255);
    PlayerTextDrawFont(playerid, TABLA[12][playerid], 2);
    PlayerTextDrawLetterSize(playerid, TABLA[12][playerid], 0.500000, 1.299999);
    PlayerTextDrawColor(playerid, TABLA[12][playerid], -1);
    PlayerTextDrawSetOutline(playerid, TABLA[12][playerid], 1);
    PlayerTextDrawSetProportional(playerid, TABLA[12][playerid], 1);
    
    // INFO BOX
    INFO_BOX[playerid][0] = TextDrawCreate(160.000000, 338.000000, "_");
    TextDrawBackgroundColor(INFO_BOX[playerid][0], 255);
    TextDrawFont(INFO_BOX[playerid][0], 1);
    TextDrawLetterSize(INFO_BOX[playerid][0], 0.500000, -2.000000);
    TextDrawColor(INFO_BOX[playerid][0], -1);
    TextDrawSetOutline(INFO_BOX[playerid][0], 0);
    TextDrawSetProportional(INFO_BOX[playerid][0], 1);
    TextDrawSetShadow(INFO_BOX[playerid][0], 1);
    TextDrawUseBox(INFO_BOX[playerid][0], 1);
    TextDrawBoxColor(INFO_BOX[playerid][0], 90);
    TextDrawTextSize(INFO_BOX[playerid][0], 589.000000, 0.000000);

    INFO_BOX[playerid][1] = TextDrawCreate(163.000000, 324.000000, "_");
    TextDrawBackgroundColor(INFO_BOX[playerid][1], 255);
    TextDrawFont(INFO_BOX[playerid][1], 1);
    TextDrawLetterSize(INFO_BOX[playerid][1], 0.180000, 1.000000);
    TextDrawColor(INFO_BOX[playerid][1], -65281);
    TextDrawSetOutline(INFO_BOX[playerid][1], 1);
    TextDrawSetProportional(INFO_BOX[playerid][1], 1);
    
    work_Info[playerid] = TextDrawCreate(522.000000, 9.000000, "_");
    TextDrawBackgroundColor(work_Info[playerid], 255);
    TextDrawFont(work_Info[playerid], 2);
    TextDrawLetterSize(work_Info[playerid], 0.180000, 0.899999);
    TextDrawColor(work_Info[playerid], -1);
    TextDrawSetOutline(work_Info[playerid], 1);
    TextDrawSetProportional(work_Info[playerid], 1);
    
    // NAGIB
	Nagib[playerid] = TextDrawCreate(202.000000, 3.000000, "_");
    TextDrawBackgroundColor(Nagib[playerid], 255);
    TextDrawFont(Nagib[playerid], 1);
    TextDrawLetterSize(Nagib[playerid], 0.629999, 2.000000);
    TextDrawColor(Nagib[playerid], -1);
    TextDrawSetOutline(Nagib[playerid], 0);
    TextDrawSetProportional(Nagib[playerid], 1);
    TextDrawSetShadow(Nagib[playerid], 1);
    
    // LOADING BAR
    loading_[playerid][0] = TextDrawCreate(240.000000, 171.000000, "_");
    TextDrawBackgroundColor(loading_[playerid][0], 255);
    TextDrawFont(loading_[playerid][0], 1);
    TextDrawLetterSize(loading_[playerid][0], 0.500000, 3.099999);
    TextDrawColor(loading_[playerid][0], -1);
    TextDrawSetOutline(loading_[playerid][0], 0);
    TextDrawSetProportional(loading_[playerid][0], 1);
    TextDrawSetShadow(loading_[playerid][0], 1);
    TextDrawUseBox(loading_[playerid][0], 1);
    TextDrawBoxColor(loading_[playerid][0], 80);
    TextDrawTextSize(loading_[playerid][0], 390.000000, 0.000000);

    loading_[playerid][1] = TextDrawCreate(263.000000, 179.000000, "_");
    TextDrawBackgroundColor(loading_[playerid][1], 255);
    TextDrawFont(loading_[playerid][1], 2);
    TextDrawLetterSize(loading_[playerid][1], 0.490000, 1.300000);
    TextDrawColor(loading_[playerid][1], -1);
    TextDrawSetOutline(loading_[playerid][1], 1);
    TextDrawSetProportional(loading_[playerid][1], 1);
    
    loading_[playerid][2] = TextDrawCreate(242.000000, 173.000000, "_");
    TextDrawBackgroundColor(loading_[playerid][2], 255);
    TextDrawFont(loading_[playerid][2], 1);
    TextDrawLetterSize(loading_[playerid][2], 0.480000, 2.699999);
    TextDrawColor(loading_[playerid][2], -1);
    TextDrawSetOutline(loading_[playerid][2], 0);
    TextDrawSetProportional(loading_[playerid][2], 1);
    TextDrawSetShadow(loading_[playerid][2], 1);
    TextDrawUseBox(loading_[playerid][2], 1);
    TextDrawBoxColor(loading_[playerid][2], 25690);
    TextDrawTextSize(loading_[playerid][2], load_bar[playerid], 0.000000);
    
    // ODABIR POSLA - SUB MENI
    posaoOdabir[playerid][0] = CreatePlayerTextDraw(playerid,90.000000, 143.000000, "PILOT");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][0], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][0], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][0], 0.680000, 2.700000);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][0], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][0], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][0], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][0], 173.000000, 20.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][0], 1);

    posaoOdabir[playerid][1] = CreatePlayerTextDraw(playerid,90.000000, 175.000000, "TAXI");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][1], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][1], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][1], 0.680000, 2.699999);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][1], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][1], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][1], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][1], 155.000000, 20.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][1], 1);

    posaoOdabir[playerid][2] = CreatePlayerTextDraw(playerid,90.000000, 207.000000, "TRUCKER");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][2], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][2], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][2], 0.680000, 2.699999);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][2], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][2], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][2], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][2], 221.000000, 20.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][2], 1);

    posaoOdabir[playerid][3] = CreatePlayerTextDraw(playerid,90.000000, 239.000000, "SAILOR");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][3], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][3], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][3], 0.680000, 2.699999);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][3], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][3], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][3], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][3], 197.000000, 20.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][3], 1);

    posaoOdabir[playerid][4] = CreatePlayerTextDraw(playerid,321.000000, 143.000000, "CIVILIAN PILOT");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][4], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][4], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][4], 0.680000, 2.700000);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][4], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][4], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][4], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][4], 533.000000, 15.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][4], 1);

    posaoOdabir[playerid][5] = CreatePlayerTextDraw(playerid,321.000000, 174.000000, "MEDICAL PILOT");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][5], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][5], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][5], 0.680000, 2.700000);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][5], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][5], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][5], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][5], 545.000000, 15.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][5], 1);

    posaoOdabir[playerid][6] = CreatePlayerTextDraw(playerid,321.000000, 205.000000, "MILITARY PILOT");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][6], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][6], 2);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][6], 0.680000, 2.700000);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][6], -1);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][6], 1);
    PlayerTextDrawUseBox(playerid,posaoOdabir[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid,posaoOdabir[playerid][6], -16776961);
    PlayerTextDrawTextSize(playerid,posaoOdabir[playerid][6], 545.000000, 15.000000);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][6], 1);

    posaoOdabir[playerid][7] = CreatePlayerTextDraw(playerid,228.000000, 181.000000, "----------------------~>~");
    PlayerTextDrawBackgroundColor(playerid,posaoOdabir[playerid][7], 255);
    PlayerTextDrawFont(playerid,posaoOdabir[playerid][7], 1);
    PlayerTextDrawLetterSize(playerid,posaoOdabir[playerid][7], 0.209999, 1.299999);
    PlayerTextDrawColor(playerid,posaoOdabir[playerid][7], -16776961);
    PlayerTextDrawSetOutline(playerid,posaoOdabir[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid,posaoOdabir[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid,posaoOdabir[playerid][7], 0);
    
    // Odabir spola
    PlayerTextDrawShow(playerid,langOdabir[playerid][0]);
    PlayerTextDrawShow(playerid,langOdabir[playerid][1]);
    SelectTextDraw(playerid, 0xF50000FF);
	return (true);
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == langOdabir[playerid][0])
    {
         SetPlayerLanguage(playerid, false);
         PlayerTextDrawHide(playerid,langOdabir[playerid][0]);
         PlayerTextDrawHide(playerid,langOdabir[playerid][1]);
         CheckAccount(playerid);
         CancelSelectTextDraw(playerid);
    }
    else if(playertextid == langOdabir[playerid][1])
    {
         SetPlayerLanguage(playerid, true);
         PlayerTextDrawHide(playerid,langOdabir[playerid][0]);
         PlayerTextDrawHide(playerid,langOdabir[playerid][1]);
         CheckAccount(playerid);
         CancelSelectTextDraw(playerid);
    }
    else if(playertextid == posaoOdabir[playerid][0])// PILOT
    {
         PlayerTextDrawSetString(playerid, posaoOdabir[playerid][4], "Civilian Pilot");
         PlayerTextDrawSetString(playerid, posaoOdabir[playerid][5], "Medical Pilot");
         PlayerTextDrawSetString(playerid, posaoOdabir[playerid][6], "Military Pilot");
         
         PlayerTextDrawShow(playerid,posaoOdabir[playerid][7]);
         PlayerTextDrawShow(playerid,posaoOdabir[playerid][4]);
         PlayerTextDrawShow(playerid,posaoOdabir[playerid][5]);
         PlayerTextDrawShow(playerid,posaoOdabir[playerid][6]);
         choosePosao{playerid} = (1);
    }
    else if(playertextid == posaoOdabir[playerid][1]) // TAXI
    {
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][7]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][4]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][5]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][6]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][3]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][2]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][1]);
         PlayerTextDrawHide(playerid,posaoOdabir[playerid][0]);
         choosePosao{playerid} = (2);
         
         Team{playerid} = (4);
         if(PlayerInfo[playerid][HouseSpawn] == 1 && PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID)
	     {
		     new houseid = PlayerInfo[playerid][Kljuc_Kuca];
		     SetPlayerInterior(playerid, HouseInfo[houseid][h_Vw]); SetPlayerInterior(playerid, HouseInfo[houseid][h_Int]);
             SetSpawnInfo(playerid, 0, 7, HouseInfo[houseid][h_In][0], HouseInfo[houseid][h_In][1], HouseInfo[houseid][h_In][2],0,0,0,0,0,0,0);
             inhouse[playerid] = (houseid);
             if(playerSmrt{playerid} == true)
	         {
			    playerSmrt{playerid} = (false);
             }
	         move{playerid} = (false);
	         TogglePlayerSpectating(playerid,0);
	         SetPlayerColorByJob(playerid);
	         SpawnPlayer(playerid);
	         CancelSelectTextDraw(playerid);
             return (true);
         }
         CancelSelectTextDraw(playerid);
         CreateDialog(playerid, DIALOG_SPAWN_MJESTO, DIALOG_STYLE_LIST, "Odaberi grad", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "", "Choose town", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "");
    }
    else if(playertextid == posaoOdabir[playerid][2]) // KAMION
    {
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][7]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][4]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][5]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][6]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][3]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][2]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][1]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][0]);
          choosePosao{playerid} = (3);
          
          Team{playerid} = (6);
          if(PlayerInfo[playerid][HouseSpawn] == 1 && PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID)
	      {
		     new houseid = PlayerInfo[playerid][Kljuc_Kuca];
		     SetPlayerInterior(playerid, HouseInfo[houseid][h_Vw]); SetPlayerInterior(playerid, HouseInfo[houseid][h_Int]);
             SetSpawnInfo(playerid, 0, 7, HouseInfo[houseid][h_In][0], HouseInfo[houseid][h_In][1], HouseInfo[houseid][h_In][2],0,0,0,0,0,0,0);
             inhouse[playerid] = (houseid);
             if(playerSmrt{playerid} == true)
	         {
			    playerSmrt{playerid} = (false);
             }
	         move{playerid} = (false);
	         TogglePlayerSpectating(playerid,0);
	         SetPlayerColorByJob(playerid);
	         SpawnPlayer(playerid);
	         CancelSelectTextDraw(playerid);
             return (true);
          }
          CancelSelectTextDraw(playerid);
          CreateDialog(playerid, DIALOG_SPAWN_MJESTO, DIALOG_STYLE_LIST, "Odaberi kompaniju", ""#zuta"1: "#bijela"Mala kompanija\n"#zuta"2: "#bijela"Velika kompanija", "Spawn", "", "Choose company", ""#zuta"1: "#bijela"Little company\n"#zuta"2: "#bijela"Big company", "Spawn", "");
    }
    else if(playertextid == posaoOdabir[playerid][3]) // MOREPLOVAC
    {
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][7]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][4]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][5]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][6]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][3]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][2]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][1]);
          PlayerTextDrawHide(playerid,posaoOdabir[playerid][0]);
          choosePosao{playerid} = (4);
          
          Team{playerid} = (7);
          if(PlayerInfo[playerid][HouseSpawn] == 1 && PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID)
	      {
		     new houseid = PlayerInfo[playerid][Kljuc_Kuca];
		     SetPlayerInterior(playerid, HouseInfo[houseid][h_Vw]); SetPlayerInterior(playerid, HouseInfo[houseid][h_Int]);
             SetSpawnInfo(playerid, 0, 7, HouseInfo[houseid][h_In][0], HouseInfo[houseid][h_In][1], HouseInfo[houseid][h_In][2],0,0,0,0,0,0,0);
             inhouse[playerid] = (houseid);
             if(playerSmrt{playerid} == true)
	         {
			    playerSmrt{playerid} = (false);
             }
	         move{playerid} = (false);
	         TogglePlayerSpectating(playerid,0);
	         SetPlayerColorByJob(playerid);
	         SpawnPlayer(playerid);
	         CancelSelectTextDraw(playerid);
             return (true);
          }
          CancelSelectTextDraw(playerid);
          CreateDialog(playerid, DIALOG_SPAWN_MJESTO, DIALOG_STYLE_LIST, "Odaberi grad", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "", "Choose town", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "");
    }
    else if(playertextid == posaoOdabir[playerid][4]) // SUB MENI 1
    {
		 if(choosePosao{playerid} == 1) // Pilot
		 {
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][7]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][4]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][5]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][6]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][3]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][2]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][1]);
              PlayerTextDrawHide(playerid,posaoOdabir[playerid][0]);
              
              Team{playerid} = (1);
              new id = IsPlayerInAirline(playerid, GetName(playerid));
              if(PlayerInfo[playerid][HouseSpawn] == 1 && PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID)
	          {
		         new houseid = PlayerInfo[playerid][Kljuc_Kuca];
		         SetPlayerInterior(playerid, HouseInfo[houseid][h_Vw]); SetPlayerInterior(playerid, HouseInfo[houseid][h_Int]);
                 SetSpawnInfo(playerid, 0, 61, HouseInfo[houseid][h_In][0], HouseInfo[houseid][h_In][1], HouseInfo[houseid][h_In][2],0,0,0,0,0,0,0);
                 inhouse[playerid] = (houseid);
                 if(playerSmrt{playerid} == true)
                 {
			       playerSmrt{playerid} = (false);
                 }
	             move{playerid} = (false);
	             TogglePlayerSpectating(playerid,0);
	             SetPlayerColorByJob(playerid);
	             SpawnPlayer(playerid);
	             CancelSelectTextDraw(playerid);
                 return (true);
	          }
	          if(PlayerInfo[playerid][AvioSpawn] >= 1 && id != -1)
              {
		         SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0);
		         SetSpawnInfo(playerid, 0, 61, AvioKompanija[id][av_Spawn][0], AvioKompanija[id][av_Spawn][1], AvioKompanija[id][av_Spawn][2], AvioKompanija[id][av_Spawn][3],0,0,0,0,0,0);
		         if(playerSmrt{playerid} == true)
                 {
			        playerSmrt{playerid} = (false);
                 }
                 move{playerid} = (false);
                 TogglePlayerSpectating(playerid,0);
                 SetPlayerColorByJob(playerid);
                 SpawnPlayer(playerid);
                 CancelSelectTextDraw(playerid);
                 return (true);
	          }
	          else { PlayerInfo[playerid][AvioSpawn] = (0); UpdatePlayer(playerid); }
	          CancelSelectTextDraw(playerid);
              CreateDialog(playerid, DIALOG_SPAWN_MJESTO, DIALOG_STYLE_LIST, "Odaberi pistu", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "", "Choose airport", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "");
		 }
    }
    else if(playertextid == posaoOdabir[playerid][5])
    {
         if(choosePosao{playerid} == 1) // Pilot
		 {
		      if(PlayerInfo[playerid][Bodovi] < 30) return SCM(playerid, ""#bijela"* Moras imati 30+ bodova (score).", ""#bijela"* You must have 30+ scores.");
		      else
		      {
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][7]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][4]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][5]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][6]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][3]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][2]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][1]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][0]);
                  
                  Team{playerid} = (2);
                  new id = IsPlayerInAirline(playerid, GetName(playerid));
                  if(PlayerInfo[playerid][HouseSpawn] == 1 && PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID)
	              {
		             new houseid = PlayerInfo[playerid][Kljuc_Kuca];
		             SetPlayerInterior(playerid, HouseInfo[houseid][h_Vw]); SetPlayerInterior(playerid, HouseInfo[houseid][h_Int]);
                     SetSpawnInfo(playerid, 0, 61, HouseInfo[houseid][h_In][0], HouseInfo[houseid][h_In][1], HouseInfo[houseid][h_In][2],0,0,0,0,0,0,0);
                     inhouse[playerid] = (houseid);
                     if(playerSmrt{playerid} == true)
	                 {
			           playerSmrt{playerid} = (false);
                     }
	                 move{playerid} = (false);
	                 TogglePlayerSpectating(playerid,0);
	                 SetPlayerColorByJob(playerid);
	                 SpawnPlayer(playerid);
	                 CancelSelectTextDraw(playerid);
                     return (true);
	              }
	              if(PlayerInfo[playerid][AvioSpawn] >= 1 && id != -1)
	              {
				      SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0);
				      SetSpawnInfo(playerid, 0, 61, AvioKompanija[id][av_Spawn][0], AvioKompanija[id][av_Spawn][1], AvioKompanija[id][av_Spawn][2], AvioKompanija[id][av_Spawn][3],0,0,0,0,0,0);
				      if(playerSmrt{playerid} == true)
	                  {
			             playerSmrt{playerid} = (false);
                      }
	                  move{playerid} = (false);
	                  TogglePlayerSpectating(playerid,0);
	                  SetPlayerColorByJob(playerid);
	                  SpawnPlayer(playerid);
	                  CancelSelectTextDraw(playerid);
	                  return (true);
	              }
	              else { PlayerInfo[playerid][AvioSpawn] = (0); UpdatePlayer(playerid); }
	              CancelSelectTextDraw(playerid);
                  CreateDialog(playerid, DIALOG_SPAWN_MJESTO, DIALOG_STYLE_LIST, "Odaberi pistu", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "", "Choose airport", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero", "Spawn", "");
		      }
		 }
    }
    else if(playertextid == posaoOdabir[playerid][6])
    {
         if(choosePosao{playerid} == 1) // Pilot
         {
             if(PlayerInfo[playerid][Bodovi] < 60) return SCM(playerid, ""#bijela"* Moras imati 60+ bodova (score).", ""#bijela"* You must have 60+ scores.");
		     else
		     {
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][7]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][4]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][5]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][6]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][3]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][2]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][1]);
                  PlayerTextDrawHide(playerid,posaoOdabir[playerid][0]);
                  
                  Team{playerid} = (3);
                  new id = IsPlayerInAirline(playerid, GetName(playerid));
                  if(PlayerInfo[playerid][HouseSpawn] == 1 && PlayerInfo[playerid][Kljuc_Kuca] != INVALID_HOUSE_ID)
	              {
		             new houseid = PlayerInfo[playerid][Kljuc_Kuca];
		             SetPlayerInterior(playerid, HouseInfo[houseid][h_Vw]); SetPlayerInterior(playerid, HouseInfo[houseid][h_Int]);
                     SetSpawnInfo(playerid, 0, 61, HouseInfo[houseid][h_In][0], HouseInfo[houseid][h_In][1], HouseInfo[houseid][h_In][2],0,0,0,0,0,0,0);
                     inhouse[playerid] = (houseid);
                     if(playerSmrt{playerid} == true)
	                 {
			            playerSmrt{playerid} = (false);
                     }
	                 move{playerid} = (false);
	                 TogglePlayerSpectating(playerid,0);
	                 SetPlayerColorByJob(playerid);
	                 SpawnPlayer(playerid);
	                 CancelSelectTextDraw(playerid);
                     return (true);
	              }
                  if(PlayerInfo[playerid][AvioSpawn] >= 1 && id != -1)
	              {
				      SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0);
				      SetSpawnInfo(playerid, 0, 61, AvioKompanija[id][av_Spawn][0], AvioKompanija[id][av_Spawn][1], AvioKompanija[id][av_Spawn][2], AvioKompanija[id][av_Spawn][3],0,0,0,0,0,0);
				      if(playerSmrt{playerid} == true)
	                  {
			            playerSmrt{playerid} = (false);
                      }
	                  move{playerid} = (false);
	                  TogglePlayerSpectating(playerid,0);
	                  SetPlayerColorByJob(playerid);
	                  SpawnPlayer(playerid);
	                  CancelSelectTextDraw(playerid);
	                  return (true);
	              }
	              else { PlayerInfo[playerid][AvioSpawn] = (0); UpdatePlayer(playerid); }
	              CancelSelectTextDraw(playerid);
                  CreateDialog(playerid, DIALOG_SPAWN_MJESTO, DIALOG_STYLE_LIST, "Odaberi pistu", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero\n"#zuta"4: "#bijela"Area 51", "Spawn", "", "Choose airport", ""#zuta"1: "#bijela"Los Santos\n"#zuta"2: "#bijela"Las Venturas\n"#zuta"3: "#bijela"San Fiero\n"#zuta"4: "#bijela"Area 51", "Spawn", "");
		     }
         }
    }
    return (true);
}

stock SendInfo(playerid, balkan[], english[], bool:stvori)
{
	if(stvori == true)
	{
       TextSet(Text:INFO_BOX[playerid][1], balkan, english);
       TextDrawShowForPlayer(playerid, Text:INFO_BOX[playerid][0]);
       TextDrawShowForPlayer(playerid, Text:INFO_BOX[playerid][1]);
       info_box{playerid} = (8);
	}
	else if(stvori == false)
	{
       TextSet(Text:INFO_BOX[playerid][1], "_", "_");
       TextDrawHideForPlayer(playerid, Text:INFO_BOX[playerid][0]);
       TextDrawHideForPlayer(playerid, Text:INFO_BOX[playerid][1]);
       info_box{playerid} = (0);
	}
	return (true);
}

stock bool:isSQLidOnline(sqlid)
{
	foreach(Player, i)
	{
		if(PlayerInfo[i][ID] == sqlid)
		{
		    return true;
		}
	}
	return false;
}

forward DohvatiLozinku(playerid);
public DohvatiLozinku(playerid)
{
	new string[100];
    if(cache_num_rows() > 0)
	{
	    cache_get_field_content(0, "Lozinka", string);
	    format(PlayerInfo[playerid][Lozinka], 200, "%s", string);
 	}
	return true;
}

forward OnPlayerLoginEx(playerid);
public OnPlayerLoginEx(playerid)
{
	new string1[128] = "\0", string2[128] = "\0";
	if(cache_num_rows() > 0)
	{
	    cache_get_field_content(0, "ID", string1);
	    PlayerInfo[playerid][ID] = strval(string1);
	    cache_get_field_content(0, "Nick", string1);
	    format(PlayerInfo[playerid][Nick], MAX_PLAYER_NAME, "%s", string1);
	    cache_get_field_content(0, "Email", string1);
	    format(PlayerInfo[playerid][Email], 50, "%s", string1);
	    cache_get_field_content(0, "Lozinka", string1);
	    format(PlayerInfo[playerid][Lozinka], 200, "%s",string1);
	    cache_get_field_content(0, "Spol", string1);
	    PlayerInfo[playerid][Spol] = strval(string1);
	    cache_get_field_content(0, "Preporuka", string1);
	    PlayerInfo[playerid][Preporuka] = strval(string1);
	    cache_get_field_content(0, "Grupa", string1);
	    PlayerInfo[playerid][Grupa] = strval(string1);
	    cache_get_field_content(0, "Iskljucen", string1);
	    PlayerInfo[playerid][Iskljucen] = strval(string1);
	    cache_get_field_content(0, "Admin", string1);
	    PlayerInfo[playerid][Admin] = strval(string1);
	    cache_get_field_content(0, "Novac", string1);
	    PlayerInfo[playerid][Novac] = strval(string1);
	    cache_get_field_content(0, "Bodovi", string1);
	    PlayerInfo[playerid][Bodovi] = strval(string1);
	    cache_get_field_content(0, "Bodovi_1", string1);
	    PlayerInfo[playerid][Bodovi_][0] = strval(string1);
	    cache_get_field_content(0, "Bodovi_2", string1);
	    PlayerInfo[playerid][Bodovi_][1] = strval(string1);
	    cache_get_field_content(0, "Bodovi_3", string1);
	    PlayerInfo[playerid][Bodovi_][2] = strval(string1);
	    cache_get_field_content(0, "Radio", string1);
	    format(PlayerInfo[playerid][Radio], 3, "%s", string1);
	    cache_get_field_content(0, "Ubrzanje", string1);
		format(PlayerInfo[playerid][Ubrzanje], 3, "%s", string1);
	    cache_get_field_content(0, "Sati", string1);
	    PlayerInfo[playerid][Sati] = strval(string1);
	    cache_get_field_content(0, "Minute", string1);
	    PlayerInfo[playerid][Minute] = strval(string1);
	    cache_get_field_content(0, "Zadnji_Login", string1);
	    PlayerInfo[playerid][Zadnji_Login] = strval(string1);
	    cache_get_field_content(0, "Kljuc_Kuca", string1);
	    PlayerInfo[playerid][Kljuc_Kuca] = strval(string1);
	    cache_get_field_content(0, "Kljuc_Vozilo_1", string1);
	    PlayerInfo[playerid][Kljuc_Vozilo][0] = strval(string1);
	    cache_get_field_content(0, "Kljuc_Vozilo_2", string1);
	    PlayerInfo[playerid][Kljuc_Vozilo][1] = strval(string1);
	    cache_get_field_content(0, "Kljuc_Vozilo_3", string1);
	    PlayerInfo[playerid][Kljuc_Vozilo][2] = strval(string1);
	    cache_get_field_content(0, "Registracija", string1);
	    PlayerInfo[playerid][Registracija] = strval(string1);
	    cache_get_field_content(0, "Logiran", string1);
	    PlayerInfo[playerid][Logiran] = strval(string1);
	    cache_get_field_content(0, "Tankirao_1", string1);
	    PlayerInfo[playerid][Tankirao][0] = strval(string1);
	    cache_get_field_content(0, "Tankirao_2", string1);
	    PlayerInfo[playerid][Tankirao][1] = strval(string1);
	    cache_get_field_content(0, "Popravio_1", string1);
	    PlayerInfo[playerid][Popravio][0] = strval(string1);
	    cache_get_field_content(0, "Popravio_2", string1);
	    PlayerInfo[playerid][Popravio][1] = strval(string1);
	    cache_get_field_content(0, "Smrt", string1);
	    PlayerInfo[playerid][Smrt] = strval(string1);
	    cache_get_field_content(0, "Prekid", string1);
	    PlayerInfo[playerid][Prekid] = strval(string1);
	    cache_get_field_content(0, "Upozorenja", string1);
	    PlayerInfo[playerid][Upozorenja] = strval(string1);
	    cache_get_field_content(0, "Pohvale", string1);
	    PlayerInfo[playerid][Pohvale] = strval(string1);
	    cache_get_field_content(0, "Pozicija_X", string1);
	    PlayerInfo[playerid][Pozicija][0]= floatstr(string1);
	    cache_get_field_content(0, "Pozicija_Y", string1);
	    PlayerInfo[playerid][Pozicija][1] = floatstr(string1);
	    cache_get_field_content(0, "Pozicija_Z", string1);
	    PlayerInfo[playerid][Pozicija][2] = floatstr(string1);
	    cache_get_field_content(0, "Vip", string1);
	    PlayerInfo[playerid][Vip] = strval(string1);
	    cache_get_field_content(0, "HouseSpawn", string1);
	    PlayerInfo[playerid][HouseSpawn] = strval(string1);
	    cache_get_field_content(0, "Vlasnik_Kompanije", string1);
	    PlayerInfo[playerid][Vlasnik_Kompanije] = strval(string1);
	    cache_get_field_content(0, "Vip_Vrijeme", string1);
	    PlayerInfo[playerid][Vip_Vrijeme] = strval(string1);
	    cache_get_field_content(0, "Fix", string1);
	    PlayerInfo[playerid][Fix] = strval(string1);
	    cache_get_field_content(0, "Fill", string1);
	    PlayerInfo[playerid][Fill] = strval(string1);
	    cache_get_field_content(0, "AvioSpawn", string1);
	    PlayerInfo[playerid][AvioSpawn] = strval(string1);
	    cache_get_field_content(0, "AirlineUgovor", string1);
	    PlayerInfo[playerid][AirlineUgovor] = strval(string1);
	    cache_get_field_content(0, "Shamal", string1);
	    PlayerInfo[playerid][Shamal] = strval(string1);
	    cache_get_field_content(0, "Dodo", string1);
	    PlayerInfo[playerid][Dodo] = strval(string1);
	    cache_get_field_content(0, "Beagle", string1);
	    PlayerInfo[playerid][Beagle] = strval(string1);
	    cache_get_field_content(0, "Hydra", string1);
	    PlayerInfo[playerid][Hydra] = strval(string1);
	    cache_get_field_content(0, "Nevada", string1);
	    PlayerInfo[playerid][Nevada] = strval(string1);
	    cache_get_field_content(0, "At400s", string1);
	    PlayerInfo[playerid][At400s] = strval(string1);
	    cache_get_field_content(0, "Andromada", string1);
	    PlayerInfo[playerid][Andromada] = strval(string1);
	    cache_get_field_content(0, "trenutnaX", string1);
	    PlayerInfo[playerid][trenutnaX] = floatstr(string1);
	    cache_get_field_content(0, "trenutnaY", string1);
	    PlayerInfo[playerid][trenutnaY] = floatstr(string1);
	    
	    novost(GetName(playerid), "se prijavio na svoj racun.");
	    PlayerInfo[playerid][Zadnji_Login] = gettime();
    	SetPlayerScore(playerid, GetPlayerScoreEx(playerid));
    	PlayerInfo[playerid][Logiran] ++;
    	CreateDialog(playerid, DIALOG_USPJESNI_LOGIN, DIALOG_STYLE_MSGBOX, ""#error"Server For Pilots", ""#narancasta">> "#bijela"Uspjesno si se logirao!", "Zatvori", "", ""#error"Server For Pilots", ""#narancasta">> "#bijela"You are successfully logged!", "Close", "");
    	PlayerLogin{playerid} = (true);
	}
	else if(cache_num_rows() <= 0)
	{
        FailLogin{playerid}++;
 	    if(FailLogin{playerid} >= MAX_LOGIN_POKUSAJA)
        {
 			SCM(playerid, ""#error"[SERVER]: Kickan si sa servera zbog previse pokusaja logiranja.", ""#error"[SERVER]: You have been kicked from server because of too much login attempts.");
		    Kick(playerid);
	    }
	    format(string1, (sizeof string1), ""#error"[SERVER]: "#siva"Pogresna lozinka | Preostalo pokusaja %d/%d",FailLogin{playerid},MAX_LOGIN_POKUSAJA);
	    format(string2, (sizeof string2), ""#error"[SERVER]: "#siva"Wrong password | Remaining attempts %d/%d",FailLogin{playerid},MAX_LOGIN_POKUSAJA);
	    SCM(playerid, string1, string2);
	    CheckAccount(playerid);
	}
	return true;
}

forward EmailDostavi(index, response_code, data[]);
public EmailDostavi(index, response_code, data[])
{
    new buffer[128];
    if(response_code == 200)
    {
        format(buffer, sizeof(buffer), "Status: %s", data);
        SCM(index, buffer, buffer);
    }
    else
    {
        format(buffer, sizeof(buffer), "Status: Undelivered Response Code: %d", response_code);
        SCM(index, buffer, buffer);
    }
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new
	   string1[512] = "\0",
	   string2[256] = "\0";
    if(dialogid == DIALOG_REGISTER)
	{
		if(strlen(inputtext) < 3 || strlen(inputtext) > 15) { SCM(playerid, "SERVER: Lozinka ne smije biti manja od 3 slova, a veca od 15 slova ili brojeva.", "SERVER: Your password should not have less then 3 letters or higher then 15 letters or numbers."); CheckAccount(playerid); }
		else
		{
			OnPlayerRegister(playerid, inputtext);
		}
	}
	else if(dialogid == DIALOG_LOGIN)
	{
	    mysql_format(mySQL, string2, (sizeof string2), "SELECT * FROM `korisnici` WHERE `Nick`='%e' AND `Lozinka`=MD5('%e') LIMIT 1;", GetName(playerid), inputtext);
        mysql_pquery(mySQL, string2, "OnPlayerLoginEx", "i", playerid);
	}
	else if(dialogid == DIALOG_EMAIL)
	{
	    if(strlen(inputtext) < 4 || strfind(inputtext, "@", true) == -1 || strfind(inputtext, ".", true) == -1)
	    {
	        return CreateDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, "Server For Pilots - Email", "Neto�na email adresa!\nUnesite svoju email adresu!","DALJE","","Server For Pilots - Email","Incorrect email address!\nEnter your email address","NEXT","");
	    }
	    PlayerLogin{playerid} = (true); posao{playerid} = (false);
    	jobOdabir(playerid);
    	format(PlayerInfo[playerid][Email], 50, "%s",inputtext);
    	
    	format(string1, sizeof(string1), "samp-sfp.com/aktivacija-racuna.php?samp=%s&jezik=%s",GetName(playerid),GetPlayerLanguage(playerid));
    	HTTP(playerid, HTTP_GET, string1, " ", "EmailDostavi");
	}
	else if(dialogid == DIALOG_USPJESNI_LOGIN)
	{
		if(response) return jobOdabir(playerid);
		else if(!response) return jobOdabir(playerid);
	}
	else if(dialogid == DIALOG_SPAWN_MJESTO)
	{
		if(listitem == 0) // LS
		{
		   if(Team{playerid} < 4){SetSpawnInfo(playerid, 0, 61, 1881.8055,-2528.6833,13.5469,357.8358,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		   else if(Team{playerid} == 4){SetSpawnInfo(playerid, 0, 7, 1755.8203,-1898.4631,13.5616,271.7444,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		   else if(Team{playerid} == 6){SetSpawnInfo(playerid, 0, 133, -83.3641,-1136.6288,1.0781,328.6721,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }//MALA
		   else if(Team{playerid} == 7){SetSpawnInfo(playerid, 0, 210, 2690.0029,-2325.8052,13.3315,269.1148,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		   if(playerSmrt{playerid} == true)
	       {
			  playerSmrt{playerid} = (false);
	       }
	       move{playerid} = (false);
	       TogglePlayerSpectating(playerid,0);
	       SetPlayerColorByJob(playerid);
	       SpawnPlayer(playerid);
		}
		else if(listitem == 1) // LV
		{
           if(Team{playerid} < 4){SetSpawnInfo(playerid, 0, 61, 1319.3599,1261.9497,10.8203,1.3586,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		   else if(Team{playerid} == 4){SetSpawnInfo(playerid, 0, 7, 2841.0278,1290.9235,11.3906,91.4602,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		   else if(Team{playerid} == 6){SetSpawnInfo(playerid, 0, 133, -525.2004,-502.8224,25.5234,357.1624,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }//VELIKA
		   else if(Team{playerid} == 7){SetSpawnInfo(playerid, 0, 210, 2289.2686,552.3491,7.7813,87.2127,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
           if(playerSmrt{playerid} == true)
	       {
			  playerSmrt{playerid} = (false);
	       }
	       move{playerid} = (false);
	       TogglePlayerSpectating(playerid,0);
	       SetPlayerColorByJob(playerid);
	       SpawnPlayer(playerid);
		}
		else if(listitem == 2) // SF
		{
            if(Team{playerid} < 4){SetSpawnInfo(playerid, 0, 61, -1259.2897,79.3274,14.1407,133.4472,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		    else if(Team{playerid} == 4){SetSpawnInfo(playerid, 0, 7, -1942.9761,560.3199,35.1719,359.6480,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
		    else if(Team{playerid} == 7){SetSpawnInfo(playerid, 0, 210, -1466.7751,1077.6184,7.1875,91.7898,0,0,0,0,0,0); SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0); }
            if(playerSmrt{playerid} == true)
	        {
			  playerSmrt{playerid} = (false);
	        }
	        move{playerid} = (false);
	        TogglePlayerSpectating(playerid,0);
	        SetPlayerColorByJob(playerid);
	        SpawnPlayer(playerid);
		}
		else if(listitem == 3) // area 51
		{
            SetSpawnInfo(playerid, 0, 287, 285.0164,1938.9041,17.6406,187.3545,0,0,0,0,0,0);
            SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0);
            if(playerSmrt{playerid} == true)
	        {
			  playerSmrt{playerid} = (false);
	        }
	        move{playerid} = (false);
	        TogglePlayerSpectating(playerid,0);
	        SetPlayerColorByJob(playerid);
	        SpawnPlayer(playerid);
		}
	}
	else if(dialogid == DIALOG_STORE)
	{
	   if(!response) return (true);
	   if(listitem == 0) // KUPI
	   {
           CreateDialog(playerid, DIALOG_STORE_BUY, DIALOG_STYLE_LIST,
           ""#error"Odaberi proizvod",
           ""#bijela"Radio - "#zelena"$10,000\n"#bijela"Ubrzanje - "#zelena"$15,000\n"#bijela"Brzi popravci x15 - "#zelena"$100,000\n"#bijela"Brzo gorivo x15 - "#zelena"$100,000",
           "Kupi",
           "Natrag",
           //ENGLISH
           ""#error"Choose stuff",
           ""#bijela"Radio - "#zelena"$10,000\n"#bijela"Boost - "#zelena"$15,000\n"#bijela"Fast repair x15 - "#zelena"$100,000\n"#bijela"Fast fuel x15 - "#zelena"$100,000",
           "Buy",
           "Back");
	   }
	   else if(listitem == 1) // PRODAJ
	   {
           CreateDialog(playerid, DIALOG_STORE_SELL, DIALOG_STYLE_LIST,
           ""#error"Odaberi",
           ""#bijela"Radio - "#zelena"$7,000\n"#bijela"Ubrzanje - "#zelena"$10,000",
           "Prodaj",
           "Natrag",
           //ENGLISH
           ""#error"Choose",
           ""#bijela"Radio - "#zelena"$7,000\n"#bijela"Boost - "#zelena"$10,000",
           "Sell",
           "Back");
	   }
	}
	else if(dialogid == DIALOG_ENDROUTE)
	{
		if(response) return (true);
		else if(!response) return (true);
	}
	else if(dialogid == DIALOG_STORE_BUY)
	{
		if(!response) {
		CreateDialog(playerid,
		DIALOG_STORE,
		DIALOG_STYLE_LIST,
		""#error"Online ducan",
		""#zuta"(1): "#bijela"Kupi\n"#zuta"(2): "#bijela"Prodaj",
		"Odaberi",
		"Odustani",
		""#error"Online store", // ENGLISH
		""#zuta"(1): "#bijela"Buy stuff\n"#zuta"(2): "#bijela"Sell stuff",
		"Choose",
		"Cancel"); return (true); }
		if(listitem == 0) // RADIO
		{
			if(GetPlayerMoneyEx(playerid) < 10000) return SCM(playerid, ""#siva"Nemas dovoljno novaca.", ""#siva"You don't have enought money.");
			else if(IsPlayerHaveRadio(playerid)) return SCM(playerid, ""#siva"Vec imas radio.", ""#siva"You already have a radio.");
			else
			{
				GivePlayerRadio(playerid, true);
				GivePlayerMoneyEx(playerid, -10000);
				SCM(playerid, ""#zuta"Kupio si radio, koristi /radio kako bi ga pokrenuo.", ""#zuta"You bought a radio, use /radio for listen.");
			}
		}
		else if(listitem == 1) // UBRZANJE
		{
			if(GetPlayerMoneyEx(playerid) < 15000) return SCM(playerid, ""#siva"Nemas dovoljno novaca.", ""#siva"You don't have enought money.");
			else if(IsPlayerHaveBoost(playerid)) return SCM(playerid, ""#siva"Vec imas ubrzanje.", ""#siva"You already have a boost.");
			else
			{
				GivePlayerBoost(playerid, true);
				GivePlayerMoneyEx(playerid,- 15000);
				SCM(playerid, ""#zuta"Kupio si ubrzanje mozes ga koristiti kada radis koristeci tipku Y.", ""#zuta"You bought a boost, you can use boost when you work by pressing Y.");
			}
		}
		else if(listitem == 2) // FIX KIT 100,000 x15
		{
            if(GetPlayerMoneyEx(playerid) < 100000) return SCM(playerid, ""#siva"Nemas dovoljno novaca.", ""#siva"You don't have enought money.");
			else
			{
                GivePlayerMoneyEx(playerid, -100000);
                PlayerInfo[playerid][Fix] += (15);
                UpdatePlayer(playerid);
                format(string1, (sizeof string1), ""#narancasta">> "#bijela"Kupio si kit popravaka imas ih %d! Kada ti treba fix koristi N!",PlayerInfo[playerid][Fix]);
                format(string2, (sizeof string2), ""#narancasta">> "#bijela"You bought reapir kit - You have %d kits! When you need fix use N!",PlayerInfo[playerid][Fix]);
                SCM(playerid, string1, string2);
			}
		}
		else if(listitem == 3) // FILL KIT 100,000 x15
		{
            if(GetPlayerMoneyEx(playerid) < 100000) return SCM(playerid, ""#siva"Nemas dovoljno novaca.", ""#siva"You don't have enought money.");
			else
			{
                GivePlayerMoneyEx(playerid, -100000);
                PlayerInfo[playerid][Fill] += (15);
                UpdatePlayer(playerid);
                format(string1, (sizeof string1), ""#narancasta">> "#bijela"Kupio si kit goriva imas ih %d! Kada ti treba gorivo koristi NUM4!",PlayerInfo[playerid][Fill]);
                format(string2, (sizeof string2), ""#narancasta">> "#bijela"You bought fuel kit - You have %d kits! When you need fuel use NUM4!",PlayerInfo[playerid][Fill]);
                SCM(playerid, string1, string2);
			}
		}
	}
	else if(dialogid == DIALOG_RADIO)
	{
	   if(!response) return StopAudioStreamForPlayer(playerid);
	   if(listitem == 0) // BALKAN DJ
	   {
          novost(GetName(playerid), "pusta radio (BalkanDJ)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://balkan.dj.topstream.net:8070/listen.pls");
	   }
	   else if(listitem == 1) // iLoveRadio
	   {
          novost(GetName(playerid), "pusta radio (iLoveRadio)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://www.iloveradio.de//listen.m3u");
	   }
	   else if(listitem == 2) // 24DubStep
	   {
          novost(GetName(playerid), "pusta radio (24DubStep)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://24dubstep.net/24dubstep.m3u");
	   }
	   else if(listitem == 3) // fun team radio
	   {
          novost(GetName(playerid), "pusta radio (fun team radio)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=342174");
	   }
	   else if(listitem == 4) // AZ HARDCORE
	   {
          novost(GetName(playerid), "pusta radio (AZ HARDCORE)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://cast1.serverhostingcenter.com/tunein.php/azhardcoreradio/playlist.pls");
	   }
	   else if(listitem == 5) // RADIO HS
	   {
          novost(GetName(playerid), "pusta radio (Radio HS)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=205578");
	   }
	   else if(listitem == 6) // Balkan Hip-Hop
	   {
          novost(GetName(playerid), "pusta radio (Balkan Hip-Hop)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1660804");
	   }
	   else if(listitem == 7) // RadioRock1
	   {
          novost(GetName(playerid), "pusta radio (RadioRock1)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=558051");
	   }
	   else if(listitem == 8) // Drum&Bass Heaven
	   {
          novost(GetName(playerid), "pusta radio (Drum&Bass Heaven)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=309786");
	   }
	   else if(listitem == 9) // Musik Drumstep
	   {
          novost(GetName(playerid), "pusta radio (Musik Drumstep)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=5415");
	   }
	   else if(listitem == 10) // Antena ZAGREB
	   {
          novost(GetName(playerid), "pusta radio (Antena Zagreb)");
          StopAudioStreamForPlayer(playerid);
          PlayAudioStreamForPlayer(playerid, "http://s7.iqstreaming.com/tunein.php/antenazagrebmp3/playlist.pls");
	   }
	}
	else if(dialogid == DIALOG_STORE_SELL)
	{
		   if(!response) {
		   CreateDialog(playerid,
		   DIALOG_STORE,
		   DIALOG_STYLE_LIST,
		   ""#error"Online ducan",
		   ""#zuta"(1): "#bijela"Kupi\n"#zuta"(2): "#bijela"Prodaj",
		   "Odaberi",
		   "Odustani",
		   ""#error"Online store", // ENGLISH
		   ""#zuta"(1): "#bijela"Buy stuff\n"#zuta"(2): "#bijela"Sell stuff",
		   "Choose",
		   "Cancel"); return (true); }
           if(listitem == 0) // RADIO $7,000
           {
			   if(!IsPlayerHaveRadio(playerid)) return SCM(playerid, ""#siva"Nemas radio.", ""#siva"You don't have a radio.");
			   else
			   {
                  novost(GetName(playerid), "je prodao svoj radio.");
				  GivePlayerRadio(playerid, false);
				  GivePlayerMoneyEx(playerid, 7000);
				  SCM(playerid, ""#bijela"Prodao si radio i dobio $7,000.", ""#bijela"You sell a radio for $7,000.");
			   }
           }
           else if(listitem == 1) // BOOST $10,000
           {
			   if(!IsPlayerHaveBoost(playerid)) return SCM(playerid, ""#siva"Nemas radio.", ""#siva"You don't have a radio.");
			   else
			   {
                  novost(GetName(playerid), "je prodao svoje ubrzanje");
				  GivePlayerBoost(playerid, false);
				  GivePlayerMoneyEx(playerid, 10000);
				  SCM(playerid, ""#bijela"Prodao si ubrzanje i dobio $10,000.", ""#bijela"You sell a boost for $10,000.");
			   }
           }
	}
	else if(dialogid == DIALOG_ADMIN_TELE)
	{
		if(!response) return (true);
		if(listitem == 0)
		{
			SFP_SetPlayerPos(playerid, 1881.8055,-2528.6833,13.5469); // LS
			SCM(playerid, ""#bijela"* Teleportiran si.", ""#bijela"* You teleported to Los Santos.");
		}
		else if(listitem == 1)
		{
			SFP_SetPlayerPos(playerid, -1259.0291,79.5006,14.1396); // sf
			SCM(playerid, ""#bijela"* Teleportiran si.", ""#bijela"* You teleported to San Fiero.");
		}
		else if(listitem == 2)
		{
			 SFP_SetPlayerPos(playerid,1319.1670,1261.7671,10.8203); // LV
			 SCM(playerid, ""#bijela"* Teleportiran si.", ""#bijela"* You teleported to Las Venturas.");
		}
		else if(listitem == 3) // area 51
		{
             SFP_SetPlayerPos(playerid,285.0164,1938.9041,17.6406); // area 51
			 SCM(playerid, ""#bijela"* Teleportiran si.", ""#bijela"* You teleported to Area 51.");
		}
	}
	else if(dialogid == DIALOG_HOUSE)
	{
		if(!response) return (true);
		new id, Float:Pos[3];
		GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
        
        mysql_format(mySQL, string1, (sizeof string1), "INSERT INTO `kuce`(h_Vlasnik)VALUES('-/-')");
    	mysql_pquery(mySQL, string1, "", "");
    	id = cache_insert_id();
    	
	    format(HouseInfo[id][h_Vlasnik], MAX_PLAYER_NAME, "-/-");
	    HouseInfo[id][h_Locked] = (1);
	    HouseInfo[id][h_Pi][0] = (Pos[0]);
	    HouseInfo[id][h_Pi][1] = (Pos[1]);
	    HouseInfo[id][h_Pi][2] = (Pos[2]);
	    if(listitem == 0) // mala
	    {
           HouseInfo[id][h_In][0] = (2496.2192);
		   HouseInfo[id][h_In][1] = (-1693.8173);
		   HouseInfo[id][h_In][2] = (1014.7422);
		   HouseInfo[id][h_Int] = (3);
		   HouseInfo[id][h_Vw] = (random(1500));
		   HouseInfo[id][h_Cijena] = (2500000);
	    }
	    else if(listitem == 1) // srednja
	    {
           HouseInfo[id][h_In][0] = (2196.4148);
		   HouseInfo[id][h_In][1] = (-1204.1061);
		   HouseInfo[id][h_In][2] = (1049.0234);
		   HouseInfo[id][h_Int] = (6);
		   HouseInfo[id][h_Vw] = (random(1500));
		   HouseInfo[id][h_Cijena] = (3500000);
	    }
	    else if(listitem == 2) // velika
	    {
           HouseInfo[id][h_In][0] = (234.199996);
		   HouseInfo[id][h_In][1] = (1064.900024);
		   HouseInfo[id][h_In][2] = (1084.199951);
		   HouseInfo[id][h_Int] = (6);
		   HouseInfo[id][h_Vw] = (random(1500));
		   HouseInfo[id][h_Cijena] = (5000000);
	    }
		UpdateHouse(id);
		UpdateHouseLabel(id);
	}
	else if(dialogid == DIALOG_VEHICLE_CAT)
	{
		if(!response) return (true);
		if(listitem == 0) // motori
		{
           new string[1024];
	       for(new i=400;i<600;i++)
 	       {
	         new modelid = motoriProdaja(i);
	         if(modelid != -1)
	         {
                 format(string, 1024, "%s"#narancasta"%s "#zelena"$%s\n",string,VehicleNames[modelid-400], convertNumber(motoriCijena(modelid), .iDelim = ","));
	         }
	       }
           CreateDialog(playerid,
           DIALOG_VEHICLE_MOTORI,
	       DIALOG_STYLE_LIST,
           ""#error"Kupi",
           string,
	       "Kupi", "Natrag",
           ""#error"Choose",
           string,
  	       "Buy", "Back");
		}
		else if(listitem == 1) // auti
		{
           new string[1024];
	       for(new i=400;i<474;i++)
 	       {
	         new modelid = autiProdaja(i);
	         if(modelid != -1)
	         {
                 format(string, 1024, "%s"#narancasta"%s "#zelena"$%s\n",string,VehicleNames[modelid-400], convertNumber(autiCijena(modelid), .iDelim = ","));
	         }
	       }
	       format(string, 1024, "%s\n"#error">> NEXT PAGE / IDUCA STRANA", string);
           CreateDialog(playerid,
           DIALOG_VEHICLE_AUTI,
	       DIALOG_STYLE_LIST,
           ""#error"Kupi",
           string,
	       "Odaberi", "Natrag",
           ""#error"Choose",
           string,
  	       "Choose", "Back");
		}
	}
	else if(dialogid == DIALOG_VEHICLE_AUTI)
	{
        if(!response) {
		return CreateDialog(playerid,
        DIALOG_VEHICLE_CAT,
	    DIALOG_STYLE_LIST,
        ""#error"Odaberi",
        ""#zuta"(1): "#bijela"Motori\n"#zuta"(2): "#bijela"Auti",
	    "Odaberi", "Odustani",
        ""#error"Choose",
        ""#zuta"(1): "#bijela"Motorcycles\n"#zuta"(2): "#bijela"Cars",
  	    "Accept", "Cancel"); }
  	    if(listitem == 0) return buyVehicle(playerid, 400, false);
  	    else if(listitem == 1) return buyVehicle(playerid, 401, false);
  	    else if(listitem == 2) return buyVehicle(playerid, 402, false);
  	    else if(listitem == 3) return buyVehicle(playerid, 404, false);
  	    else if(listitem == 4) return buyVehicle(playerid, 405, false);
  	    else if(listitem == 5) return buyVehicle(playerid, 410, false);
  	    else if(listitem == 6) return buyVehicle(playerid, 411, false);
  	    else if(listitem == 7) return buyVehicle(playerid, 412, false);
  	    else if(listitem == 8) return buyVehicle(playerid, 413, false);
  	    else if(listitem == 9) return buyVehicle(playerid, 415, false);
  	    else if(listitem == 10) return buyVehicle(playerid, 418, false);
  	    else if(listitem == 11) return buyVehicle(playerid, 419, false);
  	    else if(listitem == 12) return buyVehicle(playerid, 421, false);
  	    else if(listitem == 13) return buyVehicle(playerid, 422, false);
  	    else if(listitem == 14) return buyVehicle(playerid, 424, false);
  	    else if(listitem == 15) return buyVehicle(playerid, 426, false);
  	    else if(listitem == 16) return buyVehicle(playerid, 429, false);
  	    else if(listitem == 17) return buyVehicle(playerid, 434, false);
  	    else if(listitem == 18) return buyVehicle(playerid, 436, false);
  	    else if(listitem == 19) return buyVehicle(playerid, 439, false);
  	    else if(listitem == 20) return buyVehicle(playerid, 440, false);
  	    else if(listitem == 21) return buyVehicle(playerid, 444, false);
        else if(listitem == 22) return buyVehicle(playerid, 445, false);
        else if(listitem == 23) return buyVehicle(playerid, 451, false);
        else if(listitem == 24) return buyVehicle(playerid, 458, false);
        else if(listitem == 25) return buyVehicle(playerid, 459, false);
        else if(listitem == 26) return buyVehicle(playerid, 466, false);
        else if(listitem == 27) return buyVehicle(playerid, 467, false);
        else if(listitem == 28) return buyVehicle(playerid, 470, false);
		else if(listitem == 29) {
		new string[2048];
	    for(new i=473;i<611;i++)
        {
           new modelid = autiProdaja(i);
           if(modelid != -1)
	       {
              format(string, 2048, "%s"#narancasta"%s "#zelena"$%s\n",string,VehicleNames[modelid-400], convertNumber(autiCijena(modelid), .iDelim = ","));
	       }
	    }
        CreateDialog(playerid,
        DIALOG_VEHICLE_AUTI_2,
        DIALOG_STYLE_LIST,
        ""#error"Kupi",
        string,
        "Odaberi", "Natrag",
        ""#error"Choose",
        string,
        "Choose", "Back");
		}
	}
	else if(dialogid == DIALOG_VEHICLE_AUTI_2)
	{
		if(!response) {
		new string[1024];
        for(new i=400;i<474;i++)
        {
	       new modelid = autiProdaja(i);
	       if(modelid != -1)
           {
                 format(string, 1024, "%s"#narancasta"%s "#zelena"$%s\n",string,VehicleNames[modelid-400], convertNumber(autiCijena(modelid), .iDelim = ","));
	       }
	    }
        format(string, 1024, "%s\n"#error">> NEXT PAGE / IDUCA STRANA", string);
        CreateDialog(playerid,
        DIALOG_VEHICLE_AUTI,
        DIALOG_STYLE_LIST,
        ""#error"Kupi",
        string,
        "Odaberi", "Natrag",
        ""#error"Choose",
        string,
        "Choose", "Back"); }
        if(listitem == 0) return buyVehicle(playerid, 474, false);
        else if(listitem == 1) return buyVehicle(playerid, 475, false);
        else if(listitem == 2) return buyVehicle(playerid, 477, false);
        else if(listitem == 3) return buyVehicle(playerid, 478, false);
        else if(listitem == 4) return buyVehicle(playerid, 479, false);
        else if(listitem == 5) return buyVehicle(playerid, 480, false);
        else if(listitem == 6) return buyVehicle(playerid, 482, false);
        else if(listitem == 7) return buyVehicle(playerid, 483, false);
        else if(listitem == 8) return buyVehicle(playerid, 489, false);
        else if(listitem == 9) return buyVehicle(playerid, 491, false);
        else if(listitem == 10) return buyVehicle(playerid, 492, false);
        else if(listitem == 11) return buyVehicle(playerid, 494, false);
        else if(listitem == 12) return buyVehicle(playerid, 495, false);
        else if(listitem == 13) return buyVehicle(playerid, 496, false);
        else if(listitem == 14) return buyVehicle(playerid, 500, false);
        else if(listitem == 15) return buyVehicle(playerid, 506, false);
        else if(listitem == 16) return buyVehicle(playerid, 507, false);
        else if(listitem == 17) return buyVehicle(playerid, 516, false);
        else if(listitem == 18) return buyVehicle(playerid, 517, false);
        else if(listitem == 19) return buyVehicle(playerid, 518, false);
        else if(listitem == 20) return buyVehicle(playerid, 526, false);
        else if(listitem == 21) return buyVehicle(playerid, 527, false);
        else if(listitem == 22) return buyVehicle(playerid, 535, false);
        else if(listitem == 23) return buyVehicle(playerid, 540, false);
        else if(listitem == 24) return buyVehicle(playerid, 541, false);
        else if(listitem == 25) return buyVehicle(playerid, 542, false);
        else if(listitem == 26) return buyVehicle(playerid, 545, false);
        else if(listitem == 27) return buyVehicle(playerid, 547, false);
        else if(listitem == 28) return buyVehicle(playerid, 549, false);
        else if(listitem == 29) return buyVehicle(playerid, 550, false);
        else if(listitem == 30) return buyVehicle(playerid, 554, false);
        else if(listitem == 31) return buyVehicle(playerid, 555, false);
        else if(listitem == 32) return buyVehicle(playerid, 558, false);
        else if(listitem == 33) return buyVehicle(playerid, 559, false);
        else if(listitem == 34) return buyVehicle(playerid, 560, false);
        else if(listitem == 35) return buyVehicle(playerid, 561, false);
        else if(listitem == 36) return buyVehicle(playerid, 562, false);
        else if(listitem == 37) return buyVehicle(playerid, 565, false);
        else if(listitem == 38) return buyVehicle(playerid, 579, false);
        else if(listitem == 39) return buyVehicle(playerid, 580, false);
        else if(listitem == 40) return buyVehicle(playerid, 587, false);
        else if(listitem == 41) return buyVehicle(playerid, 589, false);
        else if(listitem == 42) return buyVehicle(playerid, 602, false);
        else if(listitem == 43) return buyVehicle(playerid, 603, false);
	}
	else if(dialogid == DIALOG_VEHICLE_MOTORI)
	{
		if(!response) {
		return CreateDialog(playerid,
        DIALOG_VEHICLE_CAT,
	    DIALOG_STYLE_LIST,
        ""#error"Odaberi",
        ""#zuta"(1): "#bijela"Motori\n"#zuta"(2): "#bijela"Auti",
	    "Odaberi", "Odustani",
        ""#error"Choose",
        ""#zuta"(1): "#bijela"Motorcycles\n"#zuta"(2): "#bijela"Cars",
  	    "Accept", "Cancel"); }
  	    if(listitem == 0) return buyVehicle(playerid, 448, true);
  	    else if(listitem == 1) return buyVehicle(playerid, 461, true);
  	    else if(listitem == 2) return buyVehicle(playerid, 462, true);
  	    else if(listitem == 3) return buyVehicle(playerid, 463, true);
  	    else if(listitem == 4) return buyVehicle(playerid, 468, true);
  	    else if(listitem == 5) return buyVehicle(playerid, 471, true);
  	    else if(listitem == 6) return buyVehicle(playerid, 481, true);
  	    else if(listitem == 7) return buyVehicle(playerid, 509, true);
  	    else if(listitem == 8) return buyVehicle(playerid, 510, true);
  	    else if(listitem == 9) return buyVehicle(playerid, 521, true);
  	    else if(listitem == 10) return buyVehicle(playerid, 522, true);
  	    else if(listitem == 11) return buyVehicle(playerid, 523, true);
  	    else if(listitem == 12) return buyVehicle(playerid, 581, true);
  	    else if(listitem == 13) return buyVehicle(playerid, 586, true);

	}
	else if(dialogid == DIALOG_PLAYER_KLIK)
	{
		if(!response) return (true);
		else if(response) return (true);
	}
	else if(dialogid == DIALOG_ADMINS)
    {
		if(!response) return (true);
		else if(response) return (true);
	}
	else if(dialogid == DIALOG_ADMIN_SETTINGS)
	{
		if(!response) return (true);
		if(listitem == 0) // ZADNJE PRIJAVE
		{
		   if(prijaveLog{playerid} == true) { prijaveLog{playerid} = (false); SCM(playerid, ""#bijela"* Pracenje prijava, iskljuceno!", ""); } else if(prijaveLog{playerid} == false) { prijaveLog{playerid} = (true); SCM(playerid, ""#bijela"* Pracenje prijava, ukljuceno!", ""); }
		}
		else if(listitem == 1) // ZADNJE RADNJE ADMINA
		{
           if(adminLog{playerid} == true) { adminLog{playerid} = (false); SCM(playerid, ""#bijela"* Pracenje admina, iskljuceno!", ""); } else if(adminLog{playerid} == false) { adminLog{playerid} = (true); SCM(playerid, ""#bijela"* Pracenje admina, ukljuceno!", ""); }
		}
		else if(listitem == 2) // ZADNJE PORUKE U ADMIN CHATU
		{
           if(pmLog{playerid} == true) { pmLog{playerid} = (false); SCM(playerid, ""#bijela"* Pracenje poruka, iskljuceno!", ""); } else if(pmLog{playerid} == false) { pmLog{playerid} = (true); SCM(playerid, ""#bijela"* Pracenje poruka, ukljuceno!", ""); }
		}
		else if(listitem == 3) // ZADNJE TRANSAKCIJE NOVCA
		{
           if(sendMoneyLog{playerid} == true) { sendMoneyLog{playerid} = (false); SCM(playerid, ""#bijela"* Pracenje transakcija, iskljuceno!", ""); } else if(sendMoneyLog{playerid} == false) { sendMoneyLog{playerid} = (true); SCM(playerid, ""#bijela"* Pracenje transakcija, ukljuceno!", ""); }
		}
		else if(listitem == 4) // MOGUCI CHEATERI
		{
           if(cheatLog{playerid} == true) { cheatLog{playerid} = (false); SCM(playerid, ""#bijela"* Pracenje cheatera, iskljuceno!", ""); } else if(cheatLog{playerid} == false) { cheatLog{playerid} = (true); SCM(playerid, ""#bijela"* Pracenje cheatera, ukljuceno!", ""); }
		}
	}
	else if(dialogid == DIALOG_NOVO_IME)
	{
        new avio_id = PlayerInfo[playerid][Vlasnik_Kompanije];
		if(!response) return (true);
		else if(strlen(inputtext) <= 3 || inputtext[0] == '\0') return SCM(playerid, ""#siva"Ime kompanije mora biti duzi od 3 znaka! Ne smije biti razmaka!", ""#siva"Name must be longer! Please without spacing!");
		else
		{
            format(AvioKompanija[avio_id][av_Ime], 24, "%s", inputtext);
			UpdateAirline(avio_id);
            SCM(playerid, ""#bijela"* Ime je uspjesno promjenjeno!", ""#bijela"* Name is now changed!");
		}
	}
	else if(dialogid == DIALOG_CREATE_AIRLINE)
	{
		new id = createAvio();
		if(!response) return (true);
		else if(strlen(inputtext) <= 3 || inputtext[0] == '\0') return SCM(playerid, ""#siva"Ime kompanije mora biti duzi od 3 znaka! Ne smije biti razmaka!", ""#siva"Name must be longer! Please without spacing!");
		else if(id == -1) return SCM(playerid, ""#siva"Ne mozes kreirati kompaniju! Kontaktiraj skriptera!", ""#siva"You can't create airline, contact server scripter about this problem!");
		else
		{
			format(AvioKompanija[id][av_Vlasnik], MAX_PLAYER_NAME, "%s", GetName(playerid));
			format(AvioKompanija[id][av_Ime], 24, "%s", inputtext);
			format(AvioKompanija[id][av_Zaposlenik_1], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_2], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_3], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_4], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_5], MAX_PLAYER_NAME, "-/-");
			AvioKompanija[id][av_Spawn][0] = (0.000); AvioKompanija[id][av_Spawn][1] = (0.000);
			AvioKompanija[id][av_Spawn][2] = (0.000); AvioKompanija[id][av_Spawn][3] = (0.000);
			AvioKompanija[id][av_Bodovi] = (0);
		    AvioKompanija[id][av_Novac] = (0);
		    AvioKompanija[id][av_Baza] = (0);
			PlayerInfo[playerid][AirlineUgovor] = (7200);
			PlayerInfo[playerid][Vlasnik_Kompanije] = (id);
			GivePlayerMoneyEx(playerid, -5000000);
			UpdatePlayer(playerid);
			AvioKompanija[id][av_Upgrade] = (0);
			format(AvioKompanija[id][av_Zaposlenik_6], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_7], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_8], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_9], MAX_PLAYER_NAME, "-/-");
			format(AvioKompanija[id][av_Zaposlenik_10], MAX_PLAYER_NAME, "-/-");
			AvioKompanija[id][av_Vozilo][0] = (-1); AvioKompanija[id][av_Vozilo][1] = (-1); AvioKompanija[id][av_Vozilo][2] = (-1);
			AvioKompanija[id][av_Vozilo][3] = (-1); AvioKompanija[id][av_Vozilo][4] = (-1); AvioKompanija[id][av_Vozilo][5] = (-1);
			AvioKompanija[id][av_Vozilo][6] = (-1); AvioKompanija[id][av_Vozilo][7] = (-1); AvioKompanija[id][av_Vozilo][8] = (-1);
			AvioKompanija[id][av_Vozilo][9] = (-1); AvioKompanija[id][av_Vozilo][10] = (-1); AvioKompanija[id][av_Vozilo][11] = (-1);
			AvioKompanija[id][av_Vozilo][12] = (-1); AvioKompanija[id][av_Vozilo][13] = (-1); AvioKompanija[id][av_Vozilo][14] = (-1);
			CreateAirline(id);
			
			format(string1, (sizeof string1), ""#narancasta"[INFO]: "#bijela"Uspjesno si kreirao avio kompaniju | IME: %s | Zaposlenika: 0 | Placa: 0 | Bodovi: 0", AvioKompanija[id][av_Ime]);
            format(string2, (sizeof string2), ""#narancasta"[INFO]: "#bijela"You have successfully created the airline | NAME: %s | Employee: 0 | Paycheck: 0 | Score: 0", AvioKompanija[id][av_Vlasnik]);
            SCM(playerid, string1, string2);
		}
	}
	else if(dialogid == DIALOG_AIRLINE)
	{
		if(!response) return (true);
		if(listitem == 0) // stats
		{
           new id = IsPlayerInAirline(playerid, GetName(playerid));
           format(string1, 512, ""#zelena"IME: "#bijela"%s\n"#zelena"VLASNIK: "#bijela"%s\n"#zelena"BODOVI: "#bijela"%s\n"#zelena"NOVAC: "#bijela"$%s",AvioKompanija[id][av_Ime], AvioKompanija[id][av_Vlasnik], convertNumber(AvioKompanija[id][av_Bodovi], .iDelim = ","), convertNumber(AvioKompanija[id][av_Novac], .iDelim = ","));
		   format(string2, 512, ""#zelena"NAME: "#bijela"%s\n"#zelena"OWNER: "#bijela"%s\n"#zelena"SCORES: "#bijela"%s\n"#zelena"MONEY: "#bijela"$%s",AvioKompanija[id][av_Ime], AvioKompanija[id][av_Vlasnik], convertNumber(AvioKompanija[id][av_Bodovi], .iDelim = ","), convertNumber(AvioKompanija[id][av_Novac], .iDelim = ","));
		   CreateDialog(playerid, DIALOG_AIRLINE_STATS, DIALOG_STYLE_MSGBOX, "Avio kompanija statistika", string1, "ZATVORI", "", "Airline stats", string2, "CLOSE", "");
		}
		else if(listitem == 1) // otkaz
		{
			CreateDialog(playerid, DIALOG_AIRLINE_OTKAZ, DIALOG_STYLE_MSGBOX, "Da ili ne?", ""#bijela"Jesi li siguran da zelis napustiti avio kompaniju?", "DA", "NE", "Yes or No?", ""#bijela"Are you sure you wanna leave this company?", "YES", "NO");
		}
		else if(listitem == 2) // spawn u bazi
		{
             new avio_id = IsPlayerInAirline(playerid, GetName(playerid));
		     if(AvioKompanija[avio_id][av_Baza] == 0) return SCM(playerid, ""#siva"* Tvoja avio kompanija jos nije kupila privatnu zracnu luku!", ""#siva"* Your airline don't have private airport!");
			 if(PlayerInfo[playerid][AvioSpawn] != 0)
			 {
				 PlayerInfo[playerid][AvioSpawn] = (0);
				 PlayerInfo[playerid][HouseSpawn] = (0);
				 SCM(playerid, ""#narancasta">> "#bijela"Od sada ces birati spawn ili ces se spawnti u svojoj kuci!", ""#narancasta">> "#bijela"You will choose spawn place now or you will be spawned in your house!");
				 UpdatePlayer(playerid);
			 }
			 else if(PlayerInfo[playerid][AvioSpawn] == 0)
			 {
                 new id = IsPlayerInAirline(playerid, GetName(playerid));
				 PlayerInfo[playerid][AvioSpawn] = (id);
				 PlayerInfo[playerid][HouseSpawn] = (0);
				 SCM(playerid, ""#narancasta">> "#bijela"Od sada ces se spawnti u avio kompaniji!", ""#narancasta">> "#bijela"Your spawn is now airline!");
				 UpdatePlayer(playerid);
			 }
		}
		else if(listitem == 3) // clanovi
		{
            new avio_id = IsPlayerInAirline(playerid, GetName(playerid));
            if(AvioKompanija[avio_id][av_Upgrade] <= 0)
			{
			    format(string1, (sizeof string1), ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5]);
			}
			else if(AvioKompanija[avio_id][av_Upgrade] == 1)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, (sizeof string1), ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 2)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s",string1,AvioKompanija[avio_id][av_Zaposlenik_7]);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 3)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s\n"#narancasta"8: "#bijela"%s\n",string1,AvioKompanija[avio_id][av_Zaposlenik_7],AvioKompanija[avio_id][av_Zaposlenik_8]);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 4)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s\n"#narancasta"8: "#bijela"%s\n"#narancasta"9: "#bijela"%s\n",string1,AvioKompanija[avio_id][av_Zaposlenik_7],AvioKompanija[avio_id][av_Zaposlenik_8],AvioKompanija[avio_id][av_Zaposlenik_9]);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 5)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s\n"#narancasta"8: "#bijela"%s\n"#narancasta"9: "#bijela"%s\n"#narancasta"10: "#bijela"%s",string1,AvioKompanija[avio_id][av_Zaposlenik_7],AvioKompanija[avio_id][av_Zaposlenik_8],AvioKompanija[avio_id][av_Zaposlenik_9],AvioKompanija[avio_id][av_Zaposlenik_10]);
            }
            CreateDialog(playerid, DIALOG_MEMBERS, DIALOG_STYLE_MSGBOX, ""#error"CLANOVI", string1, "Natrag", "", ""#error"MEMBERS", string1, "Back", "");
		}
		else if(listitem == 4) // daj novac kompaniji
		{
			 CreateDialog(playerid, DIALOG_DONIRAJ, DIALOG_STYLE_INPUT, ""#error"DONIRAJ", ""#bijela"Napisi iznos koji zelis staviti na racun kompanije", "DONIRAJ", "ZATVORI", ""#error"DONATE", ""#bijela"Write down the amount you want to donate", "DONATE", "CLOSE");
		}
	}
	else if(dialogid == DIALOG_DONIRAJ)
	{
		if(!response) return (true);
		new iznos = strval(inputtext);
		if(iznos <= 0) return SCM(playerid, ""#siva"* Iznos mora biti veci od nule!", ""#siva"* Amount must be more then 0!");
		else if(GetPlayerMoneyEx(playerid) < iznos) return SCM(playerid, ""#siva"* Nemas toliko novaca!", ""#siva"* You don't have that much money.");
		{
            new avio_id = IsPlayerInAirline(playerid, GetName(playerid));
            GivePlayerMoneyEx(playerid, -iznos);
            AvioKompanija[avio_id][av_Novac] += (iznos);
            format(string1, (sizeof string1), ""#narancasta">> "#bijela"Donirao si $%d u svoju kompaniju!", iznos);
            format(string2, (sizeof string2), ""#narancasta">> "#bijela"You just donate $%d your airline!", iznos);
            SCM(playerid, string1, string2);
            UpdateAirline(avio_id); UpdatePlayer(playerid);
		}
	}
	else if(dialogid == DIALOG_MEMBERS)
	{
		if(response || !response) return CreateDialog(playerid, DIALOG_AIRLINE, DIALOG_STYLE_LIST, ""#error"AVIO KOMPANIJA", ""#bijela"STATISTIKA\nDAJ OTKAZ\nSPAWNAJ ME U BAZI\nCLANOVI\nDONIRAJ KOMPANIJI", "OK", "Zatvori", ""#error"AIRLINE", ""#bijela"AIRLINE STATS\nLEAVE COMPANY\nSPAWN ME IN COMPANY AIRPORT\nMEMBERS\nDONATE TO AIRLINE", "OK", "CLOSE");
	}
	else if(dialogid == DIALOG_AIRLINE_OTKAZ)
	{
		if(response) // da
		{
            if(PlayerInfo[playerid][AirlineUgovor] >= 1) return SCM(playerid, ""#siva"* Ne mozes tako brzo napustiti kompaniju!", ""#siva"* You can't leave company so fast!");
			for(new a=0; a<=MAX_AIRLINES; ++a)
			{
				format(Data, (sizeof Data), AVIO_BAZA, a);
				if(fexist(Data))
				{
					if(PlayerInfo[playerid][Vlasnik_Kompanije] == a) return SCM(playerid, ""#siva"* Ne mozes napustiti avio kompaniju jer si vlasnik!", ""#siva"* You can't leave this company beacuse you own it.");
					if(strcmp(AvioKompanija[a][av_Zaposlenik_1], GetName(playerid), false) == 0)
					{
						 format(AvioKompanija[a][av_Zaposlenik_1], MAX_PLAYER_NAME, "-/-");
						 format(string1, (sizeof string1), ""#bijela"* Napusti si avio kompaniju %s!", AvioKompanija[a][av_Ime]);
                         format(string2, (sizeof string2), ""#bijela"* You just leave airline %s!", AvioKompanija[a][av_Ime]);
                         SCM(playerid, string1, string2);
                         UpdateAirline(a);
                         break;
					}
					else if(strcmp(AvioKompanija[a][av_Zaposlenik_2], GetName(playerid),false) == 0)
					{
                         format(AvioKompanija[a][av_Zaposlenik_2], MAX_PLAYER_NAME, "-/-");
                         format(string1, (sizeof string1), ""#bijela"* Napusti si avio kompaniju %s!", AvioKompanija[a][av_Ime]);
                         format(string2, (sizeof string2), ""#bijela"* You just leave airline %s!", AvioKompanija[a][av_Ime]);
                         SCM(playerid, string1, string2);
                         UpdateAirline(a);
                         break;
					}
					else if(strcmp(AvioKompanija[a][av_Zaposlenik_3], GetName(playerid),false) == 0)
					{
                         format(AvioKompanija[a][av_Zaposlenik_3], MAX_PLAYER_NAME, "-/-");
                         format(string1, (sizeof string1), ""#bijela"* Napusti si avio kompaniju %s!", AvioKompanija[a][av_Ime]);
                         format(string2, (sizeof string2), ""#bijela"* You just leave airline %s!", AvioKompanija[a][av_Ime]);
                         SCM(playerid, string1, string2);
                         UpdateAirline(a);
                         break;
					}
					else if(strcmp(AvioKompanija[a][av_Zaposlenik_4], GetName(playerid),false) == 0)
					{
                         format(AvioKompanija[a][av_Zaposlenik_4], MAX_PLAYER_NAME, "-/-");
                         format(string1, (sizeof string1), ""#bijela"* Napusti si avio kompaniju %s!", AvioKompanija[a][av_Ime]);
                         format(string2, (sizeof string2), ""#bijela"* You just leave airline %s!", AvioKompanija[a][av_Ime]);
                         SCM(playerid, string1, string2);
                         UpdateAirline(a);
                         break;
					}
					else if(strcmp(AvioKompanija[a][av_Zaposlenik_5], GetName(playerid),false) == 0)
					{
                        format(AvioKompanija[a][av_Zaposlenik_5], MAX_PLAYER_NAME, "-/-");
                        format(string1, (sizeof string1), ""#bijela"* Napusti si avio kompaniju %s!", AvioKompanija[a][av_Ime]);
                        format(string2, (sizeof string2), ""#bijela"* You just leave airline %s!", AvioKompanija[a][av_Ime]);
                        SCM(playerid, string1, string2);
                        UpdateAirline(a);
                        break;
					}
				}
			}
		}
		else if(!response) return (true);
	}
	else if(dialogid == DIALOG_EDIT_AIRLINE)
	{
		new avio_id = PlayerInfo[playerid][Vlasnik_Kompanije];
		if(!response) return (true);
		if(listitem == 0) // zaposlenici
		{
			if(AvioKompanija[avio_id][av_Upgrade] <= 0)
			{
			    format(string1, (sizeof string1), ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5]);
			}
			else if(AvioKompanija[avio_id][av_Upgrade] == 1)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, (sizeof string1), ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 2)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s",string1,AvioKompanija[avio_id][av_Zaposlenik_7]);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 3)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s\n"#narancasta"8: "#bijela"%s\n",string1,AvioKompanija[avio_id][av_Zaposlenik_7],AvioKompanija[avio_id][av_Zaposlenik_8]);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 4)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s\n"#narancasta"8: "#bijela"%s\n"#narancasta"9: "#bijela"%s\n",string1,AvioKompanija[avio_id][av_Zaposlenik_7],AvioKompanija[avio_id][av_Zaposlenik_8],AvioKompanija[avio_id][av_Zaposlenik_9]);
            }
            else if(AvioKompanija[avio_id][av_Upgrade] == 5)
			{
			   new z[MAX_PLAYER_NAME];
			   format(z, MAX_PLAYER_NAME, "%s", AvioKompanija[avio_id][av_Zaposlenik_6]);
			   format(string1, 128, ""#narancasta"1: "#bijela"%s\n"#narancasta"2: "#bijela"%s\n"#narancasta"3: "#bijela"%s\n"#narancasta"4: "#bijela"%s\n"#narancasta"5: "#bijela"%s\n"#narancasta"6: "#bijela"%s",AvioKompanija[avio_id][av_Zaposlenik_1],AvioKompanija[avio_id][av_Zaposlenik_2],AvioKompanija[avio_id][av_Zaposlenik_3],AvioKompanija[avio_id][av_Zaposlenik_4],AvioKompanija[avio_id][av_Zaposlenik_5],z);
			   format(string1, 256, "%s\n"#narancasta"7: "#bijela"%s\n"#narancasta"8: "#bijela"%s\n"#narancasta"9: "#bijela"%s\n"#narancasta"10: "#bijela"%s",string1,AvioKompanija[avio_id][av_Zaposlenik_7],AvioKompanija[avio_id][av_Zaposlenik_8],AvioKompanija[avio_id][av_Zaposlenik_9],AvioKompanija[avio_id][av_Zaposlenik_10]);
            }
			CreateDialog(playerid, DIALOG_LISTA, DIALOG_STYLE_LIST, "Zaposlenici", string1, "Otpusti", "Natrag", "Airline", string1, "Dismiss", "Back");
		}
		else if(listitem == 1) // promjeni ime
		{
			 CreateDialog(playerid, DIALOG_NOVO_IME, DIALOG_STYLE_INPUT, ""#bijela"NOVO IME", ""#bijela"Upisi novo ime avio kompanije", "OK", "ODUSTANI", ""#bijela"New name", ""#bijela"Type new name of airline", "OK", "CLOSE");
		}
		else if(listitem == 2) // zatvori kompaniju
		{
			 CreateDialog(playerid, DIALOG_AIRLINE_DELTE, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jesi li siguran da zelis zatvoriti svoju avio kompaniju?\nNeces dobiti nikakav novac!", "Da","Ne", "Are you sure?", ""#bijela"Are you sure you wanna delete your airline?\nYou will not get any money!", "Yes", "No");
		}
		else if(listitem == 3) // pozovi igraca u kompaniju
		{
			 CreateDialog(playerid, DIALOG_AIRLINE_INVITE, DIALOG_STYLE_INPUT, "Pozovi igraca u avio kompaniju", ""#bijela"Upisi ID igraca kojeg zelis pozvati", "Pozovi", "Odustani", "Invite player in airline", ""#bijela"Type ID of player that you wanna invite", "Invite", "Close");
		}
		else if(listitem == 4) // privatna zracna luka
		{
			 if(AvioKompanija[avio_id][av_Baza] != 0) return SCM(playerid, ""#siva"* Kompanija vec ima svoju vlastitu zracnu luku!", ""#siva"* This airline already have private airport!");
			 else if(AvioKompanija[avio_id][av_Novac] < 25000000 || AvioKompanija[avio_id][av_Bodovi] < 2000) return SCM(playerid, ""#siva"* Za kupnju zracne luke morate imati u kompaniji $25,000,000 i kompanija mora imati 2000+ bodova!", ""#siva"* You can't buy private airport! Airline bank account must have $25,000,000 and airline need to have 2000+ scores!");
			 else
			 {
				 AvioKompanija[avio_id][av_Novac] -= (25000000);
				 AvioKompanija[avio_id][av_Baza] = (1);
				 if(avio_id == 1)
			     {
                    AvioKompanija[avio_id][av_Spawn][0] = (-3505.4512);
			        AvioKompanija[avio_id][av_Spawn][1] = (776.5965);
			        AvioKompanija[avio_id][av_Spawn][2] = (4.2635);
			        AvioKompanija[avio_id][av_Spawn][3] = (265.9814);
			     }
			     else if(avio_id == 2)
			     {
                    AvioKompanija[avio_id][av_Spawn][0] = (3526.4758);
			        AvioKompanija[avio_id][av_Spawn][1] = (-2356.3479);
			        AvioKompanija[avio_id][av_Spawn][2] = (4.7205);
			        AvioKompanija[avio_id][av_Spawn][3] = (1.8857);
			     }
			     else if(avio_id == 3)
			     {
                    AvioKompanija[avio_id][av_Spawn][0] = (3242.5315);
			        AvioKompanija[avio_id][av_Spawn][1] = (-259.2365);
			        AvioKompanija[avio_id][av_Spawn][2] = (29.6724);
			        AvioKompanija[avio_id][av_Spawn][3] = (4.7760);
			     }
			     else if(avio_id == 4)
			     {
                    AvioKompanija[avio_id][av_Spawn][0] = (-2163.8809);
			        AvioKompanija[avio_id][av_Spawn][1] = (1765.7122);
			        AvioKompanija[avio_id][av_Spawn][2] = (1.7000);
			        AvioKompanija[avio_id][av_Spawn][3] = (82.0765);
			     }
			     else if(avio_id == 5)
			     {
                    AvioKompanija[avio_id][av_Spawn][0] = (811.7468);
			        AvioKompanija[avio_id][av_Spawn][1] = (-462.0352);
			        AvioKompanija[avio_id][av_Spawn][2] = (20.7770);
			        AvioKompanija[avio_id][av_Spawn][3] = (92.1264);
			     }
			     SCM(playerid, ""#narancasta">> "#bijela"Uspjesno si kupio zracnu luku za kompaniju! Na /company mozes namjestiti spawn u njoj!", ""#narancasta">> You bought private airport for your airline! Use /company to set spawn in airline airport!");
			 }
        }
        else if(listitem == 5) // vozila za kompaniju
        {
			if(AvioKompanija[avio_id][av_Baza] == 0) return SCM(playerid, ""#siva"* Kompanija mora imati svoju zracnu luku!", ""#siva"* Airline must have own airport!");
			else
			{
				format(string1, (sizeof string1), ""#zuta"Shamal "#zelena"($5,500,000)\n"#zuta"Dodo "#zelena"($3,500,000)\n"#zuta"Hydra "#zelena"($8,000,000)\n"#zuta"Maverick "#zelena"($4,000,000)");
				CreateDialog(playerid, DIALOG_AIRLINE_VEH, DIALOG_STYLE_LIST, ""#zelena"ODABERI", string1, "Kupi", "Natrag", ""#zelena"CHOOSE", string1, "Buy", "Back");
			}
        }
        else if(listitem == 6) // upgrade zaposlenika
        {
			if(AvioKompanija[avio_id][av_Upgrade] >= 5) return SCM(playerid, ""#siva"* Kompanija je maximalno nadogradena!", ""#siva"* You can't upgrade airline anymore!");
			else if(AvioKompanija[avio_id][av_Novac] < 2000000) return SCM(playerid, ""#siva"* Kompanija nema dovoljno novaca!", ""#siva"* Airline bank account don't have that much money!");
			else
			{
				CreateDialog(playerid, DIALOG_UPGRADE_AIRLINE, DIALOG_STYLE_MSGBOX, ""#zelena"NADOGRADNJA", ""#narancasta"Jeste li sigurni da zelite prosiriti slobodna\nmjesta u kompaniji? Cijena: $2,000,000 po jednom slotu!", "Da", "Ne", ""#zelena"UPGRADE", ""#narancasta"Are you sure you wanna upgrade airline company slots? Price: $2,000,000 by slot!", "Yes", "No");
			}
        }
        else if(listitem == 7) // inicijali
        {
			CreateDialog(playerid, DIALOG_INICIJALI, DIALOG_STYLE_INPUT, ""#bijela"AVIO-KOMPANIJA", ""#bijela"Upisi inicijale (MAX 2 ZNAKA!)", "Postavi", "Zatvori", ""#bijela"AIRLINE", ""#bijela"Type initials (MAX 2 CHARS!)", "Set", "Close");
        }
	}
	else if(dialogid == DIALOG_INICIJALI)
	{
		if(strlen(inputtext) > 2 || strlen(inputtext) < 2) return SCM(playerid, ""#bijela"* Inicijali kompanije moraju sadrzavati TOCNO 2 ZNAKA!", ""#bijela"* Use JUST 2 CHARS!");
		else
		{
			new NICK[1];
			GetPlayerName(playerid, NICK, 1);
			inputtext[0] = toupper(inputtext[0]); inputtext[1] = toupper(inputtext[1]);
            if(strcmp(NICK[0], "[", false) == 0) return SCM(playerid, ""#bijela"Ne mozes mijenjati inicijale!", ""#bijela"You can't change initials!");
            for(new a=0; a<=MAX_AIRLINES; ++a)
            {
				new set[5] = "\0";
				set[1] = toupper(set[1]); set[2] = toupper(set[2]);
				format(set, (sizeof set), "[%s]", inputtext);
				if(strcmp(AvioKompanija[a][av_Inicijali], set, false) == 0)
				{
					SCM(playerid, ""#bijela"* Neka kompanija vec koristi ove inicijale!", ""#bijela"Some other airline already use this initials!");
					break;
				}
            }
            if(inputtext[0] == '[' || inputtext[0] == ']' || inputtext[1] == '[' || inputtext[1] == ']')
			{
				return SCM(playerid, ""#bijela"* Inicijali kompanije ne smiju biti "#error"[ "#bijela"ili "#error"]", ""#bijela"* Airline initials can't be "#error"[ "#bijela"or "#error"]");
            }
            new avio_id = IsPlayerInAirline(playerid, GetName(playerid)), NICK___[MAX_PLAYER_NAME] = "\0";
			format(AvioKompanija[avio_id][av_Inicijali], 5, "[%s]", inputtext);
			UpdateAirline(avio_id);
			
			format(NICK___, MAX_PLAYER_NAME, "%s%s", AvioKompanija[avio_id][av_Inicijali], GetName(playerid));
			switch(SetPlayerName(playerid, NICK___))
            {
               case (-1): // NETKO IMA TO IME ONLINE
               {
				   SCM(playerid, ""#bijela"ERROR #1", ""#bijela"ERROR #1");
               }
               case (0): // VEC IMA TO IME
               {
				   SCM(playerid, ""#bijela"Kompanija vec ima svoje inicijale!", ""#bijela"Airline already have initials!");
               }
               case (1): // USPJESNO
               {
				   SCM(playerid, ""#narancasta">> "#bijela"Uspjesno si postavio inicijale!", ""#narancasta">> "#bijela"You successfully set airline initials!");
               }
            }
		}
	}
	else if(dialogid == DIALOG_AIRLINE_VEH)
	{
        new avio_id = PlayerInfo[playerid][Vlasnik_Kompanije], slot = IsAirlineHaveEmptyVehicleSlot(avio_id), Float:X, Float:Y, Float:Z, Float:ANG;
		if(!response)
		{
            if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		    {
			   format(string1, 256, ""#zelena"ZAPOSLENICI\n"#zuta"PROMJENI IME\n"#zelena"ZATVORI KOMPANIJU\n"#zuta"POZOVI IGRACA U KOMPANIJU\n");
			   format(string1, 512, "%s"#zelena"KUPI PRIVATNU ZRACNU LUKU\n"#zuta"KUPUJ VOZILA ZA KOMPANIJU\n"#zelena"UPGRADE KAPACITET ZAPOSLENIKA",string1);
		    }
		    else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		    {
               format(string1, 256, ""#zelena"Employees\n"#zuta"Change name\n"#zelena"Close this airline\n"#zuta"INVITE PLAYER IN AIRLINE\n");
			   format(string1, 512, "%s"#zelena"BUY PRIVATE AIRPORT\n"#zuta"BUY VEHICLES FOR AIRLINE\n"#zelena"UPGRADE EMPLOYEES AMOUNT",string1);
		    }
		    return CreateDialog(playerid, DIALOG_EDIT_AIRLINE, DIALOG_STYLE_LIST, ""#error"UREDI AVIO KOMPANIJU", string1, "OK", "ZATVORI", ""#error"EDIT AIRLINE", string1, "OK", "CLOSE");
		}
		if(listitem == 0) // SHAMAL ($5,500,000)
		{
			if(AvioKompanija[avio_id][av_Novac] < 5500000) return SCM(playerid, ""#siva"* Kompanija nema toliko novaca!", ""#siva"* Airline don't have that much money.");
			else if(slot == -1) return SCM(playerid, ""#siva"* Ova kompanija ne moze imati vise vozila!", ""#siva"* This airline can't have more vehicles!");
			else
			{
				new vehicleid = createVehID();
				AvioKompanija[avio_id][av_Vozilo][slot] = (vehicleid);
				if(avio_id == 1) { X = (-3505.4512); Y = (776.5965); Z = (4.2635); ANG = (265.9814); }
			    else if(avio_id == 2) { X = (3526.4758); Y = (-2356.3479); Z = (4.7205); ANG = (1.8857); }
			    else if(avio_id == 3) { X = (3242.5315); Y = (-259.2365); Z = (29.6724); ANG = (4.7760); }
                else if(avio_id == 4) { X = (-2163.8809); Y = (1765.7122); Z = (1.7000); ANG = (82.0765); }
                else if(avio_id == 4) { X = (811.7468); Y = (-462.0352); Z = (20.7770); ANG = (92.1264); }
				COS_VOZILA[vehicleid] = AddStaticVehicle(519, X, Y, Z, ANG, -1, -1);
			    format(CarInfo[COS_VOZILA[vehicleid]][v_Vlasnik], MAX_PLAYER_NAME, "-/-");
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][0] = (X); CarInfo[COS_VOZILA[vehicleid]][v_Pos][1] = (Y);
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][2] = (Z); CarInfo[COS_VOZILA[vehicleid]][v_Pos][3] = (ANG);
			    CarInfo[COS_VOZILA[vehicleid]][v_PaintJob] = (-1);
			    CarInfo[COS_VOZILA[vehicleid]][v_Posao] = (1);
			    CarInfo[COS_VOZILA[vehicleid]][v_Airline] = (avio_id);
			    CarInfo[COS_VOZILA[vehicleid]][v_Cijena] = (5500000);
			    CarInfo[COS_VOZILA[vehicleid]][v_Model] = (519);
			    AvioKompanija[avio_id][av_Vozilo][slot] = (COS_VOZILA[vehicleid]);
			    UpdateVehicle(COS_VOZILA[vehicleid]);
			    AvioKompanija[avio_id][av_Novac] -= (5500000);
			    UpdateAirline(avio_id);
			    SCM(playerid, ""#narancasta">> "#bijela"Avion je kupljen, na privatnoj pisti je!", ""#narancasta">> "#bijela"Plane was purchased, you can see it on airline airport!");
			}
		}
		else if(listitem == 1) // DODO ($3,500,000)
		{
            if(AvioKompanija[avio_id][av_Novac] < 3500000) return SCM(playerid, ""#siva"* Kompanija nema toliko novaca!", ""#siva"* Airline don't have that much money.");
            else if(slot == -1) return SCM(playerid, ""#siva"* Ova kompanija ne moze imati vise vozila!", ""#siva"* This airline can't have more vehicles!");
			else
			{
				new vehicleid = createVehID();
				AvioKompanija[avio_id][av_Vozilo][slot] = (vehicleid);
				if(avio_id == 1) { X = (-3505.4512); Y = (776.5965); Z = (4.2635); ANG = (265.9814); }
			    else if(avio_id == 2) { X = (3526.4758); Y = (-2356.3479); Z = (4.7205); ANG = (1.8857); }
			    else if(avio_id == 3) { X = (3242.5315); Y = (-259.2365); Z = (29.6724); ANG = (4.7760); }
                else if(avio_id == 4) { X = (-2163.8809); Y = (1765.7122); Z = (1.7000); ANG = (82.0765); }
                else if(avio_id == 4) { X = (811.7468); Y = (-462.0352); Z = (20.7770); ANG = (92.1264); }
				COS_VOZILA[vehicleid] = AddStaticVehicle(593, X, Y, Z, ANG, -1, -1);
			    format(CarInfo[COS_VOZILA[vehicleid]][v_Vlasnik], MAX_PLAYER_NAME, "-/-");
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][0] = (X); CarInfo[COS_VOZILA[vehicleid]][v_Pos][1] = (Y);
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][2] = (Z); CarInfo[COS_VOZILA[vehicleid]][v_Pos][3] = (ANG);
			    CarInfo[COS_VOZILA[vehicleid]][v_PaintJob] = (-1);
			    CarInfo[COS_VOZILA[vehicleid]][v_Posao] = (1);
			    CarInfo[COS_VOZILA[vehicleid]][v_Airline] = (avio_id);
			    CarInfo[COS_VOZILA[vehicleid]][v_Cijena] = (3500000);
			    CarInfo[COS_VOZILA[vehicleid]][v_Model] = (593);
			    AvioKompanija[avio_id][av_Vozilo][slot] = (COS_VOZILA[vehicleid]);
			    UpdateVehicle(COS_VOZILA[vehicleid]);
			    AvioKompanija[avio_id][av_Novac] -= (3500000);
			    UpdateAirline(avio_id);
			    SCM(playerid, ""#narancasta">> "#bijela"Avion je kupljen, na privatnoj pisti je!", ""#narancasta">> "#bijela"Plane was purchased, you can see it on airline airport!");
			}
		}
		else if(listitem == 2) // HYDRA ($8,000,000)
		{
            if(AvioKompanija[avio_id][av_Novac] < 8000000) return SCM(playerid, ""#siva"* Kompanija nema toliko novaca!", ""#siva"* Airline don't have that much money.");
            else if(slot == -1) return SCM(playerid, ""#siva"* Ova kompanija ne moze imati vise vozila!", ""#siva"* This airline can't have more vehicles!");
			else
			{
				new vehicleid = createVehID();
				AvioKompanija[avio_id][av_Vozilo][slot] = (vehicleid);
				if(avio_id == 1) { X = (-3505.4512); Y = (776.5965); Z = (4.2635); ANG = (265.9814); }
			    else if(avio_id == 2) { X = (3526.4758); Y = (-2356.3479); Z = (4.7205); ANG = (1.8857); }
			    else if(avio_id == 3) { X = (3242.5315); Y = (-259.2365); Z = (29.6724); ANG = (4.7760); }
                else if(avio_id == 4) { X = (-2163.8809); Y = (1765.7122); Z = (1.7000); ANG = (82.0765); }
                else if(avio_id == 4) { X = (811.7468); Y = (-462.0352); Z = (20.7770); ANG = (92.1264); }
				COS_VOZILA[vehicleid] = AddStaticVehicle(520, X, Y, Z, ANG, -1, -1);
			    format(CarInfo[COS_VOZILA[vehicleid]][v_Vlasnik], MAX_PLAYER_NAME, "-/-");
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][0] = (X); CarInfo[COS_VOZILA[vehicleid]][v_Pos][1] = (Y);
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][2] = (Z); CarInfo[COS_VOZILA[vehicleid]][v_Pos][3] = (ANG);
			    CarInfo[COS_VOZILA[vehicleid]][v_PaintJob] = (-1);
			    CarInfo[COS_VOZILA[vehicleid]][v_Airline] = (avio_id);
			    CarInfo[COS_VOZILA[vehicleid]][v_Posao] = (3);
			    CarInfo[COS_VOZILA[vehicleid]][v_Cijena] = (8000000);
			    CarInfo[COS_VOZILA[vehicleid]][v_Model] = (520);
			    AvioKompanija[avio_id][av_Vozilo][slot] = (COS_VOZILA[vehicleid]);
			    UpdateVehicle(COS_VOZILA[vehicleid]);
			    AvioKompanija[avio_id][av_Novac] -= (8000000);
			    UpdateAirline(avio_id);
			    SCM(playerid, ""#narancasta">> "#bijela"Avion je kupljen, na privatnoj pisti je!", ""#narancasta">> "#bijela"Plane was purchased, you can see it on airline airport!");
			}
		}
		else if(listitem == 3) // MAVERICK ($4,000,000)
		{
            if(AvioKompanija[avio_id][av_Novac] < 4000000) return SCM(playerid, ""#siva"* Kompanija nema toliko novaca!", ""#siva"* Airline don't have that much money.");
            else if(slot == -1) return SCM(playerid, ""#siva"* Ova kompanija ne moze imati vise vozila!", ""#siva"* This airline can't have more vehicles!");
			else
			{
				new vehicleid = createVehID();
				AvioKompanija[avio_id][av_Vozilo][slot] = (vehicleid);
				if(avio_id == 1) { X = (-3505.4512); Y = (776.5965); Z = (4.2635); ANG = (265.9814); }
			    else if(avio_id == 2) { X = (3526.4758); Y = (-2356.3479); Z = (4.7205); ANG = (1.8857); }
			    else if(avio_id == 3) { X = (3242.5315); Y = (-259.2365); Z = (29.6724); ANG = (4.7760); }
                else if(avio_id == 4) { X = (-2163.8809); Y = (1765.7122); Z = (1.7000); ANG = (82.0765); }
                else if(avio_id == 4) { X = (811.7468); Y = (-462.0352); Z = (20.7770); ANG = (92.1264); }
				COS_VOZILA[vehicleid] = AddStaticVehicle(487, X, Y, Z, ANG, -1, -1);
			    format(CarInfo[COS_VOZILA[vehicleid]][v_Vlasnik], MAX_PLAYER_NAME, "-/-");
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][0] = (X); CarInfo[COS_VOZILA[vehicleid]][v_Pos][1] = (Y);
			    CarInfo[COS_VOZILA[vehicleid]][v_Pos][2] = (Z); CarInfo[COS_VOZILA[vehicleid]][v_Pos][3] = (ANG);
			    CarInfo[COS_VOZILA[vehicleid]][v_PaintJob] = (-1);
			    CarInfo[COS_VOZILA[vehicleid]][v_Posao] = (2);
			    CarInfo[COS_VOZILA[vehicleid]][v_Airline] = (avio_id);
			    CarInfo[COS_VOZILA[vehicleid]][v_Cijena] = (4000000);
			    CarInfo[COS_VOZILA[vehicleid]][v_Model] = (487);
			    AvioKompanija[avio_id][av_Vozilo][slot] = (COS_VOZILA[vehicleid]);
			    UpdateVehicle(COS_VOZILA[vehicleid]);
			    AvioKompanija[avio_id][av_Novac] -= (4000000);
			    UpdateAirline(avio_id);
			    SCM(playerid, ""#narancasta">> "#bijela"Avion je kupljen, na privatnoj pisti je!", ""#narancasta">> "#bijela"Plane was purchased, you can see it on airline airport!");
			}
		}
	}
	else if(dialogid == DIALOG_UPGRADE_AIRLINE)
	{
		if(!response) return (true);
        new avio_id = PlayerInfo[playerid][Vlasnik_Kompanije];
		++AvioKompanija[avio_id][av_Upgrade];
		AvioKompanija[avio_id][av_Novac] -= (2000000);
		format(string1, (sizeof string1), ""#narancasta">> %s sada moze primiti %d ljudi!", AvioKompanija[avio_id][av_Ime], (AvioKompanija[avio_id][av_Upgrade]+5));
		format(string1, (sizeof string1), ""#narancasta">> %s now can receive %d workers!", AvioKompanija[avio_id][av_Ime], (AvioKompanija[avio_id][av_Upgrade]+5));
		SCM(playerid, string1, string2);
		UpdateAirline(avio_id);
	}
	else if(dialogid == DIALOG_AIRLINE_DELTE)
	{
		if(!response) return (true);
		format(Data, (sizeof Data), AVIO_BAZA, PlayerInfo[playerid][Vlasnik_Kompanije]);
		if(PlayerInfo[playerid][AirlineUgovor] >= 1) return SCM(playerid, ""#siva"* Ne mozes tako brzo zatvoriti kompaniju!", ""#siva"* You can't close company so fast!");
		if(fexist(Data))
		{
			for(new v=0; v<MAX_VEHICLES; v++)
			{
				if(CarInfo[v][v_Airline] == PlayerInfo[playerid][Vlasnik_Kompanije])
				{
					CarInfo[v][v_Airline] = (-1);
					CarInfo[v][v_Posao] = (-1);
					CarInfo[v][v_Pos][0] = (0.000); CarInfo[v][v_Pos][1] = (0.000);
					CarInfo[v][v_Pos][2] = (0.000); CarInfo[v][v_Pos][3] = (0.000);
				}
			}
			fremove(Data);
			SCM(playerid, ""#bijela"* Uspjesno si pobrisao kompaniju!", ""#bijela"* You have delete your airline!");
			PlayerInfo[playerid][Vlasnik_Kompanije] = (-1);
			UpdatePlayer(playerid);
		}
	}
	else if(dialogid == DIALOG_AIRLINE_INVITE)
	{
		new id = strval(inputtext);
		if(!response) return (true);
		else if(!IsPlayerConnected(strval(inputtext))) return SCM(playerid, ""#siva"* Pogresan player ID!", ""#siva"* Invalid player ID!");
		new avio_id = IsPlayerInAirline(id, GetName(id));
	    if(avio_id != -1) return SCM(playerid, ""#siva"* Taj igrac je vec u nekoj drugoj avio kompaniji!", ""#siva"* That player is already in other airline!");
		else if(av_call_vlasnik[strval(inputtext)] != INVALID_PLAYER_ID) return SCM(playerid, ""#siva"* Taj igrac vec ima neku pozivnicu.", ""#siva"* That player is already invited!");
		else
		{
			new avid = PlayerInfo[playerid][Vlasnik_Kompanije];
			if(strcmp(AvioKompanija[avid][av_Zaposlenik_1], "-/-", false) == 0 || strcmp(AvioKompanija[avid][av_Zaposlenik_2], "-/-", false) == 0  || strcmp(AvioKompanija[avid][av_Zaposlenik_3], "-/-", false) == 0  || strcmp(AvioKompanija[avid][av_Zaposlenik_4], "-/-", false) == 0  || strcmp(AvioKompanija[avid][av_Zaposlenik_5], "-/-", false) == 0)
			{
			   av_call_vlasnik[id] = (playerid);
			   av_call_avio{id} = (PlayerInfo[playerid][Vlasnik_Kompanije]);
		 	   av_call_time{id} = (20);
			
			   format(string1, (sizeof string1), ""#error"[KOMPANIJA]: "#bijela"Vlasnik kompanije '%s' %s te pozvao da se prikljucis u njegovu avio kompaniju! "#zelena"/accept "#bijela"da se prikljucis!", AvioKompanija[avid][av_Ime], GetName(playerid));
               format(string2, (sizeof string2), ""#error"[COMPANY]: "#bijela"Owner of company '%s' %s has invited you in airline! "#zelena"/accept "#bijela"if you want to join!", AvioKompanija[avid][av_Ime], GetName(playerid));
               SCM(id, string1, string2);
            
               format(string1, (sizeof string1), ""#bijela"* Dao si pozivnicu za ulazak u tvoju avio kompaniju igracu %s.",GetName(id));
               format(string2, (sizeof string2), ""#bijela"* You have successfully invited %s in your airline.", GetName(id));
               SCM(playerid, string1, string2);
               return (true);
			}
			else if(AvioKompanija[avid][av_Upgrade] == 1)
			{
               if(strcmp(AvioKompanija[avid][av_Zaposlenik_6], "-/-", false) == 0)
               {
                   av_call_vlasnik[id] = (playerid);
			       av_call_avio{id} = (PlayerInfo[playerid][Vlasnik_Kompanije]);
		 	       av_call_time{id} = (20);

			       format(string1, (sizeof string1), ""#error"[KOMPANIJA]: "#bijela"Vlasnik kompanije '%s' %s te pozvao da se prikljucis u njegovu avio kompaniju! "#zelena"/accept "#bijela"da se prikljucis!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   format(string2, (sizeof string2), ""#error"[COMPANY]: "#bijela"Owner of company '%s' %s has invited you in airline! "#zelena"/accept "#bijela"if you want to join!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   SCM(id, string1, string2);

                   format(string1, (sizeof string1), ""#bijela"* Dao si pozivnicu za ulazak u tvoju avio kompaniju igracu %s.",GetName(id));
                   format(string2, (sizeof string2), ""#bijela"* You have successfully invited %s in your airline.", GetName(id));
                   SCM(playerid, string1, string2);
                   return (true);
               }
			}
			else if(AvioKompanija[avid][av_Upgrade] == 2)
			{
               if(strcmp(AvioKompanija[avid][av_Zaposlenik_7], "-/-", false) == 0)
               {
                   av_call_vlasnik[id] = (playerid);
			       av_call_avio{id} = (PlayerInfo[playerid][Vlasnik_Kompanije]);
		 	       av_call_time{id} = (20);

			       format(string1, (sizeof string1), ""#error"[KOMPANIJA]: "#bijela"Vlasnik kompanije '%s' %s te pozvao da se prikljucis u njegovu avio kompaniju! "#zelena"/accept "#bijela"da se prikljucis!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   format(string2, (sizeof string2), ""#error"[COMPANY]: "#bijela"Owner of company '%s' %s has invited you in airline! "#zelena"/accept "#bijela"if you want to join!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   SCM(id, string1, string2);

                   format(string1, (sizeof string1), ""#bijela"* Dao si pozivnicu za ulazak u tvoju avio kompaniju igracu %s.",GetName(id));
                   format(string2, (sizeof string2), ""#bijela"* You have successfully invited %s in your airline.", GetName(id));
                   SCM(playerid, string1, string2);
                   return (true);
               }
			}
			else if(AvioKompanija[avid][av_Upgrade] == 3)
			{
               if(strcmp(AvioKompanija[avid][av_Zaposlenik_8], "-/-", false) == 0)
               {
                   av_call_vlasnik[id] = (playerid);
			       av_call_avio{id} = (PlayerInfo[playerid][Vlasnik_Kompanije]);
		 	       av_call_time{id} = (20);

			       format(string1, (sizeof string1), ""#error"[KOMPANIJA]: "#bijela"Vlasnik kompanije '%s' %s te pozvao da se prikljucis u njegovu avio kompaniju! "#zelena"/accept "#bijela"da se prikljucis!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   format(string2, (sizeof string2), ""#error"[COMPANY]: "#bijela"Owner of company '%s' %s has invited you in airline! "#zelena"/accept "#bijela"if you want to join!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   SCM(id, string1, string2);

                   format(string1, (sizeof string1), ""#bijela"* Dao si pozivnicu za ulazak u tvoju avio kompaniju igracu %s.",GetName(id));
                   format(string2, (sizeof string2), ""#bijela"* You have successfully invited %s in your airline.", GetName(id));
                   SCM(playerid, string1, string2);
                   return (true);
               }
			}
			else if(AvioKompanija[avid][av_Upgrade] == 4)
			{
               if(strcmp(AvioKompanija[avid][av_Zaposlenik_9], "-/-", false) == 0)
               {
                   av_call_vlasnik[id] = (playerid);
			       av_call_avio{id} = (PlayerInfo[playerid][Vlasnik_Kompanije]);
		 	       av_call_time{id} = (20);

			       format(string1, (sizeof string1), ""#error"[KOMPANIJA]: "#bijela"Vlasnik kompanije '%s' %s te pozvao da se prikljucis u njegovu avio kompaniju! "#zelena"/accept "#bijela"da se prikljucis!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   format(string2, (sizeof string2), ""#error"[COMPANY]: "#bijela"Owner of company '%s' %s has invited you in airline! "#zelena"/accept "#bijela"if you want to join!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   SCM(id, string1, string2);

                   format(string1, (sizeof string1), ""#bijela"* Dao si pozivnicu za ulazak u tvoju avio kompaniju igracu %s.",GetName(id));
                   format(string2, (sizeof string2), ""#bijela"* You have successfully invited %s in your airline.", GetName(id));
                   SCM(playerid, string1, string2);
                   return (true);
               }
			}
			else if(AvioKompanija[avid][av_Upgrade] == 5)
			{
               if(strcmp(AvioKompanija[avid][av_Zaposlenik_10], "-/-", false) == 0)
               {
                   av_call_vlasnik[id] = (playerid);
			       av_call_avio{id} = (PlayerInfo[playerid][Vlasnik_Kompanije]);
		 	       av_call_time{id} = (20);

			       format(string1, (sizeof string1), ""#error"[KOMPANIJA]: "#bijela"Vlasnik kompanije '%s' %s te pozvao da se prikljucis u njegovu avio kompaniju! "#zelena"/accept "#bijela"da se prikljucis!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   format(string2, (sizeof string2), ""#error"[COMPANY]: "#bijela"Owner of company '%s' %s has invited you in airline! "#zelena"/accept "#bijela"if you want to join!", AvioKompanija[avid][av_Ime], GetName(playerid));
                   SCM(id, string1, string2);

                   format(string1, (sizeof string1), ""#bijela"* Dao si pozivnicu za ulazak u tvoju avio kompaniju igracu %s.",GetName(id));
                   format(string2, (sizeof string2), ""#bijela"* You have successfully invited %s in your airline.", GetName(id));
                   SCM(playerid, string1, string2);
                   return (true);
               }
			}
			else return SCM(playerid, ""#siva"* Nemas slobodnog mjesta u kompaniji, otpusti nekoga!", ""#siva"* You have too much workers you can't call this player in airline.");
		}
	}
	else if(dialogid == DIALOG_LISTA)
	{
        new avio_id = PlayerInfo[playerid][Vlasnik_Kompanije];
		if(!response)
		{
            if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
		    {
			   format(string1, 256, ""#zelena"ZAPOSLENICI\n"#zuta"PROMJENI IME\n"#zelena"ZATVORI KOMPANIJU\n"#zuta"POZOVI IGRACA U KOMPANIJU\n");
			   format(string1, 512, "%s"#zelena"KUPI PRIVATNU ZRACNU LUKU\n"#zuta"KUPUJ VOZILA ZA KOMPANIJU\n"#zelena"UPGRADE KAPACITET ZAPOSLENIKA",string1);
		    }
		    else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
		    {
               format(string1, 256, ""#zelena"Employees\n"#zuta"Change name\n"#zelena"Close this airline\n"#zuta"INVITE PLAYER IN AIRLINE\n");
			   format(string1, 512, "%s"#zelena"BUY PRIVATE AIRPORT\n"#zuta"BUY VEHICLES FOR AIRLINE\n"#zelena"UPGRADE EMPLOYEES AMOUNT",string1);
		    }
		    return CreateDialog(playerid, DIALOG_EDIT_AIRLINE, DIALOG_STYLE_LIST, ""#error"UREDI AVIO KOMPANIJU", string1, "OK", "ZATVORI", ""#error"EDIT AIRLINE", string1, "OK", "CLOSE");
		}
		if(listitem == 0)
		{
		   if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_1], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (1);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 1)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_2], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (2);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 2)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_3], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (3);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 3)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_4], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (4);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 4)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_5], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (5);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 5)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_6], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (6);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 6)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_7], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (7);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 7)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_8], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (8);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 8)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_9], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (9);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
		else if(listitem == 9)
		{
           if(strcmp(AvioKompanija[avio_id][av_Zaposlenik_10], "-/-", false) == 0) return SCM(playerid, ""#siva"* U ovom slotu nema niti jednog zaposlenika!", ""#siva"* You choose empty slot! -/- is not employee!");
		   otkaz_slot{playerid} = (10);
		   CreateDialog(playerid, DIALOG_ZAPOSLENIK, DIALOG_STYLE_MSGBOX, "Jesi li siguran?", ""#bijela"Jeste li sigurni da zelite otpustiti ovog zaposlenika?", "Da", "Ne", "Are you sure?", ""#bijela"Are you sure you want dismiss this employee?", "Yes", "No");
		}
	}
	else if(dialogid == DIALOG_ZAPOSLENIK)
	{
        new avio_id = PlayerInfo[playerid][Vlasnik_Kompanije];
		if(!response) return otkaz_slot{playerid} = (0), (true);
		if(otkaz_slot{playerid} == 1)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_1], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_1], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 2)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_2], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_2], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 3)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_3], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_3], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 4)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_4], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_4], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 5)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_5], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_5], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 6)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_6], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_6], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 7)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_7], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_7], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 8)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_8], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_8], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 9)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_9], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_9], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
		else if(otkaz_slot{playerid} == 10)
		{
		    novost(AvioKompanija[avio_id][av_Zaposlenik_10], "je dobio otkaz u svojoj aviokompaniji.");
			format(AvioKompanija[avio_id][av_Zaposlenik_10], MAX_PLAYER_NAME, "-/-");
			UpdateAirline(avio_id);
			SCM(playerid, ""#bijela"* Uspjesno si otpustio radnika!", ""#bijela"* You have successfully dismiss worker!");
			otkaz_slot{playerid} = (0);
		}
	}
	return (true);
}

stock jobOdabir(playerid)
{
    anti_Kicker{playerid} = (true);
    PlayerTextDrawShow(playerid,posaoOdabir[playerid][0]);
    PlayerTextDrawShow(playerid,posaoOdabir[playerid][1]);
    PlayerTextDrawShow(playerid,posaoOdabir[playerid][2]);
    PlayerTextDrawShow(playerid,posaoOdabir[playerid][3]);
    SelectTextDraw(playerid, 0x0037FFFF);
    return (true);
}

stock errorCommand(playerid, level)
{
	new
	   string1[128] = "\0";
	if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
	{
		if(PlayerInfo[playerid][Admin] < level)
		{
		    format(string1, (sizeof string1), ""#error"[SERVER]: "#bijela"Samo administratori level %d smiju koristiti ovu komandu.", level);
		    SCM(playerid, string1,"");
		}
	}
	else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
	{
        if(PlayerInfo[playerid][Admin] < level)
		{
           format(string1, (sizeof string1), ""#error"[SERVER]: "#bijela"Just administrator with level %d can use this command.",level);
           SCM(playerid, "",string1);
        }
	}
	return (true);
}

stock UpdateHouseLabel(houseid)
{
    new string[256] = "\0", LOKACIJA[128] = "\0";
    Get2DZone(HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1],LOKACIJA,128);
    if(strcmp(HouseInfo[houseid][h_Vlasnik], "-/-", false) == 0) // PRODAJA
    {
       Delete3DTextLabel(HouseLabel[houseid]);
       DestroyDynamicPickup(HousePickup[houseid]);
       DestroyDynamicMapIcon(HouseIcon[houseid]);
	   format(string, sizeof(string),""#error"For Sale!\nPrice: "#zelena"$%d\n"#error"ID: "#zelena"%d",HouseInfo[houseid][h_Cijena], houseid);
	   HouseLabel[houseid] = Create3DTextLabel(string ,-1, HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1], HouseInfo[houseid][h_Pi][2]+0.75, 35, 0, 1);
	   HousePickup[houseid] = CreateDynamicPickup(1273, 1, HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1], HouseInfo[houseid][h_Pi][2]);
	   HouseIcon[houseid] = CreateDynamicMapIcon(HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1], HouseInfo[houseid][h_Pi][2], 31, 0, -1, -1, -1, 65);
    }
    else
    {
       Delete3DTextLabel(HouseLabel[houseid]);
       DestroyDynamicPickup(HousePickup[houseid]);
       DestroyDynamicMapIcon(HouseIcon[houseid]);
	   format(string, sizeof(string),""#error"Owner: "#zelena"%s\n"#error"Adress: "#zelena"%s\n"#error"ID: "#zelena"%d",HouseInfo[houseid][h_Vlasnik], LOKACIJA, houseid);
	   HouseLabel[houseid] = Create3DTextLabel(string , -1, HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1], HouseInfo[houseid][h_Pi][2]+0.75, 35, 0, 1);
	   HousePickup[houseid] = CreateDynamicPickup(1318, 1, HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1], HouseInfo[houseid][h_Pi][2]);
	   HouseIcon[houseid] = CreateDynamicMapIcon(HouseInfo[houseid][h_Pi][0], HouseInfo[houseid][h_Pi][1], HouseInfo[houseid][h_Pi][2], 32, 0, -1, -1, -1, 65);
    }
    return (true);
}

forward LoadCars(carid, name[], value[]);
public LoadCars(carid, name[], value[])
{
    INI_String("Vlasnik", CarInfo[carid][v_Vlasnik], MAX_PLAYER_NAME);
	INI_Float("Pozicija_X",CarInfo[carid][v_Pos][0]);
	INI_Float("Pozicija_Y",CarInfo[carid][v_Pos][1]);
	INI_Float("Pozicija_Z",CarInfo[carid][v_Pos][2]);
	INI_Float("Pozicija_ANG",CarInfo[carid][v_Pos][3]);
	INI_Int("Zakljucan", CarInfo[carid][v_Locked]);
	INI_Int("Model", CarInfo[carid][v_Model]);
	INI_Int("Cijena", CarInfo[carid][v_Cijena]);
	INI_Int("Boja_1", CarInfo[carid][v_Boja][0]);
	INI_Int("Boja_2", CarInfo[carid][v_Boja][1]);
	INI_Int("PaintJob", CarInfo[carid][v_PaintJob]);
	INI_Int("Airline", CarInfo[carid][v_Airline]);
	INI_Int("Posao", CarInfo[carid][v_Posao]);
	
	INI_Int("vMod1", vMods[carid][0]);
	INI_Int("vMod2", vMods[carid][1]);
	INI_Int("vMod3", vMods[carid][2]);
	INI_Int("vMod4", vMods[carid][3]);
	INI_Int("vMod5", vMods[carid][4]);
	INI_Int("vMod6", vMods[carid][5]);
	INI_Int("vMod7", vMods[carid][6]);
	INI_Int("vMod8", vMods[carid][7]);
	INI_Int("vMod9", vMods[carid][8]);
	INI_Int("vMod10", vMods[carid][9]);
	INI_Int("vMod11", vMods[carid][10]);
	INI_Int("vMod12", vMods[carid][11]);
    return (true);
}

stock UpdateVehicle(carid)
{
	format(Data, (sizeof Data), CAR_BAZA, carid);
	new INI:VEHICLE_ = INI_Open(Data);
	INI_WriteString(VEHICLE_, "Vlasnik", CarInfo[carid][v_Vlasnik]);
	INI_WriteFloat(VEHICLE_, "Pozicija_X",CarInfo[carid][v_Pos][0]);
	INI_WriteFloat(VEHICLE_, "Pozicija_Y",CarInfo[carid][v_Pos][1]);
	INI_WriteFloat(VEHICLE_, "Pozicija_Z",CarInfo[carid][v_Pos][2]);
	INI_WriteFloat(VEHICLE_, "Pozicija_ANG",CarInfo[carid][v_Pos][3]);
	INI_WriteInt(VEHICLE_, "Zakljucan", CarInfo[carid][v_Locked]);
	INI_WriteInt(VEHICLE_, "Model", CarInfo[carid][v_Model]);
	INI_WriteInt(VEHICLE_, "Cijena", CarInfo[carid][v_Cijena]);
	INI_WriteInt(VEHICLE_, "Boja_1", CarInfo[carid][v_Boja][0]);
	INI_WriteInt(VEHICLE_, "Boja_2", CarInfo[carid][v_Boja][1]);
	INI_WriteInt(VEHICLE_, "PaintJob", CarInfo[carid][v_PaintJob]);
	INI_WriteInt(VEHICLE_, "Airline", CarInfo[carid][v_Airline]);
	INI_WriteInt(VEHICLE_, "Posao", CarInfo[carid][v_Posao]);
	
	INI_WriteInt(VEHICLE_,"vMod1", vMods[carid][0]);
   	INI_WriteInt(VEHICLE_,"vMod2", vMods[carid][1]);
   	INI_WriteInt(VEHICLE_,"vMod3", vMods[carid][2]);
   	INI_WriteInt(VEHICLE_,"vMod4", vMods[carid][3]);
   	INI_WriteInt(VEHICLE_,"vMod5", vMods[carid][4]);
   	INI_WriteInt(VEHICLE_,"vMod6", vMods[carid][5]);
   	INI_WriteInt(VEHICLE_,"vMod7", vMods[carid][6]);
   	INI_WriteInt(VEHICLE_,"vMod8", vMods[carid][7]);
   	INI_WriteInt(VEHICLE_,"vMod9", vMods[carid][8]);
   	INI_WriteInt(VEHICLE_,"vMod10", vMods[carid][9]);
   	INI_WriteInt(VEHICLE_,"vMod11", vMods[carid][10]);
   	INI_WriteInt(VEHICLE_,"vMod12", vMods[carid][11]);
	INI_Close(VEHICLE_);
	return (true);
}

stock UpdateAirline(avio_id)
{
    format(Data, (sizeof Data), AVIO_BAZA, avio_id);
    if(!fexist(Data)) return (true);
	new INI:AVIO_ = INI_Open(Data);
	INI_WriteString(AVIO_, "Vlasnik", AvioKompanija[avio_id][av_Vlasnik]);
	INI_WriteString(AVIO_, "Ime", AvioKompanija[avio_id][av_Ime]);
	INI_WriteString(AVIO_, "Zaposlenik_1", AvioKompanija[avio_id][av_Zaposlenik_1]);
	INI_WriteString(AVIO_, "Zaposlenik_2", AvioKompanija[avio_id][av_Zaposlenik_2]);
	INI_WriteString(AVIO_, "Zaposlenik_3", AvioKompanija[avio_id][av_Zaposlenik_3]);
	INI_WriteString(AVIO_, "Zaposlenik_4", AvioKompanija[avio_id][av_Zaposlenik_4]);
	INI_WriteString(AVIO_, "Zaposlenik_5", AvioKompanija[avio_id][av_Zaposlenik_5]);
	INI_WriteInt(AVIO_, "Baza",AvioKompanija[avio_id][av_Baza]);
	INI_WriteInt(AVIO_, "Novac",AvioKompanija[avio_id][av_Novac]);
	INI_WriteFloat(AVIO_, "Spawn_X",AvioKompanija[avio_id][av_Spawn][0]);
	INI_WriteFloat(AVIO_, "Spawn_Y",AvioKompanija[avio_id][av_Spawn][1]);
	INI_WriteFloat(AVIO_, "Spawn_Z",AvioKompanija[avio_id][av_Spawn][2]);
	INI_WriteFloat(AVIO_, "Spawn_ANG",AvioKompanija[avio_id][av_Spawn][3]);
	INI_WriteInt(AVIO_, "Bodovi",AvioKompanija[avio_id][av_Bodovi]);
	INI_WriteInt(AVIO_, "Vozilo_1",AvioKompanija[avio_id][av_Vozilo][0]);
	INI_WriteInt(AVIO_, "Vozilo_2",AvioKompanija[avio_id][av_Vozilo][1]);
	INI_WriteInt(AVIO_, "Vozilo_3",AvioKompanija[avio_id][av_Vozilo][2]);
	INI_WriteInt(AVIO_, "Vozilo_4",AvioKompanija[avio_id][av_Vozilo][3]);
	INI_WriteInt(AVIO_, "Vozilo_5",AvioKompanija[avio_id][av_Vozilo][4]);
	INI_WriteInt(AVIO_, "Vozilo_6",AvioKompanija[avio_id][av_Vozilo][5]);
	INI_WriteInt(AVIO_, "Vozilo_7",AvioKompanija[avio_id][av_Vozilo][6]);
	INI_WriteInt(AVIO_, "Vozilo_8",AvioKompanija[avio_id][av_Vozilo][7]);
	INI_WriteInt(AVIO_, "Vozilo_9",AvioKompanija[avio_id][av_Vozilo][8]);
	INI_WriteInt(AVIO_, "Vozilo_10",AvioKompanija[avio_id][av_Vozilo][9]);
	INI_WriteInt(AVIO_, "Vozilo_11",AvioKompanija[avio_id][av_Vozilo][10]);
	INI_WriteInt(AVIO_, "Vozilo_12",AvioKompanija[avio_id][av_Vozilo][11]);
	INI_WriteInt(AVIO_, "Vozilo_13",AvioKompanija[avio_id][av_Vozilo][12]);
	INI_WriteInt(AVIO_, "Vozilo_14",AvioKompanija[avio_id][av_Vozilo][13]);
	INI_WriteInt(AVIO_, "Vozilo_15",AvioKompanija[avio_id][av_Vozilo][14]);
	INI_WriteInt(AVIO_, "Nadogradnja",AvioKompanija[avio_id][av_Upgrade]);
	INI_WriteString(AVIO_, "Zaposlenik_6", AvioKompanija[avio_id][av_Zaposlenik_6]);
	INI_WriteString(AVIO_, "Zaposlenik_7", AvioKompanija[avio_id][av_Zaposlenik_7]);
	INI_WriteString(AVIO_, "Zaposlenik_8", AvioKompanija[avio_id][av_Zaposlenik_8]);
	INI_WriteString(AVIO_, "Zaposlenik_9", AvioKompanija[avio_id][av_Zaposlenik_9]);
	INI_WriteString(AVIO_, "Zaposlenik_10", AvioKompanija[avio_id][av_Zaposlenik_10]);
	INI_WriteString(AVIO_, "Inicijali", AvioKompanija[avio_id][av_Inicijali]);
	INI_Close(AVIO_);
	return (true);
}

stock CreateAirline(avio_id)
{
    format(Data, (sizeof Data), AVIO_BAZA, avio_id);
	new INI:AVIO_ = INI_Open(Data);
	INI_WriteString(AVIO_, "Vlasnik", AvioKompanija[avio_id][av_Vlasnik]);
	INI_WriteString(AVIO_, "Ime", AvioKompanija[avio_id][av_Ime]);
	INI_WriteString(AVIO_, "Zaposlenik_1", AvioKompanija[avio_id][av_Zaposlenik_1]);
	INI_WriteString(AVIO_, "Zaposlenik_2", AvioKompanija[avio_id][av_Zaposlenik_2]);
	INI_WriteString(AVIO_, "Zaposlenik_3", AvioKompanija[avio_id][av_Zaposlenik_3]);
	INI_WriteString(AVIO_, "Zaposlenik_4", AvioKompanija[avio_id][av_Zaposlenik_4]);
	INI_WriteString(AVIO_, "Zaposlenik_5", AvioKompanija[avio_id][av_Zaposlenik_5]);
	INI_WriteInt(AVIO_, "Baza",AvioKompanija[avio_id][av_Baza]);
	INI_WriteInt(AVIO_, "Novac",AvioKompanija[avio_id][av_Novac]);
	INI_WriteFloat(AVIO_, "Spawn_X",AvioKompanija[avio_id][av_Spawn][0]);
	INI_WriteFloat(AVIO_, "Spawn_Y",AvioKompanija[avio_id][av_Spawn][1]);
	INI_WriteFloat(AVIO_, "Spawn_Z",AvioKompanija[avio_id][av_Spawn][2]);
	INI_WriteFloat(AVIO_, "Spawn_ANG",AvioKompanija[avio_id][av_Spawn][3]);
	INI_WriteInt(AVIO_, "Bodovi",AvioKompanija[avio_id][av_Bodovi]);
	INI_WriteInt(AVIO_, "Vozilo_1",AvioKompanija[avio_id][av_Vozilo][0]);
	INI_WriteInt(AVIO_, "Vozilo_2",AvioKompanija[avio_id][av_Vozilo][1]);
	INI_WriteInt(AVIO_, "Vozilo_3",AvioKompanija[avio_id][av_Vozilo][2]);
	INI_WriteInt(AVIO_, "Vozilo_4",AvioKompanija[avio_id][av_Vozilo][3]);
	INI_WriteInt(AVIO_, "Vozilo_5",AvioKompanija[avio_id][av_Vozilo][4]);
	INI_WriteInt(AVIO_, "Vozilo_6",AvioKompanija[avio_id][av_Vozilo][5]);
	INI_WriteInt(AVIO_, "Vozilo_7",AvioKompanija[avio_id][av_Vozilo][6]);
	INI_WriteInt(AVIO_, "Vozilo_8",AvioKompanija[avio_id][av_Vozilo][7]);
	INI_WriteInt(AVIO_, "Vozilo_9",AvioKompanija[avio_id][av_Vozilo][8]);
	INI_WriteInt(AVIO_, "Vozilo_10",AvioKompanija[avio_id][av_Vozilo][9]);
	INI_WriteInt(AVIO_, "Vozilo_11",AvioKompanija[avio_id][av_Vozilo][10]);
	INI_WriteInt(AVIO_, "Vozilo_12",AvioKompanija[avio_id][av_Vozilo][11]);
	INI_WriteInt(AVIO_, "Vozilo_13",AvioKompanija[avio_id][av_Vozilo][12]);
	INI_WriteInt(AVIO_, "Vozilo_14",AvioKompanija[avio_id][av_Vozilo][13]);
	INI_WriteInt(AVIO_, "Vozilo_15",AvioKompanija[avio_id][av_Vozilo][14]);
	INI_WriteInt(AVIO_, "Nadogradnja",AvioKompanija[avio_id][av_Upgrade]);
	INI_WriteString(AVIO_, "Zaposlenik_6", AvioKompanija[avio_id][av_Zaposlenik_6]);
	INI_WriteString(AVIO_, "Zaposlenik_7", AvioKompanija[avio_id][av_Zaposlenik_7]);
	INI_WriteString(AVIO_, "Zaposlenik_8", AvioKompanija[avio_id][av_Zaposlenik_8]);
	INI_WriteString(AVIO_, "Zaposlenik_9", AvioKompanija[avio_id][av_Zaposlenik_9]);
	INI_WriteString(AVIO_, "Zaposlenik_10", AvioKompanija[avio_id][av_Zaposlenik_10]);
	INI_WriteString(AVIO_, "Inicijali", AvioKompanija[avio_id][av_Inicijali]);
	INI_Close(AVIO_);
	return (true);
}

forward LoadAirlines(avio_id, name[], value[]);
public LoadAirlines(avio_id, name[], value[])
{
    INI_String("Vlasnik", AvioKompanija[avio_id][av_Vlasnik], MAX_PLAYER_NAME);
    INI_String("Ime", AvioKompanija[avio_id][av_Ime], 24);
    INI_String("Zaposlenik_1", AvioKompanija[avio_id][av_Zaposlenik_1], MAX_PLAYER_NAME);
    INI_String("Zaposlenik_2", AvioKompanija[avio_id][av_Zaposlenik_2], MAX_PLAYER_NAME);
    INI_String("Zaposlenik_3", AvioKompanija[avio_id][av_Zaposlenik_3], MAX_PLAYER_NAME);
    INI_String("Zaposlenik_4", AvioKompanija[avio_id][av_Zaposlenik_4], MAX_PLAYER_NAME);
    INI_String("Zaposlenik_5", AvioKompanija[avio_id][av_Zaposlenik_5], MAX_PLAYER_NAME);
    INI_Float("Spawn_X",AvioKompanija[avio_id][av_Spawn][0]);
    INI_Float("Spawn_Y",AvioKompanija[avio_id][av_Spawn][1]);
    INI_Float("Spawn_Z",AvioKompanija[avio_id][av_Spawn][2]);
    INI_Float("Spawn_ANG",AvioKompanija[avio_id][av_Spawn][3]);
    INI_Int("Bodovi", AvioKompanija[avio_id][av_Bodovi]);
    INI_Int("Baza",AvioKompanija[avio_id][av_Baza]);
	INI_Int("Novac",AvioKompanija[avio_id][av_Novac]);
	INI_Int("Vozilo_1",AvioKompanija[avio_id][av_Vozilo][0]);
	INI_Int("Vozilo_2",AvioKompanija[avio_id][av_Vozilo][1]);
	INI_Int("Vozilo_3",AvioKompanija[avio_id][av_Vozilo][2]);
	INI_Int("Vozilo_4",AvioKompanija[avio_id][av_Vozilo][3]);
	INI_Int("Vozilo_5",AvioKompanija[avio_id][av_Vozilo][4]);
	INI_Int("Vozilo_6",AvioKompanija[avio_id][av_Vozilo][5]);
	INI_Int("Vozilo_7",AvioKompanija[avio_id][av_Vozilo][6]);
	INI_Int("Vozilo_8",AvioKompanija[avio_id][av_Vozilo][7]);
	INI_Int("Vozilo_9",AvioKompanija[avio_id][av_Vozilo][8]);
	INI_Int("Vozilo_10",AvioKompanija[avio_id][av_Vozilo][9]);
	INI_Int("Vozilo_11",AvioKompanija[avio_id][av_Vozilo][10]);
	INI_Int("Vozilo_12",AvioKompanija[avio_id][av_Vozilo][11]);
	INI_Int("Vozilo_13",AvioKompanija[avio_id][av_Vozilo][12]);
	INI_Int("Vozilo_14",AvioKompanija[avio_id][av_Vozilo][13]);
	INI_Int("Vozilo_15",AvioKompanija[avio_id][av_Vozilo][14]);
	INI_Int("Nadogradnja",AvioKompanija[avio_id][av_Upgrade]);
	INI_String("Zaposlenik_6", AvioKompanija[avio_id][av_Zaposlenik_6], MAX_PLAYER_NAME);
	INI_String("Zaposlenik_7", AvioKompanija[avio_id][av_Zaposlenik_7], MAX_PLAYER_NAME);
	INI_String("Zaposlenik_8", AvioKompanija[avio_id][av_Zaposlenik_8], MAX_PLAYER_NAME);
	INI_String("Zaposlenik_9", AvioKompanija[avio_id][av_Zaposlenik_9], MAX_PLAYER_NAME);
	INI_String("Zaposlenik_10", AvioKompanija[avio_id][av_Zaposlenik_10], MAX_PLAYER_NAME);
	INI_String("Inicijali", AvioKompanija[avio_id][av_Inicijali], 5);
    return (true);
}

stock UpdateHouse(houseid)
{
	new Query[512] = "\0";
    mysql_format(mySQL, Query, (sizeof Query), "UPDATE `kuce` SET h_Vlasnik='%e',h_Pi_X='%f',h_Pi_Y='%f',h_Pi_Z='%f',h_In_X='%f',h_In_Y='%f' WHERE ID='%d'", HouseInfo[houseid][h_Vlasnik],HouseInfo[houseid][h_Pi][0],HouseInfo[houseid][h_Pi][1],HouseInfo[houseid][h_Pi][2],HouseInfo[houseid][h_In][0],HouseInfo[houseid][h_In][1],houseid);
    mysql_pquery(mySQL, Query, "", "");
    mysql_format(mySQL, Query, (sizeof Query), "UPDATE `kuce` SET h_Cijena='%d',h_Int='%d',h_Vw='%d',h_Locked='%d',h_In_Z='%f' WHERE ID='%d'",HouseInfo[houseid][h_Cijena],HouseInfo[houseid][h_Int],HouseInfo[houseid][h_Vw],HouseInfo[houseid][h_Locked],HouseInfo[houseid][h_In][2],houseid);
    mysql_pquery(mySQL, Query, "", "");
	return (true);
}

stock updateLokacija(playerid)
{
	new Float:pos[3], Query[128] = "\0";
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET trenutnaX='%f', trenutnaY='%f' WHERE Nick='%e'", pos[0], pos[1],GetName(playerid));
    mysql_pquery(mySQL, Query, "", "");
}

stock UpdatePlayer(playerid)
{
	new Query[1024] = "\0";
	if(PlayerLogin{playerid} == true)
	{
       mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Radio='%s',Ubrzanje='%s',Lozinka='%s',Admin='%d',Novac='%d' WHERE Nick='%s'", PlayerInfo[playerid][Radio],PlayerInfo[playerid][Ubrzanje],PlayerInfo[playerid][Lozinka],PlayerInfo[playerid][Admin],GetPlayerMoneyEx(playerid),GetName(playerid));
	   mysql_pquery(mySQL, Query, "", "");
       mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Registracija='%d',Zadnji_Login='%d',Bodovi='%d',Bodovi_1='%d',Bodovi_2='%d',Bodovi_3='%d' WHERE Nick='%s'",PlayerInfo[playerid][Registracija],PlayerInfo[playerid][Zadnji_Login],PlayerInfo[playerid][Bodovi],PlayerInfo[playerid][Bodovi_][0],PlayerInfo[playerid][Bodovi_][1],PlayerInfo[playerid][Bodovi_][2],GetName(playerid));
       mysql_pquery(mySQL, Query, "", "");
       mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Sati='%d',Minute='%d',Kljuc_Kuca='%d',Kljuc_Vozilo_1='%d',Kljuc_Vozilo_2='%d',Kljuc_Vozilo_3='%d',Zadnji_Login='%d' WHERE Nick='%s'",PlayerInfo[playerid][Sati],PlayerInfo[playerid][Minute],PlayerInfo[playerid][Kljuc_Kuca],PlayerInfo[playerid][Kljuc_Vozilo][0],PlayerInfo[playerid][Kljuc_Vozilo][1],PlayerInfo[playerid][Kljuc_Vozilo][2],PlayerInfo[playerid][Zadnji_Login],GetName(playerid));
       mysql_pquery(mySQL, Query, "", "");
	   mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Logiran='%d',Tankirao_1='%d',Tankirao_2='%d',Popravio_1='%d',Popravio_2='%d',Smrt='%d',Prekid='%d' WHERE Nick='%s'",PlayerInfo[playerid][Logiran],PlayerInfo[playerid][Tankirao][0],PlayerInfo[playerid][Tankirao][1],PlayerInfo[playerid][Popravio][0],PlayerInfo[playerid][Popravio][1],PlayerInfo[playerid][Smrt],PlayerInfo[playerid][Prekid],GetName(playerid));
       mysql_pquery(mySQL, Query, "", "");
	   mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Pozicija_X='%f',Pozicija_Y='%f',Pozicija_Z='%f',Vip='%d',HouseSpawn='%d',Vlasnik_Kompanije='%d' ,Upozorenja='%d',Pohvale='%d' WHERE Nick='%s'",PlayerInfo[playerid][Pozicija][0],PlayerInfo[playerid][Pozicija][1],PlayerInfo[playerid][Pozicija][2],PlayerInfo[playerid][Vip],PlayerInfo[playerid][HouseSpawn],PlayerInfo[playerid][Vlasnik_Kompanije],PlayerInfo[playerid][Upozorenja],PlayerInfo[playerid][Pohvale],GetName(playerid));
	   mysql_pquery(mySQL, Query, "", "");
       mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Nevada='%d',At400s='%d',Andromada='%d',Vip_Vrijeme='%d',Fix='%d',Fill='%d',AvioSpawn='%d' WHERE Nick='%s'",PlayerInfo[playerid][Nevada],PlayerInfo[playerid][At400s],PlayerInfo[playerid][Andromada],PlayerInfo[playerid][Vip_Vrijeme],PlayerInfo[playerid][Fix],PlayerInfo[playerid][Fill],PlayerInfo[playerid][AvioSpawn],GetName(playerid));
       mysql_pquery(mySQL, Query, "", "");
	   mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET AirlineUgovor='%d',Shamal='%d',Dodo='%d',Beagle='%d',Hydra='%d' WHERE Nick='%s'",Query,PlayerInfo[playerid][AirlineUgovor],PlayerInfo[playerid][Dodo],PlayerInfo[playerid][Beagle],PlayerInfo[playerid][Hydra],GetName(playerid));
	   mysql_pquery(mySQL, Query, "", "");
	}
	return (true);
}

stock OnPlayerRegister(playerid, lozinka[])
{
	format(PlayerInfo[playerid][Nick], MAX_PLAYER_NAME, "%s", GetName(playerid));
	format(PlayerInfo[playerid][Radio], 3, "Ne");
	format(PlayerInfo[playerid][Ubrzanje], 3, "Ne");
	PlayerInfo[playerid][Zadnji_Login] = 0;
	PlayerInfo[playerid][Registracija] = gettime();
	format(PlayerInfo[playerid][Lozinka], 200, "%s", lozinka);
	PlayerInfo[playerid][HouseSpawn] = (0); PlayerInfo[playerid][Vlasnik_Kompanije] = (-1);
	PlayerInfo[playerid][Kljuc_Kuca] = (INVALID_HOUSE_ID);
	PlayerInfo[playerid][Vip_Vrijeme] = 0;  PlayerInfo[playerid][Fix] = (0); PlayerInfo[playerid][Fill] = (0);
	PlayerInfo[playerid][Kljuc_Vozilo][0] = (INVALID_CAR_ID); PlayerInfo[playerid][Kljuc_Vozilo][1] = (INVALID_CAR_ID); PlayerInfo[playerid][Kljuc_Vozilo][2] = (INVALID_CAR_ID);
    PlayerInfo[playerid][Bodovi_][0] = (0); PlayerInfo[playerid][Bodovi_][1] = (0); PlayerInfo[playerid][Bodovi] = (0);
	PlayerInfo[playerid][Vip] = (0); PlayerInfo[playerid][Novac] = (0); PlayerInfo[playerid][Bodovi_][2] = (0);
	PlayerInfo[playerid][Pozicija][0] = (0.000); PlayerInfo[playerid][Pozicija][1] = (0.000); PlayerInfo[playerid][Pozicija][2] = (0.000);
	PlayerInfo[playerid][Logiran] ++; PlayerInfo[playerid][AvioSpawn] = (0); PlayerInfo[playerid][AirlineUgovor] = (0);
	PlayerInfo[playerid][Sati] = (0); PlayerInfo[playerid][Minute] = (0); PlayerInfo[playerid][Smrt] = (0); PlayerInfo[playerid][Prekid] = (0);
	PlayerInfo[playerid][Shamal] = (0); PlayerInfo[playerid][Dodo] = (0); PlayerInfo[playerid][Beagle] = (0); PlayerInfo[playerid][Hydra] = (0);
	PlayerInfo[playerid][Nevada] = (0); PlayerInfo[playerid][At400s] = (0); PlayerInfo[playerid][Andromada] = (0);

    new Query[1000] = "\0";
    mysql_format(mySQL, Query, (sizeof Query), "INSERT INTO `korisnici`(Nick,Email,Lozinka,Spol,Grupa,Iskljucen,Admin,Novac,Radio,Ubrzanje)VALUES('%e','%e',MD5('%e'),'0','0','0','0',0,'Ne','Ne')",PlayerInfo[playerid][Nick],PlayerInfo[playerid][Email],PlayerInfo[playerid][Lozinka]);
    mysql_pquery(mySQL, Query, "", "");
    mysql_format(mySQL, Query, (sizeof Query), "UPDATE `korisnici` SET Zadnji_Login='%d',Registracija='%d',Vlasnik_Kompanije='%d',Kljuc_Kuca='%d',Kljuc_Vozilo_1='%d',Kljuc_Vozilo_2='%d',Kljuc_Vozilo_3='%d' WHERE Nick='%e'",0,PlayerInfo[playerid][Registracija],PlayerInfo[playerid][Vlasnik_Kompanije],PlayerInfo[playerid][Kljuc_Kuca],PlayerInfo[playerid][Kljuc_Vozilo][0],PlayerInfo[playerid][Kljuc_Vozilo][1],PlayerInfo[playerid][Kljuc_Vozilo][2],GetName(playerid));
    mysql_pquery(mySQL, Query, "", "");
	
    mysql_format(mySQL, Query, (sizeof Query), "SELECT Lozinka FROM `korisnici` WHERE `Nick`='%e' LIMIT 1;", GetName(playerid));
    mysql_pquery(mySQL, Query, "DohvatiLozinku", "i", playerid);
    
    CreateDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, "Server For Pilots - Email", "Unesite svoju email adresu!","DALJE","","Server For Pilots - Email","Enter your email address","NEXT","");
	return (true);
}

stock GivePlayerRadio(playerid, bool:daj_uzmi)
{
	if(daj_uzmi == true) // daj
	{
	   format(PlayerInfo[playerid][Radio], 3, "Da");
	}
	else if(daj_uzmi == false) // uzmi
	{
       format(PlayerInfo[playerid][Radio], 3, "Ne");
	}
	return (true);
}

forward ProvjeriRacun(playerid);
public ProvjeriRacun(playerid)
{
	new string1[400] = "\0", string2[400] = "\0";
    if(cache_num_rows() != 0)
    {
	   format(string1, (sizeof string1), "                                         {340000}DOBRODO�AO NATRAG %s!\n{79B4B1}MOLIM VAS DA UNESETE LOZINKU KOJU STE IZABRALI NA REGISTRACIJI KAKO\nBI MOGLI PRISTUPITI SVOJIM PODACIMA TJ. KAKO BI MOGLI NASTAVITI SA\nIGROM! U SLU�AJU BILO KAKVIH PROBLEMA ILI PITANJA S VEZI SERVERA\nKONTAKTIRAJTE NA�U ADMINISTRACIJU!\n",GetName(playerid));
	   format(string2, (sizeof string2), "                                         {340000}WELCOME BACK %s!\n{79B4B1}PLEASE ENTER THE PASSWORD THAT YOU CHOOSE ON REGISTRATION TO BE\nABLE TO ACCESS YOUR SETTINGS, IN ORDER TO COUNTINUE WITH THE GAME!\nIN CASE OF ANY PROBLEMS PLEASE CONTACT OUR ADMINISTRATION!\n",GetName(playerid));
       CreateDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Server For Pilots", string1,"DALJE","","Server For Pilots",string2,"NEXT","");
    }
    else if(cache_num_rows() == 0)
    {
	   format(string1, (sizeof string1), "                                         {340000}DOBRODO�AO NA SERVER %s!\n{79B4B1}TVOJ NICK NIJE REGISTRIRAN NA OVOM SERVERU PA �E� GA SADA MORATI\nREGISTRIRATI! ODABERI LOZINKU KOJU �ELI� I UKUCAJ JE OVDJE, PAZI DA\nSTAVI� LOZINKU KOJU �E� ZAPAMTITI! \n{950000}NAPOMENA: LOZINKU KOJU SADA UPI�ETE NE�EMO JAVNO OBJAVLJIVATI NITI\n�E VAS NA�A ADMINISTRACIJA IKADA TRA�ITI DA NAM JE KA�E�!\n",GetName(playerid));
	   format(string2, (sizeof string2), "                                        {340000}WELCOME TO THE SERVER %s!\n{79B4B1}YOUR NAME IS NOT REGISTERED IN OUR DATABASE, YOU MUST REGISTER\nYOUR NAME NOW! SELECT THE PASSWORD YOU WANT AND TYPE IN IS HERE,\nKEEP THE REMEMBER!\n{950000}NOTE: PASSWORD THAT YOU ENROLL WE WILL NOT PUBLISH AND OUR\nADMINISTRATION WILL NEVER ASK FOR!\n",GetName(playerid));
       CreateDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Server For Pilots", string1,"DALJE","","Server For Pilots",string2,"NEXT","");
    }
	return (true);
}

stock CheckAccount(playerid)
{
    new Query[128] = "\0";
    mysql_format(mySQL, Query, (sizeof Query), "SELECT `Nick` FROM `korisnici` WHERE `Nick` = '%e' LIMIT 1;", GetName(playerid));
    mysql_pquery(mySQL, Query, "ProvjeriRacun", "i", playerid);
	return (true);
}

stock novost(const nick[], const novost[])
{
	new Query[256] = "\0";
    mysql_format(mySQL, Query, (sizeof Query), "INSERT INTO `novosti`(Nick,Novost,Vrijeme)VALUES('%e','%e','%d')", nick, novost, gettime());
    mysql_pquery(mySQL, Query, "", "");
	return (true);
}

stock GetSpeed(playerid)
{
	new
	   vehicle = GetPlayerVehicleID(playerid),
	   Float:speed_x,Float:speed_y,Float:speed_z,Float:Brzina;
    GetVehicleVelocity(vehicle,speed_x,speed_y,speed_z);
    Brzina = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*176.666667;
	return floatround(Brzina,floatround_round);
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	new Float:Pos[3], string[30];
	GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
	if(BigMission(vehicleid) == true)
	{
		 if(Team{playerid} >= 1 && Team{playerid} <= 3 && GetPlayerScore(playerid) >= 400)
		 {
			 SCM(playerid, ""#narancasta">> "#bijela"Sa ovim avionom nece biti lako stici do cilja!", ""#narancasta">> With this plane will not be easy to reach the goal!");
		 }
		 else
		 {
             SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
             GameText(playerid, "~r~Samo piloti ~n~sa 400+ bodova!", "~r~Just pilots ~n~with 400+ scores!", 2500, 3);
		 }
	}
	if(IsACosVeh(vehicleid))
    {
	  for(new i=0;i<3;++i)
	  {
		if(CarInfo[vehicleid][v_Airline] == -1)
		{
		   if(CarInfo[vehicleid][v_Locked] == 1 && PlayerInfo[playerid][Kljuc_Vozilo][i] != vehicleid)
		   {
              SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
              GameText(playerid, "~r~Vozilo zakljucano!", "~r~Vehicle locked!", 1000, 3);
		   }
		   else if(CarInfo[vehicleid][v_Locked] == 1 && PlayerInfo[playerid][Kljuc_Vozilo][i] == vehicleid)
		   {
			  format(string, (sizeof string), ""#bijela"* %s", CarInfo[vehicleid][v_Vlasnik]);
			  SCM(playerid, string, string);
			  break;
		   }
        }
        else if(CarInfo[vehicleid][v_Airline] != -1)
        {
            new avio_id = IsPlayerInAirline(playerid, GetName(playerid));
			if(CarInfo[vehicleid][v_Airline] != avio_id)
			{
                SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
                GameText(playerid, "~r~Vozilo zakljucano!", "~r~Vehicle locked!", 1000, 3);
			}
        }
	  }
    }
	if(Team{playerid} == 1) // CIVILNI PILOT
	{
	   if(MedicinskiAvion(vehicleid))
	   {
		  SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo medicinski piloti!", "~r~Just medical pilots!", 1000, 3);
	   }
	   else if(VojniAvion(vehicleid) || VojniHeli(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vojni piloti!", "~r~Just military pilots!", 1000, 3);
	   }
	   else if(TaxiAuto(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci taksija!", "~r~Just Taxi drivers!", 1000, 3);
	   }
	   else if(Truck(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci kamiona!", "~r~Just Truck drivers!", 1000, 3);
	   }
	   else if(IsABoat(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo moreplovci!", "~r~Just for sailors!", 1000, 3);
	   }
	}
	else if(Team{playerid} == 2) // MEDICINSKI PILOT
	{
	   if(VojniAvion(vehicleid) || VojniHeli(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vojni piloti!", "~r~Just military pilots!", 1000, 3);
	   }
	   else if(TaxiAuto(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci taksija!", "~r~Just Taxi drivers!", 1000, 3);
	   }
	   else if(Truck(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci kamiona!", "~r~Just Truck drivers!", 1000, 3);
	   }
	   else if(IsABoat(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo moreplovci!", "~r~Just for sailors!", 1000, 3);
	   }
	}
	else if(Team{playerid} == 2) // VOJNI PILOT
	{
	   if(TaxiAuto(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci taksija!", "~r~Just Taxi drivers!", 1000, 3);
	   }
	   else if(Truck(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci kamiona!", "~r~Just Truck drivers!", 1000, 3);
	   }
	   else if(IsABoat(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo moreplovci!", "~r~Just for sailors!", 1000, 3);
	   }
	}
	else if(Team{playerid} == 4) // TAXI VOZACI
	{
       if(CivilniAvion(vehicleid))
       {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo piloti!", "~r~Just pilots!", 1000, 3);
       }
       else if(MedicinskiAvion(vehicleid))
	   {
		  SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo medicinski piloti!", "~r~Just medical pilots!", 1000, 3);
	   }
	   else if(VojniAvion(vehicleid) || VojniHeli(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vojni piloti!", "~r~Just military pilots!", 1000, 3);
	   }
	   else if(Truck(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci kamiona!", "~r~Just Truck drivers!", 1000, 3);
	   }
	   else if(IsABoat(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo moreplovci!", "~r~Just for sailors!", 1000, 3);
	   }
	}
	else if(Team{playerid} == 6) // VOZACI KAMIONA
	{
       if(CivilniAvion(vehicleid))
       {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo piloti!", "~r~Just pilots!", 1000, 3);
       }
       else if(MedicinskiAvion(vehicleid))
	   {
		  SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo medicinski piloti!", "~r~Just medical pilots!", 1000, 3);
	   }
	   else if(VojniAvion(vehicleid) || VojniHeli(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vojni piloti!", "~r~Just military pilots!", 1000, 3);
	   }
	   else if(TaxiAuto(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci taksija!", "~r~Just Taxi drivers!", 1000, 3);
	   }
	   else if(IsABoat(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo moreplovci!", "~r~Just for sailors!", 1000, 3);
	   }
	}
	else if(Team{playerid} == 7) // MOREPLOVCI
	{
       if(CivilniAvion(vehicleid))
       {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo piloti!", "~r~Just pilots!", 1000, 3);
       }
       else if(MedicinskiAvion(vehicleid))
	   {
		  SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo medicinski piloti!", "~r~Just medical pilots!", 1000, 3);
	   }
	   else if(VojniAvion(vehicleid) || VojniHeli(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vojni piloti!", "~r~Just military pilots!", 1000, 3);
	   }
	   else if(TaxiAuto(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci taksija!", "~r~Just Taxi drivers!", 1000, 3);
	   }
       else if(Truck(vehicleid))
	   {
          SFP_SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		  GameText(playerid, "~r~Samo vozaci kamiona!", "~r~Just Truck drivers!", 1000, 3);
	   }
	}
	return (true);
}

stock GetName(playerid)
{
    new IME_IGRACA[MAX_PLAYER_NAME];
    GetPlayerName(playerid, IME_IGRACA, MAX_PLAYER_NAME);
    if(IME_IGRACA[0] == '[' && IME_IGRACA[3] == ']')
    {
        strdel(IME_IGRACA, 0, 4);
    }
	return (IME_IGRACA);
}

public OnPlayerDisconnect(playerid, reason)
{
    novost(GetName(playerid), "napusta server.");
	new dan, mjesec, godina;
	getdate(godina,mjesec,dan);
	PlayerInfo[playerid][Zadnji_Login]= gettime();
	checkPrekid(playerid);
	if(IsBeingSpeced{playerid} == true)
    {
        foreach(Player,i)
        {
            if(spectatorid[i] == playerid)
            {
                TogglePlayerSpectating(i,false);
            }
        }
    }
    PlayerTextDrawDestroy(playerid, TABLA[0][playerid]); PlayerTextDrawDestroy(playerid, TABLA[1][playerid]);
    PlayerTextDrawDestroy(playerid, TABLA[2][playerid]); PlayerTextDrawDestroy(playerid, TABLA[3][playerid]);
    PlayerTextDrawDestroy(playerid, TABLA[4][playerid]); PlayerTextDrawDestroy(playerid, TABLA[5][playerid]);
    PlayerTextDrawDestroy(playerid, TABLA[6][playerid]); PlayerTextDrawDestroy(playerid, TABLA[7][playerid]);
    PlayerTextDrawDestroy(playerid, TABLA[8][playerid]); PlayerTextDrawDestroy(playerid, TABLA[9][playerid]);
    TextDrawDestroy(INFO_BOX[playerid][0]);
    TextDrawDestroy(INFO_BOX[playerid][1]);
	UpdatePlayer(playerid);
	if(snowOn{playerid})
    {
    	for(new i = 0; i < MAX_SNOW_OBJECTS; i++) DestroyDynamicObject(snowObject[playerid][i]);
        snowOn{playerid} = false;
        KillTimer(updateTimer{playerid});
    }
    CanCheckABX[playerid] = (true);
	NeedCheckTuningAB [playerid] = (0);
	TextDrawDestroy(loading_[playerid][0]);
	TextDrawDestroy(loading_[playerid][1]);
	TextDrawDestroy(loading_[playerid][2]);
	return (true);
}

public OnPlayerSpawn(playerid)
{
    new id = IsPlayerInAirline(playerid, GetName(playerid));
    if(PlayerInfo[playerid][AvioSpawn] >= 1 && id != -1)
    {
        Freeze(playerid, 1);
        timerFreeze{playerid} = (3);
    }
	GivePlayerWeapon(playerid, 46, 1);
	playerSpawned{playerid} = (true);
	CanCheckAirBreak[playerid] = (false);
	if(playerSmrt{playerid} == true)
	{
       jobOdabir(playerid);
	}
	if(IsSpecing{playerid} == true)
    {
        SFP_SetPlayerPos(playerid,SPEC_POS[playerid][0],SPEC_POS[playerid][1],SPEC_POS[playerid][2]);
        SetPlayerInterior(playerid,SPEC_INT{playerid});
        SetPlayerVirtualWorld(playerid,SPEC_VW[playerid]);
        IsSpecing{playerid} = (false);
        IsBeingSpeced{spectatorid[playerid]} = (false);
    }
    PlayerTextDrawShow(playerid, MONEY_BAR[0]);
    PlayerTextDrawShow(playerid, MONEY_BAR[2]);
    
    StopAudioStreamForPlayer(playerid);
    TextDrawHideForPlayer(playerid, MainMenu[0]); TextDrawHideForPlayer(playerid, MainMenu[1]); PlayerTextDrawHide(playerid, con__);
    TextDrawHideForPlayer(playerid, MainMenu[2]); TextDrawHideForPlayer(playerid, MainMenu[3]); PlayerTextDrawHide(playerid, naslov__);
    anti_Kicker{playerid} = (false);
	return (true);
}

public OnPlayerDeath(playerid, killerid, reason)
{
	PlayerInfo[playerid][Smrt] ++;
	playerSmrt{playerid} = (true);
	PlayerTextDrawHide(playerid, MONEY_BAR[0]); PlayerTextDrawHide(playerid, MONEY_BAR[1]); PlayerTextDrawHide(playerid, MONEY_BAR[2]);
	DisablePlayerRaceCheckpoint(playerid);
	Bonus{playerid} = (0);
	checkPrekid(playerid);
	TogglePlayerSpectating(playerid,1);
	jobOdabir(playerid);
	if(IsBeingSpeced{playerid} == true)
    {
        foreach(Player,i)
        {
            if(spectatorid[i] == playerid)
            {
                TogglePlayerSpectating(i,false);
            }
        }
    }
    TextDrawHideForPlayer(playerid, MainMenu[0]); TextDrawHideForPlayer(playerid, MainMenu[1]); PlayerTextDrawHide(playerid, con__);
    TextDrawHideForPlayer(playerid, MainMenu[2]); TextDrawHideForPlayer(playerid, MainMenu[3]); PlayerTextDrawHide(playerid, naslov__);
	return (true);
}

stock checkPrekid(playerid)
{
    if(posao{playerid} == true)
	{
        work_vehicle[playerid] = (-1);
		GivePlayerMoneyEx(playerid, -5000);
		posao{playerid} = (false);
		PlayerInfo[playerid][Prekid] ++;
		ruta_sec{playerid} = (0);
        ruta_min{playerid} = (0);
        bonus_[playerid] = (578.00);
	}
	return (true);
}

public OnVehicleSpawn(vehicleid)
{
     if(IsACosVeh(vehicleid))
	 {
		 DestroyVehicle(vehicleid);
         COS_VOZILA[vehicleid] = AddStaticVehicle(CarInfo[vehicleid][v_Model], CarInfo[vehicleid][v_Pos][0], CarInfo[vehicleid][v_Pos][1], CarInfo[vehicleid][v_Pos][2], CarInfo[vehicleid][v_Pos][3], CarInfo[vehicleid][v_Boja][0], CarInfo[vehicleid][v_Boja][0]);
         if(CarInfo[vehicleid][v_PaintJob] != -1)
         {
             ChangeVehiclePaintjob(vehicleid, CarInfo[vehicleid][v_PaintJob]);
         }
         for(new iMod = 0; iMod < 12; ++iMod)
		 {
		    if(vMods[vehicleid][iMod] > 0)
		    {
		        AddVehicleComponent(COS_VOZILA[vehicleid], vMods[vehicleid][iMod]);
			}
		 }
	 }
	 return (true);
}

public OnPlayerText(playerid, text[])
{
	if(PlayerLogin{playerid} == false) return (false);
	if(mute{playerid} == true) return (false);
	new string[135];
	if(strcmp(GetName(playerid), "BloodMaster", true) == 0)
	{
	    format(string, (sizeof string), ""#error"GAY %s%s dosadjuje"#bijela": %s", SetPlayerColorByJob(playerid), GetName(playerid), text);
	}
	else
	{
        new id = IsPlayerInAirline(playerid, GetName(playerid));
		if(id != -1)
		{
			if(strlen(AvioKompanija[id][av_Inicijali]) > 3)
			{
                format(string, (sizeof string), ""#error"%s%s%s ("#bijela"%d%s)"#bijela": %s", AvioKompanija[id][av_Inicijali], SetPlayerColorByJob(playerid), GetName(playerid), playerid, SetPlayerColorByJob(playerid), text);
			}
			else { format(string, (sizeof string), "%s%s ("#bijela"%d%s)"#bijela": %s", SetPlayerColorByJob(playerid), GetName(playerid), playerid, SetPlayerColorByJob(playerid), text); }
		}
		else { format(string, (sizeof string), "%s%s ("#bijela"%d%s)"#bijela": %s", SetPlayerColorByJob(playerid), GetName(playerid), playerid, SetPlayerColorByJob(playerid), text); }
	}
	return ScmToAll(string, string), (false);
}

/*stock IsPlayerInWater(playerid)
{
	new Float:Z;
	GetPlayerPos(playerid,Z,Z,Z);
	if(Z < 0.7) switch(GetPlayerAnimationIndex(playerid)) { case 1543,1538,1539: return (true); }
	if(GetPlayerDistanceFromPoint(playerid,-965,2438,42) <= 700 && Z < 45) return (true);
	new Float:water_places[][] =
	{
		{25.0,	2313.0,	-1417.0,	23.0},
		{15.0,	1280.0,	-773.0,		1082.0},
		{15.0,	1279.0,	-804.0,		86.0},
		{20.0,	1094.0,	-674.0,		111.0},
		{26.0,	194.0,	-1232.0,	76.0},
		{25.0,	2583.0,	2385.0,		15.0},
		{25.0,	225.0,	-1187.0,	73.0},
		{50.0,	1973.0,	-1198.0,	17.0}
	};
	for(new t=0; t < sizeof water_places; t++)
	if(GetPlayerDistanceFromPoint(playerid,water_places[t][1],water_places[t][2],water_places[t][3]) <= water_places[t][0]) return (true);
	return (false);
}*/

public OnPlayerUpdate(playerid)
{
	new string[128];
    if(CanCheckABX[playerid])
	{
		if(!CanCheckAirBreak[playerid])
		{
			AC_AirBreakReset(playerid);
			CanCheckAirBreak[playerid] = true;
		}
		else
		{
		    if( NeedCheckTuningAB[ playerid ] == 1 )
			{
				NeedCheckTuningAB[ playerid ] = 0;
				CanCheckAirBreak[ playerid ] = false;
			}
		    else if( NeedCheckTuningAB[ playerid ] > 0 ) NeedCheckTuningAB[ playerid ]--;
		    else
		    {
				new AC_playerState = GetPlayerState(playerid);
				if(AC_oldPlayerState[playerid] == AC_playerState)
				{
					if(AC_playerState == PLAYER_STATE_ONFOOT || AC_playerState == PLAYER_STATE_DRIVER || AC_playerState == PLAYER_STATE_PASSENGER)
					{
					    if(AC_playerState == PLAYER_STATE_ONFOOT)
					    {
							new AC_animIndex = GetPlayerAnimationIndex(playerid);
						    if(AC_animIndex)
						    {
								new animLib[32], animName[32];
						        GetAnimationName(AC_animIndex, animLib, 32, animName, 32);
						        if(!strcmp(animName, "FALL_LAND", true) || !strcmp(animName, "CLIMB_JUMP2FALL", true) || !strcmp(animName, "CLIMB_PULL", true) || !strcmp(animName, "CLIMB_JUMP_B", true))
						        {
						            CanCheckAirBreak[playerid] = false;
						            return true;
						        }
						    }
					    }

						new Float:AC_fPos[3], Float:AC_fSpeed;
						if(AC_playerState == PLAYER_STATE_DRIVER) GetVehicleVelocity(GetPlayerVehicleID(playerid), AC_fPos[0], AC_fPos[1], AC_fPos[2]);
						else GetPlayerVelocity(playerid, AC_fPos[0], AC_fPos[1], AC_fPos[2]);
						AC_fSpeed = floatsqroot(floatpower(AC_fPos[0], 2) + floatpower(AC_fPos[1], 2) + floatpower(AC_fPos[2], 2)) * 200;
						if(AC_oldPos[playerid][0] != 0.0)
						{
							GetPlayerPos(playerid, AC_fPos[0], AC_fPos[1], AC_fPos[2]);
							if(IsPlayerInRangeOfPoint(playerid, 5.0, 616.7820, -74.8151, 997.6350) || IsPlayerInRangeOfPoint(playerid, 5.0, 615.2851, -124.2390, 997.6350 ) || IsPlayerInRangeOfPoint(playerid, 5.0, 617.5380, -1.9900, 1000.6829 ) )
							{
							    NeedCheckTuningAB [ playerid ] = 10;
							}
							if(NeedCheckTuningAB [ playerid ] == 0)
							{
								new Float:AC_traveledDistance = GetDistanceBetweenPoints(AC_fPos[0], AC_fPos[1], AC_fPos[2], AC_oldPos[playerid][0], AC_oldPos[playerid][1], AC_oldPos[playerid][2]);

								AC_oldPos[playerid][0] = AC_fPos[0];
				                AC_oldPos[playerid][1] = AC_fPos[1];
				                AC_oldPos[playerid][2] = AC_fPos[2];
				                if(AC_traveledDistance > AC_fSpeed > 0.2)
								{
									++ a_b__{playerid};
									if(a_b__{playerid} >= 5)
									{
									   new dan, mjesec, godina;
		                               getdate(godina, mjesec, dan);
		                               format(string, (sizeof string), "%s koristi airbreak (%d.%d.%d)",GetName(playerid),dan,mjesec,godina);
		                               CheatLog(string);
		                               sendToAdmins(string);
		                               SCM(playerid, ""#error"[SFP]: "#bijela"Ne smijes koristiti airbreak!", ""#error"[SFP]: "#bijela"Don't use airbreak!");
							           Kick(playerid);
	                                }
				                }
							}
						}
						else GetPlayerPos(playerid, AC_oldPos[playerid][0], AC_oldPos[playerid][1], AC_oldPos[playerid][2]);
					}
				}
				else CanCheckAirBreak[playerid] = false;
                AC_oldPlayerState[playerid] = AC_playerState;
			}
		}
	}
	else
	{
	    if(AC_oldPos[playerid][0] != 0.0) AC_AirBreakReset(playerid);
	}
	if(AFK{playerid} > 2)
	{
    	AFK{playerid} = (0);
    	AFK2{playerid} = (false);
    	return (true);
	}
	return (true);
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
    zadnje_vozilo[playerid] = (vehicleid);
	return (true);
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    new playerState = GetPlayerState(playerid);
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new Float:vhelti; Zastita__{playerid} = (1);
	 	GetVehicleHealth(GetPlayerVehicleID(playerid), vhelti);
     	AutoHelti[playerid] = (vhelti);
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		new vehicleid = GetPlayerVehicleID(playerid), Float:vehHelti;
        if(GetVehicleModel(vehicleid) == 520 && playerState == PLAYER_STATE_DRIVER && Team{playerid} == 3 && antiTAB{playerid} == false)
        {
			if(PRESSED(KEY_FIRE) || PRESSED(KEY_ACTION))
			{
               ++hydraFire{playerid};
               SCM(playerid, ""#narancasta"[SERVER]: "#bijela"Ne smijes pucati iz aviona! DM je zabranjen!", ""#narancasta"[SERVER]: "#bijela"Don't fire from vehicle!");
               if(hydraFire{playerid} >= 3)
               {
                  checkPrekid(playerid);
				  SFP_SetPlayerHealth(playerid, 0.000);
				  SCM(playerid, ""#narancasta"[SERVER]: "#bijela"Ne smijes pucati iz aviona! DM je zabranjen, prisilno si ubijen!", ""#narancasta"[SERVER]: "#bijela"Don't fire from vehicle! Server killed you!");
               }
            }
        }
		if(PRESSED(KEY_NO) && PlayerInfo[playerid][Fix] >= 1 && playerState == PLAYER_STATE_DRIVER) // N
		{
			GetVehicleHealth(vehicleid, vehHelti);
			if(vehHelti < 1000)
			{
				RepairVehicle(vehicleid);
				SetVehicleHealth(vehicleid, 1000);
				PlayerInfo[playerid][Fix] --;
				SCM(playerid, ""#bijela"* Upravo si koristio kit za popravak!", ""#siva"* You just use one fast fix!");
                if(PlayerInfo[playerid][Fix] <= 0)
				{
					 PlayerInfo[playerid][Fix] = (0);
					 SCM(playerid, ""#bijela"* Nemas vise kit za popravak vozila, kupi novi! (/store)", ""#bijela"* You don't have anymore kits for fast fix! Buy new (/store)");
				}
				UpdatePlayer(playerid);
			}
		}
		else if(PRESSED(KEY_ANALOG_LEFT) && PlayerInfo[playerid][Fill] >= 1 && playerState == PLAYER_STATE_DRIVER) // NUM4
		{
			if(Gorivo[vehicleid] < MAX_FUEL)
			{
				Gorivo[vehicleid] = (MAX_FUEL);
				PlayerInfo[playerid][Fill] --;
				SCM(playerid, ""#bijela"* Upravo si koristio kit za punjenje goriva!", ""#siva"* You just use one fast fill!");
				if(PlayerInfo[playerid][Fill] <= 0)
				{
					 PlayerInfo[playerid][Fill] = (0);
					 SCM(playerid, ""#bijela"* Nemas vise kit za punjenje goriva, kupi novi! (/store)", ""#bijela"* You don't have anymore kits for fuel! Buy new (/store)");
				}
				UpdatePlayer(playerid);
			}
		}
	}
	if(posao{playerid} == true && IsPlayerInAnyVehicle(playerid))
	{
	   if(IsPlayerHaveBoost(playerid) && PRESSED(KEY_YES) && playerState == PLAYER_STATE_DRIVER)
	   {
          new Float:Pos[3];
          GetVehicleVelocity(GetPlayerVehicleID(playerid), Pos[0], Pos[1], Pos[2]);
          if(Team{playerid} == 3)
		  {
			 //if(!VojniAvion(GetPlayerVehicleID(playerid)) || !VojniHeli(GetPlayerVehicleID(playerid))) return (true);
             if(GetSpeed(playerid) < 340)
             {
                SetVehicleVelocity(GetPlayerVehicleID(playerid), Pos[0]*2.0, Pos[1]*2.0, Pos[2]*2.0);
		     }
	      }
	      else if(Team{playerid} == 1 || Team{playerid} == 2)
          {
			 //if(!CivilniAvion(GetPlayerVehicleID(playerid)) || !MedicinskiAvion(GetPlayerVehicleID(playerid))) return (true);
             if(GetSpeed(playerid) < 265)
             {
                SetVehicleVelocity(GetPlayerVehicleID(playerid), Pos[0]*2.0, Pos[1]*2.0, Pos[2]*2.0);
		     }
	      }
	      else if(Team{playerid} == 4) // taxi
          {
			 //if(!DriftCar(GetPlayerVehicleID(playerid)) || !TaxiAuto(GetPlayerVehicleID(playerid))) return (true);
             if(GetSpeed(playerid) < 180)
             {
                SetVehicleVelocity(GetPlayerVehicleID(playerid), Pos[0]*2.0, Pos[1]*2.0, Pos[2]*2.0);
		     }
	      }
	      else if(Team{playerid} == 6 || Team{playerid} == 7) // moreplovac & kamijondjija
          {
			 //if(!DriftCar(GetPlayerVehicleID(playerid)) || !TaxiAuto(GetPlayerVehicleID(playerid))) return (true);
             if(GetSpeed(playerid) < 200)
             {
                SetVehicleVelocity(GetPlayerVehicleID(playerid), Pos[0]*2.0, Pos[1]*2.0, Pos[2]*2.0);
		     }
	      }
	   }
	}
	if(PRESSED(KEY_SECONDARY_ATTACK))
    {
    	for(new i=0;i<MAX_HOUSES;i++)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[i][h_Pi][0], HouseInfo[i][h_Pi][1], HouseInfo[i][h_Pi][2]))
			{
				if(HouseInfo[i][h_Locked] == 0 || strcmp(HouseInfo[i][h_Vlasnik], GetName(playerid), false) == 0)
				{
					SetPlayerInterior(playerid, HouseInfo[i][h_Int]); SetPlayerVirtualWorld(playerid,HouseInfo[i][h_Vw]);
					SFP_SetPlayerPos(playerid, HouseInfo[i][h_In][0], HouseInfo[i][h_In][1], HouseInfo[i][h_In][2]);
					inhouse[playerid] = (i);
				}
				else
				{
					GameText(playerid, "~r~Zakljucano!", "~r~Locked!", 4000, 3);
					return (true);
				}
			}
		}
		if(inhouse[playerid] != MAX_HOUSES+1)
 		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, HouseInfo[inhouse[playerid]][h_In][0], HouseInfo[inhouse[playerid]][h_In][1], HouseInfo[inhouse[playerid]][h_In][2]))
			{
				SetPlayerInterior(playerid,0); SetPlayerVirtualWorld(playerid,0);
				SFP_SetPlayerPos(playerid,HouseInfo[inhouse[playerid]][h_Pi][0], HouseInfo[inhouse[playerid]][h_Pi][1], HouseInfo[inhouse[playerid]][h_Pi][2]);
				inhouse[playerid] = (MAX_HOUSES+1);
				return (true);
			}
		}
	}
	return (true);
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
    if(IsBeingSpeced{playerid} == true)
    {
        foreach(Player,i)
        {
            if(spectatorid[i] == playerid)
            {
                SetPlayerInterior(i,GetPlayerInterior(playerid));
                SetPlayerVirtualWorld(i,GetPlayerVirtualWorld(playerid));
            }
        }
    }
    return (true);
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
        TIMER_GORIVO{GetPlayerVehicleID(playerid)} = (15);
	}
	else if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        if(IsBeingSpeced{playerid} == true)
        {
            foreach(Player,i)
            {
                if(spectatorid[i] == playerid)
                {
                    PlayerSpectateVehicle(i, GetPlayerVehicleID(playerid));
                }
            }
        }
    }
    else if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(IsBeingSpeced{playerid} == true)
        {
            foreach(Player,i)
            {
                if(spectatorid[i] == playerid)
                {
                    PlayerSpectatePlayer(i, playerid);
                }
            }
        }
    }
	return (true);
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	new string[128] = "\0", Float:Pos[3], LOKACIJA[128] = "\0";
	GetPlayerPos(clickedplayerid, Pos[0], Pos[1], Pos[2]);
	Get2DZone(Pos[0],Pos[1],LOKACIJA,128);
	if(IsPlayerLanguage(playerid, JEZIK_BALKAN))
	{
        format(string, 128, ""#narancasta"IME: "#bijela"%s\n"#narancasta"LOKACIJA: "#bijela"%s\n"#narancasta"ID: "#bijela"%d\n"#narancasta"PING: "#bijela"%d\n"#narancasta"ONLINE: "#bijela"%d:%d",GetName(clickedplayerid),LOKACIJA, clickedplayerid, GetPlayerPing(clickedplayerid), PlayerInfo[clickedplayerid][Sati], PlayerInfo[clickedplayerid][Minute]);
	}
	else if(IsPlayerLanguage(playerid, JEZIK_ENGLISH))
	{
        format(string, 128, ""#narancasta"NAME: "#bijela"%s\n"#narancasta"LOCATION: "#bijela"%s\n"#narancasta"ID: "#bijela"%d\n"#narancasta"PING: "#bijela"%d\n"#narancasta"ONLINE: "#bijela"%d:%d",GetName(clickedplayerid),LOKACIJA, clickedplayerid, GetPlayerPing(clickedplayerid), PlayerInfo[clickedplayerid][Sati], PlayerInfo[clickedplayerid][Minute]);
	}
	CreateDialog(playerid, DIALOG_PLAYER_KLIK, DIALOG_STYLE_MSGBOX, "INFO", string, "OK", "", "INFO", string, "OK", "");
	return (true);
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
    new Total_V_Mods = 0;
	if(IsACosVeh(vehicleid))
	{
	   if(strcmp(GetName(playerid), CarInfo[vehicleid][v_Vlasnik], true) == 0)
	   {
	      for(new i = 0; i < 12; ++i)
	      {
	          if(vMods[vehicleid][i] == 0)
	          {
	              vMods[vehicleid][i] = (componentid);
			      ++ Total_V_Mods;
			      UpdateVehicle(vehicleid);
	              break;
		      }
	      }
	      if(Total_V_Mods == 0) SCM(playerid, ""#error"Ne mozes vise tunirati svoje vozilo.", ""#error"You can't tune your vehicle anymore.");
       }
	}
	return (true);
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
    if(IsACosVeh(vehicleid))
	{
		if(strcmp(GetName(playerid), CarInfo[vehicleid][v_Vlasnik], true) == 0)
		{
			 CarInfo[vehicleid][v_PaintJob] = (paintjobid);
			 UpdateVehicle(vehicleid);
		}
	}
	return (true);
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	if(IsACosVeh(vehicleid))
	{
		if(strcmp(GetName(playerid), CarInfo[vehicleid][v_Vlasnik], true) == 0)
		{
			 CarInfo[vehicleid][v_Boja][0] = (color1);
			 CarInfo[vehicleid][v_Boja][1] = (color2);
		}
		UpdateVehicle(vehicleid);
	}
	return (true);
}

public OnPlayerRequestSpawn(playerid)
{
	if(PlayerLogin{playerid} == false || Team{playerid} == 0) return (false);
	return (true);
}

public OnPlayerGiveDamage(playerid, damagedid, Float: amount, weaponid)
{
	if(weaponid == 0 && amount >= 1.0)
	{
        SCM(playerid, ""#siva"* Na ovom serveru je zabranjen DM!", ""#siva"* Don't DM!");
		++dm{playerid};
		if(dm{playerid} >= 3)
		{
			SCM(playerid, ""#siva"* Na ovom serveru je zabranjen DM! Server te prisilno ubio!", ""#siva"* Don't DM! Server killed you!");
            dm{playerid} = (2);
            new Float:health;
			SFP_SetPlayerHealth(playerid, 0.000);
			GetPlayerHealth(damagedid, health);
			SFP_SetPlayerHealth(damagedid, health+amount);
		}
	}
	return (true);
}
