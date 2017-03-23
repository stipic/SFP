/*----------------------------------------------------------------------------*\
			========================================
			j_ints - Pretrazivanje interiora in-game
			========================================	
Zahvale:
	Zeex - ZCMD
	Y_Less - YSI

Napravio: Joey_
				
Verzija:
	1.0
Changelog:
	13/01/13:
		Prva verzija
\*----------------------------------------------------------------------------*/

#include <YSI\y_hooks>
#include <YSI\y_commands>

#define PRESSED(%0) 									(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define INTS_FILE_PATH									("/j_ints/spremljeni_interiori.pwn")

#define J_INTS											"{3CB371}(j_ints){FFFFFF}"
#define ERROR											"{B22222}(error){FFFFFF}"

static const Float:intCoords[146][4] = {
	{2003.12, 1015.19, 33.01, 351.58}, 
	{770.8, -0.7, 1000.73, 22.86}, 
	{974.02, -9.59, 1001.15, 22.6}, 
	{961.93, -51.91, 1001.12, 95.54}, 
	{830.6, 5.94, 1004.18, 125.81}, 
	{1037.83, 0.4, 1001.28, 353.93}, 
	{1212.15, -28.54, 1000.95, 170.57}, 
	{1290.41, 1.95, 1001.02, 179.94}, 
	{1412.15, -2.28, 1000.92, 114.66}, 
	{1527.05, -12.02, 1002.1, 350.0}, 
	{1523.51, -47.82, 1002.27, 262.7}, 
	{612.22, -123.9, 997.99, 266.57}, 
	{512.93, -11.69, 1001.57, 198.77}, 
	{418.47, -80.46, 1001.8, 343.24}, 
	{386.53, 173.64, 1008.38, 63.74}, 
	{288.47, 170.06, 1007.18, 22.05}, 
	{206.46, -137.71, 1003.09, 10.93}, 
	{-100.27, -22.94, 1000.72, 17.29}, 
	{-201.22, -43.25, 1002.27, 45.86}, 
	{-202.94, -6.7, 1002.27, 204.27}, 
	{-25.72, -187.82, 1003.55, 5.08}, 
	{454.99, -107.25, 999.44, 309.02}, 
	{372.56, -131.36, 1001.49, 354.23}, 
	{378.03, -190.52, 1000.63, 141.02}, 
	{315.24, -140.89, 999.6, 7.42}, 
	{225.03, -9.18, 1002.22, 85.53}, 
	{611.35, -77.56, 998.0, 320.93}, 
	{246.07, 108.97, 1003.22, 0.29}, 
	{6.09, -28.9, 1003.55, 5.04}, 
	{773.73, -74.7, 1000.65, 5.23}, 
	{621.45, -23.73, 1000.92, 15.68}, 
	{445.6, -6.98, 1000.73, 172.21}, 
	{285.84, -39.02, 1001.52, 0.75}, 
	{204.12, -46.8, 1001.8, 357.58}, 
	{245.23, 304.76, 999.15, 273.44}, 
	{290.62, 309.06, 999.15, 89.92}, 
	{322.5, 303.69, 999.15, 8.17}, 
	{-2041.23, 178.4, 28.85, 156.22}, 
	{-1402.66, 106.39, 1032.27, 105.14}, 
	{-1403.01, -250.45, 1043.53, 355.86}, 
	{1204.67, -13.54, 1000.92, 350.02}, 
	{2016.12, 1017.15, 996.88, 88.01}, 
	{-741.85, 493.0, 1371.98, 71.78}, 
	{2447.87, -1704.45, 1013.51, 314.53}, 
	{2527.02, -1679.21, 1015.5, 260.97}, 
	{-1129.89, 1057.54, 1346.41, 274.53}, 
	{2496.05, -1695.17, 1014.74, 179.22}, 
	{366.02, -73.35, 1001.51, 292.01}, 
	{2233.94, 1711.8, 1011.63, 184.39}, 
	{269.64, 305.95, 999.15, 215.66}, 
	{414.3, -18.8, 1001.8, 41.43}, 
	{1.19, -3.24, 999.43, 87.57}, 
	{-30.99, -89.68, 1003.55, 359.84}, 
	{161.4, -94.24, 1001.8, 0.79}, 
	{-2638.82, 1407.34, 906.46, 94.68}, 
	{1267.84, -776.96, 1091.91, 231.34}, 
	{2536.53, -1294.84, 1044.13, 254.95}, 
	{2350.16, -1181.07, 1027.98, 99.19}, 
	{-2158.67, 642.09, 1052.38, 86.54}, 
	{419.89, 2537.12, 10.0, 67.65}, 
	{256.9, -41.65, 1002.02, 85.88}, 
	{204.17, -165.77, 1000.52, 181.76}, 
	{1133.35, -7.85, 1000.68, 165.85}, 
	{-1420.43, 1616.92, 1052.53, 159.13}, 
	{493.14, -24.26, 1000.68, 356.99}, 
	{1727.29, -1642.95, 20.23, 172.42}, 
	{-202.84, -24.03, 1002.27, 252.82}, 
	{2233.69, -1112.81, 1050.88, 8.65}, 
	{1211.25, 1049.02, 359.94, 170.93}, 
	{2319.13, -1023.96, 1050.21, 167.4}, 
	{2261.1, -1137.88, 1050.63, 266.88}, 
	{-944.24, 1886.15, 5.01, 179.85}, 
	{-26.19, -140.92, 1003.55, 2.91}, 
	{2217.28, -1150.53, 1025.8, 273.73}, 
	{1.55, 23.32, 1199.59, 359.91}, 
	{681.62, -451.89, -25.62, 166.17}, 
	{234.61, 1187.82, 1080.26, 349.48}, 
	{225.57, 1240.06, 1082.14, 96.29}, 
	{224.29, 1289.19, 1082.14, 359.87}, 
	{239.28, 1114.2, 1080.99, 270.27}, 
	{207.52, -109.74, 1005.13, 358.62}, 
	{295.14, 1473.37, 1080.26, 352.95}, 
	{-1417.89, 932.45, 1041.53, 0.7}, 
	{446.32, 509.97, 1001.42, 330.57}, 
	{2306.38, -15.24, 26.75, 274.49}, 
	{2331.9, 6.78, 26.5, 100.24}, 
	{663.06, -573.63, 16.34, 264.98}, 
	{-227.57, 1401.55, 27.77, 269.3}, 
	{-688.15, 942.08, 13.63, 177.66}, 
	{-1916.13, 714.86, 46.56, 152.28}, 
	{818.77, -1102.87, 25.79, 91.14}, 
	{255.21, -59.68, 1.57, 1.46}, 
	{446.63, 1397.74, 1084.3, 343.96}, 
	{227.39, 1114.66, 1081.0, 267.46}, 
	{227.76, 1114.38, 1080.99, 266.26}, 
	{261.12, 1287.22, 1080.26, 178.91}, 
	{291.76, -80.13, 1001.52, 290.22}, 
	{449.02, -88.99, 999.55, 89.66}, 
	{-27.84, -26.67, 1003.56, 184.31}, 
	{2135.2, -2276.28, 20.67, 318.59}, 
	{306.2, 307.82, 1003.3, 203.14}, 
	{24.38, 1341.18, 1084.38, 8.33}, 
	{963.06, 2159.76, 1011.03, 175.31}, 
	{2548.48, 2823.74, 10.82, 270.6}, 
	{215.15, 1874.06, 13.14, 177.55}, 
	{221.68, 1142.5, 1082.61, 184.96}, 
	{2323.71, -1147.65, 1050.71, 206.54}, 
	{345.0, 307.18, 999.16, 193.64}, 
	{411.97, -51.92, 1001.9, 173.34}, 
	{-1421.56, -663.83, 1059.56, 170.93}, 
	{773.89, -47.77, 1000.59, 10.72}, 
	{246.67, 65.8, 1003.64, 7.96}, 
	{-1864.94, 55.73, 1055.53, 85.85}, 
	{-262.18, 1456.62, 1084.37, 82.46}, 
	{22.86, 1404.92, 1084.43, 349.62}, 
	{140.37, 1367.88, 1083.86, 349.24}, 
	{1494.86, 1306.48, 1093.3, 196.07}, 
	{-1813.21, -58.01, 1058.96, 335.32}, 
	{-1401.07, 1265.37, 1039.87, 178.65}, 
	{234.28, 1065.23, 1084.21, 4.39}, 
	{-68.51, 1353.85, 1080.21, 3.57}, 
	{-2240.1, 136.97, 1035.41, 269.1}, 
	{297.14, -109.87, 1001.52, 20.23}, 
	{316.5, -167.63, 999.59, 10.3}, 
	{-285.25, 1471.2, 1084.38, 85.65}, 
	{-26.83, -55.58, 1003.55, 3.95}, 
	{442.13, -52.48, 999.72, 177.94}, 
	{2182.2, 1628.58, 1043.87, 224.86}, 
	{748.46, 1438.24, 1102.95, 0.61}, 
	{2807.36, -1171.7, 1025.57, 193.71}, 
	{366.0, -9.43, 1001.85, 160.53}, 
	{2216.13, -1076.31, 1050.48, 86.43}, 
	{2268.52, 1647.77, 1084.23, 99.73}, 
	{2236.7, -1078.95, 1049.02, 2.57}, 
	{-2031.12, -115.83, 1035.17, 190.19}, 
	{2365.11, -1133.08, 1050.88, 177.39}, 
	{1168.51, 1360.11, 10.93, 196.59}, 
	{315.45, 976.6, 1960.85, 359.64}, 
	{1893.07, 1017.9, 31.88, 86.1}, 
	{501.96, -70.56, 998.76, 171.57}, 
	{-42.53, 1408.23, 1084.43, 172.07}, 
	{2283.31, 1139.31, 1050.9, 19.7}, 
	{84.92, 1324.3, 1083.86, 159.56}, 
	{260.74, 1238.23, 1084.26, 84.31}, 
	{-1658.17, 1215.0, 7.25, 103.91}, 
	{-1961.63, 295.24, 35.47, 264.49}
};

static const intIDs[146] = {
	11, 5, 3, 3, 3, 3, 3, 18, 1, 3, 2, 3, 3, 3, 
	3, 3, 3, 3, 3, 17, 17, 5, 5, 17, 7, 5, 2, 10, 
	10, 7, 1, 1, 1, 1, 1, 3, 5, 1, 1, 7, 2, 10, 
	1, 2, 1, 10, 3, 10, 1, 2, 2, 2, 18, 18, 3, 5, 
	2, 5, 1, 10, 14, 14, 12, 14, 17, 18, 16, 5, 6, 
	9, 10, 17, 16, 15, 1, 1, 3, 2, 1, 5, 15, 15, 15, 
	12, 0, 0, 0, 18, 0, 0, 0, 0, 2, 5, 5, 4, 4, 4, 
	4, 0, 4, 10, 1, 0, 0, 4, 12, 6, 12, 4, 6, 6, 14, 
	4, 5, 5, 3, 14, 16, 6, 6, 6, 6, 6, 15, 6, 6, 2, 6, 
	8, 9, 1, 1, 2, 3, 8, 0, 9, 10, 11, 8, 11, 9, 9, 0, 0
};

static const intNames[146][] = {
	{"Four Dragons Managerial Suite"}, 
	{"Ganton Gym"}, 
	{"Brothel"}, 
	{"Brothel2"}, 
	{"Inside Track Betting"}, 
	{"Blastin  Fools Records"}, 
	{"The Big Spread Ranch"}, 
	{"Warehouse1 "}, 
	{"Warehouse2 "}, 
	{"B Dup s Apartment"}, 
	{"B Dup s Crack Palace"}, 
	{"Wheel Arch Angels"}, 
	{"OG Loc s House"}, 
	{"Barber Shop"}, 
	{"Planning Department"}, 
	{"Las Venturas Police Department"}, 
	{"Pro-Laps"}, 
	{"Sex Shop"}, 
	{"Las Venturas Tattoo parlor"}, 
	{"Lost San Fierro Tattoo"}, 
	{"24/07/09 (version 1)"}, 
	{"Diner1 "}, 
	{"Pizza Stack"}, 
	{"Rusty Brown s Donuts"}, 
	{"Ammu-nation"}, 
	{"Victim"}, 
	{"Loco Low Co"}, 
	{"San Fierro Police Department"}, 
	{"24/07/09 (version 2)"}, 
	{"Below The Belt Gym"}, 
	{"Transfenders"}, 
	{"World of Coq"}, 
	{"Ammu-nation (version 2)"}, 
	{"SubUrban"}, 
	{"Denise s Bedroom"}, 
	{"Helena s Barn"}, 
	{"Barbara s Love nest"}, 
	{"San Fierro Garage"}, 
	{"Oval Stadium"}, 
	{"8-Track Stadium"}, 
	{"The Pig Pen (strip"}, 
	{"Four Dragons"}, 
	{"Liberty City"}, 
	{"Ryder s house"}, 
	{"Sweet s House"}, 
	{"RC Battlefield"}, 
	{"The Johnson House"}, 
	{"Burger shot"}, 
	{"Caligula s Casino"}, 
	{"Katie s Lovenest"}, 
	{"Barber Shop2 (Reece s)"}, 
	{"Angel Pine Trailer"}, 
	{"24/07/09 (version 3)"}, 
	{"Zip"}, 
	{"The Pleasure Domes"}, 
	{"Madd Dogg s Mansion"}, 
	{"Big Smoke s Crack Palace"}, 
	{"Burning Desire Building"}, 
	{"Wu-Zi Mu s"}, 
	{"Abandoned AC tower"}, 
	{"Wardrobe/Changing room"}, 
	{"Didier Sachs"}, 
	{"Casino (Redsands West)"}, 
	{"Kickstart Stadium"}, 
	{"Club"}, 
	{"Atrium"}, 
	{"Los Santos Tattoo Parlor"}, 
	{"Safe House group1 "}, 
	{"Safe House group2 "}, 
	{"Safe House group3 "}, 
	{"Safe House group4 "}, 
	{"Sherman Dam"}, 
	{"24/07/09 (version 4)"}, 
	{"Jefferson Motel"}, 
	{"Jet Interior"}, 
	{"The Welcome Pump"}, 
	{"Burglary House X1"}, 
	{"Burglary House X2"}, 
	{"Burglary House X3"}, 
	{"Burglary House X4"}, 
	{"Binco"}, 
	{"4 Burglary houses"}, 
	{"Blood Bowl Stadium"}, 
	{"Budget Inn Motel Room"}, 
	{"Palamino Bank"}, 
	{"Palamino Diner"}, 
	{"Dillimore Gas Station"}, 
	{"Lil  Probe Inn"}, 
	{"Torreno s Ranch"}, 
	{"Zombotech - lobby area"}, 
	{"Crypt in LS cemetery"}, 
	{"Blueberry Liquor Store"}, 
	{"Pair of Burglary Houses"}, 
	{"Crack Den"}, 
	{"Burglary House X11"}, 
	{"Burglary House X12"}, 
	{"Ammu-nation (version 3)"}, 
	{"Jay s Diner"}, 
	{"24/07/09 (version 5)"}, 
	{"Warehouse3 "}, 
	{"Michelle s Love Nest*"}, 
	{"Burglary House X14"}, 
	{"Sindacco Abatoir"}, 
	{"K.A.C.C. Military Fuels Depot"}, 
	{"Area69 "}, 
	{"Burglary House X13"}, 
	{"Unused Safe House"}, 
	{"Millie s Bedroom"}, 
	{"Barber Shop"}, 
	{"Dirtbike Stadium"}, 
	{"Cobra Gym"}, 
	{"Los Santos Police Department"}, 
	{"Los Santos Airport"}, 
	{"Burglary House X15"}, 
	{"Burglary House X16"}, 
	{"Burglary House X17"}, 
	{"Bike School"}, 
	{"Francis International Airport"}, 
	{"Vice Stadium"}, 
	{"Burglary House X18"}, 
	{"Burglary House X19"}, 
	{"Zero s RC Shop"}, 
	{"Ammu-nation (version 4)"}, 
	{"Ammu-nation (version 5)"}, 
	{"Burglary House X20"}, 
	{"24/07/09 (version 6)"}, 
	{"Secret Valley Diner"}, 
	{"Rosenberg s Office in Caligulas"}, 
	{"Fanny Batter s Whore House"}, 
	{"Colonel Furhberger s"}, 
	{"Cluckin  Bell"}, 
	{"The Camel s Toe Safehouse"}, 
	{"Caligula s Roof"}, 
	{"Old Venturas Strip Casino"}, 
	{"Driving School"}, 
	{"Verdant Bluffs Safehouse"}, 
	{"Bike School"}, 
	{"Andromada"}, 
	{"Four Dragons  Janitor s Office"}, 
	{"Bar"}, 
	{"Burglary House X21"}, 
	{"Willowfield Safehouse"}, 
	{"Burglary House X22"}, 
	{"Burglary House X23"}, 
	{"Otto s Autos"}, 
	{"Wang Cars"}
};

new currentInt[MAX_PLAYERS] = 0, bool:j_playerBrowsingInts[MAX_PLAYERS] = false;
new Float:playerLastPos[MAX_PLAYERS][3], playerLastInt[MAX_PLAYERS];

new Text:intTD[MAX_PLAYERS];

hook OnPlayerConnect(playerid) {
	intTD[playerid] = TextDrawCreate(320.000000, 322.133239, "~r~Wang Cars (146.) ~<~ ~w~Four Dragons Managerial Suite (1.) ~>~~g~Wang Cars (2.)");
	TextDrawLetterSize(intTD[playerid], 0.304856, 1.467733);
	TextDrawAlignment(intTD[playerid], 2);
	TextDrawColor(intTD[playerid], -1);
	TextDrawSetShadow(intTD[playerid], 0);
	TextDrawSetOutline(intTD[playerid], 1);
	TextDrawBackgroundColor(intTD[playerid], 51);
	TextDrawFont(intTD[playerid], 3);
	TextDrawSetProportional(intTD[playerid], 1);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
	TextDrawHideForPlayer(playerid, intTD[playerid]);
	TextDrawDestroy(intTD[playerid]);
	
	j_playerBrowsingInts[playerid] = false;
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (PRESSED(KEY_ANALOG_LEFT) && j_playerBrowsingInts[playerid]) {
		new strIntNames[140];
	
		if (currentInt[playerid] == 0) currentInt[playerid] = 145;
		else currentInt[playerid]--;
	
		format(strIntNames, sizeof(strIntNames), "~r~%s (%d.) ~<~ ~w~%s (%d.) ~g~~>~ %s (%d.)", 
		intNames[((currentInt[playerid] == 0) ? (145) : (currentInt[playerid] - 1))], ((currentInt[playerid] == 0) ? (146) : (currentInt[playerid])), intNames[currentInt[playerid]], (currentInt[playerid] + 1),
		intNames[((currentInt[playerid] == 145) ? (0) : (currentInt[playerid] + 1))], ((currentInt[playerid] == 145) ? (1) : (currentInt[playerid] + 2)));
		
		TextDrawSetString(intTD[playerid], strIntNames);
		
		TextDrawShowForPlayer(playerid, intTD[playerid]);
		
		SetPlayerInterior(playerid, intIDs[currentInt[playerid]]);
		SetPlayerPos(playerid, intCoords[currentInt[playerid]][0], intCoords[currentInt[playerid]][1], intCoords[currentInt[playerid]][2]);
	} else if (PRESSED(KEY_ANALOG_RIGHT) && j_playerBrowsingInts[playerid]) {
		new strIntNames[140];
	
		if (currentInt[playerid] == 145) currentInt[playerid] = 0;
		else currentInt[playerid]++;
	
		format(strIntNames, sizeof(strIntNames), "~r~%s (%d.) ~<~ ~w~%s (%d.) ~g~~>~ %s (%d.)", 
		intNames[((currentInt[playerid] == 0) ? (145) : (currentInt[playerid] - 1))], ((currentInt[playerid] == 0) ? (146) : (currentInt[playerid])), intNames[currentInt[playerid]], (currentInt[playerid] + 1),
		intNames[((currentInt[playerid] == 145) ? (0) : (currentInt[playerid] + 1))], ((currentInt[playerid] == 145) ? (1) : (currentInt[playerid] + 2)));
		
		TextDrawSetString(intTD[playerid], strIntNames);
		
		TextDrawShowForPlayer(playerid, intTD[playerid]);
		
		format(strIntNames, (sizeof strIntNames), "INT: %d", intIDs[currentInt[playerid]]);
		SendClientMessage(playerid, -1, strIntNames);
		SetPlayerInterior(playerid, intIDs[currentInt[playerid]]);
		SetPlayerPos(playerid, intCoords[currentInt[playerid]][0], intCoords[currentInt[playerid]][1], intCoords[currentInt[playerid]][2]);
	}
	return 1;
}

stock j_startBrowsingInteriors(playerID) {
	if (!j_playerBrowsingInts[playerID]) {
		new strIntNames[140];

		format(strIntNames, sizeof(strIntNames), "~r~%s (146.) ~<~ ~w~%s (1.) ~g~~>~ %s (2.)", intNames[145], intNames[0], intNames[1]);
		TextDrawSetString(intTD[playerID], strIntNames);

		j_playerBrowsingInts[playerID] = true;
		currentInt[playerID] = 0;
		
		TextDrawShowForPlayer(playerID, intTD[playerID]);
		
		SendClientMessage(playerID, -1, J_INTS" Kretanje kroz interiore je pomocu NUM4 (idete lijevo) i NUM6 (idete desno)");
		
		GetPlayerPos(playerID, playerLastPos[playerID][0], playerLastPos[playerID][1], playerLastPos[playerID][2]);
		playerLastInt[playerID] = GetPlayerInterior(playerID);
		
		SetPlayerInterior(playerID, intIDs[currentInt[playerID]]);
		SetPlayerPos(playerID, intCoords[currentInt[playerID]][0], intCoords[currentInt[playerID]][1], intCoords[currentInt[playerID]][2]);
	}
	return 1;
}

stock j_stopBrowsingInteriors(playerID) {
	if (j_playerBrowsingInts[playerID]) {
		SetPlayerPos(playerID, playerLastPos[playerID][0], playerLastPos[playerID][1], playerLastPos[playerID][2]);
		SetPlayerInterior(playerID, playerLastInt[playerID]);
		
		j_playerBrowsingInts[playerID] = false;
		
		TextDrawHideForPlayer(playerID, intTD[playerID]);
	}
	return 1;
}

YCMD:ints(playerid, params[],help) {
	if (!j_playerBrowsingInts[playerid]) j_startBrowsingInteriors(playerid);
	else j_stopBrowsingInteriors(playerid);
	return 1;
}

YCMD:saveint(playerid, params[],help) {
	if (j_playerBrowsingInts[playerid]) {
		if (isnull(params)) SendClientMessage(playerid, -1, J_INTS" Mozes i dodat komentar prije spremanju (/saveint [komentar])");

		new File:intsFile = fopen(INTS_FILE_PATH, io_append);
		new savedInt[223];

		format(savedInt, sizeof(savedInt), "\r\n// %s\r\nSetPlayerPos(playerid, %.2f, %.2f, %.2f);\r\nSetPlayerInterior(playerid, %d);",
		params, intCoords[currentInt[playerid]][0], intCoords[currentInt[playerid]][1], intCoords[currentInt[playerid]][2], intIDs[currentInt[playerid]]);

		fwrite(intsFile, savedInt);

		fclose(intsFile);

		SendClientMessage(playerid, -1, J_INTS" Interior uspjesno spremljen");
	} else {
		SendClientMessage(playerid, -1, ERROR" Ne pretrazujes interiore");
	}
	return 1;
}
