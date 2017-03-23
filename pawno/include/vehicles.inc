#include "a_samp"
#include "streamer"

new ZabranjenaImena[][] =
{
     "[cenzura]", "Jebem", "Jebem",
	 "Admin", "Hitler", "Jebanje",
	 "Administrator", "Tito", "Sex",
	 "Yugoslavia", "Srbija", "Seks",
	 "Jugoslavia", "Serbia", "Prazno/None",
	 "Jugoslavija", "Ustasa", "None",
	 "Dick", "Ustase",
	 "Kurva", "Cetnik",
	 "Peder", "Cetnici",
	 "Picka", "Fuck",
	 "Kurac", "FuckYou",
	 "Pimpek", "Fuck_You"
};

new
   MedicinskiPiloti[16], VojniPiloti[24], CivilniAvioni[91], vojni_Heli[10],

   TaxiAutiSF[16], TaxiAutiLV[17], TaxiAutiLS[19],
   
   Kamioni[13],
   
   Brod[26],
   
   Text3D:D3TEXT[MAX_VEHICLES];
   
new VehicleNames[212][] = {
{"Landstalker"},{"Bravura"},{"Buffalo"},{"Linerunner"},{"Perrenial"},{"Sentinel"},{"Dumper"},
{"Firetruck"},{"Trashmaster"},{"Stretch"},{"Manana"},{"Infernus"},{"Voodoo"},{"Pony"},{"Mule"},
{"Cheetah"},{"Ambulance"},{"Leviathan"},{"Moonbeam"},{"Esperanto"},{"Taxi"},{"Washington"},
{"Bobcat"},{"Mr Whoopee"},{"BF Injection"},{"Hunter"},{"Premier"},{"Enforcer"},{"Securicar"},
{"Banshee"},{"Predator"},{"Bus"},{"Rhino"},{"Barracks"},{"Hotknife"},{"Trailer 1"},{"Previon"},
{"Coach"},{"Cabbie"},{"Stallion"},{"Rumpo"},{"RC Bandit"},{"Romero"},{"Packer"},{"Monster"},
{"Admiral"},{"Squalo"},{"Seasparrow"},{"Pizzaboy"},{"Tram"},{"Trailer 2"},{"Turismo"},
{"Speeder"},{"Reefer"},{"Tropic"},{"Flatbed"},{"Yankee"},{"Caddy"},{"Solair"},{"Berkley's RC Van"},
{"Skimmer"},{"PCJ-600"},{"Faggio"},{"Freeway"},{"RC Baron"},{"RC Raider"},{"Glendale"},{"Oceanic"},
{"Sanchez"},{"Sparrow"},{"Patriot"},{"Quad"},{"Coastguard"},{"Dinghy"},{"Hermes"},{"Sabre"},
{"Rustler"},{"ZR-350"},{"Walton"},{"Regina"},{"Comet"},{"BMX"},{"Burrito"},{"Camper"},{"Marquis"},
{"Baggage"},{"Dozer"},{"Maverick"},{"News Chopper"},{"Rancher"},{"FBI Rancher"},{"Virgo"},{"Greenwood"},
{"Jetmax"},{"Hotring"},{"Sandking"},{"Blista Compact"},{"Police Maverick"},{"Boxville"},{"Benson"},
{"Mesa"},{"RC Goblin"},{"Hotring Racer A"},{"Hotring Racer B"},{"Bloodring Banger"},{"Rancher"},
{"Super GT"},{"Elegant"},{"Journey"},{"Bike"},{"Mountain Bike"},{"Beagle"},{"Cropdust"},{"Stunt"},
{"Tanker"}, {"Roadtrain"},{"Nebula"},{"Majestic"},{"Buccaneer"},{"Shamal"},{"Hydra"},{"FCR-900"},
{"NRG-500"},{"HPV1000"},{"Cement Truck"},{"Tow Truck"},{"Fortune"},{"Cadrona"},{"FBI Truck"},
{"Willard"},{"Forklift"},{"Tractor"},{"Combine"},{"Feltzer"},{"Remington"},{"Slamvan"},
{"Blade"},{"Freight"},{"Streak"},{"Vortex"},{"Vincent"},{"Bullet"},{"Clover"},{"Sadler"},
{"Firetruck LA"},{"Hustler"},{"Intruder"},{"Primo"},{"Cargobob"},{"Tampa"},{"Sunrise"},{"Merit"},
{"Utility"},{"Nevada"},{"Yosemite"},{"Windsor"},{"Monster A"},{"Monster B"},{"Uranus"},{"Jester"},
{"Sultan"},{"Stratum"},{"Elegy"},{"Raindance"},{"RC Tiger"},{"Flash"},{"Tahoma"},{"Savanna"},
{"Bandito"},{"Freight Flat"},{"Streak Carriage"},{"Kart"},{"Mower"},{"Duneride"},{"Sweeper"},
{"Broadway"},{"Tornado"},{"AT-400"},{"DFT-30"},{"Huntley"},{"Stafford"},{"BF-400"},{"Newsvan"},
{"Tug"},{"Trailer 3"},{"Emperor"},{"Wayfarer"},{"Euros"},{"Hotdog"},{"Club"},{"Freight Carriage"},
{"Trailer 3"},{"Andromada"},{"Dodo"},{"RC Cam"},{"Launch"},{"Police Car (LSPD)"},{"Police Car (SFPD)"},
{"Police Car (LVPD)"},{"Police Ranger"},{"Picador"},{"S.W.A.T. Van"},{"Alpha"},{"Phoenix"},{"Glendale"},
{"Sadler"},{"Luggage Trailer A"},{"Luggage Trailer B"},{"Stair Trailer"},{"Boxville"},{"Farm Plow"},
{"Utility Trailer"}
};

stock LoadVehicles()
{
    // VOZILA - LVA
	CivilniAvioni[0] = AddStaticVehicle(519,1285.40002441,1324.09997559,11.80000019,268.08264160,-1,-1); //Shamal
    CivilniAvioni[1] = AddStaticVehicle(519,1284.19995117,1361.19995117,11.80000019,268.07739258,-1,-1); //Shamal
    CivilniAvioni[2] = AddStaticVehicle(519,1310.19995117,1360.59997559,11.80000019,268.07739258,-1,-1); //Shamal
    CivilniAvioni[3] = AddStaticVehicle(519,1310.00000000,1338.30004883,11.80000019,268.07739258,-1,-1); //Shamal
    CivilniAvioni[4] = AddStaticVehicle(519,1310.59997559,1315.90002441,11.80000019,269.99475098,-1,-1); //Shamal
    CivilniAvioni[5] = AddStaticVehicle(593,1297.90002441,1412.00000000,11.39999962,0.00000000,-1,-1); //Dodo
    CivilniAvioni[6] = AddStaticVehicle(593,1312.09997559,1412.00000000,11.39999962,0.00000000,-1,-1); //Dodo
    CivilniAvioni[7] = AddStaticVehicle(593,1326.69995117,1412.00000000,11.39999962,0.00000000,-1,-1); //Dodo
    CivilniAvioni[8] = AddStaticVehicle(553,1346.19995117,1507.30004883,13.10000038,270.00000000,-1,-1); //Nevada
    CivilniAvioni[9] = AddStaticVehicle(553,1346.09997559,1477.00000000,13.10000038,270.00000000,-1,-1); //Nevada
    CivilniAvioni[10] = AddStaticVehicle(553,1330.69995117,1571.09997559,13.10000038,270.00000000,-1,-1); //Nevada
    CivilniAvioni[11] = AddStaticVehicle(553,1330.50000000,1604.59997559,13.10000038,270.00000000,-1,-1); //Nevada
    CivilniAvioni[12] = AddStaticVehicle(577,1483.80004883,1801.80004883,12.50000000,138.08264160,-1,-1); //AT-400
    CivilniAvioni[13] = AddStaticVehicle(577,1511.80004883,1756.00000000,9.80000019,138.08166504,-1,-1); //AT-400
    CivilniAvioni[14] = AddStaticVehicle(577,1518.40002441,1696.19995117,9.80000019,138.08166504,-1,-1); //AT-400
    CivilniAvioni[15] = AddStaticVehicle(577,1373.90002441,1820.59997559,9.80000019,178.08160400,-1,-1); //AT-400
    CivilniAvioni[16] = AddStaticVehicle(577,1430.09997559,1797.80004883,9.80000019,178.07733154,-1,-1); //AT-400
    CivilniAvioni[17] = AddStaticVehicle(519,1341.80004883,1682.90002441,11.80000019,266.16528320,-1,-1); //Shamal
    CivilniAvioni[18] = AddStaticVehicle(511,1323.59997559,1478.69995117,12.30000019,271.91735840,-1,-1); //Beagle
    CivilniAvioni[19] = AddStaticVehicle(511,1323.19995117,1501.40002441,12.30000019,271.91711426,-1,-1); //Beagle
    CivilniAvioni[20] = AddStaticVehicle(511,1294.30004883,1526.90002441,12.30000019,271.91711426,-1,-1); //Beagle
    CivilniAvioni[21] = AddStaticVehicle(511,1293.00000000,1550.69995117,12.30000019,271.91711426,-1,-1); //Beagle
    CivilniAvioni[22] = AddStaticVehicle(593,1328.00000000,1398.80004883,13.10000038,0.00000000,-1,-1); //Dodo
    
    MedicinskiPiloti[0] = AddStaticVehicle(563,1366.09997559,1253.59997559,11.69999981,0.00000000,-1,-1); //Raindance
    MedicinskiPiloti[1] = AddStaticVehicle(563,1367.09997559,1271.50000000,11.69999981,0.00000000,-1,-1); //Raindance
    MedicinskiPiloti[2] = AddStaticVehicle(563,1282.40002441,1274.50000000,11.69999981,0.00000000,-1,-1); //Raindance
    MedicinskiPiloti[3] = AddStaticVehicle(563,1366.40002441,1290.40002441,11.69999981,0.00000000,-1,-1); //Raindance
    
    AddStaticVehicle(583,1328.80004883,1279.00000000,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1325.69995117,1278.90002441,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1322.19995117,1278.80004883,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1319.09997559,1278.80004883,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1315.80004883,1278.80004883,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1312.69995117,1278.80004883,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1309.50000000,1278.90002441,9.80000019,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1306.30004883,1279.00000000,9.80000019,0.00000000,-1,-1); //Tug
    
    // AVIONI - LOS SANTOS
    MedicinskiPiloti[4] = AddStaticVehicle(487,1972.19995117,-2379.10009766,13.80000019,90.00000000,-1,-1); //Maverick
    MedicinskiPiloti[5] = AddStaticVehicle(487,1973.00000000,-2392.80004883,13.80000019,90.00000000,-1,-1); //Maverick
    MedicinskiPiloti[6] = AddStaticVehicle(487,1972.90002441,-2365.10009766,13.80000019,90.00000000,-1,-1); //Maverick
    MedicinskiPiloti[7] = AddStaticVehicle(563,1970.59997559,-2351.50000000,14.39999962,90.00000000,-1,-1); //Raindance
    MedicinskiPiloti[8] = AddStaticVehicle(563,1970.30004883,-2338.69995117,14.39999962,90.00000000,-1,-1); //Raindance
    
    CivilniAvioni[23] = AddStaticVehicle(519,1885.19995117,-2377.60009766,14.60000038,238.08264160,-1,-1); //Shamal
    CivilniAvioni[24] = AddStaticVehicle(519,1899.00000000,-2358.19995117,14.50000000,238.07922363,-1,-1); //Shamal
    CivilniAvioni[25] = AddStaticVehicle(592,1902.80004883,-2293.60009766,15.50000000,268.08264160,-1,-1); //Andromada
    CivilniAvioni[26] = AddStaticVehicle(592,1970.59997559,-2277.10009766,12.50000000,148.07727051,-1,-1); //Andromada
    CivilniAvioni[27] = AddStaticVehicle(593,2011.69995117,-2436.89990234,14.10000038,90.00000000,-1,-1); //Dodo
    CivilniAvioni[28] = AddStaticVehicle(593,2011.80004883,-2450.50000000,14.10000038,90.00000000,-1,-1); //Dodo
    CivilniAvioni[29] = AddStaticVehicle(593,2011.59997559,-2463.89990234,14.10000038,90.00000000,-1,-1); //Dodo
    CivilniAvioni[30] = AddStaticVehicle(577,2100.80004883,-2454.10009766,12.50000000,0.00000000,-1,-1); //AT-400
    CivilniAvioni[31] = AddStaticVehicle(577,2065.00000000,-2593.19995117,12.50000000,87.66931152,-1,-1); //AT-400
    CivilniAvioni[32] = AddStaticVehicle(577,2033.50000000,-2494.00000000,12.50000000,89.58300781,-1,-1); //AT-400
    CivilniAvioni[33] = AddStaticVehicle(511,1992.90002441,-2637.50000000,15.10000038,0.00000000,-1,-1); //Beagle
    CivilniAvioni[34] = AddStaticVehicle(511,1969.40002441,-2637.19995117,15.10000038,0.00000000,-1,-1); //Beagle
    CivilniAvioni[35] = AddStaticVehicle(511,1946.00000000,-2637.10009766,15.10000038,0.00000000,-1,-1); //Beagle
    CivilniAvioni[36] = AddStaticVehicle(511,1947.09997559,-2616.39990234,15.10000038,0.00000000,-1,-1); //Beagle
    CivilniAvioni[37] = AddStaticVehicle(553,1969.59997559,-2427.80004883,15.80000019,90.00000000,-1,-1); //Nevada
    CivilniAvioni[38] = AddStaticVehicle(553,1967.69995117,-2457.69995117,15.80000019,90.00000000,-1,-1); //Nevada
    CivilniAvioni[39] = AddStaticVehicle(553,1848.59997559,-2413.80004883,15.80000019,197.66943359,-1,-1); //Nevada
    CivilniAvioni[40] = AddStaticVehicle(553,1874.90002441,-2413.89990234,15.80000019,217.66601562,-1,-1); //Nevada
    CivilniAvioni[41] = AddStaticVehicle(519,1879.30004883,-2465.89990234,14.60000038,271.91735840,-1,-1); //Shamal
    CivilniAvioni[42] = AddStaticVehicle(519,1878.50000000,-2442.80004883,14.60000038,271.91711426,-1,-1); //Shamal
    
    AddStaticVehicle(583,1896.69995117,-2528.60009766,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1893.40002441,-2528.50000000,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1890.09997559,-2528.19995117,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1886.90002441,-2528.00000000,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1886.69995117,-2522.89990234,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1890.09997559,-2523.10009766,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1893.40002441,-2522.89990234,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1896.80004883,-2522.60009766,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1896.90002441,-2517.50000000,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1893.80004883,-2517.80004883,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1890.40002441,-2518.19995117,12.50000000,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,1887.30004883,-2518.30004883,12.50000000,0.00000000,-1,-1); //Tug
    
    AddStaticVehicle(485,1875.69995117,-2527.50000000,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1872.69995117,-2527.00000000,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1870.00000000,-2526.80004883,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1870.00000000,-2522.10009766,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1872.50000000,-2522.10009766,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1875.50000000,-2522.30004883,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1875.50000000,-2517.80004883,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1872.40002441,-2517.50000000,13.19999981,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,1869.90002441,-2517.19995117,13.19999981,0.00000000,-1,-1); //Baggage
    
    vojni_Heli[0] = AddStaticVehicle(548,1969.00000000,-2406.69995117,15.39999962,90.00000000,-1,-1); //Cargobob
    
    // AVIONI - SAN FIERO
    
    MedicinskiPiloti[9] = AddStaticVehicle(563,-1236.30004883,-33.90000153,15.00000000,0.00000000,-1,-1); //Raindance
    MedicinskiPiloti[10] = AddStaticVehicle(563,-1248.90002441,-44.00000000,15.00000000,0.00000000,-1,-1); //Raindance
    MedicinskiPiloti[11] = AddStaticVehicle(563,-1260.30004883,-55.59999847,15.00000000,0.00000000,-1,-1); //Raindance
    MedicinskiPiloti[12] = AddStaticVehicle(563,-1260.09997559,-3.20000005,15.00000000,200.00000000,-1,-1); //Raindance
    MedicinskiPiloti[13] = AddStaticVehicle(563,-1271.59997559,-12.60000038,15.00000000,199.99511719,-1,-1); //Raindance
    MedicinskiPiloti[14] = AddStaticVehicle(563,-1282.50000000,-22.60000038,15.00000000,199.99511719,-1,-1); //Raindance
    
    vojni_Heli[1] = AddStaticVehicle(548,-1224.09997559,29.29999924,16.00000000,0.00000000,-1,-1); //Cargobob
    vojni_Heli[2] = AddStaticVehicle(548,-1207.50000000,46.29999924,16.00000000,0.00000000,-1,-1); //Cargobob
    
    AddStaticVehicle(583,-1251.50000000,69.30000305,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1254.30004883,67.00000000,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1256.69995117,64.40000153,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1259.50000000,62.00000000,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1262.30004883,59.59999847,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1265.00000000,57.09999847,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1255.09997559,72.59999847,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1258.30004883,70.30000305,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1261.09997559,67.80000305,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1263.90002441,65.59999847,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(583,-1266.50000000,63.09999847,13.10000038,0.00000000,-1,-1); //Tug
    AddStaticVehicle(485,-1265.19995117,83.69999695,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1268.09997559,81.09999847,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1270.80004883,78.90000153,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1273.69995117,76.50000000,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1276.59997559,74.00000000,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1279.19995117,71.09999847,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1268.30004883,87.40000153,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1271.40002441,84.50000000,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1274.30004883,82.00000000,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1277.19995117,79.50000000,13.80000019,0.00000000,-1,-1); //Baggage
    AddStaticVehicle(485,-1280.09997559,76.90000153,13.80000019,0.00000000,-1,-1); //Baggage

    CivilniAvioni[43] = AddStaticVehicle(553,-1331.80004883,-265.60000610,16.39999962,310.00000000,-1,-1); //Nevada
    CivilniAvioni[44] = AddStaticVehicle(553,-1353.80004883,-234.19999695,16.39999962,309.99572754,-1,-1); //Nevada
    CivilniAvioni[45] = AddStaticVehicle(553,-1380.50000000,-211.30000305,16.39999962,329.99572754,-1,-1); //Nevada
    CivilniAvioni[46] = AddStaticVehicle(593,-1321.80004883,-203.89999390,14.69999981,309.99755859,-1,-1); //Dodo
    CivilniAvioni[47] = AddStaticVehicle(593,-1331.19995117,-194.10000610,14.69999981,313.83044434,-1,-1); //Dodo
    CivilniAvioni[48] = AddStaticVehicle(593,-1312.40002441,-214.10000610,14.69999981,313.82995605,-1,-1); //Dodo
    CivilniAvioni[49] = AddStaticVehicle(511,-1257.69995117,-93.19999695,15.69999981,0.00000000,-1,-1); //Beagle
    CivilniAvioni[50] = AddStaticVehicle(511,-1242.90002441,-111.09999847,15.69999981,0.00000000,-1,-1); //Beagle
    CivilniAvioni[51] = AddStaticVehicle(511,-1226.19995117,-127.69999695,15.69999981,0.00000000,-1,-1); //Beagle
    CivilniAvioni[52] = AddStaticVehicle(511,-1209.40002441,-143.89999390,15.69999981,0.00000000,-1,-1); //Beagle
    CivilniAvioni[53] = AddStaticVehicle(592,-1132.69995117,-207.89999390,15.10000038,80.00000000,-1,-1); //Andromada
    CivilniAvioni[54] = AddStaticVehicle(592,-1157.09997559,-315.10000610,15.00000000,48.07958984,-1,-1); //Andromada
    CivilniAvioni[55] = AddStaticVehicle(592,-1152.90002441,-367.70001221,15.00000000,48.07617188,-1,-1); //Andromada
    CivilniAvioni[56] = AddStaticVehicle(592,-1156.00000000,-420.60000610,15.00000000,48.07617188,-1,-1); //Andromada
    CivilniAvioni[57] = AddStaticVehicle(519,-1392.69995117,-115.09999847,15.10000038,350.00000000,-1,-1); //Shamal
    CivilniAvioni[58] = AddStaticVehicle(519,-1415.00000000,-110.09999847,15.10000038,349.99694824,-1,-1); //Shamal
    CivilniAvioni[59] = AddStaticVehicle(519,-1438.59997559,-105.09999847,15.10000038,349.99694824,-1,-1); //Shamal
    CivilniAvioni[60] = AddStaticVehicle(519,-1455.80004883,-132.69999695,15.30000019,31.91430664,-1,-1); //Shamal
    CivilniAvioni[61] = AddStaticVehicle(577,-1632.19995117,-139.39999390,13.10000038,313.83471680,-1,-1); //AT-400
    CivilniAvioni[62] = AddStaticVehicle(577,-1624.09997559,-283.29998779,13.10000038,315.74731445,-1,-1); //AT-400
    CivilniAvioni[63] = AddStaticVehicle(577,-1670.40002441,-238.19999695,13.10000038,315.74707031,-1,-1); //AT-400
    CivilniAvioni[64] = AddStaticVehicle(577,-1264.00000000,-447.70001221,13.10000038,285.74707031,-1,-1); //AT-400
    CivilniAvioni[65] = AddStaticVehicle(519,-1374.19995117,-492.29998779,15.19999981,260.00000000,-1,-1); //Shamal
    CivilniAvioni[66] = AddStaticVehicle(519,-1353.50000000,-479.50000000,15.19999981,159.99688721,-1,-1); //Shamal
    CivilniAvioni[67] = AddStaticVehicle(519,-1381.59997559,-547.70001221,15.10000038,198.07647705,-1,-1); //Shamal
    CivilniAvioni[68] = AddStaticVehicle(519,-1362.30004883,-553.90002441,15.10000038,198.07250977,-1,-1); //Shamal
    CivilniAvioni[69] = AddStaticVehicle(593,-1455.19995117,-532.59997559,14.69999981,250.00000000,-1,-1); //Dodo
    CivilniAvioni[70] = AddStaticVehicle(593,-1441.59997559,-523.29998779,14.69999981,209.99938965,-1,-1); //Dodo
    CivilniAvioni[71] = AddStaticVehicle(593,-1425.90002441,-517.40002441,14.69999981,179.99810791,-1,-1); //Dodo
    CivilniAvioni[72] = AddStaticVehicle(577,-1330.00000000,9.80000019,13.10000038,0.00000000,-1,-1); //AT-400
    
    // NEGDJE KOD LOS SANTOSA (BLOOD MASTER AVIONSKA PISTA)
    CivilniAvioni[73] = AddStaticVehicle(511,-284.97250366,-3126.28955078,24.99460030,180.00000000,-1,-1); //Beagle
    CivilniAvioni[74] = AddStaticVehicle(511,-306.63940430,-3126.17797852,24.99460030,180.00000000,-1,-1); //Beagle
    CivilniAvioni[75] = AddStaticVehicle(511,-328.73941040,-3126.02709961,24.99460030,180.00000000,-1,-1); //Beagle
    CivilniAvioni[76] = AddStaticVehicle(511,-350.85540771,-3125.93994141,24.99460030,180.00000000,-1,-1); //Beagle
    CivilniAvioni[77] = AddStaticVehicle(511,-373.40649414,-3125.85400391,24.99460030,180.00000000,-1,-1); //Beagle
    CivilniAvioni[78] = AddStaticVehicle(519,-454.83319092,-3155.71582031,24.86669922,215.00000000,-1,-1); //Shamal
    CivilniAvioni[79] = AddStaticVehicle(519,-454.87249756,-3137.26171875,24.86669922,214.99694824,-1,-1); //Shamal
    CivilniAvioni[80] = AddStaticVehicle(519,-455.40280151,-3119.19580078,24.86669922,214.99694824,-1,-1); //Shamal
    CivilniAvioni[81] = AddStaticVehicle(519,-433.16180420,-3118.20947266,24.86669922,214.99694824,-1,-1); //Shamal
    CivilniAvioni[82] = AddStaticVehicle(519,-431.45010376,-3137.20117188,24.86669922,214.99694824,-1,-1); //Shamal
    CivilniAvioni[83] = AddStaticVehicle(519,-431.89169312,-3156.34033203,24.86669922,214.99694824,-1,-1); //Shamal
    CivilniAvioni[84] = AddStaticVehicle(553,-405.94259644,-3156.06616211,25.19169998,215.00000000,-1,-1); //Nevada
    CivilniAvioni[85] = AddStaticVehicle(553,-404.42428589,-3135.46923828,25.19169998,214.99694824,-1,-1); //Nevada
    CivilniAvioni[86] = AddStaticVehicle(553,-404.50930786,-3116.92407227,25.19169998,214.99694824,-1,-1); //Nevada
    CivilniAvioni[87] = AddStaticVehicle(593,-286.75561523,-3157.49829102,23.50690079,155.00000000,-1,-1); //Dodo
    CivilniAvioni[88] = AddStaticVehicle(593,-300.06060791,-3157.15258789,23.50690079,154.99511719,-1,-1); //Dodo
    CivilniAvioni[89] = AddStaticVehicle(593,-313.22140503,-3156.38134766,23.50690079,154.99511719,-1,-1); //Dodo
    CivilniAvioni[90] = AddStaticVehicle(593,-325.59490967,-3155.26879883,23.50690079,154.99511719,-1,-1); //Dodo
    
    MedicinskiPiloti[15] = AddStaticVehicle(417,-244.59109497,-3153.77270508,26.94219971,180.00000000,-1,-1); //Leviathan
    
    CreateDynamicObject(10766,-849.06561279,-3190.94995117,20.01409912,0.00000000,0.00000000,90.00000000); //object(airport_10_sfse) (1)
    CreateDynamicObject(10766,-849.06542969,-3190.94921875,-9.53590012,0.00000000,0.00000000,90.00000000); //object(airport_10_sfse) (2)
    CreateDynamicObject(10766,-849.06542969,-3190.94921875,-38.65589905,0.00000000,0.00000000,90.00000000); //object(airport_10_sfse) (3)
    CreateDynamicObject(10767,-721.64251709,-3191.09741211,7.35109997,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (1)
    CreateDynamicObject(10767,-721.64160156,-3191.09667969,-22.25489998,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (2)
    CreateDynamicObject(10767,-721.64160156,-3191.09667969,-51.32300186,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (3)
    CreateDynamicObject(10767,-551.33209229,-3191.08666992,7.35109997,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (5)
    CreateDynamicObject(10767,-551.33209229,-3191.08593750,-22.22890091,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (6)
    CreateDynamicObject(10767,-551.33209229,-3191.08593750,-51.52890015,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (7)
    CreateDynamicObject(10767,-551.33209229,-3191.08593750,-80.43890381,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (8)
    CreateDynamicObject(10767,-721.64160156,-3191.09667969,-80.40299988,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (9)
    CreateDynamicObject(10766,-849.06542969,-3190.94921875,-67.81590271,0.00000000,0.00000000,90.00000000); //object(airport_10_sfse) (4)
    CreateDynamicObject(10816,-277.16809082,-3171.77783203,20.87080002,0.00000000,0.00000000,180.00000000); //object(airprtgnd_01_sfse) (1)
    CreateDynamicObject(10816,-277.16799927,-3171.77734375,-8.49919987,0.00000000,0.00000000,179.99450684); //object(airprtgnd_01_sfse) (2)
    CreateDynamicObject(10816,-277.16799927,-3171.77734375,-37.33919907,0.00000000,0.00000000,179.99450684); //object(airprtgnd_01_sfse) (3)
    CreateDynamicObject(10816,-277.16799927,-3171.77734375,-65.77919769,0.00000000,0.00000000,179.99450684); //object(airprtgnd_01_sfse) (4)
    CreateDynamicObject(10767,-113.37139893,-3134.89819336,6.73909998,0.00000000,0.00000000,225.00000000); //object(airport_11_sfse) (10)
    CreateDynamicObject(10767,-113.37110138,-3134.89746094,-22.06089973,0.00000000,0.00000000,225.00000000); //object(airport_11_sfse) (11)
    CreateDynamicObject(10767,-113.37110138,-3134.89746094,-51.08089828,0.00000000,0.00000000,225.00000000); //object(airport_11_sfse) (12)
    CreateDynamicObject(10767,-113.37110138,-3134.89746094,-79.20089722,0.00000000,0.00000000,225.00000000); //object(airport_11_sfse) (13)
    CreateDynamicObject(10767,-721.64160156,-3191.09667969,7.35109997,0.00000000,0.00000000,135.00000000); //object(airport_11_sfse) (15)
    CreateDynamicObject(10766,-113.54620361,-3051.66821289,-90.53929901,90.00000000,185.00000000,355.00000000); //object(airport_10_sfse) (5)
    CreateDynamicObject(10767,-227.12919617,-3128.78417969,7.18109989,0.00000000,0.00000000,315.00000000); //object(airport_11_sfse) (16)
    CreateDynamicObject(10767,-379.27539062,-3128.86083984,7.18109989,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (17)
    CreateDynamicObject(10767,-379.27539062,-3128.86035156,-22.18889999,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (18)
    CreateDynamicObject(10767,-379.27539062,-3128.86035156,-50.41889954,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (19)
    CreateDynamicObject(10767,-379.27539062,-3128.86035156,-69.43890381,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (20)
    CreateDynamicObject(10767,-227.12890625,-3128.78417969,-22.12689972,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (21)
    CreateDynamicObject(10767,-227.12890625,-3128.78417969,-50.53689957,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (22)
    CreateDynamicObject(10767,-227.12890625,-3128.78417969,-78.40689850,0.00000000,0.00000000,314.99450684); //object(airport_11_sfse) (23)
    CreateDynamicObject(8038,-102.17040253,-3098.65893555,40.97539902,0.00000000,0.00000000,0.00000000); //object(arprtermnl01_lvs) (1)
    CreateDynamicObject(8251,-191.45150757,-3122.57812500,25.88459969,0.00000000,0.00000000,270.00000000); //object(pltschlhnger02_lvs) (1)
    CreateDynamicObject(8550,-155.84739685,-3132.30371094,26.20479965,0.00000000,0.00000000,0.00000000); //object(laconcha_lvs) (1)
    CreateDynamicObject(9241,-244.88349915,-3152.39843750,24.11409950,0.00000000,0.00000000,0.00000000); //object(copbits_sfn) (1)
    CreateDynamicObject(10763,-116.17630005,-3088.63549805,33.87210083,0.00000000,0.00000000,315.00000000); //object(controltower_sfse) (1)
    CreateDynamicObject(3526,-791.52227783,-3175.32250977,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (1)
    CreateDynamicObject(3526,-791.52148438,-3175.32226562,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (3)
    CreateDynamicObject(3526,-7521484288.00000000,-3175.32226562,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (4)
    CreateDynamicObject(3526,-785.52148438,-3175.32226562,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (5)
    CreateDynamicObject(3526,-779.52069092,-3175.32202148,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (6)
    CreateDynamicObject(3526,-773.51989746,-3175.32177734,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (7)
    CreateDynamicObject(3526,-767.51910400,-3175.32153320,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (8)
    CreateDynamicObject(3526,-761.51831055,-3175.32128906,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (9)
    CreateDynamicObject(3526,-755.51751709,-3175.32104492,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (10)
    CreateDynamicObject(3526,-749.51672363,-3175.32080078,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (11)
    CreateDynamicObject(3526,-743.51593018,-3175.32055664,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (12)
    CreateDynamicObject(3526,-737.51513672,-3175.32031250,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (13)
    CreateDynamicObject(3526,-731.51434326,-3175.32006836,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (14)
    CreateDynamicObject(3526,-725.51354980,-3175.31982422,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (15)
    CreateDynamicObject(3526,-719.51275635,-3175.31958008,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (16)
    CreateDynamicObject(3526,-713.51196289,-3175.31933594,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (17)
    CreateDynamicObject(3526,-707.51116943,-3175.31909180,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (18)
    CreateDynamicObject(3526,-701.51037598,-3175.31884766,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (19)
    CreateDynamicObject(3526,-695.50958252,-3175.31860352,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (20)
    CreateDynamicObject(3526,-689.50878906,-3175.31835938,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (21)
    CreateDynamicObject(3526,-683.50799561,-3175.31811523,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (22)
    CreateDynamicObject(3526,-677.50720215,-3175.31787109,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (23)
    CreateDynamicObject(3526,-671.50640869,-3175.31762695,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (24)
    CreateDynamicObject(3526,-665.50561523,-3175.31738281,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (25)
    CreateDynamicObject(3526,-659.50482178,-3175.31713867,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (26)
    CreateDynamicObject(3526,-653.50402832,-3175.31689453,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (27)
    CreateDynamicObject(3526,-647.50323486,-3175.31665039,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (28)
    CreateDynamicObject(3526,-641.50244141,-3175.31640625,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (29)
    CreateDynamicObject(3526,-635.50164795,-3175.31616211,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (30)
    CreateDynamicObject(3526,-629.50085449,-3175.31591797,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (31)
    CreateDynamicObject(3526,-623.50006104,-3175.31567383,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (32)
    CreateDynamicObject(3526,-617.49926758,-3175.31542969,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (33)
    CreateDynamicObject(3526,-611.49847412,-3175.31518555,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (34)
    CreateDynamicObject(3526,-605.49768066,-3175.31494141,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (35)
    CreateDynamicObject(3526,-792.82550049,-3206.41088867,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (36)
    CreateDynamicObject(3526,-785.82519531,-3206.41015625,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (37)
    CreateDynamicObject(3526,-778.82489014,-3206.40942383,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (38)
    CreateDynamicObject(3526,-771.82458496,-3206.40869141,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (39)
    CreateDynamicObject(3526,-764.82427979,-3206.40795898,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (40)
    CreateDynamicObject(3526,-757.82397461,-3206.40722656,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (41)
    CreateDynamicObject(3526,-750.82366943,-3206.40649414,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (42)
    CreateDynamicObject(3526,-743.82336426,-3206.40576172,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (43)
    CreateDynamicObject(3526,-736.82305908,-3206.40502930,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (44)
    CreateDynamicObject(3526,-729.82275391,-3206.40429688,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (45)
    CreateDynamicObject(3526,-722.82244873,-3206.40356445,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (46)
    CreateDynamicObject(3526,-715.82214355,-3206.40283203,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (47)
    CreateDynamicObject(3526,-708.82183838,-3206.40209961,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (48)
    CreateDynamicObject(3526,-701.82153320,-3206.40136719,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (49)
    CreateDynamicObject(3526,-694.82122803,-3206.40063477,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (50)
    CreateDynamicObject(3526,-687.82092285,-3206.39990234,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (51)
    CreateDynamicObject(3526,-680.82061768,-3206.39916992,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (52)
    CreateDynamicObject(3526,-673.82031250,-3206.39843750,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (53)
    CreateDynamicObject(3526,-666.82000732,-3206.39770508,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (54)
    CreateDynamicObject(3526,-659.81970215,-3206.39697266,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (55)
    CreateDynamicObject(3526,-652.81939697,-3206.39624023,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (56)
    CreateDynamicObject(3526,-645.81909180,-3206.39550781,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (57)
    CreateDynamicObject(3526,-638.81878662,-3206.39477539,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (58)
    CreateDynamicObject(3526,-631.81848145,-3206.39404297,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (59)
    CreateDynamicObject(3526,-624.81817627,-3206.39331055,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (60)
    CreateDynamicObject(3526,-617.81787109,-3206.39257812,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (61)
    CreateDynamicObject(3526,-610.81756592,-3206.39184570,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (62)
    CreateDynamicObject(3526,-603.81726074,-3206.39111328,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (63)
    CreateDynamicObject(3526,-596.81695557,-3206.39038086,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (64)
    CreateDynamicObject(3526,-589.81665039,-3206.38964844,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (65)
    CreateDynamicObject(3526,-582.81634521,-3206.38891602,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (66)
    CreateDynamicObject(3526,-575.81604004,-3206.38818359,22.03669930,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (67)
    CreateDynamicObject(3666,-869.32330322,-3175.44677734,22.47310066,0.00000000,0.00000000,0.00000000); //object(airuntest_las) (1)
    CreateDynamicObject(3666,-869.22991943,-3206.32543945,22.47310066,0.00000000,0.00000000,0.00000000); //object(airuntest_las) (2)
    CreateDynamicObject(1232,-864.94158936,-3207.90649414,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (1)
    CreateDynamicObject(1232,-854.94140625,-3207.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (3)
    CreateDynamicObject(1232,-844.94122314,-3207.90600586,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (4)
    CreateDynamicObject(1232,-834.94104004,-3207.90576172,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (5)
    CreateDynamicObject(1232,-824.94085693,-3207.90551758,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (6)
    CreateDynamicObject(1232,-814.94067383,-3207.90527344,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (7)
    CreateDynamicObject(1232,-804.94049072,-3207.90502930,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (8)
    CreateDynamicObject(1232,-794.94030762,-3207.90478516,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (9)
    CreateDynamicObject(1232,-784.94012451,-3207.90454102,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (10)
    CreateDynamicObject(1232,-774.93994141,-3207.90429688,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (11)
    CreateDynamicObject(1232,-764.93975830,-3207.90405273,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (12)
    CreateDynamicObject(1232,-754.93957520,-3207.90380859,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (13)
    CreateDynamicObject(1232,-744.93939209,-3207.90356445,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (14)
    CreateDynamicObject(1232,-734.93920898,-3207.90332031,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (15)
    CreateDynamicObject(1232,-724.93902588,-3207.90307617,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (16)
    CreateDynamicObject(1232,-714.93884277,-3207.90283203,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (17)
    CreateDynamicObject(1232,-704.93865967,-3207.90258789,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (18)
    CreateDynamicObject(1232,-694.93847656,-3207.90234375,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (19)
    CreateDynamicObject(1232,-684.93829346,-3207.90209961,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (20)
    CreateDynamicObject(1232,-674.93811035,-3207.90185547,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (21)
    CreateDynamicObject(1232,-664.93792725,-3207.90161133,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (22)
    CreateDynamicObject(1232,-654.93774414,-3207.90136719,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (23)
    CreateDynamicObject(1232,-644.93756104,-3207.90112305,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (24)
    CreateDynamicObject(1232,-634.93737793,-3207.90087891,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (25)
    CreateDynamicObject(1232,-624.93719482,-3207.90063477,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (26)
    CreateDynamicObject(1232,-614.93701172,-3207.90039062,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (27)
    CreateDynamicObject(1232,-604.93682861,-3207.90014648,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (28)
    CreateDynamicObject(1232,-594.93664551,-3207.89990234,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (29)
    CreateDynamicObject(1232,-584.93646240,-3207.89965820,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (30)
    CreateDynamicObject(1232,-574.93627930,-3207.89941406,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (31)
    CreateDynamicObject(1232,-564.93609619,-3207.89916992,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (32)
    CreateDynamicObject(1232,-554.93591309,-3207.89892578,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (33)
    CreateDynamicObject(1232,-864.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (34)
    CreateDynamicObject(1232,-854.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (35)
    CreateDynamicObject(1232,-844.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (36)
    CreateDynamicObject(1232,-834.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (37)
    CreateDynamicObject(1232,-824.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (38)
    CreateDynamicObject(1232,-814.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (39)
    CreateDynamicObject(1232,-804.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (40)
    CreateDynamicObject(1232,-794.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (41)
    CreateDynamicObject(1232,-784.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (42)
    CreateDynamicObject(1232,-774.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (43)
    CreateDynamicObject(1232,-764.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (44)
    CreateDynamicObject(1232,-754.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (45)
    CreateDynamicObject(1232,-744.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (46)
    CreateDynamicObject(1232,-734.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (47)
    CreateDynamicObject(1232,-724.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (48)
    CreateDynamicObject(1232,-714.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (49)
    CreateDynamicObject(1232,-704.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (50)
    CreateDynamicObject(1232,-694.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (51)
    CreateDynamicObject(1232,-684.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (52)
    CreateDynamicObject(1232,-674.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (53)
    CreateDynamicObject(1232,-664.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (54)
    CreateDynamicObject(1232,-654.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (55)
    CreateDynamicObject(1232,-644.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (56)
    CreateDynamicObject(1232,-634.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (57)
    CreateDynamicObject(1232,-624.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (58)
    CreateDynamicObject(1232,-614.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (59)
    CreateDynamicObject(1232,-604.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (60)
    CreateDynamicObject(1232,-594.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (61)
    CreateDynamicObject(1232,-584.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (62)
    CreateDynamicObject(1232,-574.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (63)
    CreateDynamicObject(1232,-564.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (64)
    CreateDynamicObject(1232,-554.94140625,-3172.90625000,24.58869934,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (65)
    CreateDynamicObject(1238,-881.12927246,-3177.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (5)
    CreateDynamicObject(1238,-881.10363770,-3178.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (6)
    CreateDynamicObject(1238,-881.07800293,-3179.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (7)
    CreateDynamicObject(1238,-881.05236816,-3180.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (8)
    CreateDynamicObject(1238,-881.02673340,-3181.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (9)
    CreateDynamicObject(1238,-881.00109863,-3182.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (10)
    CreateDynamicObject(1238,-880.97546387,-3183.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (11)
    CreateDynamicObject(1238,-880.94982910,-3184.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (12)
    CreateDynamicObject(1238,-880.92419434,-3185.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (13)
    CreateDynamicObject(1238,-880.89855957,-3186.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (14)
    CreateDynamicObject(1238,-880.87292480,-3187.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (15)
    CreateDynamicObject(1238,-880.84729004,-3188.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (16)
    CreateDynamicObject(1238,-880.82165527,-3189.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (17)
    CreateDynamicObject(1238,-880.79602051,-3190.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (18)
    CreateDynamicObject(1238,-880.77038574,-3191.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (19)
    CreateDynamicObject(1238,-880.74475098,-3192.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (20)
    CreateDynamicObject(1238,-880.71911621,-3193.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (21)
    CreateDynamicObject(1238,-880.69348145,-3194.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (22)
    CreateDynamicObject(1238,-880.66784668,-3195.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (23)
    CreateDynamicObject(1238,-880.64221191,-3196.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (24)
    CreateDynamicObject(1238,-880.61657715,-3197.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (25)
    CreateDynamicObject(1238,-880.59094238,-3198.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (26)
    CreateDynamicObject(1238,-880.56530762,-3199.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (27)
    CreateDynamicObject(1238,-880.53967285,-3200.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (28)
    CreateDynamicObject(1238,-880.51403809,-3201.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (29)
    CreateDynamicObject(1238,-880.48840332,-3202.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (30)
    CreateDynamicObject(1238,-880.46276855,-3203.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (31)
    CreateDynamicObject(1238,-880.43713379,-3204.60156250,22.27759933,0.00000000,0.00000000,0.00000000); //object(trafficcone) (32)
    CreateDynamicObject(1290,-84.87950134,-3191.15502930,27.97260094,0.00000000,0.00000000,90.00000000); //object(lamppost2) (1)
    CreateDynamicObject(1290,-84.91410065,-3201.43457031,27.97260094,0.00000000,0.00000000,90.00000000); //object(lamppost2) (2)
    CreateDynamicObject(1290,-84.83399963,-3181.52807617,27.97260094,0.00000000,0.00000000,90.00000000); //object(lamppost2) (3)
    CreateDynamicObject(1232,-120.91829681,-3154.62182617,24.99180031,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (66)
    CreateDynamicObject(1232,-203.75669861,-3162.89306641,24.99180031,0.00000000,0.00000000,0.00000000); //object(streetlamp1) (67)
    
    // BLUBERY AIRPORT
    CreateDynamicObject(3998,-18.72460938,-159.33691406,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(1)
    CreateDynamicObject(3998,-13.19238281,-138.58007812,-8.74690723,0.00000000,0.00000000,344.98718262); //object(court1_lan)(2)
    CreateDynamicObject(3998,-7.60449219,-117.77832031,-8.74690723,0.00000000,0.00000000,344.99267578); //object(court1_lan)(3)
    CreateDynamicObject(3998,-2.08794737,-97.05231476,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(4)
    CreateDynamicObject(3998,3.55175781,-76.20605469,-8.74690723,0.00000000,0.00000000,344.99267578); //object(court1_lan)(5)
    CreateDynamicObject(3998,9.12784100,-55.41535187,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(6)
    CreateDynamicObject(3998,14.57519531,-35.11621094,-8.74690723,0.00000000,0.00000000,344.99267578); //object(court1_lan)(7)
    CreateDynamicObject(3998,19.97670174,-15.20260048,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(8)
    CreateDynamicObject(3998,25.42668343,5.19435501,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(9)
    CreateDynamicObject(3998,30.96191406,25.86230469,-8.74690723,0.00000000,0.00000000,344.99267578); //object(court1_lan)(10)
    CreateDynamicObject(3998,36.49764252,46.49599075,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(11)
    CreateDynamicObject(3998,41.89724350,66.52142334,-8.74690723,0.00000000,0.00000000,344.99816895); //object(court1_lan)(12)
    CreateDynamicObject(3998,4.37061548,-165.47891235,-10.05139446,0.00000000,6.00000000,344.99816895); //object(court1_lan)(13)
    CreateDynamicObject(3998,25.51497650,-171.12634277,-12.35343075,0.00000000,5.99853516,344.99267578); //object(court1_lan)(14)
    CreateDynamicObject(3998,47.47753906,87.29394531,-8.74690723,0.00000000,0.00000000,344.98718262); //object(court1_lan)(15)
    CreateDynamicObject(3998,31.44531250,-61.98144531,-10.28159809,0.00000000,7.49816895,344.99267578); //object(court1_lan)(18)
    CreateDynamicObject(3998,54.23301697,-68.15390778,-13.39302349,0.00000000,7.49816895,344.99267578); //object(court1_lan)(19)
    CreateDynamicObject(3998,-20.73075294,-166.81823730,-8.28649998,356.25000000,0.00000000,344.99816895); //object(court1_lan)(22)
    CreateDynamicObject(3998,-40.50292969,-151.63085938,-10.51180172,0.00000000,350.99670410,344.98718262); //object(court1_lan)(23)
    CreateDynamicObject(3998,-50.96747589,-148.76527405,-11.12567806,0.00000000,0.00000000,344.99816895); //object(court1_lan)(24)
    CreateDynamicObject(3998,-54.47106171,-116.20841217,-11.12567806,0.00000000,0.00000000,255.03186035); //object(court1_lan)(25)
    CreateDynamicObject(3998,-36.50911713,-120.92005157,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(26)
    CreateDynamicObject(3998,-48.29334641,-93.03331757,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(27)
    CreateDynamicObject(3998,-34.40805054,-96.82485962,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(28)
    CreateDynamicObject(3998,-42.56882858,-71.32667542,-11.12567806,0.00000000,0.00000000,255.03186035); //object(court1_lan)(29)
    CreateDynamicObject(3998,-28.37181473,-74.88730621,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(30)
    CreateDynamicObject(3998,-23.32267189,-53.45492554,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(31)
    CreateDynamicObject(3998,-37.00031662,-50.09704208,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(32)
    CreateDynamicObject(3998,-16.17675781,-30.45800781,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(33)
    CreateDynamicObject(3998,-30.70117188,-26.17285156,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(34)
    CreateDynamicObject(3998,-11.00097656,-6.06738281,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(35)
    CreateDynamicObject(8038,-31.15399933,-29.90777206,22.09459496,0.00000000,0.00000000,346.50000000); //object(arprtermnl01_lvs)(1)
    CreateDynamicObject(8253,-42.48398209,-82.45592499,6.04542208,0.00000000,0.00000000,254.67243958); //object(pltschlhnger01_lvs)(1)
    CreateDynamicObject(3998,-53.47362518,-79.76937866,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(36)
    CreateDynamicObject(3998,-60.39414978,-102.51128387,-11.12567806,0.00000000,0.00000000,255.03112793); //object(court1_lan)(37)
    CreateDynamicObject(3998,-60.52441406,-126.27636719,-11.12567806,0.00000000,0.00000000,284.13940430); //object(court1_lan)(38)
    CreateDynamicObject(10810,-29.25564957,-21.97941399,16.01921463,0.00000000,0.00000000,271.73266602); //object(ap_smallradar1_sfse)(1)
    CreateDynamicObject(1682,-27.10839844,-16.87402344,27.47344208,0.00000000,0.00000000,0.00000000); //object(ap_radar1_01)(1)
    CreateDynamicObject(982,2.87909365,-129.67477417,4.87302208,0.00000000,55.76916504,344.99816895); //object(fenceshit)(1)
    CreateDynamicObject(982,9.52001953,-104.92415619,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(982,16.18976974,-80.21218872,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(982,30.96541023,-25.20412827,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(982,37.68576431,-0.44858211,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(982,44.34778595,24.32898521,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(982,50.89066315,49.02568436,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(982,57.48427200,73.68656158,4.87302208,0.00000000,55.76660156,344.99267578); //object(fenceshit)(1)
    CreateDynamicObject(984,62.40929413,92.32617950,4.74941254,0.00000000,58.42959595,345.75000000); //object(fenceshit2)(1)
    CreateDynamicObject(984,37.04320526,100.02321625,4.74941254,0.00000000,58.42529297,165.31054688); //object(fenceshit2)(3)
    CreateDynamicObject(982,32.13946533,81.56800842,4.87302208,0.00000000,55.76660156,164.89782715); //object(fenceshit)(1)
    CreateDynamicObject(982,25.50611496,57.03316498,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,18.86572647,32.47778320,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,12.23672485,7.85794115,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,5.67357349,-16.78681374,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,-0.98209095,-41.45229721,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,-7.60679293,-66.03464508,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,-14.15904140,-90.64982605,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,-20.83760262,-115.34452057,4.87302208,0.00000000,55.76660156,164.89379883); //object(fenceshit)(1)
    CreateDynamicObject(982,-20.94130516,-167.09271240,5.17996025,0.00000000,51.25671387,254.94873047); //object(fenceshit)(1)
    CreateDynamicObject(982,12.05522728,-146.14184570,3.33832908,5.99737549,55.46978760,75.41629028); //object(fenceshit)(1)
    CreateDynamicObject(982,5.75992918,-166.91343689,3.41506386,354.66195679,53.85394287,255.79830933); //object(fenceshit)(1)
    CreateDynamicObject(983,-34.37255478,-154.75393677,4.33543682,352.21728516,310.01629639,76.46624756); //object(fenceshit3)(1)
    CreateDynamicObject(983,-34.37255478,-154.75393677,4.33543682,352.21728516,310.01629639,76.46624756); //object(fenceshit3)(3)
    CreateDynamicObject(3578,58.59766388,99.65835571,3.73974705,0.00000000,0.00000000,345.75000000); //object(dockbarr1_la)(1)
    CreateDynamicObject(3578,48.77707672,102.16371155,3.73974705,0.00000000,0.00000000,345.74523926); //object(dockbarr1_la)(2)
    CreateDynamicObject(3578,43.91406631,103.43492126,3.73974705,0.00000000,0.00000000,345.74523926); //object(dockbarr1_la)(3)
    CreateDynamicObject(3578,47.66450119,105.05457306,3.73974705,0.00000000,0.00000000,316.56561279); //object(dockbarr1_la)(4)
    CreateDynamicObject(3578,56.83557510,102.60681152,3.73974705,0.00000000,0.00000000,13.01345825); //object(dockbarr1_la)(5)
    CreateDynamicObject(3578,54.91682816,89.41629791,3.73974705,0.00000000,0.00000000,345.74523926); //object(dockbarr1_la)(6)
    CreateDynamicObject(3578,54.97815704,89.63766479,3.73974705,0.00000000,0.00000000,345.74523926); //object(dockbarr1_la)(7)
    CreateDynamicObject(3578,54.99825287,89.71060181,3.73974705,0.00000000,0.00000000,345.74523926); //object(dockbarr1_la)(8)
    CreateDynamicObject(3578,54.99804688,89.70996094,3.73974705,0.00000000,0.00000000,345.74523926); //object(dockbarr1_la)(9)
    CreateDynamicObject(3578,51.48292923,95.26336670,3.73974705,0.00000000,0.00000000,73.82281494); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,51.70312500,95.20019531,3.73974705,0.00000000,0.00000000,73.81713867); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,51.85089874,95.15876770,3.73974705,0.00000000,0.00000000,73.82263184); //object(dockbarr1_la)(12)
    CreateDynamicObject(3578,51.85058594,95.15820312,3.73974705,0.00000000,0.00000000,73.82263184); //object(dockbarr1_la)(13)
    CreateDynamicObject(3578,57.68191910,98.61031342,3.73974705,0.00000000,0.00000000,164.90020752); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,57.63288116,98.39788818,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,57.64911652,98.22665405,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(16)
    CreateDynamicObject(3578,56.19107819,93.59613037,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,56.34493637,93.78280640,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(18)
    CreateDynamicObject(3578,56.32842255,93.95303345,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(19)
    CreateDynamicObject(3578,42.27921295,92.68367767,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(20)
    CreateDynamicObject(3578,42.33105469,92.82714844,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(21)
    CreateDynamicObject(3578,42.38378906,92.97070312,3.73974705,0.00000000,0.00000000,164.89929199); //object(dockbarr1_la)(22)
    CreateDynamicObject(3578,39.06451035,98.59368896,3.73974705,0.00000000,0.00000000,72.39208984); //object(dockbarr1_la)(23)
    CreateDynamicObject(3578,39.28054047,98.51339722,3.73974705,0.00000000,0.00000000,72.38891602); //object(dockbarr1_la)(24)
    CreateDynamicObject(3578,39.42382812,98.45898438,3.73974705,0.00000000,0.00000000,72.38342285); //object(dockbarr1_la)(25)
    CreateDynamicObject(3578,45.49649429,101.94005585,3.73974705,0.00000000,0.00000000,165.30627441); //object(dockbarr1_la)(26)
    CreateDynamicObject(3578,45.41671753,101.72336578,3.73974705,0.00000000,0.00000000,165.30578613); //object(dockbarr1_la)(27)
    CreateDynamicObject(3578,45.38955688,101.65062714,3.73974705,0.00000000,0.00000000,165.30578613); //object(dockbarr1_la)(28)
    CreateDynamicObject(3578,43.76620865,97.23342896,3.73974705,0.00000000,0.00000000,165.30578613); //object(dockbarr1_la)(29)
    CreateDynamicObject(3578,43.81854248,97.37745667,3.73974705,0.00000000,0.00000000,165.30578613); //object(dockbarr1_la)(30)
    CreateDynamicObject(3578,43.81835938,97.37695312,3.73974705,0.00000000,0.00000000,165.30578613); //object(dockbarr1_la)(31)
    CreateDynamicObject(3578,43.91493225,97.66830444,3.73974705,0.00000000,0.00000000,165.30578613); //object(dockbarr1_la)(31)
    CreateDynamicObject(3578,58.13627243,81.17163849,3.73974705,0.00000000,0.00000000,75.31713867); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,55.59141541,71.49800110,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,53.09201813,61.91468430,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,50.54165649,52.23110962,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,48.11720657,43.04608154,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,45.57064056,33.37720490,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,43.06095886,23.77081490,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,40.46273804,13.98590565,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,37.83530807,4.06683445,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,35.24284744,-5.84439278,3.73974705,0.00000000,0.00000000,75.31677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,32.60776901,-15.60046768,3.73974705,0.00000000,0.00000000,74.56677246); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,29.83089638,-25.53219223,3.73974705,0.00000000,0.00000000,74.56420898); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,27.06368637,-35.40742111,3.73974705,0.00000000,0.00000000,74.56420898); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,24.46285820,-44.90364838,3.73974705,0.00000000,0.00000000,75.31420898); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,21.97964287,-54.35030746,3.73974705,0.00000000,0.00000000,75.31127930); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,19.42608833,-64.07034302,3.73974705,0.00000000,0.00000000,75.31127930); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,16.82403946,-73.89602661,3.73974705,0.00000000,0.00000000,75.31127930); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,14.27989960,-83.55502319,3.73974705,0.00000000,0.00000000,75.31127930); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,11.68870163,-93.38839722,3.73974705,0.00000000,0.00000000,75.31127930); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,9.05886269,-103.10108948,3.73974705,0.00000000,0.00000000,74.56127930); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,6.31953907,-112.96355438,3.73974705,0.00000000,0.00000000,74.55871582); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,3.84535027,-122.20917511,3.73974705,0.00000000,0.00000000,75.30871582); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,1.26397717,-131.91600037,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-1.34193802,-141.77256775,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,36.62014008,87.78169250,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,34.15148544,78.44627380,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,31.63905716,68.94515228,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,29.10676765,59.36998749,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,26.42203140,49.21809387,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,24.88792419,43.41717529,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,22.41555786,34.07638168,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,20.06114388,25.00570488,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,17.50649261,15.21264172,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,15.03736401,5.85365582,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,12.45436382,-3.89882851,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,9.93174171,-13.40007305,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,7.36209631,-23.13405800,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,4.81194592,-32.83556747,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,2.46330523,-41.62325668,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-0.04228477,-51.13892746,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-2.61689496,-60.74879074,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-4.97493744,-69.79384613,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-7.42830276,-79.05742645,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-9.93511581,-88.54328918,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-12.29438305,-97.49062347,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-14.76155186,-106.78970337,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-17.32977867,-116.65545654,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-19.82993698,-126.25325012,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-20.85495186,-130.41333008,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,46.81455612,83.87158966,3.73974705,0.00000000,0.00000000,75.30578613); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,42.86571884,69.01259613,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,39.07312012,55.50061035,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,35.80416489,43.33608627,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,32.57102585,31.33255959,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,28.95779800,17.52555466,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,25.08837700,3.07365322,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,21.54807472,-10.00054932,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,17.95476913,-23.61384583,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,14.00158882,-38.24240112,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,10.10159016,-52.80334473,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,6.17342663,-68.00315857,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,6.17285156,-68.00292969,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,2.45411539,-81.20056915,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-0.95165801,-93.43223572,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-4.73209572,-106.70212555,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-8.19389153,-119.85330200,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-11.79938984,-133.28857422,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-14.80216885,-144.66990662,3.73974705,0.00000000,0.00000000,75.30029297); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-11.68762970,-151.97697449,3.73974705,0.00000000,0.00000000,150.69827271); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,0.47354934,-155.83515930,3.20260358,0.00000000,354.00000000,168.62353516); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,9.82499027,-157.72360229,2.20505142,0.00000000,353.99597168,168.61816406); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,19.99168968,-159.77561951,1.05403125,0.00000000,353.99597168,168.61816406); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,29.18781471,-161.61184692,0.13321516,0.00000000,353.99597168,168.61816406); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-19.79093552,-145.13926697,3.73974705,0.00000000,0.00000000,6.85131836); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-32.71739960,-143.88888550,3.04913402,0.00000000,351.00000000,345.84997559); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-42.28536606,-141.47128296,1.43770456,0.00000000,351.00000000,345.84997559); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-45.85630417,-137.27845764,1.36096990,0.00000000,359.99670410,306.17001343); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,-47.78904343,-128.14849854,1.36096990,0.00000000,359.99450684,257.96801758); //object(dockbarr1_la)(11)
    CreateDynamicObject(3526,-24.72949219,-134.17480469,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-28.07624245,-145.15316772,4.67048264,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-30.98947334,-155.20475769,4.56770849,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-30.02535248,-159.18283081,4.72794104,0.00000000,0.00000000,257.66516113); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-27.04337120,-159.58227539,4.70260668,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-24.27186394,-160.15512085,4.69182920,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-21.10461807,-160.82620239,4.68055391,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-18.57805824,-161.34014893,4.67020464,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-16.00032616,-162.13873291,4.67701578,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-13.39468861,-162.89082336,4.68040800,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-10.33061600,-163.70130920,4.67971468,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-8.35761356,-164.58088684,4.70192385,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-8.40316010,-164.43759155,4.75828505,0.00000000,0.00000000,257.66235352); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-15.90432644,-103.88693237,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-7.38361120,-75.00187683,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-0.86842632,-49.57639694,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,5.60801029,-24.30213928,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,11.06621361,-3.00157356,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,17.07155991,20.43409348,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,22.82331085,40.36695480,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,27.31194687,57.88367462,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,31.12884521,72.77896881,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,36.18061447,92.30141449,4.56482363,0.00000000,0.00000000,165.76721191); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,59.94849396,86.10588074,4.56482363,0.00000000,0.00000000,346.42236328); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,55.37370682,67.90324402,4.56482363,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,50.73938370,50.68751526,4.56482363,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,45.42549515,30.94736481,4.56482363,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,39.18060684,7.74871349,4.56482363,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,33.92028427,-11.79660702,4.58941507,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,27.24139786,-35.05279922,4.58941507,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,20.14425850,-61.41733932,4.58941507,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,13.00812340,-87.92666626,4.58941507,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,6.21098232,-113.17672729,4.58941507,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,-1.22195530,-140.78869629,4.58941507,0.00000000,0.00000000,346.42089844); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,39.24982834,104.74408722,4.58941507,0.00000000,0.00000000,255.08319092); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,51.52765274,101.45405579,4.58941507,0.00000000,0.00000000,255.08056641); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,63.46421814,98.48883057,4.58941507,0.00000000,0.00000000,255.08056641); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,58.87779999,123.64532471,1.14654291,0.00000000,0.00000000,255.08056641); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,54.87130737,113.05448151,2.50827575,0.00000000,0.00000000,255.08056641); //object(vegasairportlight)(28)
    CreateDynamicObject(3526,64.60215759,142.29647827,1.49810541,0.00000000,0.00000000,255.08056641); //object(vegasairportlight)(28)
    CreateDynamicObject(3666,64.24782562,103.34834290,1.83578849,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(1)
    CreateDynamicObject(3666,58.42560196,104.81887054,2.01127601,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(2)
    CreateDynamicObject(3666,47.82348633,108.10483551,2.62108302,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(3)
    CreateDynamicObject(3666,40.81050873,109.55719757,2.45976043,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(4)
    CreateDynamicObject(3666,-20.02692413,-166.40252686,5.46071815,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(5)
    CreateDynamicObject(3666,68.74459839,159.90664673,0.00000000,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(6)
    CreateDynamicObject(3666,67.13788605,153.53182983,0.93541384,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(7)
    CreateDynamicObject(3666,65.59866333,147.01606750,1.94337249,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(8)
    CreateDynamicObject(3666,62.95196533,136.23095703,1.94337249,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(9)
    CreateDynamicObject(3877,74.99897766,155.90504456,0.89252257,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(1)
    CreateDynamicObject(3877,56.57617188,157.64579773,0.52387965,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(2)
    CreateDynamicObject(3877,65.45717621,103.69956970,3.01430559,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(3)
    CreateDynamicObject(3877,-21.73263168,1.14323807,12.68651581,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(4)
    CreateDynamicObject(3877,39.93556976,109.95993805,3.42512894,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(5)
    CreateDynamicObject(980,-2.87936521,5.07355928,4.89102602,0.00000000,0.00000000,166.88574219); //object(airportgate)(1)
    CreateDynamicObject(980,5.33379698,2.85732651,4.89102602,0.00000000,0.00000000,166.88232422); //object(airportgate)(2)
    CreateDynamicObject(979,-6.96761227,-9.43887424,2.95785475,0.00000000,0.00000000,351.00000000); //object(sub_roadleft)(1)
    CreateDynamicObject(979,-3.43381238,-14.62789345,2.95785475,0.00000000,0.00000000,259.91912842); //object(sub_roadleft)(2)
    CreateDynamicObject(978,-6.05143118,-27.75424004,2.95785475,0.00000000,0.00000000,256.99282837); //object(sub_roadright)(2)
    CreateDynamicObject(978,-8.14589691,-36.49548721,2.95785475,0.00000000,0.00000000,256.99218750); //object(sub_roadright)(3)
    CreateDynamicObject(978,-13.99210358,-41.14665985,2.95785475,0.00000000,0.00000000,186.50440979); //object(sub_roadright)(4)
    CreateDynamicObject(3031,-32.26595688,-61.80746460,36.09679031,0.00000000,0.00000000,0.00000000); //object(wong_dish)(1)
    CreateDynamicObject(625,-11.65862274,-19.44857788,2.11763477,0.00000000,0.00000000,0.00000000); //object(veg_palmkb1)(1)
    CreateDynamicObject(625,-12.63775826,-23.18263435,2.11763477,0.00000000,0.00000000,0.00000000); //object(veg_palmkb1)(2)
    CreateDynamicObject(3268,81.69821167,82.41506195,0.44491386,0.00000000,0.00000000,65.37860107); //object(mil_hangar1_)(1)
    CreateDynamicObject(3268,108.77467346,69.90948486,0.44491386,0.00000000,0.00000000,65.37414551); //object(mil_hangar1_)(2)
    CreateDynamicObject(2775,-14.65527344,-22.42382812,8.02007961,0.00000000,0.00000000,0.00000000); //object(cj_airprt_mon)(1)
    CreateDynamicObject(3877,99.19525909,84.92005920,5.85787487,286.32254028,0.00000000,338.25000000); //object(sf_rooflite)(8)
    CreateDynamicObject(4003,-14.52263641,-22.38781738,9.95610428,0.00000000,0.00000000,260.26223755); //object(lacityhalltrans_lan)(1)
    CreateDynamicObject(16098,117.10379028,-34.23196411,5.56666088,0.00000000,0.00000000,0.00000000); //object(des_by_hangar_)(1)
    CreateDynamicObject(9241,122.50456238,10.27751446,0.26225537,0.00000000,0.00000000,0.00000000); //object(copbits_sfn)(1)
    CreateDynamicObject(9241,147.68077087,10.30800343,0.26225537,0.00000000,0.00000000,0.00000000); //object(copbits_sfn)(2)
    CreateDynamicObject(9241,132.15911865,35.26538849,0.26225537,0.00000000,0.00000000,0.00000000); //object(copbits_sfn)(3)
    CreateDynamicObject(11495,128.99514771,152.68237305,0.00000000,0.00000000,0.00000000,179.56536865); //object(des_ranchjetty)(1)
    CreateDynamicObject(1461,129.09877014,134.71389771,2.23090076,0.00000000,0.00000000,0.00000000); //object(dyn_life_p)(1)
    CreateDynamicObject(1637,127.53810883,117.60537720,2.71596241,0.00000000,0.00000000,170.29589844); //object(od_pat_hutb)(1)
    CreateDynamicObject(9819,-40.01232910,-59.99261093,42.30744553,0.00000000,0.00000000,166.74493408); //object(shpbridge_sfw02)(1)
    CreateDynamicObject(16782,-41.32546997,-60.25956345,43.73264313,0.00000000,0.00000000,345.00000000); //object(a51_radar_scan)(2)
    CreateDynamicObject(3383,-36.06971741,-60.87696838,41.45397186,0.00000000,0.00000000,77.30816650); //object(a51_labtable1_)(2)
    CreateDynamicObject(1649,-34.12719345,-56.83065033,43.79471970,0.00000000,0.00000000,346.50000000); //object(wglasssmash)(3)
    CreateDynamicObject(1649,-38.22933960,-55.83763504,43.79471970,0.00000000,0.00000000,346.49780273); //object(wglasssmash)(10)
    CreateDynamicObject(1649,-40.30247116,-64.26875305,43.79471970,0.00000000,0.00000000,346.49780273); //object(wglasssmash)(11)
    CreateDynamicObject(1649,-36.14621735,-65.29425812,43.79471970,0.00000000,0.00000000,346.49780273); //object(wglasssmash)(12)
    CreateDynamicObject(1649,-33.51970291,-63.72034454,43.79471970,0.00000000,0.00000000,76.89575195); //object(wglasssmash)(13)
    CreateDynamicObject(1649,-32.51406860,-59.48686218,43.79471970,0.00000000,0.00000000,76.89331055); //object(wglasssmash)(14)
    CreateDynamicObject(1649,-40.85342026,-57.47121811,43.79471970,0.00000000,0.00000000,76.89331055); //object(wglasssmash)(15)
    CreateDynamicObject(1649,-41.85636520,-61.58260345,43.79471970,0.00000000,0.00000000,76.89331055); //object(wglasssmash)(16)
    CreateDynamicObject(3095,-37.09883499,-60.47792053,44.99113464,0.00000000,0.00000000,346.50000000); //object(a51_jetdoor)(2)
    
    // PALAMINO AIRPORT
    CreateDynamicObject(3998,2464.82250977,-199.30180359,13.27782917,0.00000000,0.00000000,90.85714722); //object(court1_lan)(1)
    CreateDynamicObject(3998,2443.22753906,-199.63671875,13.27782917,0.00000000,0.00000000,90.85144043); //object(court1_lan)(2)
    CreateDynamicObject(3998,2421.79980469,-199.95410156,13.27782917,0.00000000,0.00000000,90.85144043); //object(court1_lan)(3)
    CreateDynamicObject(3998,2401.29003906,-200.25097656,13.27782917,0.00000000,0.00000000,90.85144043); //object(court1_lan)(4)
    CreateDynamicObject(3998,2380.14550781,-200.56391907,13.27782917,0.00000000,0.00000000,90.85693359); //object(court1_lan)(5)
    CreateDynamicObject(3998,2359.26025391,-200.86547852,13.27782917,0.00000000,0.00000000,90.85693359); //object(court1_lan)(6)
    CreateDynamicObject(3998,2337.81640625,-201.18164062,13.27782917,0.00000000,0.00000000,90.85144043); //object(court1_lan)(7)
    CreateDynamicObject(3998,2468.66235352,-199.31719971,13.77668858,352.79998779,0.00000000,90.85693359); //object(court1_lan)(8)
    CreateDynamicObject(3998,2387.73925781,-149.70410156,15.48610210,0.00000000,0.00000000,180.92285156); //object(court1_lan)(10)
    CreateDynamicObject(3998,2388.05981445,-169.61811829,15.46270084,352.79144287,0.00000000,180.92834473); //object(court1_lan)(13)
    CreateDynamicObject(3998,2387.38671875,-128.14941406,15.48610210,0.00000000,0.00000000,180.92285156); //object(court1_lan)(14)
    CreateDynamicObject(3998,2362.13256836,-130.27169800,15.48610210,0.00000000,0.00000000,180.92834473); //object(court1_lan)(15)
    CreateDynamicObject(3998,2345.90527344,-130.53561401,15.48610210,0.00000000,0.00000000,180.92834473); //object(court1_lan)(16)
    CreateDynamicObject(3998,2345.56054688,-109.00585938,15.48610210,0.00000000,0.00000000,180.93334961); //object(court1_lan)(17)
    CreateDynamicObject(3998,2371.02709961,-108.60276794,15.48610210,0.00000000,0.00000000,180.92834473); //object(court1_lan)(18)
    CreateDynamicObject(3998,2387.04687500,-106.62500000,15.48610210,0.00000000,0.00000000,180.92285156); //object(court1_lan)(19)
    CreateDynamicObject(3998,2386.70019531,-85.24098969,15.48610210,0.00000000,0.00000000,180.92834473); //object(court1_lan)(20)
    CreateDynamicObject(3998,2386.67846680,-76.81017303,15.48610210,0.00000000,0.00000000,180.01031494); //object(court1_lan)(21)
    CreateDynamicObject(3998,2412.19091797,-76.80148315,15.48610210,0.00000000,0.00000000,180.00549316); //object(court1_lan)(22)
    CreateDynamicObject(3998,2437.74682617,-76.82516479,15.48610210,0.00000000,0.00000000,180.00549316); //object(court1_lan)(23)
    CreateDynamicObject(3998,2463.25830078,-76.81542206,15.48610210,0.00000000,0.00000000,180.00549316); //object(court1_lan)(24)
    CreateDynamicObject(3998,2455.60644531,-64.34280396,15.48610210,0.00000000,0.00000000,270.21423340); //object(court1_lan)(25)
    CreateDynamicObject(3998,2412.43945312,-98.18652344,15.48610210,0.00000000,0.00000000,180.92285156); //object(court1_lan)(26)
    CreateDynamicObject(3998,2437.91259766,-97.79803467,15.48610210,0.00000000,0.00000000,180.92834473); //object(court1_lan)(27)
    CreateDynamicObject(6296,2377.27758789,-104.06232452,30.94349289,0.00000000,0.00000000,314.08004761); //object(veropolice_law2)(1)
    CreateDynamicObject(3998,2367.65429688,-99.26269531,15.48610210,0.00000000,0.00000000,142.97607422); //object(court1_lan)(29)
    CreateDynamicObject(16564,2369.66699219,-93.33691406,28.55513000,0.00000000,0.00000000,90.20324707); //object(des_stmedicentre_)(1)
    CreateDynamicObject(3998,2370.11523438,-76.84277344,15.48610210,0.00000000,0.00000000,180.00549316); //object(court1_lan)(30)
    CreateDynamicObject(14394,2356.58789062,-79.66810608,27.90640068,0.00000000,0.00000000,0.00000000); //object(dr_gsnew10)(1)
    CreateDynamicObject(14394,2354.67578125,-79.67407990,26.51211357,0.00000000,0.00000000,0.00000000); //object(dr_gsnew10)(2)
    CreateDynamicObject(14394,2352.76196289,-79.67629242,25.11885643,0.00000000,0.00000000,0.00000000); //object(dr_gsnew10)(3)
    CreateDynamicObject(14394,2356.58764648,-87.28503418,27.90640068,0.00000000,0.00000000,0.00000000); //object(dr_gsnew10)(4)
    CreateDynamicObject(14394,2354.67309570,-87.28447723,26.51211357,0.00000000,0.00000000,0.00000000); //object(dr_gsnew10)(5)
    CreateDynamicObject(14394,2352.75976562,-87.29113770,25.11885643,0.00000000,0.00000000,0.00000000); //object(dr_gsnew10)(6)
    CreateDynamicObject(14394,2354.62597656,-93.61689758,27.90640068,0.00000000,0.00000000,323.02832031); //object(dr_gsnew10)(7)
    CreateDynamicObject(14394,2353.12158203,-92.48509216,26.51211357,0.00000000,0.00000000,322.51428223); //object(dr_gsnew10)(9)
    CreateDynamicObject(14394,2351.60742188,-91.31705475,25.11599159,0.00000000,0.00000000,322.50915527); //object(dr_gsnew10)(10)
    CreateDynamicObject(4724,2357.26684570,-93.47684479,26.65219498,350.33499146,0.31039429,233.50744629); //object(librarywall_lan2)(1)
    CreateDynamicObject(3578,2324.82812500,-193.33750916,25.74860382,0.00000000,0.00000000,0.91799927); //object(dockbarr1_la)(1)
    CreateDynamicObject(3578,2324.83056641,-193.83872986,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(2)
    CreateDynamicObject(3578,2324.83642578,-194.34867859,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(3)
    CreateDynamicObject(3578,2320.02587891,-198.29801941,25.74860382,0.00000000,0.00000000,90.83935547); //object(dockbarr1_la)(4)
    CreateDynamicObject(3578,2320.53710938,-198.29093933,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(5)
    CreateDynamicObject(3578,2321.05175781,-198.28222656,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(6)
    CreateDynamicObject(3578,2333.71386719,-202.98828125,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.70800781,-202.48303223,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(11)
    CreateDynamicObject(3578,2333.70654297,-201.97775269,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(12)
    CreateDynamicObject(3578,2338.56665039,-198.02513123,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(13)
    CreateDynamicObject(3578,2338.05566406,-198.03222656,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2337.55078125,-198.03417969,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2338.68188477,-208.58885193,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(16)
    CreateDynamicObject(3578,2338.18750000,-208.59667969,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2337.70654297,-208.60560608,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(18)
    CreateDynamicObject(3578,2463.77856445,-205.64747620,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(25)
    CreateDynamicObject(3578,2463.27343750,-205.65332031,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(26)
    CreateDynamicObject(3578,2462.78002930,-205.65876770,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(27)
    CreateDynamicObject(3578,2445.00756836,-193.68681335,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(40)
    CreateDynamicObject(3578,2445.45629883,-193.70269775,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(41)
    CreateDynamicObject(3578,2445.94531250,-193.68008423,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(42)
    CreateDynamicObject(3578,2458.93505859,-210.62388611,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(49)
    CreateDynamicObject(3578,2458.92675781,-210.12141418,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(50)
    CreateDynamicObject(3578,2458.91894531,-209.61946106,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(51)
    CreateDynamicObject(3578,2449.97729492,-200.96481323,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(52)
    CreateDynamicObject(3578,2449.97851562,-201.47328186,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(53)
    CreateDynamicObject(3578,2449.97827148,-201.97872925,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(54)
    CreateDynamicObject(3578,2445.15820312,-205.93690491,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(56)
    CreateDynamicObject(3578,2445.66528320,-205.93066406,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(57)
    CreateDynamicObject(3578,2446.17724609,-205.92549133,25.74860382,0.00000000,0.00000000,90.83496094); //object(dockbarr1_la)(58)
    CreateDynamicObject(3578,2344.50170898,-189.76083374,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(62)
    CreateDynamicObject(3578,2354.65161133,-189.60882568,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(63)
    CreateDynamicObject(3578,2364.85424805,-189.45491028,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(64)
    CreateDynamicObject(3578,2371.45166016,-189.34339905,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(65)
    CreateDynamicObject(3578,2387.93847656,-188.93164062,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2405.55102539,-188.84516907,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(68)
    CreateDynamicObject(3578,2415.74755859,-188.69340515,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(69)
    CreateDynamicObject(3578,2425.98852539,-188.54248047,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(70)
    CreateDynamicObject(3578,2436.25366211,-188.39082336,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(71)
    CreateDynamicObject(3578,2436.58227539,-211.14888000,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(72)
    CreateDynamicObject(3578,2426.31835938,-211.29725647,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(73)
    CreateDynamicObject(3578,2416.27636719,-211.44569397,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(74)
    CreateDynamicObject(3578,2406.00854492,-211.59414673,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(75)
    CreateDynamicObject(3578,2395.71386719,-211.74699402,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(76)
    CreateDynamicObject(3578,2385.55737305,-211.89796448,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(77)
    CreateDynamicObject(3578,2375.39257812,-212.05101013,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(78)
    CreateDynamicObject(3578,2365.10986328,-212.20043945,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(79)
    CreateDynamicObject(3578,2354.90258789,-212.35188293,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(80)
    CreateDynamicObject(3578,2344.75952148,-212.50389099,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(81)
    CreateDynamicObject(3578,2344.82031250,-201.17276001,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(82)
    CreateDynamicObject(3578,2365.19042969,-200.87303162,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(84)
    CreateDynamicObject(3578,2385.62963867,-200.57215881,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(86)
    CreateDynamicObject(3578,2406.09472656,-200.26148987,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(88)
    CreateDynamicObject(3578,2436.86206055,-199.80036926,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(91)
    CreateDynamicObject(3578,2421.16967773,-200.02876282,25.74860382,0.00000000,0.00000000,0.91735840); //object(dockbarr1_la)(92)
    CreateDynamicObject(982,2329.88549805,-188.05642700,26.82012177,0.00000000,60.57998657,90.76376343); //object(fenceshit)(1)
    CreateDynamicObject(982,2355.50244141,-187.71820068,26.82012177,0.00000000,60.57861328,90.76354980); //object(fenceshit)(2)
    CreateDynamicObject(982,2361.89672852,-187.63050842,26.82012177,0.00000000,60.57861328,90.76354980); //object(fenceshit)(3)
    CreateDynamicObject(982,2414.94824219,-186.82519531,26.82012177,0.00000000,60.57312012,90.75256348); //object(fenceshit)(4)
    CreateDynamicObject(982,2440.56445312,-186.48535156,26.82012177,0.00000000,60.57312012,90.75805664); //object(fenceshit)(5)
    CreateDynamicObject(982,2451.75585938,-186.33203125,26.82012177,0.00000000,60.57312012,90.75805664); //object(fenceshit)(6)
    CreateDynamicObject(982,2316.75292969,-201.37091064,26.82012177,0.00000000,60.57861328,180.89276123); //object(fenceshit)(7)
    CreateDynamicObject(4642,2440.11230469,-196.16050720,24.83946991,0.00000000,0.00000000,0.94372559); //object(paypark_lan)(1)
    CreateDynamicObject(4642,2440.05493164,-192.06443787,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(2)
    CreateDynamicObject(4642,2440.20288086,-203.49311829,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(3)
    CreateDynamicObject(4642,2440.25830078,-207.50076294,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(4)
    CreateDynamicObject(4642,2429.70312500,-205.87042236,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(5)
    CreateDynamicObject(4642,2429.42358398,-193.65980530,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(6)
    CreateDynamicObject(4642,2341.53564453,-194.09152222,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(7)
    CreateDynamicObject(4642,2341.56103516,-197.93055725,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(8)
    CreateDynamicObject(4642,2341.60595703,-204.73591614,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(9)
    CreateDynamicObject(4642,2341.63037109,-208.40080261,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(10)
    CreateDynamicObject(4642,2350.95239258,-206.41529846,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(11)
    CreateDynamicObject(4642,2350.87695312,-195.85076904,24.83946991,0.00000000,0.00000000,0.93933105); //object(paypark_lan)(12)
    CreateDynamicObject(3998,2458.40722656,-200.94815063,13.27782917,0.00000000,0.00000000,114.50857544); //object(court1_lan)(2)
    CreateDynamicObject(3998,2405.29394531,-201.78320312,13.27782917,0.00000000,0.00000000,247.75817871); //object(court1_lan)(2)
    CreateDynamicObject(3998,2432.09350586,-200.70289612,13.27782917,0.00000000,0.00000000,180.32958984); //object(court1_lan)(2)
    CreateDynamicObject(984,2457.56347656,-215.93974304,26.86925507,0.00000000,53.85421753,294.51367188); //object(fenceshit2)(1)
    CreateDynamicObject(984,2450.96191406,-218.95005798,26.86925507,0.00000000,53.84948730,294.51049805); //object(fenceshit2)(2)
    CreateDynamicObject(984,2438.53149414,-221.64889526,26.86925507,0.00000000,54.05349731,270.33474731); //object(fenceshit2)(3)
    CreateDynamicObject(984,2425.72875977,-221.72489929,26.86925507,0.00000000,54.05273438,270.32958984); //object(fenceshit2)(4)
    CreateDynamicObject(984,2413.27392578,-219.24775696,26.86925507,0.00000000,54.05273438,247.79443359); //object(fenceshit2)(5)
    CreateDynamicObject(984,2405.87304688,-216.23403931,26.86925507,0.00000000,54.04724121,247.79113770); //object(fenceshit2)(6)
    CreateDynamicObject(982,2386.72949219,-213.81362915,26.82012177,0.00000000,60.57312012,270.86364746); //object(fenceshit)(4)
    CreateDynamicObject(982,2361.11230469,-214.19389343,26.82012177,0.00000000,60.57312012,270.86242676); //object(fenceshit)(4)
    CreateDynamicObject(982,2335.49316406,-214.58294678,26.82012177,0.00000000,60.57312012,270.86242676); //object(fenceshit)(4)
    CreateDynamicObject(982,2330.44189453,-214.65779114,26.82012177,0.00000000,60.57312012,270.86242676); //object(fenceshit)(4)
    CreateDynamicObject(3998,2404.15258789,-114.07740021,15.48610210,0.00000000,0.00000000,138.58007812); //object(court1_lan)(26)
    CreateDynamicObject(3998,2408.86840820,-108.68868256,15.48610210,0.00000000,0.00000000,138.57604980); //object(court1_lan)(26)
    CreateDynamicObject(1257,2352.54833984,-73.11376953,26.76356697,0.00000000,0.00000000,1.20001221); //object(bustopm)(1)
    CreateDynamicObject(1425,2343.90454102,-38.47944641,25.78843498,0.00000000,0.00000000,180.74293518); //object(dyn_roadbarrier_3)(1)
    CreateDynamicObject(973,2338.09423828,-107.04782867,26.30659294,0.00000000,0.00000000,13.37142944); //object(sub_roadbarrier)(2)
    CreateDynamicObject(973,2346.04101562,-102.92382812,26.30659294,0.00000000,0.00000000,41.13830566); //object(sub_roadbarrier)(3)
    CreateDynamicObject(1237,2333.44628906,-108.02832031,25.48437500,0.00000000,0.00000000,67.76916504); //object(strtbarrier01)(2)
    CreateDynamicObject(8843,2311.07763672,-100.81384277,25.33826637,0.00000000,0.00000000,269.42855835); //object(arrows01_lvs)(1)
    CreateDynamicObject(8843,2310.64575195,-95.43677521,25.33826637,0.00000000,0.00000000,269.42321777); //object(arrows01_lvs)(2)
    CreateDynamicObject(1318,2326.31054688,-100.40361786,25.28414726,359.99707031,269.44470215,35.27719116); //object(arrow)(1)
    CreateDynamicObject(1318,2330.23266602,-100.26770782,25.28414726,359.99450684,269.43969727,35.27709961); //object(arrow)(3)
    CreateDynamicObject(1318,2328.34570312,-96.06046295,25.28414726,359.99450684,269.43978882,0.30581665); //object(arrow)(4)
    CreateDynamicObject(1318,2338.53198242,-93.61714172,25.28414726,359.98904419,269.43988037,34.13037109); //object(arrow)(5)
    CreateDynamicObject(1318,2341.37011719,-83.24550629,25.28414726,359.98348999,269.43966675,85.44314575); //object(arrow)(6)
    CreateDynamicObject(1318,2341.41406250,-74.25465393,25.28414726,359.97802734,269.43429565,87.49780273); //object(arrow)(7)
    CreateDynamicObject(1318,2341.43090820,-64.12907410,25.28414726,359.97802734,269.43429565,90.58081055); //object(arrow)(8)
    CreateDynamicObject(1318,2344.01342773,-56.40329742,25.28414726,359.97802734,269.43429565,68.97680664); //object(arrow)(9)
    CreateDynamicObject(1318,2341.21044922,-50.97253799,25.28414726,359.97802734,269.43429565,91.02932739); //object(arrow)(10)
    CreateDynamicObject(1318,2346.18774414,-51.02783966,25.28414726,359.97802734,269.43420410,91.02722168); //object(arrow)(11)
    CreateDynamicObject(1318,2341.34887695,-40.49797821,25.28414726,359.97802734,269.43429565,137.08493042); //object(arrow)(12)
    CreateDynamicObject(1318,2341.19091797,-43.80487823,25.28414726,359.97802734,269.43420410,137.08190918); //object(arrow)(13)
    CreateDynamicObject(1318,2346.31030273,-40.16291809,25.28414726,359.97802734,269.43429565,92.85342407); //object(arrow)(14)
    CreateDynamicObject(1318,2346.62792969,-40.74647522,25.28414726,359.97802734,269.43429565,359.86962891); //object(arrow)(15)
    CreateDynamicObject(3578,2331.94995117,-100.66033936,24.56340027,0.00000000,0.00000000,33.94287109); //object(dockbarr1_la)(55)
    CreateDynamicObject(3578,2337.42675781,-102.54208374,24.56340027,0.00000000,0.00000000,102.17083740); //object(dockbarr1_la)(67)
    CreateDynamicObject(3578,2336.26562500,-103.65194702,24.56340027,0.00000000,0.00000000,103.19592285); //object(dockbarr1_la)(89)
    CreateDynamicObject(3578,2334.90283203,-104.24864197,24.56340027,0.00000000,0.00000000,103.19458008); //object(dockbarr1_la)(87)
    CreateDynamicObject(3578,2333.64501953,-105.18867493,24.56340027,0.00000000,0.00000000,103.19458008); //object(dockbarr1_la)(90)
    CreateDynamicObject(3578,2332.47875977,-106.21141815,24.56340027,0.00000000,0.00000000,103.19458008); //object(dockbarr1_la)(93)
    CreateDynamicObject(3578,2331.45874023,-106.70240021,24.56340027,0.00000000,0.00000000,103.19458008); //object(dockbarr1_la)(94)
    CreateDynamicObject(3578,2330.44287109,-107.28062439,24.56340027,0.00000000,0.00000000,103.19458008); //object(dockbarr1_la)(95)
    CreateDynamicObject(3578,2344.29565430,-99.60356903,24.56340027,0.00000000,0.00000000,128.91021729); //object(dockbarr1_la)(97)
    CreateDynamicObject(3578,2348.62695312,-92.73243713,24.56340027,0.00000000,0.00000000,156.67956543); //object(dockbarr1_la)(98)
    CreateDynamicObject(3578,2349.18139648,-70.35470581,24.56340027,0.00000000,0.00000000,179.30444336); //object(dockbarr1_la)(99)
    CreateDynamicObject(3578,2344.27026367,-75.31502533,24.56340027,0.00000000,0.00000000,270.03408813); //object(dockbarr1_la)(100)
    CreateDynamicObject(3578,2344.16723633,-85.44243622,24.56340027,0.00000000,0.00000000,268.80899048); //object(dockbarr1_la)(101)
    CreateDynamicObject(3578,2347.32666016,-91.35099030,24.56340027,0.00000000,0.00000000,307.77944946); //object(dockbarr1_la)(102)
    CreateDynamicObject(3578,2347.30639648,-88.95774841,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(103)
    CreateDynamicObject(3578,2347.42700195,-86.76622009,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(104)
    CreateDynamicObject(3578,2347.56323242,-84.48900604,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(105)
    CreateDynamicObject(3578,2347.51245117,-82.26705933,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(106)
    CreateDynamicObject(3578,2347.49194336,-79.87376404,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(107)
    CreateDynamicObject(3578,2347.39233398,-77.32394409,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(108)
    CreateDynamicObject(3578,2347.56250000,-75.58862305,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(109)
    CreateDynamicObject(3578,2348.13256836,-74.24257660,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(110)
    CreateDynamicObject(3578,2350.13378906,-74.35041046,24.56340027,0.00000000,0.00000000,307.77648926); //object(dockbarr1_la)(111)
    CreateDynamicObject(3578,2349.19116211,-60.09555435,24.56340027,0.00000000,0.00000000,179.30236816); //object(dockbarr1_la)(112)
    CreateDynamicObject(8038,2368.73315430,-242.10539246,27.56798935,0.00000000,0.00000000,89.42855835); //object(arprtermnl01_lvs)(1)
    CreateDynamicObject(9819,2399.99975586,-244.31271362,47.78678131,0.00000000,0.00000000,269.48571777); //object(shpbridge_sfw02)(1)
    CreateDynamicObject(3383,2399.62963867,-241.09333801,46.92736435,0.00000000,0.00000000,180.28564453); //object(a51_labtable1_)(1)
    CreateDynamicObject(2775,2399.69140625,-240.81495667,48.19643784,301.48196411,0.00000000,0.00000000); //object(cj_airprt_mon)(1)
    CreateDynamicObject(2002,2403.75634766,-242.78976440,46.92736435,0.00000000,0.00000000,267.70935059); //object(water_coolnu)(1)
    CreateDynamicObject(2356,2401.87011719,-244.27722168,46.92736435,0.00000000,0.00000000,182.34277344); //object(police_off_chair)(1)
    CreateDynamicObject(2356,2398.97802734,-244.05456543,46.92736435,0.00000000,0.00000000,175.14013672); //object(police_off_chair)(2)
    CreateDynamicObject(2356,2396.27148438,-244.22459412,46.92736435,0.00000000,0.00000000,175.13854980); //object(police_off_chair)(3)
    CreateDynamicObject(2605,2403.86499023,-241.56744385,47.32580185,0.00000000,0.00000000,268.50750732); //object(polce_desk1)(1)
    CreateDynamicObject(2356,2402.98144531,-241.56507874,46.92736435,0.00000000,0.00000000,267.31152344); //object(police_off_chair)(4)
    CreateDynamicObject(7980,2316.42089844,-200.30482483,10.63994694,0.00000000,269.59991455,0.81600952); //object(airprtbits12_lvs)(1)
    CreateDynamicObject(1649,2397.94653320,-236.87403870,49.27716446,0.00000000,0.00000000,359.38800049); //object(wglasssmash)(1)
    CreateDynamicObject(1649,2402.03833008,-236.92268372,49.27716446,0.00000000,0.00000000,359.38476562); //object(wglasssmash)(2)
    CreateDynamicObject(1649,2402.03808594,-236.92187500,49.27716446,0.00000000,0.00000000,179.48181152); //object(wglasssmash)(3)
    CreateDynamicObject(1649,2397.94628906,-236.87402344,49.27716446,0.00000000,0.00000000,179.24206543); //object(wglasssmash)(4)
    CreateDynamicObject(1649,2395.70385742,-239.06883240,49.27716446,0.00000000,0.00000000,89.29110718); //object(wglasssmash)(5)
    CreateDynamicObject(1649,2395.70312500,-239.06835938,49.27716446,0.00000000,0.00000000,269.21948242); //object(wglasssmash)(6)
    CreateDynamicObject(1649,2395.64453125,-243.15261841,49.27716446,0.00000000,0.00000000,89.28588867); //object(wglasssmash)(8)
    CreateDynamicObject(1649,2395.64526367,-243.14637756,49.27716446,0.00000000,0.00000000,269.28942871); //object(wglasssmash)(9)
    CreateDynamicObject(1649,2404.23876953,-239.15415955,49.27716446,0.00000000,0.00000000,269.21447754); //object(wglasssmash)(10)
    CreateDynamicObject(1649,2404.17333984,-243.26521301,49.27716446,0.00000000,0.00000000,269.21447754); //object(wglasssmash)(11)
    CreateDynamicObject(1649,2404.17285156,-243.26464844,49.27716446,0.00000000,0.00000000,88.36779785); //object(wglasssmash)(12)
    CreateDynamicObject(1649,2404.26904297,-239.12010193,49.27716446,0.00000000,0.00000000,89.17901611); //object(wglasssmash)(13)
    CreateDynamicObject(1649,2401.99633789,-245.50627136,49.27716446,0.00000000,0.00000000,179.48181152); //object(wglasssmash)(15)
    CreateDynamicObject(1649,2397.76171875,-245.42926025,49.27716446,0.00000000,0.00000000,179.47814941); //object(wglasssmash)(16)
    CreateDynamicObject(1649,2397.76171875,-245.42871094,49.27716446,0.00000000,0.00000000,0.04956055); //object(wglasssmash)(17)
    CreateDynamicObject(1649,2401.99609375,-245.50585938,49.27716446,0.00000000,0.00000000,359.30673218); //object(wglasssmash)(18)
    CreateDynamicObject(3095,2399.85766602,-241.21066284,50.74061966,0.00000000,0.00000000,358.67401123); //object(a51_jetdoor)(1)
    CreateDynamicObject(16782,2398.49414062,-245.36140442,49.50539398,0.00000000,0.00000000,89.33886719); //object(a51_radar_scan)(1)
    CreateDynamicObject(16782,2400.78173828,-245.37367249,49.50539398,0.00000000,0.00000000,89.33532715); //object(a51_radar_scan)(2)
    CreateDynamicObject(16101,2422.77709961,-167.06468201,25.75799942,0.00000000,0.00000000,0.00000000); //object(des_windsockpole)(3)
    CreateDynamicObject(16368,2422.76733398,-167.06733704,36.66702652,0.00000000,0.00000000,0.00000000); //object(bonyrd_windsock)(1)
    CreateDynamicObject(10764,2438.44409180,-199.87432861,23.26281357,0.00000000,0.00000000,316.26495361); //object(app_light_sfs05e)(1)
    CreateDynamicObject(10764,2343.45581055,-201.09313965,23.23908234,0.00000000,0.00000000,135.51947021); //object(app_light_sfs05e)(2)
    CreateDynamicObject(3526,2463.34497070,-187.63827515,26.58955956,0.00000000,0.00000000,181.48583984); //object(vegasairportlight)(1)
    CreateDynamicObject(3526,2463.78710938,-199.54296875,26.58955956,0.00000000,0.00000000,181.48315430); //object(vegasairportlight)(2)
    CreateDynamicObject(3526,2463.79711914,-211.42532349,26.58955956,0.00000000,0.00000000,181.48315430); //object(vegasairportlight)(3)
    CreateDynamicObject(3526,2320.39331055,-201.68273926,26.59827232,0.00000000,0.00000000,2.68310547); //object(vegasairportlight)(4)
    CreateDynamicObject(3526,2320.66943359,-212.74157715,26.58955956,0.00000000,0.00000000,2.68066406); //object(vegasairportlight)(5)
    CreateDynamicObject(3526,2320.22363281,-191.62130737,26.58955956,0.00000000,0.00000000,2.68066406); //object(vegasairportlight)(6)
    CreateDynamicObject(3526,2340.01147461,-213.48995972,26.58955956,0.00000000,0.30599976,271.20837402); //object(vegasairportlight)(7)
    CreateDynamicObject(3526,2441.64672852,-212.03399658,26.58955956,0.00000000,0.30212402,271.20300293); //object(vegasairportlight)(8)
    CreateDynamicObject(3526,2401.23339844,-212.69572449,26.58955956,0.00000000,0.30212402,271.20300293); //object(vegasairportlight)(9)
    CreateDynamicObject(3526,2441.25146484,-187.50704956,26.58955956,0.00000000,0.30212402,88.68875122); //object(vegasairportlight)(11)
    CreateDynamicObject(3526,2400.73339844,-188.07519531,26.58955956,0.00000000,0.29663086,88.68713379); //object(vegasairportlight)(12)
    CreateDynamicObject(3526,2339.86157227,-188.98446655,26.58955956,0.00000000,0.29663086,88.68713379); //object(vegasairportlight)(13)
    CreateDynamicObject(3666,2345.80175781,-165.61212158,22.87574387,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(1)
    CreateDynamicObject(3666,2345.83056641,-167.57968140,22.53462219,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(2)
    CreateDynamicObject(3666,2448.05981445,-177.42057800,26.80183601,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(3)
    CreateDynamicObject(3666,2448.61059570,-175.36323547,27.32344627,0.00000000,0.00000000,0.00000000); //object(airuntest_las)(4)
    CreateDynamicObject(1215,2448.80053711,-173.48141479,27.86806107,0.00000000,0.00000000,0.00000000); //object(bollardlight)(1)
    CreateDynamicObject(1215,2449.15600586,-171.74836731,28.34545517,0.00000000,0.00000000,0.00000000); //object(bollardlight)(2)
    CreateDynamicObject(1215,2345.99316406,-169.60917664,22.23702240,0.00000000,0.00000000,0.00000000); //object(bollardlight)(3)
    CreateDynamicObject(1215,2346.05419922,-171.56082153,21.89954376,0.00000000,0.00000000,0.00000000); //object(bollardlight)(4)
    CreateDynamicObject(3877,2400.03027344,-240.86416626,52.96172714,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(1)
    CreateDynamicObject(3877,2371.92041016,-104.07846832,36.49897003,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(2)
    CreateDynamicObject(3877,2514.65991211,-199.79431152,30.38291931,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(3)
    CreateDynamicObject(3877,2284.67114258,-202.06634521,12.95474625,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(4)
    CreateDynamicObject(3877,2615.69165039,-165.30572510,94.61042786,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(5)
    CreateDynamicObject(3877,2578.52539062,-202.70800781,35.52435303,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(6)
    CreateDynamicObject(3877,2614.18164062,-209.71582031,82.24126434,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(7)
    CreateDynamicObject(3877,2615.87646484,-184.21331787,42.07321548,0.00000000,0.00000000,13.37142944); //object(sf_rooflite)(8)
    CreateDynamicObject(3877,2547.95800781,-200.98828125,33.25863647,0.00000000,0.00000000,0.00000000); //object(sf_rooflite)(9)
    CreateDynamicObject(3877,1882.38208008,-65.60029602,35.48059082,0.00000000,0.00000000,342.51428223); //object(sf_rooflite)(10)
    CreateDynamicObject(3877,1764.67175293,-158.94860840,178.59541321,0.00000000,0.00000000,342.50976562); //object(sf_rooflite)(11)
    CreateDynamicObject(3877,2161.82446289,-102.71052551,5.42906570,0.00000000,0.00000000,28.96688843); //object(sf_rooflite)(12)
    CreateDynamicObject(973,2351.79882812,-96.01914215,26.30659294,0.00000000,0.00000000,59.65258789); //object(sub_roadbarrier)(3)
    CreateDynamicObject(1237,2343.89331055,-39.08057785,25.24592972,0.00000000,0.00000000,2.47628784); //object(strtbarrier01)(2)
    CreateDynamicObject(1238,2343.93090820,-40.11270142,25.65648460,0.00000000,0.00000000,0.00000000); //object(trafficcone)(1)
    CreateDynamicObject(1238,2343.89550781,-42.83301163,25.65411758,0.00000000,0.00000000,0.00000000); //object(trafficcone)(2)
    CreateDynamicObject(1238,2343.94458008,-45.90150452,25.65646553,0.00000000,0.00000000,0.00000000); //object(trafficcone)(3)
    CreateDynamicObject(1238,2338.37841797,-38.26345062,25.80255508,0.00000000,0.00000000,0.00000000); //object(trafficcone)(4)
    CreateDynamicObject(1238,2349.40551758,-38.09461594,25.80255508,0.00000000,0.00000000,0.00000000); //object(trafficcone)(5)
    CreateDynamicObject(1238,2336.39575195,-97.74224854,25.66283035,0.00000000,0.00000000,0.00000000); //object(trafficcone)(6)
    CreateDynamicObject(1238,2353.87207031,-28.29492188,25.65748405,0.00000000,0.00000000,0.00000000); //object(trafficcone)(8)
    CreateDynamicObject(1238,2343.83300781,-33.63964844,25.65411758,0.00000000,0.00000000,0.00000000); //object(trafficcone)(9)
    CreateDynamicObject(1226,2345.91748047,-103.13156128,29.34101105,0.00000000,0.00000000,312.51428223); //object(lamppost3)(1)
    CreateDynamicObject(1216,2362.32153320,-78.00563049,29.42141914,0.00000000,0.00000000,269.82421875); //object(phonebooth1)(2)
    CreateDynamicObject(1216,2362.29980469,-76.68671417,29.42141914,0.00000000,0.00000000,269.82421875); //object(phonebooth1)(4)
    CreateDynamicObject(1216,2362.31616211,-79.58087158,29.42141914,0.00000000,0.00000000,269.82421875); //object(phonebooth1)(5)
    CreateDynamicObject(1211,2348.51196289,-93.95747375,26.00938034,0.00000000,0.00000000,72.91430664); //object(fire_hydrant)(1)
    CreateDynamicObject(11489,2367.65332031,-92.88183594,33.71135330,0.00000000,0.00000000,268.95916748); //object(dam_statues)(1)
    CreateDynamicObject(1269,2344.19384766,-99.56764221,26.30228424,0.00000000,0.00000000,306.05712891); //object(parkingmeter)(1)
    CreateDynamicObject(1269,2347.86914062,-94.18707275,26.30228424,0.00000000,0.00000000,329.88568115); //object(parkingmeter)(2)
    CreateDynamicObject(1269,2349.29296875,-60.25098419,26.30228424,0.00000000,0.00000000,357.08096313); //object(parkingmeter)(3)
    CreateDynamicObject(1278,2389.55859375,-101.83007812,41.96031952,0.00000000,0.00000000,90.48889160); //object(sub_floodlite)(1)
    CreateDynamicObject(1278,2350.60351562,-151.91334534,38.57430649,0.00000000,1.02856445,180.77455139); //object(sub_floodlite)(2)
    CreateDynamicObject(1278,2429.05249023,-121.08946991,42.92090988,0.00000000,1.02722168,180.76904297); //object(sub_floodlite)(3)
    CreateDynamicObject(1278,2332.91406250,-125.30468750,39.78174591,0.00000000,0.00000000,90.48889160); //object(sub_floodlite)(5)
    CreateDynamicObject(984,2401.46069336,-179.69244385,27.95861435,7.09506226,43.20263672,0.93991089); //object(fenceshit2)(7)
    CreateDynamicObject(984,2401.41113281,-176.51693726,28.35546112,7.09167480,43.19824219,0.93933105); //object(fenceshit2)(8)
    CreateDynamicObject(984,2375.18457031,-179.90878296,27.97348022,352.80697632,43.21014404,180.93858337); //object(fenceshit2)(10)
    CreateDynamicObject(984,2375.13574219,-176.73512268,28.36119080,352.80395508,43.20922852,180.93383789); //object(fenceshit2)(11)
    CreateDynamicObject(982,2400.84252930,-157.15747070,29.32896423,0.09960938,12.44403076,0.89602661); //object(fenceshit)(8)
    CreateDynamicObject(982,2400.74511719,-150.77635193,29.33496475,0.09887695,12.44201660,0.89538574); //object(fenceshit)(9)
    CreateDynamicObject(982,2408.84423828,-128.38322449,29.37093735,0.00000000,17.48571777,318.49035645); //object(fenceshit)(10)
    CreateDynamicObject(982,2429.99511719,-118.64655304,29.36493683,0.00000000,17.48474121,270.86602783); //object(fenceshit)(12)
    CreateDynamicObject(984,2440.31689453,-118.47994232,29.31106567,0.00000000,20.65798950,270.45715332); //object(fenceshit2)(12)
    CreateDynamicObject(984,2447.34790039,-111.85546112,29.31106567,0.00000000,20.65429688,355.88452148); //object(fenceshit2)(13)
    CreateDynamicObject(984,2447.64941406,-107.69226074,29.31106567,0.00000000,20.65429688,355.88012695); //object(fenceshit2)(14)
    CreateDynamicObject(983,2450.86865234,-99.70514679,29.30497742,0.00000000,29.82858276,303.54284668); //object(fenceshit3)(1)
    CreateDynamicObject(983,2454.85913086,-97.04774475,29.30497742,0.00000000,29.82788086,303.54125977); //object(fenceshit3)(2)
    CreateDynamicObject(983,2460.55468750,-95.35415649,29.31097794,0.00000000,29.82788086,270.70007324); //object(fenceshit3)(3)
    CreateDynamicObject(983,2462.14111328,-95.33262634,29.31097794,0.00000000,29.82238770,270.69763184); //object(fenceshit3)(4)
    CreateDynamicObject(984,2468.76904297,-89.60411072,29.31106567,0.00000000,20.65429688,329.16253662); //object(fenceshit2)(16)
    CreateDynamicObject(984,2472.87133789,-82.74277496,29.31106567,0.00000000,20.65429688,329.16137695); //object(fenceshit2)(17)
    CreateDynamicObject(982,2476.08618164,-64.35119629,29.33080673,0.00000000,17.47924805,0.29846191); //object(fenceshit)(16)
    CreateDynamicObject(3934,2465.11523438,-42.95642853,25.48437500,0.00000000,0.00000000,0.00000000); //object(helipad01)(1)
    CreateDynamicObject(973,2458.31469727,-37.07073975,26.28859138,0.00000000,0.00000000,12.45257568); //object(sub_roadbarrier)(3)
    CreateDynamicObject(973,2466.09423828,-33.30505371,26.28859138,0.00000000,0.00000000,38.33322144); //object(sub_roadbarrier)(3)
    CreateDynamicObject(973,2471.12451172,-27.40838242,26.28859138,0.00000000,0.00000000,60.38842773); //object(sub_roadbarrier)(3)
    CreateDynamicObject(973,2473.42163086,-21.65144920,26.28859138,0.00000000,0.00000000,84.21490479); //object(sub_roadbarrier)(3)
    CreateDynamicObject(984,2469.42309570,-51.39068222,29.31106567,0.00000000,20.65429688,90.21392822); //object(fenceshit2)(18)
    CreateDynamicObject(984,2461.41992188,-51.41315842,29.31106567,0.00000000,20.65429688,90.20874023); //object(fenceshit2)(19)
    CreateDynamicObject(984,2454.85205078,-58.04893494,29.31106567,0.00000000,20.65429688,180.08473206); //object(fenceshit2)(20)
    CreateDynamicObject(984,2454.86889648,-69.24134827,29.31106567,0.00000000,20.65429688,180.08239746); //object(fenceshit2)(21)
    CreateDynamicObject(982,2441.91894531,-75.59944153,29.36493683,0.00000000,17.47924805,90.01757812); //object(fenceshit)(18)
    CreateDynamicObject(982,2361.83032227,-150.97334290,29.37096786,0.00000000,17.47375488,270.81219482); //object(fenceshit)(19)
    CreateDynamicObject(984,2398.72265625,-75.65136719,29.33009338,0.00000000,20.65429688,90.20324707); //object(fenceshit2)(22)
    CreateDynamicObject(984,2392.85180664,-77.22055054,23.92172623,75.48382568,93.31234741,46.49737549); //object(fenceshit2)(23)
    CreateDynamicObject(984,2383.46459961,-110.48217773,29.33009338,0.00000000,20.65429688,133.57546997); //object(fenceshit2)(24)
    CreateDynamicObject(984,2383.21679688,-110.26644897,28.60321808,0.69161987,132.24969482,133.10910034); //object(fenceshit2)(25)
    CreateDynamicObject(3578,2382.42480469,-185.23007202,26.06403732,7.20001221,0.00000000,0.91186523); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2392.69750977,-185.07669067,26.06403732,7.19604492,0.00000000,0.90637207); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2394.26586914,-185.05307007,26.06403732,7.20001221,0.00000000,0.91186523); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2394.26416016,-184.36611938,26.15404510,7.19604492,0.00000000,0.90637207); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2383.95874023,-184.51394653,26.15404510,7.19604492,0.00000000,0.90637207); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2382.41723633,-184.53617859,26.15404510,7.19604492,0.00000000,0.90637207); //object(dockbarr1_la)(66)
    CreateDynamicObject(3578,2378.20776367,-181.53370667,26.50861740,0.00000000,353.16601562,90.82946777); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2379.74853516,-181.52331543,26.50807571,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2381.18725586,-181.56182861,26.49948120,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2382.77246094,-181.54446411,26.49921036,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2384.32739258,-181.53218079,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2385.98461914,-181.52142334,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2387.83178711,-181.49314880,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2389.66259766,-181.47154236,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2391.63061523,-181.43733215,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2393.61206055,-181.39993286,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2395.26782227,-181.36560059,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2397.18286133,-181.33966064,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(3578,2398.60302734,-181.30845642,26.49607468,0.00000000,353.16101074,90.82397461); //object(dockbarr1_la)(14)
    CreateDynamicObject(984,2375.11035156,-163.91119385,29.31209183,0.00000000,20.65429688,181.06101990); //object(fenceshit2)(26)
    CreateDynamicObject(984,2374.97998047,-157.02890015,29.31209183,0.00000000,20.65429688,181.06018066); //object(fenceshit2)(27)
    CreateDynamicObject(982,2416.29980469,-75.60351562,29.36493683,0.00000000,17.47375488,90.01647949); //object(fenceshit)(21)
    CreateDynamicObject(982,2346.21752930,-151.19648743,29.37096786,0.00000000,17.46826172,270.80749512); //object(fenceshit)(22)
    CreateDynamicObject(982,2333.11816406,-138.38769531,29.37096786,0.00000000,17.46826172,181.01074219); //object(fenceshit)(23)
    CreateDynamicObject(982,2332.86230469,-121.05621338,29.34096527,0.00000000,17.46826172,181.01074219); //object(fenceshit)(23)
    CreateDynamicObject(982,2345.46704102,-107.81416321,29.34096527,0.00000000,17.46826172,90.77972412); //object(fenceshit)(23)
    CreateDynamicObject(1238,2356.40014648,-114.69561768,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(7)
    CreateDynamicObject(1238,2364.03247070,-114.65832520,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(10)
    CreateDynamicObject(3578,2387.35180664,-178.33944702,26.93287277,0.00000000,352.81713867,90.82946777); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2387.30517578,-175.05392456,27.34745026,0.00000000,352.81494141,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2387.17578125,-164.93652344,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2387.04199219,-154.63867188,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2384.67187500,-144.94531250,27.95431519,0.00000000,0.00000000,116.71325684); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2386.89672852,-144.29510498,27.95431519,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2388.30078125,-134.24609375,27.95431519,0.00000000,0.00000000,73.91052246); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2392.00268555,-124.75096893,27.95431519,0.00000000,0.00000000,63.62481689); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2397.20141602,-115.95063019,27.95431519,0.00000000,0.00000000,55.39324951); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2400.02124023,-106.70716095,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2399.88256836,-96.41431427,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2399.74584961,-86.16618347,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2399.65869141,-81.25115204,27.95431519,0.00000000,0.00000000,179.92132568); //object(dockbarr1_la)(15)
    CreateDynamicObject(16360,2376.95068359,-80.47261810,28.72341537,0.00000000,0.00000000,91.02856445); //object(desn2_tsfuelpay)(1)
    CreateDynamicObject(984,2385.92993164,-75.69766998,29.31809235,0.00000000,20.65429688,90.20324707); //object(fenceshit2)(22)
    CreateDynamicObject(984,2373.13525391,-75.74961090,29.31809235,0.00000000,20.65429688,90.20324707); //object(fenceshit2)(22)
    CreateDynamicObject(16107,2382.57958984,-90.06706238,28.72941589,0.00000000,0.00000000,89.93057251); //object(des_ngassta)(1)
    CreateDynamicObject(16360,2382.21752930,-93.38896179,32.00356293,0.00000000,0.00000000,0.41970825); //object(desn2_tsfuelpay)(2)
    CreateDynamicObject(1676,2399.36914062,-78.12123871,30.31028366,0.00000000,0.00000000,0.00000000); //object(washgaspump)(1)
    CreateDynamicObject(16101,2400.75366211,-78.08072662,28.72941589,0.00000000,0.00000000,0.00000000); //object(des_windsockpole)(1)
    CreateDynamicObject(16101,2398.04516602,-78.38195038,28.72941589,0.00000000,0.00000000,0.00000000); //object(des_windsockpole)(2)
    CreateDynamicObject(16101,2399.39746094,-80.38318634,28.72941589,0.00000000,0.00000000,0.00000000); //object(des_windsockpole)(4)
    CreateDynamicObject(3578,2399.70874023,-81.99561310,27.95431519,0.00000000,0.00000000,179.91760254); //object(dockbarr1_la)(15)
    CreateDynamicObject(1572,2366.74340820,-100.83026886,29.73164940,0.00000000,0.00000000,179.94726562); //object(cj_air_trolly)(2)
    CreateDynamicObject(1572,2366.74707031,-100.16498566,29.73164940,0.00000000,0.00000000,179.94506836); //object(cj_air_trolly)(3)
    CreateDynamicObject(1572,2366.78881836,-99.52534485,29.73164940,0.00000000,0.00000000,179.94506836); //object(cj_air_trolly)(4)
    CreateDynamicObject(1572,2366.81640625,-98.87876129,29.73164940,0.00000000,0.00000000,179.94506836); //object(cj_air_trolly)(5)
    CreateDynamicObject(1572,2366.86523438,-98.21317291,29.73164940,0.00000000,0.00000000,179.94506836); //object(cj_air_trolly)(6)
    CreateDynamicObject(2797,2364.79858398,-93.58856964,32.68579102,0.00000000,0.00000000,90.26544189); //object(cj_air_d_5)(1)
    CreateDynamicObject(3658,2362.05371094,-96.25437164,29.28169060,0.00000000,0.00000000,90.41168213); //object(airlastrola_las)(1)
    CreateDynamicObject(3659,2366.82324219,-89.42111206,30.17173576,0.00000000,0.30599976,89.97113037); //object(airfinfoa_las)(1)
    CreateDynamicObject(3578,2404.66601562,-109.85505676,27.95431519,0.00000000,0.00000000,24.07879639); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2414.41186523,-107.55462646,27.95431519,0.00000000,0.00000000,2.59082031); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2424.68798828,-107.09907532,27.95431519,0.00000000,0.00000000,2.58728027); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2419.41113281,-102.12723541,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2419.27294922,-91.84588623,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2419.16503906,-83.32244873,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2419.02319336,-78.23622131,27.95431519,0.00000000,0.00000000,180.04882812); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2434.82641602,-107.73948669,27.95431519,0.00000000,0.00000000,350.24438477); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2474.31689453,-57.07835007,27.95431519,0.00000000,0.00000000,90.05273438); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2474.30126953,-70.65156555,27.95431519,0.00000000,0.00000000,90.04943848); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2469.23413086,-57.27920532,27.95431519,0.00000000,0.00000000,180.04394531); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2469.05371094,-71.08171082,27.95431519,0.00000000,0.00000000,180.04394531); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2461.62939453,-61.55860901,27.95431519,0.00000000,0.00000000,238.84382629); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2459.02001953,-70.98129272,27.95431519,0.00000000,0.00000000,90.04943848); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2461.27612305,-75.27347565,27.95431519,0.00000000,0.00000000,236.71038818); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2458.26147461,-81.14668274,27.95431519,0.00000000,0.00000000,81.51486206); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2453.98291016,-89.75126648,27.95431519,0.00000000,0.00000000,46.19876099); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2446.85913086,-97.16903687,27.95431519,0.00000000,0.00000000,46.19750977); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2439.26538086,-103.75349426,27.95431519,0.00000000,0.00000000,35.91180420); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2438.14575195,-104.57283783,27.95431519,0.00000000,0.00000000,35.90881348); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2442.67626953,-112.64505005,27.95431519,0.00000000,0.00000000,306.01556396); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2447.63159180,-115.13029480,27.95431519,0.00000000,0.00000000,36.01318359); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2431.54443359,-102.02455139,27.95431519,0.00000000,0.00000000,75.45166016); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2434.15966797,-92.07080078,27.95431519,0.00000000,0.00000000,75.44860840); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2436.27270508,-84.05372620,27.95431519,0.00000000,0.00000000,75.44860840); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2437.46752930,-79.04875946,27.95431519,0.00000000,0.00000000,162.19128418); //object(dockbarr1_la)(15)
    CreateDynamicObject(1238,2409.90795898,-99.18993378,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(11)
    CreateDynamicObject(1238,2409.87402344,-93.84634399,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(12)
    CreateDynamicObject(1238,2409.97021484,-88.69719696,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(13)
    CreateDynamicObject(1238,2409.91333008,-83.66799164,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(14)
    CreateDynamicObject(1238,2455.02490234,-76.10210419,29.04759598,0.00000000,0.00000000,0.00000000); //object(trafficcone)(15)
    CreateDynamicObject(3578,2364.06323242,-149.44108582,27.95431519,0.00000000,0.00000000,180.85140991); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2345.95849609,-149.59530640,27.95431519,0.00000000,0.00000000,180.84594727); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2343.20166016,-109.59300232,27.95431519,0.00000000,0.00000000,180.84594727); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2378.98803711,-136.59591675,27.95431519,0.00000000,0.00000000,132.14178467); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2371.09790039,-130.39117432,27.95431519,0.00000000,0.00000000,151.68078613); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2361.55615234,-127.31093597,27.95431519,0.00000000,0.00000000,172.70581055); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2351.35717773,-126.73451233,27.95431519,0.00000000,0.00000000,180.84594727); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2364.03466797,-144.26086426,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2363.85400391,-134.07032776,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2363.82177734,-132.93785095,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2345.57958984,-144.58978271,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2345.42724609,-134.48538208,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2343.43725586,-114.91641998,27.95431519,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2344.41162109,-124.59867859,27.95431519,0.00000000,0.00000000,100.99908447); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2346.28198242,-126.81661224,27.95431519,0.00000000,0.00000000,180.84594727); //object(dockbarr1_la)(15)
    CreateDynamicObject(3578,2454.97900391,-205.79882812,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(26)
    CreateDynamicObject(3578,2454.54272461,-205.79409790,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(26)
    CreateDynamicObject(3578,2454.02685547,-205.78842163,25.74860382,0.00000000,0.00000000,90.82946777); //object(dockbarr1_la)(26)
    CreateDynamicObject(3578,2450.66894531,-190.69709778,25.74860382,0.00000000,0.00000000,337.99758911); //object(dockbarr1_la)(37)
    CreateDynamicObject(3578,2450.47802734,-191.16220093,25.74860382,0.00000000,0.00000000,337.99438477); //object(dockbarr1_la)(37)
    CreateDynamicObject(3578,2450.28100586,-191.61167908,25.74860382,0.00000000,0.00000000,337.99438477); //object(dockbarr1_la)(37)
    CreateDynamicObject(3578,2458.96777344,-195.16307068,25.74860382,0.00000000,0.00000000,337.99438477); //object(dockbarr1_la)(37)
    CreateDynamicObject(3578,2459.15893555,-194.69462585,25.74860382,0.00000000,0.00000000,337.99438477); //object(dockbarr1_la)(37)
    CreateDynamicObject(3578,2459.55761719,-194.30876160,25.74860382,0.00000000,0.00000000,337.99438477); //object(dockbarr1_la)(37)
    CreateDynamicObject(3578,2325.52954102,-203.06912231,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2325.49975586,-202.11029053,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2325.51318359,-202.60511780,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.20117188,-194.22257996,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.16992188,-193.24276733,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.18530273,-193.72564697,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.67236328,-203.77178955,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.65429688,-204.26283264,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.64331055,-204.77777100,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.82763672,-213.52601624,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.79711914,-213.02926636,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2333.76025391,-212.51626587,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2328.69873047,-208.71241760,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2329.19409180,-208.67607117,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2329.65332031,-208.69285583,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2325.08178711,-213.65286255,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2325.05419922,-213.16900635,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2325.04980469,-212.70962524,25.74860382,0.00000000,0.00000000,0.91186523); //object(dockbarr1_la)(10)
    CreateDynamicObject(3578,2320.13574219,-208.69116211,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2320.62719727,-208.66777039,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    CreateDynamicObject(3578,2321.10278320,-208.64515686,25.74860382,0.00000000,0.00000000,90.82397461); //object(dockbarr1_la)(17)
    
    // BAYSIDE AIRPORT
    CreateDynamicObject(18754,-1569.88000000,3118.82000000,2.13000000,0.00000000,0.00000000,1.64000000); //
    CreateDynamicObject(18754,-1325.52000000,3121.71000000,2.26000000,0.00000000,0.00000000,359.80000000); //
    CreateDynamicObject(19335,-1405.86000000,3038.59000000,2.81000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(10816,-1387.91000000,3303.82000000,1.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3268,-1376.33000000,3037.80000000,2.16000000,0.00000000,0.00000000,272.24000000); //
    CreateDynamicObject(3268,-1343.84000000,3039.18000000,2.14000000,0.00000000,0.00000000,270.92000000); //
    CreateDynamicObject(3268,-1310.51000000,3039.65000000,2.51000000,0.00000000,0.00000000,270.22000000); //
    CreateDynamicObject(669,-1298.95000000,3018.65000000,0.72000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(4828,-1464.19000000,3040.78000000,14.14000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(1682,-1500.62000000,3036.19000000,6.57000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8240,-1639.05000000,3030.59000000,15.03000000,0.00000000,0.00000000,2.55000000); //
    CreateDynamicObject(700,-1513.65000000,3024.92000000,0.23000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1519.89000000,3024.83000000,0.48000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1527.09000000,3024.62000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1534.06000000,3023.77000000,-0.19000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1538.73000000,3019.51000000,0.50000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1544.74000000,3017.60000000,1.43000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1554.66000000,3023.36000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1562.04000000,3023.45000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(700,-1552.17000000,3017.86000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(10811,-1586.79000000,3055.33000000,10.24000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1513.80000000,3026.72000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1518.17000000,3026.69000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1518.91000000,3024.68000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1522.48000000,3026.49000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1523.36000000,3024.57000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1526.11000000,3023.38000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1526.78000000,3025.45000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1524.85000000,3028.06000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1529.07000000,3027.90000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1519.97000000,3028.25000000,0.59000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1514.85000000,3028.68000000,0.78000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14469,-1527.81000000,3025.53000000,0.78000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-1428.89000000,3052.54000000,-0.85000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-1409.82000000,3053.67000000,-1.23000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(16098,-1260.44000000,3042.31000000,7.62000000,0.00000000,0.00000000,270.56000000); //
    CreateDynamicObject(18754,-1080.81000000,3121.16000000,2.33000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(4874,-1188.73000000,3028.17000000,3.57000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(4874,-1139.79000000,3024.34000000,3.59000000,0.00000000,0.00000000,179.26000000); //
    CreateDynamicObject(4874,-1060.35000000,3028.24000000,3.65000000,0.00000000,0.00000000,0.16000000); //
    CreateDynamicObject(4874,-1012.97000000,3029.16000000,4.02000000,0.00000000,0.00000000,179.10000000); //
    CreateDynamicObject(10816,-1009.70000000,3307.08000000,1.23000000,0.00000000,0.00000000,1.56000000); //
    CreateDynamicObject(10816,-1745.71000000,3302.69000000,1.80000000,0.00000000,0.00000000,0.33000000); //
    CreateDynamicObject(10816,-638.95000000,3314.01000000,0.94000000,0.00000000,0.00000000,0.50000000); //
    CreateDynamicObject(18754,-1814.75000000,3114.97000000,2.35000000,0.00000000,0.00000000,0.41000000); //
    CreateDynamicObject(18754,-833.01000000,3121.48000000,2.40000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3268,-1700.25000000,3015.59000000,2.88000000,0.00000000,0.00000000,270.76000000); //
    CreateDynamicObject(645,-1717.79000000,3030.66000000,2.82000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(645,-1727.89000000,3029.42000000,2.82000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(14582,-1691.19000000,3011.47000000,5.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(1825,-1697.74000000,3015.08000000,2.84000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(1825,-1695.57000000,3017.07000000,2.84000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(1825,-1692.97000000,3018.21000000,2.84000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3660,-1689.54000000,3035.60000000,5.43000000,0.00000000,0.00000000,269.11000000); //
    CreateDynamicObject(3660,-1709.61000000,3035.71000000,5.56000000,0.00000000,0.00000000,268.46000000); //
    CreateDynamicObject(3660,-1704.10000000,3045.71000000,5.40000000,0.00000000,0.00000000,358.64000000); //
    CreateDynamicObject(3660,-1711.62000000,3034.94000000,5.40000000,0.00000000,0.00000000,268.62000000); //
    CreateDynamicObject(669,-1715.54000000,3042.41000000,2.83000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2240,-1691.45000000,3026.54000000,3.25000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2240,-1708.93000000,3025.92000000,3.25000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2164,-1714.95000000,3017.42000000,2.81000000,0.00000000,0.00000000,89.32000000); //
    CreateDynamicObject(2173,-1712.02000000,3018.24000000,2.84000000,0.00000000,0.00000000,268.64000000); //
    CreateDynamicObject(1371,-1714.44000000,3020.05000000,3.58000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-1689.55000000,3044.76000000,2.83000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-1698.92000000,3045.58000000,3.34000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2745,-1714.11000000,3014.11000000,3.86000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(1255,-1713.30000000,3012.00000000,3.04000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(1255,-1713.04000000,3010.62000000,3.04000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2296,-1704.50000000,3005.97000000,2.84000000,0.00000000,0.00000000,178.81000000); //
    CreateDynamicObject(2290,-1706.32000000,3008.73000000,2.84000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2290,-1703.41000000,3008.85000000,2.87000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(2290,-1709.32000000,3008.63000000,2.75000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3660,-1448.99000000,3081.37000000,5.56000000,0.00000000,0.00000000,357.97000000); //
    CreateDynamicObject(3660,-1473.19000000,3081.88000000,5.82000000,0.00000000,0.00000000,359.06000000); //
    CreateDynamicObject(18754,-586.90000000,3121.69000000,2.58000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8678,-505.25000000,3018.55000000,3.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8678,-586.19000000,3018.69000000,3.72000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8678,-666.05000000,3018.67000000,3.74000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(16159,-1599.79000000,-4682.53000000,-6858.89000000,0.00000000,0.00000000,2.61000000); //
    CreateDynamicObject(16159,-1600.34000000,-4682.37000000,-6861.63000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(16159,-513.49000000,2917.58000000,56.84000000,0.00000000,0.00000000,359.63000000); //
    CreateDynamicObject(10766,-416.09000000,3339.89000000,-0.03000000,0.00000000,0.00000000,272.56000000); //
    CreateDynamicObject(8240,-1777.74000000,3028.36000000,15.80000000,0.00000000,0.00000000,0.21000000); //
    CreateDynamicObject(8240,-1873.29000000,3031.94000000,15.93000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(10766,-1977.55000000,3320.01000000,0.95000000,0.00000000,0.00000000,91.44000000); //
    CreateDynamicObject(18784,-912.84000000,2750.46000000,44.09000000,0.00000000,3.00000000,90.00000000); //
    CreateDynamicObject(615,-969.55000000,3015.17000000,2.79000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-949.22000000,3015.15000000,2.79000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-928.73000000,3017.18000000,2.79000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-991.13000000,3005.78000000,2.79000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8251,-911.67000000,3031.51000000,6.95000000,0.00000000,0.00000000,89.27000000); //
    CreateDynamicObject(8251,-883.89000000,3033.25000000,6.51000000,0.00000000,0.00000000,91.31000000); //
    CreateDynamicObject(8251,-857.73000000,3034.17000000,6.56000000,0.00000000,0.00000000,91.30000000); //
    CreateDynamicObject(709,-819.58000000,3015.35000000,0.98000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(647,-821.62000000,3026.23000000,3.93000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(647,-816.94000000,3025.06000000,3.81000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(647,-823.38000000,3022.13000000,3.92000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(647,-825.60000000,3018.33000000,3.81000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3660,-834.82000000,3047.05000000,5.50000000,0.00000000,0.00000000,0.72000000); //
    CreateDynamicObject(3660,-815.56000000,3047.29000000,5.46000000,0.00000000,0.00000000,0.41000000); //
    CreateDynamicObject(3660,-797.09000000,3047.17000000,5.47000000,0.00000000,0.00000000,0.20000000); //
    CreateDynamicObject(3660,-665.05000000,3021.51000000,5.71000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3660,-650.73000000,3021.54000000,5.62000000,0.00000000,0.00000000,0.30000000); //
    CreateDynamicObject(11470,-658.83000000,3015.49000000,6.37000000,0.00000000,0.00000000,279.84000000); //
    CreateDynamicObject(11470,-647.50000000,3016.58000000,6.50000000,0.00000000,0.00000000,83.52000000); //
    CreateDynamicObject(669,-669.27000000,3016.43000000,3.86000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-587.42000000,3013.72000000,3.38000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-577.10000000,3016.66000000,3.38000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-593.37000000,3019.10000000,3.38000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-496.17000000,3010.33000000,3.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-510.56000000,3011.27000000,3.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-485.01000000,3010.48000000,3.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-483.94000000,3020.95000000,3.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-498.68000000,3019.77000000,3.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(737,-510.89000000,3020.09000000,3.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(18754,-339.32000000,3122.01000000,2.53000000,0.00000000,0.00000000,0.51000000); //
    CreateDynamicObject(8240,-416.53000000,3034.50000000,15.38000000,0.00000000,0.00000000,0.78000000); //
    CreateDynamicObject(16098,-336.80000000,3058.33000000,7.97000000,0.00000000,0.00000000,273.80000000); //
    CreateDynamicObject(16098,-275.43000000,3060.47000000,8.26000000,0.00000000,0.00000000,272.98000000); //
    CreateDynamicObject(615,-238.02000000,3078.73000000,1.65000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-237.13000000,3095.97000000,2.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-242.87000000,3120.26000000,2.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-276.78000000,3050.53000000,1.50000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-336.46000000,3063.40000000,2.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-313.10000000,3005.33000000,2.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-375.67000000,3078.19000000,2.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(615,-292.00000000,3019.25000000,2.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(19335,-231.33000000,3052.23000000,3.50000000,0.00000000,0.00000000,0.00000000); //
    
    // MALA LS AIRPORT LUKA
    CreateDynamicObject(4058,286.51000000,-1806.60000000,-26.88000000,0.00000000,0.00000000,0.26000000); //
    CreateDynamicObject(4058,235.58000000,-1806.95000000,-26.84000000,0.00000000,0.00000000,0.57000000); //
    CreateDynamicObject(4058,194.88000000,-1807.18000000,-26.81000000,0.00000000,0.00000000,0.03000000); //
    CreateDynamicObject(10060,234.45000000,-1842.24000000,-19.21000000,0.00000000,0.00000000,359.80000000); //
    CreateDynamicObject(10763,237.18000000,-1845.12000000,35.51000000,0.00000000,0.00000000,44.09000000); //
    CreateDynamicObject(3578,291.89000000,-1802.17000000,2.77000000,0.00000000,0.00000000,358.62000000); //
    CreateDynamicObject(3578,275.78000000,-1801.72000000,2.79000000,0.00000000,0.00000000,359.28000000); //
    CreateDynamicObject(3578,260.08000000,-1801.53000000,2.89000000,0.00000000,0.00000000,358.66000000); //
    CreateDynamicObject(3578,245.04000000,-1801.14000000,2.89000000,0.00000000,0.00000000,357.96000000); //
    CreateDynamicObject(3578,229.00000000,-1800.17000000,2.85000000,0.00000000,0.00000000,358.84000000); //
    CreateDynamicObject(3578,211.33000000,-1799.93000000,2.89000000,0.00000000,0.00000000,358.87000000); //
    CreateDynamicObject(3578,196.26000000,-1799.68000000,2.87000000,0.00000000,0.00000000,359.06000000); //
    CreateDynamicObject(3578,181.51000000,-1799.75000000,2.85000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3578,166.69000000,-1799.42000000,2.85000000,0.00000000,0.00000000,0.00000000); //
    
    // VOJNI AVIONI I HELIKOPTERI
    VojniPiloti[0] = AddStaticVehicle(520,280.10000610,1955.69995117,18.60000038,265.75207520,-1,-1); //Hydra
    VojniPiloti[1] = AddStaticVehicle(520,280.60000610,1989.90002441,18.60000038,265.74829102,-1,-1); //Hydra
    VojniPiloti[2] = AddStaticVehicle(520,280.79998779,2023.69995117,18.60000038,267.66564941,-1,-1); //Hydra
    VojniPiloti[3] = AddStaticVehicle(520,330.20001221,1942.00000000,18.60000038,91.91320801,-1,-1); //Hydra
    VojniPiloti[4] = AddStaticVehicle(520,330.20001221,1955.09997559,18.60000038,91.91162109,-1,-1); //Hydra
    VojniPiloti[5] = AddStaticVehicle(520,329.50000000,1967.19995117,18.60000038,91.91162109,-1,-1); //Hydra
    VojniPiloti[6] = AddStaticVehicle(520,328.89999390,1978.90002441,18.60000038,91.91162109,-1,-1); //Hydra
    VojniPiloti[7] = AddStaticVehicle(520,328.79998779,1990.40002441,18.60000038,91.91162109,-1,-1); //Hydra
    VojniPiloti[8] = AddStaticVehicle(520,329.20001221,2001.59997559,18.60000038,89.99426270,-1,-1); //Hydra
    VojniPiloti[9] = AddStaticVehicle(520,330.10000610,2013.30004883,19.70000076,89.98901367,-1,-1); //Hydra
    VojniPiloti[10] = AddStaticVehicle(520,349.20001221,2011.00000000,22.50000000,89.98901367,-1,-1); //Hydra
    VojniPiloti[11] = AddStaticVehicle(520,347.89999390,2000.69995117,19.10000038,91.90637207,-1,-1); //Hydra
    VojniPiloti[12] = AddStaticVehicle(520,347.79998779,1990.00000000,18.60000038,91.90612793,-1,-1); //Hydra
    VojniPiloti[13] = AddStaticVehicle(520,347.70001221,1978.50000000,18.60000038,91.90612793,-1,-1); //Hydra
    VojniPiloti[14] = AddStaticVehicle(520,347.39999390,1966.90002441,18.60000038,91.90612793,-1,-1); //Hydra
    VojniPiloti[15] = AddStaticVehicle(520,347.89999390,1955.00000000,18.60000038,91.90612793,-1,-1); //Hydra
    VojniPiloti[16] = AddStaticVehicle(520,347.70001221,1943.69995117,18.60000038,91.90612793,-1,-1); //Hydra
    vojni_Heli[3] = AddStaticVehicle(548,290.39999390,1927.09997559,19.50000000,240.00000000,-1,-1); //Cargobob
    vojni_Heli[4] = AddStaticVehicle(548,335.20001221,1922.19995117,19.50000000,239.99633789,-1,-1); //Cargobob
    vojni_Heli[5] = AddStaticVehicle(548,356.29998779,1923.59997559,19.50000000,239.99633789,-1,-1); //Cargobob
    vojni_Heli[6] = AddStaticVehicle(548,335.39999390,1901.30004883,19.50000000,239.99633789,-1,-1); //Cargobob
    vojni_Heli[7] = AddStaticVehicle(548,356.10000610,1904.40002441,19.50000000,239.99633789,-1,-1); //Cargobob
    vojni_Heli[8] = AddStaticVehicle(548,335.79998779,1881.50000000,19.60000038,239.99633789,-1,-1); //Cargobob
    VojniPiloti[17] = AddStaticVehicle(520,-1403.50000000,496.60000610,19.10000038,0.00000000,-1,-1); //Hydra
    VojniPiloti[18] = AddStaticVehicle(520,-1414.50000000,496.60000610,19.20000076,0.00000000,-1,-1); //Hydra
    VojniPiloti[19] = AddStaticVehicle(520,-1426.59997559,496.60000610,19.20000076,0.00000000,-1,-1); //Hydra
    VojniPiloti[20] = AddStaticVehicle(520,-1438.59997559,496.50000000,19.20000076,0.00000000,-1,-1); //Hydra
    VojniPiloti[21] = AddStaticVehicle(520,-1269.30004883,495.70001221,19.20000076,0.00000000,-1,-1); //Hydra
    VojniPiloti[22] = AddStaticVehicle(520,-1280.59997559,495.89999390,19.20000076,0.00000000,-1,-1); //Hydra
    VojniPiloti[23] = AddStaticVehicle(520,-1291.80004883,495.79998779,19.20000076,0.00000000,-1,-1); //Hydra
    vojni_Heli[9] = AddStaticVehicle(548,-1303.50000000,495.20001221,20.10000038,0.00000000,-1,-1); //Cargobob
    
    //************************** TAKSI POSAO *****************************************
    
    // LOS SANTOS
    TaxiAutiLS[0] = AddStaticVehicle(420,1777.00000000,-1932.19995117,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[1] = AddStaticVehicle(420,1780.40002441,-1932.19995117,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[2] = AddStaticVehicle(420,1783.90002441,-1932.19995117,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[3] = AddStaticVehicle(420,1787.30004883,-1932.09997559,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[4] = AddStaticVehicle(420,1790.69995117,-1932.09997559,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[5] = AddStaticVehicle(420,1794.00000000,-1932.09997559,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[6] = AddStaticVehicle(420,1797.19995117,-1932.00000000,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[7] = AddStaticVehicle(420,1800.50000000,-1932.19995117,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[8] = AddStaticVehicle(420,1804.09997559,-1932.30004883,13.19999981,0.00000000,-1,-1); //Taxi
    TaxiAutiLS[9] = AddStaticVehicle(420,1777.90002441,-1917.59997559,13.19999981,320.00000000,-1,-1); //Taxi
    TaxiAutiLS[10] = AddStaticVehicle(420,1777.40002441,-1912.90002441,13.19999981,319.99877930,-1,-1); //Taxi
    TaxiAutiLS[11] = AddStaticVehicle(420,1777.80004883,-1907.19995117,13.19999981,319.99877930,-1,-1); //Taxi
    TaxiAutiLS[12] = AddStaticVehicle(420,1777.30004883,-1901.80004883,13.19999981,319.99877930,-1,-1); //Taxi
    TaxiAutiLS[13] = AddStaticVehicle(420,1777.40002441,-1895.59997559,13.19999981,319.99877930,-1,-1); //Taxi
    TaxiAutiLS[14] = AddStaticVehicle(420,1777.30004883,-1889.69995117,13.19999981,319.99877930,-1,-1); //Taxi
    TaxiAutiLS[15] = AddStaticVehicle(420,1803.09997559,-1921.50000000,13.19999981,40.00000000,-1,-1); //Taxi
    TaxiAutiLS[16] = AddStaticVehicle(420,1803.30004883,-1916.80004883,13.19999981,39.99572754,-1,-1); //Taxi
    TaxiAutiLS[17] = AddStaticVehicle(420,1803.50000000,-1911.30004883,13.19999981,39.99572754,-1,-1); //Taxi
    TaxiAutiLS[18] = AddStaticVehicle(420,1803.19995117,-1905.40002441,13.19999981,39.99572754,-1,-1); //Taxi
    
    // LAS VENTURAS
    TaxiAutiLV[0] = AddStaticVehicle(420,2766.00000000,1262.50000000,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[1] = AddStaticVehicle(420,2766.10009766,1265.50000000,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[2] = AddStaticVehicle(420,2766.19995117,1268.59997559,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[3] = AddStaticVehicle(420,2766.19995117,1272.00000000,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[4] = AddStaticVehicle(420,2766.19995117,1275.09997559,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[5] = AddStaticVehicle(420,2766.19995117,1278.19995117,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[6] = AddStaticVehicle(420,2766.19995117,1281.50000000,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[7] = AddStaticVehicle(420,2766.19995117,1284.80004883,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[8] = AddStaticVehicle(420,2805.50000000,1326.19995117,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[9] = AddStaticVehicle(420,2805.60009766,1329.30004883,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[10] = AddStaticVehicle(420,2805.39990234,1332.40002441,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[11] = AddStaticVehicle(420,2805.50000000,1335.80004883,10.60000038,270.00000000,-1,-1); //Taxi
    TaxiAutiLV[12] = AddStaticVehicle(420,2824.89990234,1274.90002441,10.60000038,0.00000000,-1,-1); //Taxi
    TaxiAutiLV[13] = AddStaticVehicle(420,2825.00000000,1281.30004883,10.60000038,0.00000000,-1,-1); //Taxi
    TaxiAutiLV[14] = AddStaticVehicle(420,2825.00000000,1287.80004883,10.60000038,0.00000000,-1,-1); //Taxi
    TaxiAutiLV[15] = AddStaticVehicle(420,2825.00000000,1294.40002441,10.60000038,0.00000000,-1,-1); //Taxi
    TaxiAutiLV[16] = AddStaticVehicle(420,2825.00000000,1301.00000000,10.60000038,0.00000000,-1,-1); //Taxi
    
    // SAN FIERO
    TaxiAutiSF[0] = AddStaticVehicle(438,-1959.30004883,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[1] = AddStaticVehicle(438,-1956.30004883,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[2] = AddStaticVehicle(438,-1953.40002441,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[3] = AddStaticVehicle(438,-1950.30004883,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[4] = AddStaticVehicle(438,-1947.40002441,584.70001221,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[5] = AddStaticVehicle(438,-1944.40002441,584.70001221,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[6] = AddStaticVehicle(438,-1941.30004883,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[7] = AddStaticVehicle(438,-1938.30004883,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[8] = AddStaticVehicle(438,-1935.40002441,584.79998779,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[9] = AddStaticVehicle(438,-1932.30004883,585.00000000,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[10] = AddStaticVehicle(438,-1929.30004883,585.00000000,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[11] = AddStaticVehicle(438,-1926.40002441,584.90002441,35.29999924,0.00000000,-1,-1); //Cabbie
    TaxiAutiSF[12] = AddStaticVehicle(420,-1967.40002441,580.70001221,35.00000000,90.00000000,-1,-1); //Taxi
    TaxiAutiSF[13] = AddStaticVehicle(420,-1973.69995117,579.40002441,35.00000000,113.83471680,-1,-1); //Taxi
    TaxiAutiSF[14] = AddStaticVehicle(420,-1979.00000000,575.90002441,35.00000000,135.74670410,-1,-1); //Taxi
    
    //****************************** KAMIONI POSAO *****************************************
    
    Kamioni[0] = AddStaticVehicle(515,-42.79999924,-1152.40002441,2.20000005,0.00000000,-1,-1); //Roadtrain
    Kamioni[1] = AddStaticVehicle(515,-48.50000000,-1150.40002441,2.20000005,0.00000000,-1,-1); //Roadtrain
    Kamioni[2] = AddStaticVehicle(514,-54.29999924,-1146.90002441,1.79999995,0.00000000,-1,-1); //Tanker
    Kamioni[3] = AddStaticVehicle(403,-60.09999847,-1145.30004883,1.79999995,0.00000000,-1,-1); //Linerunner
    
    Kamioni[4] = AddStaticVehicle(515,-589.59997559,-486.00000000,26.70000076,0.00000000,-1,-1); //Roadtrain
    Kamioni[5] = AddStaticVehicle(515,-584.59997559,-485.60000610,26.70000076,0.00000000,-1,-1); //Roadtrain
    Kamioni[6] = AddStaticVehicle(515,-579.50000000,-485.29998779,26.70000076,0.00000000,-1,-1); //Roadtrain
    Kamioni[7] = AddStaticVehicle(515,-564.79998779,-485.70001221,26.70000076,0.00000000,-1,-1); //Roadtrain
    Kamioni[8] = AddStaticVehicle(403,-545.20001221,-486.10000610,26.20000076,0.00000000,-1,-1); //Linerunner
    Kamioni[9] = AddStaticVehicle(403,-540.20001221,-485.89999390,26.20000076,0.00000000,-1,-1); //Linerunner
    Kamioni[10] = AddStaticVehicle(403,-544.79998779,-473.60000610,26.20000076,0.00000000,-1,-1); //Linerunner
    Kamioni[11] = AddStaticVehicle(403,-535.40002441,-486.10000610,26.20000076,0.00000000,-1,-1); //Linerunner
    Kamioni[12] = AddStaticVehicle(403,-524.50000000,-473.60000610,26.20000076,0.00000000,-1,-1); //Linerunner
    
    // PRIKOLICE
    AddStaticVehicle(584,-66.59999847,-1112.09997559,1.60000002,160.41314697,-1,-1);
    AddStaticVehicle(450,-70.90000153,-1110.69995117,1.60000002,160.41131592,-1,-1);
    AddStaticVehicle(584,-75.30000305,-1109.19995117,1.60000002,160.40588379,-1,-1);
    AddStaticVehicle(591,-86.80000305,-1147.69995117,2.29999995,64.24060059,-1,-1);
    
    AddStaticVehicle(591,-611.70001221,-489.89999390,26.10000038,270.00000000,-1,-1);
    AddStaticVehicle(450,-611.59997559,-484.10000610,26.10000038,270.00000000,-1,-1);
    AddStaticVehicle(584,-611.50000000,-478.10000610,26.10000038,270.00000000,-1,-1);
    AddStaticVehicle(584,-484.70001221,-473.70001221,26.10000038,180.00000000,-1,-1);
    AddStaticVehicle(450,-479.39999390,-473.70001221,26.10000038,180.00000000,-1,-1);
    AddStaticVehicle(584,-499.20001221,-473.79998779,26.10000038,180.00000000,-1,-1);
    AddStaticVehicle(450,-504.29998779,-473.70001221,26.10000038,180.00000000,-1,-1);
    AddStaticVehicle(584,-519.29998779,-473.60000610,26.10000038,180.00000000,-1,-1);
    AddStaticVehicle(584,-471.29998779,-516.79998779,26.10000038,0.00000000,-1,-1);
    
    //****************************** MOREPLOVAC POSAO *****************************************
    
    // LOS SANTOS
    Brod[0] = AddStaticVehicle(452,2735.00000000,-2324.50000000,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[1] = AddStaticVehicle(452,2720.60009766,-2309.30004883,0.00000000,271.91735840,-1,-1); //Tropic
    Brod[2] = AddStaticVehicle(452,2703.80004883,-2308.50000000,0.00000000,271.91711426,-1,-1); //Tropic
    Brod[3] = AddStaticVehicle(452,2682.89990234,-2308.69995117,0.00000000,271.91711426,-1,-1); //Tropic
    Brod[4] = AddStaticVehicle(452,2669.89990234,-2324.60009766,0.00000000,359.99975586,-1,-1); //Tropic
    Brod[5] = AddStaticVehicle(452,2668.50000000,-2306.69995117,0.00000000,31.49865723,-1,-1); //Tropic
    Brod[6] = AddStaticVehicle(452,2744.60009766,-2311.19995117,0.00000000,21.49780273,-1,-1); //Tropic
    Brod[7] = AddStaticVehicle(452,2723.69995117,-2296.69995117,0.00000000,300.00000000,-1,-1); //Tropic
    CreateDynamicObject(10814,2787.50000000,-2309.39990234,0.00000000,0.00000000,0.00000000,1.91735840); //object(apfuel2_sfse) (1)
    CreateDynamicObject(6295,2789.80004883,-2335.39990234,36.00000000,0.00000000,0.00000000,89.99996948); //object(sanpedlithus_law2) (1)
    CreateDynamicObject(18646,2791.50000000,-2335.39990234,60.20000076,0.00000000,0.00000000,0.00000000);

    // LAS VENTURAS
    Brod[8] = AddStaticVehicle(452,2305.50000000,533.70001221,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[9] = AddStaticVehicle(452,2283.50000000,534.20001221,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[10] = AddStaticVehicle(452,2292.19995117,516.90002441,0.00000000,270.00000000,-1,-1); //Tropic
    Brod[11] = AddStaticVehicle(452,2366.50000000,516.79998779,0.00000000,270.00000000,-1,-1); //Tropic
    Brod[12] = AddStaticVehicle(452,2354.30004883,515.00000000,0.00000000,216.57849121,-1,-1); //Tropic
    Brod[13] = AddStaticVehicle(452,2343.69995117,538.09997559,0.00000000,180.40814209,-1,-1); //Tropic
    Brod[14] = AddStaticVehicle(452,2376.39990234,539.09997559,0.00000000,180.40649414,-1,-1); //Tropic
    CreateDynamicObject(6295,2251.19995117,556.40002441,30.00000000,0.00000000,0.00000000,0.00000000); //object(sanpedlithus_law2) (1)
    CreateDynamicObject(18646,2251.50000000,554.50000000,54.20000076,0.00000000,0.00000000,0.00000000);
    CreateDynamicObject(10814,2217.10009766,548.50000000,0.00000000,0.00000000,0.00000000,0.00000000); //object(apfuel2_sfse) (1)
    
    // SAN FIERO
    Brod[15] = AddStaticVehicle(452,-1458.09997559,1091.59997559,0.00000000,270.00000000,-1,-1); //Tropic
    Brod[16] = AddStaticVehicle(452,-1473.59997559,1091.69995117,0.00000000,270.00000000,-1,-1); //Tropic
    Brod[17] = AddStaticVehicle(452,-1484.09997559,1094.19995117,0.00000000,340.00000000,-1,-1); //Tropic
    Brod[18] = AddStaticVehicle(452,-1441.40002441,1089.09997559,0.00000000,289.99938965,-1,-1); //Tropic
    Brod[19] = AddStaticVehicle(452,-1460.69995117,1100.90002441,0.00000000,299.99511719,-1,-1); //Tropic
    Brod[20] = AddStaticVehicle(452,-1498.00000000,1098.50000000,0.00000000,349.99511719,-1,-1); //Tropic
    Brod[21] = AddStaticVehicle(452,-1456.40002441,1027.59997559,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[22] = AddStaticVehicle(452,-1463.40002441,1027.50000000,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[23] = AddStaticVehicle(452,-1470.50000000,1027.59997559,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[24] = AddStaticVehicle(452,-1477.69995117,1027.59997559,0.00000000,0.00000000,-1,-1); //Tropic
    Brod[25] = AddStaticVehicle(452,-1446.40002441,1022.20001221,0.00000000,290.00000000,-1,-1); //Tropic
    CreateDynamicObject(10814,-1375.00000000,1059.19995117,0.00000000,0.00000000,0.00000000,0.00000000); //object(apfuel2_sfse) (1)
    CreateDynamicObject(6295,-1458.90002441,1143.19995117,29.79999924,0.00000000,0.00000000,90.00000000); //object(sanpedlithus_law2) (1)
    CreateDynamicObject(18646,-1457.19995117,1143.40002441,54.00000000,0.00000000,0.00000000,0.00000000);
    
    // BOZICNI OBJEKTI (LAMPE NAJVISE)
    CreateDynamicObject(3472,1899.19995117,-2531.19995117,12.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (1)
    CreateDynamicObject(3472,1869.80004883,-2531.50000000,12.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (2)
    CreateDynamicObject(3472,1914.40002441,-2516.10009766,12.50000000,0.00000000,0.00000000,21.50415039); //object(circuslampost03) (3)
    CreateDynamicObject(3472,1854.40002441,-2516.69995117,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (4)
    CreateDynamicObject(3472,1861.30004883,-2563.39990234,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (5)
    CreateDynamicObject(3472,1905.09997559,-2565.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (6)
    CreateDynamicObject(3472,1908.50000000,-2547.10009766,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (7)
    CreateDynamicObject(3472,1848.09997559,-2545.80004883,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (8)
    CreateDynamicObject(3472,1878.00000000,-2397.80004883,12.60000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (9)
    CreateDynamicObject(3472,2033.00000000,-2447.80004883,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (10)
    CreateDynamicObject(3472,2005.69995117,-2412.30004883,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (11)
    CreateDynamicObject(3472,1880.09997559,-2474.69995117,12.60000038,0.00000000,0.00000000,71.50024414); //object(circuslampost03) (12)
    CreateDynamicObject(3472,1939.09997559,-2514.69995117,12.50000000,0.00000000,0.00000000,31.49902344); //object(circuslampost03) (13)
    CreateDynamicObject(3472,1963.00000000,-2514.80004883,12.50000000,0.00000000,0.00000000,31.49780273); //object(circuslampost03) (14)
    CreateDynamicObject(3472,1985.50000000,-2516.00000000,12.50000000,0.00000000,0.00000000,31.49780273); //object(circuslampost03) (15)
    CreateDynamicObject(3472,2006.40002441,-2516.10009766,12.50000000,0.00000000,0.00000000,31.49780273); //object(circuslampost03) (16)
    CreateDynamicObject(3472,2025.59997559,-2515.50000000,12.50000000,0.00000000,0.00000000,31.49780273); //object(circuslampost03) (17)
    CreateDynamicObject(3472,2050.00000000,-2513.80004883,12.50000000,0.00000000,0.00000000,31.49780273); //object(circuslampost03) (18)
    CreateDynamicObject(3472,1833.30004883,-2513.60009766,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (19)
    CreateDynamicObject(3472,1806.69995117,-2513.69995117,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (20)
    CreateDynamicObject(3472,1783.30004883,-2513.60009766,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (21)
    CreateDynamicObject(3472,1762.50000000,-2513.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (22)
    CreateDynamicObject(3472,1742.00000000,-2513.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (23)
    CreateDynamicObject(3472,1719.59997559,-2513.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (24)
    CreateDynamicObject(3472,1694.40002441,-2513.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (25)
    CreateDynamicObject(3472,1667.30004883,-2513.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (26)
    CreateDynamicObject(3472,1642.19995117,-2512.89990234,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (27)
    CreateDynamicObject(3472,1614.00000000,-2512.89990234,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (28)
    CreateDynamicObject(3472,1585.59997559,-2513.10009766,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (29)
    CreateDynamicObject(3472,1550.09997559,-2512.80004883,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (30)
    CreateDynamicObject(3472,1514.09997559,-2512.89990234,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (31)
    CreateDynamicObject(3472,1483.09997559,-2513.10009766,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (32)
    CreateDynamicObject(3472,1447.40002441,-2513.00000000,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (33)
    CreateDynamicObject(3472,1411.69995117,-2513.19995117,12.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (34)
    CreateDynamicObject(3472,1808.50000000,-2412.89990234,12.60000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (35)
    CreateDynamicObject(3472,1839.50000000,-2410.30004883,12.60000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (36)
    CreateDynamicObject(3472,302.20001221,-1813.90002441,3.40000010,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (37)
    CreateDynamicObject(3472,303.10000610,-1781.80004883,3.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (38)
    CreateDynamicObject(3472,243.30000305,-1776.09997559,3.20000005,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (39)
    CreateDynamicObject(3472,207.89999390,-1775.90002441,2.79999995,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (40)
    CreateDynamicObject(3472,-1266.59997559,91.40000153,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (41)
    CreateDynamicObject(3472,-1251.50000000,75.00000000,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (42)
    CreateDynamicObject(3472,-1284.40002441,45.29999924,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (43)
    CreateDynamicObject(3472,-1309.09997559,74.09999847,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (44)
    CreateDynamicObject(3472,-1382.09997559,-170.30000305,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (45)
    CreateDynamicObject(3472,-1374.09997559,-146.39999390,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (46)
    CreateDynamicObject(3472,-1063.19995117,402.20001221,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (47)
    CreateDynamicObject(3472,-1081.80004883,383.70001221,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (48)
    CreateDynamicObject(3472,-1092.40002441,372.79998779,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (49)
    CreateDynamicObject(3472,-1104.00000000,361.60000610,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (50)
    CreateDynamicObject(3472,-1115.30004883,350.39999390,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (51)
    CreateDynamicObject(3472,-1127.69995117,337.79998779,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (52)
    CreateDynamicObject(3472,-1143.09997559,322.89999390,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (53)
    CreateDynamicObject(3472,-1157.90002441,308.00000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (54)
    CreateDynamicObject(3472,-1174.30004883,291.20001221,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (55)
    CreateDynamicObject(3472,-1190.69995117,274.79998779,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (56)
    CreateDynamicObject(3472,-1204.19995117,261.60000610,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (57)
    CreateDynamicObject(3472,-1223.90002441,241.80000305,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (58)
    CreateDynamicObject(3472,-1235.30004883,230.80000305,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (59)
    CreateDynamicObject(3472,-1089.90002441,431.10000610,13.39999962,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (60)
    CreateDynamicObject(3472,-1107.90002441,412.60000610,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (61)
    CreateDynamicObject(3472,-1117.19995117,402.50000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (62)
    CreateDynamicObject(3472,-1129.69995117,390.39999390,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (63)
    CreateDynamicObject(3472,-1141.50000000,378.50000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (64)
    CreateDynamicObject(3472,-1152.19995117,368.10000610,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (65)
    CreateDynamicObject(3472,-1163.80004883,356.20001221,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (66)
    CreateDynamicObject(3472,-1175.90002441,344.50000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (67)
    CreateDynamicObject(3472,-1188.59997559,331.50000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (68)
    CreateDynamicObject(3472,-1204.90002441,315.10000610,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (69)
    CreateDynamicObject(3472,-1219.19995117,300.50000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (70)
    CreateDynamicObject(3472,-1233.00000000,286.79998779,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (71)
    CreateDynamicObject(3472,-1244.69995117,275.29998779,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (72)
    CreateDynamicObject(3472,-1258.50000000,261.39999390,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (73)
    CreateDynamicObject(3472,-1269.69995117,250.00000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (74)
    CreateDynamicObject(3472,-1282.59997559,236.80000305,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (75)
    CreateDynamicObject(3472,-1294.59997559,225.10000610,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (76)
    CreateDynamicObject(3472,-1311.30004883,208.50000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (77)
    CreateDynamicObject(3472,-1322.50000000,197.19999695,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (78)
    CreateDynamicObject(3472,-1335.50000000,184.30000305,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (79)
    CreateDynamicObject(3472,-1345.69995117,174.00000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (80)
    CreateDynamicObject(3472,-1358.19995117,161.80000305,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (81)
    CreateDynamicObject(3472,-1370.40002441,149.39999390,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (82)
    CreateDynamicObject(3472,-1383.00000000,137.00000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (83)
    CreateDynamicObject(3472,-1396.30004883,123.50000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (84)
    CreateDynamicObject(3472,-1408.30004883,111.80000305,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (85)
    CreateDynamicObject(3472,-1420.50000000,99.50000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (86)
    CreateDynamicObject(3472,-1433.80004883,86.09999847,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (87)
    CreateDynamicObject(3472,-1446.80004883,72.90000153,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (88)
    CreateDynamicObject(3472,-1461.00000000,58.70000076,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (89)
    CreateDynamicObject(3472,-1474.90002441,45.00000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (90)
    CreateDynamicObject(3472,-1487.59997559,32.59999847,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (91)
    CreateDynamicObject(3472,-1498.09997559,21.89999962,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (92)
    CreateDynamicObject(3472,-1510.59997559,9.19999981,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (93)
    CreateDynamicObject(3472,-1521.19995117,-1.29999995,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (94)
    CreateDynamicObject(3472,-1536.30004883,-16.20000076,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (95)
    CreateDynamicObject(3472,-1547.50000000,-27.60000038,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (96)
    CreateDynamicObject(3472,-1560.09997559,-40.20000076,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (97)
    CreateDynamicObject(3472,-1572.00000000,-52.00000000,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (98)
    CreateDynamicObject(3472,-1592.19995117,-72.30000305,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (99)
    CreateDynamicObject(3472,-1607.00000000,-87.30000305,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (100)
    CreateDynamicObject(3472,-1338.00000000,126.30000305,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (101)
    CreateDynamicObject(3472,-1321.40002441,117.00000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (102)
    CreateDynamicObject(3472,-1303.40002441,115.80000305,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (103)
    CreateDynamicObject(3472,-1285.30004883,117.80000305,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (104)
    CreateDynamicObject(3472,-1269.40002441,135.80000305,13.50000000,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (105)
    CreateDynamicObject(3472,-1269.09997559,154.39999390,13.39999962,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (106)
    CreateDynamicObject(3472,-1270.59997559,172.39999390,13.39999962,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (107)
    CreateDynamicObject(3472,-1299.00000000,166.39999390,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (108)
    CreateDynamicObject(3472,-1355.40002441,48.29999924,13.39999962,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (109)
    CreateDynamicObject(3472,-1356.50000000,67.30000305,13.39999962,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (110)
    CreateDynamicObject(3472,-1358.40002441,91.09999847,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (111)
    CreateDynamicObject(3472,-1375.50000000,89.40000153,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (112)
    CreateDynamicObject(3472,-1367.19995117,35.20000076,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (113)
    CreateDynamicObject(3472,-1379.69995117,23.70000076,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (114)
    CreateDynamicObject(3472,-1392.90002441,24.20000076,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (115)
    CreateDynamicObject(3472,-1406.90002441,25.50000000,13.30000019,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (116)
    CreateDynamicObject(3472,-1421.59997559,29.10000038,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (117)
    CreateDynamicObject(3472,-1421.40002441,44.09999847,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (118)
    CreateDynamicObject(3472,-1402.80004883,62.59999847,13.19999981,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (119)
    CreateDynamicObject(3472,-1252.50000000,-65.90000153,13.10000038,0.00000000,0.00000000,21.50024414); //object(circuslampost03) (120)
    CreateDynamicObject(3472,1311.80004883,1265.80004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (121)
    CreateDynamicObject(3472,1327.80004883,1266.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (122)
    CreateDynamicObject(3472,1291.00000000,1309.40002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (123)
    CreateDynamicObject(3472,1290.90002441,1338.19995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (124)
    CreateDynamicObject(3472,1290.90002441,1375.90002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (125)
    CreateDynamicObject(3472,1357.50000000,1397.09997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (126)
    CreateDynamicObject(3472,1368.59997559,1332.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (127)
    CreateDynamicObject(3472,1376.80004883,1273.09997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (128)
    CreateDynamicObject(3472,1387.00000000,1259.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (129)
    CreateDynamicObject(3472,1400.09997559,1249.09997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (130)
    CreateDynamicObject(3472,1416.09997559,1242.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (131)
    CreateDynamicObject(3472,1433.09997559,1239.80004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (132)
    CreateDynamicObject(3472,1457.09997559,1245.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (133)
    CreateDynamicObject(3472,1456.50000000,1300.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (134)
    CreateDynamicObject(3472,1457.19995117,1317.40002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (135)
    CreateDynamicObject(3472,1456.69995117,1335.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (136)
    CreateDynamicObject(3472,1456.80004883,1352.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (137)
    CreateDynamicObject(3472,1456.80004883,1373.90002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (138)
    CreateDynamicObject(3472,1457.00000000,1395.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (139)
    CreateDynamicObject(3472,1456.80004883,1416.09997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (140)
    CreateDynamicObject(3472,1457.09997559,1436.40002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (141)
    CreateDynamicObject(3472,1457.00000000,1485.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (142)
    CreateDynamicObject(3472,1456.90002441,1503.69995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (143)
    CreateDynamicObject(3472,1456.80004883,1526.80004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (144)
    CreateDynamicObject(3472,1456.40002441,1551.40002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (145)
    CreateDynamicObject(3472,1456.40002441,1577.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (146)
    CreateDynamicObject(3472,1456.59997559,1606.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (147)
    CreateDynamicObject(3472,1456.69995117,1639.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (148)
    CreateDynamicObject(3472,1456.59997559,1667.90002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (149)
    CreateDynamicObject(3472,1455.19995117,1695.19995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (150)
    CreateDynamicObject(3472,1443.19995117,1709.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (151)
    CreateDynamicObject(3472,1423.30004883,1709.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (152)
    CreateDynamicObject(3472,1411.50000000,1697.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (153)
    CreateDynamicObject(3472,1409.40002441,1684.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (154)
    CreateDynamicObject(3472,1409.50000000,1668.90002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (155)
    CreateDynamicObject(3472,1409.50000000,1651.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (156)
    CreateDynamicObject(3472,1409.30004883,1632.19995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (157)
    CreateDynamicObject(3472,1409.30004883,1606.40002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (158)
    CreateDynamicObject(3472,1409.40002441,1586.19995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (159)
    CreateDynamicObject(3472,1409.40002441,1564.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (160)
    CreateDynamicObject(3472,1409.40002441,1537.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (161)
    CreateDynamicObject(3472,1409.50000000,1518.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (162)
    CreateDynamicObject(3472,1409.69995117,1499.80004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (163)
    CreateDynamicObject(3472,1409.69995117,1483.40002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (164)
    CreateDynamicObject(3472,1409.40002441,1442.90002441,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (165)
    CreateDynamicObject(3472,1409.40002441,1420.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (166)
    CreateDynamicObject(3472,1409.69995117,1395.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (167)
    CreateDynamicObject(3472,1409.59997559,1367.09997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (168)
    CreateDynamicObject(3472,1409.69995117,1343.69995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (169)
    CreateDynamicObject(3472,1409.40002441,1317.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (170)
    CreateDynamicObject(3472,1411.09997559,1297.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (171)
    CreateDynamicObject(3472,1421.30004883,1284.19995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (172)
    CreateDynamicObject(3472,1441.40002441,1282.69995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (173)
    CreateDynamicObject(3472,1336.90002441,1693.59997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (174)
    CreateDynamicObject(3472,1310.90002441,1660.69995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (175)
    CreateDynamicObject(3472,1625.00000000,1301.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (176)
    CreateDynamicObject(3472,1602.19995117,1302.19995117,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (177)
    CreateDynamicObject(3472,1589.59997559,1295.09997559,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (178)
    CreateDynamicObject(3472,1579.50000000,1279.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (179)
    CreateDynamicObject(3472,1576.90002441,1265.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (180)
    CreateDynamicObject(3472,1576.90002441,1248.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (181)
    CreateDynamicObject(3472,1497.80004883,1153.30004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (182)
    CreateDynamicObject(3472,264.20001221,1932.40002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (183)
    CreateDynamicObject(3472,294.70001221,1910.90002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (184)
    CreateDynamicObject(3472,294.70001221,1886.90002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (185)
    CreateDynamicObject(3472,294.70001221,1872.19995117,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (186)
    CreateDynamicObject(3472,294.60000610,1853.80004883,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (187)
    CreateDynamicObject(3472,295.29998779,1838.30004883,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (188)
    CreateDynamicObject(3472,295.20001221,1827.00000000,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (189)
    CreateDynamicObject(3472,321.50000000,1805.30004883,16.70000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (190)
    CreateDynamicObject(3472,321.70001221,1820.00000000,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (191)
    CreateDynamicObject(3472,321.70001221,1835.50000000,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (192)
    CreateDynamicObject(3472,321.50000000,1852.80004883,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (193)
    CreateDynamicObject(3472,321.50000000,1866.30004883,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (194)
    CreateDynamicObject(3472,286.70001221,1972.59997559,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (195)
    CreateDynamicObject(3472,286.70001221,2006.50000000,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (196)
    CreateDynamicObject(3472,286.20001221,2039.59997559,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (197)
    CreateDynamicObject(3472,294.70001221,2040.40002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (198)
    CreateDynamicObject(3472,294.79998779,2049.89990234,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (199)
    CreateDynamicObject(3472,303.60000610,2060.10009766,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (200)
    CreateDynamicObject(3472,316.10000610,2060.10009766,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (201)
    CreateDynamicObject(3472,321.60000610,2052.60009766,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (202)
    CreateDynamicObject(3472,321.50000000,2036.00000000,16.70000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (203)
    CreateDynamicObject(3472,321.60000610,2018.09997559,16.70000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (204)
    CreateDynamicObject(3472,321.39999390,2005.19995117,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (205)
    CreateDynamicObject(3472,385.70001221,1915.69995117,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (206)
    CreateDynamicObject(3472,385.60000610,1935.90002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (207)
    CreateDynamicObject(3472,384.60000610,1954.09997559,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (208)
    CreateDynamicObject(3472,380.89999390,1975.40002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (209)
    CreateDynamicObject(3472,380.10000610,1992.90002441,16.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (210)
    CreateDynamicObject(3472,278.10000610,2533.10009766,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (211)
    CreateDynamicObject(3472,303.00000000,2533.00000000,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (212)
    CreateDynamicObject(3472,312.89999390,2533.10009766,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (213)
    CreateDynamicObject(3472,337.20001221,2532.89990234,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (214)
    CreateDynamicObject(3472,429.50000000,2527.69995117,15.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (215)
    CreateDynamicObject(3472,434.10000610,2515.00000000,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (216)
    CreateDynamicObject(3472,433.79998779,2498.60009766,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (217)
    CreateDynamicObject(3472,434.00000000,2481.89990234,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (218)
    CreateDynamicObject(3472,370.39999390,2476.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (219)
    CreateDynamicObject(3472,355.00000000,2476.00000000,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (220)
    CreateDynamicObject(3472,340.20001221,2476.10009766,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (221)
    CreateDynamicObject(3472,324.50000000,2476.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (222)
    CreateDynamicObject(3472,306.29998779,2476.00000000,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (223)
    CreateDynamicObject(3472,283.50000000,2476.10009766,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (224)
    CreateDynamicObject(3472,265.79998779,2476.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (225)
    CreateDynamicObject(3472,243.19999695,2475.80004883,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (226)
    CreateDynamicObject(3472,222.80000305,2476.50000000,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (227)
    CreateDynamicObject(3472,198.30000305,2476.89990234,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (228)
    CreateDynamicObject(3472,179.00000000,2476.89990234,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (229)
    CreateDynamicObject(3472,152.30000305,2476.69995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (230)
    CreateDynamicObject(3472,124.50000000,2476.69995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (231)
    CreateDynamicObject(3472,94.00000000,2476.60009766,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (232)
    CreateDynamicObject(3472,72.30000305,2476.69995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (233)
    CreateDynamicObject(3472,43.29999924,2476.10009766,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (234)
    CreateDynamicObject(3472,20.00000000,2476.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (235)
    CreateDynamicObject(3472,-10.30000019,2477.30004883,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (236)
    CreateDynamicObject(3472,-36.70000076,2477.30004883,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (237)
    CreateDynamicObject(3472,-66.09999847,2477.00000000,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (238)
    CreateDynamicObject(3472,-71.09999847,2528.50000000,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (239)
    CreateDynamicObject(3472,-44.90000153,2528.30004883,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (240)
    CreateDynamicObject(3472,-19.89999962,2528.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (241)
    CreateDynamicObject(3472,5.59999990,2528.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (242)
    CreateDynamicObject(3472,32.29999924,2528.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (243)
    CreateDynamicObject(3472,59.50000000,2528.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (244)
    CreateDynamicObject(3472,91.69999695,2527.50000000,15.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (245)
    CreateDynamicObject(3472,118.90000153,2528.39990234,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (246)
    CreateDynamicObject(3472,150.10000610,2528.80004883,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (247)
    CreateDynamicObject(3472,183.89999390,2528.19995117,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (248)
    CreateDynamicObject(3472,368.29998779,2550.19995117,15.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (249)
    CreateDynamicObject(3472,339.20001221,2550.19995117,15.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (250)
    CreateDynamicObject(3472,2822.19995117,1308.00000000,10.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (251)
    CreateDynamicObject(3472,2794.60009766,1323.40002441,9.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (252)
    CreateDynamicObject(3472,2785.10009766,1323.40002441,9.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (253)
    CreateDynamicObject(3472,2771.50000000,1323.80004883,9.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (254)
    CreateDynamicObject(3472,2759.60009766,1323.90002441,9.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (255)
    CreateDynamicObject(3472,2757.10009766,1306.80004883,11.30000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (256)
    CreateDynamicObject(3472,2726.50000000,1306.50000000,12.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (257)
    CreateDynamicObject(3472,2727.19995117,1320.00000000,12.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (258)
    CreateDynamicObject(3472,2706.50000000,1319.80004883,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (259)
    CreateDynamicObject(3472,2706.80004883,1306.69995117,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (260)
    CreateDynamicObject(3472,2688.80004883,1320.40002441,12.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (261)
    CreateDynamicObject(3472,2688.60009766,1306.19995117,12.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (262)
    CreateDynamicObject(3472,1398.80004883,2687.50000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (263)
    CreateDynamicObject(3472,1398.90002441,2698.89990234,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (264)
    CreateDynamicObject(3472,1550.40002441,2712.80004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (265)
    CreateDynamicObject(3472,1588.50000000,2681.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (266)
    CreateDynamicObject(3472,1580.90002441,2611.10009766,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (267)
    CreateDynamicObject(3472,1593.80004883,2604.39990234,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (268)
    CreateDynamicObject(3472,1470.30004883,2509.30004883,10.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (269)
    CreateDynamicObject(3472,1484.30004883,2511.69995117,10.60000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (270)
    CreateDynamicObject(3472,1470.69995117,2464.60009766,13.10000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (271)
    CreateDynamicObject(3472,1484.59997559,2464.69995117,13.10000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (272)
    CreateDynamicObject(3472,1485.09997559,2403.60009766,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (273)
    CreateDynamicObject(3472,1506.90002441,2400.39990234,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (274)
    CreateDynamicObject(3472,1524.19995117,2387.10009766,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (275)
    CreateDynamicObject(3472,1554.59997559,2400.00000000,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (276)
    CreateDynamicObject(3472,1574.40002441,2377.80004883,9.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (277)
    CreateDynamicObject(3472,2301.39990234,547.29998779,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (278)
    CreateDynamicObject(3472,2286.89990234,546.79998779,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (279)
    CreateDynamicObject(3472,2344.69995117,562.79998779,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (280)
    CreateDynamicObject(3472,2330.89990234,580.40002441,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (281)
    CreateDynamicObject(3472,2304.50000000,581.90002441,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (282)
    CreateDynamicObject(3472,2349.50000000,586.79998779,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (283)
    CreateDynamicObject(3472,2265.50000000,592.50000000,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (284)
    CreateDynamicObject(3472,2280.80004883,574.90002441,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (285)
    CreateDynamicObject(3472,2320.30004883,571.40002441,6.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (286)
    CreateDynamicObject(3472,1826.50000000,-1108.50000000,23.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (287)
    CreateDynamicObject(3472,1826.19995117,-1078.80004883,23.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (288)
    CreateDynamicObject(3472,1810.80004883,-1047.50000000,23.10000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (289)
    CreateDynamicObject(3472,1717.80004883,-1079.80004883,22.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (290)
    CreateDynamicObject(3472,1755.69995117,-1153.90002441,22.79999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (291)
    CreateDynamicObject(3472,1741.69995117,-1151.80004883,22.79999924,0.00000000,0.00000000,73.00830078); //object(circuslampost03) (292)
    CreateDynamicObject(3472,1723.50000000,-1150.80004883,22.79999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (293)
    CreateDynamicObject(3472,1724.40002441,-1290.90002441,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (294)
    CreateDynamicObject(3472,1504.69995117,-1739.09997559,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (295)
    CreateDynamicObject(3472,1485.50000000,-1739.40002441,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (296)
    CreateDynamicObject(3472,1467.59997559,-1739.40002441,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (297)
    CreateDynamicObject(3472,1450.50000000,-1739.80004883,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (298)
    CreateDynamicObject(3472,1771.40002441,-1888.00000000,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (299)
    CreateDynamicObject(3472,1771.40002441,-1905.69995117,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (300)
    CreateDynamicObject(3472,1809.40002441,-1928.59997559,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (301)
    CreateDynamicObject(3472,1808.80004883,-1908.00000000,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (302)
    CreateDynamicObject(3472,1829.50000000,-1924.50000000,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (303)
    CreateDynamicObject(3472,1829.00000000,-1913.69995117,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (304)
    CreateDynamicObject(3472,1829.00000000,-1901.80004883,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (305)
    CreateDynamicObject(3472,1829.40002441,-1887.80004883,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (306)
    CreateDynamicObject(3472,1829.59997559,-1851.19995117,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (307)
    CreateDynamicObject(3472,1813.69995117,-1844.09997559,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (308)
    CreateDynamicObject(3472,1828.30004883,-1826.50000000,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (309)
    CreateDynamicObject(3472,1828.30004883,-1814.90002441,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (310)
    CreateDynamicObject(3472,1828.19995117,-1802.40002441,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (311)
    CreateDynamicObject(3472,1828.19995117,-1792.00000000,12.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (312)
    CreateDynamicObject(3472,2777.30004883,-2247.69995117,2.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (313)
    CreateDynamicObject(3472,2811.80004883,-2243.19995117,0.80000001,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (314)
    CreateDynamicObject(3472,2676.80004883,-2315.60009766,2.20000005,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (315)
    CreateDynamicObject(3472,2691.39990234,-2315.69995117,2.20000005,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (316)
    CreateDynamicObject(3472,2713.89990234,-2315.30004883,2.20000005,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (317)
    CreateDynamicObject(3472,2729.30004883,-2329.80004883,15.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (318)
    CreateDynamicObject(3472,2675.50000000,-2329.60009766,15.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (319)
    CreateDynamicObject(3472,2686.00000000,-2330.80004883,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (320)
    CreateDynamicObject(3472,2701.69995117,-2330.69995117,12.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (321)
    CreateDynamicObject(3472,2788.00000000,-2252.00000000,0.89999998,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (322)
    CreateDynamicObject(3472,2802.10009766,-2249.10009766,0.89999998,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (323)
    CreateDynamicObject(3472,2823.60009766,-2236.00000000,0.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (324)
    CreateDynamicObject(3472,-78.09999847,-1100.50000000,3.59999990,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (325)
    CreateDynamicObject(3472,-68.30000305,-1103.59997559,3.59999990,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (326)
    CreateDynamicObject(3472,-60.00000000,-1106.40002441,3.59999990,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (327)
    CreateDynamicObject(3472,-83.69999695,-1116.80004883,3.59999990,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (328)
    CreateDynamicObject(3472,-80.90000153,-1140.40002441,0.10000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (329)
    CreateDynamicObject(3472,-90.19999695,-1136.19995117,0.10000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (330)
    CreateDynamicObject(3472,-99.00000000,-1115.30004883,0.69999999,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (331)
    CreateDynamicObject(3472,-94.19999695,-1104.00000000,2.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (332)
    CreateDynamicObject(3472,-89.19999695,-1092.19995117,5.40000010,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (333)
    CreateDynamicObject(3472,-87.40000153,-1080.50000000,9.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (334)
    CreateDynamicObject(3472,-87.00000000,-1067.80004883,14.39999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (335)
    CreateDynamicObject(3472,-170.19999695,-1070.40002441,-17.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (336)
    CreateDynamicObject(3472,-88.50000000,-1053.19995117,19.20000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (337)
    CreateDynamicObject(3472,-93.90000153,-1040.40002441,22.70000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (338)
    CreateDynamicObject(3472,-82.09999847,-1032.59997559,22.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (339)
    CreateDynamicObject(3472,-77.59999847,-1042.19995117,20.79999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (340)
    CreateDynamicObject(3472,-73.30000305,-1069.69995117,12.69999981,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (341)
    CreateDynamicObject(3472,-74.59999847,-1085.80004883,7.69999981,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (342)
    CreateDynamicObject(3472,-107.00000000,-1136.59997559,0.40000001,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (343)
    CreateDynamicObject(3472,-116.09999847,-1155.59997559,1.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (344)
    CreateDynamicObject(3472,-111.59999847,-1179.40002441,1.89999998,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (345)
    CreateDynamicObject(3472,-99.00000000,-1154.90002441,1.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (346)
    CreateDynamicObject(3472,-84.69999695,-1149.59997559,0.69999999,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (347)
    CreateDynamicObject(3472,-87.09999847,-1186.69995117,0.80000001,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (348)
    CreateDynamicObject(3472,-120.09999847,-1197.19995117,2.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (349)
    CreateDynamicObject(3472,-123.69999695,-1206.59997559,1.79999995,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (350)
    CreateDynamicObject(3472,-126.80000305,-1216.59997559,1.79999995,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (351)
    CreateDynamicObject(3472,-130.39999390,-1229.69995117,1.79999995,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (352)
    CreateDynamicObject(3472,-133.30000305,-1243.09997559,1.70000005,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (353)
    CreateDynamicObject(3472,-136.80000305,-1268.09997559,1.79999995,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (354)
    CreateDynamicObject(3472,-138.89999390,-1283.80004883,1.79999995,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (355)
    CreateDynamicObject(3472,-142.39999390,-1313.00000000,1.89999998,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (356)
    CreateDynamicObject(3472,-499.39999390,-568.20001221,24.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (357)
    CreateDynamicObject(3472,-497.20001221,-578.79998779,21.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (358)
    CreateDynamicObject(3472,-491.29998779,-596.29998779,16.70000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (359)
    CreateDynamicObject(3472,-481.70001221,-615.40002441,16.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (360)
    CreateDynamicObject(3472,-473.50000000,-629.50000000,15.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (361)
    CreateDynamicObject(3472,-458.79998779,-640.29998779,14.19999981,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (362)
    CreateDynamicObject(3472,-441.79998779,-644.29998779,12.19999981,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (363)
    CreateDynamicObject(3472,-421.50000000,-641.40002441,10.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (364)
    CreateDynamicObject(3472,-428.70001221,-627.09997559,11.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (365)
    CreateDynamicObject(3472,-447.89999390,-628.29998779,13.19999981,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (366)
    CreateDynamicObject(3472,-460.29998779,-620.29998779,15.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (367)
    CreateDynamicObject(3472,-469.00000000,-607.00000000,15.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (368)
    CreateDynamicObject(3472,-480.79998779,-566.79998779,23.10000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (369)
    CreateDynamicObject(3472,-480.89999390,-579.00000000,19.20000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (370)
    CreateDynamicObject(3472,-477.89999390,-590.00000000,16.29999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (371)
    CreateDynamicObject(3472,-468.70001221,-525.40002441,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (372)
    CreateDynamicObject(3472,-480.50000000,-538.09997559,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (373)
    CreateDynamicObject(3472,-523.40002441,-505.89999390,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (374)
    CreateDynamicObject(3472,-532.70001221,-495.39999390,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (375)
    CreateDynamicObject(3472,-553.79998779,-495.00000000,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (376)
    CreateDynamicObject(3472,-619.00000000,-501.00000000,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (377)
    CreateDynamicObject(3472,-618.59997559,-470.20001221,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (378)
    CreateDynamicObject(3472,-475.10000610,-479.89999390,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (379)
    CreateDynamicObject(3472,-428.39999390,-617.50000000,10.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (380)
    CreateDynamicObject(3472,-429.39999390,-606.59997559,9.39999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (381)
    CreateDynamicObject(3472,-427.20001221,-595.90002441,10.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (382)
    CreateDynamicObject(3472,-422.89999390,-582.59997559,11.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (383)
    CreateDynamicObject(3472,-417.39999390,-571.29998779,12.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (384)
    CreateDynamicObject(3472,-410.39999390,-555.50000000,15.39999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (385)
    CreateDynamicObject(3472,-407.70001221,-542.70001221,16.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (386)
    CreateDynamicObject(3472,-405.79998779,-530.90002441,18.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (387)
    CreateDynamicObject(3472,-404.70001221,-520.09997559,18.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (388)
    CreateDynamicObject(3472,-406.20001221,-507.50000000,19.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (389)
    CreateDynamicObject(3472,-416.89999390,-648.29998779,11.80000019,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (390)
    CreateDynamicObject(3472,-411.00000000,-659.50000000,13.39999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (391)
    CreateDynamicObject(3472,-406.29998779,-669.20001221,14.80000019,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (392)
    CreateDynamicObject(3472,-400.79998779,-679.20001221,16.39999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (393)
    CreateDynamicObject(3472,-393.70001221,-691.90002441,18.29999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (394)
    CreateDynamicObject(3472,-383.00000000,-712.00000000,21.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (395)
    CreateDynamicObject(3472,-374.60000610,-728.09997559,24.29999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (396)
    CreateDynamicObject(3472,-341.89999390,-772.40002441,29.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (397)
    CreateDynamicObject(3472,-343.79998779,-797.29998779,31.20000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (398)
    CreateDynamicObject(3472,-345.39999390,-758.50000000,29.39999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (399)
    CreateDynamicObject(3472,-348.00000000,-750.00000000,28.70000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (400)
    CreateDynamicObject(3472,-354.89999390,-737.50000000,27.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (401)
    CreateDynamicObject(3472,-365.60000610,-714.70001221,26.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (402)
    CreateDynamicObject(3472,-392.00000000,-505.79998779,18.79999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (403)
    CreateDynamicObject(3472,-389.60000610,-514.79998779,18.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (404)
    CreateDynamicObject(3472,-389.39999390,-522.79998779,18.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (405)
    CreateDynamicObject(3472,-390.00000000,-530.90002441,18.10000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (406)
    CreateDynamicObject(3472,-390.89999390,-542.40002441,17.29999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (407)
    CreateDynamicObject(3472,-395.39999390,-557.59997559,15.80000019,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (408)
    CreateDynamicObject(3472,-398.10000610,-567.00000000,14.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (409)
    CreateDynamicObject(3472,-407.79998779,-584.09997559,12.10000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (410)
    CreateDynamicObject(3472,-412.00000000,-592.79998779,10.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (411)
    CreateDynamicObject(3472,-414.79998779,-603.20001221,10.00000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (412)
    CreateDynamicObject(3472,-415.10000610,-615.29998779,10.10000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (413)
    CreateDynamicObject(3472,-412.20001221,-625.40002441,10.80000019,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (414)
    CreateDynamicObject(3472,-408.39999390,-635.00000000,11.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (415)
    CreateDynamicObject(3472,-401.50000000,-648.50000000,15.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (416)
    CreateDynamicObject(3472,-396.29998779,-658.59997559,18.89999962,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (417)
    CreateDynamicObject(3472,-392.00000000,-667.50000000,21.60000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (418)
    CreateDynamicObject(3472,-388.20001221,-674.59997559,23.20000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (419)
    CreateDynamicObject(3472,-384.89999390,-680.00000000,24.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (420)
    CreateDynamicObject(3472,-379.79998779,-689.20001221,26.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (421)
    CreateDynamicObject(3472,-375.60000610,-696.90002441,27.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (422)
    CreateDynamicObject(3472,-370.60000610,-705.20001221,27.10000038,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (423)
    CreateDynamicObject(3472,-369.60000610,-739.29998779,26.29999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (424)
    CreateDynamicObject(3472,-366.10000610,-746.90002441,27.50000000,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (425)
    CreateDynamicObject(3472,-360.79998779,-758.59997559,29.20000076,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (426)
    CreateDynamicObject(3472,-360.60000610,-772.00000000,29.79999924,0.00000000,0.00000000,73.00415039); //object(circuslampost03) (427)
    CreateDynamicObject(3472,-1539.69995117,702.50000000,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (428)
    CreateDynamicObject(3472,-1532.09997559,715.09997559,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (429)
    CreateDynamicObject(3472,-1531.80004883,731.90002441,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (430)
    CreateDynamicObject(3472,-1531.50000000,747.79998779,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (431)
    CreateDynamicObject(3472,-1530.19995117,767.79998779,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (432)
    CreateDynamicObject(3472,-1529.00000000,783.29998779,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (433)
    CreateDynamicObject(3472,-1526.69995117,806.00000000,6.19999981,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (434)
    CreateDynamicObject(3472,-1576.09997559,740.09997559,6.40000010,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (435)
    CreateDynamicObject(3472,-1589.59997559,740.00000000,8.10000038,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (436)
    CreateDynamicObject(3472,-1601.69995117,739.90002441,10.30000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (437)
    CreateDynamicObject(3472,-1618.30004883,740.29998779,13.30000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (438)
    CreateDynamicObject(3472,-1569.09997559,721.09997559,6.19999981,0.00000000,0.00000000,30.00000000); //object(circuslampost03) (439)
    CreateDynamicObject(3472,-1588.59997559,722.29998779,7.90000010,0.00000000,0.00000000,329.99816895); //object(circuslampost03) (440)
    CreateDynamicObject(3472,-1602.09997559,722.00000000,10.30000019,0.00000000,0.00000000,329.99633789); //object(circuslampost03) (441)
    CreateDynamicObject(3472,-1922.40002441,596.40002441,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (442)
    CreateDynamicObject(3472,-1938.09997559,596.29998779,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (443)
    CreateDynamicObject(3472,-1951.90002441,596.90002441,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (444)
    CreateDynamicObject(3472,-1967.19995117,596.50000000,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (445)
    CreateDynamicObject(3472,-1986.90002441,596.40002441,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (446)
    CreateDynamicObject(3472,-1993.40002441,585.59997559,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (447)
    CreateDynamicObject(3472,-1993.30004883,570.20001221,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (448)
    CreateDynamicObject(3472,-1993.50000000,551.40002441,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (449)
    CreateDynamicObject(3472,-1993.59997559,535.79998779,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (450)
    CreateDynamicObject(3472,-1993.59997559,522.29998779,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (451)
    CreateDynamicObject(3472,-1993.59997559,510.10000610,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (452)
    CreateDynamicObject(3472,-1993.59997559,500.50000000,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (453)
    CreateDynamicObject(3472,-1993.59997559,490.89999390,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (454)
    CreateDynamicObject(3472,-1993.59997559,478.79998779,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (455)
    CreateDynamicObject(3472,-1994.09997559,469.39999390,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (456)
    CreateDynamicObject(3472,-1994.00000000,457.29998779,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (457)
    CreateDynamicObject(3472,-1993.90002441,447.70001221,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (458)
    CreateDynamicObject(3472,-1993.50000000,432.89999390,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (459)
    CreateDynamicObject(3472,-1993.19995117,421.39999390,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (460)
    CreateDynamicObject(3472,-1992.90002441,406.39999390,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (461)
    CreateDynamicObject(3472,-1992.59997559,396.79998779,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (462)
    CreateDynamicObject(3472,-1994.09997559,385.20001221,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (463)
    CreateDynamicObject(3472,-1994.09997559,373.10000610,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (464)
    CreateDynamicObject(3472,-1994.09997559,360.89999390,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (465)
    CreateDynamicObject(3472,-1908.30004883,627.00000000,34.20000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (466)
    CreateDynamicObject(3472,-1908.19995117,640.59997559,34.70000076,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (467)
    CreateDynamicObject(3472,-1908.30004883,652.20001221,36.79999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (468)
    CreateDynamicObject(3472,-1908.09997559,666.20001221,39.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (469)
    CreateDynamicObject(3472,-1908.40002441,676.00000000,41.09999847,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (470)
    CreateDynamicObject(3472,-1908.30004883,685.79998779,42.90000153,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (471)
    CreateDynamicObject(3472,-1907.90002441,700.50000000,44.40000153,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (472)
    CreateDynamicObject(3472,-1908.59997559,710.59997559,44.40000153,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (473)
    
    CreateDynamicObject(664,-2707.30761719,376.57815552,3.96888542,0.00000000,0.00000000,44.00000000);
	CreateDynamicObject(664,-2706.46826172,375.02407837,3.96923542,0.00000000,0.00000000,349.99475098);
	CreateDynamicObject(664,-2707.12426758,379.04116821,3.96928978,0.00000000,0.00000000,97.99145508);
	CreateDynamicObject(2486,-2708.43017578,373.17453003,4.97945309,0.00000000,0.00000000,354.00000000);
	CreateDynamicObject(2485,-2709.13354492,374.46206665,4.97945309,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2484,-2707.38378906,372.33828735,4.80856562,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2454,-2702.79663086,375.01049805,3.97252083,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2454,-2702.54785156,377.06506348,3.96868849,0.00000000,0.00000000,89.99548340);
	CreateDynamicObject(2454,-2709.84130859,378.29168701,3.96876383,0.00000000,0.00000000,205.99450684);
	CreateDynamicObject(14870,-2706.71582031,373.61630249,11.54687119,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(14870,-2704.56494141,373.26446533,24.75610924,0.00000000,0.00000000,296.00000000);
	CreateDynamicObject(14870,-2705.25488281,373.35855103,15.12049675,0.00000000,0.00000000,17.99914551);
	CreateDynamicObject(14870,-2706.72265625,364.66778564,24.47894669,0.00000000,0.00000000,215.99560547);
	CreateDynamicObject(14870,-2707.57861328,381.17886353,19.09156799,0.00000000,0.00000000,155.99121094);
	CreateDynamicObject(14870,-2704.77075195,377.04089355,20.49364662,0.00000000,0.00000000,155.98937988);
	CreateDynamicObject(3877,-2707.77490234,373.80313110,16.76913071,271.00000000,0.00000000,152.00000000);
	CreateDynamicObject(3877,-2708.58154297,379.04061890,15.68122482,270.99975586,0.00000000,107.99584961);
	CreateDynamicObject(3877,-2707.08251953,381.24850464,16.50436783,270.99426270,0.00000000,21.99560547);
	CreateDynamicObject(3877,-2704.91479492,376.21548462,17.06835556,270.99426270,0.00000000,291.99462891);
	CreateDynamicObject(3877,-2704.30419922,374.74246216,15.31949806,270.99426270,0.00000000,235.99462891);
	CreateDynamicObject(3877,-2706.62670898,373.60058594,19.21698761,270.99426270,0.00000000,181.99182129);
	CreateDynamicObject(3877,-2706.60522461,373.59677124,25.51964188,270.99426270,0.00000000,181.98852539);
	CreateDynamicObject(3877,-2708.80078125,376.48785400,25.34601974,270.99426270,0.00000000,143.98852539);
	CreateDynamicObject(3877,-2708.76245117,380.32965088,22.49613190,270.99426270,0.00000000,49.98681641);
	CreateDynamicObject(3877,-2705.79125977,379.82800293,20.90824699,270.99426270,0.00000000,283.98229980);
	CreateDynamicObject(3534,-2714.23632812,378.60433960,15.30849075,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2707.74877930,375.39852905,16.67776489,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2704.40332031,378.12808228,11.28053474,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2708.10400391,381.10507202,12.84053516,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2707.80346680,375.45501709,14.76138401,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2708.46166992,378.18728638,12.28053474,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2707.83056641,373.84539795,18.48528862,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2707.92895508,375.27389526,15.86812496,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2708.50781250,378.51614380,17.39788818,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2706.96020508,381.26565552,24.25031090,13.00000000,194.00000000,314.00000000);
	CreateDynamicObject(3472,-2705.07421875,376.74777222,30.69754219,12.99682617,193.99658203,257.99475098);
	CreateDynamicObject(3534,-2713.55468750,363.66510010,21.78607178,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2705.38818359,358.29653931,20.97453690,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2693.00292969,367.05838013,19.85726357,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2702.90283203,383.85583496,20.11940193,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2699.66821289,383.50790405,15.66015148,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2698.00952148,380.52221680,16.66557312,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2701.49658203,375.21389771,17.21406555,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2713.64453125,370.86132812,18.92479324,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2708.59521484,379.13803101,30.03047752,13.00000000,194.00000000,0.00000000);
	CreateDynamicObject(3472,-2708.01733398,375.67639160,25.94305611,12.99682617,193.99658203,96.00000000);
	CreateDynamicObject(3534,-2720.61157227,384.60675049,22.78135681,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2715.02368164,385.54934692,20.23530579,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2718.37109375,377.79827881,19.75296783,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2725.89916992,375.05877686,21.18688011,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2698.17187500,373.01635742,15.73170090,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2701.84106445,368.41925049,17.12574768,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2705.81225586,373.45687866,22.08354568,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2709.46386719,374.91137695,25.64812851,13.00000000,194.00000000,68.00000000);
	CreateDynamicObject(3472,-2708.39379883,381.06442261,21.48554802,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2705.72656250,379.36645508,23.78524208,13.00000000,194.00000000,216.00000000);
	CreateDynamicObject(3472,-2705.59863281,373.21707153,24.72511101,12.99682617,193.99658203,183.99670410);
	CreateDynamicObject(3472,-2708.55273438,378.83599854,27.33802032,12.99682617,193.99108887,77.99353027);
	CreateDynamicObject(3472,-2707.00610352,381.25921631,28.51313019,12.99682617,193.99108887,283.99194336);
	CreateDynamicObject(3534,-2704.69604492,384.71276855,16.07434654,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2708.01049805,365.46545410,20.03053093,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2699.31030273,365.08697510,21.65671539,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3534,-2711.09155273,367.46783447,25.64758110,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3472,-2708.09887695,373.47668457,32.40806961,12.99682617,193.99658203,103.99987793);
	CreateDynamicObject(3472,-2705.20361328,373.34951782,32.51392365,12.99682617,193.99108887,155.99658203);
	CreateDynamicObject(3472,-2701.80981445,378.32183838,26.66471672,12.99682617,193.99108887,229.99487305);
	CreateDynamicObject(3038,-2706.46289062,373.57168579,10.39013863,99.00000000,0.00000000,48.00000000);
	CreateDynamicObject(3038,-2704.14379883,375.65164185,7.62436914,98.99783325,0.00000000,165.99926758);
	CreateDynamicObject(3038,-2705.21508789,377.54974365,11.81369305,98.99780273,0.00000000,183.99792480);
	CreateDynamicObject(3038,-2705.92187500,380.75765991,11.07896423,98.99780273,0.00000000,189.99353027);
	CreateDynamicObject(3038,-2708.19018555,381.09298706,7.86560822,98.99780273,0.00000000,223.99206543);
	CreateDynamicObject(3038,-2708.62670898,379.36236572,7.49907446,98.99780273,0.00000000,179.98925781);
	CreateDynamicObject(3038,-2708.48266602,377.44958496,13.01852798,98.99780273,0.00000000,179.98901367);
	CreateDynamicObject(3038,-2706.24975586,373.53408813,7.27033615,98.99780273,0.00000000,179.98901367);
	CreateDynamicObject(970,-2710.69140625,371.59402466,3.94076157,0.00000000,0.00000000,314.00000000);
	CreateDynamicObject(970,-2706.46606445,370.02069092,3.93623304,0.00000000,0.00000000,359.99475098);
	CreateDynamicObject(970,-2701.73046875,371.75238037,3.94078469,0.00000000,0.00000000,43.99450684);
	CreateDynamicObject(970,-2701.80297852,380.86795044,3.92647910,0.00000000,0.00000000,137.98925781);
	CreateDynamicObject(970,-2703.66650391,376.11059570,4.60033703,275.00000000,0.00000000,87.98449707);
	CreateDynamicObject(970,-2706.29931641,382.41464233,3.91866851,0.00000000,0.00000000,179.98376465);
	CreateDynamicObject(970,-2710.92382812,380.47610474,3.91866851,0.00000000,0.00000000,223.98352051);
	CreateDynamicObject(970,-2712.72534180,376.12063599,3.92792559,0.00000000,0.00000000,269.97827148);
	CreateDynamicObject(3877,-2712.58178711,378.66693115,5.03292847,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2712.51611328,373.55255127,5.05479240,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2708.97583008,370.20312500,5.04991341,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2703.76489258,370.20312500,5.04991341,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2700.09375000,373.60821533,5.04971313,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2700.02294922,379.27618408,5.04073906,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2703.79223633,382.11779785,5.03292847,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2708.85937500,382.00000000,5.03292847,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2124,-2703.68579102,376.19537354,5.58674717,0.00000000,0.00000000,178.00000000);
	CreateDynamicObject(1472,-2703.39843750,376.12493896,3.99562263,0.00000000,0.00000000,90.00000000);
	CreateDynamicObject(1577,-2703.58471680,378.94894409,4.16833305,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2710,-2702.46582031,376.82360840,5.10903502,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2057,-2704.42260742,379.12969971,5.14990664,0.00000000,0.00000000,336.00000000);
	CreateDynamicObject(2035,-2702.76123047,375.29367065,5.01246452,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(1654,-2703.45800781,378.24755859,5.53104591,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(1579,-2702.21606445,374.08361816,4.37533331,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3522,-2699.57617188,376.09201050,3.45473099,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(2057,-2703.59228516,374.04187012,5.14990664,0.00000000,0.00000000,335.99487305);
	CreateDynamicObject(1577,-2702.17285156,374.61962891,4.38290453,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(1827,-2702.13793945,374.12081909,3.97474098,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(1954,-2701.78198242,373.78027344,4.69306993,0.00000000,0.00000000,46.00000000);
	CreateDynamicObject(2484,-2702.41088867,378.17538452,4.69339085,0.00000000,0.00000000,90.00000000);
	CreateDynamicObject(2484,-2704.55395508,376.18743896,6.87564707,0.00000000,0.00000000,90.00000000);
	CreateDynamicObject(2484,-2709.94458008,374.98107910,4.80514002,0.00000000,0.00000000,116.00000000);
	CreateDynamicObject(2485,-2702.60839844,377.15664673,5.00863266,0.00000000,0.00000000,126.00000000);
	CreateDynamicObject(2464,-2701.64501953,375.14590454,4.11610460,0.00000000,0.00000000,290.00000000);
	CreateDynamicObject(2464,-2701.89282227,377.39620972,4.11152649,0.00000000,0.00000000,257.99511719);
	CreateDynamicObject(2464,-2703.32958984,379.53802490,4.10850334,0.00000000,0.00000000,309.99194336);
	CreateDynamicObject(2464,-2709.75537109,378.10208130,5.15171289,0.00000000,0.00000000,63.99023438);
	CreateDynamicObject(2464,-2710.69531250,375.15093994,4.11727858,0.00000000,0.00000000,91.98986816);
	CreateDynamicObject(2464,-2708.88745117,372.80325317,4.11450672,0.00000000,0.00000000,105.98852539);
	CreateDynamicObject(2464,-2703.42065430,372.72836304,4.11189795,0.00000000,0.00000000,219.98510742);
	CreateDynamicObject(2466,-2705.27709961,377.61380005,6.06908226,0.00000000,0.00000000,94.00000000);
	CreateDynamicObject(2466,-2701.61425781,374.35293579,4.55010271,0.00000000,0.00000000,117.99902344);
	CreateDynamicObject(2477,-2702.24511719,378.58636475,4.41969681,0.00000000,0.00000000,84.00000000);
	CreateDynamicObject(2477,-2705.17846680,371.86395264,4.53150940,0.00000000,0.00000000,1.99597168);
	CreateDynamicObject(2477,-2710.75488281,376.70098877,4.53381872,0.00000000,0.00000000,275.99401855);
	CreateDynamicObject(970,-2697.26513672,373.62747192,3.93238306,0.00000000,0.00000000,2.00000000);
	CreateDynamicObject(970,-2697.31054688,379.07852173,3.92647910,0.00000000,0.00000000,359.99902344);
	CreateDynamicObject(970,-2692.37377930,373.79226685,3.92839718,0.00000000,0.00000000,359.99450684);
	CreateDynamicObject(970,-2692.45971680,379.13003540,3.91866851,0.00000000,0.00000000,359.99450684);
	CreateDynamicObject(3877,-2694.81933594,373.61663818,5.04487801,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2695.22143555,379.01626587,5.03292847,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2690.27124023,373.53881836,5.04664612,0.00000000,0.00000000,0.00000000);
	CreateDynamicObject(3877,-2690.11132812,379.28613281,5.04073906,0.00000000,0.00000000,0.00000000);
//-------------------------------------------------------------------------------
	CreateDynamicObject(664, -1998.0460205078, 148.79306030273, 25.906070709229, 0, 0, 340);
	CreateDynamicObject(664, -1998.0458984375, 148.79296875, 25.906070709229, 0, 0, 325.99938964844);
	CreateDynamicObject(664, -1998.0458984375, 148.79296875, 25.906070709229, 0, 0, 303.99731445313);
	CreateDynamicObject(664, -1998.0458984375, 148.79296875, 25.906070709229, 0, 0, 287.99719238281);
	CreateDynamicObject(3472, -1997.1529541016, 148.4162902832, 32.6875, 0, 0, 0);
	CreateDynamicObject(3472, -1997.15234375, 148.416015625, 36.607498168945, 0, 0, 0);
	CreateDynamicObject(3472, -1997.15234375, 148.416015625, 44.357498168945, 0, 0, 0);
	CreateDynamicObject(3472, -1997.4702148438, 148.65103149414, 55.107498168945, 0, 0, 0);
	CreateDynamicObject(3472, -1998.1090087891, 148.44111633301, 50.607498168945, 40, 0, 0);
	CreateDynamicObject(3472, -2001.8745117188, 148.5101776123, 47.607498168945, 39.995727539063, 0, 90);
	CreateDynamicObject(3472, -2000.2878417969, 145.7417755127, 50.607498168945, 39.995727539063, 0, 170);
	CreateDynamicObject(3472, -1996.1226806641, 149.14767456055, 44.607498168945, 39.995727539063, 0, 277.99694824219);
	CreateDynamicObject(3472, -1996.2100830078, 149.05192565918, 41.607498168945, 39.995727539063, 0, 277.99255371094);
	CreateDynamicObject(3472, -2000.4672851563, 151.34553527832, 41.607498168945, 39.995727539063, 0, 39.992553710938);
	CreateDynamicObject(3472, -1999.8195800781, 147.89109802246, 41.607498168945, 39.995727539063, 0, 127.990234375);
	CreateDynamicObject(3472, -1998.1652832031, 147.17254638672, 41.607498168945, 39.995727539063, 0, 207.98522949219);
	CreateDynamicObject(3472, -1997.15234375, 148.416015625, 28.857498168945, 0, 0, 310);
	CreateDynamicObject(3515, -1998.8930664063, 144.0747833252, 27.581159591675, 0, 0, 0);
	CreateDynamicObject(3515, -1998.8284912109, 154.17958068848, 27.831155776978, 0, 0, 0);
	CreateDynamicObject(3534, -1998.560546875, 141.37292480469, 48.970138549805, 28, 0, 352);
	CreateDynamicObject(3534, -1993.6901855469, 142.69296264648, 48.970138549805, 27.998657226563, 0, 29.996459960938);
	CreateDynamicObject(3534, -1991.8308105469, 148.89370727539, 48.970138549805, 27.998657226563, 0, 85.99267578125);
	CreateDynamicObject(3534, -1995.1551513672, 155.28498840332, 48.970138549805, 27.998657226563, 0, 123.98999023438);
	CreateDynamicObject(3534, -1999.73828125, 155.6160736084, 48.970138549805, 27.998657226563, 0, 159.98620605469);
	CreateDynamicObject(3534, -2004.7911376953, 149.40711975098, 48.970138549805, 27.998657226563, 0, 215.98291015625);
	CreateDynamicObject(3534, -2002.8659667969, 144.27090454102, 48.970138549805, 27.998657226563, 0, 277.98022460938);
	CreateDynamicObject(3534, -2001.7861328125, 145.97839355469, 56.220138549805, 27.998657226563, 0, 291.97607421875);
	CreateDynamicObject(3534, -2001.3598632813, 150.37046813965, 56.220138549805, 27.998657226563, 0, 253.97265625);
	CreateDynamicObject(3534, -1997.0113525391, 150.35415649414, 55.470138549805, 27.998657226563, 0, 177.97094726563);
	CreateDynamicObject(3534, -1995.1121826172, 147.66877746582, 55.470138549805, 27.998657226563, 0, 161.96752929688);
	CreateDynamicObject(3534, -1997.7120361328, 144.8631439209, 56.220138549805, 27.998657226563, 0, 3.97265625);
	CreateDynamicObject(3534, -2000.2390136719, 144.6975402832, 40.745124816895, 356.92108154297, 167.98248291016, 24.167358398438);
	CreateDynamicObject(3534, -2002.3602294922, 147.19053649902, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -2002.7614746094, 150.74235534668, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -2001.1950683594, 153.51251220703, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1999.08984375, 154.86074829102, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1994.4105224609, 155.89538574219, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1990.2229003906, 153.66470336914, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1989.1068115234, 150.2596282959, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1990.0328369141, 144.34252929688, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1992.7410888672, 140.88737487793, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(3534, -1996.2249755859, 139.30950927734, 40.745124816895, 356.91833496094, 167.98095703125, 24.164428710938);
	CreateDynamicObject(7666, -1998.1800537109, 148.45513916016, 74.819854736328, 0, 0, 0);
	CreateDynamicObject(7666, -1998.1796875, 148.455078125, 74.819854736328, 0, 0, 280);
	CreateDynamicObject(3472, -1997.4697265625, 148.650390625, 60.357498168945, 0, 0, 0);
//------------------------------------------------------------------------------
	CreateDynamicObject(19076, -1503.59, 758.20, 6.00,   0.00, 0.00, 0.00);
	CreateDynamicObject(19054, -1503.96, 760.58, 6.00,   0.00, 0.00, 0.00);
	CreateDynamicObject(19055, -1502.41, 757.02, 6.00,   0.00, 0.00, 0.00);
	CreateDynamicObject(19056, -1505.53, 756.86, 6.00,   0.00, 0.00, 0.00);
	CreateDynamicObject(19057, -1505.26, 759.72, 6.00,   0.00, 0.00, 0.00);
//--------------------------------------more SF objects----------------------------------------
	CreateDynamicObject(3472,-1293.96105957,471.57125854,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (2)
	CreateDynamicObject(3472,-1290.66809082,446.02911377,6.18091583,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (3)
	CreateDynamicObject(3472,-1258.05554199,467.54418945,6.18750381,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (4)
	CreateDynamicObject(3472,-1260.64416504,444.49423218,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (5)
	CreateDynamicObject(3472,-1229.65881348,453.10644531,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (6)
	CreateDynamicObject(3472,-1373.04516602,475.83438110,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (7)
	CreateDynamicObject(3472,-1478.45825195,460.13754272,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (8)
	CreateDynamicObject(3472,-1529.34753418,515.56933594,6.17968750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (9)
	CreateDynamicObject(3472,-1567.61364746,549.51361084,6.17968750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (10)
	CreateDynamicObject(3472,-1568.94836426,643.86126709,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (11)
	CreateDynamicObject(3472,-1524.52832031,660.17004395,7.41608429,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (12)
	CreateDynamicObject(3472,-1501.54455566,720.14257812,6.18531418,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (13)
	CreateDynamicObject(3472,-1499.36853027,776.62878418,6.18531609,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (14)
	CreateDynamicObject(3472,-1550.60546875,781.25585938,6.26562500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (15)
	CreateDynamicObject(3472,-1520.44885254,815.79431152,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (16)
	CreateDynamicObject(3472,-1544.27246094,886.05963135,6.26562452,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (17)
	CreateDynamicObject(3472,-1581.40991211,822.94024658,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (18)
	CreateDynamicObject(3472,-1509.78454590,899.04162598,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (19)
	CreateDynamicObject(3472,-1546.51574707,913.64306641,6.03906250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (20)
	CreateDynamicObject(3472,-1518.42053223,982.31994629,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (21)
	CreateDynamicObject(3472,-1518.47070312,982.08013916,6.30566978,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (22)
	CreateDynamicObject(3472,-1550.61291504,961.41210938,6.26562500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (23)
	CreateDynamicObject(3472,-1553.86828613,1010.84375000,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (24)
	CreateDynamicObject(3472,-1553.73522949,1010.60394287,6.64642811,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (25)
	CreateDynamicObject(3472,-1579.41711426,998.09582520,6.26562500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (26)
	CreateDynamicObject(3472,-1562.93664551,1053.31579590,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (27)
	CreateDynamicObject(3472,-1562.88769531,1053.07592773,6.26924467,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (28)
	CreateDynamicObject(3472,-1593.29321289,1056.06738281,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (29)
	CreateDynamicObject(3472,-1592.88037109,1104.89196777,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (30)
	CreateDynamicObject(3472,-1560.65539551,1120.92175293,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (31)
	CreateDynamicObject(3472,-1623.77185059,641.17657471,9.65450096,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (32)
	CreateDynamicObject(3472,-1640.87207031,674.90277100,8.93161583,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (33)
	CreateDynamicObject(3472,-1699.64978027,704.69982910,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (34)
	CreateDynamicObject(3472,-1701.62536621,679.50115967,27.78968430,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (35)
	CreateDynamicObject(3472,-1724.50158691,693.65356445,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (36)
	CreateDynamicObject(3472,-1705.47058105,744.39886475,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (37)
	CreateDynamicObject(3472,-1709.11193848,623.88732910,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (38)
	CreateDynamicObject(3472,-1724.10241699,740.69903564,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (39)
	CreateDynamicObject(3472,-1660.48291016,742.40258789,16.72198486,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (40)
	CreateDynamicObject(3472,-1651.47204590,723.47357178,15.10015297,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (41)
	CreateDynamicObject(3472,-1615.34167480,737.95001221,12.58959675,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (42)
	CreateDynamicObject(3472,-1607.08288574,723.17523193,11.25325871,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (43)
	CreateDynamicObject(3472,-1624.35449219,825.00469971,6.38964462,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (44)
	CreateDynamicObject(3472,-1700.49682617,859.54553223,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (45)
	CreateDynamicObject(3472,-1727.25012207,832.10980225,23.88281250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (46)
	CreateDynamicObject(3472,-1703.49011230,830.76989746,23.88281250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (47)
	CreateDynamicObject(3472,-1724.87207031,860.37762451,23.88281250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (48)
	CreateDynamicObject(3472,-1749.93322754,943.09399414,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (49)
	CreateDynamicObject(3472,-1703.65295410,941.42010498,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (50)
	CreateDynamicObject(3472,-1724.85913086,939.44940186,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (51)
	CreateDynamicObject(3472,-1665.53027344,909.76446533,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (52)
	CreateDynamicObject(3472,-1665.74206543,909.74322510,23.93263626,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (53)
	CreateDynamicObject(3472,-1637.48144531,1234.69323730,6.17968750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (54)
	CreateDynamicObject(3472,-1663.11669922,1257.96508789,6.18750381,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (55)
	CreateDynamicObject(3472,-1696.36828613,1293.80273438,6.17968750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (56)
	CreateDynamicObject(3472,-1720.56884766,1315.33398438,14.94494629,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (57)
	CreateDynamicObject(3472,-1754.96801758,1350.69250488,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (58)
	CreateDynamicObject(3472,-1779.22412109,1365.34558105,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (59)
	CreateDynamicObject(3472,-1807.24621582,1369.09082031,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (60)
	CreateDynamicObject(3472,-1839.78442383,1365.01721191,6.18749952,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (61)
	CreateDynamicObject(3472,-1870.61950684,1344.38049316,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (62)
	CreateDynamicObject(3472,-1906.68127441,1311.92297363,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (63)
	CreateDynamicObject(3472,-1913.93029785,1338.57812500,6.23189545,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (64)
	CreateDynamicObject(3472,-1966.59936523,1295.37219238,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (65)
	CreateDynamicObject(3472,-1967.86145020,1330.51306152,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (66)
	CreateDynamicObject(3472,-2032.22045898,1324.98010254,6.27741623,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (67)
	CreateDynamicObject(3472,-2059.11791992,1295.58276367,6.33593750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (68)
	CreateDynamicObject(3472,-2077.17700195,1257.81030273,11.29933167,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (69)
	CreateDynamicObject(3472,-2089.61059570,1337.08764648,7.75382042,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (70)
	CreateDynamicObject(3472,-2134.23706055,1320.89282227,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (71)
	CreateDynamicObject(3472,-2173.73852539,1340.86975098,7.54163265,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (72)
	CreateDynamicObject(3472,-2205.13208008,1321.81726074,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (73)
	CreateDynamicObject(3472,-2249.03027344,1341.90502930,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (74)
	CreateDynamicObject(3472,-2340.65991211,1363.66772461,6.27034760,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (75)
	CreateDynamicObject(3472,-2408.94897461,1386.64294434,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (76)
	CreateDynamicObject(3472,-2467.03588867,1365.49072266,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (77)
	CreateDynamicObject(3472,-2591.46240234,1381.00390625,6.10973692,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (78)
	CreateDynamicObject(3472,-2559.83496094,1357.22033691,6.18750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (79)
	CreateDynamicObject(3472,-2611.50463867,1347.07189941,6.19531202,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (80)
	CreateDynamicObject(3472,-2641.41723633,1388.83044434,6.10828972,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (81)
	CreateDynamicObject(3472,-2613.32861328,1407.99890137,6.14962482,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (82)
	CreateDynamicObject(3472,-2658.95239258,1281.64196777,6.18750048,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (83)
	CreateDynamicObject(3472,-2694.06298828,1298.85168457,6.18109035,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (84)
	CreateDynamicObject(3472,-2740.91113281,1280.98754883,5.82114124,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (85)
	CreateDynamicObject(3472,-2768.25146484,1303.40466309,5.25621080,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (86)
	CreateDynamicObject(3472,-2813.50683594,1275.10961914,4.72656250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (87)
	CreateDynamicObject(3472,-2825.19824219,1311.52380371,6.10156250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (88)
	CreateDynamicObject(3472,-2856.93774414,1214.14099121,4.73629856,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (89)
	CreateDynamicObject(3472,-2877.17382812,1222.44958496,6.10156250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (90)
	CreateDynamicObject(3472,-2874.36108398,1164.48522949,11.63819790,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (91)
	CreateDynamicObject(3472,-2599.26562500,582.26965332,14.62674332,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (92)
	CreateDynamicObject(3472,-2613.83056641,582.63970947,14.62500191,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (93)
	CreateDynamicObject(3472,-2615.22680664,601.59143066,14.62500000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (94)
	CreateDynamicObject(3472,-2599.00488281,601.62139893,14.62674332,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (95)
	CreateDynamicObject(3472,-2666.29003906,605.63476562,13.45312500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2634.42016602,607.13775635,13.45312500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (97)
	CreateDynamicObject(3472,-2697.69799805,619.00164795,13.45312500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (98)
	CreateDynamicObject(3472,-2700.64990234,582.93231201,14.81543350,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (99)
	CreateDynamicObject(3472,-2700.76367188,410.51034546,3.36718750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (100)
	CreateDynamicObject(3472,-2721.14721680,411.87704468,3.17631340,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (101)
	CreateDynamicObject(3472,-2698.97534180,343.98141479,3.41406250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (102)
	CreateDynamicObject(3472,-2713.60205078,342.31127930,3.41406250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (103)
	CreateDynamicObject(3472,-2705.25708008,289.91201782,3.28906250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (104)
	CreateDynamicObject(3472,-2017.07019043,48.86506653,30.41587448,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (105)
	CreateDynamicObject(3472,-1998.59790039,66.54217529,28.12905884,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (106)
	CreateDynamicObject(3472,-2066.35693359,52.16223526,27.53498459,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (107)
	CreateDynamicObject(3472,-2045.57324219,72.18668365,39.91793823,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (108)
	CreateDynamicObject(3472,-2064.02685547,96.19390106,27.39062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (109)
	CreateDynamicObject(3472,-2066.05908203,69.35791016,27.39062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (110)
	CreateDynamicObject(3472,-2051.78149414,116.07773590,28.08853531,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (111)
	CreateDynamicObject(3472,-2022.22412109,116.58210754,26.92206764,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (112)
	CreateDynamicObject(3472,-1994.85546875,91.80888367,26.68750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (113)
	CreateDynamicObject(3472,-1999.72644043,123.17033386,26.68750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (114)
	CreateDynamicObject(3472,-1985.12670898,111.70661926,26.68750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (115)
	CreateDynamicObject(3472,-1999.26464844,153.17291260,27.08593750,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (116)
	CreateDynamicObject(3472,-2013.57385254,153.70773315,26.68750000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (117)
	CreateDynamicObject(3472,-1991.73107910,205.28132629,26.67986298,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (118)
	CreateDynamicObject(3472,-2014.72155762,223.69349670,27.05139160,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (119)
	CreateDynamicObject(3472,-1989.80310059,253.95675659,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (120)
	CreateDynamicObject(3472,-2037.47790527,213.30299377,34.77034378,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (121)
	CreateDynamicObject(3472,-1972.75964355,332.83102417,33.53115845,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (122)
	CreateDynamicObject(3472,-1985.43359375,437.95660400,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (123)
	CreateDynamicObject(3472,-1985.44323730,437.71679688,34.28994370,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (124)
	CreateDynamicObject(3472,-1917.57788086,584.41796875,34.22170639,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (125)
	CreateDynamicObject(3472,-1911.19750977,723.03210449,44.44531250,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (126)
	CreateDynamicObject(3472,-2035.43908691,713.39001465,51.75196457,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (127)
	CreateDynamicObject(3472,-2024.85827637,679.72918701,47.81198883,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (128)
	CreateDynamicObject(3472,-1983.20715332,880.57531738,44.20312500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (129)
	CreateDynamicObject(3472,-1912.47937012,876.44409180,34.24229050,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (130)
	CreateDynamicObject(3472,-1937.45471191,893.04943848,37.51273727,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (131)
	CreateDynamicObject(3472,-1937.49206543,892.80963135,37.64380264,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (132)
	CreateDynamicObject(3472,-1891.09375000,945.79534912,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (133)
	CreateDynamicObject(3472,-1933.61303711,1133.05590820,47.34764099,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (134)
	CreateDynamicObject(3472,-1911.71374512,1103.49316406,46.47879791,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (135)
	CreateDynamicObject(3472,-1951.02807617,1100.13354492,53.67317963,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (136)
	CreateDynamicObject(3472,-1891.90270996,1225.30822754,34.75508881,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (138)
	CreateDynamicObject(3472,-2132.27954102,1158.10119629,56.62572479,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (139)
	CreateDynamicObject(18653,-2614.51049805,1378.27355957,6.14176083,0.00000000,0.00000000,0.00000000); //object(chairs) (1)
	CreateDynamicObject(18653,-2614.51684570,1373.05969238,6.10626984,0.00000000,0.00000000,0.00000000); //object(chairs) (2)
	CreateDynamicObject(18653,-2620.54956055,1381.84790039,6.17231178,0.00000000,0.00000000,90.00000000); //object(chairs) (3)
	CreateDynamicObject(18653,-2629.73242188,1381.83435059,6.17219543,0.00000000,0.00000000,90.00000000); //object(chairs) (4)
	CreateDynamicObject(18653,-2640.67333984,1381.99267578,6.17354870,0.00000000,0.00000000,90.00000000); //object(chairs) (5)
	CreateDynamicObject(18654,-2648.99316406,1376.48046875,6.18049622,0.00000000,0.00000000,180.00000000); //object(mansion-light05) (1)
	CreateDynamicObject(18654,-2648.66943359,1361.73339844,6.17915249,0.00000000,0.00000000,179.99450684); //object(mansion-light05) (2)
	CreateDynamicObject(18654,-2649.17407227,1344.03051758,6.18124771,0.00000000,0.00000000,179.99450684); //object(mansion-light05) (3)
	CreateDynamicObject(18655,-2630.03759766,1329.87109375,6.19531250,0.00000000,0.00000000,270.00000000); //object(carter-stairs01) (1)
	CreateDynamicObject(18655,-2641.14843750,1328.94580078,6.19531250,0.00000000,0.00000000,270.00000000); //object(carter-stairs01) (2)
	CreateDynamicObject(18655,-2619.07983398,1337.67651367,6.19531202,0.00000000,0.00000000,270.00000000); //object(carter-stairs01) (3)
	CreateDynamicObject(18653,-1573.58581543,666.43377686,6.19012070,0.00000000,0.00000000,0.00000000); //object(chairs) (6)
	CreateDynamicObject(18654,-1574.26953125,658.37652588,6.18750000,0.00000000,0.00000000,0.00000000); //object(mansion-light05) (4)
	CreateDynamicObject(18655,-1702.58251953,688.40405273,23.89062500,0.00000000,0.00000000,0.00000000); //object(carter-stairs01) (4)
	CreateDynamicObject(18655,-1702.30944824,680.65692139,23.89062500,0.00000000,0.00000000,0.00000000); //object(carter-stairs01) (5)
	CreateDynamicObject(18653,-2612.64624023,579.25091553,14.62500000,0.00000000,0.00000000,90.00000000); //object(chairs) (7)
	CreateDynamicObject(18653,-2601.17456055,579.05352783,14.62674332,0.00000000,0.00000000,90.00000000); //object(chairs) (8)
	CreateDynamicObject(18654,-2656.21118164,579.32592773,14.62500000,0.00000000,0.00000000,0.00000000); //object(mansion-light05) (5)
	CreateDynamicObject(18654,-2674.60913086,578.81097412,13.57416534,0.00000000,0.00000000,180.00000000); //object(mansion-light05) (6)
	CreateDynamicObject(3472,-2422.14990234,574.95202637,23.89062500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2361.98535156,502.25823975,29.08357430,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2015.01782227,584.51171875,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-1958.47534180,596.22546387,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2029.48034668,496.16537476,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2127.29736328,497.09268188,34.17187500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2244.83691406,532.76287842,34.14505005,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2261.16967773,601.58367920,39.46350479,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(3472,-2261.08129883,746.97790527,48.29687500,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (96)
	CreateDynamicObject(7862,-1524.21191406,881.68579102,22.63117027,0.00000000,0.00000000,0.00000000); //object(vgntelwires22) (2)
	CreateDynamicObject(7862,-1524.21191406,881.68579102,22.63117027,0.00000000,0.00000000,0.00000000); //object(vgntelwires22) (2)
	
	// LV-AIRPORT NOVA (Slay)
    CreateDynamicObject(10767,-1993.40002441,2131.19995117,-10.00000000,0.00000000,0.00000000,20.00000000); //object(airport_11_sfse) (1)
    CreateDynamicObject(10757,-1979.59997559,2201.19995117,7.00000000,0.00000000,0.00000000,0.00000000); //object(airport_04_sfse) (1)
    CreateDynamicObject(10757,-1948.00000000,2193.60009766,7.00000000,0.00000000,0.00000000,300.00000000); //object(airport_04_sfse) (2)
    CreateDynamicObject(3624,-1970.50000000,2178.69995117,9.30000019,0.00000000,0.00000000,64.24795532); //object(nwwarhus) (1)
    CreateDynamicObject(10767,-2058.80004883,1991.30004883,-10.00000000,0.00000000,0.00000000,19.99511719); //object(airport_11_sfse) (2)
    CreateDynamicObject(5706,-2104.89990234,1922.30004883,-8.10000038,90.00000000,180.00000000,155.07446289); //object(studiobld03_law) (2)
    CreateDynamicObject(5706,-2081.00000000,1911.19995117,-8.10000038,90.00000000,179.99450684,155.07202148); //object(studiobld03_law) (3)
    CreateDynamicObject(3374,-1989.09997559,2174.30004883,6.09999990,0.00000000,0.00000000,336.16528320); //object(sw_haybreak02) (1)
    CreateDynamicObject(3374,-1992.69995117,2176.00000000,6.09999990,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (2)
    CreateDynamicObject(3374,-1996.40002441,2177.39990234,6.50000000,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (3)
    CreateDynamicObject(3374,-2000.00000000,2179.10009766,6.19999981,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (4)
    CreateDynamicObject(3374,-1962.69995117,2161.69995117,6.09999990,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (5)
    CreateDynamicObject(3374,-1959.19995117,2160.10009766,6.09999990,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (6)
    CreateDynamicObject(3374,-1955.80004883,2158.39990234,6.50000000,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (7)
    CreateDynamicObject(3374,-1952.19995117,2157.00000000,6.19999981,0.00000000,0.00000000,336.16516113); //object(sw_haybreak02) (8)
    CreateDynamicObject(3472,-2001.40002441,2169.89990234,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (1)
    CreateDynamicObject(3472,-2011.80004883,2144.89990234,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (2)
    CreateDynamicObject(3472,-2023.00000000,2122.30004883,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (3)
    CreateDynamicObject(3472,-2032.30004883,2102.80004883,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (4)
    CreateDynamicObject(3472,-2040.50000000,2084.30004883,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (5)
    CreateDynamicObject(3472,-2050.30004883,2060.50000000,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (6)
    CreateDynamicObject(3472,-2060.80004883,2039.09997559,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (7)
    CreateDynamicObject(3472,-2069.10009766,2022.00000000,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (8)
    CreateDynamicObject(3472,-2077.30004883,2004.59997559,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (9)
    CreateDynamicObject(3472,-2085.50000000,1987.19995117,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (10)
    CreateDynamicObject(3472,-2093.19995117,1969.40002441,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (11)
    CreateDynamicObject(3472,-2102.39990234,1948.90002441,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (12)
    CreateDynamicObject(3472,-2111.39990234,1930.80004883,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (13)
    CreateDynamicObject(3472,-2070.39990234,1911.00000000,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (14)
    CreateDynamicObject(3472,-2063.00000000,1928.40002441,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (15)
    CreateDynamicObject(3472,-2054.19995117,1948.69995117,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (16)
    CreateDynamicObject(3472,-2045.90002441,1965.90002441,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (17)
    CreateDynamicObject(3472,-2037.59997559,1982.90002441,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (18)
    CreateDynamicObject(3472,-2029.30004883,2000.09997559,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (19)
    CreateDynamicObject(3472,-2020.19995117,2020.19995117,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (20)
    CreateDynamicObject(3472,-2010.59997559,2041.09997559,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (21)
    CreateDynamicObject(3472,-2000.19995117,2064.00000000,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (22)
    CreateDynamicObject(3472,-1990.40002441,2085.00000000,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (23)
    CreateDynamicObject(3472,-1982.90002441,2101.80004883,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (24)
    CreateDynamicObject(3472,-1972.40002441,2124.89990234,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (25)
    CreateDynamicObject(3472,-1961.19995117,2150.39990234,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (26)
    CreateDynamicObject(3472,-1929.19995117,2204.10009766,6.90000010,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (27)
    CreateDynamicObject(3472,-1949.59997559,2211.89990234,9.30000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (28)
    CreateDynamicObject(3472,-1977.59997559,2227.00000000,12.50000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (29)
    CreateDynamicObject(3472,-1988.09997559,2192.39990234,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (30)
    CreateDynamicObject(3472,-1944.40002441,2180.60009766,5.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (31)

	// BAYSIDE AIRPORT (Slay)
    CreateDynamicObject(10766,-2351.19995117,2564.68994141,24.00000000,0.00000000,0.00000000,274.24792480); //object(airport_10_sfse) (1)
    CreateDynamicObject(10767,-2436.30004883,2557.89990234,11.39999962,0.00000000,0.00000000,320.00000000); //object(airport_11_sfse) (3)
    CreateDynamicObject(3472,-2508.60009766,2527.50000000,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (32)
    CreateDynamicObject(3472,-2476.60009766,2531.00000000,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (33)
    CreateDynamicObject(3472,-2455.60009766,2533.19995117,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (34)
    CreateDynamicObject(3472,-2432.50000000,2535.89990234,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (35)
    CreateDynamicObject(3472,-2410.50000000,2538.10009766,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (36)
    CreateDynamicObject(3472,-2393.00000000,2539.80004883,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (37)
    CreateDynamicObject(3472,-2370.80004883,2541.80004883,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (38)
    CreateDynamicObject(3472,-2350.69995117,2543.89990234,26.39999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (39)
    CreateDynamicObject(3472,-2324.39990234,2545.19995117,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (40)
    CreateDynamicObject(3472,-2300.80004883,2546.80004883,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (41)
    CreateDynamicObject(3472,-2279.89990234,2548.30004883,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (42)
    CreateDynamicObject(3472,-2245.30004883,2550.89990234,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (43)
    CreateDynamicObject(3472,-2245.39990234,2566.60009766,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (44)
    CreateDynamicObject(3472,-2263.19995117,2583.69995117,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (45)
    CreateDynamicObject(3472,-2282.10009766,2582.89990234,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (46)
    CreateDynamicObject(3472,-2301.39990234,2579.50000000,26.29999924,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (47)
    CreateDynamicObject(3268,-2506.80004883,2546.60009766,26.00000000,0.00000000,0.00000000,186.16528320); //object(mil_hangar1_) (1)
    CreateDynamicObject(5706,-2517.69995117,2538.30004883,13.00000000,90.00000000,180.00000000,95.75241089); //object(studiobld03_law) (1)
    CreateDynamicObject(5706,-2520.00000000,2559.89990234,13.00000000,90.00000000,179.99450684,95.75134277); //object(studiobld03_law) (4)
    
    // SAN FIERO ZRACNA LUKA (Slay)
    CreateDynamicObject(10767,-2971.00000000,863.70001221,0.00000000,0.00000000,0.00000000,127.66937256); //object(airport_11_sfse) (1)
    CreateDynamicObject(10766,-3096.89990234,879.20001221,12.69999981,0.00000000,0.00000000,83.83471680); //object(airport_10_sfse) (3)
    CreateDynamicObject(3268,-2916.19995117,857.29998779,14.60000038,0.00000000,0.00000000,353.83471680); //object(mil_hangar1_) (1)
    CreateDynamicObject(3374,-2922.50000000,875.20001221,16.10000038,0.00000000,0.00000000,356.16528320); //object(sw_haybreak02) (1)
    CreateDynamicObject(3374,-2922.50000000,879.09997559,16.50000000,0.00000000,0.00000000,350.40820312); //object(sw_haybreak02) (2)
    CreateDynamicObject(3374,-2921.80004883,883.50000000,16.29999924,0.00000000,0.00000000,350.40344238); //object(sw_haybreak02) (3)
    CreateDynamicObject(3374,-2926.10009766,841.20001221,16.10000038,0.00000000,0.00000000,354.23815918); //object(sw_haybreak02) (4)
    CreateDynamicObject(3374,-2926.89990234,837.40002441,16.39999962,0.00000000,0.00000000,354.23767090); //object(sw_haybreak02) (5)
    CreateDynamicObject(3374,-2927.39990234,832.20001221,16.29999924,0.00000000,0.00000000,354.23767090); //object(sw_haybreak02) (6)
    CreateDynamicObject(3472,-2890.00000000,876.50000000,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (1)
    CreateDynamicObject(3472,-2913.60009766,879.20001221,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (2)
    CreateDynamicObject(3472,-2940.19995117,882.40002441,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (3)
    CreateDynamicObject(3472,-2960.60009766,885.79998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (4)
    CreateDynamicObject(3472,-2982.89990234,888.09997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (5)
    CreateDynamicObject(3472,-3003.50000000,890.59997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (6)
    CreateDynamicObject(3472,-3024.30004883,892.59997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (7)
    CreateDynamicObject(3472,-3043.80004883,895.20001221,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (8)
    CreateDynamicObject(3472,-3061.00000000,898.09997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (9)
    CreateDynamicObject(3472,-3078.19995117,899.59997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (10)
    CreateDynamicObject(3472,-3098.80004883,902.29998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (11)
    CreateDynamicObject(3472,-3120.89990234,905.09997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (12)
    CreateDynamicObject(3472,-3140.50000000,907.00000000,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (13)
    CreateDynamicObject(3472,-3159.69995117,909.59997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (14)
    CreateDynamicObject(3472,-3183.19995117,912.50000000,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (15)
    CreateDynamicObject(3472,-3201.50000000,915.40002441,14.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (16)
    CreateDynamicObject(3472,-3203.50000000,896.90002441,14.89999962,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (17)
    CreateDynamicObject(3472,-3205.89990234,877.00000000,14.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (18)
    CreateDynamicObject(3472,-3187.39990234,863.20001221,14.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (19)
    CreateDynamicObject(3472,-3169.50000000,860.90002441,14.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (20)
    CreateDynamicObject(3472,-3150.60009766,859.00000000,14.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (21)
    CreateDynamicObject(3472,-3124.50000000,857.50000000,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (22)
    CreateDynamicObject(3472,-3104.00000000,855.40002441,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (23)
    CreateDynamicObject(3472,-3085.89990234,853.40002441,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (24)
    CreateDynamicObject(3472,-3067.39990234,853.29998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (25)
    CreateDynamicObject(3472,-3051.50000000,850.79998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (26)
    CreateDynamicObject(3472,-3034.80004883,849.09997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (27)
    CreateDynamicObject(3472,-3011.39990234,846.79998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (28)
    CreateDynamicObject(3472,-2993.39990234,844.50000000,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (29)
    CreateDynamicObject(3472,-2971.30004883,842.29998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (30)
    CreateDynamicObject(3472,-2954.30004883,839.09997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (31)
    CreateDynamicObject(3472,-2921.30004883,835.29998779,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (32)
    CreateDynamicObject(3472,-2907.50000000,832.09997559,15.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (33)
    CreateDynamicObject(10764,-3172.80004883,885.70001221,18.39999962,0.00000000,0.00000000,130.00000000); //object(app_light_sfs05e) (1)
    
    // LAS VENTURAS NOVI AIRPORT (Slay 0.3e)
    CreateDynamicObject(19454,2404.39990234,612.00000000,11.10000038,0.00000000,0.00000000,0.00000000); //object(cs_detrok06) (1)
    CreateDynamicObject(19454,2404.39990234,602.59997559,11.10000038,0.00000000,0.00000000,0.00000000); //object(cs_detrok06) (2)
    CreateDynamicObject(19454,2404.39990234,593.40002441,11.10000038,0.00000000,0.00000000,0.00000000); //object(cs_detrok06) (3)
    CreateDynamicObject(19454,2409.10009766,588.59997559,11.10000038,0.00000000,0.00000000,89.99996948); //object(cs_detrok06) (5)
    CreateDynamicObject(19454,2418.60009766,588.59997559,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (6)
    CreateDynamicObject(19454,2427.89990234,588.59997559,11.10000038,0.00000000,0.00000000,89.99996948); //object(cs_detrok06) (7)
    CreateDynamicObject(19454,2437.10009766,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (8)
    CreateDynamicObject(19454,2446.30004883,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (9)
    CreateDynamicObject(19454,2455.60009766,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (10)
    CreateDynamicObject(19454,2464.89990234,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (11)
    CreateDynamicObject(19454,2474.50000000,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (12)
    CreateDynamicObject(19454,2483.80004883,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (13)
    CreateDynamicObject(19454,2493.39990234,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (14)
    CreateDynamicObject(19454,2502.89990234,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (15)
    CreateDynamicObject(19454,2512.10009766,588.59997559,11.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (16)
    CreateDynamicObject(19454,2409.30004883,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (17)
    CreateDynamicObject(19454,2418.89990234,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (18)
    CreateDynamicObject(19454,2428.39990234,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (19)
    CreateDynamicObject(19454,2437.80004883,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (20)
    CreateDynamicObject(19454,2447.10009766,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (22)
    CreateDynamicObject(19454,2456.39990234,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (23)
    CreateDynamicObject(19454,2465.30004883,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (24)
    CreateDynamicObject(19454,2474.60009766,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (25)
    CreateDynamicObject(19454,2484.30004883,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (26)
    CreateDynamicObject(19454,2494.00000000,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (27)
    CreateDynamicObject(19454,2503.50000000,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (28)
    CreateDynamicObject(19454,2508.80004883,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (29)
    CreateDynamicObject(19454,2516.89990234,593.40002441,11.10000038,0.00000000,0.00000000,0.00000000); //object(cs_detrok06) (30)
    CreateDynamicObject(19454,2516.89990234,603.00000000,11.10000038,0.00000000,0.00000000,0.00000000); //object(cs_detrok06) (31)
    CreateDynamicObject(19454,2516.89990234,611.90002441,11.10000038,0.00000000,0.00000000,0.00000000); //object(cs_detrok06) (32)
    CreateDynamicObject(19454,2512.19995117,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (34)
    CreateDynamicObject(19380,2409.60009766,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (1)
    CreateDynamicObject(19380,2409.60009766,602.09997559,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (2)
    CreateDynamicObject(19380,2409.60009766,611.00000000,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (3)
    CreateDynamicObject(19380,2409.60009766,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (4)
    CreateDynamicObject(19380,2419.19995117,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (5)
    CreateDynamicObject(19380,2419.19995117,602.70001221,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (6)
    CreateDynamicObject(19380,2419.19995117,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (7)
    CreateDynamicObject(19380,2427.89990234,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (8)
    CreateDynamicObject(19380,2427.89990234,602.59997559,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (9)
    CreateDynamicObject(19380,2427.89990234,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (10)
    CreateDynamicObject(19380,2438.00000000,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (11)
    CreateDynamicObject(19380,2438.00000000,602.50000000,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (12)
    CreateDynamicObject(19380,2438.00000000,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (13)
    CreateDynamicObject(19380,2448.50000000,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (14)
    CreateDynamicObject(19380,2448.50000000,603.00000000,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (15)
    CreateDynamicObject(19380,2448.50000000,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (16)
    CreateDynamicObject(19380,2458.80004883,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (17)
    CreateDynamicObject(19380,2458.80004883,602.79998779,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (18)
    CreateDynamicObject(19380,2458.80004883,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (19)
    CreateDynamicObject(19380,2469.30004883,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (20)
    CreateDynamicObject(19380,2469.30004883,603.00000000,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (21)
    CreateDynamicObject(19380,2469.30004883,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (22)
    CreateDynamicObject(19380,2479.80004883,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (23)
    CreateDynamicObject(19380,2490.89990234,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (24)
    CreateDynamicObject(19380,2501.30004883,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (25)
    CreateDynamicObject(19380,2511.60009766,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (26)
    CreateDynamicObject(19380,2485.80004883,611.90002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (27)
    CreateDynamicObject(19380,2478.80004883,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (28)
    CreateDynamicObject(19380,2489.10009766,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (29)
    CreateDynamicObject(19380,2499.39990234,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (30)
    CreateDynamicObject(19380,2508.10009766,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (31)
    CreateDynamicObject(19380,2511.60009766,593.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (32)
    CreateDynamicObject(19380,2511.60009766,602.29998779,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (33)
    CreateDynamicObject(19380,2501.30004883,602.50000000,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (34)
    CreateDynamicObject(19380,2491.00000000,602.50000000,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (35)
    CreateDynamicObject(19380,2480.69995117,602.59997559,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (36)
    CreateDynamicObject(19380,2474.50000000,602.40002441,12.75000000,0.00000000,90.00000000,0.00000000); //object(hosbibal_sfw) (37)
    CreateDynamicObject(19454,2481.19995117,588.59997559,10.89999962,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (35)
    CreateDynamicObject(19454,2471.89990234,588.59997559,10.50000000,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (36)
    CreateDynamicObject(19454,2463.60009766,588.59997559,10.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (37)
    CreateDynamicObject(19454,2454.00000000,588.79998779,9.69999981,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (38)
    CreateDynamicObject(19454,2444.50000000,588.59997559,10.10000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (39)
    CreateDynamicObject(19454,2435.89990234,588.59997559,10.30000019,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (40)
    CreateDynamicObject(19454,2426.50000000,588.59997559,10.60000038,0.00000000,0.00000000,89.99450684); //object(cs_detrok06) (41)
    CreateDynamicObject(19454,2488.10009766,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (42)
    CreateDynamicObject(19454,2479.39990234,616.70001221,11.10000038,0.00000000,0.00000000,90.00000000); //object(cs_detrok06) (43)
    CreateDynamicObject(19381,2409.60009766,611.79998779,12.76000023,0.00000000,90.00000000,0.00000000); //object(fescape_sfw03) (2)
    CreateDynamicObject(19381,2409.60009766,602.20001221,12.76000023,0.00000000,90.00000000,0.00000000); //object(fescape_sfw03) (3)
    CreateDynamicObject(19381,2409.60009766,593.40002441,12.76000023,0.00000000,90.00000000,0.00000000); //object(fescape_sfw03) (4)
    CreateDynamicObject(4652,2462.69995117,600.50000000,12.94999981,0.00000000,0.00000000,0.00000000); //object(road04_lan2) (1)
    CreateDynamicObject(16001,2500.50000000,612.90002441,12.80000019,0.00000000,0.00000000,0.70001221); //object(drvin_projhut) (1)
    CreateDynamicObject(3934,2410.00000000,601.50000000,12.89000034,0.00000000,0.00000000,0.00000000); //object(helipad01) (1)
    CreateDynamicObject(3472,2514.50000000,615.50000000,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (1)
    CreateDynamicObject(3472,2490.50000000,614.70001221,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (2)
    CreateDynamicObject(3472,2477.10009766,615.09997559,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (3)
    CreateDynamicObject(3472,2461.30004883,614.79998779,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (4)
    CreateDynamicObject(3472,2446.50000000,614.70001221,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (5)
    CreateDynamicObject(3472,2431.39990234,615.09997559,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (6)
    CreateDynamicObject(3472,2405.80004883,615.09997559,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (7)
    CreateDynamicObject(3472,2405.30004883,589.79998779,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (8)
    CreateDynamicObject(3472,2431.39990234,589.50000000,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (9)
    CreateDynamicObject(3472,2447.60009766,589.29998779,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (10)
    CreateDynamicObject(3472,2461.89990234,589.90002441,13.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (11)
    CreateDynamicObject(3472,2479.89990234,590.20001221,13.00000000,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (12)
    CreateDynamicObject(3472,2492.30004883,589.79998779,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (13)
    CreateDynamicObject(3472,2516.39990234,589.29998779,12.80000019,0.00000000,0.00000000,0.00000000); //object(circuslampost03) (14)

	// BAYSIDE AIRPORT (...NENO...)
    CreateDynamicObject(8411,-2463.20000000,-2774.61000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2588.22000000,-2799.87000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2525.66000000,-2800.02000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2400.75000000,-2749.26000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2463.17000000,-2800.00000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2400.73000000,-2850.74000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2400.75000000,-2774.62000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(10763,-2406.84000000,-2834.67000000,50.14000000,0.00000000,0.00000000,44.66000000); //
    CreateDynamicObject(8411,-2400.72000000,-2800.05000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2400.72000000,-2825.46000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3578,-2541.60000000,-2788.02000000,16.69000000,0.00000000,0.00000000,269.67000000); //
    CreateDynamicObject(3578,-2546.84000000,-2782.86000000,16.69000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3578,-2536.77000000,-2793.15000000,16.69000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3578,-2551.76000000,-2788.10000000,16.69000000,0.00000000,0.00000000,269.67000000); //
    CreateDynamicObject(3578,-2536.62000000,-2782.87000000,16.69000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3578,-2531.73000000,-2788.21000000,16.69000000,0.00000000,0.00000000,269.67000000); //
    CreateDynamicObject(16098,-2382.50000000,-2785.70000000,22.19000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3934,-2407.30000000,-2750.29000000,17.51000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3934,-2424.89000000,-2750.36000000,17.51000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(18228,-2601.69000000,-2756.36000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2536.27000000,-2755.82000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2498.85000000,-2756.16000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2492.89000000,-2756.27000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2459.67000000,-2755.14000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2466.32000000,-2755.23000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2459.80000000,-2750.22000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2459.70000000,-2745.64000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2459.63000000,-2742.28000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2459.82000000,-2738.07000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2397.06000000,-2864.85000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2413.36000000,-2730.10000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2394.09000000,-2729.21000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2401.37000000,-2729.38000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2362.69000000,-2748.23000000,3.48000000,0.00000000,0.00000000,55.05000000); //
    CreateDynamicObject(18228,-2362.60000000,-2755.86000000,3.48000000,0.00000000,0.00000000,55.05000000); //
    CreateDynamicObject(18228,-2362.81000000,-2794.35000000,3.48000000,0.00000000,0.00000000,55.05000000); //
    CreateDynamicObject(18228,-2362.84000000,-2801.98000000,3.48000000,0.00000000,0.00000000,55.05000000); //
    CreateDynamicObject(18228,-2362.74000000,-2841.06000000,3.48000000,0.00000000,0.00000000,55.05000000); //
    CreateDynamicObject(18228,-2419.00000000,-2730.37000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2417.29000000,-2865.25000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2526.45000000,-2819.31000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2362.72000000,-2847.64000000,3.48000000,0.00000000,0.00000000,55.05000000); //
    CreateDynamicObject(18228,-2440.43000000,-2850.71000000,-0.13000000,0.00000000,0.00000000,233.86000000); //
    CreateDynamicObject(18228,-2439.74000000,-2839.48000000,3.48000000,0.00000000,0.00000000,233.86000000); //
    CreateDynamicObject(18228,-2625.27000000,-2793.17000000,3.48000000,0.00000000,0.00000000,233.86000000); //
    CreateDynamicObject(18228,-2410.12000000,-2864.88000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2409.66000000,-2867.80000000,-1.02000000,0.00000000,0.00000000,346.77000000); //
    CreateDynamicObject(18228,-2377.82000000,-2871.24000000,-1.02000000,0.00000000,0.00000000,346.77000000); //
    CreateDynamicObject(18228,-2451.39000000,-2819.35000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2458.34000000,-2819.30000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2496.64000000,-2819.14000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2502.65000000,-2818.81000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2590.30000000,-2819.13000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2439.76000000,-2848.23000000,3.48000000,0.00000000,0.00000000,233.86000000); //
    CreateDynamicObject(8411,-2525.66000000,-2774.62000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(8411,-2588.18000000,-2774.45000000,-47.55000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(18228,-2542.71000000,-2755.71000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2581.57000000,-2755.87000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2589.69000000,-2756.07000000,3.48000000,0.00000000,0.00000000,146.39000000); //
    CreateDynamicObject(18228,-2625.59000000,-2781.39000000,3.48000000,0.00000000,0.00000000,233.86000000); //
    CreateDynamicObject(18228,-2533.73000000,-2819.43000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2573.85000000,-2819.19000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2580.96000000,-2819.19000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(18228,-2597.74000000,-2819.08000000,2.18000000,0.00000000,0.00000000,324.70000000); //
    CreateDynamicObject(3472,-2483.16000000,-2817.76000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2622.13000000,-2806.13000000,19.61000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2621.97000000,-2770.30000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2587.05000000,-2756.42000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2586.74000000,-2818.15000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2536.92000000,-2817.13000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2538.64000000,-2756.48000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    CreateDynamicObject(3472,-2485.02000000,-2755.87000000,19.99000000,0.00000000,0.00000000,0.00000000); //
    
    // ...Neno... Mapa sa riverside-a
    CreateDynamicObject(6959,2591.8800000,663.4300000,9.8700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(8251,2635.3600000,656.8900000,13.6700000,0.0000000,0.0000000,89.9800000); //
    CreateDynamicObject(6959,2633.1700000,663.4100000,9.8700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1421,2623.4800000,670.6500000,10.5500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(9339,2584.1600000,643.3300000,10.4500000,0.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2571.2400000,670.4300000,10.4500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(9339,2653.8700000,670.3300000,10.4500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(9339,2624.3800000,669.7700000,2.8600000,90.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2614.8800000,643.3200000,10.4500000,0.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2588.8300000,643.3300000,10.4500000,0.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2653.8800000,656.4000000,10.4500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(9339,2571.2400000,656.5100000,10.4500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(9339,2640.9500000,643.3200000,10.4500000,0.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2584.3700000,683.3400000,10.4500000,0.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(8562,2597.3900000,723.2200000,9.7400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1468,2645.9300000,683.3600000,11.0500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1468,2631.4600000,683.4200000,11.0500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(713,2660.5600000,662.6900000,9.8000000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(647,2663.3100000,661.6900000,11.2500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(708,2567.4600000,658.9000000,9.8000000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1299,2647.7800000,671.0000000,10.2300000,0.0000000,0.0000000,334.6200000); //
    CreateDynamicObject(3567,2606.0500000,681.1500000,10.6400000,0.0000000,0.0000000,270.3200000); //
    CreateDynamicObject(3627,2582.4500000,663.2800000,13.5000000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3569,2581.8300000,673.8700000,12.1800000,0.0000000,0.0000000,270.6700000); //
    CreateDynamicObject(3569,2581.3300000,653.4000000,12.1800000,0.0000000,0.0000000,270.6700000); //
    CreateDynamicObject(3569,2581.5800000,663.4000000,12.1800000,0.0000000,0.0000000,270.6700000); //
    CreateDynamicObject(3578,2617.1500000,644.8600000,10.5400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3633,2621.9700000,667.0900000,10.2500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3633,2621.9800000,668.5400000,10.2500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3630,2635.0900000,645.9900000,11.2800000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(18257,2646.1800000,662.4500000,9.8300000,0.0000000,0.0000000,86.6700000); //
    CreateDynamicObject(16773,2635.0900000,669.7700000,12.1300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(9339,2610.4900000,683.3500000,10.4500000,0.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2645.7700000,669.7500000,3.0600000,90.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2625.7100000,669.7700000,3.0600000,90.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2627.1100000,669.7700000,3.1600000,90.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2643.0600000,669.7600000,3.1600000,90.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(9339,2644.3800000,669.7600000,3.1600000,90.0000000,0.0000000,269.9900000); //
    CreateDynamicObject(3577,2620.8100000,662.8000000,10.5800000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3572,2610.3700000,681.1900000,12.7800000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3572,2601.7700000,681.1900000,12.7800000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3470,2622.4700000,656.3100000,13.7300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3631,2626.8400000,655.7400000,11.4500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3631,2626.8400000,662.7200000,11.4300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3631,2626.8400000,659.2400000,11.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3631,2626.8400000,655.7400000,10.3700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3631,2626.8400000,659.2400000,10.3700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3631,2626.8400000,662.7200000,10.3700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3396,2645.2100000,651.0800000,9.8300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3394,2645.2200000,647.6700000,9.8300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3761,2648.9000000,655.2100000,11.8700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3761,2648.9400000,661.5900000,11.8700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3795,2641.7300000,645.2400000,10.1400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3798,2650.3800000,646.5400000,11.8300000,0.0000000,0.0000000,335.6600000); //
    CreateDynamicObject(3798,2649.6700000,647.1900000,9.8300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3798,2651.4500000,645.6200000,9.8300000,0.0000000,0.0000000,335.6600000); //
    CreateDynamicObject(2991,2651.0500000,682.2300000,11.5700000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(2991,2600.2100000,644.9900000,10.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1468,2651.1200000,683.3600000,11.0500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1468,2626.2000000,683.4300000,11.0500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1431,2629.9900000,682.5700000,10.3400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1431,2627.7900000,682.6100000,10.3400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(2991,2651.0500000,682.2300000,10.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(2991,2607.9500000,644.9900000,10.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3337,2644.2100000,683.5800000,8.3200000,0.0000000,0.0000000,89.8600000); //
    
    // TRUCK UREÐENE LOKACIJE
    CreateDynamicObject(3472,-1050.5000000,-467.3999939,34.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (1)
    CreateDynamicObject(3472,-1045.9000244,-484.3999939,31.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (2)
    CreateDynamicObject(3472,-1045.9000244,-501.1000061,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (3)
    CreateDynamicObject(3472,-1046.4000244,-522.5999756,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (4)
    CreateDynamicObject(3472,-1046.6999512,-543.7000122,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (5)
    CreateDynamicObject(3472,-1046.5999756,-560.2999878,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (6)
    CreateDynamicObject(3472,-1047.5000000,-582.5000000,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (7)
    CreateDynamicObject(3472,-1029.5000000,-583.5000000,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (8)
    CreateDynamicObject(3472,-1028.8000488,-561.4000244,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (9)
    CreateDynamicObject(3472,-1028.0000000,-543.5999756,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (10)
    CreateDynamicObject(3472,-1029.3000488,-525.0000000,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (11)
    CreateDynamicObject(3472,-1029.5999756,-502.2999878,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (12)
    CreateDynamicObject(3472,-1030.0999756,-482.8999939,31.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (13)
    CreateDynamicObject(3472,-1035.5000000,-461.1000061,35.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (14)
    CreateDynamicObject(12932,-993.7000122,-633.7999878,34.2000008,0.0000000,0.0000000,0.0000000); //object(sw_trailer02) (1)
    CreateDynamicObject(12930,-1052.3000488,-667.2999878,31.7000008,0.0000000,0.0000000,0.0000000); //object(sw_pipepile02) (1)
    CreateDynamicObject(12930,-1052.4000244,-656.0000000,31.7000008,0.0000000,0.0000000,0.0000000); //object(sw_pipepile02) (2)
    CreateDynamicObject(12943,-1016.2999878,-688.5000000,31.0000000,0.0000000,0.0000000,90.0000000); //object(sw_shed07) (1)
    CreateDynamicObject(12934,-986.7999878,-671.2000122,34.4000015,0.0000000,0.0000000,0.0000000); //object(sw_trailer03) (1)
    CreateDynamicObject(16003,-1005.7999878,-595.5000000,32.0000000,0.0000000,0.0000000,110.0000000); //object(drvin_ticket) (1)
    CreateDynamicObject(3472,-1001.0000000,-599.4000244,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (15)
    CreateDynamicObject(3472,-992.0999756,-633.5999756,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (16)
    CreateDynamicObject(3472,-1022.0999756,-682.7999878,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (17)
    CreateDynamicObject(3472,-1010.7000122,-681.5999756,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (18)
    CreateDynamicObject(3472,-1047.9000244,-672.0999756,31.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (19)
    CreateDynamicObject(3472,-989.7999878,-692.0000000,31.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (20)
    CreateDynamicObject(3578,-1003.2000122,-446.0000000,36.0000000,0.0000000,0.0000000,3.8347168); //object(dockbarr1_la) (1)
    CreateDynamicObject(3578,-1004.0000000,-443.2000122,36.0000000,0.0000000,0.0000000,34.5119629); //object(dockbarr1_la) (2)
    CreateDynamicObject(3578,-995.7000122,-437.1000061,36.0000000,0.0000000,0.0000000,38.3427734); //object(dockbarr1_la) (3)
    CreateDynamicObject(3578,-986.5999756,-434.1000061,35.9000015,0.0000000,0.0000000,358.3422852); //object(dockbarr1_la) (4)
    CreateDynamicObject(4527,-976.0999756,-442.0000000,36.0000000,0.0000000,0.0000000,140.0000000); //object(sfse_roadblock2) (1)
    CreateDynamicObject(978,-1012.7000122,-447.6000061,36.0999985,0.0000000,0.0000000,20.0000000); //object(sub_roadright) (1)
    CreateDynamicObject(978,-989.0999756,-429.2000122,36.0999985,0.0000000,0.0000000,52.3256836); //object(sub_roadright) (3)
    CreateDynamicObject(3567,-159.1999969,-241.3999939,1.3000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (1)
    CreateDynamicObject(3567,-164.8999939,-241.1000061,1.3000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (2)
    CreateDynamicObject(3567,-170.1000061,-241.0000000,1.3000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (3)
    CreateDynamicObject(3567,-175.8999939,-241.1000061,1.3000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (4)
    CreateDynamicObject(3567,-131.5000000,-210.1000061,1.3000000,0.0000000,0.0000000,150.0000000); //object(lasnfltrail) (5)
    CreateDynamicObject(3567,-137.8000031,-207.8000031,1.3000000,0.0000000,0.0000000,149.9963379); //object(lasnfltrail) (6)
    CreateDynamicObject(3564,-160.8999939,-229.3000031,2.0999999,0.0000000,0.0000000,0.0000000); //object(lastran1_la01) (1)
    CreateDynamicObject(3564,-170.8000031,-229.5000000,2.0999999,0.0000000,0.0000000,0.0000000); //object(lastran1_la01) (2)
    CreateDynamicObject(3066,-147.6999969,-222.6999969,1.5000000,0.0000000,0.0000000,91.9173584); //object(ammotrn_obj) (1)
    CreateDynamicObject(2991,-134.6999969,-202.3999939,2.8000000,0.0000000,0.0000000,60.0000000); //object(imy_bbox) (1)
    CreateDynamicObject(2991,-136.8999939,-206.1000061,2.8000000,0.0000000,0.0000000,59.9963379); //object(imy_bbox) (2)
    CreateDynamicObject(2991,-139.0000000,-209.6999969,2.8000000,0.0000000,0.0000000,59.9963379); //object(imy_bbox) (3)
    CreateDynamicObject(2991,-141.1999969,-213.3999939,2.8000000,0.0000000,0.0000000,59.9963379); //object(imy_bbox) (4)
    CreateDynamicObject(2934,-245.5000000,-208.8000031,1.9000000,0.0000000,0.0000000,339.5867920); //object(kmb_container_red) (1)
    CreateDynamicObject(2934,-243.0000000,-201.8000031,1.9000000,0.0000000,0.0000000,339.5819092); //object(kmb_container_red) (2)
    CreateDynamicObject(2934,-242.1000061,-210.0000000,1.9000000,0.0000000,0.0000000,339.5819092); //object(kmb_container_red) (3)
    CreateDynamicObject(2934,-239.6999969,-203.0000000,1.9000000,0.0000000,0.0000000,339.5819092); //object(kmb_container_red) (4)
    CreateDynamicObject(2934,-239.6999969,-203.0000000,4.8000002,0.0000000,0.0000000,339.5819092); //object(kmb_container_red) (5)
    CreateDynamicObject(2934,-239.8000031,-203.0000000,7.6999998,0.0000000,0.0000000,339.5819092); //object(kmb_container_red) (6)
    CreateDynamicObject(2934,-242.1000061,-210.0000000,4.8000002,0.0000000,0.0000000,339.5819092); //object(kmb_container_red) (7)
    CreateDynamicObject(2935,-245.5000000,-208.8000031,4.8000002,0.0000000,0.0000000,339.5867920); //object(kmb_container_yel) (1)
    CreateDynamicObject(2935,-245.5000000,-208.8000031,7.6999998,0.0000000,0.0000000,339.5819092); //object(kmb_container_yel) (2)
    CreateDynamicObject(2935,-243.0000000,-201.8000031,4.8000002,0.0000000,0.0000000,339.5819092); //object(kmb_container_yel) (3)
    CreateDynamicObject(1348,-163.1999969,-196.1000061,1.1000000,0.0000000,0.0000000,21.9173584); //object(cj_o2tanks) (1)
    CreateDynamicObject(1348,-160.5000000,-196.3999939,1.1000000,0.0000000,0.0000000,21.9122314); //object(cj_o2tanks) (2)
    CreateDynamicObject(3569,-183.3000031,-238.3000031,3.0000000,0.0000000,0.0000000,0.0000000); //object(lasntrk3) (1)
    CreateDynamicObject(3569,-188.8000031,-238.0000000,3.0000000,0.0000000,0.0000000,0.0000000); //object(lasntrk3) (2)
    CreateDynamicObject(3569,-214.6000061,-241.5000000,3.0000000,0.0000000,0.0000000,0.0000000); //object(lasntrk3) (3)
    CreateDynamicObject(3566,-183.0000000,-200.8999939,3.0000000,0.0000000,0.0000000,75.7520447); //object(lasntrk1) (1)
    CreateDynamicObject(3566,-201.6000061,-196.3999939,3.0000000,0.0000000,0.0000000,75.7507324); //object(lasntrk1) (2)
    CreateDynamicObject(3577,-156.8000031,-224.3000031,1.2000000,0.0000000,0.0000000,0.0000000); //object(dockcrates1_la) (1)
    CreateDynamicObject(3576,-162.0000000,-224.1999969,1.9000000,0.0000000,0.0000000,0.0000000); //object(dockcrates2_la) (1)
    CreateDynamicObject(3472,-297.6000061,-160.0000000,0.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (21)
    CreateDynamicObject(3472,-292.2999878,-176.1999969,0.3000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (22)
    CreateDynamicObject(3472,-285.7000122,-191.0000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (23)
    CreateDynamicObject(3472,-277.0000000,-208.1000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (24)
    CreateDynamicObject(3472,-268.3999939,-223.3999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (25)
    CreateDynamicObject(3472,-259.2999878,-237.8999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (26)
    CreateDynamicObject(3472,-251.3999939,-249.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (27)
    CreateDynamicObject(3472,-198.1999969,-262.0000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (28)
    CreateDynamicObject(3472,-140.0000000,-219.6999969,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (29)
    CreateDynamicObject(3472,-139.1000061,-200.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (30)
    CreateDynamicObject(3472,-158.3999939,-196.3999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (31)
    CreateDynamicObject(3472,-192.1000061,-198.0000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (32)
    CreateDynamicObject(3472,-238.0000000,-191.1999969,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (33)
    CreateDynamicObject(3472,-193.0000000,-231.8999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (34)
    CreateDynamicObject(3472,-209.8000031,-231.6999969,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (35)
    CreateDynamicObject(3472,-237.8999939,-214.6999969,0.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (36)
    CreateDynamicObject(3472,-199.8000031,-307.2000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (37)
    CreateDynamicObject(3472,-208.8000031,-297.0000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (38)
    CreateDynamicObject(3472,-221.1000061,-283.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (39)
    CreateDynamicObject(3472,-233.6000061,-266.5000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (40)
    CreateDynamicObject(3472,-184.1999969,-277.7999878,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (41)
    CreateDynamicObject(3472,-178.0000000,-297.2999878,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (42)
    CreateDynamicObject(3472,-177.1999969,-324.3999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (43)
    CreateDynamicObject(3472,-160.8999939,-312.7000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (44)
    CreateDynamicObject(3472,-105.3000031,-379.7000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (45)
    CreateDynamicObject(3472,-118.4000015,-346.5000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (46)
    CreateDynamicObject(3472,-128.8000031,-370.7000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (47)
    CreateDynamicObject(3472,-164.1000061,-345.2999878,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (48)
    CreateDynamicObject(3472,-146.8000031,-362.2000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (49)
    CreateDynamicObject(3472,-115.4000015,-395.1000061,0.3000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (50)
    CreateDynamicObject(3472,-98.6999969,-408.8999939,0.2000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (51)
    CreateDynamicObject(3472,-83.5000000,-418.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (52)
    CreateDynamicObject(3472,-67.0000000,-428.1000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (53)
    CreateDynamicObject(3472,-76.5999985,-440.7000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (54)
    CreateDynamicObject(3472,-95.1999969,-430.5000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (55)
    CreateDynamicObject(3472,-107.5999985,-421.7000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (56)
    CreateDynamicObject(3472,-128.1000061,-405.7000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (57)
    CreateDynamicObject(3472,-144.1999969,-391.8999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (58)
    CreateDynamicObject(3472,-158.8000031,-378.8999939,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (59)
    CreateDynamicObject(3472,-173.1999969,-364.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (60)
    CreateDynamicObject(3472,-187.8000031,-349.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (61)
    CreateDynamicObject(3472,-207.3000031,-330.1000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (62)
    CreateDynamicObject(3472,-226.3999939,-308.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (63)
    CreateDynamicObject(3472,-249.0000000,-283.2000122,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (64)
    CreateDynamicObject(3472,-264.2999878,-259.7000122,0.9000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (65)
    CreateDynamicObject(3472,-274.1000061,-246.3999939,0.6000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (66)
    CreateDynamicObject(3472,-282.7000122,-233.6999969,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (67)
    CreateDynamicObject(3472,-292.5000000,-214.1999969,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (68)
    CreateDynamicObject(3472,-300.7000122,-197.6000061,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (69)
    CreateDynamicObject(3472,-308.5000000,-178.0000000,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (70)
    CreateDynamicObject(3472,-313.7000122,-163.8000031,0.4000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (71)
    CreateDynamicObject(3472,-263.8999939,-287.8999939,0.9000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (72)
    CreateDynamicObject(3472,-280.1000061,-295.2999878,2.0999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (73)
    CreateDynamicObject(3472,-295.7999878,-296.7999878,3.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (74)
    CreateDynamicObject(3472,-309.7000122,-295.1000061,5.0999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (75)
    CreateDynamicObject(3472,-321.8999939,-290.1000061,7.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (76)
    CreateDynamicObject(3472,-318.8999939,-272.6000061,7.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (77)
    CreateDynamicObject(3472,-306.2999878,-277.7000122,5.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (78)
    CreateDynamicObject(3472,-295.7999878,-279.7000122,3.7000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (79)
    CreateDynamicObject(3472,-281.1000061,-275.7000122,2.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (80)
    CreateDynamicObject(3472,-734.2000122,-238.5000000,56.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (81)
    CreateDynamicObject(3472,-717.2999878,-238.6999969,58.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (82)
    CreateDynamicObject(3472,-701.0000000,-239.5000000,60.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (83)
    CreateDynamicObject(3472,-682.4000244,-237.8999939,62.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (84)
    CreateDynamicObject(3472,-661.0000000,-235.6000061,62.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (85)
    CreateDynamicObject(3472,-644.2999878,-233.5000000,62.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (86)
    CreateDynamicObject(12956,270.8999939,1384.5999756,12.8000002,0.0000000,0.0000000,0.0000000); //object(sw_trailerjump) (1)
    CreateDynamicObject(16304,302.7999878,1378.0000000,12.6999998,0.0000000,0.0000000,0.0000000); //object(des_gravelpile05) (1)
    CreateDynamicObject(3567,283.6000061,1357.3000488,10.5000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (7)
    CreateDynamicObject(3567,277.1000061,1356.9000244,10.5000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (8)
    CreateDynamicObject(3567,276.8999939,1376.3000488,10.5000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (9)
    CreateDynamicObject(3567,283.7000122,1378.1999512,10.5000000,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (10)
    CreateDynamicObject(3567,346.5000000,1388.6999512,6.8000002,0.0000000,0.0000000,342.7437744); //object(lasnfltrail) (11)
    CreateDynamicObject(3567,352.5000000,1408.0000000,6.5000000,0.0000000,0.0000000,342.7404785); //object(lasnfltrail) (12)
    CreateDynamicObject(3567,357.7999878,1427.0000000,6.5000000,0.0000000,0.0000000,344.6578369); //object(lasnfltrail) (13)
    CreateDynamicObject(3578,341.8999939,1375.9000244,7.0999999,0.0000000,0.0000000,281.9173584); //object(dockbarr1_la) (6)
    CreateDynamicObject(3578,342.0000000,1386.3000488,6.8000002,0.0000000,0.0000000,253.8320312); //object(dockbarr1_la) (7)
    CreateDynamicObject(3578,345.2000122,1396.6999512,6.5000000,0.0000000,0.0000000,253.8281250); //object(dockbarr1_la) (8)
    CreateDynamicObject(3578,348.3999939,1407.4000244,6.4000001,0.0000000,0.0000000,253.8281250); //object(dockbarr1_la) (9)
    CreateDynamicObject(3578,351.3999939,1418.0999756,6.4000001,0.0000000,0.0000000,253.8281250); //object(dockbarr1_la) (10)
    CreateDynamicObject(3578,354.5000000,1428.8000488,6.4000001,0.0000000,0.0000000,253.8281250); //object(dockbarr1_la) (11)
    CreateDynamicObject(3578,359.5000000,1437.5000000,6.5000000,0.0000000,0.0000000,226.1586914); //object(dockbarr1_la) (12)
    CreateDynamicObject(3472,292.2999878,1420.0999756,9.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (87)
    CreateDynamicObject(3472,308.7999878,1419.5999756,7.9000001,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (88)
    CreateDynamicObject(3472,323.1000061,1418.8000488,6.8000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (89)
    CreateDynamicObject(3472,341.8999939,1418.4000244,5.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (90)
    CreateDynamicObject(3472,336.3999939,1400.9000244,5.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (91)
    CreateDynamicObject(3472,321.6000061,1401.5000000,6.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (92)
    CreateDynamicObject(3472,308.1000061,1402.3000488,7.8000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (93)
    CreateDynamicObject(3472,291.2999878,1401.8000488,9.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (94)
    CreateDynamicObject(3472,333.2000122,1388.8000488,6.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (95)
    CreateDynamicObject(3472,328.1000061,1374.8000488,6.9000001,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (96)
    CreateDynamicObject(3472,324.2000122,1361.8000488,7.4000001,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (97)
    CreateDynamicObject(3472,321.2999878,1349.5000000,8.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (98)
    CreateDynamicObject(3472,317.7999878,1335.1999512,9.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (99)
    CreateDynamicObject(3472,314.2000122,1322.4000244,9.8000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (100)
    CreateDynamicObject(3472,309.3999939,1304.5000000,11.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (101)
    CreateDynamicObject(3472,303.8999939,1289.5999756,12.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (102)
    CreateDynamicObject(3472,297.7000122,1276.1999512,13.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (103)
    CreateDynamicObject(3472,286.8999939,1260.5000000,14.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (104)
    CreateDynamicObject(3472,272.1000061,1245.1999512,14.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (105)
    CreateDynamicObject(3472,284.8999939,1232.5000000,14.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (106)
    CreateDynamicObject(3472,301.2999878,1251.0999756,14.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (107)
    CreateDynamicObject(3472,311.8999939,1266.5000000,13.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (108)
    CreateDynamicObject(3472,320.1000061,1281.9000244,12.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (109)
    CreateDynamicObject(3472,325.5000000,1296.5000000,11.5000000,0.0000000,0.0000000,3.8347168); //object(circuslampost03) (110)
    CreateDynamicObject(3472,331.5000000,1314.0999756,10.1000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (111)
    CreateDynamicObject(3472,334.6000061,1327.6999512,9.1000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (112)
    CreateDynamicObject(3472,338.8999939,1344.0999756,8.0000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (113)
    CreateDynamicObject(3472,342.8999939,1356.8000488,7.3000002,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (114)
    CreateDynamicObject(3472,345.6000061,1370.0000000,6.5999999,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (115)
    CreateDynamicObject(3472,350.2000122,1384.1999512,6.3000002,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (116)
    CreateDynamicObject(3472,354.8999939,1400.0999756,6.0999999,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (117)
    CreateDynamicObject(3472,357.3999939,1412.3000488,5.9000001,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (118)
    CreateDynamicObject(3472,361.1000061,1423.6999512,6.0000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (119)
    CreateDynamicObject(3472,365.7000122,1444.1999512,6.0999999,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (120)
    CreateDynamicObject(3472,350.5000000,1443.6999512,6.1999998,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (121)
    CreateDynamicObject(3472,369.3999939,1453.3000488,6.5999999,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (122)
    CreateDynamicObject(3472,353.6000061,1455.6999512,6.5000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (123)
    CreateDynamicObject(3472,372.8999939,1464.5000000,7.0000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (124)
    CreateDynamicObject(3472,376.6000061,1479.0000000,7.6999998,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (125)
    CreateDynamicObject(3472,380.1000061,1489.9000244,8.5000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (126)
    CreateDynamicObject(3472,385.0000000,1507.8000488,9.8999996,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (127)
    CreateDynamicObject(3472,388.5000000,1520.4000244,11.1000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (128)
    CreateDynamicObject(3472,392.7999878,1532.6999512,12.5000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (129)
    CreateDynamicObject(3472,396.1000061,1546.8000488,14.3000002,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (130)
    CreateDynamicObject(3472,379.0000000,1548.6999512,14.0000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (131)
    CreateDynamicObject(3472,375.3999939,1534.8000488,12.1999998,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (132)
    CreateDynamicObject(3472,372.2000122,1523.0000000,11.0000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (133)
    CreateDynamicObject(3472,368.6000061,1509.1999512,9.6999998,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (134)
    CreateDynamicObject(3472,363.8999939,1494.6999512,8.5000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (135)
    CreateDynamicObject(3472,359.8999939,1481.8000488,7.6999998,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (136)
    CreateDynamicObject(3472,356.7000122,1468.4000244,7.0000000,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (137)
    CreateDynamicObject(3472,236.3000031,1421.3000488,9.6000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (138)
    CreateDynamicObject(3472,254.3999939,1443.8000488,9.6000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (139)
    CreateDynamicObject(3472,277.7000122,1431.6999512,9.6000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (140)
    CreateDynamicObject(3472,275.8999939,1394.0999756,9.6000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (141)
    CreateDynamicObject(3472,262.1000061,1373.8000488,9.6000004,0.0000000,0.0000000,3.8342285); //object(circuslampost03) (142)
    CreateDynamicObject(3567,149.6999969,1948.6999512,19.1000004,0.0000000,0.0000000,60.0000000); //object(lasnfltrail) (14)
    CreateDynamicObject(3567,150.3000031,1958.5000000,19.2000008,0.0000000,0.0000000,59.9963379); //object(lasnfltrail) (15)
    CreateDynamicObject(3567,151.1000061,1969.1999512,19.2000008,0.0000000,0.0000000,59.9963379); //object(lasnfltrail) (16)
    CreateDynamicObject(3567,150.6000061,1984.4000244,19.2000008,0.0000000,0.0000000,59.9963379); //object(lasnfltrail) (17)
    CreateDynamicObject(3567,149.0000000,1999.4000244,19.2000008,0.0000000,0.0000000,59.9963379); //object(lasnfltrail) (18)
    CreateDynamicObject(3567,148.6999969,2013.5000000,19.0000000,0.0000000,0.0000000,59.9963379); //object(lasnfltrail) (19)
    CreateDynamicObject(3567,148.5000000,2029.0000000,18.5000000,0.0000000,0.0000000,59.9963379); //object(lasnfltrail) (20)
    CreateDynamicObject(3378,117.0999985,1947.5999756,19.2999992,0.0000000,0.0000000,90.0000000); //object(ce_beerpile01) (1)
    CreateDynamicObject(3378,116.8000031,1954.3000488,19.2999992,0.0000000,0.0000000,90.0000000); //object(ce_beerpile01) (2)
    CreateDynamicObject(3378,116.9000015,1961.3000488,19.2999992,0.0000000,0.0000000,90.0000000); //object(ce_beerpile01) (3)
    CreateDynamicObject(3378,116.4000015,1968.0000000,19.3999996,0.0000000,0.0000000,90.0000000); //object(ce_beerpile01) (4)
    CreateDynamicObject(3378,116.5000000,1974.8000488,19.3999996,0.0000000,0.0000000,90.0000000); //object(ce_beerpile01) (5)
    CreateDynamicObject(3066,147.1999969,1950.1999512,21.0000000,0.0000000,0.0000000,60.0000000); //object(ammotrn_obj) (2)
    CreateDynamicObject(3052,127.6999969,1958.9000244,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (1)
    CreateDynamicObject(3052,127.6999969,1959.5000000,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (2)
    CreateDynamicObject(3052,127.6999969,1960.1999512,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (3)
    CreateDynamicObject(3052,127.6999969,1960.6999512,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (4)
    CreateDynamicObject(3052,127.6999969,1961.3000488,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (5)
    CreateDynamicObject(3052,127.6999969,1961.9000244,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (6)
    CreateDynamicObject(3052,127.6999969,1962.5000000,20.6000004,0.0000000,0.0000000,0.0000000); //object(db_ammo) (7)
    CreateDynamicObject(3015,127.8000031,1963.1999512,20.5000000,0.0000000,0.0000000,0.0000000); //object(cr_cratestack) (1)
    CreateDynamicObject(3015,127.8000031,1963.1999512,21.1000004,0.0000000,0.0000000,0.0000000); //object(cr_cratestack) (2)
    CreateDynamicObject(2991,132.8000031,1943.4000244,19.0000000,0.0000000,0.0000000,0.0000000); //object(imy_bbox) (5)
    CreateDynamicObject(2991,132.8999939,1943.5000000,20.2999992,0.0000000,0.0000000,0.0000000); //object(imy_bbox) (6)
    CreateDynamicObject(2991,132.8999939,1943.5000000,21.6000004,0.0000000,0.0000000,0.0000000); //object(imy_bbox) (7)
    CreateDynamicObject(2991,137.3999939,1943.5000000,19.0000000,0.0000000,0.0000000,0.0000000); //object(imy_bbox) (8)
    CreateDynamicObject(2991,137.3999939,1943.4000244,20.2999992,0.0000000,0.0000000,0.0000000); //object(imy_bbox) (9)
    CreateDynamicObject(2991,137.3999939,1943.3000488,21.6000004,0.0000000,0.0000000,0.0000000); //object(imy_bbox) (10)
    CreateDynamicObject(2935,146.6999969,1971.8000488,21.5000000,0.0000000,0.0000000,60.0000000); //object(kmb_container_yel) (5)
    CreateDynamicObject(2935,146.6999969,1971.8000488,24.3999996,0.0000000,0.0000000,59.9963379); //object(kmb_container_yel) (6)
    CreateDynamicObject(2934,153.3000031,1967.9000244,21.5000000,0.0000000,0.0000000,60.0000000); //object(kmb_container_red) (8)
    CreateDynamicObject(2932,153.1999969,1967.6999512,24.3999996,0.0000000,0.0000000,59.5867920); //object(kmb_container_blue) (1)
    CreateDynamicObject(2912,156.3999939,1965.0999756,20.1000004,0.0000000,0.0000000,60.0000000); //object(temp_crate1) (1)
    CreateDynamicObject(2912,156.5000000,1965.1999512,20.7999992,0.0000000,0.0000000,59.9963379); //object(temp_crate1) (2)
    CreateDynamicObject(2912,156.8999939,1965.9000244,20.1000004,0.0000000,0.0000000,59.9963379); //object(temp_crate1) (3)
    CreateDynamicObject(925,155.1000061,1955.6999512,21.1000004,0.0000000,0.0000000,110.0000000); //object(rack2) (1)
    CreateDynamicObject(930,157.6000061,1966.6999512,20.6000004,0.0000000,0.0000000,330.0000000); //object(o2_bottles) (1)
    CreateDynamicObject(930,157.8999939,1965.0999756,20.6000004,0.0000000,0.0000000,49.9963379); //object(o2_bottles) (2)
    CreateDynamicObject(2359,158.6999969,1966.0000000,20.2999992,0.0000000,0.0000000,0.0000000); //object(ammo_box_c5) (1)
    CreateDynamicObject(2934,153.1000061,1967.5999756,27.2999992,0.0000000,0.0000000,59.9963379); //object(kmb_container_red) (9)
    CreateDynamicObject(2934,146.6999969,1971.4000244,27.2999992,0.0000000,0.0000000,59.9963379); //object(kmb_container_red) (10)
    CreateDynamicObject(2932,150.5000000,1968.9000244,30.2000008,0.0000000,0.0000000,59.5843506); //object(kmb_container_blue) (2)
    CreateDynamicObject(12934,116.0000000,1984.4000244,21.5000000,0.0000000,0.0000000,0.0000000); //object(sw_trailer03) (2)
    CreateDynamicObject(3472,125.6999969,1997.3000488,18.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (143)
    CreateDynamicObject(3472,127.4000015,2027.0999756,17.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (144)
    CreateDynamicObject(3472,116.0999985,2058.8000488,16.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (145)
    CreateDynamicObject(3472,69.4000015,2060.6999512,16.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (146)
    CreateDynamicObject(3472,127.8000031,1943.0000000,18.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (147)
    CreateDynamicObject(3472,143.1000061,1943.5000000,18.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (148)
    CreateDynamicObject(3472,144.0000000,1967.9000244,18.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (149)
    CreateDynamicObject(3472,143.3000031,1998.0999756,18.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (150)
    CreateDynamicObject(3472,143.8000031,2027.6999512,17.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (151)
    CreateDynamicObject(3472,120.5999985,2079.1000977,16.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (152)
    CreateDynamicObject(3472,68.9000015,2080.8000488,16.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (153)
    CreateDynamicObject(3472,38.7999992,2078.1000977,16.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (154)
    CreateDynamicObject(3472,40.5000000,2059.0000000,16.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (155)
    CreateDynamicObject(3472,-1.2000000,2075.3000488,17.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (156)
    CreateDynamicObject(3472,3.7000000,2061.1999512,18.8999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (157)
    CreateDynamicObject(3472,-35.7000008,2073.3000488,16.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (158)
    CreateDynamicObject(3472,-33.5000000,2058.6999512,16.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (159)
    CreateDynamicObject(3472,-55.7000008,2057.6000977,16.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (160)
    CreateDynamicObject(3472,-59.0000000,2073.0000000,16.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (161)
    CreateDynamicObject(3472,-91.3000031,2055.3000488,16.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (162)
    CreateDynamicObject(3472,-91.4000015,2072.3000488,16.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (163)
    CreateDynamicObject(3472,-123.0000000,2052.6999512,16.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (164)
    CreateDynamicObject(3472,-122.3000031,2071.1999512,16.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (165)
    CreateDynamicObject(3472,-152.3000031,2067.0000000,16.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (166)
    CreateDynamicObject(3472,-144.3999939,2049.5000000,16.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (167)
    CreateDynamicObject(3472,-163.0000000,2013.4000244,14.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (168)
    CreateDynamicObject(3472,-184.1999969,2016.5000000,14.8999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (169)
    CreateDynamicObject(3472,-174.6999969,2051.3000488,15.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (170)
    CreateDynamicObject(3472,-155.3999939,1973.1999512,14.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (171)
    CreateDynamicObject(3472,-173.6999969,1971.4000244,14.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (172)
    CreateDynamicObject(3472,-179.6999969,1992.6999512,14.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (173)
    CreateDynamicObject(3472,-160.6999969,1992.3000488,14.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (174)
    CreateDynamicObject(3472,-147.5000000,1951.3000488,14.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (175)
    CreateDynamicObject(3472,-139.1000061,1925.6999512,14.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (176)
    CreateDynamicObject(3472,-157.3999939,1921.0999756,14.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (177)
    CreateDynamicObject(3472,-165.1999969,1946.1999512,14.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (178)
    CreateDynamicObject(3472,-74.4000015,1370.9000244,9.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (179)
    CreateDynamicObject(3472,-72.4000015,1355.5000000,9.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (180)
    CreateDynamicObject(3472,-105.0000000,1333.9000244,9.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (181)
    CreateDynamicObject(3472,-109.5999985,1381.6999512,9.3000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (182)
    CreateDynamicObject(3578,-71.5999985,1271.5999756,11.6999998,0.0000000,0.0000000,86.1653442); //object(dockbarr1_la) (13)
    CreateDynamicObject(3578,-70.9000015,1281.8000488,11.5000000,0.0000000,0.0000000,84.2429199); //object(dockbarr1_la) (14)
    CreateDynamicObject(3578,-69.5999985,1291.8000488,11.3999996,0.0000000,0.0000000,82.3255615); //object(dockbarr1_la) (15)
    CreateDynamicObject(3578,-68.1999969,1301.9000244,11.3999996,0.0000000,0.0000000,82.3205566); //object(dockbarr1_la) (16)
    CreateDynamicObject(3578,-66.8000031,1312.0000000,11.3000002,0.0000000,0.0000000,82.3203125); //object(dockbarr1_la) (18)
    CreateDynamicObject(3578,-65.4000015,1322.0999756,11.1999998,0.0000000,0.0000000,82.3150635); //object(dockbarr1_la) (19)
    CreateDynamicObject(3578,-64.3000031,1332.4000244,10.8999996,0.0000000,0.0000000,86.1497803); //object(dockbarr1_la) (20)
    CreateDynamicObject(3472,-414.1000061,1382.0000000,30.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (183)
    CreateDynamicObject(3472,-420.2999878,1400.0000000,30.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (184)
    CreateDynamicObject(3472,-426.2999878,1415.8000488,31.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (185)
    CreateDynamicObject(3472,-428.8999939,1429.0000000,32.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (186)
    CreateDynamicObject(3472,-419.5000000,1440.4000244,34.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (187)
    CreateDynamicObject(3472,-411.5000000,1433.4000244,36.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (188)
    CreateDynamicObject(3472,-405.1000061,1419.0999756,37.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (189)
    CreateDynamicObject(3472,-396.8999939,1403.0999756,39.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (190)
    CreateDynamicObject(3472,-390.7999878,1390.3000488,41.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (191)
    CreateDynamicObject(3472,-382.8999939,1374.6999512,43.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (192)
    CreateDynamicObject(3472,-375.1000061,1360.5000000,45.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (193)
    CreateDynamicObject(3472,-367.2000122,1345.4000244,47.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (194)
    CreateDynamicObject(3472,-357.3999939,1328.0999756,49.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (195)
    CreateDynamicObject(3472,-349.0000000,1317.5000000,50.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (196)
    CreateDynamicObject(3472,-313.1000061,1335.0999756,53.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (197)
    CreateDynamicObject(3472,-319.2000122,1348.6999512,54.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (198)
    CreateDynamicObject(3472,-327.7999878,1364.6999512,54.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (199)
    CreateDynamicObject(3472,-335.6000061,1377.4000244,55.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (200)
    CreateDynamicObject(3472,-343.0000000,1390.6999512,56.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (201)
    CreateDynamicObject(3472,-353.6000061,1409.4000244,58.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (202)
    CreateDynamicObject(3472,-364.2999878,1429.5000000,59.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (203)
    CreateDynamicObject(3472,-371.7000122,1450.5999756,60.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (204)
    CreateDynamicObject(3472,-363.6000061,1457.0000000,62.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (205)
    CreateDynamicObject(3472,-347.7999878,1441.5999756,65.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (206)
    CreateDynamicObject(3472,-340.3999939,1426.0999756,67.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (207)
    CreateDynamicObject(3472,-330.7000122,1407.0999756,69.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (208)
    CreateDynamicObject(3472,-319.5000000,1391.6999512,71.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (209)
    CreateDynamicObject(3472,-307.3999939,1387.4000244,71.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (210)
    CreateDynamicObject(3472,-292.6000061,1394.6999512,71.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (211)
    CreateDynamicObject(3472,-287.3999939,1410.9000244,71.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (212)
    CreateDynamicObject(3472,-289.2000122,1435.5999756,72.1999969,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (213)
    CreateDynamicObject(3472,-290.7000122,1457.3000488,73.3000031,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (214)
    CreateDynamicObject(3472,-292.2999878,1478.1999512,74.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (215)
    CreateDynamicObject(3472,-293.5000000,1501.5999756,74.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (216)
    CreateDynamicObject(3472,-310.3999939,1503.9000244,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (217)
    CreateDynamicObject(3472,-308.2999878,1480.5999756,74.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (218)
    CreateDynamicObject(3472,-305.5000000,1456.3000488,73.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (219)
    CreateDynamicObject(3472,-303.7999878,1433.6999512,72.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (220)
    CreateDynamicObject(3472,-302.5000000,1412.6999512,71.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (221)
    CreateDynamicObject(3472,-308.5000000,1402.5999756,71.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (222)
    CreateDynamicObject(3472,-319.8999939,1417.1999512,69.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (223)
    CreateDynamicObject(3472,-329.2999878,1436.3000488,66.8000031,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (224)
    CreateDynamicObject(3472,-333.3999939,1446.4000244,65.6999969,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (225)
    CreateDynamicObject(3472,-342.2999878,1463.6999512,63.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (226)
    CreateDynamicObject(3472,-358.6000061,1472.3000488,62.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (227)
    CreateDynamicObject(3472,-377.0000000,1469.9000244,61.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (228)
    CreateDynamicObject(3472,-385.6000061,1459.0000000,60.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (229)
    CreateDynamicObject(3472,-387.1000061,1445.0999756,60.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (230)
    CreateDynamicObject(3472,-379.2000122,1426.0999756,59.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (231)
    CreateDynamicObject(3472,-368.2000122,1404.0999756,58.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (232)
    CreateDynamicObject(3472,-358.2000122,1386.3000488,56.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (233)
    CreateDynamicObject(3472,-347.3999939,1368.5000000,55.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (234)
    CreateDynamicObject(3472,-337.2999878,1350.8000488,53.4000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (235)
    CreateDynamicObject(3472,-328.2000122,1329.8000488,53.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (236)
    CreateDynamicObject(3472,-342.2000122,1331.4000244,50.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (237)
    CreateDynamicObject(3472,-354.1000061,1351.8000488,47.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (238)
    CreateDynamicObject(3472,-361.2000122,1366.5000000,46.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (239)
    CreateDynamicObject(3472,-370.7999878,1382.5000000,43.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (240)
    CreateDynamicObject(3472,-377.2999878,1396.5999756,41.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (241)
    CreateDynamicObject(3472,-385.3999939,1411.9000244,39.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (242)
    CreateDynamicObject(3472,-392.2000122,1425.5000000,37.7000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (243)
    CreateDynamicObject(3472,-400.7000122,1443.4000244,35.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (244)
    CreateDynamicObject(3472,-418.7000122,1455.0999756,33.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (245)
    CreateDynamicObject(3472,-435.1000061,1452.6999512,33.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (246)
    CreateDynamicObject(3472,-437.2999878,1467.8000488,33.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (247)
    CreateDynamicObject(3472,-437.7999878,1485.0000000,33.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (248)
    CreateDynamicObject(3472,-439.7000122,1505.0000000,33.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (249)
    CreateDynamicObject(3472,-441.3999939,1525.6999512,34.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (250)
    CreateDynamicObject(3472,-445.2999878,1549.9000244,35.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (251)
    CreateDynamicObject(3472,-448.6000061,1576.6999512,34.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (252)
    CreateDynamicObject(3472,-446.2000122,1594.5999756,34.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (253)
    CreateDynamicObject(3472,-438.7000122,1620.4000244,34.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (254)
    CreateDynamicObject(3472,-428.0000000,1642.6999512,34.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (255)
    CreateDynamicObject(3472,-419.2999878,1658.5999756,35.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (256)
    CreateDynamicObject(3472,-433.2999878,1667.3000488,37.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (257)
    CreateDynamicObject(3472,-443.7999878,1651.0000000,36.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (258)
    CreateDynamicObject(3472,-454.7000122,1626.1999512,35.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (259)
    CreateDynamicObject(3472,-462.3999939,1600.0000000,36.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (260)
    CreateDynamicObject(3472,-464.3999939,1578.6999512,36.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (261)
    CreateDynamicObject(3472,-461.0000000,1547.1999512,36.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (262)
    CreateDynamicObject(3472,-457.6000061,1523.4000244,36.0999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (263)
    CreateDynamicObject(3472,-456.0000000,1503.8000488,35.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (264)
    CreateDynamicObject(3472,-454.7999878,1484.5999756,34.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (265)
    CreateDynamicObject(3472,-453.0000000,1465.6999512,33.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (266)
    CreateDynamicObject(3472,-449.2999878,1443.1999512,32.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (267)
    CreateDynamicObject(3472,-444.2000122,1423.8000488,32.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (268)
    CreateDynamicObject(3472,-438.0000000,1403.5999756,31.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (269)
    CreateDynamicObject(3472,-432.1000061,1385.3000488,30.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (270)
    CreateDynamicObject(3472,-425.8999939,1366.1999512,29.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (271)
    CreateDynamicObject(3472,-419.1000061,1348.4000244,28.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (272)
    CreateDynamicObject(3472,-410.0000000,1330.3000488,26.6000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (273)
    CreateDynamicObject(3472,-409.1000061,1364.4000244,28.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (274)
    CreateDynamicObject(3472,-402.7000122,1350.5999756,27.7999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (275)
    CreateDynamicObject(3472,-392.1000061,1331.0999756,26.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (276)
    CreateDynamicObject(3472,-399.0000000,1313.1999512,25.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (277)
    CreateDynamicObject(3472,-383.1000061,1316.5000000,24.8999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (278)
    CreateDynamicObject(3472,-388.2000122,1298.5999756,24.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (279)
    CreateDynamicObject(3472,-377.5000000,1286.1999512,24.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (280)
    CreateDynamicObject(3472,-365.2999878,1274.0000000,23.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (281)
    CreateDynamicObject(3472,-351.3999939,1282.0999756,23.3999996,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (282)
    CreateDynamicObject(3472,-339.0000000,1272.4000244,22.2999992,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (283)
    CreateDynamicObject(3472,-320.8999939,1262.9000244,22.5000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (284)
    CreateDynamicObject(3472,-352.2999878,1262.1999512,23.2000008,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (285)
    CreateDynamicObject(3472,-339.6000061,1254.4000244,23.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (286)
    CreateDynamicObject(3578,-352.0000000,1536.3000488,75.3000031,0.0000000,0.0000000,350.4132080); //object(dockbarr1_la) (21)
    CreateDynamicObject(3578,-364.2000122,1538.5000000,75.3000031,0.0000000,0.0000000,348.4915771); //object(dockbarr1_la) (22)
    CreateDynamicObject(3578,-376.1000061,1541.0000000,75.3000031,0.0000000,0.0000000,348.4863281); //object(dockbarr1_la) (23)
    CreateDynamicObject(3578,-381.7999878,1548.4000244,75.3000031,0.0000000,0.0000000,270.4036865); //object(dockbarr1_la) (24)
    CreateDynamicObject(3578,-379.8999939,1559.0000000,75.3000031,0.0000000,0.0000000,248.0704346); //object(dockbarr1_la) (25)
    CreateDynamicObject(3578,-373.7000122,1567.9000244,75.5999985,0.0000000,0.0000000,222.3137207); //object(dockbarr1_la) (26)
    CreateDynamicObject(3567,-359.7999878,1560.3000488,75.4000015,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (21)
    CreateDynamicObject(3567,-368.6000061,1553.4000244,75.4000015,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (22)
    CreateDynamicObject(2975,-373.3999939,1584.0000000,75.0000000,0.0000000,0.0000000,310.0000000); //object(k_cargo3) (1)
    CreateDynamicObject(2975,-374.7999878,1582.9000244,75.0999985,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (2)
    CreateDynamicObject(2975,-376.0000000,1581.8000488,75.0999985,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (3)
    CreateDynamicObject(2975,-377.3999939,1583.4000244,75.0999985,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (4)
    CreateDynamicObject(2975,-376.2000122,1584.5999756,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (5)
    CreateDynamicObject(2975,-374.8999939,1585.8000488,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (6)
    CreateDynamicObject(2975,-376.3999939,1587.3000488,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (7)
    CreateDynamicObject(2975,-378.0000000,1586.4000244,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (8)
    CreateDynamicObject(2975,-379.2999878,1585.1999512,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (9)
    CreateDynamicObject(2975,-380.6000061,1586.6999512,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (10)
    CreateDynamicObject(2975,-379.2000122,1588.0999756,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (11)
    CreateDynamicObject(2975,-378.2999878,1589.5999756,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (12)
    CreateDynamicObject(2975,-380.3999939,1590.8000488,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (13)
    CreateDynamicObject(2975,-381.6000061,1589.3000488,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (14)
    CreateDynamicObject(2975,-382.8999939,1587.8000488,74.9000015,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (15)
    CreateDynamicObject(2975,-382.7000122,1585.6999512,74.9000015,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (16)
    CreateDynamicObject(2975,-381.2000122,1584.0000000,74.9000015,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (17)
    CreateDynamicObject(2975,-379.2000122,1582.5000000,75.0000000,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (18)
    CreateDynamicObject(2975,-377.8999939,1580.4000244,75.0999985,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (19)
    CreateDynamicObject(2975,-380.0000000,1579.6999512,74.9000015,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (20)
    CreateDynamicObject(2975,-381.2999878,1581.6999512,74.9000015,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (21)
    CreateDynamicObject(2975,-383.3999939,1583.5999756,74.8000031,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (22)
    CreateDynamicObject(2975,-385.3999939,1586.1999512,74.6999969,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (23)
    CreateDynamicObject(2975,-386.3999939,1584.0999756,74.5999985,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (24)
    CreateDynamicObject(2975,-384.8999939,1582.3000488,74.6999969,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (25)
    CreateDynamicObject(2975,-383.0000000,1580.5000000,74.8000031,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (26)
    CreateDynamicObject(2975,-381.7000122,1578.3000488,74.8000031,0.0000000,0.0000000,309.9957275); //object(k_cargo3) (27)
    CreateDynamicObject(2973,-383.2000122,1575.9000244,74.8000031,0.0000000,0.0000000,310.0000000); //object(k_cargo2) (1)
    CreateDynamicObject(2973,-384.8999939,1577.9000244,74.5999985,0.0000000,0.0000000,309.9957275); //object(k_cargo2) (2)
    CreateDynamicObject(2973,-385.3999939,1574.1999512,74.6999969,0.0000000,0.0000000,309.9957275); //object(k_cargo2) (3)
    CreateDynamicObject(2973,-387.1000061,1576.0000000,74.5000000,0.0000000,0.0000000,309.9957275); //object(k_cargo2) (4)
    CreateDynamicObject(2935,-368.3999939,1557.6999512,77.6999969,0.0000000,0.0000000,358.0826416); //object(kmb_container_yel) (7)
    CreateDynamicObject(18260,-360.3999939,1576.8000488,76.6999969,0.0000000,0.0000000,311.9173584); //object(crates01) (1)
    CreateDynamicObject(2669,-388.6000061,1572.4000244,75.9000015,0.0000000,0.0000000,44.2479248); //object(cj_chris_crate) (1)
    CreateDynamicObject(2669,-391.2999878,1569.8000488,75.8000031,0.0000000,0.0000000,48.0821533); //object(cj_chris_crate) (2)
    CreateDynamicObject(3568,-393.3999939,1556.8000488,77.1999969,0.0000000,0.0000000,355.7520752); //object(lasntrk2) (1)
    CreateDynamicObject(3566,-402.6000061,1535.5999756,76.5000000,0.0000000,0.0000000,318.0826416); //object(lasntrk1) (3)
    CreateDynamicObject(3566,-375.6000061,1520.5999756,77.1999969,0.0000000,0.0000000,358.0810547); //object(lasntrk1) (4)
    CreateDynamicObject(3569,-335.8999939,1513.4000244,77.0000000,0.0000000,0.0000000,270.0000000); //object(lasntrk3) (4)
    CreateDynamicObject(3569,-335.7000122,1517.5000000,77.0000000,0.0000000,0.0000000,270.0000000); //object(lasntrk3) (5)
    CreateDynamicObject(3569,-335.7999878,1521.8000488,77.0000000,0.0000000,0.0000000,270.0000000); //object(lasntrk3) (6)
    CreateDynamicObject(3571,-398.7999878,1522.5000000,75.9000015,0.0000000,0.0000000,0.0000000); //object(lasdkrt3) (1)
    CreateDynamicObject(3571,-399.2000122,1525.9000244,75.9000015,0.0000000,0.0000000,0.0000000); //object(lasdkrt3) (2)
    CreateDynamicObject(3571,-389.7999878,1525.5999756,75.9000015,0.0000000,0.0000000,0.0000000); //object(lasdkrt3) (3)
    CreateDynamicObject(3571,-389.7000122,1522.1999512,75.9000015,0.0000000,0.0000000,0.0000000); //object(lasdkrt3) (4)
    CreateDynamicObject(3472,-354.7000122,1539.4000244,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (287)
    CreateDynamicObject(3472,-374.3999939,1542.3000488,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (288)
    CreateDynamicObject(3472,-377.6000061,1559.5000000,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (289)
    CreateDynamicObject(3472,-365.0000000,1573.4000244,74.9000015,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (290)
    CreateDynamicObject(3472,-355.0000000,1524.5000000,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (291)
    CreateDynamicObject(3472,-384.2999878,1528.4000244,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (292)
    CreateDynamicObject(3472,-394.2000122,1545.0999756,74.5999985,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (293)
    CreateDynamicObject(3472,-380.2000122,1584.5999756,75.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (294)
    CreateDynamicObject(3577,-324.1000061,1513.6999512,75.0999985,0.0000000,0.0000000,0.0000000); //object(dockcrates1_la) (3)
    CreateDynamicObject(3577,-324.1000061,1517.1999512,75.0999985,0.0000000,0.0000000,90.0000000); //object(dockcrates1_la) (4)
    CreateDynamicObject(3630,-295.6000061,1536.5000000,76.0999985,0.0000000,0.0000000,358.0826416); //object(crdboxes2_las) (1)
    CreateDynamicObject(3630,-312.2999878,1536.1999512,76.0999985,0.0000000,0.0000000,178.0773926); //object(crdboxes2_las) (2)
    CreateDynamicObject(3722,-310.6000061,1575.4000244,78.8000031,0.0000000,0.0000000,316.1652832); //object(laxrf_scrapbox) (1)
    CreateDynamicObject(5259,-358.2999878,1545.1999512,74.5999985,0.0000000,0.0000000,0.0000000); //object(las2dkwar01) (1)
    CreateDynamicObject(5260,-1728.0000000,141.1999969,4.3000002,0.0000000,0.0000000,0.0000000); //object(las2dkwar02) (1)
    CreateDynamicObject(5260,-1728.0000000,141.1999969,7.6999998,0.0000000,0.0000000,270.0000000); //object(las2dkwar02) (2)
    CreateDynamicObject(5261,-1727.3000488,135.6999969,4.8000002,0.0000000,0.0000000,359.5867920); //object(las2dkwar03) (1)
    CreateDynamicObject(8078,-1722.9000244,126.0000000,6.5999999,0.0000000,0.0000000,268.0826416); //object(vgsfrates07) (1)
    CreateDynamicObject(3567,-1746.0999756,159.1999969,3.4000001,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (23)
    CreateDynamicObject(3567,-1735.1999512,135.6999969,3.4000001,0.0000000,0.0000000,0.0000000); //object(lasnfltrail) (24)
    CreateDynamicObject(3472,-1767.1999512,186.6999969,6.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (295)
    CreateDynamicObject(3472,-1757.8000488,170.8000031,5.8000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (296)
    CreateDynamicObject(3472,-1757.5999756,153.8999939,3.8000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (297)
    CreateDynamicObject(3472,-1732.5999756,147.1999969,2.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (298)
    CreateDynamicObject(3472,-1728.5999756,165.1999969,2.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (299)
    CreateDynamicObject(3472,-1727.4000244,115.0999985,2.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (300)
    CreateDynamicObject(3472,-1723.9000244,98.1999969,2.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (301)
    CreateDynamicObject(3472,-1757.8000488,131.0000000,2.8000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (302)
    CreateDynamicObject(3472,-1757.5999756,115.1999969,3.2000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (303)
    CreateDynamicObject(3472,-1757.5999756,100.4000015,3.8000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (304)
    CreateDynamicObject(3472,-1757.6999512,81.0999985,4.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (305)
    CreateDynamicObject(3472,-1757.8000488,60.2000008,5.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (306)
    CreateDynamicObject(3472,-1757.9000244,38.2000008,6.5999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (307)
    CreateDynamicObject(3472,-1769.8000488,37.4000015,6.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (308)
    CreateDynamicObject(3472,-1769.8000488,60.9000015,5.6999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (309)
    CreateDynamicObject(3472,-1769.8000488,80.1999969,4.8000002,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (310)
    CreateDynamicObject(3472,-1769.8000488,100.9000015,3.9000001,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (311)
    CreateDynamicObject(3472,-1769.3000488,116.3000031,3.3000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (312)
    CreateDynamicObject(3472,-1769.4000244,135.3000031,2.8000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (313)
    CreateDynamicObject(3472,-1768.6999512,154.1000061,4.0000000,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (314)
    CreateDynamicObject(3472,-1769.9000244,171.6999969,6.0999999,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (315)
    CreateDynamicObject(3472,-1786.8000488,176.1000061,10.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (316)
    CreateDynamicObject(3472,-1802.4000244,175.6000061,14.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (317)
    CreateDynamicObject(3472,-1802.1999512,191.1999969,14.1000004,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (318)
    CreateDynamicObject(3472,-1787.0999756,189.6999969,10.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (319)
    
    // ...Neno... LV airport kod golf terena
    CreateDynamicObject(19340,1150.5700000,2578.8400000,10.0200000,0.0000000,0.0000000,270.0700000); //
    CreateDynamicObject(18228,1103.3000000,2555.8900000,-2.6600000,0.0000000,0.0000000,347.0700000); //
    CreateDynamicObject(19076,1089.8000000,2560.0800000,9.4800000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3472,1237.2000000,2534.7900000,12.7300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3472,1099.5200000,2554.9700000,16.6100000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3472,1083.0000000,2551.0300000,14.1600000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1224.6100000,2623.3100000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1136.1300000,2547.1700000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1063.6800000,2610.3200000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1148.9600000,2572.5200000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1097.7700000,2572.4600000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1237.4200000,2547.2800000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1063.6800000,2585.2400000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1076.5000000,2572.4400000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1076.5200000,2623.1500000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1102.1300000,2623.1800000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1127.6800000,2623.2100000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1153.3000000,2623.2400000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1178.9000000,2623.2700000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1148.9800000,2534.3800000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1136.1300000,2559.7100000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1237.4000000,2610.5300000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1237.4000000,2584.9000000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1237.4100000,2559.2900000,14.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(982,1204.4400000,2623.2900000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1224.6400000,2534.4700000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1199.0300000,2534.4400000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1173.4400000,2534.4200000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(982,1123.3200000,2572.4900000,14.4400000,0.0000000,0.0000000,270.0500000); //
    CreateDynamicObject(18850,1186.7000000,2554.7300000,1.6800000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(18850,1219.2500000,2554.7100000,1.6900000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(10763,1167.8500000,2549.5500000,17.7500000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(19454,1146.9300000,2554.9900000,15.3400000,0.0000000,0.0000000,269.9000000); //
    CreateDynamicObject(19454,1151.6900000,2550.2500000,15.3400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(19454,1142.1900000,2550.2200000,15.3400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(19454,1142.2000000,2540.6700000,15.3400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(19454,1146.9600000,2553.3200000,17.0600000,0.0000000,90.0000000,270.0000000); //
    CreateDynamicObject(1508,1151.8800000,2549.0600000,15.0200000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(1508,1151.8700000,2540.2900000,15.0200000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(19454,1151.6900000,2540.6300000,15.3400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(19454,1146.9700000,2535.9100000,15.3400000,0.0000000,0.0000000,269.9000000); //
    CreateDynamicObject(19454,1146.9500000,2537.6100000,17.0500000,0.0000000,90.0000000,269.9000000); //
    CreateDynamicObject(19454,1146.9500000,2541.1000000,17.0500000,0.0000000,90.0000000,269.9000000); //
    CreateDynamicObject(19454,1146.9600000,2544.5900000,17.0500000,0.0000000,90.0000000,269.9000000); //
    CreateDynamicObject(19454,1146.9600000,2548.0700000,17.0500000,0.0000000,90.0000000,270.0000000); //
    CreateDynamicObject(19454,1146.9600000,2551.5500000,17.0500000,0.0000000,90.0000000,270.0000000); //
    CreateDynamicObject(1540,1217.2000000,2599.4700000,8.9900000,0.0000000,0.0000000,270.3600000); //
    CreateDynamicObject(1540,1091.2200000,2598.6700000,8.9900000,0.0000000,0.0000000,270.3600000); //
    CreateDynamicObject(1540,1133.2200000,2598.9300000,8.9900000,0.0000000,0.0000000,270.3600000); //
    CreateDynamicObject(1540,1175.2100000,2599.2100000,8.9900000,0.0000000,0.0000000,270.3600000); //
    CreateDynamicObject(3472,1113.5600000,2564.0600000,13.4400000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3472,1063.9900000,2572.7500000,12.7300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3472,1063.9500000,2622.9200000,12.7300000,0.0000000,0.0000000,0.0000000); //
    CreateDynamicObject(3472,1237.0800000,2623.0500000,12.7300000,0.0000000,0.0000000,0.0000000); //
    
    // DISCO ZA PROSLAVE
    CreateDynamicObject(19388,1269.6999512,1252.9000244,11.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw15)(1)
    CreateDynamicObject(19404,1272.9000244,1252.9000244,11.6000004,0.0000000,0.0000000,90.0000000); //object(boigagr_sfw)(1)
    CreateDynamicObject(19404,1276.0999756,1252.9000244,11.6000004,0.0000000,0.0000000,90.0000000); //object(boigagr_sfw)(2)
    CreateDynamicObject(19404,1279.3000488,1252.9000244,11.6000004,0.0000000,0.0000000,90.0000000); //object(boigagr_sfw)(3)
    CreateDynamicObject(19358,1282.5000000,1252.9000244,11.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(1)
    CreateDynamicObject(19358,1266.5000000,1252.9000244,11.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(2)
    CreateDynamicObject(19358,1264.9000244,1251.4000244,11.6000004,0.0000000,0.0000000,179.5867920); //object(road_sfw12)(6)
    CreateDynamicObject(19358,1264.9000244,1248.1999512,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(9)
    CreateDynamicObject(19358,1264.9000244,1245.0000000,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(10)
    CreateDynamicObject(19358,1264.9000244,1241.8000488,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(11)
    CreateDynamicObject(19358,1264.9000244,1238.5999756,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(12)
    CreateDynamicObject(19358,1264.9000244,1235.4000244,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(13)
    CreateDynamicObject(19358,1284.0000000,1251.1999512,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(16)
    CreateDynamicObject(19358,1284.0000000,1248.0999756,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(17)
    CreateDynamicObject(19358,1284.0000000,1244.9000244,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(18)
    CreateDynamicObject(19358,1284.0000000,1241.6999512,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(19)
    CreateDynamicObject(19358,1284.0000000,1238.5000000,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(20)
    CreateDynamicObject(19358,1284.0000000,1235.3000488,11.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(21)
    CreateDynamicObject(19358,1282.4000244,1233.8000488,11.6000004,0.0000000,0.0000000,89.5824890); //object(road_sfw12)(22)
    CreateDynamicObject(19358,1279.1999512,1233.8000488,11.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(24)
    CreateDynamicObject(19358,1276.0000000,1233.8000488,11.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(25)
    CreateDynamicObject(19358,1272.8000488,1233.8000488,11.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(26)
    CreateDynamicObject(19358,1269.6999512,1233.8000488,11.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(27)
    CreateDynamicObject(19358,1266.5000000,1233.8000488,11.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(28)
    CreateDynamicObject(19360,1282.1999512,1251.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(1)
    CreateDynamicObject(19360,1282.1999512,1248.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(2)
    CreateDynamicObject(19360,1282.1999512,1245.5000000,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(3)
    CreateDynamicObject(19360,1282.1999512,1242.5999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(4)
    CreateDynamicObject(19360,1282.1999512,1239.8000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(5)
    CreateDynamicObject(19360,1282.1999512,1237.0999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(6)
    CreateDynamicObject(19360,1282.1999512,1235.4000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(7)
    CreateDynamicObject(19360,1278.9000244,1251.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(8)
    CreateDynamicObject(19360,1278.9000244,1248.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(10)
    CreateDynamicObject(19360,1278.9000244,1245.0999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(11)
    CreateDynamicObject(19360,1278.9000244,1242.0999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(12)
    CreateDynamicObject(19360,1278.9000244,1238.9000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(13)
    CreateDynamicObject(19360,1278.9000244,1235.8000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(14)
    CreateDynamicObject(19360,1278.9000244,1235.4000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(15)
    CreateDynamicObject(19360,1275.6999512,1235.4000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(16)
    CreateDynamicObject(19360,1272.5000000,1235.4000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(17)
    CreateDynamicObject(19360,1269.1999512,1235.4000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(18)
    CreateDynamicObject(19360,1266.7000732,1235.4000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(19)
    CreateDynamicObject(19360,1275.5999756,1251.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(20)
    CreateDynamicObject(19360,1272.4000244,1251.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(21)
    CreateDynamicObject(19360,1269.5999756,1251.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(22)
    CreateDynamicObject(19360,1266.6999512,1251.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(23)
    CreateDynamicObject(19360,1266.6999512,1248.0999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(24)
    CreateDynamicObject(19360,1266.6999512,1245.5000000,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(25)
    CreateDynamicObject(19360,1266.6999512,1242.3000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(26)
    CreateDynamicObject(19360,1266.6999512,1239.5999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(27)
    CreateDynamicObject(19360,1266.6999512,1237.1999512,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(28)
    CreateDynamicObject(19360,1275.4000244,1248.0999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(29)
    CreateDynamicObject(19360,1272.4000244,1248.0999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(30)
    CreateDynamicObject(19360,1269.8000488,1248.1002197,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(31)
    CreateDynamicObject(19360,1275.4000244,1245.0000000,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(32)
    CreateDynamicObject(19360,1272.1999512,1245.0000000,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(33)
    CreateDynamicObject(19360,1269.9000244,1244.9000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(34)
    CreateDynamicObject(19360,1275.9000244,1241.9000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(35)
    CreateDynamicObject(19360,1272.6999512,1241.8000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(36)
    CreateDynamicObject(19360,1270.0000000,1241.8000488,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(37)
    CreateDynamicObject(19360,1270.0999756,1238.5999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(38)
    CreateDynamicObject(19360,1273.0000000,1238.5999756,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(39)
    CreateDynamicObject(19360,1275.5000000,1238.7000732,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(40)
    CreateDynamicObject(19360,1275.5999756,1236.9000244,9.8000002,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(41)
    CreateDynamicObject(19358,1266.5000000,1252.9000244,15.1000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(29)
    CreateDynamicObject(19358,1269.5999756,1252.9000244,15.1000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(30)
    CreateDynamicObject(19358,1272.8000488,1252.9000244,15.1000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(31)
    CreateDynamicObject(19358,1276.0000000,1252.9000244,15.1000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(32)
    CreateDynamicObject(19358,1279.1999512,1252.9000244,15.1000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(33)
    CreateDynamicObject(19358,1282.4000244,1252.9000244,15.1000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(34)
    CreateDynamicObject(19358,1284.0000000,1251.4000244,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(35)
    CreateDynamicObject(19358,1284.0000000,1248.1999512,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(36)
    CreateDynamicObject(19358,1284.0000000,1245.0000000,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(37)
    CreateDynamicObject(19358,1284.0000000,1241.8000488,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(38)
    CreateDynamicObject(19358,1284.0000000,1238.5999756,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(39)
    CreateDynamicObject(19358,1284.0000000,1235.9000244,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(40)
    CreateDynamicObject(19358,1284.0000000,1235.3000488,15.1000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(41)
    CreateDynamicObject(19358,1282.4000244,1233.8000488,15.1000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(44)
    CreateDynamicObject(19358,1279.3000488,1233.8000488,15.1000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(45)
    CreateDynamicObject(19358,1276.0999756,1233.8000488,15.1000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(46)
    CreateDynamicObject(19358,1272.9000244,1233.8000488,15.1000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(47)
    CreateDynamicObject(19358,1269.6999512,1233.8000488,15.1000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(48)
    CreateDynamicObject(19358,1266.5000000,1233.8000488,15.1000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(49)
    CreateDynamicObject(19358,1264.9000244,1235.4000244,15.1000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(51)
    CreateDynamicObject(19358,1264.9000244,1238.5999756,15.1000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(52)
    CreateDynamicObject(19358,1264.9000244,1241.8000488,15.1000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(53)
    CreateDynamicObject(19358,1264.9000244,1245.0000000,15.1000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(54)
    CreateDynamicObject(19358,1264.9000244,1248.1999512,15.1000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(55)
    CreateDynamicObject(19358,1264.9000244,1251.4000244,15.1000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(56)
    CreateDynamicObject(19360,1266.6999512,1251.3000488,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(42)
    CreateDynamicObject(19360,1266.6999512,1248.3000488,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(43)
    CreateDynamicObject(19360,1266.6999512,1245.0999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(44)
    CreateDynamicObject(19360,1266.6999512,1242.1999512,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(45)
    CreateDynamicObject(19360,1266.6999512,1239.0000000,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(46)
    CreateDynamicObject(19360,1266.6999512,1236.1999512,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(47)
    CreateDynamicObject(19360,1266.6999512,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(48)
    CreateDynamicObject(19360,1269.5000000,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(49)
    CreateDynamicObject(19360,1272.0999756,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(50)
    CreateDynamicObject(19360,1275.5999756,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(51)
    CreateDynamicObject(19360,1278.5000000,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(52)
    CreateDynamicObject(19360,1281.9000244,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(53)
    CreateDynamicObject(19360,1282.1999512,1235.4000244,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(54)
    CreateDynamicObject(19360,1282.1999512,1238.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(55)
    CreateDynamicObject(19360,1279.0000000,1238.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(56)
    CreateDynamicObject(19360,1276.0000000,1238.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(57)
    CreateDynamicObject(19360,1272.5000000,1238.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(58)
    CreateDynamicObject(19360,1269.0000000,1238.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(59)
    CreateDynamicObject(19360,1270.0000000,1241.8000488,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(60)
    CreateDynamicObject(19360,1270.0000000,1244.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(61)
    CreateDynamicObject(19360,1270.0000000,1247.5999756,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(62)
    CreateDynamicObject(19360,1270.0000000,1250.8000488,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(63)
    CreateDynamicObject(19360,1270.0000000,1251.3000488,16.7999992,0.0000000,90.0000000,0.0000000); //object(newvic1_sfw)(64)
    CreateDynamicObject(19404,1269.6999512,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(boigagr_sfw)(5)
    CreateDynamicObject(19404,1266.5000000,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(boigagr_sfw)(6)
    CreateDynamicObject(19358,1272.9000244,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(57)
    CreateDynamicObject(19358,1275.8000488,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(58)
    CreateDynamicObject(19358,1279.0000000,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(59)
    CreateDynamicObject(19358,1281.5000000,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(60)
    CreateDynamicObject(19358,1282.4000244,1252.9000244,18.6000004,0.0000000,0.0000000,90.0000000); //object(road_sfw12)(61)
    CreateDynamicObject(19358,1264.9000244,1251.3000488,18.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(62)
    CreateDynamicObject(19404,1264.9000244,1248.0999756,18.6000004,0.0000000,0.0000000,180.0000000); //object(boigagr_sfw)(8)
    CreateDynamicObject(19358,1264.9000244,1244.9000244,18.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(64)
    CreateDynamicObject(19358,1264.9000244,1241.6999512,18.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(65)
    CreateDynamicObject(19358,1264.9000244,1238.5000000,18.6000004,0.0000000,0.0000000,179.5825195); //object(road_sfw12)(66)
    CreateDynamicObject(19404,1264.9000244,1235.4000244,18.6000004,0.0000000,0.0000000,179.9945068); //object(boigagr_sfw)(10)
    CreateDynamicObject(19358,1266.5000000,1233.8000488,18.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(67)
    CreateDynamicObject(19358,1269.6999512,1233.8000488,18.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(68)
    CreateDynamicObject(19358,1272.9000244,1233.8000488,18.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(69)
    CreateDynamicObject(19358,1276.0999756,1233.8000488,18.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(70)
    CreateDynamicObject(19358,1279.3000488,1233.8000488,18.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(71)
    CreateDynamicObject(19358,1282.5000000,1233.8000488,18.6000004,0.0000000,0.0000000,89.5770264); //object(road_sfw12)(72)
    CreateDynamicObject(19404,1284.0000000,1235.4000244,18.6000004,0.0000000,0.0000000,179.9945068); //object(boigagr_sfw)(11)
    CreateDynamicObject(19358,1284.0000000,1238.5999756,18.6000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(73)
    CreateDynamicObject(19358,1284.0000000,1241.8000488,18.6000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(74)
    CreateDynamicObject(19358,1284.0000000,1245.0000000,18.6000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(75)
    CreateDynamicObject(19358,1284.0000000,1248.1999512,18.6000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(76)
    CreateDynamicObject(19358,1284.0000000,1251.4000244,18.6000004,0.0000000,0.0000000,0.0000000); //object(road_sfw12)(77)
    CreateDynamicObject(19358,1282.5000000,1252.9000244,22.1000004,0.0000000,180.0000000,90.0000000); //object(road_sfw12)(78)
    CreateDynamicObject(19358,1279.4000244,1252.9000244,22.1000004,0.0000000,179.9945068,90.0000000); //object(road_sfw12)(79)
    CreateDynamicObject(19358,1276.3000488,1252.9000244,22.1000004,0.0000000,179.9945068,90.0000000); //object(road_sfw12)(80)
    CreateDynamicObject(19358,1273.0999756,1252.9000244,22.1000004,0.0000000,179.9945068,90.0000000); //object(road_sfw12)(81)
    CreateDynamicObject(19358,1269.9000244,1252.9000244,22.1000004,0.0000000,179.9945068,90.0000000); //object(road_sfw12)(82)
    CreateDynamicObject(19358,1267.5999756,1252.9000244,22.1000004,0.0000000,179.9945068,90.0000000); //object(road_sfw12)(83)
    CreateDynamicObject(19358,1266.5000000,1252.9000244,22.1000004,0.0000000,179.9945068,90.0000000); //object(road_sfw12)(84)
    CreateDynamicObject(19358,1284.0000000,1251.1999512,22.1000004,0.0000000,180.0000000,0.0000000); //object(road_sfw12)(85)
    CreateDynamicObject(19358,1284.0000000,1248.0000000,22.1000004,0.0000000,179.9945068,0.0000000); //object(road_sfw12)(86)
    CreateDynamicObject(19358,1284.0000000,1244.8000488,22.1000004,0.0000000,179.9945068,0.0000000); //object(road_sfw12)(87)
    CreateDynamicObject(19358,1284.0000000,1241.5999756,22.1000004,0.0000000,179.9945068,0.0000000); //object(road_sfw12)(88)
    CreateDynamicObject(19358,1284.0000000,1238.5000000,22.1000004,0.0000000,179.9945068,0.0000000); //object(road_sfw12)(89)
    CreateDynamicObject(19358,1284.0000000,1235.3000488,22.1000004,0.0000000,179.9945068,0.0000000); //object(road_sfw12)(90)
    CreateDynamicObject(19358,1282.4000244,1233.8000488,22.1000004,0.0000000,180.0000000,89.5770264); //object(road_sfw12)(91)
    CreateDynamicObject(19358,1279.1999512,1233.8000488,22.1000004,0.0000000,179.9945068,89.5715332); //object(road_sfw12)(92)
    CreateDynamicObject(19358,1276.0000000,1233.8000488,22.1000004,0.0000000,179.9945068,89.5715332); //object(road_sfw12)(93)
    CreateDynamicObject(19358,1272.8000488,1233.8000488,22.1000004,0.0000000,179.9945068,89.5715332); //object(road_sfw12)(94)
    CreateDynamicObject(19358,1269.5999756,1233.8000488,22.1000004,0.0000000,179.9945068,89.5715332); //object(road_sfw12)(95)
    CreateDynamicObject(19358,1266.4000244,1233.8000488,22.1000004,0.0000000,179.9945068,89.5715332); //object(road_sfw12)(96)
    CreateDynamicObject(19358,1264.9000244,1235.4000244,22.1000004,0.0000000,180.0000000,179.5825195); //object(road_sfw12)(98)
    CreateDynamicObject(19358,1264.9000244,1238.5999756,22.1000004,0.0000000,179.9945068,179.5825195); //object(road_sfw12)(99)
    CreateDynamicObject(19358,1264.9000244,1241.8000488,22.1000004,0.0000000,179.9945068,179.5825195); //object(road_sfw12)(100)
    CreateDynamicObject(19358,1264.9000244,1245.0000000,22.1000004,0.0000000,179.9945068,179.5825195); //object(road_sfw12)(101)
    CreateDynamicObject(19358,1264.9000244,1248.1999512,22.1000004,0.0000000,179.9945068,179.5825195); //object(road_sfw12)(102)
    CreateDynamicObject(19358,1264.9000244,1251.4000244,22.1000004,0.0000000,179.9945068,179.5825195); //object(road_sfw12)(103)
    CreateDynamicObject(10009,1278.5999756,1243.9000244,13.6899996,0.0000000,0.0000000,271.5041504); //object(fer_cars3_sfe)(2)
    CreateDynamicObject(19377,1270.0999756,1238.6999512,23.7000008,0.0000000,90.0000000,0.0000000); //object(freight_interiorsfw)(1)
    CreateDynamicObject(19377,1278.8000488,1238.6999512,23.7000008,0.0000000,90.0000000,0.0000000); //object(freight_interiorsfw)(2)
    CreateDynamicObject(19377,1270.0999756,1248.0000000,23.7000008,0.0000000,90.0000000,0.0000000); //object(freight_interiorsfw)(3)
    CreateDynamicObject(19377,1278.8000488,1248.0000000,23.7000008,0.0000000,90.0000000,0.0000000); //object(freight_interiorsfw)(4)
    CreateDynamicObject(997,1280.6999512,1239.8000488,16.8999996,0.0000000,0.0000000,0.0000000); //object(lhouse_barrier3)(1)
    CreateDynamicObject(997,1274.1999512,1240.0999756,16.8999996,0.0000000,0.0000000,0.0000000); //object(lhouse_barrier3)(3)
    CreateDynamicObject(997,1271.5999756,1240.0999756,16.8999996,0.0000000,0.0000000,0.0000000); //object(lhouse_barrier3)(4)
    CreateDynamicObject(997,1271.5999756,1243.4000244,16.8999996,0.0000000,0.0000000,270.0000000); //object(lhouse_barrier3)(5)
    CreateDynamicObject(997,1271.5999756,1246.5999756,16.8999996,0.0000000,0.0000000,270.0000000); //object(lhouse_barrier3)(6)
    CreateDynamicObject(997,1271.5999756,1249.8000488,16.8999996,0.0000000,0.0000000,270.0000000); //object(lhouse_barrier3)(7)
    CreateDynamicObject(997,1271.5999756,1252.8000488,16.8999996,0.0000000,0.0000000,270.0000000); //object(lhouse_barrier3)(8)
    CreateDynamicObject(3785,1273.0999756,1252.8000488,15.1999998,0.0000000,0.0000000,300.0000000); //object(bulkheadlight)(1)
    CreateDynamicObject(3785,1275.0999756,1252.8000488,15.1999998,0.0000000,0.0000000,289.9981689); //object(bulkheadlight)(2)
    CreateDynamicObject(3785,1277.0999756,1252.8000488,15.1999998,0.0000000,0.0000000,289.9951172); //object(bulkheadlight)(3)
    CreateDynamicObject(3785,1279.0000000,1252.8000488,15.1999998,0.0000000,0.0000000,289.9951172); //object(bulkheadlight)(4)
    CreateDynamicObject(3785,1281.1999512,1252.8000488,15.1999998,0.0000000,0.0000000,289.9951172); //object(bulkheadlight)(5)
    CreateDynamicObject(3785,1283.3000488,1252.8000488,15.1000004,0.0000000,0.0000000,289.9951172); //object(bulkheadlight)(6)
    CreateDynamicObject(3785,1270.9000244,1252.8000488,15.1999998,0.0000000,0.0000000,290.0000000); //object(bulkheadlight)(7)
    CreateDynamicObject(3785,1268.8000488,1252.8000488,15.1999998,0.0000000,0.0000000,289.9951172); //object(bulkheadlight)(8)
    CreateDynamicObject(3785,1266.4000244,1252.8000488,15.1999998,0.0000000,0.0000000,289.9951172); //object(bulkheadlight)(9)
    CreateDynamicObject(3785,1265.0000000,1250.8000488,15.1000004,0.0000000,0.0000000,338.0777588); //object(bulkheadlight)(10)
    CreateDynamicObject(3785,1265.0000000,1247.0999756,15.1000004,0.0000000,0.0000000,338.0767822); //object(bulkheadlight)(11)
    CreateDynamicObject(3785,1265.0000000,1243.0000000,15.1000004,0.0000000,0.0000000,338.0767822); //object(bulkheadlight)(12)
    CreateDynamicObject(3785,1265.0000000,1239.0999756,15.1000004,0.0000000,0.0000000,338.0767822); //object(bulkheadlight)(13)
    CreateDynamicObject(3785,1265.0000000,1235.3000488,15.1000004,0.0000000,0.0000000,338.0767822); //object(bulkheadlight)(14)
    CreateDynamicObject(3785,1266.8000488,1233.9000244,15.1000004,0.0000000,0.0000000,66.1594238); //object(bulkheadlight)(15)
    CreateDynamicObject(3785,1270.0000000,1233.9000244,15.0000000,0.0000000,0.0000000,66.1541748); //object(bulkheadlight)(16)
    CreateDynamicObject(3785,1272.5999756,1233.9000244,15.0000000,0.0000000,0.0000000,66.1541748); //object(bulkheadlight)(17)
    CreateDynamicObject(3785,1275.5999756,1233.9000244,15.0000000,0.0000000,0.0000000,66.1541748); //object(bulkheadlight)(18)
    CreateDynamicObject(3785,1278.4000244,1233.9000244,15.0000000,0.0000000,0.0000000,66.1541748); //object(bulkheadlight)(19)
    CreateDynamicObject(3785,1282.1999512,1233.9000244,14.8999996,0.0000000,0.0000000,66.1541748); //object(bulkheadlight)(20)
    CreateDynamicObject(3785,1283.9000244,1235.8000488,15.0000000,0.0000000,0.0000000,156.1541748); //object(bulkheadlight)(21)
    CreateDynamicObject(3785,1283.9000244,1239.3000488,15.0000000,0.0000000,0.0000000,156.1486816); //object(bulkheadlight)(22)
    CreateDynamicObject(3785,1283.9000244,1242.5999756,15.0000000,0.0000000,0.0000000,156.1486816); //object(bulkheadlight)(23)
    CreateDynamicObject(3785,1283.9000244,1245.9000244,15.1000004,0.0000000,0.0000000,156.1486816); //object(bulkheadlight)(24)
    CreateDynamicObject(3785,1283.9000244,1248.6999512,15.1000004,0.0000000,0.0000000,156.1486816); //object(bulkheadlight)(25)
    CreateDynamicObject(3785,1283.9000244,1251.1999512,15.1000004,0.0000000,0.0000000,156.1486816); //object(bulkheadlight)(26)
    CreateDynamicObject(3785,1265.0000000,1251.6999512,21.1000004,0.0000000,0.0000000,0.0000000); //object(bulkheadlight)(28)
    CreateDynamicObject(3785,1265.0000000,1248.3000488,21.0000000,0.0000000,0.0000000,0.0000000); //object(bulkheadlight)(29)
    CreateDynamicObject(3785,1265.0000000,1244.9000244,21.1000004,0.0000000,0.0000000,0.0000000); //object(bulkheadlight)(30)
    CreateDynamicObject(3785,1265.0000000,1241.0000000,21.0000000,0.0000000,0.0000000,0.0000000); //object(bulkheadlight)(31)
    CreateDynamicObject(3785,1265.0000000,1236.9000244,21.1000004,0.0000000,0.0000000,0.0000000); //object(bulkheadlight)(32)
    CreateDynamicObject(3785,1266.9000244,1233.9000244,21.1000004,0.0000000,0.0000000,70.0000000); //object(bulkheadlight)(33)
    CreateDynamicObject(3785,1270.1999512,1233.9000244,21.1000004,0.0000000,0.0000000,69.9993896); //object(bulkheadlight)(34)
    CreateDynamicObject(3785,1273.5000000,1233.9000244,21.1000004,0.0000000,0.0000000,69.9993896); //object(bulkheadlight)(35)
    CreateDynamicObject(3785,1277.4000244,1233.9000244,21.1000004,0.0000000,0.0000000,69.9993896); //object(bulkheadlight)(36)
    CreateDynamicObject(3785,1280.4000244,1233.9000244,21.1000004,0.0000000,0.0000000,69.9993896); //object(bulkheadlight)(37)
    CreateDynamicObject(3785,1283.1999512,1233.9000244,21.0000000,0.0000000,0.0000000,69.9993896); //object(bulkheadlight)(38)
    CreateDynamicObject(3785,1283.9000244,1235.4000244,20.8999996,0.0000000,0.0000000,166.1646729); //object(bulkheadlight)(39)
    CreateDynamicObject(3785,1283.9000244,1238.1999512,20.8999996,0.0000000,0.0000000,166.1627197); //object(bulkheadlight)(40)
    CreateDynamicObject(3785,1283.9000244,1240.6999512,20.8999996,0.0000000,0.0000000,166.1627197); //object(bulkheadlight)(41)
    CreateDynamicObject(3785,1283.9000244,1243.8000488,20.8999996,0.0000000,0.0000000,166.1627197); //object(bulkheadlight)(42)
    CreateDynamicObject(3785,1283.9000244,1247.9000244,20.8999996,0.0000000,0.0000000,166.1627197); //object(bulkheadlight)(43)
    CreateDynamicObject(3785,1283.9000244,1251.4000244,21.0000000,0.0000000,0.0000000,166.1627197); //object(bulkheadlight)(44)
    CreateDynamicObject(3785,1281.8000488,1252.8000488,20.8999996,0.0000000,0.0000000,256.1627197); //object(bulkheadlight)(45)
    CreateDynamicObject(3785,1278.9000244,1252.8000488,20.8999996,0.0000000,0.0000000,256.1572266); //object(bulkheadlight)(46)
    CreateDynamicObject(3785,1276.0999756,1252.8000488,20.8999996,0.0000000,0.0000000,256.1572266); //object(bulkheadlight)(47)
    CreateDynamicObject(3785,1273.0999756,1252.8000488,20.8999996,0.0000000,0.0000000,256.1572266); //object(bulkheadlight)(48)
    CreateDynamicObject(3785,1270.0000000,1252.8000488,20.8999996,0.0000000,0.0000000,256.1572266); //object(bulkheadlight)(49)
    CreateDynamicObject(3785,1267.3000488,1252.8000488,21.0000000,0.0000000,0.0000000,256.1572266); //object(bulkheadlight)(50)
    CreateDynamicObject(2780,1271.8000488,1240.5999756,16.7999992,0.0000000,0.0000000,0.0000000); //object(cj_smoke_mach)(1)
    CreateDynamicObject(2780,1276.9000244,1252.4000244,19.6000004,0.0000000,0.0000000,0.0000000); //object(cj_smoke_mach)(2)
    CreateDynamicObject(2780,1283.5999756,1246.6999512,19.1000004,0.0000000,0.0000000,270.0000000); //object(cj_smoke_mach)(3)
    CreateDynamicObject(3524,1271.0999756,1253.5000000,12.6999998,0.0000000,0.0000000,170.0000000); //object(skullpillar01_lvs)(1)
    CreateDynamicObject(3524,1268.5999756,1253.5000000,12.6999998,0.0000000,0.0000000,169.9969482); //object(skullpillar01_lvs)(2)
    CreateDynamicObject(3524,1265.5000000,1234.5000000,12.8000002,0.0000000,0.0000000,149.9969482); //object(skullpillar01_lvs)(3)
    CreateDynamicObject(3524,1283.4000244,1234.5000000,12.8000002,0.0000000,0.0000000,209.9963379); //object(skullpillar01_lvs)(4)
    CreateDynamicObject(3524,1265.8000488,1252.0000000,19.7999992,0.0000000,0.0000000,49.9926758); //object(skullpillar01_lvs)(5)
    CreateDynamicObject(3534,1266.0999756,1251.6999512,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(1)
    CreateDynamicObject(3534,1265.6999512,1245.0000000,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(3)
    CreateDynamicObject(3534,1265.5999756,1238.5999756,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(4)
    CreateDynamicObject(3534,1268.9000244,1234.5999756,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(5)
    CreateDynamicObject(3534,1274.6999512,1234.5999756,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(6)
    CreateDynamicObject(3534,1280.6999512,1234.9000244,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(7)
    CreateDynamicObject(3534,1283.0999756,1239.5999756,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(8)
    CreateDynamicObject(3534,1283.1999512,1245.0999756,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(9)
    CreateDynamicObject(3534,1283.0000000,1250.0000000,11.1999998,0.0000000,0.0000000,0.0000000); //object(trdlamp01)(10)
    CreateDynamicObject(18647,1269.8785400,1247.1412350,16.6859390,0.0000000,0.0000000,0.0000000); //disco
    CreateDynamicObject(18648,1277.6896970,1237.0634760,16.4859580,0.0000000,0.0000000,0.0000000); //disco2
    CreateDynamicObject(18649,1280.3308100,1247.3963620,23.4535420,0.0000000,0.0000000,0.0000000); //discogreen
    CreateDynamicObject(1651,1273.0241690,1252.8909910,11.7129630,359.7000120,0.0000000,88.6000060); //prozor3
    CreateDynamicObject(1651,1269.6250000,1252.8909910,18.6129890,359.7000120,0.0000000,88.6000060); //prozor4
    CreateDynamicObject(1651,1276.4233390,1252.8909910,11.7129630,359.7000120,0.0000000,88.6000060); //prozor_od_test
    CreateDynamicObject(1651,1283.9221190,1235.8951410,18.6129890,359.7000120,0.0000000,0.0000300); //prozor8
    CreateDynamicObject(2964,1266.7460930,1248.3598630,9.8859330,0.0000000,0.0000000,0.0000000); //testint
    CreateDynamicObject(1651,1264.9267570,1235.8951410,18.6129890,359.7000120,0.0000000,182.5000300); //prozor7
    CreateDynamicObject(1491,1268.9168700,1252.9792480,9.8129550,0.0000000,0.0000000,0.0000000); //test
    CreateDynamicObject(1651,1266.7257080,1252.8909910,18.6129890,359.7000120,0.0000000,88.6000060); //prozor5
    CreateDynamicObject(16151,1274.5676260,1251.7390130,10.2859350,0.0000000,0.0000000,90.0999600); //testint2
    CreateDynamicObject(1651,1279.8225090,1252.8909910,11.7129630,359.7000120,0.0000000,88.6000060); //test
    CreateDynamicObject(1651,1264.9267570,1247.8922110,18.6129890,359.7000120,0.0000000,182.5000300); //prozor6
    CreateDynamicObject(18660,1283.8725580,1249.8128660,12.1859420,0.0000000,0.0000000,0.0000000); //spray
    CreateDynamicObject(1723,1283.3070060,1248.3798820,9.8859330,0.0000000,0.0000000,270.0000000); //stolice
    CreateDynamicObject(1723,1283.3070060,1237.7824700,9.8859330,0.0000000,0.0000000,270.0000000); //stolice3
    CreateDynamicObject(1723,1272.7095940,1234.5832510,9.8859330,0.0000000,0.0000000,180.0000000); //stolice5
    CreateDynamicObject(1723,1267.3109130,1234.7832030,9.8859330,0.0000000,0.0000000,137.4000090); //stolice6
    CreateDynamicObject(1723,1283.3070060,1242.9812010,9.8859330,0.0000000,0.0000000,270.0000000); //stolice2
    CreateDynamicObject(1723,1278.7081290,1234.5832510,9.8859330,0.0000000,0.0000000,180.0000000); //stolice4
    CreateDynamicObject(1723,1265.7113030,1240.9816890,9.8859330,0.0000000,0.0000000,89.4000090); //stolice 7
    CreateDynamicObject(2024,1281.9993890,1236.3112790,9.8859380,0.0000000,0.0000000,90.0000000); //teststol
    CreateDynamicObject(2024,1268.0028070,1241.5100090,9.8859380,0.0000000,0.0000000,90.0000000); //stol4
    CreateDynamicObject(2024,1282.1993400,1241.5100090,9.8859380,0.0000000,0.0000000,90.0000000); //stol2
    CreateDynamicObject(2024,1268.4027090,1236.5112300,9.8859380,0.0000000,0.0000000,138.0000000); //stol5
    CreateDynamicObject(2024,1282.1993400,1246.7087400,9.8859380,0.0000000,0.0000000,90.0000000); //stol3
    CreateDynamicObject(2024,1272.2017820,1236.9111320,9.8859380,0.0000000,0.0000000,180.0000000); //stol6
    CreateDynamicObject(2024,1278.2003170,1236.9111320,9.8859380,0.0000000,0.0000000,180.0000000); //stol7
    
    // BAZA ZA AIRLINE ID:1
    CreateDynamicObject(10815, -3021.33, 466.64, 3.73,   0.00, 0.00, 44.88);
	CreateDynamicObject(10815, -3021.33, 466.64, 3.73,   0.00, 0.00, 44.88);
	CreateDynamicObject(8947, -3147.96, 444.30, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3148.14, 459.00, 0.37,   0.00, 0.00, 270.84);
	CreateDynamicObject(8947, -3148.32, 473.60, 0.37,   0.00, 0.00, 270.84);
	CreateDynamicObject(8947, -3148.55, 488.03, 0.37,   0.00, 0.00, 270.84);
	CreateDynamicObject(10838, -3137.75, 466.97, 20.12,   0.00, 0.00, 0.90);
	CreateDynamicObject(10757, -3136.67, 467.38, 21.99,   13.02, -6.54, 83.76);
	CreateDynamicObject(7983, -3237.33, 490.67, 26.16,   0.00, 0.00, 236.10);
	CreateDynamicObject(3920, -3134.40, 480.56, 13.52,   0.00, 0.00, -89.58);
	CreateDynamicObject(3920, -3134.35, 467.93, 13.52,   0.00, 0.00, -89.58);
	CreateDynamicObject(3920, -3134.35, 455.58, 13.52,   0.00, 0.00, -89.58);
	CreateDynamicObject(5191, -3146.68, 560.21, -2.56,   0.00, 0.00, 0.00);
	CreateDynamicObject(10757, -3255.19, 525.77, 50.80,   14.10, 10.62, 20.58);
	CreateDynamicObject(8947, -3170.57, 497.74, 0.32,   0.00, 0.00, 299.58);
	CreateDynamicObject(8947, -3177.80, 510.50, 0.32,   0.00, 0.00, 299.58);
	CreateDynamicObject(8947, -3184.32, 518.37, 0.32,   0.00, 0.00, 319.38);
	CreateDynamicObject(8947, -3195.49, 527.92, 0.33,   0.00, 0.00, 319.38);
	CreateDynamicObject(8947, -3191.71, 554.81, 0.33,   0.00, 0.00, 327.42);
	CreateDynamicObject(8947, -3190.24, 557.07, 0.33,   0.00, 0.00, 327.42);
	CreateDynamicObject(8947, -3191.51, 565.85, 0.33,   0.00, 0.00, 409.74);
	CreateDynamicObject(8947, -3206.69, 578.72, 0.33,   0.00, 0.00, 409.74);
	CreateDynamicObject(8947, -3223.16, 584.28, 0.33,   0.00, 0.00, 453.48);
	CreateDynamicObject(8947, -3246.40, 582.86, 0.33,   0.00, 0.00, 453.48);
	CreateDynamicObject(8947, -3266.82, 577.48, 0.33,   0.00, 0.00, 476.16);
	CreateDynamicObject(8947, -3288.34, 566.90, 0.33,   0.00, 0.00, 476.16);
	CreateDynamicObject(8947, -3299.15, 554.76, 0.33,   0.00, 0.00, 511.14);
	CreateDynamicObject(8947, -3144.87, 505.98, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.47, 530.30, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3145.47, 554.58, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3145.22, 578.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3145.55, 602.19, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3145.74, 606.86, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8843, -3146.45, 503.96, 3.27,   0.00, 0.00, 0.66);
	CreateDynamicObject(8843, -3146.34, 528.61, 3.27,   0.00, 0.00, 0.00);
	CreateDynamicObject(8843, -3146.21, 552.64, 3.27,   0.00, 0.00, -0.30);
	CreateDynamicObject(8843, -3146.31, 578.74, 3.27,   0.00, 0.00, 1.08);
	CreateDynamicObject(8843, -3146.68, 604.08, 3.27,   0.00, 0.00, 1.08);
	CreateDynamicObject(8947, -3142.17, 631.09, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3156.77, 630.94, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3171.34, 630.84, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3186.04, 630.79, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3200.76, 630.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3217.55, 581.57, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3217.76, 605.95, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3215.46, 630.49, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3229.72, 581.94, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3229.93, 606.29, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3230.13, 630.41, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8210, -3183.12, 619.86, 6.00,   0.00, 0.00, 0.00);
	CreateDynamicObject(8210, -3211.00, 592.34, 6.00,   0.00, 0.00, 90.54);
	CreateDynamicObject(8947, -3244.27, 581.44, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3244.46, 605.74, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3244.60, 630.30, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3258.69, 581.51, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3259.06, 605.96, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3259.33, 630.30, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3142.35, 655.27, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3142.55, 678.00, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3157.00, 653.60, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3157.28, 677.76, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3171.70, 653.65, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3172.02, 677.71, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3186.45, 654.17, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3186.71, 677.57, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3201.09, 654.21, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3201.34, 677.42, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3215.83, 653.52, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3216.06, 677.15, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3230.51, 653.50, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3230.64, 676.95, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(4990, -3358.94, 606.63, 8.33,   0.00, 0.00, 183.90);
	CreateDynamicObject(8947, -3273.37, 582.03, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3273.66, 606.15, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3273.92, 630.22, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.07, 582.17, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.35, 606.65, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.57, 630.08, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3302.05, 580.83, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3301.87, 556.53, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3316.47, 556.25, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3316.63, 580.64, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.08, 556.15, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.31, 580.48, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3345.43, 555.86, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3359.93, 555.74, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3374.46, 555.62, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3245.13, 653.34, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3245.28, 676.91, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3259.67, 653.74, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3259.87, 676.78, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3274.02, 652.04, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.73, 651.89, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3274.61, 676.55, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3289.05, 676.39, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3303.43, 676.31, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3303.37, 651.73, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3303.16, 627.31, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3302.95, 603.23, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3316.79, 604.90, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.68, 627.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.71, 627.16, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.43, 604.47, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.62, 651.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.79, 676.09, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.81, 650.94, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.82, 675.32, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.01, 580.29, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.14, 604.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.25, 628.92, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.43, 653.35, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.77, 676.01, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.35, 675.97, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3360.65, 580.17, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8356, -3273.51, 708.58, 3.26,   0.00, 0.00, -89.40);
	CreateDynamicObject(8947, -3172.16, 702.18, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3172.68, 726.55, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3192.15, 736.73, 0.21,   0.00, 0.00, 270.18);
	CreateDynamicObject(8947, -3172.18, 726.50, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3216.41, 736.54, 0.21,   0.00, 0.00, 270.66);
	CreateDynamicObject(8947, -3240.34, 736.29, 0.21,   0.00, 0.00, 270.66);
	CreateDynamicObject(8947, -3264.85, 736.04, 0.21,   0.00, 0.00, 270.66);
	CreateDynamicObject(8947, -3289.40, 735.68, 0.21,   0.00, 0.00, 270.66);
	CreateDynamicObject(8947, -3313.93, 735.44, 0.21,   0.00, 0.00, 270.66);
	CreateDynamicObject(8947, -3338.21, 735.27, 0.21,   0.00, 0.00, 270.66);
	CreateDynamicObject(8947, -3362.72, 734.77, 0.21,   0.00, 0.00, 270.96);
	CreateDynamicObject(8354, -3435.59, 705.70, 3.27,   0.00, 0.00, 91.50);
	CreateDynamicObject(8947, -3361.06, 675.64, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3387.23, 734.24, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3411.68, 733.58, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3436.07, 733.02, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3491.11, 729.27, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3515.35, 728.85, 0.21,   0.00, 0.00, 450.84);
	CreateDynamicObject(8947, -3512.83, 676.49, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3488.42, 677.03, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8356, -3601.25, 701.61, 3.29,   0.00, 0.00, 91.36);
	CreateDynamicObject(8947, -3537.29, 676.28, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3561.73, 675.98, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3585.76, 675.68, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3610.18, 675.42, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3634.14, 675.13, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3658.23, 674.88, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3682.64, 674.59, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3701.09, 679.53, 0.21,   0.00, 0.00, 539.16);
	CreateDynamicObject(8947, -3700.76, 703.92, 0.21,   0.00, 0.00, 718.56);
	CreateDynamicObject(8947, -3700.30, 722.05, 0.21,   0.00, 0.00, 718.56);
	CreateDynamicObject(8947, -3680.78, 726.78, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3656.48, 727.00, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3632.47, 727.24, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3608.47, 727.50, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3585.95, 727.76, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3562.44, 728.20, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8947, -3538.15, 728.54, 0.21,   0.00, 0.00, 450.60);
	CreateDynamicObject(8354, -3485.21, 841.15, 3.35,   0.00, 0.00, 271.68);
	CreateDynamicObject(8343, -3592.87, 861.45, 3.34,   0.00, 0.00, 92.64);
	CreateDynamicObject(8344, -3577.43, 902.06, 3.34,   0.00, 0.00, -89.64);
	CreateDynamicObject(8171, -3444.04, 928.00, 3.35,   0.00, 0.00, 91.20);
	CreateDynamicObject(8171, -3306.45, 931.08, 3.35,   0.00, 0.00, 91.20);
	CreateDynamicObject(8343, -3188.89, 909.70, 3.33,   0.00, 0.00, -88.38);
	CreateDynamicObject(8344, -3204.91, 868.99, 3.32,   0.00, 0.00, 90.54);
	CreateDynamicObject(8171, -3342.26, 843.79, 3.29,   0.00, 0.00, 90.42);
	CreateDynamicObject(8171, -3338.50, 843.68, 3.29,   0.00, 0.00, 90.42);
	CreateDynamicObject(8947, -3157.48, 702.08, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3142.75, 702.10, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3157.62, 726.46, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3142.94, 726.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3143.12, 750.90, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3157.81, 750.91, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3143.30, 775.32, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3143.49, 799.48, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3143.69, 824.45, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3143.86, 848.84, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3173.04, 750.73, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3157.99, 775.26, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3158.58, 799.79, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3173.09, 775.22, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3187.53, 750.93, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3158.65, 824.19, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3173.22, 799.69, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3173.14, 824.07, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3159.09, 848.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3173.49, 848.57, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.03, 873.40, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.18, 897.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3187.48, 775.34, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3187.52, 799.87, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3187.77, 824.35, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3187.78, 876.12, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3188.13, 900.69, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3145.06, 921.95, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3159.73, 921.86, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.34, 921.79, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3159.74, 921.99, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3144.51, 945.76, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3159.87, 945.80, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3149.41, 965.09, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3174.33, 945.66, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3188.76, 945.56, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3174.70, 965.11, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3199.20, 965.29, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3203.44, 945.70, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3218.01, 946.99, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8947, -3223.69, 965.55, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3223.76, 951.16, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3248.20, 965.55, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3248.13, 951.03, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3202.63, 901.51, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3202.40, 876.97, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3217.12, 876.78, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3217.21, 901.32, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3202.09, 755.83, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3202.06, 780.45, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3202.28, 804.61, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3202.47, 828.40, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3216.75, 756.00, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3216.83, 780.53, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3216.98, 804.78, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3217.06, 829.09, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3231.45, 755.85, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3246.05, 755.76, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3260.61, 755.50, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3275.18, 755.56, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3289.49, 755.40, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3303.29, 755.12, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.65, 755.01, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.98, 754.69, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.32, 754.50, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3361.01, 754.44, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.59, 754.17, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.10, 753.85, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.54, 753.42, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3418.88, 753.07, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.47, 752.68, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.69, 777.23, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3419.06, 777.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.37, 777.90, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.61, 801.71, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.19, 801.50, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.34, 818.04, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.85, 825.93, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3419.21, 826.47, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.60, 826.59, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3418.90, 801.96, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.19, 802.05, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.17, 778.25, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.52, 802.69, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.69, 827.19, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.74, 778.54, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.98, 802.78, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3376.12, 827.26, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3361.60, 827.78, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3361.13, 778.77, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3361.35, 803.35, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.74, 813.03, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.54, 788.66, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3346.48, 772.96, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3331.80, 773.71, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3332.01, 797.81, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3332.43, 821.47, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.17, 779.24, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.65, 803.65, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3317.80, 828.09, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3303.21, 828.05, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3302.74, 779.60, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3302.99, 803.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.15, 779.98, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.27, 803.90, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3288.52, 828.30, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3273.89, 827.91, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3273.78, 803.86, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3273.54, 779.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3258.89, 780.10, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3259.49, 804.33, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3259.70, 819.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3244.39, 780.18, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3244.39, 780.18, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3230.86, 780.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3244.80, 804.35, 0.21,   0.00, 0.00, 180.54);
	CreateDynamicObject(8947, -3230.27, 804.60, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3235.61, 818.91, 0.21,   0.00, 0.00, 271.44);
	CreateDynamicObject(8947, -3248.60, 820.67, 0.21,   0.00, 0.00, 271.44);
	CreateDynamicObject(8947, -3491.11, 743.95, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3491.23, 758.30, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3491.43, 773.04, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3491.77, 787.61, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3492.15, 801.93, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3492.55, 816.34, 0.21,   0.00, 0.00, 271.32);
	CreateDynamicObject(8947, -3231.78, 901.16, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3231.66, 876.59, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3246.32, 876.20, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3246.46, 900.72, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3260.73, 876.26, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3260.94, 900.84, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3275.26, 876.27, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3275.35, 900.65, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(5032, -3565.16, 701.63, 4.27,   0.00, 0.00, 0.00);
	CreateDynamicObject(8947, -3289.73, 876.15, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3289.79, 900.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3304.50, 900.42, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3304.43, 875.94, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3318.97, 876.02, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3319.05, 900.51, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3333.65, 875.78, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3333.71, 900.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(5032, -3264.90, 842.34, 4.41,   0.00, 0.00, 0.00);
	CreateDynamicObject(5044, -3331.93, 931.33, 4.40,   0.00, 0.00, 0.00);
	CreateDynamicObject(5044, -3321.57, 708.12, 4.40,   0.00, 0.00, 0.00);
	CreateDynamicObject(8947, -3347.50, 875.65, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3347.62, 899.41, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3361.76, 899.33, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3361.31, 875.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.93, 875.57, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3376.12, 899.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.64, 898.64, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.49, 874.66, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(5032, -3499.67, 839.85, 4.41,   0.00, 0.00, 0.00);
	CreateDynamicObject(8947, -3404.94, 874.61, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3405.17, 898.69, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3419.75, 898.84, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3419.58, 874.55, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3434.33, 897.19, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3434.21, 872.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.60, 872.77, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.86, 897.00, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.61, 873.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.78, 897.80, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3477.27, 873.19, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3477.51, 897.22, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3492.19, 897.07, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3491.95, 872.61, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3506.31, 871.68, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3506.39, 896.13, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3520.53, 871.58, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3520.68, 896.05, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3535.06, 871.58, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3535.23, 896.03, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3549.51, 871.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3549.78, 895.27, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3563.91, 870.08, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3564.07, 894.59, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3578.49, 870.38, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3578.64, 894.65, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3592.93, 894.72, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3592.74, 870.62, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3599.42, 881.40, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3633.43, 908.90, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3267.22, 960.70, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3281.71, 960.54, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3296.38, 960.56, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3311.02, 960.54, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3325.57, 960.36, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3340.19, 960.34, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3354.84, 960.07, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3369.48, 959.92, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3383.50, 959.71, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3397.86, 959.65, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3412.08, 959.57, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3426.59, 959.45, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3440.84, 959.27, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3455.26, 959.18, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3469.64, 958.96, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3484.09, 958.81, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3498.27, 958.41, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3512.44, 958.35, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3526.83, 957.66, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3540.82, 957.36, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3555.54, 957.14, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3570.09, 957.17, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3584.09, 956.96, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3598.50, 956.93, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3612.53, 956.71, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3627.16, 956.55, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3641.76, 956.40, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3656.17, 956.11, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3597.44, 934.07, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3612.37, 932.41, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3627.02, 932.95, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3641.73, 932.55, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3656.00, 932.49, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3648.08, 908.13, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3655.84, 908.05, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3655.64, 883.90, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3641.34, 884.01, 0.21,   0.00, 0.00, 720.48);
	CreateDynamicObject(8947, -3641.11, 859.55, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3655.43, 859.45, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3628.04, 859.66, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3655.25, 835.29, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3655.29, 811.04, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3641.03, 835.46, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3626.34, 835.60, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3640.84, 811.16, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3626.21, 811.26, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3611.68, 811.42, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3611.89, 835.99, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3374.96, 580.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3389.46, 580.18, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.22, 580.06, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3418.87, 580.25, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.48, 580.37, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.03, 580.27, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.62, 580.14, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3477.04, 579.36, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3491.70, 579.17, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3491.58, 554.62, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3506.02, 554.79, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3506.18, 579.30, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3505.81, 530.44, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3505.66, 505.97, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3491.30, 530.30, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3490.97, 506.06, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3476.34, 506.16, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3461.71, 506.21, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(10815, -3017.59, 466.79, 4.14,   0.00, 0.00, 44.88);
	CreateDynamicObject(8947, -3447.03, 506.25, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3432.36, 506.37, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3417.77, 506.49, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3597.10, 811.58, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3582.57, 811.70, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3568.10, 811.78, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3553.49, 811.85, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3539.09, 812.02, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3524.71, 812.20, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3510.88, 812.51, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3511.06, 788.56, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3510.84, 764.83, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(8947, -3510.57, 741.26, 0.21,   0.00, 0.00, 900.42);
	CreateDynamicObject(19425, -3149.93, 618.86, 3.26,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3147.39, 618.86, 3.26,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3144.79, 618.85, 3.26,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3143.21, 618.85, 3.26,   0.00, 0.00, 0.00);
	CreateDynamicObject(19479, -3187.95, 404.10, 16.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(8947, -3477.41, 530.08, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3463.07, 530.37, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3477.13, 553.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3477.10, 558.38, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3463.22, 554.58, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3463.29, 557.17, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.70, 556.01, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.48, 531.57, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.52, 526.13, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3434.07, 556.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.97, 532.13, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.92, 530.37, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3414.51, 526.03, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3414.51, 540.48, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3414.54, 555.02, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3414.75, 564.16, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3392.41, 561.51, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3392.70, 550.54, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(4890, -3396.85, 522.45, 2.47,   0.00, 0.00, 181.26);
	CreateDynamicObject(8947, -3147.72, 429.82, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3171.59, 433.13, 0.14,   0.00, 0.00, 329.46);
	CreateDynamicObject(8947, -3173.22, 429.59, 0.14,   0.00, 0.00, 329.46);
	CreateDynamicObject(8947, -3187.26, 413.17, 0.14,   0.00, 0.00, 309.60);
	CreateDynamicObject(8947, -3190.39, 410.56, 0.14,   0.00, 0.00, 309.60);
	CreateDynamicObject(8947, -3209.10, 399.99, 0.14,   0.00, 0.00, 289.50);
	CreateDynamicObject(8947, -3212.47, 398.75, 0.14,   0.00, 0.00, 289.50);
	CreateDynamicObject(8947, -3233.95, 395.23, 0.14,   0.00, 0.00, 269.82);
	CreateDynamicObject(8947, -3237.81, 395.30, 0.14,   0.00, 0.00, 269.82);
	CreateDynamicObject(8947, -3258.89, 399.18, 0.14,   0.00, 0.00, 249.00);
	CreateDynamicObject(8947, -3261.91, 400.42, 0.14,   0.00, 0.00, 248.76);
	CreateDynamicObject(8947, -3280.72, 411.33, 0.14,   0.00, 0.00, 229.86);
	CreateDynamicObject(8947, -3283.62, 413.77, 0.14,   0.00, 0.00, 229.86);
	CreateDynamicObject(8947, -3297.08, 430.39, 0.14,   0.00, 0.00, 208.50);
	CreateDynamicObject(8947, -3298.86, 433.67, 0.14,   0.00, 0.00, 208.50);
	CreateDynamicObject(19377, -3184.60, 480.95, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3183.07, 471.47, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3181.62, 461.98, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3180.03, 452.48, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3178.56, 442.99, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3177.07, 433.55, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3188.36, 439.30, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3186.82, 429.83, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3196.95, 428.15, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3195.36, 418.63, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3198.54, 437.61, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3200.07, 447.12, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3201.57, 456.58, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3203.12, 465.97, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3189.47, 448.49, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3190.09, 448.65, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3191.33, 457.96, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3193.04, 467.26, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3194.07, 476.54, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3204.32, 475.15, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3205.51, 417.07, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3207.03, 426.41, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3215.62, 415.38, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3214.60, 409.10, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3182.90, 490.66, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3193.31, 489.17, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3184.31, 500.07, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3194.53, 482.71, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3185.69, 509.42, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3193.97, 498.37, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3195.32, 506.10, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3200.41, 514.63, 2.73,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3205.61, 505.38, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3213.37, 504.65, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3211.49, 490.57, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3203.47, 498.35, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3212.56, 495.97, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3200.94, 490.06, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3201.58, 484.29, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3208.09, 482.71, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3211.01, 481.87, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3215.46, 476.48, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3209.47, 472.81, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3215.07, 469.13, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3208.92, 463.79, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3214.26, 462.92, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3211.23, 453.69, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3209.73, 444.26, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3208.20, 434.82, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3220.41, 453.95, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3229.95, 448.46, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3239.81, 446.29, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19123, -2904.16, 455.80, 4.20,   0.00, 0.00, 0.00);
	CreateDynamicObject(19123, -2904.11, 477.35, 4.20,   0.00, 0.00, 0.00);
	CreateDynamicObject(19123, -2899.02, 477.18, 4.20,   0.00, 0.00, 0.00);
	CreateDynamicObject(19123, -2899.27, 455.83, 4.20,   0.00, 0.00, 0.00);
	CreateDynamicObject(19377, -3219.20, 445.75, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3218.31, 437.34, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3217.30, 429.35, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3217.32, 424.24, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3221.73, 479.29, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3218.47, 484.01, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3228.21, 482.40, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3237.52, 480.98, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3259.37, 450.33, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3208.12, 514.06, 2.73,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3216.48, 512.60, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3211.18, 521.00, 2.74,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3221.00, 517.66, 2.75,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3228.72, 517.90, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3225.86, 508.77, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3223.25, 502.12, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3232.84, 500.66, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3222.31, 492.73, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3231.55, 491.46, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3239.15, 489.81, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3241.69, 498.19, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3243.44, 506.47, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3234.57, 509.28, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3236.69, 520.71, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3238.70, 514.12, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3227.90, 440.13, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3227.44, 430.59, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3226.06, 421.48, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3224.60, 412.38, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3224.54, 410.85, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3232.87, 409.56, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3234.40, 418.98, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3235.77, 427.36, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3237.26, 436.71, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3237.69, 439.54, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3243.38, 454.95, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3247.18, 445.27, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3239.83, 410.46, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3244.83, 419.33, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3248.40, 409.61, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3254.14, 412.97, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3261.86, 416.66, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3253.35, 421.30, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3263.98, 424.01, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3271.61, 424.22, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3260.72, 429.48, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3252.75, 429.67, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3253.01, 435.42, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3245.72, 436.01, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3244.51, 427.67, 2.78,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3254.57, 444.19, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3260.19, 438.70, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3269.61, 437.09, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3271.73, 431.48, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3276.14, 430.98, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3276.28, 436.10, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3252.45, 453.57, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3254.15, 462.32, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3255.54, 470.99, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3246.65, 475.08, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3247.72, 482.36, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3249.18, 489.66, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3250.54, 498.49, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3251.56, 506.21, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3253.61, 514.73, 2.72,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3244.41, 517.41, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3253.84, 515.44, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3248.03, 508.12, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3262.18, 513.02, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3268.85, 506.70, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3276.00, 500.15, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3282.35, 491.40, 2.74,   0.12, -89.94, 9.24);
	CreateDynamicObject(19377, -3259.15, 504.26, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3258.40, 497.25, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3265.76, 497.61, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3272.39, 491.43, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3280.66, 482.27, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3288.40, 483.19, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3256.62, 479.25, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3258.21, 487.99, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3262.53, 488.43, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3270.70, 483.56, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3263.44, 483.00, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3265.12, 476.24, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3274.25, 474.86, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3282.53, 472.51, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3289.65, 473.90, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3288.16, 464.96, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3279.53, 464.61, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3264.58, 463.36, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3264.63, 466.97, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3271.49, 465.92, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3263.20, 456.53, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3265.22, 446.92, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3274.25, 445.54, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3273.43, 456.67, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3272.66, 452.94, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3282.70, 450.67, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3282.07, 443.83, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3280.57, 439.78, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3283.80, 457.56, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3288.27, 457.25, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(19377, -3287.92, 450.20, 2.77,   0.12, -89.76, 9.24);
	CreateDynamicObject(3920, -3139.62, 477.87, 13.52,   0.00, 0.00, 89.58);
	CreateDynamicObject(3920, -3139.64, 465.19, 13.52,   0.00, 0.00, 89.58);
	CreateDynamicObject(3920, -3139.58, 455.69, 13.52,   0.00, 0.00, 90.42);
	CreateDynamicObject(18663, -3156.53, 513.31, 10.57,   0.00, 0.00, -89.94);
	CreateDynamicObject(3851, -3165.73, 434.00, 9.25,   0.00, 0.00, -30.66);
	CreateDynamicObject(3851, -3165.73, 434.00, 5.33,   0.00, 0.00, -30.66);
	CreateDynamicObject(3851, -3171.43, 424.34, 5.33,   0.00, 0.00, -30.66);
	CreateDynamicObject(3851, -3171.43, 424.34, 9.27,   0.00, 0.00, -30.66);
	CreateDynamicObject(3851, -3172.84, 422.05, 5.33,   0.00, 0.00, -30.66);
	CreateDynamicObject(3851, -3172.84, 422.05, 9.26,   0.00, 0.00, -30.66);
	CreateDynamicObject(3851, -3180.04, 413.60, 5.32,   0.00, 0.00, -50.40);
	CreateDynamicObject(3851, -3180.04, 413.60, 9.25,   0.00, 0.00, -50.40);
	CreateDynamicObject(3851, -3188.73, 406.41, 5.32,   0.00, 0.00, -50.40);
	CreateDynamicObject(3851, -3188.73, 406.41, 9.24,   0.00, 0.00, -50.40);
	CreateDynamicObject(3851, -3191.99, 403.71, 5.32,   0.00, 0.00, -50.40);
	CreateDynamicObject(3851, -3191.99, 403.71, 9.15,   0.00, 0.00, -50.40);
	CreateDynamicObject(3851, -3202.31, 397.85, 5.28,   0.00, 0.00, -70.50);
	CreateDynamicObject(3851, -3202.31, 397.85, 8.98,   0.00, 0.00, -70.56);
	CreateDynamicObject(3851, -3212.96, 394.08, 8.98,   0.00, 0.00, -70.56);
	CreateDynamicObject(3851, -3212.96, 394.08, 5.28,   0.00, 0.00, -70.56);
	CreateDynamicObject(3851, -3216.92, 392.73, 5.28,   0.00, 0.00, -70.56);
	CreateDynamicObject(3851, -3216.88, 392.75, 9.16,   0.00, 0.00, -70.74);
	CreateDynamicObject(3851, -3227.89, 390.95, 8.86,   0.00, 0.00, -90.48);
	CreateDynamicObject(3851, -3227.89, 390.95, 5.01,   0.00, 0.00, -90.48);
	CreateDynamicObject(3851, -3239.17, 391.02, 5.01,   0.00, 0.00, -90.48);
	CreateDynamicObject(3851, -3244.83, 391.06, 5.01,   0.00, 0.00, -90.48);
	CreateDynamicObject(3851, -3250.43, 391.12, 8.92,   0.00, 0.00, -90.48);
	CreateDynamicObject(3851, -3239.16, 391.05, 8.90,   0.00, 0.00, -90.48);
	CreateDynamicObject(6965, -3233.28, 466.44, 6.87,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3223.42, 475.39, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3241.17, 455.47, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3242.56, 474.88, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3223.47, 457.34, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3219.92, 466.51, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3246.26, 466.00, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3233.33, 479.22, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(9833, -3232.23, 452.78, 5.86,   0.00, 0.00, 0.00);
	CreateDynamicObject(3851, -3255.42, 393.35, 5.33,   0.00, 0.00, -110.46);
	CreateDynamicObject(3851, -3255.42, 393.35, 9.15,   0.00, 0.00, -110.46);
	CreateDynamicObject(3851, -3265.99, 397.26, 5.33,   0.00, 0.00, -110.46);
	CreateDynamicObject(3851, -3265.99, 397.26, 9.17,   0.00, 0.00, -110.46);
	CreateDynamicObject(3851, -3269.95, 398.70, 5.33,   0.00, 0.00, -110.46);
	CreateDynamicObject(3851, -3269.95, 398.70, 9.24,   0.00, 0.00, -110.46);
	CreateDynamicObject(3851, -3279.67, 404.98, 5.33,   0.00, 0.00, -130.50);
	CreateDynamicObject(3851, -3279.67, 404.98, 9.24,   0.00, 0.00, -130.50);
	CreateDynamicObject(3851, -3288.26, 412.25, 5.33,   0.00, 0.00, -130.50);
	CreateDynamicObject(3851, -3288.22, 412.26, 9.27,   0.00, 0.00, -130.50);
	CreateDynamicObject(3851, -3291.34, 414.89, 5.33,   0.00, 0.00, -130.50);
	CreateDynamicObject(3851, -3291.37, 414.93, 9.24,   0.00, 0.00, -130.50);
	CreateDynamicObject(3851, -3298.60, 424.16, 5.38,   0.00, 0.00, -150.48);
	CreateDynamicObject(3851, -3298.60, 424.16, 9.24,   0.00, 0.00, -150.48);
	CreateDynamicObject(3851, -3304.14, 433.93, 5.38,   0.00, 0.00, -150.48);
	CreateDynamicObject(3851, -3304.12, 433.91, 9.26,   0.00, 0.00, -150.48);
	CreateDynamicObject(3851, -3306.24, 437.60, 5.38,   0.00, 0.00, -150.48);
	CreateDynamicObject(3851, -3306.19, 437.59, 8.93,   0.00, 0.00, -150.48);
	CreateDynamicObject(1597, -3227.65, 466.48, 5.28,   0.00, 0.00, 0.00);
	CreateDynamicObject(1597, -3229.59, 465.58, 5.28,   0.00, 0.00, -29.82);
	CreateDynamicObject(1597, -3228.50, 468.30, 5.28,   0.00, 0.00, 18.36);
	CreateDynamicObject(1597, -3229.23, 469.77, 5.28,   0.00, 0.00, -148.14);
	CreateDynamicObject(3851, -3309.81, 448.50, 5.32,   0.00, 0.00, -169.38);
	CreateDynamicObject(3851, -3309.81, 448.50, 9.07,   0.00, 0.00, -169.38);
	CreateDynamicObject(3851, -3314.10, 470.35, 5.32,   0.00, 0.00, -169.38);
	CreateDynamicObject(3851, -3314.10, 470.36, 9.10,   0.00, 0.00, -169.38);
	CreateDynamicObject(3851, -3164.90, 500.34, 5.33,   0.00, 0.00, 29.70);
	CreateDynamicObject(8947, -3163.43, 485.05, 0.32,   0.00, 0.00, 299.58);
	CreateDynamicObject(3851, -3164.90, 500.34, 9.23,   0.00, 0.00, 29.70);
	CreateDynamicObject(3851, -3170.47, 510.13, 5.33,   0.00, 0.00, 29.70);
	CreateDynamicObject(3851, -3170.50, 510.14, 9.29,   0.00, 0.00, 29.94);
	CreateDynamicObject(3851, -3171.88, 512.60, 5.33,   0.00, 0.00, 29.70);
	CreateDynamicObject(3851, -3171.97, 512.52, 9.24,   0.00, 0.00, 29.70);
	CreateDynamicObject(3851, -3178.97, 521.11, 5.32,   0.00, 0.00, 49.50);
	CreateDynamicObject(3851, -3178.97, 521.11, 9.22,   0.00, 0.00, 49.50);
	CreateDynamicObject(3851, -3187.52, 528.43, 5.32,   0.00, 0.00, 49.50);
	CreateDynamicObject(3851, -3187.52, 528.43, 9.28,   0.00, 0.00, 49.50);
	CreateDynamicObject(3851, -3196.11, 535.79, 5.32,   0.00, 0.00, 49.50);
	CreateDynamicObject(3851, -3196.11, 535.79, 9.24,   0.00, 0.00, 49.50);
	CreateDynamicObject(1597, -3230.33, 460.03, 5.28,   0.00, 0.00, -62.52);
	CreateDynamicObject(1597, -3230.72, 463.12, 5.28,   0.00, 0.00, -107.46);
	CreateDynamicObject(1597, -3237.02, 462.65, 5.28,   0.00, 0.00, -26.70);
	CreateDynamicObject(1597, -3233.79, 461.08, 5.28,   0.00, 0.00, 20.10);
	CreateDynamicObject(1597, -3236.03, 461.41, 5.28,   0.00, 0.00, 52.92);
	CreateDynamicObject(1597, -3238.09, 466.35, 5.28,   0.00, 0.00, 30.84);
	CreateDynamicObject(1597, -3236.62, 467.34, 5.28,   0.00, 0.00, -22.62);
	CreateDynamicObject(8947, -3306.03, 454.14, 0.14,   0.00, 0.00, 190.38);
	CreateDynamicObject(8947, -3321.80, 472.82, 0.20,   0.00, 0.00, 442.92);
	CreateDynamicObject(1597, -3235.68, 472.62, 5.28,   0.00, 0.00, 85.08);
	CreateDynamicObject(1597, -3241.03, 465.14, 5.28,   0.00, 0.00, 5.52);
	CreateDynamicObject(1597, -3238.66, 471.01, 5.28,   0.00, 0.00, -26.40);
	CreateDynamicObject(1597, -3233.19, 470.03, 5.28,   0.00, 0.00, -88.02);
	CreateDynamicObject(1597, -3228.45, 469.74, 5.28,   0.00, 0.00, -203.46);
	CreateDynamicObject(1597, -3226.92, 469.16, 5.28,   0.00, 0.00, -147.84);
	CreateDynamicObject(1597, -3233.22, 471.15, 5.28,   0.00, 0.00, -94.08);
	CreateDynamicObject(1597, -3232.61, 473.96, 5.28,   0.00, 0.00, -94.08);
	CreateDynamicObject(1597, -3238.72, 469.80, 5.28,   0.00, 0.00, -21.78);
	CreateDynamicObject(8947, -3147.51, 415.29, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3147.24, 400.58, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3123.56, 430.04, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3123.22, 415.64, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3122.87, 400.98, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3147.04, 386.00, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3122.61, 386.46, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3098.10, 386.76, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3098.52, 401.41, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3099.06, 416.03, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(8947, -3099.10, 430.34, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(19425, -3158.45, 436.84, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3155.18, 436.85, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3151.91, 436.85, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3148.63, 436.86, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3145.33, 436.87, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3142.05, 436.89, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3138.76, 436.88, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(19425, -3137.17, 436.88, 3.42,   0.00, 0.00, 0.00);
	CreateDynamicObject(8656, -3120.34, 436.90, 4.45,   0.00, 0.00, 90.36);
	CreateDynamicObject(8947, -3081.89, 425.59, 0.37,   0.00, 0.00, 360.00);
	CreateDynamicObject(8656, -3089.84, 437.05, 4.45,   0.00, 0.00, 90.36);
	CreateDynamicObject(8656, -3075.21, 422.35, 4.45,   0.00, 0.00, 179.76);
	CreateDynamicObject(8947, -3081.90, 401.69, 0.37,   0.00, 0.00, 360.00);
	CreateDynamicObject(8947, -3081.86, 391.83, 0.37,   0.00, 0.00, 540.42);
	CreateDynamicObject(8656, -3075.35, 395.09, 4.45,   0.00, 0.00, 179.76);
	CreateDynamicObject(8656, -3090.45, 380.10, 4.45,   0.00, 0.00, 90.36);
	CreateDynamicObject(10183, -3115.31, 432.45, 3.43,   0.00, 0.00, 45.90);
	CreateDynamicObject(10183, -3080.04, 400.91, 3.43,   0.00, 0.00, -44.46);
	CreateDynamicObject(10183, -3100.15, 432.52, 3.43,   0.00, 0.00, 45.90);
	CreateDynamicObject(10183, -3102.59, 400.82, 3.43,   0.00, 0.00, -44.46);
	CreateDynamicObject(10183, -3123.83, 400.04, 3.43,   0.00, 0.00, -44.46);
	CreateDynamicObject(10183, -3145.22, 399.97, 3.43,   0.00, 0.00, -44.46);
	CreateDynamicObject(8656, -3120.70, 379.93, 4.45,   0.00, 0.00, 90.36);
	CreateDynamicObject(8656, -3143.89, 379.79, 4.45,   0.00, 0.00, 90.36);
	CreateDynamicObject(8656, -3158.75, 394.93, 4.45,   0.00, 0.00, 180.90);
	CreateDynamicObject(8656, -3159.18, 421.60, 4.45,   0.00, 0.00, 180.90);
	CreateDynamicObject(8406, -3150.80, 436.73, 8.84,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.95, 436.75, 4.01,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3157.90, 380.41, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.04, 393.17, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.34, 407.85, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.50, 422.31, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3141.24, 380.46, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3119.77, 380.64, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3098.60, 380.81, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3076.23, 380.92, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3076.09, 395.91, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3076.00, 411.00, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3075.93, 424.63, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3075.83, 436.49, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3099.19, 436.36, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3120.70, 436.31, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.61, 429.68, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.45, 415.18, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3158.17, 400.46, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3157.84, 386.69, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3149.71, 380.33, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3130.79, 380.64, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3109.90, 380.77, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3087.38, 380.93, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3076.08, 388.33, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3076.00, 403.78, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3075.93, 417.78, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3075.84, 430.50, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3087.34, 436.61, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3110.40, 436.36, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(19122, -3128.58, 436.19, 3.92,   0.00, 0.00, 0.00);
	CreateDynamicObject(3920, -3129.14, 436.58, 4.57,   0.00, 0.00, 180.54);
	CreateDynamicObject(3920, -3116.48, 436.65, 4.57,   0.00, 0.00, 180.54);
	CreateDynamicObject(3920, -3103.82, 436.75, 4.57,   0.00, 0.00, 180.54);
	CreateDynamicObject(3920, -3091.20, 436.79, 4.57,   0.00, 0.00, 180.54);
	CreateDynamicObject(3920, -3082.02, 436.73, 4.57,   0.00, 0.00, 180.54);
	CreateDynamicObject(3920, -3075.56, 430.48, 4.57,   0.00, 0.00, 90.12);
	CreateDynamicObject(3920, -3075.50, 417.91, 4.57,   0.00, 0.00, 90.12);
	CreateDynamicObject(3920, -3075.58, 405.26, 4.57,   0.00, 0.00, 90.12);
	CreateDynamicObject(3920, -3075.64, 392.65, 4.57,   0.00, 0.00, 90.12);
	CreateDynamicObject(3920, -3075.65, 387.02, 4.57,   0.00, 0.00, 90.12);
	CreateDynamicObject(3920, -3081.88, 380.44, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3094.33, 380.35, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3106.92, 380.27, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3119.42, 380.22, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3131.96, 380.10, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3144.60, 380.07, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3152.23, 379.98, 4.57,   0.00, 0.00, 0.48);
	CreateDynamicObject(3920, -3158.35, 386.56, 4.57,   0.00, 0.00, -88.62);
	CreateDynamicObject(3920, -3158.52, 398.72, 4.57,   0.00, 0.00, -89.10);
	CreateDynamicObject(3920, -3158.75, 411.08, 4.57,   0.00, 0.00, -89.10);
	CreateDynamicObject(3920, -3158.96, 423.47, 4.57,   0.00, 0.00, -89.10);
	CreateDynamicObject(3920, -3159.00, 430.27, 4.57,   0.00, 0.00, -89.10);
	CreateDynamicObject(19377, -3136.32, 483.03, 0.43,   0.00, 0.00, 0.96);
	CreateDynamicObject(19377, -3136.45, 492.27, 0.43,   0.00, 0.00, 0.96);
	CreateDynamicObject(19377, -3136.58, 497.27, 0.43,   0.00, 0.00, 0.96);
	CreateDynamicObject(8210, -3136.46, 642.98, 6.00,   0.00, 0.00, -89.34);
	CreateDynamicObject(8210, -3137.06, 695.83, 6.00,   0.00, 0.00, -89.34);
	CreateDynamicObject(8210, -3137.67, 748.68, 6.00,   0.00, 0.00, -89.34);
	CreateDynamicObject(8210, -3138.26, 801.66, 6.00,   0.00, 0.00, -89.34);
	CreateDynamicObject(8210, -3138.92, 854.74, 6.00,   0.00, 0.00, -89.34);
	CreateDynamicObject(8210, -3139.55, 909.30, 6.00,   0.00, 0.00, -89.34);
	CreateDynamicObject(8947, -3186.76, 702.10, 0.19,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3160.51, 750.89, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3161.11, 775.26, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.39, 799.47, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.34, 800.57, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3143.50, 800.60, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3144.31, 824.47, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3158.28, 848.66, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3153.33, 965.09, 0.21,   0.00, 0.00, 629.76);
	CreateDynamicObject(8947, -3145.82, 945.77, 0.21,   0.00, 0.00, 360.36);
	CreateDynamicObject(8210, -3139.91, 943.73, 6.00,   0.00, 0.00, -89.58);
	CreateDynamicObject(8210, -3167.91, 971.99, 6.00,   0.00, 0.00, -0.24);
	CreateDynamicObject(8210, -3219.65, 972.24, 6.00,   0.00, 0.00, -0.24);
	CreateDynamicObject(8210, -3272.10, 972.39, 6.00,   0.00, 0.00, -0.24);
	CreateDynamicObject(8210, -3324.42, 972.13, 6.00,   0.00, 0.00, 0.42);
	CreateDynamicObject(8210, -3376.83, 971.73, 6.00,   0.00, 0.00, 0.42);
	CreateDynamicObject(8210, -3428.95, 971.36, 6.00,   0.00, 0.00, 0.42);
	CreateDynamicObject(8210, -3481.20, 970.58, 6.00,   0.00, 0.00, 1.14);
	CreateDynamicObject(8210, -3533.49, 969.60, 6.00,   0.00, 0.00, 1.14);
	CreateDynamicObject(8210, -3586.10, 968.57, 6.00,   0.00, 0.00, 1.14);
	CreateDynamicObject(8210, -3635.29, 967.61, 6.00,   0.00, 0.00, 1.14);
	CreateDynamicObject(8210, -3662.81, 939.15, 6.00,   0.00, 0.00, 90.96);
	CreateDynamicObject(8210, -3662.22, 886.16, 6.00,   0.00, 0.00, 90.42);
	CreateDynamicObject(8210, -3661.85, 833.50, 6.00,   0.00, 0.00, 90.42);
	CreateDynamicObject(8210, -3661.83, 827.56, 6.00,   0.00, 0.00, 90.42);
	CreateDynamicObject(8210, -3633.83, 799.79, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3580.90, 800.31, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3555.90, 800.57, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3517.53, 773.68, 6.00,   0.00, 0.00, 90.36);
	CreateDynamicObject(8210, -3517.44, 761.70, 6.00,   0.00, 0.00, 90.36);
	CreateDynamicObject(8210, -3544.89, 733.58, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3597.85, 733.07, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3649.32, 732.57, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3678.64, 732.36, 6.00,   0.00, 0.00, 180.54);
	CreateDynamicObject(8210, -3706.66, 704.64, 6.00,   0.00, 0.00, 268.80);
	CreateDynamicObject(8210, -3706.95, 695.31, 6.00,   0.00, 0.00, 268.80);
	CreateDynamicObject(8210, -3680.19, 668.53, 6.00,   0.00, 0.00, 361.20);
	CreateDynamicObject(8210, -3627.28, 669.64, 6.00,   0.00, 0.00, 361.20);
	CreateDynamicObject(8210, -3571.73, 670.48, 6.00,   0.00, 0.00, 360.60);
	CreateDynamicObject(8210, -3543.94, 642.80, 6.00,   0.00, 0.00, 269.82);
	CreateDynamicObject(8210, -3544.07, 591.05, 6.00,   0.00, 0.00, 269.82);
	CreateDynamicObject(8210, -3536.64, 536.63, 6.00,   0.00, 0.00, 285.78);
	CreateDynamicObject(8947, -3390.13, 526.34, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3365.73, 526.67, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3341.68, 526.95, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3317.15, 527.25, 0.21,   0.00, 0.00, 270.72);
	CreateDynamicObject(8947, -3320.05, 487.57, 0.35,   0.00, 0.00, 442.92);
	CreateDynamicObject(8947, -3318.25, 502.29, 0.15,   0.00, 0.00, 442.92);
	CreateDynamicObject(8947, -3321.70, 516.47, 0.21,   0.00, 0.00, 442.92);
	CreateDynamicObject(8947, -3403.17, 506.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3388.46, 506.77, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3373.76, 506.93, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3359.00, 507.13, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3344.31, 507.40, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3329.61, 507.53, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3323.08, 457.91, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3331.50, 471.69, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3324.17, 449.95, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3341.29, 456.81, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3337.35, 484.81, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3339.81, 488.25, 0.21,   0.00, 0.00, 92.52);
	CreateDynamicObject(8947, -3340.66, 448.91, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3355.48, 469.52, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3360.41, 482.18, 0.21,   0.00, 0.00, 94.80);
	CreateDynamicObject(8947, -3363.63, 487.62, 0.21,   0.00, 0.00, 91.86);
	CreateDynamicObject(8947, -3363.19, 473.26, 0.21,   0.00, 0.00, 91.86);
	CreateDynamicObject(8947, -3362.66, 459.01, 0.21,   0.00, 0.00, 91.86);
	CreateDynamicObject(8947, -3362.01, 444.40, 0.21,   0.00, 0.00, 91.86);
	CreateDynamicObject(8947, -3337.84, 445.16, 0.21,   0.00, 0.00, 91.86);
	CreateDynamicObject(8947, -3313.57, 445.95, 0.21,   0.00, 0.00, 91.86);
	CreateDynamicObject(8656, -3322.74, 438.68, 4.45,   0.00, 0.00, 92.04);
	CreateDynamicObject(8656, -3353.16, 437.56, 4.45,   0.00, 0.00, 92.04);
	CreateDynamicObject(8656, -3358.42, 437.35, 4.45,   0.00, 0.00, 92.04);
	CreateDynamicObject(8656, -3374.54, 451.54, 4.45,   0.00, 0.00, 181.80);
	CreateDynamicObject(8656, -3375.43, 480.32, 4.45,   0.00, 0.00, 181.80);
	CreateDynamicObject(8210, -3532.02, 519.71, 6.00,   0.00, 0.00, 285.78);
	CreateDynamicObject(8947, -3516.95, 505.86, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3522.92, 507.30, 0.21,   0.00, 0.00, 195.96);
	CreateDynamicObject(8947, -3519.39, 505.83, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3529.66, 530.88, 0.21,   0.00, 0.00, 195.96);
	CreateDynamicObject(8947, -3536.38, 554.20, 0.21,   0.00, 0.00, 195.96);
	CreateDynamicObject(8947, -3539.55, 575.97, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3519.00, 530.02, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3520.52, 554.04, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3520.79, 578.38, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3527.12, 578.28, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3528.35, 554.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.34, 675.52, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3390.06, 675.45, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.76, 675.34, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3419.36, 675.20, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.96, 675.15, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.47, 675.07, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.99, 675.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3477.48, 675.00, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3360.66, 651.15, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3360.41, 626.98, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3360.18, 603.69, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.22, 651.11, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3375.06, 626.71, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3374.93, 604.03, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3389.96, 650.91, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3389.60, 626.67, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3389.35, 606.87, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.56, 651.00, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3404.28, 626.55, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3419.11, 650.73, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3418.95, 626.44, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3418.74, 604.47, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.37, 604.62, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3447.99, 604.50, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.55, 604.22, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.46, 628.92, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3448.06, 628.92, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.73, 628.66, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3433.14, 651.29, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3447.72, 652.74, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3462.18, 652.33, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3476.85, 651.95, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3476.63, 627.63, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3476.36, 621.29, 0.21,   0.00, 0.00, 180.42);
	CreateDynamicObject(8947, -3496.35, 662.44, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3520.79, 662.07, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3532.75, 662.21, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3496.35, 647.84, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3520.69, 647.51, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3532.48, 647.54, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3496.00, 633.19, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3520.47, 632.94, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3532.21, 632.77, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3531.87, 618.03, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3531.61, 603.41, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3531.74, 595.27, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3507.21, 597.71, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3507.54, 612.12, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3507.64, 620.12, 0.21,   0.00, 0.00, 451.08);
	CreateDynamicObject(8947, -3490.36, 617.83, 0.21,   0.00, 0.00, 526.08);
	CreateDynamicObject(8210, -3497.72, 494.85, 6.00,   0.00, 0.00, 360.66);
	CreateDynamicObject(8656, -3510.52, 494.61, 4.45,   0.00, 0.00, 90.72);
	CreateDynamicObject(8656, -3480.06, 494.98, 4.45,   0.00, 0.00, 90.72);
	CreateDynamicObject(8656, -3449.54, 495.34, 4.45,   0.00, 0.00, 90.72);
	CreateDynamicObject(8210, -3442.37, 495.38, 6.00,   0.00, 0.00, 360.66);
	CreateDynamicObject(8210, -3402.37, 495.60, 6.00,   0.00, 0.00, 360.66);
	CreateDynamicObject(8656, -3419.04, 495.59, 4.45,   0.00, 0.00, 90.18);
	CreateDynamicObject(8656, -3390.73, 495.65, 4.45,   0.00, 0.00, 90.18);
	CreateDynamicObject(3881, -3129.03, 450.34, 8.00,   0.00, 0.00, -87.90);
	CreateDynamicObject(3361, -3132.55, 453.55, 4.15,   0.00, 0.00, 181.56);
	CreateDynamicObject(3881, -3129.03, 450.37, 4.45,   0.00, 0.00, -87.60);
	CreateDynamicObject(3881, -3132.68, 451.49, 0.86,   0.00, 0.00, -87.90);
	CreateDynamicObject(3881, -3127.99, 449.93, 4.45,   0.00, 0.00, 92.64);
	CreateDynamicObject(3881, -3131.70, 451.03, 0.89,   0.00, 0.00, 92.64);
	CreateDynamicObject(8947, -3137.01, 454.80, 0.37,   0.00, 0.00, 270.78);
	CreateDynamicObject(3881, -2866.71, 473.97, 5.68,   0.00, 0.00, -272.88);
	CreateDynamicObject(8210, -2945.31, 454.94, 6.00,   0.00, 0.00, 0.00);
	CreateDynamicObject(8210, -2899.21, 477.63, 6.00,   0.00, 0.00, 175.92);
	CreateDynamicObject(8210, -2940.03, 478.55, 6.00,   0.00, 0.00, 179.94);
	CreateDynamicObject(8210, -2898.92, 455.47, 6.00,   0.00, 0.00, 3.84);
	CreateDynamicObject(3749, -2873.00, 466.46, 9.47,   0.00, 0.00, 89.76);
	CreateDynamicObject(2774, -2874.59, 460.16, -2.71,   0.00, 0.00, 0.00);
	CreateDynamicObject(2774, -2874.49, 472.53, -2.71,   0.00, 0.00, 0.00);
	CreateDynamicObject(967, -3160.20, 437.71, 3.41,   0.00, 0.00, 86.28);
	CreateDynamicObject(966, -3158.60, 436.32, 3.41,   0.00, 0.00, 181.50);
	CreateDynamicObject(966, -3144.70, 436.42, 3.41,   0.00, 0.00, 359.64);
	CreateDynamicObject(8656, -3129.28, 436.91, 4.45,   0.00, 0.00, 90.36);
	
	// AIRLINE BAZA ID:2
	CreateDynamicObject(5706,3364.8500000,-2331.4000000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3364.8200000,-2353.6000000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3364.8200000,-2375.1100000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3365.0200000,-2397.7000000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3397.8800000,-2397.8100000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3397.8700000,-2376.1300000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3397.7900000,-2357.0800000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3397.7600000,-2334.4200000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3397.7900000,-2331.3900000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3430.3000000,-2331.2300000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3431.1200000,-2353.6200000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3430.8800000,-2374.6300000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3430.5600000,-2396.3000000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3430.6500000,-2397.5500000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3462.4400000,-2397.7400000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3462.3500000,-2375.6700000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3462.4100000,-2353.5100000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3463.4500000,-2330.8300000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3493.1400000,-2330.8200000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3493.5200000,-2353.6700000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3494.1400000,-2376.5000000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3494.1800000,-2397.5400000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3526.5000000,-2397.6400000,0.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(10816,3396.2900000,-2245.9600000,-59480.9500000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(10816,3521.2500000,-2245.8800000,2.6500000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3610.9700000,-2309.0900000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3578.9900000,-2309.1400000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3547.1100000,-2309.6100000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3515.2900000,-2309.7000000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3515.3000000,-2330.6800000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3516.8200000,-2330.7400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3516.8200000,-2353.1400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3516.7700000,-2375.5300000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3557.4900000,-2397.6900000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3549.5900000,-2376.8500000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3548.6800000,-2355.4000000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3549.8300000,-2330.6800000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3549.5200000,-2341.0700000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3589.5600000,-2397.6100000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3582.3000000,-2375.2600000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3582.4000000,-2353.7400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3579.1200000,-2357.6500000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3582.2100000,-2331.9800000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3613.9100000,-2331.2400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3616.3400000,-2330.9000000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3605.3800000,-2330.8500000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3577.8800000,-2325.7900000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3615.1100000,-2352.0600000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3614.9600000,-2373.8200000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3615.3300000,-2396.6300000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3615.3700000,-2397.6400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3648.7200000,-2330.9500000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3647.7100000,-2353.4200000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3647.6200000,-2375.5600000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3647.9500000,-2397.6100000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3679.0800000,-2330.6500000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3694.2800000,-2330.2400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3698.0000000,-2330.3400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3697.9600000,-2310.6700000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3697.7800000,-2288.1900000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3697.7000000,-2266.8700000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3697.6600000,-2245.5400000,-0.1000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3697.6600000,-2224.0100000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3697.6800000,-2208.5300000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3673.8100000,-2208.4700000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3643.2500000,-2208.4400000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3611.5500000,-2208.4300000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3580.8000000,-2208.3800000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3548.3300000,-2208.3500000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3516.1600000,-2208.3500000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3483.7000000,-2208.3100000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3451.4500000,-2208.2800000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3419.5500000,-2208.2300000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3387.3100000,-2208.2300000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3355.2200000,-2208.2300000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3344.8000000,-2208.1500000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3344.6100000,-2230.7100000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3344.6600000,-2253.1600000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3344.7800000,-2274.9000000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3344.8600000,-2296.3500000,-0.3000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3341.4300000,-2302.5400000,-0.3000000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3360.9000000,-2302.4400000,-0.3000000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3362.4600000,-2333.7800000,-0.2000000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3362.0100000,-2334.2400000,-0.0200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3361.3200000,-2334.1700000,-0.0200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3382.8500000,-2334.2300000,-0.0200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3404.6200000,-2334.2400000,-0.0200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3426.8100000,-2334.2600000,-0.0200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3449.0800000,-2334.1600000,-0.0200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3319.4500000,-2228.9300000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3319.2900000,-2224.3100000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3297.3900000,-2224.4500000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3297.2500000,-2228.8600000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3276.2400000,-2225.1000000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3276.3300000,-2228.7100000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3276.5500000,-2224.7000000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3276.7300000,-2228.8800000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(5706,3276.7300000,-2228.8800000,-0.6200000,0.0000000,0.0000000,90.5500000); //
	CreateDynamicObject(4890,3535.0900000,-2413.4600000,9.5200000,0.0000000,0.0000000,180.3400000); //
	CreateDynamicObject(5006,3522.3200000,-2351.3300000,9.2500000,0.0000000,0.0000000,92.9000000); //
	CreateDynamicObject(5706,3454.1300000,-2383.5900000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(5706,3485.6100000,-2383.5900000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(5706,3517.5800000,-2383.6000000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(5706,3549.2300000,-2383.5900000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(5706,3580.7900000,-2383.5300000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(5706,3612.2500000,-2383.5400000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(5706,3612.5000000,-2382.5100000,8.1700000,0.0000000,0.0000000,179.9200000); //
	CreateDynamicObject(4832,3598.2100000,-2393.3000000,33.1100000,0.0000000,0.0000000,359.5300000); //
	CreateDynamicObject(1682,3557.4600000,-2394.8800000,26.4000000,0.0000000,0.0000000,324.0700000); //
	CreateDynamicObject(1682,3511.6800000,-2393.0500000,26.4000000,0.0000000,0.0000000,324.0700000); //
	CreateDynamicObject(1682,3511.8800000,-2392.8300000,26.4000000,0.0000000,0.0000000,324.0700000); //
	CreateDynamicObject(5706,3364.9600000,-2395.7100000,-0.0600000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3394.9900000,-2395.6500000,-0.0600000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3422.0800000,-2395.7400000,-0.0600000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3442.2700000,-2396.4200000,8.9200000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3442.5600000,-2396.3000000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3442.2000000,-2396.3500000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3454.2900000,-2396.8900000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3442.1600000,-2403.4600000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3473.1000000,-2403.3900000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3498.7100000,-2400.8800000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3532.3200000,-2403.4600000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3563.8000000,-2403.6300000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3594.9500000,-2403.8800000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3625.8300000,-2404.1000000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3627.9500000,-2403.9500000,8.2000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3627.3300000,-2404.3500000,8.6000000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3647.8000000,-2415.3000000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3647.7800000,-2437.6100000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3615.4000000,-2415.7300000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3619.0100000,-2437.5300000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3583.7700000,-2415.8900000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3587.2000000,-2437.5800000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3553.2300000,-2415.9300000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3555.8200000,-2437.4600000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3523.0000000,-2415.9900000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3523.0700000,-2437.4000000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3491.6500000,-2437.4500000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3491.6200000,-2422.0000000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3458.6000000,-2423.1700000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3458.8900000,-2437.5300000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3442.6700000,-2425.2400000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3442.8000000,-2437.5500000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3413.2000000,-2415.7500000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3413.2000000,-2434.2100000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3413.2000000,-2437.4700000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3382.2000000,-2437.4600000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(5706,3382.1700000,-2418.2800000,-0.1400000,0.0000000,0.0000000,179.8600000); //
	CreateDynamicObject(8042,3426.1700000,-2427.0400000,9.4000000,0.0000000,0.0000000,194.6500000); //
	CreateDynamicObject(1412,3425.7700000,-2441.6900000,4.9200000,0.0000000,0.0000000,268.5200000); //
	CreateDynamicObject(1412,3425.6400000,-2446.7900000,5.0500000,0.0000000,0.0000000,89.2300000); //
	CreateDynamicObject(1412,3425.6500000,-2448.0600000,5.0500000,0.0000000,0.0000000,89.2300000); //
	CreateDynamicObject(1412,3425.8500000,-2439.7700000,5.0500000,0.0000000,0.0000000,89.2300000); //
	CreateDynamicObject(1412,3423.2600000,-2416.2300000,5.0500000,0.0000000,0.0000000,1.2400000); //
	CreateDynamicObject(1412,3418.0900000,-2416.3100000,5.0500000,0.0000000,0.0000000,1.2400000); //
	CreateDynamicObject(1412,3412.9500000,-2416.4500000,5.0500000,0.0000000,0.0000000,1.2400000); //
	CreateDynamicObject(1412,3397.4400000,-2416.7000000,5.0500000,0.0000000,0.0000000,1.2400000); //
	CreateDynamicObject(1412,3392.2000000,-2416.8500000,5.0500000,0.0000000,0.0000000,1.2400000); //
	CreateDynamicObject(1412,3387.0000000,-2417.0000000,5.0500000,0.0000000,0.0000000,1.2400000); //
	CreateDynamicObject(8150,3428.4500000,-2450.8600000,6.2500000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(8150,3554.3900000,-2450.7900000,6.2500000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(8150,3601.0200000,-2451.4900000,6.2500000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(8150,3713.7000000,-2279.8400000,6.2500000,0.0000000,0.0000000,90.6600000); //
	CreateDynamicObject(8150,3713.1800000,-2255.8400000,6.2500000,0.0000000,0.0000000,90.6600000); //
	CreateDynamicObject(8150,3649.7800000,-2195.2000000,6.2500000,0.0000000,0.0000000,180.0600000); //
	CreateDynamicObject(8150,3529.5300000,-2195.3000000,6.2500000,0.0000000,0.0000000,180.0600000); //
	CreateDynamicObject(8150,3406.0300000,-2195.1600000,6.2500000,0.0000000,0.0000000,180.0600000); //
	CreateDynamicObject(10764,3288.5600000,-2227.0300000,5.1600000,0.0000000,0.0000000,135.2600000); //
	CreateDynamicObject(3526,3329.9600000,-2242.1300000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3329.9800000,-2211.2100000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3362.0200000,-2242.2800000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3362.1100000,-2211.0400000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3385.0400000,-2242.1300000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3385.0100000,-2211.3500000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3410.9100000,-2242.1200000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3411.4000000,-2211.2100000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3438.0400000,-2211.3600000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3437.7400000,-2242.2500000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3464.0600000,-2242.1000000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3463.0000000,-2211.4400000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3491.7900000,-2211.4900000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3491.9800000,-2242.1300000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3521.4700000,-2241.9700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3520.4000000,-2211.1400000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3546.6700000,-2211.4500000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3547.1100000,-2242.3200000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3572.3100000,-2242.2400000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3571.9000000,-2211.4100000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3595.9700000,-2211.3200000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3595.5400000,-2242.3600000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3626.5400000,-2242.1300000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3626.6600000,-2211.3100000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3652.9400000,-2211.4300000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3653.8900000,-2242.1700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3684.3600000,-2242.4700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3683.3500000,-2211.3500000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.6800000,-2241.5200000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.5800000,-2236.4500000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.6600000,-2231.4200000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.4800000,-2226.7500000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.2600000,-2221.2700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.2500000,-2216.5300000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3710.3300000,-2211.7600000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3668.4800000,-2226.9400000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3622.3800000,-2227.0100000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3590.7200000,-2226.6600000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3547.7500000,-2226.7400000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3496.6500000,-2226.6700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3464.0200000,-2226.6700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3432.7300000,-2226.5700000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3403.0300000,-2226.7900000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3368.6300000,-2226.6600000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3526,3330.6200000,-2226.7900000,3.8700000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5147,2907.2000000,-2223.8800000,19.8500000,0.0000000,0.0000000,123.6800000); //
	CreateDynamicObject(5147,3192.0400000,-2396.9500000,19.8200000,0.0000000,0.0000000,348.6700000); //
	CreateDynamicObject(5120,3026.2000000,-2349.2400000,21.8000000,0.0000000,0.0000000,33.3800000); //
	CreateDynamicObject(17599,2846.9100000,-2152.5400000,10.0900000,0.0000000,0.0000000,56.7600000); //
	CreateDynamicObject(5706,2850.4200000,-2150.0100000,6.1400000,0.0000000,0.0000000,325.3200000); //
	CreateDynamicObject(5706,2869.9600000,-2170.7200000,6.1400000,0.0000000,0.0000000,303.4900000); //
	CreateDynamicObject(5706,2873.5300000,-2171.2400000,6.1400000,0.0000000,0.0000000,124.3100000); //
	CreateDynamicObject(5706,2874.1300000,-2169.9800000,6.1400000,0.0000000,0.0000000,124.3100000); //
	CreateDynamicObject(5112,3324.0100000,-2421.0000000,1.2100000,0.0000000,4.0000000,351.8100000); //
	CreateDynamicObject(8168,3385.9300000,-2421.1300000,5.9600000,0.0000000,0.0000000,10.8500000); //
	CreateDynamicObject(966,3381.1400000,-2431.4200000,4.0000000,0.0000000,0.0000000,262.8800000); //
	CreateDynamicObject(968,3381.1400000,-2431.4300000,4.6100000,0.0000000,0.0000000,90.9900000); //
	CreateDynamicObject(970,3371.1800000,-2435.5000000,4.1300000,0.0000000,0.0000000,21.5000000); //
	CreateDynamicObject(970,3374.8600000,-2434.0800000,4.1300000,0.0000000,0.0000000,21.5000000); //
	CreateDynamicObject(970,3378.3800000,-2432.7200000,4.1300000,0.0000000,0.0000000,21.5000000); //
	CreateDynamicObject(970,3379.1200000,-2423.8500000,4.2400000,0.0000000,0.0000000,338.0500000); //
	CreateDynamicObject(970,3375.4100000,-2422.2800000,4.2400000,0.0000000,0.0000000,338.0500000); //
	CreateDynamicObject(970,3371.7300000,-2420.8000000,4.2400000,0.0000000,0.0000000,338.0500000); //
	CreateDynamicObject(970,3367.9800000,-2419.3100000,4.2400000,0.0000000,0.0000000,338.0500000); //
	CreateDynamicObject(1337,3367.9800000,-2419.3100000,4.2400000,0.0000000,0.0000000,338.0500000); //
	CreateDynamicObject(18752,3510.4200000,-2533.8500000,-19.2700000,0.0000000,0.0000000,358.9800000); //
	CreateDynamicObject(5706,3350.6000000,-2449.6000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3350.7400000,-2470.9900000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3318.0400000,-2471.3000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3317.2600000,-2449.6900000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3318.0700000,-2490.7200000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3350.7100000,-2490.9000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3350.9200000,-2513.4000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3317.8700000,-2513.2600000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3317.8700000,-2513.2600000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3317.8100000,-2449.5400000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3287.1500000,-2513.5300000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3287.1500000,-2513.5300000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(7523,3298.4600000,-2518.3600000,4.0000000,0.0000000,0.0000000,90.2000000); //
	CreateDynamicObject(5706,3350.9000000,-2531.2400000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3318.4500000,-2531.3800000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3287.5700000,-2531.3600000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3287.0400000,-2492.1600000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3287.2000000,-2471.1800000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3286.8900000,-2449.5800000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3263.1100000,-2449.5100000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3263.1000000,-2468.8700000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3263.0900000,-2491.1400000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3263.0900000,-2513.1100000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3263.0700000,-2534.7900000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3262.9800000,-2556.4900000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3262.9000000,-2578.6500000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3262.7900000,-2600.1100000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3295.0400000,-2553.6200000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3294.6300000,-2575.4000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3294.4400000,-2597.3100000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3294.5400000,-2599.9800000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3323.4200000,-2600.1300000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3350.8900000,-2553.5700000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3350.8900000,-2574.9500000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3350.9900000,-2595.2200000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3352.3400000,-2600.3000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3326.6600000,-2583.2900000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3323.9600000,-2567.0200000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3320.3000000,-2551.5000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5706,3320.3000000,-2551.5000000,-0.2000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3454,3310.6500000,-2584.2200000,8.6700000,0.0000000,0.0000000,359.7300000); //
	CreateDynamicObject(3454,3310.0500000,-2450.2500000,8.6700000,0.0000000,0.0000000,181.6700000); //
	CreateDynamicObject(3454,3282.5400000,-2455.7400000,8.6700000,0.0000000,0.0000000,271.1700000); //
	CreateDynamicObject(3454,3282.8600000,-2495.5000000,8.6700000,0.0000000,0.0000000,271.4700000); //
	CreateDynamicObject(3454,3281.7900000,-2538.1400000,8.6700000,0.0000000,0.0000000,271.4700000); //
	CreateDynamicObject(3454,3282.2000000,-2577.5400000,8.6700000,0.0000000,0.0000000,271.4700000); //
	CreateDynamicObject(7522,3314.6500000,-2518.4800000,8.4600000,0.0000000,0.0000000,90.4200000); //
	CreateDynamicObject(8150,3308.1200000,-2609.8600000,5.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(8150,3246.6500000,-2547.7400000,5.0000000,0.0000000,0.0000000,270.0400000); //
	CreateDynamicObject(8150,3247.0000000,-2497.0600000,5.0000000,0.0000000,0.0000000,270.0400000); //
	CreateDynamicObject(8150,3307.7600000,-2436.9300000,5.0000000,0.0000000,0.0000000,179.7100000); //
	CreateDynamicObject(8150,3367.1200000,-2513.8500000,5.0000000,0.0000000,0.0000000,90.1600000); //
	CreateDynamicObject(8150,3367.2500000,-2548.2700000,5.0000000,0.0000000,0.0000000,90.1600000); //
	CreateDynamicObject(620,3322.3200000,-2558.3100000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3321.2100000,-2543.4800000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3321.1500000,-2497.7400000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3319.7700000,-2470.9900000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3274.5000000,-2478.3500000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3274.7400000,-2520.8800000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3274.8100000,-2559.3200000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3306.6700000,-2595.7900000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3297.3100000,-2596.4300000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3278.9500000,-2596.0500000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3323.6500000,-2596.2000000,4.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(620,3509.7700000,-2490.0600000,14.9200000,0.0000000,0.0000000,359.7000000); //
	CreateDynamicObject(620,3483.6000000,-2494.6900000,14.9200000,0.0000000,0.0000000,359.7000000); //
	CreateDynamicObject(620,3531.7800000,-2506.8200000,22.0300000,0.0000000,0.0000000,359.7000000); //
	CreateDynamicObject(620,3531.7800000,-2506.8200000,22.0300000,0.0000000,0.0000000,359.7000000); //
	CreateDynamicObject(970,3081.3800000,-2364.5600000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3077.5400000,-2363.7200000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3073.6000000,-2362.9100000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3069.5900000,-2362.1300000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3065.6700000,-2361.3500000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3065.6700000,-2361.3500000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3061.6600000,-2360.5700000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3057.6300000,-2359.7800000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3053.5500000,-2358.9700000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3049.7000000,-2358.1600000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3045.7700000,-2357.2900000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3041.6800000,-2356.4600000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3037.7000000,-2355.6300000,22.5800000,0.0000000,0.0000000,347.5000000); //
	CreateDynamicObject(970,3033.7200000,-2354.9100000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3029.6000000,-2354.1700000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3025.6300000,-2353.3200000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3021.6400000,-2352.5300000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3017.6400000,-2351.7900000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3013.6700000,-2350.9700000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3009.9700000,-2350.3000000,22.5800000,0.0000000,0.0000000,349.2400000); //
	CreateDynamicObject(970,3006.3000000,-2348.7400000,22.5800000,0.0000000,0.0000000,325.9100000); //
	CreateDynamicObject(970,3002.8500000,-2346.4100000,22.5800000,0.0000000,0.0000000,325.9100000); //
	CreateDynamicObject(970,2999.4300000,-2344.0700000,22.5800000,0.0000000,0.0000000,325.9100000); //
	CreateDynamicObject(970,2996.6200000,-2341.2100000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2994.4800000,-2337.9700000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2992.4000000,-2334.7000000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2990.0900000,-2331.3500000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2987.9300000,-2328.0100000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2985.6600000,-2324.5000000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2983.4100000,-2321.1300000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2981.1800000,-2317.7700000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2979.0500000,-2314.4500000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2963.0000000,-2324.6100000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2965.1500000,-2328.1000000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2967.3800000,-2331.5800000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2969.5300000,-2335.0100000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2971.7100000,-2338.5400000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2973.8800000,-2341.8700000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2976.1300000,-2345.3000000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2978.3600000,-2348.6400000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2980.5800000,-2352.0500000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2982.6300000,-2355.2300000,22.5800000,0.0000000,0.0000000,302.2900000); //
	CreateDynamicObject(970,2985.5700000,-2358.0400000,22.5800000,0.0000000,0.0000000,326.4700000); //
	CreateDynamicObject(970,2988.9000000,-2360.2600000,22.5800000,0.0000000,0.0000000,326.4700000); //
	CreateDynamicObject(970,2992.2200000,-2362.3900000,22.5800000,0.0000000,0.0000000,326.4700000); //
	CreateDynamicObject(970,2995.5400000,-2364.6000000,22.5800000,0.0000000,0.0000000,326.4700000); //
	CreateDynamicObject(970,2998.7000000,-2366.8100000,22.5800000,0.0000000,0.0000000,326.4700000); //
	CreateDynamicObject(970,3002.4600000,-2368.4200000,22.5800000,0.0000000,0.0000000,345.6200000); //
	CreateDynamicObject(970,3006.3000000,-2369.3100000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3010.2600000,-2370.0800000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3014.1600000,-2370.8800000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3018.0900000,-2371.7100000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3022.0000000,-2372.4900000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3026.0000000,-2373.3200000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3029.9700000,-2374.1600000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3033.9400000,-2375.0000000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3037.8900000,-2375.8200000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3041.8300000,-2376.6300000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3045.8400000,-2377.4200000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3049.7300000,-2378.2400000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3053.7600000,-2379.0700000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3057.7600000,-2379.9200000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3061.8000000,-2380.7400000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3065.8400000,-2381.5600000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3069.8700000,-2382.3700000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3073.8700000,-2383.2100000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3077.8800000,-2383.9900000,22.5800000,0.0000000,0.0000000,348.3300000); //
	CreateDynamicObject(970,3077.8800000,-2383.9900000,22.5800000,0.0000000,0.0000000,348.3300000); //
	
	// AIRLINE BAZA ID:3
	CreateDynamicObject(5147,2929.5922852,-1020.3380127,32.8427124,0.0000000,0.4998779,196.4959717); //object(sanpedbigbrid_las2)(1)
	CreateDynamicObject(7605,3164.7753906,-853.7929688,28.5977573,0.0000000,0.0000000,180.2335205); //object(vegasnroad08)(2)
	CreateDynamicObject(13724,3080.3535156,-863.0184326,23.4724159,0.0000000,0.0000000,269.7473144); //object(drg_nu_ext)(1)
	CreateDynamicObject(13744,3080.3354492,-881.2167358,23.8598747,0.0000000,0.0000000,269.7500000); //object(drg_nu_ext05)(1)
	CreateDynamicObject(750,3116.2480469,-859.9016724,27.5408287,0.0000000,0.0000000,0.0000000); //object(sm_scrb_column2)(3)
	CreateDynamicObject(750,3116.3281250,-848.7187500,27.5408287,0.0000000,0.0000000,0.0000000); //object(sm_scrb_column2)(4)
	CreateDynamicObject(6297,3033.8994141,-878.1376953,9.0285149,5.9985352,0.0000000,271.9995117); //object(beachut01_law2)(2)
	CreateDynamicObject(17472,3050.0971680,-813.7299194,15.0000000,0.0000000,0.0000000,185.9943848); //object(cunt_rocgxp2_04)(3)
	CreateDynamicObject(17472,2997.6728516,-812.2460938,11.5000000,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,2950.2880859,-813.8544922,2.0800013,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(5)
	CreateDynamicObject(17472,3136.2243652,-850.4318237,11.2599983,0.0000000,350.0000000,155.9945068); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3051.5573731,-801.1381836,15.0000000,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(8)
	CreateDynamicObject(17472,3001.5085449,-802.1082764,11.5000000,0.0000000,0.0000000,181.9885254); //object(cunt_rocgxp2_04)(9)
	CreateDynamicObject(17472,2953.8205566,-800.2977295,2.0800013,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(10)
	CreateDynamicObject(17472,2989.7104492,-795.0172119,-0.1999991,0.0000000,0.0000000,175.9844971); //object(cunt_rocgxp2_04)(11)
	CreateDynamicObject(17472,3040.1489258,-791.4147949,3.6300030,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(12)
	CreateDynamicObject(17472,3084.6328125,-796.1621094,7.1300030,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3088.9169922,-785.7685547,-4.8699970,0.0000000,0.0000000,185.9930420); //object(cunt_rocgxp2_04)(14)
	CreateDynamicObject(7448,3223.5410156,-938.0527344,42.9020691,0.0000000,0.0000000,180.2471924); //object(vegaswcoast05)(3)
	CreateDynamicObject(7425,3159.6511231,-854.1642456,28.5508690,0.0000000,0.0000000,180.0000000); //object(golfsign1_vgn)(1)
	CreateDynamicObject(7423,3125.7866211,-853.9530640,28.5274448,0.0000000,0.0000000,179.7500000); //object(glfcrsgate1_vgs)(1)
	CreateDynamicObject(7664,3203.6699219,-933.6250000,30.1204758,0.0000000,0.0000000,180.2471924); //object(glfcrsgate5_vgs)(1)
	CreateDynamicObject(7665,3143.7021484,-940.5617676,30.0748138,0.0000000,0.0000000,179.7473145); //object(glfcrsgate4_vgs)(1)
	CreateDynamicObject(5428,3129.7592773,-818.7525024,27.5925121,0.0000000,0.0000000,90.0000000); //object(laejeffers10)(1)
	CreateDynamicObject(5429,3115.3906250,-822.1306763,26.8645687,0.0000000,356.0000000,2.0000000); //object(xwhattfk_lae)(1)
	CreateDynamicObject(5429,3105.2988281,-825.0657959,27.8645687,0.0000000,355.9954834,1.9995117); //object(xwhattfk_lae)(2)
	CreateDynamicObject(5429,3113.8818359,-836.4906006,27.0145741,0.0000000,355.9954834,1.9995117); //object(xwhattfk_lae)(4)
	CreateDynamicObject(5429,3111.6796875,-840.2128906,26.7645798,0.0000000,355.9899902,1.9995117); //object(xwhattfk_lae)(5)
	CreateDynamicObject(5429,3131.9875488,-828.0843506,28.1145763,0.0000000,355.9954834,1.9995117); //object(xwhattfk_lae)(6)
	CreateDynamicObject(17472,3080.4960938,-819.4085083,16.6500549,0.0000000,0.0000000,138.0000000); //object(cunt_rocgxp2_04)(1)
	CreateDynamicObject(17472,3102.5458984,-833.9638672,15.5700226,0.0000000,0.0000000,237.9913330); //object(cunt_rocgxp2_04)(5)
	CreateDynamicObject(10984,3086.6887207,-822.9583740,26.1289196,346.0000000,0.0000000,90.0000000); //object(rubbled01_sfs)(1)
	CreateDynamicObject(10984,3087.0107422,-828.4482422,26.1289196,345.9979248,0.0000000,90.0000000); //object(rubbled01_sfs)(2)
	CreateDynamicObject(7885,3214.5878906,-854.3134766,28.6508827,0.0000000,0.0000000,180.2416992); //object(vegasglfhse1)(1)
	CreateDynamicObject(7917,3214.5930176,-854.3200684,28.5914135,0.0000000,0.0000000,180.2500000); //object(vegasglfhse2)(1)
	CreateDynamicObject(5147,3136.6198731,-959.0524292,34.7425652,0.0000000,359.4946289,16.4959717); //object(sanpedbigbrid_las2)(1)
	CreateDynamicObject(14467,3137.7575684,-965.7380371,37.8246231,0.0000000,0.0000000,245.9893799); //object(carter_statue)(1)
	CreateDynamicObject(14467,3134.6643066,-953.5390625,37.8246231,0.0000000,0.0000000,279.9865723); //object(carter_statue)(1)
	CreateDynamicObject(750,3171.8212891,-963.4591675,27.2908287,0.0000000,0.0000000,0.0000000); //object(sm_scrb_column2)(4)
	CreateDynamicObject(750,3173.3867188,-963.5364990,27.0158329,0.0000000,0.0000000,0.0000000); //object(sm_scrb_column2)(4)
	CreateDynamicObject(6297,3275.7614746,-884.7066650,16.9385109,5.9985352,0.0000000,89.9995117); //object(beachut01_law2)(2)
	CreateDynamicObject(6297,3315.5563965,-883.8787231,7.5185127,5.9985352,0.0000000,89.9945068); //object(beachut01_law2)(2)
	CreateDynamicObject(17472,3234.7121582,-901.2604370,10.2500000,0.0000000,0.0000000,145.9945068); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3240.6621094,-903.7128906,17.7500000,0.0000000,0.0000000,145.9863281); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3274.3916016,-909.4980469,19.0999794,0.0000000,0.0000000,181.9885254); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3302.5920410,-911.9231567,19.0999794,0.0000000,0.0000000,181.9885254); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3342.3796387,-919.6602173,-0.4000206,0.0000000,0.0000000,151.9885254); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3306.3801269,-904.2829590,9.7749815,0.0000000,0.0000000,171.9885254); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3263.8359375,-899.9893189,9.7749815,0.0000000,0.0000000,171.9854736); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3135.3073731,-800.4949951,19.1400089,0.0000000,0.0000000,175.9930420); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3169.0415039,-799.2529907,14.1250038,0.0000000,0.0000000,175.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3194.3823242,-801.8513794,23.2750168,0.0000000,0.0000000,175.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3235.6748047,-858.7060547,10.6250038,0.0000000,0.0000000,267.9895019); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3228.9707031,-806.6716309,11.1250038,0.0000000,0.0000000,281.9895019); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3223.7343750,-806.0288696,11.1250038,0.0000000,0.0000000,281.9860840); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3223.0253906,-804.5087280,11.1250038,0.0000000,0.0000000,281.9860840); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3206.0322266,-803.7972412,11.1250038,0.0000000,0.0000000,329.9860840); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3202.1401367,-801.1406250,10.3750038,0.0000000,348.0000000,347.9853516); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(11533,3104.2092285,-1035.3908691,-5.6466150,0.0000000,0.0000000,195.9963379); //object(sw_bit_04)(2)
	CreateDynamicObject(11533,3094.5810547,-993.6669922,-19.6266117,0.0000000,0.0000000,193.9910889); //object(sw_bit_04)(3)
	CreateDynamicObject(11533,3095.0280762,-922.8051758,-19.6216011,0.0000000,0.0000000,159.9910889); //object(sw_bit_04)(4)
	CreateDynamicObject(11533,3111.5603027,-887.6963501,-19.5166264,0.0000000,0.0000000,159.9884033); //object(sw_bit_04)(5)
	CreateDynamicObject(11533,3276.1149902,-1086.4450684,2.3433838,0.0000000,0.0000000,307.9963379); //object(sw_bit_04)(6)
	CreateDynamicObject(11533,3225.9538574,-1123.9635010,-18.0666141,0.0000000,0.0000000,259.9962158); //object(sw_bit_04)(7)
	CreateDynamicObject(11533,3250.2934570,-1126.9324951,-29.3166141,0.0000000,0.0000000,239.9914551); //object(sw_bit_04)(8)
	CreateDynamicObject(16192,3356.9650879,-1053.2635498,14.3744984,0.0000000,0.0000000,248.0000000); //object(cen_bit_01)(1)
	CreateDynamicObject(17472,3303.6376953,-934.0917969,25.3799782,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3306.2812500,-984.5759277,25.3799782,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3313.2202148,-976.2492065,10.0699806,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3309.3828125,-938.5520630,10.0699806,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3315.3486328,-937.1353760,3.3199806,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3321.2626953,-942.9718018,-5.6800194,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3327.7626953,-942.7907715,-5.6800194,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(10984,3332.0273438,-954.4583130,8.3289242,346.5507812,343.5361939,231.0679932); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3341.9807129,-954.6437988,6.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3348.8642578,-953.3652344,5.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3347.8669434,-943.8883057,5.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3346.6406250,-933.1818237,5.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3348.4863281,-927.4731445,5.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3357.4323731,-937.9906616,1.5789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3357.9638672,-944.4689941,1.5789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3357.1179199,-947.0851440,1.5789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3359.8784180,-954.2224121,1.5789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3363.4802246,-958.7660523,1.5789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3366.8222656,-949.7630615,0.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3367.1779785,-942.9478760,0.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3366.4909668,-935.7291260,0.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3366.4902344,-935.7285156,0.0789242,346.5472412,343.5314941,231.0644531); //object(rubbled01_sfs)(2)
	CreateDynamicObject(17472,3135.1469727,-1007.6622925,25.3799782,0.0000000,0.0000000,101.9860535); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3137.9404297,-1014.9038086,25.3799782,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3147.2421875,-1040.5667725,25.3799782,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3150.1093750,-1045.8000488,25.3799782,0.0000000,0.0000000,101.9860535); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3158.6059570,-1045.1893310,37.9399757,0.0000000,0.0000000,127.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3162.4836426,-1038.3648682,21.8499794,0.0000000,0.0000000,127.9852295); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3151.6965332,-1043.4324951,37.6299782,0.0000000,0.0000000,101.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3160.9694824,-1073.6286621,19.8799782,0.0000000,295.9998779,101.9860535); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3079.5883789,-961.3515015,11.5000000,0.0000000,0.0000000,181.9930420); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3084.8276367,-961.0429688,11.5000000,0.0000000,0.0000000,181.9885254); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3035.3591309,-952.7828980,19.3499985,0.0000000,0.0000000,19.9885254); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,2989.6157227,-955.3785400,6.5999985,0.0000000,0.0000000,19.9841309); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,2944.3461914,-951.3011475,-1.6500015,0.0000000,0.0000000,19.9841309); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,2934.0832519,-950.4146118,-6.4000015,0.0000000,0.0000000,19.9841309); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,2970.0173340,-978.6312256,-0.1200020,0.0000000,0.0000000,181.9841309); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3027.0109863,-975.9201050,7.8799982,0.0000000,0.0000000,181.9830322); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3013.8933106,-977.3339844,4.3799982,0.0000000,0.0000000,181.9830322); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3068.6921387,-974.5825195,-0.8700018,0.0000000,0.0000000,181.9830322); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3069.0759277,-968.6452637,5.6299982,0.0000000,0.0000000,181.9830322); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3199.9758301,-784.1671143,11.5650063,0.0000000,0.0000000,5.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3170.2604981,-783.3214111,11.5650063,0.0000000,0.0000000,5.9875488); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3139.4462891,-780.0185547,11.5650063,0.0000000,0.0000000,5.9875488); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3105.5993652,-786.0288086,11.5650063,0.0000000,0.0000000,5.9875488); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3095.8312988,-785.9821777,21.3150063,0.0000000,0.0000000,5.9875488); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3097.1230469,-768.9707031,2.7850072,0.0000000,0.0000000,5.9875488); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(16192,3320.3281250,-743.6503906,-8.2405043,0.0000000,0.0000000,269.9945068); //object(cen_bit_01)(2)
	CreateDynamicObject(16192,3395.3164062,-740.3017578,-15.4405022,0.0000000,0.0000000,273.9935303); //object(cen_bit_01)(3)
	CreateDynamicObject(17472,3201.8925781,-756.4433594,24.1250038,0.0000000,0.0000000,89.9890137); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3200.7097168,-766.3260498,21.6250038,0.0000000,0.0000000,89.9890137); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3211.7729492,-738.2958374,3.8750038,0.0000000,0.0000000,69.9890137); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3196.5126953,-739.0579834,3.8750038,0.0000000,0.0000000,69.9884033); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3188.9970703,-754.1624145,8.3750038,0.0000000,0.0000000,69.9884033); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3166.5629883,-764.9058838,8.3750038,0.0000000,0.0000000,35.9884033); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3165.0200195,-1062.8549805,25.8799782,0.0000000,295.9991455,131.9805908); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3172.4843750,-1073.4995117,12.8799782,0.0000000,295.9991455,131.9787598); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3169.1826172,-1068.7906494,17.6299782,0.0000000,295.9991455,131.9787598); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3121.9599609,-985.9943848,14.3799782,0.0000000,0.0000000,101.9860535); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(10984,3107.6694336,-909.7096558,28.4889545,0.0000000,14.0000000,180.0000000); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3107.7187500,-927.3390503,28.4889545,0.0000000,13.9965820,179.9945068); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3107.0026856,-942.7850342,28.4889545,0.0000000,13.9965820,179.9945068); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3107.1948242,-952.8755493,28.6639633,0.0000000,13.9965820,179.9945068); //object(rubbled01_sfs)(2)
	CreateDynamicObject(17472,3109.6479492,-981.4456787,14.3799782,0.0000000,0.0000000,123.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3120.0380859,-977.3254394,14.3799782,0.0000000,0.0000000,123.9806824); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3088.8781738,-932.9846802,6.4500122,0.0000000,0.0000000,87.9885254); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3084.8505859,-932.8309326,3.7000122,0.0000000,0.0000000,87.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3080.5957031,-932.9472656,3.7000122,0.0000000,0.0000000,87.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3080.3515625,-941.7514038,3.7000122,0.0000000,0.0000000,87.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(10984,3042.6813965,-828.5074463,13.7639465,0.0000000,25.9965820,179.9945068); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3043.4245606,-842.7127075,13.7639465,0.0000000,25.9936523,179.9945068); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3047.1467285,-856.5779419,13.7639465,0.0000000,25.9936523,213.9945068); //object(rubbled01_sfs)(2)
	CreateDynamicObject(10984,3056.2141113,-862.5354614,13.7639465,0.0000000,25.9881592,225.9916992); //object(rubbled01_sfs)(2)
	CreateDynamicObject(17472,3056.2824707,-890.4591065,0.8500128,0.0000000,0.0000000,87.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3049.9985352,-890.4368897,0.8500128,0.0000000,0.0000000,87.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3042.0800781,-891.8974609,0.8500128,0.0000000,0.0000000,87.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3047.3115234,-903.6932373,0.8500128,0.0000000,0.0000000,125.9840088); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3050.4121094,-899.1699219,0.8500128,0.0000000,0.0000000,125.9802246); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3072.2160644,-911.3887940,0.8500128,0.0000000,0.0000000,163.9802246); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3061.0866699,-912.9915772,0.8500128,0.0000000,0.0000000,163.9764404); //object(cunt_rocgxp2_04)(4)
	CreateDynamicObject(17472,3213.7539062,-878.9592285,10.6250038,0.0000000,0.0000000,359.9895019); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3215.0878906,-877.8264770,13.7000179,0.0000000,0.0000000,347.9890137); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3214.1799316,-865.5877075,13.7000179,0.0000000,0.0000000,347.9864502); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3223.9658203,-865.0969849,13.2999992,0.0000000,0.0000000,81.9885254); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3220.8098144,-875.1488648,13.2999992,0.0000000,0.0000000,81.9854736); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3237.2150879,-831.9981079,13.2999992,0.0000000,0.0000000,271.9854736); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3236.4289551,-822.7819214,13.2999992,0.0000000,0.0000000,271.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3232.8090820,-818.5722656,13.2999992,0.0000000,0.0000000,271.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3234.3913574,-810.6605835,13.2999992,0.0000000,0.0000000,271.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(7664,3166.1413574,-833.8844605,30.0954761,0.0000000,0.0000000,270.2471924); //object(glfcrsgate5_vgs)(1)
	CreateDynamicObject(17472,3219.3632812,-807.4713745,15.0250168,0.0000000,0.0000000,175.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3120.5031738,-800.5526123,18.6900005,0.0000000,0.0000000,175.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3128.8891602,-807.3375244,12.6900005,0.0000000,0.0000000,175.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3142.9450684,-807.3447266,12.6900005,0.0000000,0.0000000,175.9899902); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(18483,3120.9584961,-908.1605835,28.5293102,0.0000000,180.0000000,90.0000000); //object(cuntsrod07)(1)
	CreateDynamicObject(18483,3126.1887207,-920.7197266,28.5293102,0.0000000,179.9945068,90.0000000); //object(cuntsrod07)(5)
	CreateDynamicObject(17472,3122.8647461,-972.4447022,15.8799782,0.0000000,0.0000000,123.9807129); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(10815,3162.5195312,-702.9804688,28.7899952,0.0000000,0.0000000,315.9997559); //object(airprtgnd_02_sfse)(1)
	CreateDynamicObject(10817,3295.8212891,-546.3457031,15.0216789,0.0000000,0.0000000,1.4996338); //object(airprtgnd_03_sfse)(1)
	CreateDynamicObject(10816,3633.1640625,-473.0195312,27.6125031,0.0000000,0.0000000,1.4996338); //object(airprtgnd_01_sfse)(1)
	CreateDynamicObject(11367,3571.2001953,-633.0136719,5.9209986,0.0000000,0.0000000,91.5000000); //object(airprtgnd_ct_sfse)(1)
	CreateDynamicObject(10767,3907.3630371,-446.5090942,14.0750141,0.0000000,0.0000000,316.5000000); //object(airport_11_sfse)(1)
	CreateDynamicObject(10766,4034.8415527,-443.3152771,26.7307091,0.0000000,0.0000000,271.5000000); //object(airport_10_sfse)(1)
	CreateDynamicObject(10764,4116.3417969,-441.2117920,29.4838333,0.0000000,0.0000000,316.7500000); //object(app_light_sfs05e)(1)
	CreateDynamicObject(10763,3681.5717773,-586.6179199,60.8807335,0.0000000,0.0000000,316.5000000); //object(controltower_sfse)(1)
	CreateDynamicObject(16192,3111.6232910,-683.2423096,-12.2705269,0.0000000,0.0000000,193.9945068); //object(cen_bit_01)(2)
	CreateDynamicObject(16192,3023.5852051,-504.5724182,-8.5705290,0.0000000,0.0000000,7.9910889); //object(cen_bit_01)(2)
	CreateDynamicObject(17472,3057.9360352,-607.6964111,24.2750053,0.0000000,0.0000000,5.9875488); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(16192,3221.7519531,-677.5632935,-12.2705269,0.0000000,0.0000000,233.9910889); //object(cen_bit_01)(2)
	CreateDynamicObject(16192,3297.8918457,-685.2091065,-12.6955204,0.0000000,0.0000000,225.9868164); //object(cen_bit_01)(2)
	CreateDynamicObject(17472,3368.7265625,-675.8286743,35.2950020,0.0000000,0.0000000,299.9890137); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3347.7880859,-638.9056397,35.2950020,0.0000000,0.0000000,317.9871826); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3313.8728027,-609.4988403,31.7450066,0.0000000,0.0000000,341.9827881); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3320.8535156,-643.6333618,35.2950020,0.0000000,0.0000000,147.9779053); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3324.7478027,-661.1911011,35.2950020,0.0000000,0.0000000,119.9748535); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3343.6142578,-700.4347534,35.2950020,0.0000000,0.0000000,169.9707031); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(17472,3294.1376953,-631.1588135,27.4950066,0.0000000,0.0000000,145.9824219); //object(cunt_rocgxp2_04)(13)
	CreateDynamicObject(16192,3477.3811035,-756.8121338,-10.9405022,0.0000000,0.0000000,231.9935303); //object(cen_bit_01)(3)
	CreateDynamicObject(16192,3573.1396484,-729.3610840,-10.9405022,0.0000000,0.0000000,243.9927978); //object(cen_bit_01)(3)
	CreateDynamicObject(16192,3662.7529297,-741.1364136,-10.9405022,0.0000000,0.0000000,229.9898682); //object(cen_bit_01)(3)
	CreateDynamicObject(16192,3744.4736328,-738.6494141,-10.9405022,0.0000000,0.0000000,231.9877930); //object(cen_bit_01)(3)
	CreateDynamicObject(16192,3817.6049805,-598.7417602,-10.9405022,0.0000000,0.0000000,307.9873047); //object(cen_bit_01)(3)
	CreateDynamicObject(17472,3749.5556641,-566.1694946,7.3799782,0.0000000,0.0000000,283.9860840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3775.4658203,-548.0865478,7.3799782,0.0000000,0.0000000,193.9855957); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3804.3725586,-545.3575440,7.3799782,0.0000000,0.0000000,193.9801025); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3829.6779785,-513.6184082,7.3799782,0.0000000,0.0000000,275.9801025); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3829.3359375,-467.2974853,7.3799782,0.0000000,0.0000000,275.9765625); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3856.5329590,-484.2779236,7.3799782,0.0000000,0.0000000,181.9765625); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3905.9035644,-482.7567749,7.3799782,0.0000000,0.0000000,181.9720459); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3956.3925781,-482.0459595,7.3799782,0.0000000,0.0000000,181.9720459); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4009.0888672,-481.3892212,7.3799782,0.0000000,0.0000000,181.9720459); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4060.7900391,-480.5477295,7.3799782,0.0000000,0.0000000,181.9720459); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4109.7880859,-475.2601318,7.3799782,0.0000000,0.0000000,181.9720459); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4149.5483398,-475.0025330,7.3799782,0.0000000,0.0000000,221.9720459); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4151.8486328,-442.6491089,7.3799782,0.0000000,0.0000000,277.9677734); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4172.7470703,-442.9154053,-6.6200218,0.0000000,0.0000000,277.9650879); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4172.7470703,-442.9150391,-6.6200218,0.0000000,0.0000000,277.9650879); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4144.0917969,-406.3114624,7.3799782,0.0000000,0.0000000,333.9650879); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4101.2011719,-403.8472290,7.3799782,0.0000000,0.0000000,3.9624023); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,4048.4384766,-406.9912109,7.3799782,0.0000000,0.0000000,3.9605713); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3996.9108887,-407.9024048,7.3799782,0.0000000,0.0000000,3.9605713); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3940.4694824,-406.6126099,7.3799782,0.0000000,0.0000000,7.9605713); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3887.5168457,-409.1727295,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3833.9299316,-413.0302734,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3783.3994141,-412.8746643,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3729.8647461,-411.9897156,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3678.9394531,-414.1673584,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3624.9604492,-414.6033325,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3575.2121582,-418.3891602,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3525.9602051,-421.9068603,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3476.4204102,-425.4349670,7.3799782,0.0000000,0.0000000,7.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3428.2250977,-427.6642456,7.3799782,0.0000000,0.0000000,5.9595947); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3377.3117676,-426.7388306,7.3799782,0.0000000,0.0000000,5.9545898); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3323.7932129,-423.9456482,7.3799782,0.0000000,0.0000000,5.9545898); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3276.3183594,-426.3994751,7.3799782,0.0000000,0.0000000,5.9545898); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3227.9206543,-428.1365356,7.3799782,0.0000000,0.0000000,5.9545898); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3179.0556641,-436.1728516,7.3799782,0.0000000,0.0000000,23.9501953); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3135.7387695,-458.7452393,7.3799782,0.0000000,0.0000000,39.9501953); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3098.6015625,-493.5615234,7.3799782,0.0000000,0.0000000,61.9409180); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(10788,3716.1716309,-567.0223389,24.5272446,0.0000000,0.0000000,316.5000000); //object(aircarpark_11_sfse)(1)
	CreateDynamicObject(11383,3716.3823242,-575.6729126,31.1168594,0.0000000,0.0000000,91.5000000); //object(jjct02)(1)
	CreateDynamicObject(3605,3399.7978516,-675.3569946,34.6563034,0.0000000,0.0000000,2.0000000); //object(bevman3_law2)(1)
	CreateDynamicObject(7885,3604.6264648,-647.9505615,28.6008835,0.0000000,0.0000000,271.4886475); //object(vegasglfhse1)(1)
	CreateDynamicObject(8240,3079.3227539,-165.0782318,42.1881638,0.0000000,0.0000000,271.7500000); //object(vgssbighanger1)(1)
	CreateDynamicObject(10815,3154.6960449,-353.8264465,28.7899952,0.0000000,0.0000000,316.4997559); //object(airprtgnd_02_sfse)(1)
	CreateDynamicObject(4865,3257.4162598,-113.5146866,28.6724434,0.0000000,0.0000000,91.7500000); //object(lasrnway2_las)(1)
	CreateDynamicObject(4866,3104.5791016,-116.4199219,28.6724434,0.0000000,0.0000000,91.7468262); //object(lasrnway1_las)(1)
	CreateDynamicObject(5003,3231.5527344,174.8808594,34.9024468,0.0000000,0.0000000,91.7468262); //object(lasrnway5_las)(1)
	CreateDynamicObject(4866,3096.1989746,145.4885712,28.6474438,0.0000000,0.0000000,91.7468262); //object(lasrnway1_las)(2)
	CreateDynamicObject(8240,3076.7785644,-80.8117142,42.1881638,0.0000000,0.0000000,271.7468262); //object(vgssbighanger1)(3)
	CreateDynamicObject(8240,3074.1723633,3.5108499,42.1881638,0.0000000,0.0000000,271.7468262); //object(vgssbighanger1)(4)
	CreateDynamicObject(8240,3071.5847168,87.7792587,42.1881638,0.0000000,0.0000000,271.7468262); //object(vgssbighanger1)(5)
	CreateDynamicObject(8240,3069.0156250,172.1787109,42.1881638,0.0000000,0.0000000,271.7413330); //object(vgssbighanger1)(6)
	CreateDynamicObject(3816,3316.3479004,55.7664833,37.1383858,0.0000000,0.0000000,272.0000000); //object(bighangar1_sfx)(1)
	CreateDynamicObject(3816,3318.8354492,-17.0821075,37.1383858,0.0000000,0.0000000,271.9995117); //object(bighangar1_sfx)(2)
	CreateDynamicObject(17472,3040.3278809,-231.7601471,27.7899742,0.0000000,0.0000000,93.9409180); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3050.6787109,-273.4193115,27.7899742,0.0000000,0.0000000,129.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3085.9060059,-282.7656860,22.3399715,0.0000000,0.0000000,185.9353027); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3117.4772949,-281.4301453,20.6650829,0.0000000,0.0000000,185.9326172); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3036.6137695,-284.4968872,8.0999785,0.0000000,0.0000000,129.9353027); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3022.0737305,-255.0237427,8.0999785,0.0000000,0.0000000,111.9353027); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3030.5034180,-216.4728088,8.0999785,0.0000000,0.0000000,81.9342041); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3122.7062988,-302.1879272,1.4150829,0.0000000,0.0000000,185.9326172); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3076.2229004,-303.4620666,1.4150829,0.0000000,0.0000000,185.9326172); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3082.2131348,-296.6662293,8.4150829,0.0000000,0.0000000,183.9326172); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3067.5461426,-308.4127808,-11.0849171,0.0000000,0.0000000,183.9276123); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3178.8041992,-277.7582092,13.6850853,0.0000000,0.0000000,185.9326172); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3186.8962402,-278.0219727,14.9350853,0.0000000,0.0000000,181.9326172); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3220.6828613,-279.3818054,27.4350853,0.0000000,0.0000000,181.9281006); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3266.6953125,-274.5774231,27.4350853,0.0000000,0.0000000,207.9281006); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3307.7619629,-243.3936310,27.4350853,0.0000000,0.0000000,237.9272461); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3327.2685547,-197.1971893,27.4350853,0.0000000,0.0000000,267.9254150); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3327.1711426,-149.8150940,27.4350853,0.0000000,0.0000000,279.9235840); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3325.4287109,-101.4246216,27.4350853,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3325.9016113,-75.9155273,27.4350853,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3348.5471191,-76.5565948,5.8550897,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3345.7854004,-107.1642303,5.8550897,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3349.0485840,-151.1538849,5.8550897,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3344.2590332,-174.9612274,5.8550897,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3336.9909668,-216.4000244,5.8550897,0.0000000,0.0000000,249.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3322.2407227,-253.2153626,5.8550897,0.0000000,0.0000000,249.9169922); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3297.0507812,-271.6017151,5.8550897,0.0000000,0.0000000,249.9169922); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3261.3190918,-293.5924988,5.8550897,0.0000000,0.0000000,195.9169922); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3218.2521973,-303.2402649,5.8550897,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3174.9184570,-291.3257141,5.8550897,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3147.8051758,-292.8956299,5.8550897,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3155.2565918,-296.2196045,15.6050892,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3168.3024902,-296.7144165,15.6050892,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3175.2304688,-295.3105469,15.6050892,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3176.9152832,-316.0899963,2.8550892,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3149.9848633,-325.2291260,2.8550892,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3030.5595703,-188.2722931,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3028.7846680,-133.3245239,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3027.2263184,-79.7593460,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3025.7084961,-27.5947304,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3024.1843262,18.4003506,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3022.6826172,64.9492874,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3021.3354492,110.4721146,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3019.9194336,155.7674408,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3018.6113281,200.3086548,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3023.0483398,246.8620453,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3028.3352051,291.6833496,23.3399773,0.0000000,0.0000000,77.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3065.7060547,311.9559936,23.3399773,0.0000000,0.0000000,29.9370117); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3098.4230957,312.5804443,23.3399773,0.0000000,0.0000000,9.9322510); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3144.7265625,315.6281738,23.3399773,0.0000000,0.0000000,9.9316406); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3188.1738281,316.8118897,22.3399773,0.0000000,0.0000000,5.9316406); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3232.4611816,313.0201721,21.0899773,0.0000000,0.0000000,355.9266357); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3271.4829102,294.7268372,21.0899773,0.0000000,0.0000000,333.9240723); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3302.2202148,264.1338196,21.0899773,0.0000000,0.0000000,309.9239502); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3313.8176269,222.6265564,21.0899773,0.0000000,0.0000000,287.9188232); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3315.6875000,178.4368897,21.0899773,0.0000000,0.0000000,275.9187012); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3316.7001953,136.5525513,21.0899773,0.0000000,0.0000000,275.9161377); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3318.6457519,106.1525497,21.0899773,0.0000000,0.0000000,275.9161377); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3010.9289551,-188.2952270,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3022.7717285,-159.2408142,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3009.8742676,-138.5256653,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3026.5473633,-106.4233551,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3015.9711914,-90.9215546,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3019.0957031,-70.0941009,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3010.8989258,-33.7254944,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3014.7053223,-20.1491642,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3006.1967773,19.7055988,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3007.6833496,62.0131226,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3011.9941406,104.6249161,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3011.8137207,128.7615204,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3007.2216797,154.6255951,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,2998.9536133,178.3773193,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,2996.4653320,209.2867279,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3007.9672852,222.2505798,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,2995.6855469,238.8674927,2.9299803,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3003.8876953,268.8551941,2.9299803,0.0000000,0.0000000,79.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3012.6074219,304.7800903,2.9299803,0.0000000,0.0000000,71.9365234); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3047.9687500,334.3677978,5.4299803,0.0000000,0.0000000,39.9329834); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3095.2050781,335.6274414,5.4299803,0.0000000,0.0000000,3.9298096); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3138.9655762,331.8466492,5.4299803,0.0000000,0.0000000,3.9276123); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3182.7375488,336.4781189,5.4299803,0.0000000,0.0000000,3.9276123); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3226.4462891,331.7932129,5.4299803,0.0000000,0.0000000,3.9276123); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3271.4968262,324.5210571,5.4299803,0.0000000,0.0000000,343.9276123); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3303.7421875,290.6878357,5.4299803,0.0000000,0.0000000,323.9270019); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3327.6757812,246.1959381,5.4299803,0.0000000,0.0000000,293.9263916); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3337.7158203,197.5702972,5.4299803,0.0000000,0.0000000,293.9227295); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3337.7158203,197.5693359,5.4299803,0.0000000,0.0000000,293.9227295); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3340.3295898,153.7847290,5.4299803,0.0000000,0.0000000,279.9227295); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3337.4916992,105.5640106,5.4299803,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3359.8928223,70.0461578,21.1299782,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3330.5178223,101.4376602,18.3799782,0.0000000,0.0000000,345.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3361.2868652,25.0721073,21.1299782,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3362.7001953,-16.6924248,21.1299782,0.0000000,0.0000000,277.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3361.8029785,-47.2985115,14.1299782,0.0000000,0.0000000,277.9156494); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3357.3444824,-52.9136124,14.1299782,0.0000000,0.0000000,277.9156494); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3338.7050781,-62.0672378,19.8799782,0.0000000,0.0000000,195.9156494); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3369.8571777,93.0419311,6.1299782,0.0000000,0.0000000,321.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3379.4052734,49.3891182,6.1299782,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3380.7978516,3.0510049,6.1299782,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3381.4404297,-41.8424377,6.1299782,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3370.3293457,-90.8349381,6.1299782,0.0000000,0.0000000,279.9206543); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3160.0410156,-372.4125977,7.6050892,0.0000000,0.0000000,181.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3153.9982910,-332.0889893,7.6050892,0.0000000,0.0000000,351.9116211); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3162.1779785,-345.0367432,7.6050892,0.0000000,0.0000000,351.9085693); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3170.9101562,-352.0024414,-1.6449108,0.0000000,0.0000000,351.9085693); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3157.6223144,-284.3167725,13.3550892,0.0000000,0.0000000,195.9136963); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3139.1284180,-445.5503540,12.6299782,0.0000000,0.0000000,99.9501648); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3138.5827637,-424.3478394,12.6299782,0.0000000,0.0000000,99.9481201); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3139.6936035,-433.0306397,12.6299782,0.0000000,0.0000000,99.9481201); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3172.4042969,-431.4759216,12.6299782,0.0000000,0.0000000,279.9481201); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3172.6074219,-420.1273498,12.6299782,0.0000000,0.0000000,279.9426269); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3153.7211914,-395.7962647,4.6299782,0.0000000,0.0000000,11.9426269); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3143.0407715,-421.9334106,12.1299782,0.0000000,0.0000000,83.9421387); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3152.6091309,-422.0032043,12.1299782,0.0000000,0.0000000,83.9410400); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3140.3173828,-452.7015686,12.8799782,0.0000000,0.0000000,99.9481201); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3172.3583984,-415.8842163,12.6299782,0.0000000,0.0000000,279.9426269); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3030.2570801,-178.5409546,23.3399773,0.0000000,0.0000000,93.9385986); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(9241,3242.7744141,-871.1780395,34.3516846,0.0000000,0.0000000,272.0000000); //object(copbits_sfn)(1)
	CreateDynamicObject(17472,3258.5817871,-880.2330322,22.3499794,0.0000000,0.0000000,91.9885254); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3251.6328125,-870.2872925,15.5999794,0.0000000,0.0000000,91.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3252.4970703,-876.5829468,15.5999794,0.0000000,0.0000000,91.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3242.9992676,-866.7057495,15.5999794,0.0000000,0.0000000,79.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3238.2722168,-867.1654663,15.5999794,0.0000000,0.0000000,79.9804688); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3233.5446777,-867.6254273,15.5999794,0.0000000,0.0000000,79.9804688); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3230.3098144,-867.9400024,14.8499794,0.0000000,0.0000000,79.9804688); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3245.6064453,-881.0988769,18.8499794,0.0000000,0.0000000,1.9830322); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(17472,3237.1728516,-882.4135132,17.3499794,0.0000000,0.0000000,1.9775391); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(11491,3472.1164551,-659.7227173,30.0756836,0.0000000,0.0000000,184.7500000); //object(des_ranchbits1)(1)
	CreateDynamicObject(11490,3472.9392090,-670.5910644,28.5756874,0.0000000,0.0000000,184.0000000); //object(des_ranch)(1)
	CreateDynamicObject(7917,3604.6198731,-647.9411621,28.5914059,0.0000000,0.0000000,271.4971924); //object(vegasglfhse2)(1)
	CreateDynamicObject(3361,3223.4106445,-885.1347656,31.5247212,0.0000000,0.0000000,90.0000000); //object(cxref_woodstair)(2)
	CreateDynamicObject(3361,3223.3625488,-892.7625732,31.5247212,0.0000000,0.0000000,270.0000000); //object(cxref_woodstair)(3)
	CreateDynamicObject(3361,3223.3554688,-898.9898071,27.3747349,0.0000000,0.0000000,270.0000000); //object(cxref_woodstair)(4)
	CreateDynamicObject(17472,3122.2998047,-851.9833984,9.2599983,0.0000000,349.9969482,125.9893799); //object(cunt_rocgxp2_04)(7)
	CreateDynamicObject(1637,3065.9975586,-934.3557129,16.1583672,0.0000000,0.0000000,181.7500000); //object(od_pat_hutb)(1)
	CreateDynamicObject(1637,3065.5771484,-922.2595215,16.1583672,0.0000000,0.0000000,182.9978027); //object(od_pat_hutb)(2)
	CreateDynamicObject(1637,3245.6936035,-821.6668701,24.0783272,0.0000000,0.0000000,357.9968262); //object(od_pat_hutb)(3)
	CreateDynamicObject(1637,3245.6154785,-833.8582764,24.1283264,0.0000000,0.0000000,357.9949951); //object(od_pat_hutb)(4)
	CreateDynamicObject(3361,3235.3713379,-846.2027588,31.4497223,0.0000000,0.0000000,0.0000000); //object(cxref_woodstair)(5)
	CreateDynamicObject(3361,3227.6181641,-846.2041016,31.4497223,0.0000000,0.0000000,180.0000000); //object(cxref_woodstair)(6)
	CreateDynamicObject(3361,3241.5747070,-846.2103882,27.3047619,0.0000000,0.0000000,0.0000000); //object(cxref_woodstair)(7)
	CreateDynamicObject(3361,3247.6235352,-846.2075806,23.2547474,0.0000000,0.0000000,0.0000000); //object(cxref_woodstair)(8)
	CreateDynamicObject(1641,2983.1955566,-890.0159912,1.6931696,15.0000000,0.0000000,274.0000000); //object(beachtowel03)(1)
	CreateDynamicObject(1641,3016.4052734,-887.7421875,7.7333398,0.0000000,0.0000000,0.0000000); //object(beachtowel03)(2)
	CreateDynamicObject(1641,2983.4799805,-893.7544556,1.5431697,14.9963379,0.0000000,269.9990234); //object(beachtowel03)(3)
	CreateDynamicObject(1641,3360.8972168,-872.6650391,1.4681698,13.9908447,0.0000000,99.9945068); //object(beachtowel03)(4)
	CreateDynamicObject(1641,3360.6635742,-868.1705322,1.3181699,13.9855957,0.0000000,91.9920654); //object(beachtowel03)(5)
	CreateDynamicObject(2404,3359.5830078,-872.8765869,2.8987865,0.0000000,0.0000000,101.0000000); //object(cj_surf_board)(1)
	CreateDynamicObject(2404,3359.3256836,-868.2408447,2.7237859,0.0000000,0.0000000,90.9973145); //object(cj_surf_board)(2)
	CreateDynamicObject(2404,2984.7114258,-889.8352051,3.1237874,0.0000000,0.0000000,278.9942627); //object(cj_surf_board)(3)
	CreateDynamicObject(2404,2983.5197754,-892.6741943,1.5737865,284.7500000,0.0000000,270.9923096); //object(cj_surf_board)(4)
	CreateDynamicObject(6295,3461.2678223,-1047.5549316,29.9941769,0.0000000,0.0000000,0.0000000); //object(sanpedlithus_law2)(1)
	CreateDynamicObject(3091,3708.9807129,-597.4868774,29.2327576,0.0000000,0.0000000,0.0000000); //object(imy_track_barrier)(1)
	CreateDynamicObject(3091,3723.8842773,-597.7544556,29.2077580,0.0000000,0.0000000,0.0000000); //object(imy_track_barrier)(2)
	CreateDynamicObject(8865,3603.5314941,-619.1790772,28.8133755,0.0000000,0.0000000,271.5000000); //object(vgeplntr07_lvs)(1)
	CreateDynamicObject(8865,3472.1677246,-648.3576050,28.8133755,0.0000000,0.0000000,274.9996338); //object(vgeplntr07_lvs)(2)
	CreateDynamicObject(8865,3398.3410644,-654.1006470,28.8133755,0.0000000,0.0000000,271.9996338); //object(vgeplntr07_lvs)(3)
	CreateDynamicObject(8240,3179.9345703,274.0191650,-13.5818386,0.0000000,90.0000000,181.7413330); //object(vgssbighanger1)(6)
	CreateDynamicObject(8240,3193.4345703,274.0185547,-13.5818386,0.0000000,90.0000000,181.7413330); //object(vgssbighanger1)(6)
	CreateDynamicObject(8240,3160.5236816,252.7685547,-13.5818386,0.0000000,90.0000000,181.7413330); //object(vgssbighanger1)(6)

	// AIR BAZA ID:4
	CreateDynamicObject(4866,-2127.8000488,1731.4000244,0.7000000,0.0000000,0.0000000,0.0000000); //object(lasrnway1_las)(1)
	CreateDynamicObject(8251,-2213.3000488,1726.4000244,4.5999999,0.0000000,0.0000000,270.0000000); //object(pltschlhnger02_lvs)(1)
	CreateDynamicObject(8251,-2262.6999512,1687.4000244,4.5999999,0.0000000,0.0000000,0.0000000); //object(pltschlhnger02_lvs)(2)
	CreateDynamicObject(8251,-2107.3000488,1727.5000000,4.5999999,0.0000000,0.0000000,270.0000000); //object(pltschlhnger02_lvs)(3)
	CreateDynamicObject(9241,-1998.6999512,1764.6999512,2.3000000,0.0000000,0.0000000,0.0000000); //object(copbits_sfn)(1)
	CreateDynamicObject(9241,-2116.6999512,1763.5000000,2.2000000,0.0000000,0.0000000,0.0000000); //object(copbits_sfn)(3)
	CreateDynamicObject(10810,-2155.8000488,1725.3000488,5.6999998,0.0000000,0.0000000,290.0000000); //object(ap_smallradar1_sfse)(1)
	CreateDynamicObject(1682,-2154.8000488,1728.8000488,17.2000008,0.0000000,0.0000000,230.0000000); //object(ap_radar1_01)(1)
	CreateDynamicObject(8038,-2250.6000977,1749.5000000,20.7999992,0.0000000,0.0000000,0.0000000); //object(arprtermnl01_lvs)(1)
	CreateDynamicObject(8251,-2004.3000488,1726.4000244,4.5999999,0.0000000,0.0000000,270.0000000); //object(pltschlhnger02_lvs)(5)
	CreateDynamicObject(9241,-2062.1000977,1763.5999756,2.2000000,0.0000000,0.0000000,0.0000000); //object(copbits_sfn)(4)
	CreateDynamicObject(8550,-2152.6999512,1765.5999756,4.9000001,0.0000000,0.0000000,0.0000000); //object(laconcha_lvs)(1)
	CreateDynamicObject(3666,-2248.1999512,1702.3000488,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(1)
	CreateDynamicObject(3666,-2248.1000977,1671.5000000,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(2)
	CreateDynamicObject(3666,-2244.8999023,1713.8000488,41.4000015,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(3)
	CreateDynamicObject(3666,-2253.6999512,1713.6999512,41.4000015,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(4)
	CreateDynamicObject(3666,-2253.8000488,1722.8000488,41.4000015,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(5)
	CreateDynamicObject(3666,-2244.8999023,1722.6999512,41.4000015,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(6)
	CreateDynamicObject(3666,-2216.8000488,1669.5000000,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(7)
	CreateDynamicObject(3666,-2216.8000488,1705.4000244,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(8)
	CreateDynamicObject(3666,-2173.3000488,1705.0000000,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(9)
	CreateDynamicObject(3666,-2173.3000488,1669.4000244,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(10)
	CreateDynamicObject(3666,-2130.8000488,1704.5999756,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(11)
	CreateDynamicObject(3666,-2130.8999023,1669.5999756,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(12)
	CreateDynamicObject(3666,-2084.6000977,1704.6999512,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(13)
	CreateDynamicObject(3666,-2084.3999023,1669.9000244,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(14)
	CreateDynamicObject(3666,-2032.1999512,1704.9000244,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(15)
	CreateDynamicObject(3666,-2033.6999512,1669.9000244,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(16)
	CreateDynamicObject(3666,-1986.0000000,1669.6999512,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(17)
	CreateDynamicObject(3666,-1988.4000244,1704.6999512,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(18)
	CreateDynamicObject(3666,-1971.6999512,1670.0000000,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(19)
	CreateDynamicObject(3666,-1971.6999512,1704.5000000,1.2000000,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(20)
	CreateDynamicObject(1290,-1991.0000000,1713.0999756,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(1)
	CreateDynamicObject(1290,-2017.5000000,1713.4000244,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(2)
	CreateDynamicObject(1290,-2059.6000977,1713.6999512,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(4)
	CreateDynamicObject(1290,-2093.8999023,1714.5000000,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(5)
	CreateDynamicObject(1290,-2120.5000000,1714.5000000,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(6)
	CreateDynamicObject(1290,-2141.8000488,1714.8000488,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(7)
	CreateDynamicObject(1290,-2168.3999023,1714.8000488,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(8)
	CreateDynamicObject(1290,-2200.0000000,1713.4000244,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(9)
	CreateDynamicObject(1290,-2226.3999023,1713.5999756,6.6999998,0.0000000,0.0000000,0.0000000); //object(lamppost2)(10)
	CreateDynamicObject(1290,-2249.6000977,1701.0000000,6.6999998,0.0000000,0.0000000,90.0000000); //object(lamppost2)(11)
	CreateDynamicObject(1290,-2250.1999512,1673.3000488,6.6999998,0.0000000,0.0000000,90.0000000); //object(lamppost2)(12)
	CreateDynamicObject(1337,-2275.1357422,1686.3183594,3.2026539,0.0000000,0.0000000,0.0000000); //object(binnt07_la)(2)
	CreateDynamicObject(10079,-2243.5000000,1716.3000488,26.0000000,0.0000000,0.0000000,224.0000000); //object(pyr_top_sfe)(1)
	
	// AIRLINE BAZA ID:5
	CreateDynamicObject(3998,829.4685669,-480.9060974,6.5336904,0.0000000,0.0000000,0.4251404); //object(court1_lan)(1)
	CreateDynamicObject(3998,803.9253540,-481.1015625,6.5336904,0.0000000,0.0000000,0.4251404); //object(court1_lan)(2)
	CreateDynamicObject(3998,808.4554443,-469.0880432,6.5336904,0.0000000,0.0000000,2.4629822); //object(court1_lan)(3)
	CreateDynamicObject(3998,783.0306397,-470.1553345,6.5336904,0.0000000,0.0000000,2.4609375); //object(court1_lan)(4)
	CreateDynamicObject(3998,779.6371460,-481.2492676,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(5)
	CreateDynamicObject(3998,754.0800171,-481.4479370,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(6)
	CreateDynamicObject(3998,744.5541382,-481.5240784,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(7)
	CreateDynamicObject(3998,782.1694336,-449.2991333,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(8)
	CreateDynamicObject(3998,782.0134888,-427.7057800,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(9)
	CreateDynamicObject(3998,781.8552246,-406.1354981,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(10)
	CreateDynamicObject(3998,781.6977539,-384.5597534,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(11)
	CreateDynamicObject(3998,781.5401001,-363.0014648,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(12)
	CreateDynamicObject(3998,781.3824463,-341.6583252,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(13)
	CreateDynamicObject(3998,781.2089844,-320.1005859,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(14)
	CreateDynamicObject(3998,768.1182861,-396.0388794,6.5336904,0.0000000,0.0000000,90.3738403); //object(court1_lan)(16)
	CreateDynamicObject(3998,749.3297730,-461.5427856,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(17)
	CreateDynamicObject(3998,744.3833008,-461.6264343,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(18)
	CreateDynamicObject(16010,832.6701050,-462.1860046,23.2529983,0.0000000,0.0000000,180.3961182); //object(des_reslab_)(1)
	CreateDynamicObject(7586,833.0424805,-462.8167725,37.8765297,0.0000000,0.0000000,0.0000000); //object(miragebuild07)(1)
	CreateDynamicObject(8345,820.8807983,-464.3894043,23.6574001,0.0000000,0.0000000,302.1715088); //object(gatesb_lvs01)(1)
	CreateDynamicObject(7981,842.0561523,-395.9432373,35.1877098,0.0000000,346.8240356,0.0000000); //object(smallradar02_lvs)(1)
	CreateDynamicObject(1682,843.9263306,-393.7641602,46.9310379,3.0019836,346.6098633,0.7142639); //object(ap_radar1_01)(1)
	CreateDynamicObject(2797,809.8473511,-462.7254028,24.5005722,0.0000000,0.0000000,90.4233704); //object(cj_air_d_5)(1)
	CreateDynamicObject(2792,811.6471558,-479.7546082,28.6214390,0.0000000,0.0000000,90.3096924); //object(cj_air_d_1)(1)
	CreateDynamicObject(2792,793.3881836,-475.8564453,26.1255970,0.0000000,0.0000000,1.7933350); //object(cj_air_d_1)(2)
	CreateDynamicObject(2775,814.9561768,-463.1277161,22.8642654,0.0000000,0.0000000,269.8162842); //object(cj_airprt_mon)(1)
	CreateDynamicObject(3658,814.8417969,-468.9910889,20.3905354,0.0000000,0.0000000,90.1376648); //object(airlastrola_las)(1)
	CreateDynamicObject(3659,814.8340454,-458.2341614,20.7922497,0.0000000,0.0000000,272.4092102); //object(airfinfoa_las)(1)
	CreateDynamicObject(8038,864.0771484,-460.8070068,42.7227020,0.0000000,0.0000000,271.7714233); //object(arprtermnl01_lvs)(1)
	CreateDynamicObject(3998,746.5349121,-396.1838379,6.5336904,0.0000000,0.0000000,90.3735352); //object(court1_lan)(19)
	CreateDynamicObject(3998,739.0662842,-410.1231079,6.5336904,0.0000000,0.0000000,180.4348145); //object(court1_lan)(20)
	CreateDynamicObject(3998,721.9318237,-410.2549744,6.5336904,0.0000000,0.0000000,180.4339600); //object(court1_lan)(21)
	CreateDynamicObject(3998,729.6583862,-396.3170776,6.5336904,0.0000000,0.0000000,90.3735352); //object(court1_lan)(22)
	CreateDynamicObject(3998,708.0739746,-396.4552612,6.5336904,0.0000000,0.0000000,90.3735352); //object(court1_lan)(23)
	CreateDynamicObject(8253,700.0429688,-396.3242188,23.5756454,0.0000000,0.0000000,0.2856445); //object(pltschlhnger01_lvs)(2)
	CreateDynamicObject(3613,742.4667358,-436.0708923,18.7792549,0.0000000,0.0000000,270.7871094); //object(hillhouse10_la)(1)
	CreateDynamicObject(3578,787.6333008,-315.4636536,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(12)
	CreateDynamicObject(3578,780.1735840,-305.7115478,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(16)
	CreateDynamicObject(3578,779.6607056,-305.7098389,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(17)
	CreateDynamicObject(3578,779.1527100,-305.7112122,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(18)
	CreateDynamicObject(3578,780.2359619,-315.4799499,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(19)
	CreateDynamicObject(3578,779.7216797,-315.4833984,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(20)
	CreateDynamicObject(3578,779.2133789,-315.4874878,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(21)
	CreateDynamicObject(3578,775.2319946,-300.8454895,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(22)
	CreateDynamicObject(3578,775.2348023,-301.3574829,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(23)
	CreateDynamicObject(3578,775.2382812,-301.8575745,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(24)
	CreateDynamicObject(3578,770.3963013,-305.7962952,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,770.9085693,-305.7929688,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(26)
	CreateDynamicObject(3578,771.4151611,-305.7907410,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(27)
	CreateDynamicObject(3578,775.3008423,-310.6512146,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(28)
	CreateDynamicObject(3578,775.2988281,-310.1468201,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(29)
	CreateDynamicObject(3578,775.3021240,-309.6694946,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,775.3551025,-320.4115601,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(31)
	CreateDynamicObject(3578,775.3503418,-319.9033814,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(32)
	CreateDynamicObject(3578,775.3452148,-319.4043884,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,781.9483643,-430.7671814,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,777.0273438,-425.8437500,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3998,758.6257324,-471.7240906,6.5336904,0.0000000,0.0000000,0.4229736); //object(court1_lan)(24)
	CreateDynamicObject(3578,769.2272949,-326.4721069,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(61)
	CreateDynamicObject(3578,769.2991943,-336.7466736,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(62)
	CreateDynamicObject(3578,769.3703003,-347.0380249,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(63)
	CreateDynamicObject(3578,769.4426269,-357.3341370,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(64)
	CreateDynamicObject(3578,769.5153198,-367.6255798,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(65)
	CreateDynamicObject(3578,769.5869751,-377.9232178,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(66)
	CreateDynamicObject(3578,769.7108765,-396.4686890,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(68)
	CreateDynamicObject(3578,769.8372803,-414.0155640,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(69)
	CreateDynamicObject(3578,769.8665161,-418.7733765,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(70)
	CreateDynamicObject(3578,792.8914185,-326.4691467,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(71)
	CreateDynamicObject(3578,792.9639893,-336.7536316,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(72)
	CreateDynamicObject(3578,793.0341186,-347.0248108,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(73)
	CreateDynamicObject(3578,793.1039429,-357.3183899,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(74)
	CreateDynamicObject(3578,793.1762085,-367.5426941,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(75)
	CreateDynamicObject(3578,793.2457275,-377.6547852,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(76)
	CreateDynamicObject(3578,793.3156128,-387.9494019,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(77)
	CreateDynamicObject(3578,793.3840942,-398.2257996,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(78)
	CreateDynamicObject(3578,793.4553223,-408.5024109,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(79)
	CreateDynamicObject(3578,793.5241089,-418.3883972,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(80)
	CreateDynamicObject(3578,781.8327026,-408.2176209,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(82)
	CreateDynamicObject(3578,781.6929932,-387.8009644,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(84)
	CreateDynamicObject(3578,781.5516968,-367.4675903,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(86)
	CreateDynamicObject(3578,781.4112549,-347.0491943,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(88)
	CreateDynamicObject(3578,781.2696533,-326.5825806,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(90)
	CreateDynamicObject(4642,789.4738159,-323.8357544,18.1045876,0.0000000,0.0000000,90.7023010); //object(paypark_lan)(1)
	CreateDynamicObject(4642,785.9720459,-323.8163757,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(2)
	CreateDynamicObject(4642,772.5317993,-323.7361450,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(3)
	CreateDynamicObject(4642,775.9899902,-323.6633301,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(4)
	CreateDynamicObject(4642,773.4626465,-410.7344360,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(5)
	CreateDynamicObject(4642,777.0044556,-410.6802978,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(6)
	CreateDynamicObject(4642,789.4840088,-410.7451477,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(7)
	CreateDynamicObject(4642,786.0809326,-410.7272644,18.1045876,0.0000000,0.0000000,90.6976318); //object(paypark_lan)(8)
	CreateDynamicObject(8843,781.7819824,-422.5589905,19.7770042,0.1019898,0.0000000,0.0000000); //object(arrows01_lvs)(1)
	CreateDynamicObject(3578,780.7333984,-453.5095825,19.0076027,0.0000000,0.0000000,90.4678955); //object(dockbarr1_la)(91)
	CreateDynamicObject(3578,785.2810669,-460.5409851,19.0076027,0.0000000,0.0000000,335.6482239); //object(dockbarr1_la)(93)
	CreateDynamicObject(3578,794.8256226,-464.2706604,19.0076027,0.0000000,0.0000000,341.8147278); //object(dockbarr1_la)(94)
	CreateDynamicObject(3578,804.7377319,-465.8044128,19.0076027,0.0000000,0.0000000,0.7835693); //object(dockbarr1_la)(95)
	CreateDynamicObject(3578,809.6530151,-465.6913147,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(96)
	CreateDynamicObject(3578,780.8084106,-463.5362244,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(98)
	CreateDynamicObject(3578,780.8829956,-473.8121643,19.0076027,0.0000000,0.0000000,90.4669189); //object(dockbarr1_la)(99)
	CreateDynamicObject(3578,780.7983398,-479.0477600,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(100)
	CreateDynamicObject(3578,775.8403320,-460.0947266,19.0076027,0.0000000,0.0000000,16.9240723); //object(dockbarr1_la)(101)
	CreateDynamicObject(3578,766.3500366,-462.9673767,19.0076027,0.0000000,0.0000000,16.9189453); //object(dockbarr1_la)(102)
	CreateDynamicObject(3578,761.6495361,-469.3414612,19.0076027,0.0000000,0.0000000,90.2903748); //object(dockbarr1_la)(103)
	CreateDynamicObject(3578,761.6610107,-475.7958679,19.0076027,0.0000000,0.0000000,90.2856445); //object(dockbarr1_la)(104)
	CreateDynamicObject(3578,761.8873291,-480.6319275,19.0076027,0.0000000,0.0000000,181.3142090); //object(dockbarr1_la)(105)
	CreateDynamicObject(3578,756.4751587,-464.3648377,19.0076027,0.0000000,0.0000000,179.2557373); //object(dockbarr1_la)(106)
	CreateDynamicObject(3578,746.2246094,-464.2011719,19.0076027,0.0000000,0.0000000,179.2529297); //object(dockbarr1_la)(107)
	CreateDynamicObject(3578,741.2150879,-469.0597229,19.0076027,0.0000000,0.0000000,268.9671631); //object(dockbarr1_la)(108)
	CreateDynamicObject(3578,741.0736694,-474.6411438,19.0076027,0.0000000,0.0000000,268.9617920); //object(dockbarr1_la)(109)
	CreateDynamicObject(3578,741.1506958,-479.6935730,19.0076027,0.0000000,0.0000000,179.2557373); //object(dockbarr1_la)(110)
	CreateDynamicObject(3578,741.4080810,-458.8924561,19.0076027,0.0000000,0.0000000,268.9617920); //object(dockbarr1_la)(111)
	CreateDynamicObject(3578,741.5869141,-449.3386231,19.0076027,0.0000000,0.0000000,268.9617920); //object(dockbarr1_la)(112)
	CreateDynamicObject(3578,741.5651856,-444.4605713,19.0076027,0.0000000,0.0000000,1.3046570); //object(dockbarr1_la)(113)
	CreateDynamicObject(3578,762.8194580,-395.9197693,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(114)
	CreateDynamicObject(3578,752.5198975,-395.9989624,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(115)
	CreateDynamicObject(3578,742.2575073,-396.0715942,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(116)
	CreateDynamicObject(3578,732.0573120,-396.1487427,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(117)
	CreateDynamicObject(3578,721.7670288,-396.2223206,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(118)
	CreateDynamicObject(3578,764.6517944,-395.7493591,19.0076027,0.0000000,0.0000000,91.2482300); //object(dockbarr1_la)(119)
	CreateDynamicObject(3578,765.7844238,-395.7518005,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(120)
	CreateDynamicObject(3578,766.9172363,-395.7537537,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(121)
	CreateDynamicObject(3578,767.9628906,-395.7554932,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(122)
	CreateDynamicObject(3578,764.8006592,-402.7770691,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(123)
	CreateDynamicObject(3578,765.9340820,-402.7542114,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(124)
	CreateDynamicObject(3578,767.0632324,-402.7390747,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(125)
	CreateDynamicObject(3578,768.1152344,-402.7250366,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(126)
	CreateDynamicObject(3578,767.8359375,-389.4342041,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(127)
	CreateDynamicObject(3578,766.7828369,-389.4857178,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(128)
	CreateDynamicObject(3578,765.6543579,-389.4791565,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(129)
	CreateDynamicObject(3578,764.5228272,-389.5443420,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(130)
	CreateDynamicObject(3578,781.0045776,-448.6054688,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(131)
	CreateDynamicObject(3578,780.9636231,-449.6502686,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(132)
	CreateDynamicObject(3578,740.6314697,-401.3750305,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(133)
	CreateDynamicObject(3578,740.8416748,-411.5187073,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(134)
	CreateDynamicObject(3578,741.0545654,-421.7988892,19.0076027,0.0000000,0.0000000,91.2469482); //object(dockbarr1_la)(135)
	CreateDynamicObject(3578,741.2622070,-426.6866150,19.0076027,0.0000000,0.0000000,182.5611725); //object(dockbarr1_la)(136)
	CreateDynamicObject(3578,723.5435791,-401.8823853,19.0076027,0.0000000,0.0000000,73.7612000); //object(dockbarr1_la)(137)
	CreateDynamicObject(3578,722.0377197,-411.8562317,19.0076027,0.0000000,0.0000000,89.1870117); //object(dockbarr1_la)(138)
	CreateDynamicObject(3578,721.8814087,-421.9131165,19.0076027,0.0000000,0.0000000,89.1870117); //object(dockbarr1_la)(139)
	CreateDynamicObject(3578,721.9461670,-426.9758606,19.0076027,0.0000000,0.0000000,181.2441406); //object(dockbarr1_la)(140)
	CreateDynamicObject(982,751.9678955,-421.8369141,20.4605598,0.0000000,0.0000000,0.1923218); //object(fenceshit)(1)
	CreateDynamicObject(982,751.6699219,-383.4599609,20.4605598,0.0000000,0.0000000,90.4779053); //object(fenceshit)(3)
	CreateDynamicObject(982,726.0615234,-383.6757812,20.4605598,0.0000000,0.0000000,90.4779053); //object(fenceshit)(4)
	CreateDynamicObject(982,731.4001465,-443.5422058,20.4574737,0.0000000,0.0000000,0.6002502); //object(fenceshit)(5)
	CreateDynamicObject(982,731.6627808,-469.1562805,20.4574737,0.0000000,0.0000000,0.5987549); //object(fenceshit)(6)
	CreateDynamicObject(982,744.6345215,-481.8719177,20.4605598,0.0000000,0.0000000,90.4779053); //object(fenceshit)(7)
	CreateDynamicObject(982,770.2524414,-481.6581421,20.4605598,0.0000000,0.0000000,90.4779053); //object(fenceshit)(8)
	CreateDynamicObject(982,795.8645630,-481.4525147,20.4605598,0.0000000,0.0000000,90.4779053); //object(fenceshit)(9)
	CreateDynamicObject(982,821.4785767,-481.2351074,20.4605598,0.0000000,0.0000000,90.4779053); //object(fenceshit)(10)
	CreateDynamicObject(984,758.3565064,-408.9850464,20.4136848,0.0000000,0.0000000,270.3962402); //object(fenceshit2)(1)
	CreateDynamicObject(984,755.4794922,-440.9609375,20.4136848,0.0000000,0.0000000,270.3955078); //object(fenceshit2)(3)
	CreateDynamicObject(983,765.1636963,-451.1232300,20.4605598,0.0000000,0.0000000,90.5714722); //object(fenceshit3)(1)
	CreateDynamicObject(983,799.0205078,-448.9541016,20.4245567,0.0000000,0.0000000,92.3016357); //object(fenceshit3)(2)
	CreateDynamicObject(984,805.4033203,-448.7128906,20.3750267,0.0000000,0.0000000,272.0324707); //object(fenceshit2)(4)
	CreateDynamicObject(983,761.9323731,-447.9258423,20.4605598,0.0000000,0.0000000,180.5135498); //object(fenceshit3)(3)
	CreateDynamicObject(983,761.8910523,-444.1369934,20.4605598,0.0000000,0.0000000,180.5108643); //object(fenceshit3)(4)
	CreateDynamicObject(984,724.8585815,-430.7521057,20.4136848,0.0000000,0.0000000,270.3954468); //object(fenceshit2)(5)
	CreateDynamicObject(984,717.9802856,-430.8077393,20.4136848,0.0000000,0.0000000,270.3955078); //object(fenceshit2)(6)
	CreateDynamicObject(984,709.2711792,-415.1849365,20.4136848,0.0000000,0.0000000,0.3377991); //object(fenceshit2)(7)
	CreateDynamicObject(984,709.3267822,-424.7728882,20.4136848,0.0000000,0.0000000,0.3350830); //object(fenceshit2)(8)
	CreateDynamicObject(982,780.9625855,-299.2196045,20.2145386,0.0000000,38.9714356,90.4779053); //object(fenceshit)(12)
	CreateDynamicObject(982,767.8070068,-312.5180969,20.1086998,0.0000000,56.1714172,180.4201508); //object(fenceshit)(13)
	CreateDynamicObject(982,767.9990234,-338.1366577,20.1086998,0.0000000,56.1676025,180.4174805); //object(fenceshit)(14)
	CreateDynamicObject(982,768.1868897,-363.7444153,20.1086998,0.0000000,56.1676025,180.4174805); //object(fenceshit)(15)
	CreateDynamicObject(982,768.6005859,-421.7132263,20.1086998,0.0000000,56.1676025,180.4174805); //object(fenceshit)(16)
	CreateDynamicObject(982,768.7163696,-438.1903076,20.1086998,0.0000000,56.1676025,180.4174805); //object(fenceshit)(17)
	CreateDynamicObject(982,795.2487793,-436.3002319,20.1086998,0.0000000,56.1676025,0.3886108); //object(fenceshit)(18)
	CreateDynamicObject(982,795.0728149,-410.6892395,20.1086998,0.0000000,56.1621094,0.3845215); //object(fenceshit)(20)
	CreateDynamicObject(982,794.9100342,-385.0669251,20.1086998,0.0000000,56.1621094,0.3845215); //object(fenceshit)(21)
	CreateDynamicObject(982,794.7416992,-359.4498596,20.1086998,0.0000000,56.1621094,0.3845215); //object(fenceshit)(22)
	CreateDynamicObject(982,794.5830078,-333.8300171,20.1086998,0.0000000,56.1621094,0.3845215); //object(fenceshit)(23)
	CreateDynamicObject(982,794.4216919,-312.2423401,20.1086998,0.0000000,56.1621094,0.3845215); //object(fenceshit)(24)
	CreateDynamicObject(982,768.2354126,-370.1439514,20.1086998,0.0000000,56.1676025,180.4174805); //object(fenceshit)(25)
	CreateDynamicObject(10764,781.4169922,-274.4033203,16.8471470,0.0000000,0.0000000,225.5273438); //object(app_light_sfs05e)(2)
	CreateDynamicObject(3526,793.4757690,-322.9953613,19.8454227,0.0000000,0.0000000,270.7428589); //object(vegasairportlight)(1)
	CreateDynamicObject(3526,768.5534058,-323.1413879,19.8454227,0.0000000,0.0000000,270.7415772); //object(vegasairportlight)(2)
	CreateDynamicObject(3526,781.2269898,-309.8033447,19.8454227,0.0000000,0.0000000,270.7415772); //object(vegasairportlight)(3)
	CreateDynamicObject(3526,769.0303955,-382.7933044,19.8454227,0.0000000,0.0000000,270.7415772); //object(vegasairportlight)(4)
	CreateDynamicObject(3526,793.7355347,-382.7418823,19.8454227,0.0000000,0.0000000,270.7415772); //object(vegasairportlight)(5)
	CreateDynamicObject(3526,794.3956909,-448.8159790,19.8454227,0.0000000,0.0000000,270.7415772); //object(vegasairportlight)(6)
	CreateDynamicObject(3526,769.5733032,-450.7842712,19.8454227,0.0000000,0.0000000,270.7415772); //object(vegasairportlight)(7)
	CreateDynamicObject(3526,768.5603027,-323.5020752,19.8454227,0.0000000,0.0000000,90.7673645); //object(vegasairportlight)(8)
	CreateDynamicObject(3526,793.4902344,-323.3613281,19.8454227,0.0000000,0.0000000,90.7635498); //object(vegasairportlight)(9)
	CreateDynamicObject(3526,769.0444336,-383.1551514,19.8454227,0.0000000,0.0000000,90.7635498); //object(vegasairportlight)(10)
	CreateDynamicObject(3526,793.7510376,-383.1040344,19.8454227,0.0000000,0.0000000,90.7635498); //object(vegasairportlight)(11)
	CreateDynamicObject(3666,793.7097778,-299.5833740,20.2906895,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(1)
	CreateDynamicObject(3666,768.2646484,-299.7341309,20.2906895,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(2)
	CreateDynamicObject(3666,782.9953003,-538.7577515,28.3228397,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(3)
	CreateDynamicObject(3877,780.7979736,-171.5776062,28.3420219,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(1)
	CreateDynamicObject(3877,795.4375000,-476.6855469,26.1392956,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(2)
	CreateDynamicObject(3877,703.0468750,-396.4179688,28.8955002,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(3)
	CreateDynamicObject(3877,773.0146484,47.0551834,69.4497986,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(4)
	CreateDynamicObject(3877,746.2594605,-92.7897568,100.7641525,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(5)
	CreateDynamicObject(3877,827.0229492,-73.5390015,80.7771606,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(6)
	CreateDynamicObject(3877,832.7267456,-462.6494446,63.7478180,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(7)
	CreateDynamicObject(3877,796.0610962,-626.4496460,27.8941498,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(8)
	CreateDynamicObject(3877,801.0037842,-697.8676148,65.6472015,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(9)
	CreateDynamicObject(3877,396.1918030,-552.5374756,142.9863586,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(10)
	CreateDynamicObject(3877,714.0732422,-803.9531250,70.8083115,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(11)
	CreateDynamicObject(3578,723.8076782,-400.9899292,19.0076027,0.0000000,0.0000000,73.7567139); //object(dockbarr1_la)(141)
	CreateDynamicObject(973,729.3856811,-478.9814453,16.1581554,0.0000000,0.0000000,121.9004822); //object(sub_roadbarrier)(1)
	CreateDynamicObject(973,648.0877685,-414.3170471,16.1461544,0.0000000,0.3059998,123.7347412); //object(sub_roadbarrier)(2)
	CreateDynamicObject(973,650.8863525,-421.1091614,16.1761570,0.0000000,0.3021240,100.9335327); //object(sub_roadbarrier)(3)
	CreateDynamicObject(973,642.5015869,-408.7567749,16.1341534,0.0000000,0.2966309,146.2782593); //object(sub_roadbarrier)(4)
	CreateDynamicObject(5820,707.6923828,-432.3466797,16.2905884,0.0000000,0.0000000,359.4891357); //object(odrampbit02)(3)
	CreateDynamicObject(5820,749.8341065,-442.6737061,22.9813957,0.0000000,0.0000000,0.0000000); //object(odrampbit02)(4)
	CreateDynamicObject(9241,671.2395630,-407.4634094,17.2696419,0.0000000,0.0000000,0.0000000); //object(copbits_sfn)(1)
	CreateDynamicObject(3934,744.8975220,-435.4265137,26.5040398,0.0000000,0.0000000,89.5428772); //object(helipad01)(1)
	CreateDynamicObject(3876,729.6836548,-475.5320740,2.1791155,0.0000000,0.0000000,16.6286621); //object(sf_roofmast)(1)
	CreateDynamicObject(1557,742.6962891,-441.7081909,19.7577324,0.0000000,358.9714356,180.6936798); //object(gen_doorext19)(1)
	CreateDynamicObject(1557,739.8014526,-441.7468567,19.7577324,0.0000000,358.9672852,359.9492798); //object(gen_doorext19)(2)
	CreateDynamicObject(3264,652.7825317,-420.5955505,15.1607876,0.0000000,0.0000000,277.2000122); //object(privatesign3)(1)
	CreateDynamicObject(3264,644.9013061,-406.1252747,15.1607876,0.0000000,0.0000000,277.1960449); //object(privatesign3)(2)
	CreateDynamicObject(3264,657.7048340,-373.4502869,19.4399662,0.0000000,0.0000000,238.9674377); //object(privatesign3)(3)
	CreateDynamicObject(3264,738.1207275,-308.8758240,6.5729408,0.0000000,0.0000000,252.0493469); //object(privatesign3)(4)
	CreateDynamicObject(3264,735.2272949,-273.2353516,8.5548000,0.0000000,0.0000000,258.2197876); //object(privatesign3)(5)
	CreateDynamicObject(3264,823.3132935,-330.1672363,25.0394688,0.0000000,0.0000000,164.3885498); //object(privatesign3)(6)
	CreateDynamicObject(3264,868.5581665,-367.5002441,36.0200996,0.0000000,0.0000000,164.3884277); //object(privatesign3)(7)
	CreateDynamicObject(3264,912.5045166,-522.1203613,30.8090668,0.0000000,0.0000000,49.5312805); //object(privatesign3)(8)
	CreateDynamicObject(3264,893.5639648,-424.8756103,43.9373703,0.0000000,0.0000000,88.2147217); //object(privatesign3)(9)
	CreateDynamicObject(3264,900.3476562,-396.7714844,46.9589462,0.0000000,0.0000000,88.2147217); //object(privatesign3)(10)
	CreateDynamicObject(3264,913.4843750,-465.7783203,44.6895790,0.0000000,0.0000000,97.4707031); //object(privatesign3)(11)
	CreateDynamicObject(2795,741.4490356,-441.7394409,22.6139774,0.0000000,0.0000000,0.0000000); //object(cj_air_d_4)(1)
	CreateDynamicObject(2795,740.8775024,-461.1428833,19.6625843,89.1427002,180.0000000,359.2555847); //object(cj_air_d_4)(3)
	CreateDynamicObject(2792,783.0672607,-459.0787048,19.6618443,89.5428467,0.0000000,64.7037048); //object(cj_air_d_1)(4)
	CreateDynamicObject(2793,780.7737427,-481.6732178,20.9810867,0.0000000,0.0000000,359.4642944); //object(cj_air_d_2)(2)
	CreateDynamicObject(2793,781.2315064,-461.5566711,19.6590767,87.4857178,0.0000000,2.0556946); //object(cj_air_d_2)(3)
	CreateDynamicObject(2794,762.4141846,-481.7840271,21.1585083,0.0000000,0.0000000,0.0000000); //object(cj_air_d_3)(2)
	CreateDynamicObject(2794,762.0710449,-465.8938293,19.6932449,87.4857178,0.0000000,1.0285644); //object(cj_air_d_3)(3)
	CreateDynamicObject(3578,770.5140381,-315.6501770,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(20)
	CreateDynamicObject(3578,770.9827881,-315.6409912,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(20)
	CreateDynamicObject(3578,771.3310547,-315.6342773,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(20)
	CreateDynamicObject(3578,787.5432129,-305.5368957,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(12)
	CreateDynamicObject(3578,787.0499268,-305.5450439,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(12)
	CreateDynamicObject(3578,786.5318603,-305.5658874,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(12)
	CreateDynamicObject(3578,786.6136475,-315.3822327,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(12)
	CreateDynamicObject(3578,787.1217041,-315.3881836,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(12)
	CreateDynamicObject(3578,777.0277100,-426.3555603,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,777.0155029,-426.8616333,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,781.4412842,-430.7925415,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,780.9295654,-430.8181763,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,781.0026245,-440.9797363,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,781.5067139,-440.9738769,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,782.0192261,-440.9685974,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,777.1112671,-445.9079895,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,777.1027222,-445.4055481,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,777.0941773,-444.9035034,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,776.9505615,-436.0011597,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,776.9579468,-436.5086670,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,776.9412231,-435.4953918,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,787.9750366,-425.7620239,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,787.9737549,-426.2740784,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,787.9752197,-426.7900391,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,783.1153565,-430.8755493,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,783.6179199,-430.9217529,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,784.1286011,-430.9382935,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,783.1853027,-440.9498596,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,783.6798096,-440.9475098,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,784.1855469,-440.9416504,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,788.1656494,-445.8108520,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,788.1808472,-445.2969055,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,788.1963501,-444.7893982,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,793.1106567,-440.7860107,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,792.5963745,-440.7948914,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,792.0906372,-440.8207397,19.0076027,0.0000000,0.0000000,90.4614258); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,787.9963989,-435.9609680,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,787.9963379,-436.4417114,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,787.9964600,-436.9220886,19.0076027,0.0000000,0.0000000,0.5053711); //object(dockbarr1_la)(46)
	
	// JOS JEDNA ZRACNA LUKA (Realistic)
	CreateDynamicObject(3998,-241.4462891,-2137.5410156,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(1)
	CreateDynamicObject(3998,-237.2412109,-2158.5625000,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(2)
	CreateDynamicObject(3998,-233.0068359,-2179.6914062,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(3)
	CreateDynamicObject(3998,-228.7714844,-2200.8437500,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(4)
	CreateDynamicObject(3998,-224.5224609,-2221.9248047,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(5)
	CreateDynamicObject(3998,-220.3146667,-2243.1005859,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(6)
	CreateDynamicObject(3998,-216.1237793,-2264.0483398,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(7)
	CreateDynamicObject(3998,-211.9111328,-2285.1210938,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(8)
	CreateDynamicObject(3998,-190.9042969,-2280.9042969,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(9)
	CreateDynamicObject(3998,-194.7322693,-2261.6877441,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(10)
	CreateDynamicObject(3998,-198.6326752,-2242.1293945,15.7874145,0.0000000,0.0000000,11.3104248); //object(court1_lan)(11)
	CreateDynamicObject(3597,-199.0859375,-2293.1972656,32.4035263,0.0000000,0.0000000,190.5688477); //object(dingbat01bex_la)(1)
	CreateDynamicObject(9245,-252.9121094,-2234.8027344,39.4642830,0.0000000,0.0000000,110.4565430); //object(cstguard_sfn01)(1)
	CreateDynamicObject(1681,-199.9011688,-2290.2143555,42.8211403,1.7597046,359.8979492,8.2316894); //object(ap_learjet1_01)(1)
	CreateDynamicObject(16101,-251.8863068,-2239.2719727,32.8470955,0.0000000,0.0000000,0.0000000); //object(des_windsockpole)(1)
	CreateDynamicObject(16368,-251.7689972,-2239.2734375,43.7316742,0.0000000,0.0000000,0.0000000); //object(bonyrd_windsock)(1)
	CreateDynamicObject(2510,-201.2272034,-2281.9108887,33.8839073,0.0000000,0.0000000,188.5141602); //object(model_plane_big2)(1)
	CreateDynamicObject(7981,-279.6911011,-2167.0612793,32.6468582,0.0000000,0.0000000,295.1428528); //object(smallradar02_lvs)(1)
	CreateDynamicObject(1682,-276.9237366,-2169.6616211,44.1010857,0.0000000,0.0000000,0.0000000); //object(ap_radar1_01)(1)
	CreateDynamicObject(2789,-196.7120361,-2281.2197266,34.2197762,0.0000000,359.7959595,190.6240234); //object(cj_depart_board)(1)
	CreateDynamicObject(2790,-205.5636444,-2282.8762207,34.3755264,0.0000000,0.0000000,190.6444244); //object(cj_arrive_board)(1)
	CreateDynamicObject(3286,-248.4145355,-2212.0959473,32.6433640,0.0000000,0.0000000,26.7428589); //object(cxrf_watertwr)(1)
	CreateDynamicObject(3515,-200.3456574,-2285.4765625,32.6634827,0.0000000,0.0000000,358.3680115); //object(vgsfountain)(1)
	CreateDynamicObject(3578,-239.5437622,-2123.3491211,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(4)
	CreateDynamicObject(3578,-244.3091431,-2133.8574219,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(16)
	CreateDynamicObject(3578,-244.7874298,-2133.9592285,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(17)
	CreateDynamicObject(3578,-245.2916412,-2134.0651856,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(18)
	CreateDynamicObject(3578,-250.0908203,-2130.0244141,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(22)
	CreateDynamicObject(3578,-249.9892578,-2130.5273438,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(23)
	CreateDynamicObject(3578,-249.8948669,-2131.0012207,28.2673264,0.0000000,0.0000000,11.3049316); //object(dockbarr1_la)(24)
	CreateDynamicObject(3578,-246.2379150,-2124.4003906,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,-227.1640625,-2210.4472656,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-226.6591797,-2210.3554688,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(38)
	CreateDynamicObject(3578,-226.1550751,-2210.2546387,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(39)
	CreateDynamicObject(3578,-215.5611725,-2218.5541992,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(46)
	CreateDynamicObject(3578,-216.0498047,-2218.6582031,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(47)
	CreateDynamicObject(3578,-216.5548859,-2218.7578125,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(48)
	CreateDynamicObject(3578,-221.3144531,-2214.7109375,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(49)
	CreateDynamicObject(3578,-221.2402344,-2215.1962891,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	CreateDynamicObject(3578,-221.1659699,-2215.6848144,28.2673264,0.0000000,0.0000000,11.3049316); //object(dockbarr1_la)(51)
	CreateDynamicObject(3578,-251.4339142,-2147.6398926,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-249.4461517,-2157.6564941,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-247.4643555,-2167.6840820,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-245.4748840,-2177.7382812,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-243.4884491,-2187.7863769,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-241.5058289,-2197.8530273,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-218.6343231,-2192.8981934,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-220.6350098,-2182.8188477,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-222.6343994,-2172.7314453,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-224.6310272,-2162.6376953,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-226.6107788,-2152.6291504,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-228.5956726,-2142.6162109,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-239.9225922,-2144.6201172,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-235.9375153,-2164.7478027,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-231.9936981,-2184.6816406,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-229.5341034,-2197.7768555,28.2673264,0.0000000,0.4079895,100.7674866); //object(dockbarr1_la)(25)
	CreateDynamicObject(4642,-245.1670380,-2142.3159180,27.3970604,0.0000000,0.0000000,101.6000061); //object(paypark_lan)(1)
	CreateDynamicObject(4642,-247.9524841,-2142.8688965,27.3970604,0.0000000,0.0000000,101.5960693); //object(paypark_lan)(2)
	CreateDynamicObject(4642,-236.4548187,-2140.4912109,27.3970604,0.0000000,0.0000000,101.5960693); //object(paypark_lan)(3)
	CreateDynamicObject(4642,-233.7875977,-2139.9443359,27.3970604,0.0000000,0.0000000,101.5960693); //object(paypark_lan)(4)
	CreateDynamicObject(3998,-243.5283203,-2128.1181641,14.3751288,6.8939209,0.0988770,10.2777100); //object(court1_lan)(1)
	CreateDynamicObject(3578,-221.9026337,-2242.4780273,28.2673264,0.0000000,0.0000000,191.8487701); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-221.7178345,-2243.3466797,28.2673264,0.0000000,0.0000000,191.8487549); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-221.5553589,-2244.3808594,28.2673264,0.0000000,0.0000000,191.8487549); //object(dockbarr1_la)(25)
	CreateDynamicObject(3578,-220.9306030,-2247.4575195,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-218.9367981,-2257.4580078,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-214.3031006,-2265.9155273,28.2673264,0.0000000,0.0000000,136.2488403); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-205.7129517,-2268.5195312,28.2673264,0.0000000,0.0000000,189.9039307); //object(dockbarr1_la)(33)
	CreateDynamicObject(3998,-189.1336060,-2293.1726074,15.7874145,0.0000000,0.0000000,280.8531189); //object(court1_lan)(9)
	CreateDynamicObject(3578,-194.9340820,-2262.6345215,28.2673264,0.0000000,0.0000000,241.9509430); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-194.6305084,-2243.3229981,28.2673264,0.0000000,0.0000000,292.3445740); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-200.7295074,-2235.7463379,28.2673264,0.0000000,0.0000000,325.4263001); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-219.4219513,-2231.5703125,28.2673264,0.0000000,0.0000000,332.3357544); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-209.8933563,-2233.4072266,28.2673264,0.0000000,0.0000000,5.9880676); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-192.6148529,-2253.1110840,28.2673264,0.0000000,0.0000000,270.9510498); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-202.2437134,-2267.9313965,28.2673264,0.0000000,0.0000000,189.8986816); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-177.1649628,-2298.5334473,28.2673264,0.0000000,0.0000000,191.9558105); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-178.1914825,-2293.6123047,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-180.1949463,-2283.4951172,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-183.1308441,-2273.7480469,28.2673264,0.0000000,0.0000000,112.5917358); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-189.0401306,-2265.8662109,28.2673264,0.0000000,0.0000000,141.2859802); //object(dockbarr1_la)(33)
	CreateDynamicObject(3998,-191.2541962,-2249.5456543,15.7874145,0.0000000,0.0000000,280.8151856); //object(court1_lan)(9)
	CreateDynamicObject(3578,-172.1987457,-2251.6770019,28.2673264,0.0000000,0.0000000,281.2359619); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-178.9830475,-2240.8955078,28.2673264,0.0000000,0.0000000,9.0063171); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-177.3749542,-2253.1840820,28.2673264,0.0000000,0.0000000,9.0032959); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-187.4769135,-2255.0610352,28.2673264,0.0000000,0.0000000,12.0890198); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-188.7748261,-2243.6171875,28.2673264,0.0000000,0.0000000,22.3747253); //object(dockbarr1_la)(33)
	CreateDynamicObject(3578,-174.0588989,-2240.3725586,28.2673264,0.0000000,0.0000000,281.2335205); //object(dockbarr1_la)(33)
	CreateDynamicObject(3998,-192.9008636,-2273.1423340,15.7874145,0.0000000,0.0000000,280.8489990); //object(court1_lan)(9)
	CreateDynamicObject(3578,-197.2861481,-2265.3115234,28.2673264,0.0000000,0.0000000,209.7983398); //object(dockbarr1_la)(33)
	CreateDynamicObject(1318,-223.3895264,-2229.4245606,29.0060749,0.0120239,89.7765198,149.3712769); //object(arrow)(1)
	CreateDynamicObject(1318,-214.3354340,-2233.8554688,29.0060749,0.0109863,89.7747192,186.7300720); //object(arrow)(2)
	CreateDynamicObject(1318,-204.4254150,-2233.1464844,29.0060749,0.0054932,89.7693481,147.4737549); //object(arrow)(3)
	CreateDynamicObject(1318,-196.2440185,-2239.3237305,29.0060749,0.0000000,89.7692871,113.0492554); //object(arrow)(4)
	CreateDynamicObject(1318,-192.6397705,-2248.5156250,29.0060749,0.0000000,89.7634277,90.4152222); //object(arrow)(5)
	CreateDynamicObject(1318,-192.8337250,-2258.7795410,29.0060749,0.0000000,89.7585144,63.0079651); //object(arrow)(6)
	CreateDynamicObject(1318,-197.8219605,-2267.1892090,29.0060749,0.0000000,89.7585144,12.7208862); //object(arrow)(7)
	CreateDynamicObject(1318,-211.0550537,-2269.0454102,29.0060749,0.0000000,89.7585144,316.8309631); //object(arrow)(8)
	CreateDynamicObject(1318,-218.0910187,-2261.7709961,29.0060749,0.0000000,89.7585144,280.8292236); //object(arrow)(9)
	CreateDynamicObject(984,-169.7934265,-2290.6555176,29.6674080,0.0000000,0.0000000,11.2355957); //object(fenceshit2)(1)
	CreateDynamicObject(984,-196.4721832,-2220.7619629,29.6674080,0.0000000,0.0000000,281.4971924); //object(fenceshit2)(2)
	CreateDynamicObject(984,-189.0312653,-2225.8054199,29.6674080,0.0000000,0.0000000,190.7507477); //object(fenceshit2)(3)
	CreateDynamicObject(983,-187.7489319,-2232.5668945,29.7142830,0.0000000,0.0000000,11.3142700); //object(fenceshit3)(1)
	CreateDynamicObject(984,-180.8123169,-2234.5043945,29.6548920,0.0000000,0.0000000,280.8651428); //object(fenceshit2)(4)
	CreateDynamicObject(984,-173.2624054,-2239.5844727,29.6548920,0.0000000,0.0000000,191.3171692); //object(fenceshit2)(5)
	CreateDynamicObject(984,-170.8233337,-2251.7631836,29.6548920,0.0000000,0.0000000,191.3159180); //object(fenceshit2)(6)
	CreateDynamicObject(983,-172.7079773,-2258.6315918,29.6420879,0.0000000,0.0000000,280.6727905); //object(fenceshit3)(2)
	CreateDynamicObject(982,-173.4448090,-2271.8093262,29.7142830,0.0000000,0.0000000,10.8891602); //object(fenceshit)(2)
	CreateDynamicObject(3578,-210.5306397,-2269.1679688,28.2673264,0.0000000,0.0000000,253.8986511); //object(dockbarr1_la)(33)
	CreateDynamicObject(984,-203.6914062,-2222.2294922,29.6674080,0.0000000,0.0000000,281.4971924); //object(fenceshit2)(7)
	CreateDynamicObject(984,-173.9032898,-2300.4394531,29.6674080,0.0000000,0.0000000,303.2463379); //object(fenceshit2)(8)
	CreateDynamicObject(984,-185.5475159,-2305.1389160,29.6674080,0.0000000,0.0000000,280.6160278); //object(fenceshit2)(9)
	CreateDynamicObject(3877,-254.2019196,-2229.8415527,43.5830460,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(1)
	CreateDynamicObject(2951,-206.9184876,-2246.0231934,29.5465698,0.0000000,179.8451538,337.4414062); //object(a51_labdoor)(1)
	CreateDynamicObject(2951,-204.4237213,-2249.8142090,29.5465698,0.0000000,179.8406982,269.6681519); //object(a51_labdoor)(2)
	CreateDynamicObject(2951,-207.1423492,-2252.6533203,29.5465698,0.0000000,179.8406982,183.3220520); //object(a51_labdoor)(3)
	CreateDynamicObject(2951,-209.7144775,-2250.1428223,29.5465698,0.0000000,179.8406982,266.5989990); //object(a51_labdoor)(4)
	CreateDynamicObject(2951,-209.5802460,-2247.6958008,29.5465698,0.0000000,179.8406982,266.5942383); //object(a51_labdoor)(5)
	CreateDynamicObject(2920,-207.2904663,-2249.1674805,26.8484840,0.0000000,0.0000000,286.6285706); //object(police_barrier)(1)
	CreateDynamicObject(3666,-207.3337402,-2249.1621094,33.6984444,0.0000000,359.7959595,354.2537842); //object(airuntest_las)(1)
	CreateDynamicObject(3877,-169.3095703,-2301.1679688,30.6964683,0.0000000,0.0000000,0.0000000); //object(sf_rooflite)(2)
	CreateDynamicObject(3526,-226.8710022,-2245.4086914,29.0991459,0.0000000,0.0000000,100.2242737); //object(vegasairportlight)(1)
	CreateDynamicObject(3526,-216.2705078,-2243.1865234,29.0991459,0.0000000,0.0000000,100.2227783); //object(vegasairportlight)(2)
	CreateDynamicObject(3526,-216.6586609,-2241.3710938,29.0991459,0.0000000,0.0000000,280.7942200); //object(vegasairportlight)(3)
	CreateDynamicObject(3526,-227.1972961,-2243.6264648,29.0991459,0.0000000,0.0000000,280.7940674); //object(vegasairportlight)(4)
	CreateDynamicObject(3526,-209.9089050,-2248.8125000,29.0991459,0.0000000,0.0000000,350.9083252); //object(vegasairportlight)(5)
	CreateDynamicObject(3526,-222.0302734,-2241.8984375,29.0991459,0.0000000,0.0000000,103.5900879); //object(vegasairportlight)(6)
	CreateDynamicObject(3526,-206.8675079,-2245.6850586,29.0991459,0.0000000,0.0000000,249.3032837); //object(vegasairportlight)(7)
	CreateDynamicObject(3526,-204.0298614,-2249.5827637,29.0991459,0.0000000,0.0000000,183.4159851); //object(vegasairportlight)(8)
	CreateDynamicObject(3526,-206.8843536,-2252.9843750,29.0991459,0.0000000,0.0000000,93.4112854); //object(vegasairportlight)(9)
	CreateDynamicObject(3526,-197.3895416,-2228.3474121,29.0991459,0.0000000,0.0000000,56.3303528); //object(vegasairportlight)(10)
	CreateDynamicObject(3526,-228.9082642,-2137.8381348,29.0991459,0.0000000,0.0000000,281.6411743); //object(vegasairportlight)(11)
	CreateDynamicObject(3526,-241.0185547,-2139.2585449,29.0991459,0.0000000,0.0000000,281.6400147); //object(vegasairportlight)(12)
	CreateDynamicObject(3526,-253.0935059,-2143.1027832,29.0991459,0.0000000,0.0000000,281.6400147); //object(vegasairportlight)(13)
	CreateDynamicObject(3526,-253.0081787,-2143.4580078,29.0991459,0.0000000,0.0000000,101.9429321); //object(vegasairportlight)(14)
	CreateDynamicObject(3526,-228.8150024,-2138.1887207,29.0991459,0.0000000,0.0000000,101.9421387); //object(vegasairportlight)(15)
	CreateDynamicObject(3526,-217.1370850,-2196.7856445,29.0991459,0.0000000,0.0000000,281.6400147); //object(vegasairportlight)(16)
	CreateDynamicObject(3526,-241.4168091,-2201.7954102,29.0991459,0.0000000,0.0000000,277.0686035); //object(vegasairportlight)(17)
	CreateDynamicObject(3526,-217.0516357,-2197.1445312,29.0991459,0.0000000,0.0000000,101.8347778); //object(vegasairportlight)(18)
	CreateDynamicObject(3526,-241.3544922,-2202.1503906,29.0991459,0.0000000,0.0000000,98.7725830); //object(vegasairportlight)(19)
	CreateDynamicObject(3666,-249.4477844,-2175.5532227,28.7351665,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(3)
	CreateDynamicObject(3666,-259.4425049,-2111.7836914,29.6638298,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(4)
	CreateDynamicObject(3666,-234.4375305,-2107.2431641,29.6114864,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(5)
	CreateDynamicObject(3666,-251.5482330,-2085.6025391,35.7558479,0.0000000,0.0000000,0.0000000); //object(airuntest_las)(6)
	CreateDynamicObject(10764,-242.0803833,-2134.6577148,25.7032280,0.0000000,0.0000000,55.6886291); //object(app_light_sfs05e)(2)
	CreateDynamicObject(3526,-255.6498413,-2067.1706543,35.3144684,1.6342163,354.9485168,281.7844238); //object(vegasairportlight)(20)
	CreateDynamicObject(1215,-250.5666809,-2175.8747559,28.7589493,0.0000000,0.0000000,0.0000000); //object(bollardlight)(1)
	CreateDynamicObject(1215,-250.5588684,-2175.8688965,28.7526531,0.0000000,0.0000000,0.0000000); //object(bollardlight)(3)
	CreateDynamicObject(642,-206.8307037,-2282.6040039,30.4539566,0.0000000,0.0000000,0.0000000); //object(kb_canopy_test)(1)
	CreateDynamicObject(642,-196.1524353,-2279.5622559,30.4539566,0.0000000,0.0000000,0.0000000); //object(kb_canopy_test)(2)
	CreateDynamicObject(1257,-266.9024658,-2223.7746582,28.8152008,0.0000000,0.0000000,31.3083191); //object(bustopm)(1)
	CreateDynamicObject(955,-203.8792267,-2283.8061523,29.0307274,0.0000000,0.0000000,281.1999817); //object(cj_ext_sprunk)(1)
	CreateDynamicObject(1432,-206.8195038,-2282.5373535,29.0307274,0.0000000,0.0000000,0.0000000); //object(dyn_table_2)(1)
	CreateDynamicObject(1432,-196.1777649,-2279.5991211,29.0307274,0.0000000,0.0000000,0.0000000); //object(dyn_table_2)(2)
	CreateDynamicObject(1970,-204.3278351,-2288.7402344,28.8650951,349.7142334,0.0000000,192.8110352); //object(dinerseat_1)(1)
	CreateDynamicObject(1970,-207.1162872,-2289.2612305,28.8650951,349.7113037,0.0000000,189.0358734); //object(dinerseat_1)(2)
	CreateDynamicObject(2427,-208.8105164,-2287.4462891,29.2107430,0.0000000,0.0000000,105.9784851); //object(cj_ff_juice_l)(1)
	CreateDynamicObject(2453,-208.6825714,-2286.6757812,29.6705093,0.0000000,0.0000000,19.5428467); //object(cj_pizza_dispf)(1)
	CreateDynamicObject(2948,-203.4811554,-2286.7770996,28.4966812,0.0000000,0.0000000,190.7616425); //object(cr_door_02)(1)
	CreateDynamicObject(2942,-199.3442535,-2281.7854004,31.2339249,0.0000000,0.0000000,190.5144806); //object(kmb_atm1)(1)
	CreateDynamicObject(2942,-202.9880676,-2282.4641113,31.2339249,0.0000000,0.0000000,190.5139160); //object(kmb_atm1)(2)
	CreateDynamicObject(11544,-222.9614868,-2287.0253906,27.9966621,0.0000000,0.0000000,9.2559815); //object(des_ntfrescape2)(1)
	CreateDynamicObject(984,-215.3091583,-2286.8354492,29.5818710,0.0000000,0.0000000,281.3953857); //object(fenceshit2)(10)
	CreateDynamicObject(982,-226.3532410,-2275.9094238,29.7142830,0.0000000,0.0000000,10.6937256); //object(fenceshit)(1)
	CreateDynamicObject(978,-219.2932587,-2279.9218750,29.7149334,0.0000000,0.0000000,338.6856995); //object(sub_roadright)(1)
	CreateDynamicObject(1237,-222.8871460,-2295.2534180,27.1182365,0.0000000,0.0000000,0.0000000); //object(strtbarrier01)(1)
	CreateDynamicObject(979,-225.5917969,-2291.2265625,27.8627090,0.0000000,0.0000000,123.8323975); //object(sub_roadleft)(2)
	CreateDynamicObject(979,-233.3437500,-2279.3991699,27.8627090,0.0000000,0.0000000,123.8323975); //object(sub_roadleft)(3)
	CreateDynamicObject(979,-238.5707855,-2271.6147461,27.8627090,0.0000000,0.0000000,123.8323975); //object(sub_roadleft)(4)
	CreateDynamicObject(979,-243.6907806,-2263.7587891,27.8627090,0.0000000,0.0000000,122.4044189); //object(sub_roadleft)(5)
	CreateDynamicObject(979,-248.7236633,-2255.8435059,27.8627090,0.0000000,0.0000000,122.4041748); //object(sub_roadleft)(6)
	CreateDynamicObject(979,-252.5560150,-2249.8112793,27.8627090,0.0000000,0.0000000,122.4041748); //object(sub_roadleft)(7)
	CreateDynamicObject(3934,-243.5180206,-2248.7692871,27.5761356,359.7874451,359.5920105,26.1699219); //object(helipad01)(1)
	CreateDynamicObject(2797,-268.7869873,-2214.6801758,31.3511906,0.0000000,0.0000000,296.0571289); //object(cj_air_d_5)(2)
	CreateDynamicObject(2792,-268.5428162,-2208.8725586,30.9130573,0.0000000,0.0000000,26.6285706); //object(cj_air_d_1)(1)
	CreateDynamicObject(2793,-270.8278809,-2203.9504394,30.9191360,0.0000000,0.0000000,24.6857300); //object(cj_air_d_2)(1)
	CreateDynamicObject(3658,-265.5798340,-2217.1667481,28.2394199,0.0000000,0.0000000,25.8857117); //object(airlastrola_las)(1)
	CreateDynamicObject(3659,-267.6732788,-2211.3588867,29.0526753,0.0000000,0.0000000,24.6857300); //object(airfinfoa_las)(1)
	CreateDynamicObject(1572,-265.5050659,-2219.5800781,28.2079334,0.0000000,0.0000000,0.0000000); //object(cj_air_trolly)(1)
	CreateDynamicObject(3763,-392.8517151,-2133.6296387,109.8541565,0.0000000,0.0000000,13.3714294); //object(ce_radarmast3)(1)
	CreateDynamicObject(16327,-288.1461487,-2086.1501465,38.4670448,0.0000000,0.0000000,119.2571411); //object(des_bycontowr)(1)
	CreateDynamicObject(11015,-295.1883850,-2225.2968750,30.5019512,0.0000000,0.0000000,27.0265808); //object(drivingschoolex_sfs)(1)
	CreateDynamicObject(5627,-296.7773438,-2176.3750000,32.6305313,0.0000000,0.0000000,21.2091065); //object(lasbrid1sjm_lae)(1)
	CreateDynamicObject(1569,-270.6236267,-2201.9677734,27.6945553,0.0000000,0.0000000,295.9951172); //object(adam_v_door)(1)
	CreateDynamicObject(1569,-291.9821472,-2233.4797363,28.6114616,0.0000000,0.0000000,207.6113739); //object(adam_v_door)(1)
	CreateDynamicObject(1229,-333.4484558,-2191.5244141,28.9683418,0.0000000,0.0000000,172.6286621); //object(bussign1)(1)
	CreateDynamicObject(979,-229.4274902,-2285.3488769,27.8627090,0.0000000,0.0000000,121.8944702); //object(sub_roadleft)(2)
	CreateDynamicObject(1257,-329.2045898,-2207.5515137,28.7376862,0.0000000,0.0000000,200.2769775); //object(bustopm)(1)
	CreateDynamicObject(5627,-328.1072998,-2188.0197754,32.1588135,0.0000000,0.0000000,20.5971069); //object(lasbrid1sjm_lae)(1)
	CreateDynamicObject(1229,-264.6298828,-2229.6435547,28.9610024,0.0000000,0.0000000,30.8551025); //object(bussign1)(2)
	CreateDynamicObject(1233,-285.3535156,-2216.9609375,29.0071945,0.0000000,0.0000000,208.5121155); //object(noparkingsign1)(1)
	CreateDynamicObject(1233,-306.6162109,-2229.0185547,29.5317154,0.0000000,0.0000000,202.2253418); //object(noparkingsign1)(2)
	CreateDynamicObject(1444,-297.3014832,-2215.8071289,29.6485615,0.0000000,0.0000000,296.6285400); //object(dyn_street_sign_2)(1)
	CreateDynamicObject(1444,-266.9570312,-2216.1044922,28.8466415,0.0000000,0.0000000,296.6253662); //object(dyn_street_sign_2)(2)
	CreateDynamicObject(1444,-297.3007812,-2215.8066406,29.6485615,0.0000000,0.0000000,296.6253662); //object(dyn_street_sign_2)(3)
	CreateDynamicObject(1444,-293.0998840,-2234.6257324,29.3468742,0.0000000,0.0000000,296.6253662); //object(dyn_street_sign_2)(4)
	CreateDynamicObject(3264,-264.0644531,-2053.0319824,33.6953011,0.0000000,0.0000000,187.6571808); //object(privatesign3)(1)
	CreateDynamicObject(3264,-288.5341797,-2105.3652344,38.9597206,0.0000000,0.0000000,301.7669678); //object(privatesign3)(2)
	CreateDynamicObject(1689,-302.2196350,-2225.7849121,33.5018959,0.0000000,0.0000000,117.2000122); //object(gen_roofbit3)(1)
	CreateDynamicObject(2794,-297.4353638,-2216.5493164,31.5661850,0.0000000,0.0000000,28.0977173); //object(cj_air_d_3)(1)
	CreateDynamicObject(2794,-300.2188110,-2216.7233887,31.5661850,0.0000000,0.0000000,293.9832459); //object(cj_air_d_3)(2)
	CreateDynamicObject(2794,-296.7649536,-2214.8662109,31.5661850,0.0000000,0.0000000,293.9831543); //object(cj_air_d_3)(3)
	CreateDynamicObject(2794,-290.4172974,-2212.9990234,31.5661850,0.0000000,0.0000000,209.5832214); //object(cj_air_d_3)(4)
	CreateDynamicObject(2795,-282.6726074,-2228.1274414,31.5665188,0.0000000,0.0000000,208.6857300); //object(cj_air_d_4)(1)
	CreateDynamicObject(2795,-293.0355225,-2234.0832519,31.5665188,0.0000000,0.0000000,207.0532227); //object(cj_air_d_4)(2)
	CreateDynamicObject(2795,-292.1886597,-2234.6816406,32.1016464,0.0000000,0.0000000,117.0484619); //object(cj_air_d_4)(3)
	CreateDynamicObject(3934,-295.0629883,-2223.4875488,32.2910156,0.0000000,0.0000000,296.6285706); //object(helipad01)(2)
	CreateDynamicObject(12950,-304.8200073,-2214.5932617,29.0895157,0.0000000,0.0000000,206.9024963); //object(cos_sbanksteps03)(1)
	CreateDynamicObject(11496,-283.7424316,-2106.5339356,38.5690804,0.0000000,0.0000000,304.2857056); //object(des_wjetty)(1)
	CreateDynamicObject(7313,-298.9859619,-2171.0603027,33.4183693,0.0000000,0.0000000,21.1576843); //object(vgsn_scrollsgn01)(1)
	CreateDynamicObject(7313,-331.5520325,-2178.8017578,32.9826546,0.0000000,0.0000000,200.8396606); //object(vgsn_scrollsgn01)(2)
	CreateDynamicObject(7313,-265.9957581,-2184.7570801,30.4103699,0.0000000,0.0000000,294.0146790); //object(vgsn_scrollsgn01)(3)
	CreateDynamicObject(1569,-297.1660156,-2216.3759766,28.8034782,0.0000000,0.0000000,206.2847900); //object(adam_v_door)(1)
	CreateDynamicObject(1569,-268.3463745,-2206.7458496,27.6945553,0.0000000,0.0000000,295.9936523); //object(adam_v_door)(1)
	CreateDynamicObject(16093,-268.9549255,-2144.2216797,32.1305771,0.0000000,0.0000000,136.6287842); //object(a51_gatecontrol)(1)
	CreateDynamicObject(16638,-268.2816467,-2143.3867188,30.3500481,0.0000000,0.0000000,136.4656372); //object(a51_gatecon_a)(1)
	CreateDynamicObject(968,-241.4518433,-2079.4907227,28.2126045,0.0000000,0.0000000,14.3999939); //object(barrierturn)(1)
	CreateDynamicObject(968,-243.7262115,-2063.8566894,28.4317589,0.0000000,0.0000000,14.3975830); //object(barrierturn)(2)
	CreateDynamicObject(968,-245.6963654,-2054.8588867,28.4317589,0.0000000,0.0000000,14.3975830); //object(barrierturn)(3)
	CreateDynamicObject(968,-246.9665070,-2045.5218506,27.9960442,0.0000000,0.0000000,14.3975830); //object(barrierturn)(4)
	CreateDynamicObject(968,-248.1001129,-2038.1910400,27.9960442,0.0000000,0.0000000,14.3975830); //object(barrierturn)(5)
	CreateDynamicObject(968,-266.8748779,-2042.6168213,27.9960442,0.0000000,0.0000000,14.3975830); //object(barrierturn)(6)
	CreateDynamicObject(968,-265.8983765,-2049.3894043,27.9960442,0.0000000,0.0000000,14.3975830); //object(barrierturn)(7)
	CreateDynamicObject(968,-265.3722229,-2057.9768066,28.4317589,0.0000000,0.0000000,14.3975830); //object(barrierturn)(8)
	CreateDynamicObject(968,-265.3318481,-2067.5541992,29.3031883,0.0000000,0.0000000,14.3975830); //object(barrierturn)(9)
	CreateDynamicObject(968,-261.3217163,-2089.9753418,31.3982887,0.0000000,0.0000000,14.3975830); //object(barrierturn)(10)
	CreateDynamicObject(968,-281.1727600,-1947.0356445,23.4099770,0.0000000,0.0000000,14.3975830); //object(barrierturn)(11)
	CreateDynamicObject(968,-264.1452026,-1944.4062500,23.4099770,0.0000000,0.0000000,14.3975830); //object(barrierturn)(12)
	CreateDynamicObject(968,-266.3971863,-1994.6712647,23.4099770,5.1428528,0.0000000,14.3975830); //object(barrierturn)(13)
	CreateDynamicObject(3578,-246.7099609,-2124.4873047,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,-247.1822510,-2124.5769043,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,-248.2611542,-2139.5925293,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(22)
	CreateDynamicObject(3578,-248.3527679,-2139.1091309,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(22)
	CreateDynamicObject(3578,-248.4490814,-2138.6022949,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(22)
	CreateDynamicObject(3578,-252.1532898,-2120.6000977,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(23)
	CreateDynamicObject(3578,-252.0682221,-2121.0397949,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(23)
	CreateDynamicObject(3578,-251.9855194,-2121.4675293,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(23)
	CreateDynamicObject(3578,-255.8506317,-2127.1181641,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,-255.4081116,-2127.0319824,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,-254.9141388,-2126.9387207,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(30)
	CreateDynamicObject(3578,-240.0509644,-2123.4428711,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(4)
	CreateDynamicObject(3578,-240.5140533,-2123.5314941,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(4)
	CreateDynamicObject(3578,-238.6764984,-2133.0429688,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(4)
	CreateDynamicObject(3578,-238.1477203,-2132.9404297,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(4)
	CreateDynamicObject(3578,-237.6696472,-2132.8469238,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(4)
	CreateDynamicObject(3578,-217.5697174,-2208.6069336,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(47)
	CreateDynamicObject(3578,-218.0501709,-2208.7192383,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(47)
	CreateDynamicObject(3578,-218.5451508,-2208.8298340,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(47)
	CreateDynamicObject(3578,-234.1149292,-2206.7736816,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(49)
	CreateDynamicObject(3578,-234.0322723,-2207.2717285,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(49)
	CreateDynamicObject(3578,-233.9217224,-2207.7607422,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(49)
	CreateDynamicObject(3578,-228.2205353,-2210.6110840,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-228.7121887,-2210.7224121,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-229.2043762,-2210.8337402,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-226.2551422,-2220.6450195,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-226.7632446,-2220.7331543,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-227.2521362,-2220.8312988,28.2673264,0.0000000,0.0000000,101.2774658); //object(dockbarr1_la)(37)
	CreateDynamicObject(3578,-230.1287537,-2226.4243164,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	CreateDynamicObject(3578,-230.2407989,-2225.9267578,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	CreateDynamicObject(3578,-230.3460541,-2225.4448242,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	CreateDynamicObject(3578,-232.2026977,-2216.6918945,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	CreateDynamicObject(3578,-232.2549133,-2216.1943359,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	CreateDynamicObject(3578,-232.0307922,-2217.1630859,28.2673264,0.0000000,0.0000000,11.2994385); //object(dockbarr1_la)(50)
	
	// VINEWOOD AIRPORT
	CreateDynamicObject(3998,1620.50000000,-659.79998779,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (1)
	CreateDynamicObject(3998,1620.50000000,-638.70001221,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (2)
	CreateDynamicObject(3998,1620.50000000,-681.09997559,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (3)
	CreateDynamicObject(3998,1620.50000000,-702.70001221,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (4)
	CreateDynamicObject(3998,1620.50000000,-723.90002441,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (5)
	CreateDynamicObject(3998,1620.50000000,-742.00000000,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (6)
	CreateDynamicObject(3998,1606.59997559,-730.20001221,70.80000305,0.00000000,0.00000000,90.00000000); //object(court1_lan) (7)
	CreateDynamicObject(3578,1632.50000000,-623.40002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (1)
	CreateDynamicObject(3578,1608.09997559,-623.40002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (2)
	CreateDynamicObject(3578,1608.09997559,-637.50000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (3)
	CreateDynamicObject(3578,1620.09997559,-623.40002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (4)
	CreateDynamicObject(3578,1620.09997559,-636.90002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (5)
	CreateDynamicObject(3578,1632.50000000,-649.09997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (6)
	CreateDynamicObject(3578,1620.09997559,-653.00000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (7)
	CreateDynamicObject(3578,1632.40002441,-662.29998779,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (8)
	CreateDynamicObject(3578,1632.40002441,-675.09997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (9)
	CreateDynamicObject(3578,1620.00000000,-665.70001221,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (10)
	CreateDynamicObject(3578,1632.40002441,-687.79998779,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (11)
	CreateDynamicObject(3578,1608.09997559,-651.00000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (12)
	CreateDynamicObject(3578,1608.09997559,-664.09997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (13)
	CreateDynamicObject(3578,1620.00000000,-679.09997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (14)
	CreateDynamicObject(3578,1608.09997559,-677.00000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (15)
	CreateDynamicObject(3578,1632.40002441,-700.00000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (16)
	CreateDynamicObject(3578,1620.00000000,-692.00000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (17)
	CreateDynamicObject(3578,1608.09997559,-690.50000000,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (18)
	CreateDynamicObject(3578,1632.40002441,-712.09997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (19)
	CreateDynamicObject(3578,1620.00000000,-707.70001221,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (20)
	CreateDynamicObject(3578,1608.09997559,-704.09997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (21)
	CreateDynamicObject(3578,1632.40002441,-724.70001221,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (22)
	CreateDynamicObject(3578,1632.40002441,-737.90002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (23)
	CreateDynamicObject(3578,1620.09997559,-737.40002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (24)
	CreateDynamicObject(3578,1556.30004883,-742.79998779,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (25)
	CreateDynamicObject(3578,1582.19995117,-742.79998779,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (26)
	CreateDynamicObject(3578,1592.19995117,-717.20001221,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (27)
	CreateDynamicObject(3578,1596.00000000,-742.79998779,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (28)
	CreateDynamicObject(3578,1569.30004883,-742.79998779,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (29)
	CreateDynamicObject(3578,1602.50000000,-717.20001221,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (30)
	CreateDynamicObject(3578,1620.00000000,-724.79998779,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (31)
	CreateDynamicObject(3578,1620.00000000,-721.40002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (32)
	CreateDynamicObject(3578,1632.50000000,-635.90002441,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (33)
	CreateDynamicObject(3578,1632.30004883,-750.59997559,83.30000305,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (34)
	CreateDynamicObject(3578,1626.59997559,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (35)
	CreateDynamicObject(3578,1613.50000000,-618.40002441,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (36)
	CreateDynamicObject(3578,1620.50000000,-618.40002441,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (37)
	CreateDynamicObject(3578,1628.09997559,-618.40002441,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (38)
	CreateDynamicObject(3998,1612.80004883,-755.90002441,70.69999695,0.00000000,0.00000000,270.00000000); //object(court1_lan) (8)
	CreateDynamicObject(3998,1610.69995117,-755.79998779,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (9)
	CreateDynamicObject(3998,1596.30004883,-737.50000000,70.80000305,0.00000000,0.00000000,0.00000000); //object(court1_lan) (10)
	CreateDynamicObject(3998,1603.80004883,-755.79998779,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (11)
	CreateDynamicObject(3998,1582.19995117,-755.90002441,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (12)
	CreateDynamicObject(3998,1550.80004883,-748.20001221,70.69999695,0.00000000,0.00000000,180.00000000); //object(court1_lan) (13)
	CreateDynamicObject(3998,1568.09997559,-729.79998779,70.69999695,0.00000000,0.00000000,270.00000000); //object(court1_lan) (14)
	CreateDynamicObject(3998,1568.69995117,-729.59997559,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (15)
	CreateDynamicObject(3998,1570.00000000,-730.70001221,70.80000305,0.00000000,0.00000000,270.00000000); //object(court1_lan) (16)
	CreateDynamicObject(3998,1558.59997559,-729.59997559,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (17)
	CreateDynamicObject(3998,1567.90002441,-736.40002441,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (18)
	CreateDynamicObject(3998,1558.59997559,-741.70001221,70.69999695,0.00000000,0.00000000,90.00000000); //object(court1_lan) (19)
	CreateDynamicObject(3578,1632.09997559,-763.40002441,83.19999695,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (39)
	CreateDynamicObject(3578,1616.50000000,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (40)
	CreateDynamicObject(3578,1606.19995117,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (41)
	CreateDynamicObject(3578,1596.00000000,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (42)
	CreateDynamicObject(3578,1585.69995117,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (43)
	CreateDynamicObject(3578,1575.40002441,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (44)
	CreateDynamicObject(3578,1565.09997559,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (45)
	CreateDynamicObject(3578,1554.90002441,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (46)
	CreateDynamicObject(3578,1544.59997559,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (47)
	CreateDynamicObject(3578,1543.19995117,-768.29998779,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (48)
	CreateDynamicObject(3578,1581.80004883,-717.20001221,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (49)
	CreateDynamicObject(3578,1571.50000000,-717.20001221,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (50)
	CreateDynamicObject(3578,1561.09997559,-717.20001221,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (51)
	CreateDynamicObject(3578,1550.90002441,-717.20001221,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (52)
	CreateDynamicObject(3578,1543.19995117,-717.20001221,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (53)
	CreateDynamicObject(3578,1543.30004883,-742.70001221,83.19999695,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (54)
	CreateDynamicObject(3578,1609.19995117,-742.79998779,83.30000305,0.00000000,0.00000000,0.00000000); //object(dockbarr1_la) (55)
	CreateDynamicObject(3578,1538.40002441,-722.70001221,83.19999695,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (56)
	CreateDynamicObject(3578,1538.40002441,-733.00000000,83.19999695,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (57)
	CreateDynamicObject(3578,1538.40002441,-763.40002441,83.19999695,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (58)
	CreateDynamicObject(3578,1538.40002441,-753.29998779,83.19999695,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (59)
	CreateDynamicObject(3578,1538.40002441,-743.00000000,83.19999695,0.00000000,0.00000000,90.00000000); //object(dockbarr1_la) (60)
	CreateDynamicObject(3526,1608.09997559,-623.90002441,84.09999847,0.00000000,0.00000000,90.00000000); //object(vegasairportlight) (1)
	CreateDynamicObject(3526,1608.09997559,-620.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (2)
	CreateDynamicObject(3526,1609.09997559,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (3)
	CreateDynamicObject(3526,1612.19995117,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (4)
	CreateDynamicObject(3526,1615.00000000,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (5)
	CreateDynamicObject(3526,1617.90002441,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (6)
	CreateDynamicObject(3526,1620.50000000,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (7)
	CreateDynamicObject(3526,1622.90002441,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (8)
	CreateDynamicObject(3526,1625.80004883,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (9)
	CreateDynamicObject(3526,1629.30004883,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (10)
	CreateDynamicObject(3526,1632.80004883,-618.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (11)
	CreateDynamicObject(3526,1608.09997559,-626.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (12)
	CreateDynamicObject(3526,1608.00000000,-628.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (13)
	CreateDynamicObject(3526,1632.50000000,-620.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (14)
	CreateDynamicObject(3526,1632.50000000,-622.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (15)
	CreateDynamicObject(3526,1632.50000000,-625.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (16)
	CreateDynamicObject(3526,1632.50000000,-628.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (17)
	CreateDynamicObject(3526,1632.50000000,-631.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (18)
	CreateDynamicObject(3526,1632.50000000,-633.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (19)
	CreateDynamicObject(3526,1632.50000000,-635.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (20)
	CreateDynamicObject(3526,1632.50000000,-636.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (21)
	CreateDynamicObject(3526,1632.50000000,-638.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (22)
	CreateDynamicObject(3526,1632.50000000,-640.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (23)
	CreateDynamicObject(3526,1632.50000000,-644.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (24)
	CreateDynamicObject(3526,1632.50000000,-646.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (25)
	CreateDynamicObject(3526,1632.50000000,-647.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (26)
	CreateDynamicObject(3526,1632.50000000,-649.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (27)
	CreateDynamicObject(3526,1632.50000000,-651.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (28)
	CreateDynamicObject(3526,1632.59997559,-654.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (29)
	CreateDynamicObject(3526,1632.59997559,-652.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (30)
	CreateDynamicObject(3526,1632.40002441,-657.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (31)
	CreateDynamicObject(3526,1632.50000000,-667.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (32)
	CreateDynamicObject(3526,1632.40002441,-662.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (33)
	CreateDynamicObject(3526,1632.40002441,-665.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (34)
	CreateDynamicObject(3526,1632.40002441,-659.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (35)
	CreateDynamicObject(3526,1632.40002441,-670.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (36)
	CreateDynamicObject(3526,1632.40002441,-680.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (37)
	CreateDynamicObject(3526,1632.40002441,-677.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (38)
	CreateDynamicObject(3526,1632.40002441,-675.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (39)
	CreateDynamicObject(3526,1632.40002441,-672.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (40)
	CreateDynamicObject(3526,1632.40002441,-692.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (41)
	CreateDynamicObject(3526,1632.40002441,-682.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (42)
	CreateDynamicObject(3526,1632.40002441,-687.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (43)
	CreateDynamicObject(3526,1632.40002441,-690.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (44)
	CreateDynamicObject(3526,1632.30004883,-685.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (45)
	CreateDynamicObject(3526,1632.40002441,-695.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (46)
	CreateDynamicObject(3526,1632.40002441,-704.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (47)
	CreateDynamicObject(3526,1632.40002441,-699.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (48)
	CreateDynamicObject(3526,1632.40002441,-702.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (49)
	CreateDynamicObject(3526,1632.40002441,-697.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (50)
	CreateDynamicObject(3526,1632.40002441,-716.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (51)
	CreateDynamicObject(3526,1632.40002441,-707.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (52)
	CreateDynamicObject(3526,1632.40002441,-712.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (53)
	CreateDynamicObject(3526,1632.40002441,-714.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (54)
	CreateDynamicObject(3526,1632.40002441,-709.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (55)
	CreateDynamicObject(3526,1632.30004883,-719.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (56)
	CreateDynamicObject(3526,1632.40002441,-729.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (57)
	CreateDynamicObject(3526,1632.30004883,-724.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (58)
	CreateDynamicObject(3526,1632.40002441,-727.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (59)
	CreateDynamicObject(3526,1632.30004883,-722.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (60)
	CreateDynamicObject(3526,1632.40002441,-733.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (61)
	CreateDynamicObject(3526,1632.30004883,-742.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (62)
	CreateDynamicObject(3526,1632.40002441,-737.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (63)
	CreateDynamicObject(3526,1632.40002441,-740.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (64)
	CreateDynamicObject(3526,1632.40002441,-735.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (65)
	CreateDynamicObject(3526,1620.09997559,-619.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (66)
	CreateDynamicObject(3526,1620.09997559,-621.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (67)
	CreateDynamicObject(3526,1620.09997559,-624.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (68)
	CreateDynamicObject(3526,1620.09997559,-626.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (69)
	CreateDynamicObject(3526,1620.09997559,-628.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (70)
	CreateDynamicObject(3526,1620.09997559,-632.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (71)
	CreateDynamicObject(3526,1620.09997559,-641.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (72)
	CreateDynamicObject(3526,1620.09997559,-636.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (73)
	CreateDynamicObject(3526,1620.09997559,-634.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (74)
	CreateDynamicObject(3526,1620.09997559,-639.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (75)
	CreateDynamicObject(3526,1620.09997559,-648.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (76)
	CreateDynamicObject(3526,1620.09997559,-657.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (77)
	CreateDynamicObject(3526,1620.09997559,-653.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (78)
	CreateDynamicObject(3526,1620.09997559,-650.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (79)
	CreateDynamicObject(3526,1620.09997559,-655.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (80)
	CreateDynamicObject(3526,1608.09997559,-632.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (81)
	CreateDynamicObject(3526,1608.09997559,-642.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (82)
	CreateDynamicObject(3526,1608.09997559,-637.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (83)
	CreateDynamicObject(3526,1608.09997559,-635.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (84)
	CreateDynamicObject(3526,1608.09997559,-639.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (85)
	CreateDynamicObject(3526,1608.09997559,-646.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (86)
	CreateDynamicObject(3526,1608.09997559,-655.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (87)
	CreateDynamicObject(3526,1608.09997559,-650.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (88)
	CreateDynamicObject(3526,1608.09997559,-648.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (89)
	CreateDynamicObject(3526,1608.09997559,-653.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (90)
	CreateDynamicObject(3526,1608.09997559,-659.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (91)
	CreateDynamicObject(3526,1608.09997559,-668.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (92)
	CreateDynamicObject(3526,1608.09997559,-664.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (93)
	CreateDynamicObject(3526,1608.09997559,-661.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (94)
	CreateDynamicObject(3526,1608.09997559,-666.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (95)
	CreateDynamicObject(3526,1608.09997559,-672.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (96)
	CreateDynamicObject(3526,1608.09997559,-681.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (97)
	CreateDynamicObject(3526,1608.09997559,-676.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (98)
	CreateDynamicObject(3526,1608.09997559,-674.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (99)
	CreateDynamicObject(3526,1608.00000000,-679.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (100)
	CreateDynamicObject(3526,1608.09997559,-685.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (101)
	CreateDynamicObject(3526,1608.09997559,-695.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (102)
	CreateDynamicObject(3526,1608.09997559,-690.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (103)
	CreateDynamicObject(3526,1608.09997559,-687.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (104)
	CreateDynamicObject(3526,1608.09997559,-692.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (105)
	CreateDynamicObject(3526,1632.30004883,-745.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (106)
	CreateDynamicObject(3526,1632.30004883,-755.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (107)
	CreateDynamicObject(3526,1632.30004883,-750.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (108)
	CreateDynamicObject(3526,1632.30004883,-753.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (109)
	CreateDynamicObject(3526,1632.30004883,-748.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (110)
	CreateDynamicObject(3526,1632.09997559,-758.50000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (111)
	CreateDynamicObject(3526,1632.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (112)
	CreateDynamicObject(3526,1632.00000000,-763.59997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (113)
	CreateDynamicObject(3526,1632.00000000,-766.09997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (114)
	CreateDynamicObject(3526,1632.09997559,-760.90002441,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (115)
	CreateDynamicObject(3526,1608.00000000,-699.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (116)
	CreateDynamicObject(3526,1608.09997559,-709.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (117)
	CreateDynamicObject(3526,1608.09997559,-704.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (118)
	CreateDynamicObject(3526,1608.00000000,-701.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (119)
	CreateDynamicObject(3526,1608.09997559,-706.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (120)
	CreateDynamicObject(3526,1620.00000000,-660.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (121)
	CreateDynamicObject(3526,1620.00000000,-670.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (122)
	CreateDynamicObject(3526,1620.00000000,-666.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (123)
	CreateDynamicObject(3526,1620.00000000,-668.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (124)
	CreateDynamicObject(3526,1620.00000000,-663.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (125)
	CreateDynamicObject(3526,1620.00000000,-684.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (126)
	CreateDynamicObject(3526,1620.00000000,-674.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (127)
	CreateDynamicObject(3526,1620.00000000,-678.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (128)
	CreateDynamicObject(3526,1620.00000000,-681.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (129)
	CreateDynamicObject(3526,1620.00000000,-676.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (130)
	CreateDynamicObject(3526,1619.90002441,-696.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (131)
	CreateDynamicObject(3526,1620.00000000,-687.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (132)
	CreateDynamicObject(3526,1620.00000000,-692.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (133)
	CreateDynamicObject(3526,1620.00000000,-694.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (134)
	CreateDynamicObject(3526,1620.00000000,-689.59997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (135)
	CreateDynamicObject(3526,1620.00000000,-702.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (136)
	CreateDynamicObject(3526,1620.00000000,-712.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (137)
	CreateDynamicObject(3526,1620.00000000,-707.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (138)
	CreateDynamicObject(3526,1620.00000000,-710.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (139)
	CreateDynamicObject(3526,1620.00000000,-705.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (140)
	CreateDynamicObject(3526,1620.00000000,-729.70001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (141)
	CreateDynamicObject(3526,1620.00000000,-727.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (142)
	CreateDynamicObject(3526,1619.90002441,-725.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (143)
	CreateDynamicObject(3526,1620.00000000,-723.00000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (144)
	CreateDynamicObject(3526,1620.00000000,-719.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (145)
	CreateDynamicObject(3526,1619.90002441,-716.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (146)
	CreateDynamicObject(3526,1620.00000000,-732.50000000,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (147)
	CreateDynamicObject(3526,1620.00000000,-742.40002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (148)
	CreateDynamicObject(3526,1620.09997559,-737.29998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (149)
	CreateDynamicObject(3526,1620.09997559,-739.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (150)
	CreateDynamicObject(3526,1620.00000000,-734.90002441,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (151)
	CreateDynamicObject(3526,1631.40002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (152)
	CreateDynamicObject(3526,1621.40002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (153)
	CreateDynamicObject(3526,1538.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (154)
	CreateDynamicObject(3526,1543.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (155)
	CreateDynamicObject(3526,1540.90002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (156)
	CreateDynamicObject(3526,1545.30004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (157)
	CreateDynamicObject(3526,1547.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (158)
	CreateDynamicObject(3526,1549.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (159)
	CreateDynamicObject(3526,1550.90002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (160)
	CreateDynamicObject(3526,1552.69995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (161)
	CreateDynamicObject(3526,1554.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (162)
	CreateDynamicObject(3526,1555.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (163)
	CreateDynamicObject(3526,1557.19995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (164)
	CreateDynamicObject(3526,1558.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (165)
	CreateDynamicObject(3526,1560.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (166)
	CreateDynamicObject(3526,1561.40002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (167)
	CreateDynamicObject(3526,1562.80004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (168)
	CreateDynamicObject(3526,1564.19995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (169)
	CreateDynamicObject(3526,1565.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (170)
	CreateDynamicObject(3526,1566.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (171)
	CreateDynamicObject(3526,1567.69995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (172)
	CreateDynamicObject(3526,1568.80004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (173)
	CreateDynamicObject(3526,1569.90002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (174)
	CreateDynamicObject(3526,1571.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (175)
	CreateDynamicObject(3526,1572.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (176)
	CreateDynamicObject(3526,1574.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (177)
	CreateDynamicObject(3526,1575.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (178)
	CreateDynamicObject(3526,1577.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (179)
	CreateDynamicObject(3526,1578.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (180)
	CreateDynamicObject(3526,1579.40002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (181)
	CreateDynamicObject(3526,1580.80004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (182)
	CreateDynamicObject(3526,1582.19995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (183)
	CreateDynamicObject(3526,1583.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (184)
	CreateDynamicObject(3526,1584.69995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (185)
	CreateDynamicObject(3526,1586.19995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (186)
	CreateDynamicObject(3526,1587.80004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (187)
	CreateDynamicObject(3526,1589.19995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (188)
	CreateDynamicObject(3526,1590.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (189)
	CreateDynamicObject(3526,1591.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (190)
	CreateDynamicObject(3526,1592.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (191)
	CreateDynamicObject(3526,1593.90002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (192)
	CreateDynamicObject(3526,1595.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (193)
	CreateDynamicObject(3526,1596.30004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (194)
	CreateDynamicObject(3526,1597.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (195)
	CreateDynamicObject(3526,1630.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (196)
	CreateDynamicObject(3526,1628.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (197)
	CreateDynamicObject(3526,1627.40002441,-768.40002441,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (198)
	CreateDynamicObject(3526,1626.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (199)
	CreateDynamicObject(3526,1624.00000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (200)
	CreateDynamicObject(3526,1619.80004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (201)
	CreateDynamicObject(3526,1617.69995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (202)
	CreateDynamicObject(3526,1616.30004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (203)
	CreateDynamicObject(3526,1615.09997559,-768.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (204)
	CreateDynamicObject(3526,1613.90002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (205)
	CreateDynamicObject(3526,1612.80004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (206)
	CreateDynamicObject(3526,1611.69995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (207)
	CreateDynamicObject(3526,1610.40002441,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (208)
	CreateDynamicObject(3526,1609.30004883,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (209)
	CreateDynamicObject(3526,1598.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (210)
	CreateDynamicObject(3526,1599.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (211)
	CreateDynamicObject(3526,1600.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (212)
	CreateDynamicObject(3526,1601.59997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (213)
	CreateDynamicObject(3526,1605.69995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (214)
	CreateDynamicObject(3526,1608.19995117,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (215)
	CreateDynamicObject(3526,1607.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (216)
	CreateDynamicObject(3526,1604.50000000,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (217)
	CreateDynamicObject(3526,1603.09997559,-768.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (218)
	CreateDynamicObject(3526,1538.40002441,-767.00000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (219)
	CreateDynamicObject(3526,1538.30004883,-765.50000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (220)
	CreateDynamicObject(3526,1538.40002441,-763.90002441,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (221)
	CreateDynamicObject(3526,1538.40002441,-762.40002441,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (222)
	CreateDynamicObject(3526,1538.40002441,-760.79998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (223)
	CreateDynamicObject(3526,1538.40002441,-759.00000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (224)
	CreateDynamicObject(3526,1538.40002441,-756.79998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (225)
	CreateDynamicObject(3526,1538.40002441,-755.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (226)
	CreateDynamicObject(3526,1538.40002441,-753.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (227)
	CreateDynamicObject(3526,1538.40002441,-751.50000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (228)
	CreateDynamicObject(3526,1538.40002441,-749.59997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (229)
	CreateDynamicObject(3526,1538.50000000,-747.59997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (230)
	CreateDynamicObject(3526,1538.40002441,-745.40002441,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (231)
	CreateDynamicObject(3526,1538.40002441,-742.70001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (232)
	CreateDynamicObject(3526,1538.40002441,-740.50000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (233)
	CreateDynamicObject(3526,1538.40002441,-738.40002441,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (234)
	CreateDynamicObject(3526,1538.40002441,-736.50000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (235)
	CreateDynamicObject(3526,1538.40002441,-733.79998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (236)
	CreateDynamicObject(3526,1538.40002441,-731.79998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (237)
	CreateDynamicObject(3526,1538.40002441,-730.00000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (238)
	CreateDynamicObject(3526,1538.40002441,-728.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (239)
	CreateDynamicObject(3526,1538.30004883,-726.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (240)
	CreateDynamicObject(3526,1538.40002441,-724.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (241)
	CreateDynamicObject(3526,1538.50000000,-722.00000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (242)
	CreateDynamicObject(3526,1538.40002441,-720.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (243)
	CreateDynamicObject(3526,1538.40002441,-718.50000000,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (244)
	CreateDynamicObject(3526,1538.50000000,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (245)
	CreateDynamicObject(3526,1607.19995117,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (246)
	CreateDynamicObject(3526,1604.90002441,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (247)
	CreateDynamicObject(3526,1602.59997559,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (248)
	CreateDynamicObject(3526,1600.09997559,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (249)
	CreateDynamicObject(3526,1597.90002441,-717.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (250)
	CreateDynamicObject(3526,1595.59997559,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (251)
	CreateDynamicObject(3526,1593.19995117,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (252)
	CreateDynamicObject(3526,1591.19995117,-717.20001221,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (253)
	CreateDynamicObject(3526,1589.19995117,-717.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (254)
	CreateDynamicObject(3526,1587.30004883,-717.09997559,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (255)
	CreateDynamicObject(3526,1583.09997559,-717.09997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (256)
	CreateDynamicObject(3526,1582.19995117,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (257)
	CreateDynamicObject(3526,1566.50000000,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (258)
	CreateDynamicObject(3526,1568.69995117,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (259)
	CreateDynamicObject(3526,1570.90002441,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (260)
	CreateDynamicObject(3526,1573.19995117,-717.29998779,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (261)
	CreateDynamicObject(3526,1575.40002441,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (262)
	CreateDynamicObject(3526,1577.69995117,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (263)
	CreateDynamicObject(3526,1580.19995117,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (264)
	CreateDynamicObject(3526,1564.80004883,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (265)
	CreateDynamicObject(3526,1563.00000000,-717.09997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (266)
	CreateDynamicObject(3526,1561.09997559,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (267)
	CreateDynamicObject(3526,1559.40002441,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (268)
	CreateDynamicObject(3526,1557.90002441,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (269)
	CreateDynamicObject(3526,1556.19995117,-717.09997559,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (270)
	CreateDynamicObject(3526,1554.40002441,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (271)
	CreateDynamicObject(3526,1552.59997559,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (272)
	CreateDynamicObject(3526,1540.40002441,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (273)
	CreateDynamicObject(3526,1542.30004883,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (274)
	CreateDynamicObject(3526,1544.30004883,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (275)
	CreateDynamicObject(3526,1546.19995117,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (276)
	CreateDynamicObject(3526,1550.80004883,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (277)
	CreateDynamicObject(3526,1548.50000000,-717.20001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (278)
	CreateDynamicObject(3526,1614.00000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (279)
	CreateDynamicObject(3526,1604.30004883,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (280)
	CreateDynamicObject(3526,1612.50000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (281)
	CreateDynamicObject(3526,1610.40002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (282)
	CreateDynamicObject(3526,1608.69995117,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (283)
	CreateDynamicObject(3526,1606.90002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (284)
	CreateDynamicObject(3526,1600.90002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (285)
	CreateDynamicObject(3526,1591.19995117,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (286)
	CreateDynamicObject(3526,1599.00000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (287)
	CreateDynamicObject(3526,1596.30004883,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (288)
	CreateDynamicObject(3526,1593.90002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (289)
	CreateDynamicObject(3526,1587.19995117,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (290)
	CreateDynamicObject(3526,1577.40002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (291)
	CreateDynamicObject(3526,1582.40002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (292)
	CreateDynamicObject(3526,1584.80004883,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (293)
	CreateDynamicObject(3526,1580.00000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (294)
	CreateDynamicObject(3526,1574.19995117,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (295)
	CreateDynamicObject(3526,1564.50000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (296)
	CreateDynamicObject(3526,1569.40002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (297)
	CreateDynamicObject(3526,1571.90002441,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (298)
	CreateDynamicObject(3526,1567.00000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (299)
	CreateDynamicObject(3526,1561.19995117,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (300)
	CreateDynamicObject(3526,1551.50000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (301)
	CreateDynamicObject(3526,1556.50000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (302)
	CreateDynamicObject(3526,1559.09997559,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (303)
	CreateDynamicObject(3526,1554.00000000,-742.79998779,84.09999847,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (304)
	CreateDynamicObject(3526,1548.19995117,-742.70001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (305)
	CreateDynamicObject(3526,1540.19995117,-742.70001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (306)
	CreateDynamicObject(3526,1544.30004883,-742.70001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (307)
	CreateDynamicObject(3526,1546.40002441,-742.70001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (308)
	CreateDynamicObject(3526,1542.40002441,-742.70001221,84.00000000,0.00000000,0.00000000,0.00000000); //object(vegasairportlight) (309)
	CreateDynamicObject(4832,1526.30004883,-721.79998779,97.00000000,0.00000000,0.00000000,0.00000000); //object(airtwer_las) (1)
	CreateDynamicObject(8682,1633.19995117,-663.09997559,84.59999847,0.00000000,0.00000000,0.00000000); //object(chnatwnfnc04_lvs) (1)
	CreateDynamicObject(8682,1633.19995117,-723.70001221,84.59999847,0.00000000,0.00000000,0.00000000); //object(chnatwnfnc04_lvs) (2)
	CreateDynamicObject(8682,1588.19995117,-768.59997559,84.50000000,0.00000000,0.00000000,90.00000000); //object(chnatwnfnc04_lvs) (3)
	CreateDynamicObject(8682,1538.00000000,-723.09997559,84.59999847,0.00000000,0.00000000,0.00000000); //object(chnatwnfnc04_lvs) (4)
	CreateDynamicObject(8682,1562.59997559,-717.00000000,84.50000000,0.00000000,0.00000000,90.00000000); //object(chnatwnfnc04_lvs) (5)
	CreateDynamicObject(8682,1607.69995117,-663.20001221,84.59999847,0.00000000,0.00000000,0.00000000); //object(chnatwnfnc04_lvs) (6)
	CreateDynamicObject(984,1607.80004883,-710.59997559,84.69999695,0.00000000,0.00000000,0.00000000); //object(fenceshit2) (1)

	// MIKSICEVA ZRACNA LUKA, LV
	CreateDynamicObject(5737,880.5000000,2222.1999512,7.1999998,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(9339,828.7000122,2209.8000488,11.8999996,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(5737,880.5000000,2196.0000000,7.1999998,0.0000000,0.0000000,180.0000000); //
	CreateDynamicObject(5737,880.5000000,2169.8000488,7.1999998,0.0000000,0.0000000,180.0000000); //
	CreateDynamicObject(5737,880.5000000,2143.6000977,7.1999998,0.0000000,0.0000000,180.0000000); //
	CreateDynamicObject(5737,880.5000000,2117.3999023,7.1999998,0.0000000,0.0000000,180.0000000); //
	CreateDynamicObject(5737,880.5000000,2091.1999512,7.1999998,0.0000000,0.0000000,180.0000000); //
	CreateDynamicObject(5737,854.2999878,2091.1999512,7.1999998,0.0000000,0.0000000,90.0000000); //
	CreateDynamicObject(5737,854.2999878,2117.3999023,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,854.2999878,2143.6000977,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,854.2999878,2169.8000488,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,854.2999878,2196.0000000,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,854.2999878,2222.1999512,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,854.2999878,2248.3999023,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,880.5000000,2248.3999023,7.1999998,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(5737,828.0999756,2248.3999023,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,828.0999756,2222.1999512,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(9339,828.7000122,2209.8000488,10.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(9339,841.9000244,2209.1000977,-0.1000000,90.0000000,180.0000000,180.0000000); //
	CreateDynamicObject(9339,828.7000122,2209.8000488,9.1000004,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(5737,880.5000000,2274.3000488,7.1999998,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(5737,854.2999878,2274.6000977,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,828.0999756,2274.6000977,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.9000244,2085.1000977,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2090.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2095.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2100.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2105.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2125.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2145.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2165.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2185.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2205.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2110.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2115.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2120.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2130.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2135.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2140.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2150.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2160.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2155.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2170.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2175.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2180.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2190.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2200.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,842.8994141,2195.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2085.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2105.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2125.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2145.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2165.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2185.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2205.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2200.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2195.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2190.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2180.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2175.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2170.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2160.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2155.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2150.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2140.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2135.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2130.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2120.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2115.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2110.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2100.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2095.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2090.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2225.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2245.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2265.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,891.8994141,2285.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2210.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2215.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2220.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2230.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2235.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2240.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2250.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2255.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2260.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2270.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2275.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2280.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(16098,828.9000244,2249.8000488,18.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,828.0999756,2300.6000977,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,854.2999878,2300.5000000,7.1999998,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5737,880.5000000,2300.5000000,7.1999998,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(717,891.8994141,2305.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2290.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2295.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1215,891.8994141,2300.0996094,13.8000002,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2305.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(717,842.8994141,2285.0996094,13.3999996,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1682,826.2999878,2214.0000000,19.3999996,0.0000000,0.0000000,239.9963379); //
	CreateDynamicObject(8550,829.9000244,2295.3000488,17.5000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(982,814.5999756,2299.8999023,13.3999996,0.0000000,300.0000000,0.0000000); //
	CreateDynamicObject(982,814.5999756,2274.3000488,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,814.5999756,2248.6999512,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,814.5999756,2223.1000977,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,827.9000244,2208.6000977,13.3999996,0.0000000,300.0000000,90.0000000); //
	CreateDynamicObject(982,840.7999878,2193.6999512,13.3999996,0.0000000,300.0000000,0.0000000); //
	CreateDynamicObject(982,840.7999878,2168.1000977,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,840.7999878,2142.5000000,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,840.7999878,2116.8999023,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,840.7999878,2091.3000488,13.3999996,0.0000000,299.9981689,0.0000000); //
	CreateDynamicObject(982,829.5000000,2314.1000977,13.3999996,0.0000000,300.0000000,270.0000000); //
	CreateDynamicObject(982,855.0999756,2314.1000977,13.3999996,0.0000000,299.9981689,270.0000000); //
	CreateDynamicObject(982,879.0999756,2314.1000977,13.3999996,0.0000000,299.9981689,270.0000000); //
	CreateDynamicObject(982,894.0000000,2299.5000000,13.3999996,0.0000000,300.0000000,180.0000000); //
	CreateDynamicObject(982,894.0000000,2273.8999023,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2248.3000488,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2222.6999512,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2197.1000977,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2171.5000000,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2145.8999023,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2120.3000488,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2094.6999512,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(982,894.0000000,2091.5000000,13.3999996,0.0000000,299.9981689,179.9945068); //
	CreateDynamicObject(3578,867.5999756,2087.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2107.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2127.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2147.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2167.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2187.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2207.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2227.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2247.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2267.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,867.5996094,2287.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(3578,857.0000000,2227.1999512,12.5000000,0.0000000,0.0000000,330.0000000); //
	CreateDynamicObject(3578,857.0000000,2262.1992188,12.5000000,0.0000000,0.0000000,329.9963379); //
	CreateDynamicObject(9339,867.4000244,2078.8000488,-0.3000000,90.0000000,180.0000000,90.0000000); //
	CreateDynamicObject(9339,867.4000244,2312.8000488,-0.3000000,90.0000000,179.9945068,90.0000000); //
	CreateDynamicObject(9339,841.2000122,2312.8999023,-0.3000000,90.0000000,179.9945068,90.0000000); //
	CreateDynamicObject(3578,867.5996094,2307.0000000,12.5000000,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(9241,880.7999878,2337.8999023,11.1999998,0.0000000,0.0000000,90.0000000); //
	CreateDynamicObject(9241,837.2000122,2338.0000000,11.1999998,0.0000000,0.0000000,90.0000000); //
	
	// NOVA ZRACNA ZA AT400S
	CreateDynamicObject(3998,3746.5998535,1404.3000488,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (1)
	CreateDynamicObject(3998,3746.8000488,1383.9000244,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (2)
	CreateDynamicObject(3998,3747.0000000,1363.3000488,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (3)
	CreateDynamicObject(3998,3746.8999023,1343.0999756,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (4)
	CreateDynamicObject(3998,3746.8000488,1323.3000488,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (5)
	CreateDynamicObject(3998,3746.6000977,1303.1999512,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (6)
	CreateDynamicObject(3998,3746.5000000,1282.9000244,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (7)
	CreateDynamicObject(3998,3771.3000488,1282.5000000,-8.0000000,0.0000000,0.0000000,0.0000000); //object(court1_lan) (8)
	CreateDynamicObject(3998,3771.3000488,1323.0000000,-8.0000000,0.0000000,0.0000000,180.0000000); //object(court1_lan) (9)
	CreateDynamicObject(3998,3770.8000488,1343.4000244,-8.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (10)
	CreateDynamicObject(3998,3771.1000977,1363.8000488,-8.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (11)
	CreateDynamicObject(3998,3770.6999512,1383.9000244,-8.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (12)
	CreateDynamicObject(3998,3770.0000000,1402.9000244,-8.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (13)
	CreateDynamicObject(3998,3769.8000488,1424.0000000,-8.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (14)
	CreateDynamicObject(3998,3794.1000977,1404.5000000,-8.0000000,0.0000000,0.0000000,359.9945068); //object(court1_lan) (15)
	CreateDynamicObject(3998,3793.6999512,1384.1999512,-8.0000000,0.0000000,0.0000000,359.9890137); //object(court1_lan) (16)
	CreateDynamicObject(3998,3793.3000488,1363.8000488,-8.0000000,0.0000000,0.0000000,359.9890137); //object(court1_lan) (17)
	CreateDynamicObject(3998,3793.3999023,1343.8000488,-8.0000000,0.0000000,0.0000000,359.9890137); //object(court1_lan) (18)
	CreateDynamicObject(3998,3793.1999512,1324.3000488,-8.0000000,0.0000000,0.0000000,359.9890137); //object(court1_lan) (19)
	CreateDynamicObject(3998,3793.1000977,1304.6999512,-8.0000000,0.0000000,0.0000000,359.9890137); //object(court1_lan) (20)
	CreateDynamicObject(3998,3793.0000000,1283.1999512,-8.0000000,0.0000000,0.0000000,359.9890137); //object(court1_lan) (21)
	CreateDynamicObject(3998,3817.0000000,1302.4000244,-8.0000000,0.0000000,0.0000000,181.9063721); //object(court1_lan) (22)
	CreateDynamicObject(3998,3815.6000977,1322.1999512,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (23)
	CreateDynamicObject(3998,3815.6000977,1340.8000488,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (24)
	CreateDynamicObject(3998,3814.8999023,1360.0000000,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (25)
	CreateDynamicObject(3998,3814.6000977,1379.6999512,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (26)
	CreateDynamicObject(3998,3814.3000488,1398.9000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (27)
	CreateDynamicObject(3998,3813.8000488,1417.6999512,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (28)
	CreateDynamicObject(3998,3813.6999512,1424.9000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (29)
	CreateDynamicObject(3998,3813.3000488,1445.1999512,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (30)
	CreateDynamicObject(3998,3788.3000488,1444.8000488,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (31)
	CreateDynamicObject(3998,3764.1999512,1445.1999512,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (32)
	CreateDynamicObject(3998,3745.8000488,1445.0000000,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (33)
	CreateDynamicObject(3998,3745.3999023,1464.3000488,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (34)
	CreateDynamicObject(3998,3770.1000977,1464.0999756,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (35)
	CreateDynamicObject(3998,3794.1000977,1464.5999756,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (36)
	CreateDynamicObject(3998,3812.8000488,1465.1999512,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (37)
	CreateDynamicObject(3998,3812.0000000,1484.5999756,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (38)
	CreateDynamicObject(3998,3787.6000977,1484.4000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (39)
	CreateDynamicObject(3998,3763.5000000,1483.8000488,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (40)
	CreateDynamicObject(3998,3745.0000000,1483.5000000,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (41)
	CreateDynamicObject(8034,3787.3000488,1299.4000244,10.1000004,0.0000000,0.0000000,0.0000000); //object(flghtschl01_lvs) (1)
	CreateDynamicObject(16098,3815.5000000,1351.8000488,10.3000002,0.0000000,0.0000000,1.9173584); //object(des_by_hangar_) (1)
	CreateDynamicObject(978,3757.8999023,1478.1999512,5.1999998,90.0000000,180.0000000,270.0001221); //object(sub_roadright) (1)
	CreateDynamicObject(978,3757.8999023,1469.5999756,5.1999998,90.0000000,179.9945068,269.9945068); //object(sub_roadright) (2)
	CreateDynamicObject(978,3757.8999023,1461.5000000,5.1999998,90.0000000,179.9945068,269.9890137); //object(sub_roadright) (3)
	CreateDynamicObject(978,3758.1000977,1452.5000000,5.1999998,90.0000000,180.0054932,271.8953857); //object(sub_roadright) (4)
	CreateDynamicObject(978,3758.3999023,1443.5999756,5.1999998,90.0000000,179.9945068,271.9061279); //object(sub_roadright) (5)
	CreateDynamicObject(978,3758.6000977,1435.0000000,5.1999998,90.0000000,179.9945068,269.9888306); //object(sub_roadright) (6)
	CreateDynamicObject(978,3758.6000977,1426.5000000,5.1999998,90.0000000,179.9945068,269.9836121); //object(sub_roadright) (7)
	CreateDynamicObject(978,3758.6999512,1417.9000244,5.1999998,90.0000000,179.9945068,271.9009094); //object(sub_roadright) (8)
	CreateDynamicObject(978,3759.0000000,1409.3000488,5.1999998,90.0000000,179.9945068,271.9006348); //object(sub_roadright) (9)
	CreateDynamicObject(978,3759.1000977,1400.8000488,5.1999998,90.0000000,180.0054932,269.9723206); //object(sub_roadright) (10)
	CreateDynamicObject(978,3759.1000977,1392.5000000,5.1999998,90.0000000,179.9945068,269.9780579); //object(sub_roadright) (11)
	CreateDynamicObject(978,3759.1999512,1384.1999512,5.1999998,90.0000000,180.0054932,271.8843994); //object(sub_roadright) (12)
	CreateDynamicObject(978,3759.5000000,1375.5000000,5.1999998,90.0000000,180.0054932,271.8841858); //object(sub_roadright) (13)
	CreateDynamicObject(978,3759.8000488,1367.0999756,5.1999998,90.0000000,180.0054932,271.8841858); //object(sub_roadright) (15)
	CreateDynamicObject(978,3760.1000977,1358.3000488,5.1999998,90.0000000,179.9945068,271.8951416); //object(sub_roadright) (16)
	CreateDynamicObject(978,3760.1999512,1349.6999512,5.1999998,90.0000000,179.9945068,269.9778137); //object(sub_roadright) (17)
	CreateDynamicObject(978,3763.5000000,1351.3000488,5.1999998,90.0000000,179.9945068,319.9725647); //object(sub_roadright) (18)
	CreateDynamicObject(978,3770.3999023,1345.5000000,5.1999998,90.0000000,180.0054932,319.9603271); //object(sub_roadright) (19)
	CreateDynamicObject(978,3777.3000488,1339.6999512,5.1999998,90.0000000,180.0054932,319.9603577); //object(sub_roadright) (20)
	CreateDynamicObject(978,3784.8999023,1336.9000244,5.1999998,90.0000000,180.0054932,359.9603882); //object(sub_roadright) (21)
	CreateDynamicObject(978,3793.3999023,1336.9000244,5.1999998,90.0000000,179.9945068,359.9670410); //object(sub_roadright) (22)
	CreateDynamicObject(978,3762.5000000,1383.1999512,5.1999998,90.0000000,180.0054932,315.7189636); //object(sub_roadright) (23)
	CreateDynamicObject(978,3769.0000000,1377.0000000,5.1999998,90.0000000,180.0054932,315.7141113); //object(sub_roadright) (24)
	CreateDynamicObject(978,3775.3999023,1370.9000244,5.1999998,90.0000000,180.0054932,315.7140808); //object(sub_roadright) (25)
	CreateDynamicObject(978,3782.6999512,1367.8000488,5.1999998,90.0000000,179.9945068,355.7196045); //object(sub_roadright) (26)
	CreateDynamicObject(978,3791.1999512,1367.1999512,5.1999998,90.0000000,179.9945068,355.7153320); //object(sub_roadright) (27)
	CreateDynamicObject(981,3826.3999023,1396.6999512,6.1999998,9.0000000,0.0000000,90.0000000); //object(helix_barrier) (1)
	CreateDynamicObject(981,3825.1000977,1440.4000244,6.1999998,8.9978027,0.0000000,91.9173279); //object(helix_barrier) (2)
	CreateDynamicObject(981,3823.8000488,1472.0999756,6.1999998,8.9923096,0.0000000,91.9171143); //object(helix_barrier) (3)
	CreateDynamicObject(981,3825.6000977,1426.0000000,6.1999998,8.9923096,0.0000000,91.9171143); //object(helix_barrier) (4)
	CreateDynamicObject(981,3827.1999512,1308.5000000,6.1999998,8.9923096,0.0000000,91.9171143); //object(helix_barrier) (5)
	CreateDynamicObject(981,3828.1000977,1297.0999756,6.1999998,8.9923096,0.0000000,91.9171143); //object(helix_barrier) (6)
	CreateDynamicObject(981,3734.3999023,1469.0000000,6.1999998,8.9923096,0.0000000,271.9171143); //object(helix_barrier) (7)
	CreateDynamicObject(981,3735.5000000,1439.6999512,6.1999998,8.9868164,0.0000000,271.9171143); //object(helix_barrier) (8)
	CreateDynamicObject(981,3735.8999023,1410.5000000,6.1999998,8.9868164,0.0000000,271.9171143); //object(helix_barrier) (9)
	CreateDynamicObject(981,3736.5000000,1381.8000488,6.1999998,8.9868164,0.0000000,271.9171143); //object(helix_barrier) (10)
	CreateDynamicObject(981,3737.0000000,1351.9000244,6.1999998,8.9868164,0.0000000,271.9171143); //object(helix_barrier) (11)
	CreateDynamicObject(981,3736.1999512,1321.8000488,6.1999998,8.9868164,0.0000000,271.9171143); //object(helix_barrier) (12)
	CreateDynamicObject(981,3735.5000000,1296.6999512,6.1999998,8.9868164,0.0000000,271.9171143); //object(helix_barrier) (13)
	CreateDynamicObject(981,3754.6000977,1283.6999512,6.1999998,8.9868164,0.0000000,359.9997559); //object(helix_barrier) (14)
	CreateDynamicObject(4724,3748.3000488,1312.6999512,7.3000002,0.0000000,0.0000000,0.0000000); //object(librarywall_lan2) (1)
	CreateDynamicObject(3877,3757.8999023,1482.9000244,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (1)
	CreateDynamicObject(3877,3758.0000000,1472.5999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (2)
	CreateDynamicObject(3877,3757.8999023,1464.1999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (3)
	CreateDynamicObject(3877,3758.1000977,1455.9000244,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (4)
	CreateDynamicObject(3877,3758.3999023,1446.5999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (5)
	CreateDynamicObject(3877,3758.8000488,1430.6999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (6)
	CreateDynamicObject(3877,3758.8999023,1419.3000488,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (7)
	CreateDynamicObject(3877,3759.1999512,1410.5999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (8)
	CreateDynamicObject(3877,3759.1999512,1400.1999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (9)
	CreateDynamicObject(3877,3759.3999023,1386.0999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (10)
	CreateDynamicObject(3877,3765.8999023,1380.0000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (11)
	CreateDynamicObject(3877,3772.3999023,1374.0000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (12)
	CreateDynamicObject(3877,3778.3999023,1368.1999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (13)
	CreateDynamicObject(3877,3787.1000977,1367.6999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (14)
	CreateDynamicObject(3877,3795.5000000,1367.0000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (15)
	CreateDynamicObject(3877,3759.6999512,1377.0999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (16)
	CreateDynamicObject(3877,3759.8999023,1368.5000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (17)
	CreateDynamicObject(3877,3760.1999512,1359.4000244,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (18)
	CreateDynamicObject(3877,3760.3999023,1349.5999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (19)
	CreateDynamicObject(3877,3767.0000000,1348.5999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (20)
	CreateDynamicObject(3877,3774.0000000,1342.6999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (21)
	CreateDynamicObject(3877,3780.6000977,1337.0000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (22)
	CreateDynamicObject(3877,3789.3999023,1337.0000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (23)
	CreateDynamicObject(3877,3797.8000488,1336.9000244,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (24)
	CreateDynamicObject(3877,3758.8000488,1438.9000244,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (26)
	CreateDynamicObject(3998,3811.0000000,1504.0999756,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (43)
	CreateDynamicObject(3998,3786.3999023,1504.0000000,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (44)
	CreateDynamicObject(3998,3762.0000000,1504.0000000,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (45)
	CreateDynamicObject(3998,3745.0000000,1503.8000488,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (46)
	CreateDynamicObject(3998,3810.3999023,1523.4000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (47)
	CreateDynamicObject(3998,3786.0000000,1523.4000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (48)
	CreateDynamicObject(3998,3761.8000488,1523.4000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (49)
	CreateDynamicObject(3998,3745.0000000,1523.4000244,-8.0000000,0.0000000,0.0000000,181.9061279); //object(court1_lan) (50)
	CreateDynamicObject(981,3822.1999512,1506.5000000,5.1999998,8.9923096,0.0000000,91.9171143); //object(helix_barrier) (15)
	CreateDynamicObject(981,3733.6999512,1505.4000244,5.1999998,8.9923096,0.0000000,272.3303223); //object(helix_barrier) (16)
	CreateDynamicObject(3877,3757.8000488,1491.0999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (27)
	CreateDynamicObject(3877,3757.6000977,1499.6999512,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (28)
	CreateDynamicObject(3877,3756.3999023,1508.5999756,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (29)
	CreateDynamicObject(3877,3756.3000488,1519.0000000,3.9000001,0.0000000,0.0000000,0.0000000); //object(sf_rooflite) (30)

	// AT400S ZRACNA LUKA_2
	CreateDynamicObject(17554,1964.0000000,-4021.1999512,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (1)
	CreateDynamicObject(17554,1926.0000000,-4021.1999512,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (2)
	CreateDynamicObject(17554,1887.6999512,-4021.1999512,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (3)
	CreateDynamicObject(17554,1849.3000488,-4021.1999512,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (4)
	CreateDynamicObject(17554,1811.0999756,-4021.1999512,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (5)
	CreateDynamicObject(17554,1811.0999756,-4049.6999512,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (6)
	CreateDynamicObject(17554,1811.0999756,-4078.3000488,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (7)
	CreateDynamicObject(17554,1811.0999756,-4106.7001953,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (8)
	CreateDynamicObject(17554,1850.3000488,-4049.3000488,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (9)
	CreateDynamicObject(17554,1888.9000244,-4049.3000488,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (10)
	CreateDynamicObject(17554,1927.0999756,-4049.3000488,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (11)
	CreateDynamicObject(17554,1964.0000000,-4049.3000488,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (12)
	CreateDynamicObject(17554,1850.4000244,-4077.8999023,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (13)
	CreateDynamicObject(17554,1888.8000488,-4077.8999023,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (14)
	CreateDynamicObject(17554,1927.0999756,-4077.8999023,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (15)
	CreateDynamicObject(17554,1964.0000000,-4077.8999023,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (16)
	CreateDynamicObject(17554,1849.3000488,-4106.7001953,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (17)
	CreateDynamicObject(17554,1887.8000488,-4106.7998047,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (18)
	CreateDynamicObject(17554,1926.4000244,-4106.7998047,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (19)
	CreateDynamicObject(17554,1964.0000000,-4106.7998047,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (20)
	CreateDynamicObject(17554,1811.0999756,-4135.5000000,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (21)
	CreateDynamicObject(17554,1849.6999512,-4135.3999023,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (22)
	CreateDynamicObject(17554,1888.3000488,-4135.5000000,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (23)
	CreateDynamicObject(17554,1926.9000244,-4135.7001953,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (24)
	CreateDynamicObject(17554,1964.0000000,-4135.7998047,-12.0000000,0.0000000,0.0000000,0.0000000); //object(beachblok5_lae2) (25)
	CreateDynamicObject(3489,1961.4000244,-4122.7001953,11.8000002,0.0000000,0.0000000,180.0000000); //object(hangar1_08_lvs) (1)
	CreateDynamicObject(3489,1827.0000000,-4118.2998047,11.8000002,0.0000000,0.0000000,179.9945068); //object(hangar1_08_lvs) (2)
	CreateDynamicObject(4726,1897.5999756,-4115.1000977,4.0000000,0.0000000,0.0000000,90.0000000); //object(libtwrhelipd_lan2) (1)
	CreateDynamicObject(7981,1925.6999512,-4104.8999023,10.1999998,0.0000000,0.0000000,0.0000000); //object(smallradar02_lvs) (1)
	CreateDynamicObject(8038,1865.8000488,-4108.2998047,25.2999992,0.0000000,0.0000000,0.0000000); //object(arprtermnl01_lvs) (1)
	CreateDynamicObject(8172,1900.0000000,-4036.0000000,5.1999998,0.0000000,0.0000000,268.0827026); //object(vgssairportland07) (1)
	CreateDynamicObject(3472,1976.5999756,-4087.8999023,5.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (1)
	CreateDynamicObject(3472,1940.0999756,-4085.8000488,5.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (2)
	CreateDynamicObject(3472,1896.5999756,-4068.1000977,5.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (3)
	CreateDynamicObject(3472,1794.8000488,-4092.6999512,5.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (4)
	CreateDynamicObject(3472,1794.0999756,-4010.3000488,5.1999998,0.0000000,0.0000000,0.0000000); //object(circuslampost03) (5)

	// BLOODMASTER AT400S
	CreateDynamicObject(4866,4.3958549,5086.4169922,5.4898090,0.0000000,0.0000000,0.0000000); //object(lasrnway1_las) (1)
	CreateDynamicObject(4866,7.1795902,4966.8833008,5.4800091,0.0000000,0.0000000,0.0000000); //object(lasrnway1_las) (2)
	CreateDynamicObject(1683,28.6820354,4854.9169922,0.0026379,0.0000000,15.0000000,325.0000000); //object(ap_jumbo_01) (1)
	CreateDynamicObject(3689,74.2910385,4983.1381836,13.2509413,0.0000000,0.0000000,0.0000000); //object(rdwarhusbig) (1)
	CreateDynamicObject(7020,158.2608948,5112.8896484,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (1)
	CreateDynamicObject(7020,158.2607574,5078.2070312,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (2)
	CreateDynamicObject(7020,158.2355042,5043.7133789,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (3)
	CreateDynamicObject(7020,158.2225342,5009.0307617,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (4)
	CreateDynamicObject(7020,158.2131805,4974.4858398,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (5)
	CreateDynamicObject(7020,158.2727661,4940.1704102,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (6)
	CreateDynamicObject(7020,158.2236786,4905.9116211,-12.2123718,0.0000000,90.0000000,0.0000000); //object(vgnhseing112) (7)
	CreateDynamicObject(7020,125.9862823,4907.1352539,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (8)
	CreateDynamicObject(7020,91.2729645,4907.1181641,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (9)
	CreateDynamicObject(7020,56.5596466,4907.1010742,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (10)
	CreateDynamicObject(7020,21.8463287,4907.0839844,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (11)
	CreateDynamicObject(7020,-12.8669891,4907.0668945,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (12)
	CreateDynamicObject(7020,-47.5800781,4907.0498047,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (13)
	CreateDynamicObject(7020,-82.2929688,4907.0322266,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (14)
	CreateDynamicObject(7020,-116.9434967,4907.0488281,-12.2123718,0.0000000,90.0000000,270.0000000); //object(vgnhseing112) (15)
	CreateDynamicObject(7020,-146.6201477,4909.8896484,-12.2123718,0.0000000,90.0000000,265.0000000); //object(vgnhseing112) (16)
	CreateDynamicObject(7020,-144.2694397,4941.8051758,-12.2123718,0.0000000,90.0000000,180.0000000); //object(vgnhseing112) (17)
	CreateDynamicObject(7020,-144.2768250,4976.5488281,-12.2123718,0.0000000,90.0000000,179.9945068); //object(vgnhseing112) (18)
	CreateDynamicObject(7020,-144.2439117,5011.2602539,-12.2123718,0.0000000,90.0000000,179.9945068); //object(vgnhseing112) (19)
	CreateDynamicObject(7020,-144.2326355,5046.0249023,-12.2123718,0.0000000,90.0000000,179.9945068); //object(vgnhseing112) (20)
	CreateDynamicObject(7020,-146.6107330,5077.3574219,-12.2123718,0.0000000,90.0000000,179.9945068); //object(vgnhseing112) (21)
	CreateDynamicObject(7020,-146.5759430,5112.0512695,-12.2123718,0.0000000,90.0000000,179.9945068); //object(vgnhseing112) (22)
	CreateDynamicObject(7020,-146.5347137,5146.7871094,-12.2123718,0.0000000,90.0000000,179.9945068); //object(vgnhseing112) (23)
	CreateDynamicObject(7020,-114.2750320,5145.1230469,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (24)
	CreateDynamicObject(7020,-79.5731964,5145.1176758,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (25)
	CreateDynamicObject(7020,-44.8713608,5145.1123047,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (26)
	CreateDynamicObject(7020,-10.1695251,5145.1069336,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (27)
	CreateDynamicObject(7020,24.5322266,5145.1015625,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (28)
	CreateDynamicObject(7020,59.2333984,5145.0957031,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (29)
	CreateDynamicObject(7020,93.9355469,5145.0908203,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (30)
	CreateDynamicObject(7020,128.6376953,5145.0859375,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (31)
	CreateDynamicObject(7020,160.6023407,5145.0781250,-12.2123718,0.0000000,90.0000000,90.0000000); //object(vgnhseing112) (32)
	CreateDynamicObject(6295,-137.7225800,4982.1533203,29.4123974,0.0000000,0.0000000,270.0000000); //object(sanpedlithus_law2) (1)
	CreateDynamicObject(9245,-26.7377911,4966.5219727,17.0791130,0.0000000,0.0000000,270.0000000); //object(cstguard_sfn01) (1)
	CreateDynamicObject(3816,-107.3600693,5116.4936523,14.0351276,0.0000000,0.0000000,0.0000000); //object(bighangar1_sfx) (1)
	CreateDynamicObject(4726,-105.5151749,4968.1733398,7.4017620,0.0000000,0.0000000,0.0000000); //object(libtwrhelipd_lan2) (1)
	CreateDynamicObject(4727,-105.5075226,4968.1347656,8.0771465,0.0000000,0.0000000,0.0000000); //object(libtwrhelipda_lan2) (1)
	CreateDynamicObject(7981,145.3172455,5130.4125977,10.4881525,0.0000000,0.0000000,95.0000000); //object(smallradar02_lvs) (1)
	CreateDynamicObject(8344,-18.3568001,4985.3237305,5.4800000,0.0000000,0.0000000,270.0000000); //object(vgssairportland10) (1)
	CreateDynamicObject(9241,118.8030853,5087.5039062,7.1909084,0.0000000,0.0000000,0.0000000); //object(copbits_sfn) (1)
	CreateDynamicObject(10763,4.9422011,4980.0942383,35.6485825,0.0000000,0.0000000,315.0000000); //object(controltower_sfse) (1)
	CreateDynamicObject(10766,202.5617676,5042.1665039,3.5344009,0.0000000,0.0000000,270.0000000); //object(airport_10_sfse) (1)
	CreateDynamicObject(10766,202.5615234,5042.1660156,-25.6155949,0.0000000,0.0000000,270.0000000); //object(airport_10_sfse) (3)
	CreateDynamicObject(10766,202.5615234,5042.1660156,-50.1055946,0.0000000,0.0000000,270.0000000); //object(airport_10_sfse) (5)
	CreateDynamicObject(10768,63.5975456,5092.5258789,-8.2880335,0.0000000,0.0000000,135.0000000); //object(airprtgnd_06_sfse) (1)
	CreateDynamicObject(7020,163.7585449,4939.0908203,-12.2221718,0.0000000,90.0000000,310.0000000); //object(vgnhseing112) (33)
	CreateDynamicObject(7020,153.8956451,4918.8168945,-12.3887711,0.0000000,85.0000000,330.0000000); //object(vgnhseing112) (34)
	CreateDynamicObject(7020,183.2626953,4955.3354492,-12.2221718,0.0000000,90.0000000,309.9957275); //object(vgnhseing112) (35)
	CreateDynamicObject(7020,209.7503510,4977.1645508,-12.2221718,0.0000000,90.0000000,315.0000000); //object(vgnhseing112) (36)
	CreateDynamicObject(7020,228.1149139,4995.9394531,-12.2221718,0.0000000,90.0000000,314.9945068); //object(vgnhseing112) (37)
	CreateDynamicObject(14553,6.6377296,5239.3300781,-79.9896774,85.0000000,0.0000000,30.0000000); //object(androm_des_obj) (1)
	CreateDynamicObject(1682,144.3854370,5134.7099609,21.9423790,0.0000000,0.0000000,165.0000000); //object(ap_radar1_01) (1)
	CreateDynamicObject(2773,-32.5304680,4964.0874023,5.9972372,0.0000000,0.0000000,0.0000000); //object(cj_airprt_bar) (1)
	CreateDynamicObject(2773,-32.5304642,4959.7412109,5.9972372,0.0000000,0.0000000,0.0000000); //object(cj_airprt_bar) (2)
	CreateDynamicObject(2794,-30.5048943,4956.4956055,8.8539457,0.0000000,0.0000000,0.0000000); //object(cj_air_d_3) (1)
	CreateDynamicObject(2792,-30.5220394,4976.5751953,8.7981453,0.0000000,0.0000000,0.0000000); //object(cj_air_d_1) (1)
	CreateDynamicObject(2796,-32.4472694,4961.5810547,8.7356901,0.0000000,0.0000000,90.0000000); //object(cj_air_d_6) (1)
	CreateDynamicObject(2796,-32.4435806,4962.6547852,8.7356901,0.0000000,0.0000000,90.0000000); //object(cj_air_d_6) (2)
	CreateDynamicObject(2797,-26.8889484,4965.2895508,14.0977087,0.0000000,0.0000000,0.0000000); //object(cj_air_d_5) (1)
	CreateDynamicObject(3526,-41.5161667,4964.9389648,5.5484271,0.0000000,0.0000000,0.0000000); //object(vegasairportlight) (1)
	CreateDynamicObject(3658,-19.0753651,4942.3779297,6.1235433,0.0000000,0.0000000,0.0000000); //object(airlastrola_las) (1)
	CreateDynamicObject(4832,248.9136353,4789.8261719,0.0000000,0.0000000,0.0000000,0.0000000); //object(airtwer_las) (1)

	// MIKSICEVA AT400S ZRACNA LUKA
	CreateDynamicObject(5644,-1571.8000488,2247.3000488,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1543.0999756,2247.3000488,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1514.4000244,2247.3000488,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6999512,2247.3000488,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.8000488,2270.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.8000488,2294.1000977,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.7998047,2317.5000000,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.8000488,2364.3000488,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.8000488,2387.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6999512,2270.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6999512,2294.1000977,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6999512,2317.5000000,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6999512,2340.8999023,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6992188,2364.2998047,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6992188,2387.5996094,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.6999512,2411.0000000,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.8000488,2411.1000977,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1491.9000244,2255.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1491.9000244,2295.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1491.9000244,2335.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1491.9000244,2375.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1491.8994141,2415.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.7998047,2423.6992188,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.6992188,2423.7998047,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1565.5999756,2375.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1565.5999756,2335.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1565.5999756,2295.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1565.5999756,2255.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1565.5996094,2415.5000000,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1529.0999756,2255.5000000,65.8889999,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1525.0999756,2286.8999023,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1525.0999756,2310.3000488,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1525.0999756,2333.6999512,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1525.0999756,2357.1000977,51.4590034,0.0000000,270.0000000,0.0002441); //
	CreateDynamicObject(5644,-1525.0996094,2380.5000000,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.3994141,2380.5000000,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.4000244,2357.0000000,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.4000244,2333.6000977,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.4000244,2310.1999512,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.4000244,2286.8000488,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(2794,-1501.5000000,2235.6000977,61.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0999756,2235.6999512,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2435.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2435.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.4000244,2235.6999512,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(7981,-1551.9000244,2489.8000488,56.7000008,0.0000000,0.0000000,119.9981384); //
	CreateDynamicObject(982,-1470.6999512,2299.5000000,66.1999969,0.0000000,60.0000000,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2273.8999023,66.1999969,0.0000000,59.9963379,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2248.3000488,66.1999969,0.0000000,59.9963379,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2325.1000977,66.1999969,0.0000000,59.9963379,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2350.6999512,66.1999969,0.0000000,59.9963379,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2376.3000488,66.1999969,0.0000000,59.9963379,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2401.8999023,66.1999969,0.0000000,59.9963379,0.0000000); //
	CreateDynamicObject(982,-1470.6992188,2422.6992188,66.1999969,0.0000000,59.9908447,0.0000000); //
	CreateDynamicObject(982,-1484.0999756,2476.0000000,66.1999969,0.0000000,59.9963379,90.0000000); //
	CreateDynamicObject(982,-1586.7998047,2422.6992188,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2397.1000977,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2371.5000000,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.7998047,2345.8994141,66.1999969,0.0000000,59.9908447,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2320.3000488,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2294.6999512,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2269.1000977,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2248.3000488,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1573.3000488,2234.8999023,66.1999969,0.0000000,60.0000000,270.0000000); //
	CreateDynamicObject(982,-1547.6999512,2234.8999023,66.1999969,0.0000000,59.9963379,270.0000000); //
	CreateDynamicObject(982,-1484.0999756,2234.8999023,66.1999969,0.0000000,59.9963379,270.0000000); //
	CreateDynamicObject(982,-1509.6999512,2234.8999023,66.1999969,0.0000000,59.9963379,270.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2245.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2255.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2265.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2275.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2285.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2295.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2305.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2315.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2325.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2335.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2345.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2355.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2365.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2375.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2385.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2395.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2405.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2415.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2425.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2245.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2255.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2265.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2275.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2285.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2295.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2305.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2315.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2325.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2335.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2345.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2355.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2365.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2375.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2385.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2395.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2405.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2415.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2425.6992188,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(979,-1594.6999512,2430.6999512,60.0999985,358.0194702,351.9952393,67.7215576); //
	CreateDynamicObject(979,-1591.5000000,2439.3994141,61.4000015,358.0114746,351.9909668,71.7187500); //
	CreateDynamicObject(978,-1613.1999512,2382.3999023,50.9000015,0.4920044,349.7470703,58.0858154); //
	CreateDynamicObject(3666,-1610.0000000,2387.1000977,51.5000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1616.3994141,2377.6992188,49.5999985,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1682,-1554.3000488,2492.3000488,67.6999969,0.0000000,0.0000000,209.9981689); //
	CreateDynamicObject(5644,-1525.0996094,2333.6992188,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(6959,-1491.9000244,2455.3999023,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2448.3000488,66.1999969,0.0000000,59.9908447,0.0000000); //
	CreateDynamicObject(982,-1470.6999512,2462.6999512,66.1999969,0.0000000,59.9908447,0.0000000); //
	CreateDynamicObject(982,-1509.6999512,2476.0000000,66.1999969,0.0000000,59.9963379,90.0000000); //
	CreateDynamicObject(6959,-1533.1999512,2455.5000000,65.8889999,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(6959,-1565.5000000,2455.3999023,65.9000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.6999512,2447.1999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.5999756,2463.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1543.0000000,2463.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1514.3000488,2463.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.5999756,2463.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1485.8000488,2442.6999512,53.2000008,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(982,-1586.8000488,2448.3000488,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1586.8000488,2462.6999512,66.1999969,0.0000000,59.9963379,179.9945068); //
	CreateDynamicObject(982,-1573.4000244,2476.0000000,66.1999969,0.0000000,59.9963379,90.0000000); //
	CreateDynamicObject(982,-1547.8000488,2476.0000000,66.1999969,0.0000000,59.9963379,90.0000000); //
	CreateDynamicObject(5644,-1525.0999756,2403.8999023,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1525.0999756,2427.3999023,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.4000244,2403.8999023,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(5644,-1550.4000244,2427.3000488,51.4590034,0.0000000,270.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2445.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2455.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2465.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1586.0996094,2475.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2475.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2465.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2455.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1471.3994141,2445.2998047,66.4000015,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3244,-1459.5999756,2218.3000488,46.0000000,0.0000000,0.0000000,229.9987793); //
	CreateDynamicObject(1237,-1581.0000000,2478.3000488,65.5999985,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1237,-1584.0000000,2478.2998047,65.5999985,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1237,-1587.0000000,2478.2998047,65.5999985,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1237,-1587.0000000,2478.2998047,65.5999985,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1237,-1588.8000488,2472.6000977,65.0000000,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1237,-1587.8000488,2475.5000000,65.3000031,7.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1228,-1585.5999756,2478.3999023,66.0999985,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(1228,-1582.5000000,2478.3999023,66.0999985,0.0000000,0.0000000,270.0000000); //
	CreateDynamicObject(1228,-1587.4000244,2476.8999023,65.8000031,3.5000000,0.0000000,343.9999695); //
	CreateDynamicObject(1228,-1588.3000488,2474.0000000,65.5000000,5.2500000,0.0000000,339.4984131); //
	CreateDynamicObject(3666,-1587.0000000,2478.3000488,66.1999969,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1581.0000000,2478.3000488,66.1999969,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(3666,-1588.8000488,2472.6000977,65.5999985,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(978,-1581.4000244,2451.0000000,66.6999969,0.0000000,0.0000000,180.0000000); //
	CreateDynamicObject(978,-1572.0000000,2451.0000000,66.6999969,0.0000000,0.0000000,179.9945068); //
	CreateDynamicObject(978,-1564.5000000,2455.3999023,66.6999969,0.0000000,0.0000000,240.0000000); //
	CreateDynamicObject(978,-1559.9000244,2463.3999023,66.6999969,0.0000000,0.0000000,240.0000000); //
	CreateDynamicObject(1237,-1567.0999756,2451.3999023,65.8000031,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(1237,-1557.3000488,2467.8999023,65.8000031,0.0000000,0.0000000,0.0000000); //
	CreateDynamicObject(5644,-1571.6999512,2340.8000488,53.2000008,0.0000000,0.0000000,0.0000000); //

	// SLAY PLANINA AIRPORT 0.3e
	CreateDynamicObject(19456,-1181.5999756,-930.2000122,130.0000000,0.0000000,0.0000000,358.0826416); //object(cs_detrok03) (1)
	CreateDynamicObject(19456,-1181.9000244,-939.7000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (2)
	CreateDynamicObject(19456,-1182.1999512,-949.2000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (3)
	CreateDynamicObject(19456,-1182.5000000,-958.5000000,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (4)
	CreateDynamicObject(19456,-1182.8000488,-967.9000244,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (5)
	CreateDynamicObject(19456,-1183.0999756,-977.5000000,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (6)
	CreateDynamicObject(19456,-1183.4000244,-987.0000000,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (7)
	CreateDynamicObject(19456,-1183.6999512,-996.2000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (8)
	CreateDynamicObject(19456,-1184.0000000,-1005.7000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (9)
	CreateDynamicObject(19456,-1184.3000488,-1015.0999756,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (10)
	CreateDynamicObject(19456,-1176.5999756,-925.4000244,130.0000000,0.0000000,0.0000000,269.9947510); //object(cs_detrok03) (11)
	CreateDynamicObject(19456,-1167.1999512,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (12)
	CreateDynamicObject(19456,-1157.8000488,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (13)
	CreateDynamicObject(19456,-1148.5999756,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (14)
	CreateDynamicObject(19456,-1139.1999512,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (15)
	CreateDynamicObject(19456,-1129.6999512,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (16)
	CreateDynamicObject(19456,-1120.5000000,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (17)
	CreateDynamicObject(19456,-1111.0999756,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (18)
	CreateDynamicObject(19456,-1102.0000000,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (19)
	CreateDynamicObject(19456,-1092.5000000,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (20)
	CreateDynamicObject(19456,-1083.1999512,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (21)
	CreateDynamicObject(19456,-1073.9000244,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (22)
	CreateDynamicObject(19456,-1064.9000244,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (23)
	CreateDynamicObject(19456,-1055.5000000,-925.4000244,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (24)
	CreateDynamicObject(19456,-1184.5999756,-1024.5999756,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (26)
	CreateDynamicObject(19456,-1184.9000244,-1034.0000000,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (27)
	CreateDynamicObject(19456,-1185.1999512,-1043.3000488,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (28)
	CreateDynamicObject(19456,-1180.5999756,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (29)
	CreateDynamicObject(19456,-1171.1999512,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (30)
	CreateDynamicObject(19456,-1161.5999756,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (31)
	CreateDynamicObject(19456,-1152.5000000,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (32)
	CreateDynamicObject(19456,-1143.5000000,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (33)
	CreateDynamicObject(19456,-1134.0999756,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (34)
	CreateDynamicObject(19456,-1124.6999512,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (35)
	CreateDynamicObject(19456,-1115.3000488,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (36)
	CreateDynamicObject(19456,-1105.6999512,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (37)
	CreateDynamicObject(19456,-1096.3000488,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (38)
	CreateDynamicObject(19456,-1086.9000244,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (39)
	CreateDynamicObject(19456,-1077.9000244,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (40)
	CreateDynamicObject(19456,-1068.6999512,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (41)
	CreateDynamicObject(19456,-1059.5999756,-1048.0000000,130.0000000,0.0000000,0.0000000,269.9945068); //object(cs_detrok03) (42)
	CreateDynamicObject(19456,-1050.9000244,-930.0999756,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (44)
	CreateDynamicObject(19456,-1051.1999512,-939.0999756,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (45)
	CreateDynamicObject(19456,-1051.5000000,-948.0000000,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (46)
	CreateDynamicObject(19456,-1051.8000488,-957.2000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (47)
	CreateDynamicObject(19456,-1052.0999756,-966.7999878,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (48)
	CreateDynamicObject(19456,-1052.4000244,-975.7000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (49)
	CreateDynamicObject(19456,-1052.6999512,-984.7999878,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (50)
	CreateDynamicObject(19456,-1053.0000000,-993.7999878,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (51)
	CreateDynamicObject(19456,-1053.3000488,-1002.7000122,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (52)
	CreateDynamicObject(19456,-1053.5999756,-1011.9000244,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (53)
	CreateDynamicObject(19456,-1053.9000244,-1020.9000244,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (54)
	CreateDynamicObject(19456,-1054.1999512,-1030.1999512,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (55)
	CreateDynamicObject(19456,-1054.5000000,-1039.0999756,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (56)
	CreateDynamicObject(19456,-1054.5999756,-1043.1999512,130.0000000,0.0000000,0.0000000,358.0773926); //object(cs_detrok03) (57)
	CreateDynamicObject(19380,-1056.3000488,-930.4000244,131.6999969,0.0000000,90.0000000,358.0826416); //object(hosbibal_sfw) (1)
	CreateDynamicObject(19380,-1066.3000488,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (2)
	CreateDynamicObject(19380,-1076.0000000,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (3)
	CreateDynamicObject(19380,-1085.8000488,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (4)
	CreateDynamicObject(19380,-1095.5999756,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (5)
	CreateDynamicObject(19380,-1104.9000244,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (6)
	CreateDynamicObject(19380,-1115.0000000,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (7)
	CreateDynamicObject(19380,-1124.5000000,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (8)
	CreateDynamicObject(19380,-1134.3000488,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (9)
	CreateDynamicObject(19380,-1143.3000488,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (10)
	CreateDynamicObject(19380,-1152.8000488,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (11)
	CreateDynamicObject(19380,-1162.9000244,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (12)
	CreateDynamicObject(19380,-1172.8000488,-930.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (13)
	CreateDynamicObject(19380,-1176.3000488,-930.2999878,131.6999969,0.0000000,90.0000000,358.0770264); //object(hosbibal_sfw) (14)
	CreateDynamicObject(19380,-1056.0999756,-930.2000122,131.6999969,0.0000000,90.0000000,0.4079285); //object(hosbibal_sfw) (15)
	CreateDynamicObject(19380,-1176.5999756,-939.7000122,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (16)
	CreateDynamicObject(19380,-1176.9000244,-948.9000244,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (17)
	CreateDynamicObject(19380,-1177.1999512,-958.5000000,131.6999969,0.0000000,90.0000000,358.0718384); //object(hosbibal_sfw) (18)
	CreateDynamicObject(19380,-1177.5000000,-968.0000000,131.6999969,0.0000000,90.0000000,358.0718384); //object(hosbibal_sfw) (19)
	CreateDynamicObject(19380,-1177.8000488,-977.4000244,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (20)
	CreateDynamicObject(19380,-1178.0999756,-986.7999878,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (21)
	CreateDynamicObject(19380,-1178.4000244,-996.0999756,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (22)
	CreateDynamicObject(19380,-1178.6999512,-1005.2000122,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (23)
	CreateDynamicObject(19380,-1179.0000000,-1014.8000488,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (24)
	CreateDynamicObject(19380,-1179.3000488,-1024.0000000,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (25)
	CreateDynamicObject(19380,-1179.5999756,-1033.5000000,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (26)
	CreateDynamicObject(19380,-1179.9000244,-1042.0999756,131.6999969,0.0000000,90.0000000,358.0718384); //object(hosbibal_sfw) (27)
	CreateDynamicObject(19380,-1180.0000000,-1043.4000244,131.6999969,0.0000000,90.0000000,359.9891968); //object(hosbibal_sfw) (28)
	CreateDynamicObject(19380,-1056.5000000,-939.4000244,131.6999969,0.0000000,90.0000000,358.4891357); //object(hosbibal_sfw) (29)
	CreateDynamicObject(19380,-1056.8000488,-948.7000122,131.6999969,0.0000000,90.0000000,358.4837646); //object(hosbibal_sfw) (30)
	CreateDynamicObject(19380,-1057.0000000,-957.9000244,131.6999969,0.0000000,90.0000000,358.4782715); //object(hosbibal_sfw) (31)
	CreateDynamicObject(19380,-1057.3000488,-966.9000244,131.6999969,0.0000000,90.0000000,358.4783020); //object(hosbibal_sfw) (32)
	CreateDynamicObject(19380,-1057.5999756,-976.2999878,131.6999969,0.0000000,90.0000000,358.4782715); //object(hosbibal_sfw) (33)
	CreateDynamicObject(19380,-1057.9000244,-985.5999756,131.6999969,0.0000000,90.0000000,358.4781799); //object(hosbibal_sfw) (34)
	CreateDynamicObject(19380,-1058.1999512,-994.5999756,131.6999969,0.0000000,90.0000000,358.4728394); //object(hosbibal_sfw) (35)
	CreateDynamicObject(19380,-1058.5000000,-1003.7999878,131.6999969,0.0000000,90.0000000,358.4728394); //object(hosbibal_sfw) (37)
	CreateDynamicObject(19380,-1059.0000000,-1013.2000122,131.6999969,0.0000000,90.0000000,358.4728394); //object(hosbibal_sfw) (38)
	CreateDynamicObject(19380,-1059.1999512,-1022.5999756,131.6999969,0.0000000,90.0000000,358.4728394); //object(hosbibal_sfw) (39)
	CreateDynamicObject(19380,-1059.5000000,-1032.1999512,131.6999969,0.0000000,90.0000000,358.4728394); //object(hosbibal_sfw) (40)
	CreateDynamicObject(19380,-1059.8000488,-1041.5999756,131.6999969,0.0000000,90.0000000,358.4729004); //object(hosbibal_sfw) (41)
	CreateDynamicObject(19380,-1169.5000000,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (42)
	CreateDynamicObject(19380,-1159.5999756,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (43)
	CreateDynamicObject(19380,-1149.5000000,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (44)
	CreateDynamicObject(19380,-1139.0000000,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (45)
	CreateDynamicObject(19380,-1128.6999512,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (46)
	CreateDynamicObject(19380,-1118.3000488,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (47)
	CreateDynamicObject(19380,-1108.1999512,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (48)
	CreateDynamicObject(19380,-1098.0000000,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890442); //object(hosbibal_sfw) (49)
	CreateDynamicObject(19380,-1087.9000244,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (50)
	CreateDynamicObject(19380,-1078.5000000,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890442); //object(hosbibal_sfw) (51)
	CreateDynamicObject(19380,-1068.9000244,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (52)
	CreateDynamicObject(19380,-1060.0000000,-1043.1999512,131.6999969,0.0000000,90.0000000,359.9890137); //object(hosbibal_sfw) (53)
	CreateDynamicObject(19380,-1066.4000244,-938.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (54)
	CreateDynamicObject(19380,-1066.5000000,-948.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (55)
	CreateDynamicObject(19380,-1066.9000244,-957.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (56)
	CreateDynamicObject(19380,-1066.9000244,-966.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (57)
	CreateDynamicObject(19380,-1067.0999756,-975.4000244,131.6999969,0.0000000,90.0000000,358.0770264); //object(hosbibal_sfw) (58)
	CreateDynamicObject(19380,-1067.6999512,-984.9000244,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (59)
	CreateDynamicObject(19380,-1068.1999512,-994.4000244,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (60)
	CreateDynamicObject(19380,-1068.0000000,-1003.7000122,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (61)
	CreateDynamicObject(19380,-1068.4000244,-1012.7999878,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (62)
	CreateDynamicObject(19380,-1069.0000000,-1021.7000122,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (63)
	CreateDynamicObject(19380,-1069.3000488,-1030.5000000,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (64)
	CreateDynamicObject(19380,-1069.5000000,-1037.8000488,131.6999969,0.0000000,90.0000000,358.0718994); //object(hosbibal_sfw) (65)
	CreateDynamicObject(19380,-1075.8000488,-939.5000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (66)
	CreateDynamicObject(19380,-1076.0000000,-948.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (67)
	CreateDynamicObject(19380,-1075.5999756,-957.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (68)
	CreateDynamicObject(19380,-1076.1999512,-965.9000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (69)
	CreateDynamicObject(19380,-1076.0999756,-974.9000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (70)
	CreateDynamicObject(19380,-1076.1999512,-983.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (71)
	CreateDynamicObject(19380,-1077.0000000,-993.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (72)
	CreateDynamicObject(19380,-1076.8000488,-1002.5000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (73)
	CreateDynamicObject(19380,-1077.4000244,-1011.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (74)
	CreateDynamicObject(19380,-1078.1999512,-1020.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (75)
	CreateDynamicObject(19380,-1078.5000000,-1030.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (76)
	CreateDynamicObject(19380,-1078.9000244,-1038.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (77)
	CreateDynamicObject(19380,-1084.8000488,-939.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (78)
	CreateDynamicObject(19380,-1085.4000244,-949.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (79)
	CreateDynamicObject(19380,-1085.3000488,-958.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (80)
	CreateDynamicObject(19380,-1085.9000244,-967.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (81)
	CreateDynamicObject(19380,-1085.9000244,-976.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (82)
	CreateDynamicObject(19380,-1086.0000000,-985.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (83)
	CreateDynamicObject(19380,-1086.4000244,-994.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (84)
	CreateDynamicObject(19380,-1086.6999512,-1003.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (85)
	CreateDynamicObject(19380,-1087.0999756,-1013.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (86)
	CreateDynamicObject(19380,-1088.0000000,-1022.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (87)
	CreateDynamicObject(19380,-1088.1999512,-1031.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (88)
	CreateDynamicObject(19380,-1088.5999756,-1038.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (89)
	CreateDynamicObject(19380,-1094.8000488,-939.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (90)
	CreateDynamicObject(19380,-1094.9000244,-948.7999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (91)
	CreateDynamicObject(19380,-1095.0000000,-958.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (92)
	CreateDynamicObject(19380,-1095.1999512,-967.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (93)
	CreateDynamicObject(19380,-1095.1999512,-976.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (94)
	CreateDynamicObject(19380,-1095.8000488,-986.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (95)
	CreateDynamicObject(19380,-1095.5999756,-995.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (96)
	CreateDynamicObject(19380,-1096.0000000,-1004.5000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (97)
	CreateDynamicObject(19380,-1097.0000000,-1013.7999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (98)
	CreateDynamicObject(19380,-1097.5000000,-1023.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (99)
	CreateDynamicObject(19380,-1098.0999756,-1032.5000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (100)
	CreateDynamicObject(19380,-1098.3000488,-1038.1999512,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (101)
	CreateDynamicObject(19380,-1103.9000244,-939.7000122,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (102)
	CreateDynamicObject(19380,-1104.1999512,-948.9000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (103)
	CreateDynamicObject(19380,-1104.6999512,-958.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (104)
	CreateDynamicObject(19380,-1104.8000488,-967.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (105)
	CreateDynamicObject(19380,-1104.8000488,-976.9000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (106)
	CreateDynamicObject(19380,-1105.3000488,-986.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (107)
	CreateDynamicObject(19380,-1105.1999512,-994.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (108)
	CreateDynamicObject(19380,-1105.5999756,-1004.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (109)
	CreateDynamicObject(19380,-1106.3000488,-1013.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (110)
	CreateDynamicObject(19380,-1106.6999512,-1022.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (111)
	CreateDynamicObject(19380,-1107.0000000,-1031.8000488,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (112)
	CreateDynamicObject(19380,-1107.6999512,-1038.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (113)
	CreateDynamicObject(19380,-1116.1999512,-1034.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (114)
	CreateDynamicObject(19380,-1115.6999512,-1025.3000488,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (115)
	CreateDynamicObject(19380,-1115.9000244,-1017.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (116)
	CreateDynamicObject(19380,-1115.3000488,-1008.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (117)
	CreateDynamicObject(19380,-1115.0000000,-1000.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (118)
	CreateDynamicObject(19380,-1114.9000244,-991.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (119)
	CreateDynamicObject(19380,-1114.4000244,-983.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (120)
	CreateDynamicObject(19380,-1114.5000000,-975.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (121)
	CreateDynamicObject(19380,-1114.5999756,-966.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (122)
	CreateDynamicObject(19380,-1114.1999512,-956.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (123)
	CreateDynamicObject(19380,-1114.0000000,-948.0000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (124)
	CreateDynamicObject(19380,-1113.9000244,-939.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (125)
	CreateDynamicObject(19380,-1123.4000244,-939.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (126)
	CreateDynamicObject(19380,-1123.4000244,-948.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (127)
	CreateDynamicObject(19380,-1123.5999756,-957.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (128)
	CreateDynamicObject(19380,-1124.3000488,-966.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (129)
	CreateDynamicObject(19380,-1124.5000000,-976.0000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (130)
	CreateDynamicObject(19380,-1124.3000488,-985.2999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (131)
	CreateDynamicObject(19380,-1124.9000244,-994.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (132)
	CreateDynamicObject(19380,-1124.9000244,-1003.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (133)
	CreateDynamicObject(19380,-1124.6999512,-1011.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (134)
	CreateDynamicObject(19380,-1125.4000244,-1019.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (135)
	CreateDynamicObject(19380,-1125.6999512,-1028.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (136)
	CreateDynamicObject(19380,-1126.3000488,-1037.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (137)
	CreateDynamicObject(19380,-1135.8000488,-1033.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (138)
	CreateDynamicObject(19380,-1135.1999512,-1024.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (139)
	CreateDynamicObject(19380,-1134.5999756,-1015.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (140)
	CreateDynamicObject(19380,-1134.3000488,-1007.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (141)
	CreateDynamicObject(19380,-1134.9000244,-999.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (142)
	CreateDynamicObject(19380,-1134.3000488,-992.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (143)
	CreateDynamicObject(19380,-1134.3000488,-983.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (144)
	CreateDynamicObject(19380,-1134.4000244,-974.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (145)
	CreateDynamicObject(19380,-1133.8000488,-965.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (146)
	CreateDynamicObject(19380,-1133.0000000,-957.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (147)
	CreateDynamicObject(19380,-1133.5000000,-950.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (148)
	CreateDynamicObject(19380,-1133.4000244,-942.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (149)
	CreateDynamicObject(19380,-1133.0999756,-935.7999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (150)
	CreateDynamicObject(19380,-1142.9000244,-939.0000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (151)
	CreateDynamicObject(19380,-1143.1999512,-947.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (152)
	CreateDynamicObject(19380,-1142.1999512,-956.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (153)
	CreateDynamicObject(19380,-1143.4000244,-965.0000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (154)
	CreateDynamicObject(19380,-1144.0999756,-974.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (155)
	CreateDynamicObject(19380,-1144.1999512,-983.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (156)
	CreateDynamicObject(19380,-1144.1999512,-993.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (157)
	CreateDynamicObject(19380,-1144.1999512,-1002.7999878,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (158)
	CreateDynamicObject(19380,-1144.0000000,-1011.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (159)
	CreateDynamicObject(19380,-1144.0999756,-1021.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (160)
	CreateDynamicObject(19380,-1144.8000488,-1030.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (161)
	CreateDynamicObject(19380,-1145.1999512,-1036.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (162)
	CreateDynamicObject(19380,-1136.0000000,-1037.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (163)
	CreateDynamicObject(19380,-1154.9000244,-1034.3000488,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (164)
	CreateDynamicObject(19380,-1153.9000244,-1024.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (165)
	CreateDynamicObject(19380,-1153.8000488,-1015.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (166)
	CreateDynamicObject(19380,-1154.0000000,-1006.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (167)
	CreateDynamicObject(19380,-1154.0999756,-997.7999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (168)
	CreateDynamicObject(19380,-1154.0999756,-988.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (169)
	CreateDynamicObject(19380,-1154.0000000,-980.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (170)
	CreateDynamicObject(19380,-1153.5999756,-970.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (171)
	CreateDynamicObject(19380,-1152.5000000,-961.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (172)
	CreateDynamicObject(19380,-1152.3000488,-953.2000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (173)
	CreateDynamicObject(19380,-1153.0000000,-943.5999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (174)
	CreateDynamicObject(19380,-1152.6999512,-936.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (175)
	CreateDynamicObject(19380,-1162.5999756,-938.4000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (176)
	CreateDynamicObject(19380,-1170.0999756,-939.0999756,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (177)
	CreateDynamicObject(19380,-1162.4000244,-947.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (178)
	CreateDynamicObject(19380,-1169.3000488,-947.9000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (179)
	CreateDynamicObject(19380,-1162.1999512,-955.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (180)
	CreateDynamicObject(19380,-1168.8000488,-956.5000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (181)
	CreateDynamicObject(19380,-1162.0999756,-964.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (182)
	CreateDynamicObject(19380,-1169.6999512,-965.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (183)
	CreateDynamicObject(19380,-1164.0000000,-973.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (184)
	CreateDynamicObject(19380,-1172.0000000,-974.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (185)
	CreateDynamicObject(19380,-1164.4000244,-982.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (186)
	CreateDynamicObject(19380,-1171.5999756,-983.5000000,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (187)
	CreateDynamicObject(19380,-1162.8000488,-991.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (188)
	CreateDynamicObject(19380,-1170.9000244,-992.4000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (189)
	CreateDynamicObject(19380,-1162.3000488,-1000.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (190)
	CreateDynamicObject(19380,-1162.4000244,-1009.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (191)
	CreateDynamicObject(19380,-1162.5999756,-1018.2999878,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (192)
	CreateDynamicObject(19380,-1163.0999756,-1026.9000244,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (193)
	CreateDynamicObject(19380,-1165.0999756,-1035.1999512,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (194)
	CreateDynamicObject(19380,-1173.1999512,-1037.3000488,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (195)
	CreateDynamicObject(19380,-1171.1999512,-1028.0999756,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (196)
	CreateDynamicObject(19380,-1170.9000244,-1018.5000000,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (197)
	CreateDynamicObject(19380,-1171.0999756,-1009.7000122,131.6999969,0.0000000,90.0000000,359.9945374); //object(hosbibal_sfw) (198)
	CreateDynamicObject(19380,-1170.3000488,-1000.9000244,131.6999969,0.0000000,90.0000000,359.9945068); //object(hosbibal_sfw) (199)
	CreateDynamicObject(8251,-1064.9000244,-938.2999878,135.6999969,0.0000000,0.0000000,178.0826416); //object(pltschlhnger02_lvs) (1)
	CreateDynamicObject(8247,-1066.8000488,-971.2000122,135.6999969,0.0000000,0.0000000,178.0826416); //object(pltschlhnger69_lvs) (1)
	CreateDynamicObject(8247,-1068.4000244,-1006.0999756,135.6999969,0.0000000,0.0000000,178.0773926); //object(pltschlhnger69_lvs) (2)
	CreateDynamicObject(8251,-1069.5000000,-1034.6999512,135.6999969,0.0000000,0.0000000,178.0773926); //object(pltschlhnger02_lvs) (2)
	CreateDynamicObject(8550,-1116.6999512,-1029.8000488,136.0000000,0.0000000,0.0000000,0.0000000); //object(laconcha_lvs) (1)
	CreateDynamicObject(9241,-1166.1999512,-1027.0999756,133.8000031,0.0000000,0.0000000,0.0000000); //object(copbits_sfn) (1)
	CreateDynamicObject(10757,-1069.9000244,-978.0999756,141.1999969,0.0000000,0.0000000,280.0000000); //object(airport_04_sfse) (1)
	CreateDynamicObject(10810,-1095.1999512,-916.5999756,133.1999969,0.0000000,0.0000000,20.0000000); //object(ap_smallradar1_sfse) (1)

	// LV AIRPORT + HELIPAD (SLAY) - KOD TVORNICE
	CreateDynamicObject(3998,2774.2998047,2682.3994141,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (1)
	CreateDynamicObject(3998,2798.3999023,2682.3999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (2)
	CreateDynamicObject(3998,2823.1000977,2682.3999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (5)
	CreateDynamicObject(3998,2774.3000488,2702.8999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (6)
	CreateDynamicObject(3998,2774.3000488,2723.1000977,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (7)
	CreateDynamicObject(3998,2774.3000488,2743.8000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (8)
	CreateDynamicObject(3998,2774.2998047,2764.1992188,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (9)
	CreateDynamicObject(3998,2774.3000488,2783.6999512,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (10)
	CreateDynamicObject(3998,2774.2998047,2803.5996094,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (11)
	CreateDynamicObject(3998,2774.3000488,2822.6999512,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (12)
	CreateDynamicObject(3998,2774.3000488,2841.1000977,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (13)
	CreateDynamicObject(3998,2823.1000977,2701.6999512,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (14)
	CreateDynamicObject(3998,2823.1000977,2720.3999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (15)
	CreateDynamicObject(3998,2823.1000977,2739.3000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (16)
	CreateDynamicObject(3998,2823.1000977,2758.3999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (17)
	CreateDynamicObject(3998,2823.1000977,2777.6000977,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (18)
	CreateDynamicObject(3998,2823.1000977,2796.3000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (19)
	CreateDynamicObject(3998,2823.1000977,2815.3000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (20)
	CreateDynamicObject(3998,2823.1000977,2833.8000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (21)
	CreateDynamicObject(3998,2796.8000488,2701.6999512,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (22)
	CreateDynamicObject(3998,2803.6000977,2701.8999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (23)
	CreateDynamicObject(3998,2798.8999023,2721.8000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (24)
	CreateDynamicObject(3998,2798.3000488,2742.3000488,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (25)
	CreateDynamicObject(3998,2798.6000977,2762.3999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (26)
	CreateDynamicObject(3998,2798.6000977,2781.3999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (27)
	CreateDynamicObject(3998,2798.1000977,2802.0000000,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (28)
	CreateDynamicObject(3998,2798.8000488,2821.8999023,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (29)
	CreateDynamicObject(3998,2799.1999512,2841.1000977,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (30)
	CreateDynamicObject(3998,2823.1000977,2841.1000977,-1.0000000,0.0000000,0.0000000,179.9945068); //object(court1_lan) (31)
	CreateDynamicObject(3578,2775.5000000,2668.6999512,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (1)
	CreateDynamicObject(3578,2775.5000000,2677.5000000,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (2)
	CreateDynamicObject(3578,2775.5000000,2686.8999023,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (3)
	CreateDynamicObject(3578,2775.5000000,2696.3000488,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (4)
	CreateDynamicObject(3578,2775.5000000,2705.6000977,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (5)
	CreateDynamicObject(3578,2775.5000000,2715.6000977,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (6)
	CreateDynamicObject(3578,2775.5000000,2725.6999512,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (7)
	CreateDynamicObject(3578,2775.5000000,2735.8000488,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (8)
	CreateDynamicObject(3578,2775.5000000,2745.5000000,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (9)
	CreateDynamicObject(3578,2775.5000000,2755.6000977,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (10)
	CreateDynamicObject(3578,2775.5000000,2765.8999023,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (11)
	CreateDynamicObject(3578,2775.5000000,2776.0000000,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (12)
	CreateDynamicObject(3578,2775.5000000,2786.1000977,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (13)
	CreateDynamicObject(3578,2775.5000000,2796.1000977,11.5000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (14)
	CreateDynamicObject(3578,2779.1000977,2804.6000977,11.5000000,0.0000000,0.0000000,223.9836731); //object(dockbarr1_la) (15)
	CreateDynamicObject(1682,2828.3999023,2786.5000000,18.7000008,0.0000000,0.0000000,130.0000000); //object(ap_radar1_01) (1)
	CreateDynamicObject(4832,2824.1000977,2686.6000977,52.5999985,0.0000000,0.0000000,270.0000000); //object(airtwer_las) (1)
	CreateDynamicObject(4874,2849.3999023,2731.1000977,15.0000000,0.0000000,0.0000000,180.0000000); //object(helipad1_las) (1)
	CreateDynamicObject(7981,2774.0000000,2852.3999023,14.8000002,0.0000000,0.0000000,0.0000000); //object(smallradar02_lvs) (1)
	CreateDynamicObject(8249,2816.3000488,2759.6000977,16.2000008,0.0000000,0.0000000,180.0000000); //object(pltschlhnger70_lvs) (1)
	CreateDynamicObject(8253,2811.6999512,2822.8999023,16.2000008,0.0000000,0.0000000,210.0000000); //object(pltschlhnger01_lvs) (1)
	CreateDynamicObject(3578,2779.0000000,2794.8000488,11.5000000,0.0000000,0.0000000,226.9917755); //object(dockbarr1_la) (16)
	CreateDynamicObject(8550,2775.8000488,2826.5000000,16.5000000,0.0000000,0.0000000,88.0826721); //object(laconcha_lvs) (1)
	CreateDynamicObject(10757,2807.0000000,2819.8999023,22.5000000,0.0000000,0.0000000,292.3305664); //object(airport_04_sfse) (1)
	CreateDynamicObject(1231,2798.0000000,2665.6999512,15.0000000,0.0000000,0.0000000,0.0000000); //object(streetlamp2) (1)
	CreateDynamicObject(1231,2797.3000488,2730.1000977,15.0000000,0.0000000,0.0000000,0.0000000); //object(streetlamp2) (2)
	CreateDynamicObject(1231,2803.0000000,2786.1000977,15.0000000,0.0000000,0.0000000,0.0000000); //object(streetlamp2) (3)
	CreateDynamicObject(1231,2792.6000977,2825.6000977,15.0000000,0.0000000,0.0000000,310.0000000); //object(streetlamp2) (4)
	CreateDynamicObject(1231,2762.8999023,2815.3999023,15.0000000,0.0000000,0.0000000,309.9957275); //object(streetlamp2) (5)
	return (true);
}

stock IsABoat(carid)
{
   for(new i=0;i<sizeof(Brod);i++)
   {
	  if(carid == Brod[i])
	  {
		  return (true);
	  }
   }
   return (false);
}

stock Truck(carid)
{
   for(new i=0;i<sizeof(Kamioni);i++)
   {
	  if(carid == Kamioni[i])
	  {
		  return (true);
	  }
   }
   return (false);
}

stock TaxiGrad(playerid)
{
   for(new i=0;i<sizeof(TaxiAutiLS);i++)
   {
	  if(GetPlayerVehicleID(playerid) == TaxiAutiLS[i])
	  {
		  return 1;
	  }
   }
   for(new i=0;i<sizeof(TaxiAutiLV);i++)
   {
	  if(GetPlayerVehicleID(playerid) == TaxiAutiLV[i])
	  {
		  return 2;
	  }
   }
   for(new i=0;i<sizeof(TaxiAutiSF);i++)
   {
	  if(GetPlayerVehicleID(playerid) == TaxiAutiSF[i])
	  {
		  return 3;
	  }
   }
   return (false);
}

stock TaxiAuto(carid)
{
   for(new i=0;i<sizeof(TaxiAutiLS);i++)
   {
	  if(carid == TaxiAutiLS[i])
	  {
		  return (true);
	  }
   }
   for(new i2=0;i2<sizeof(TaxiAutiLV);i2++)
   {
	  if(carid == TaxiAutiLV[i2])
	  {
		  return (true);
	  }
   }
   for(new i3=0;i3<sizeof(TaxiAutiSF);i3++)
   {
	  if(carid == TaxiAutiSF[i3])
	  {
		  return (true);
	  }
   }
   return (false);
}

stock MedicinskiAvion(carid)
{
   for(new i=0;i<sizeof(MedicinskiPiloti);i++)
   {
	  if(carid == MedicinskiPiloti[i])
	  {
		  return (true);
	  }
   }
   return (false);
}

stock VojniAvion(carid)
{
	for(new i=0;i<sizeof(VojniPiloti);i++)
	{
	   if(carid == VojniPiloti[i])
	   {
		  return (true);
	   }
	}
	return (false);
}

stock VojniHeli(carid)
{
	for(new i=0;i<sizeof(vojni_Heli);i++)
	{
	   if(carid == vojni_Heli[i])
	   {
		  return (true);
	   }
	}
	return (false);
}

stock CivilniAvion(carid)
{
    for(new i=0;i<sizeof(CivilniAvioni);i++)
	{
	   if(carid == CivilniAvioni[i])
	   {
		  return (true);
	   }
	}
	return (false);
}

stock create3Dtext()
{
	new string[30];
    for(new i=0;i<sizeof(CivilniAvioni);i++)
	{
	   format(string, (sizeof string), "%s",VehicleNames[GetVehicleModel(CivilniAvioni[i])-400]);
	   D3TEXT[CivilniAvioni[i]] = Create3DTextLabel(string, 0xF0F0F0FF, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	   Attach3DTextLabelToVehicle(D3TEXT[CivilniAvioni[i]] , CivilniAvioni[i], 0.0, 0.0, 0.5);
	}
	for(new i=0;i<sizeof(vojni_Heli);i++)
	{
	   format(string, (sizeof string), "%s",VehicleNames[GetVehicleModel(vojni_Heli[i])-400]);
	   D3TEXT[vojni_Heli[i]] = Create3DTextLabel(string, 0xF0F0F0FF, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	   Attach3DTextLabelToVehicle(D3TEXT[vojni_Heli[i]] , vojni_Heli[i], 0.0, 0.0, 0.5);
	}
	for(new i=0;i<sizeof(VojniPiloti);i++)
	{
       format(string, (sizeof string), "%s",VehicleNames[GetVehicleModel(VojniPiloti[i])-400]);
	   D3TEXT[VojniPiloti[i]] = Create3DTextLabel(string, 0xF0F0F0FF, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	   Attach3DTextLabelToVehicle(D3TEXT[VojniPiloti[i]] , VojniPiloti[i], 0.0, 0.0, 0.5);
	}
	for(new i=0;i<sizeof(MedicinskiPiloti);i++)
    {
       format(string, (sizeof string), "%s",VehicleNames[GetVehicleModel(MedicinskiPiloti[i])-400]);
	   D3TEXT[MedicinskiPiloti[i]] = Create3DTextLabel(string, 0xF0F0F0FF, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	   Attach3DTextLabelToVehicle(D3TEXT[MedicinskiPiloti[i]] , MedicinskiPiloti[i], 0.0, 0.0, 0.5);
    }
    for(new i=0;i<sizeof(Kamioni);i++)
    {
	   format(string, (sizeof string), "%s",VehicleNames[GetVehicleModel(Kamioni[i])-400]);
	   D3TEXT[Kamioni[i]] = Create3DTextLabel(string, 0xF0F0F0FF, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	   Attach3DTextLabelToVehicle(D3TEXT[Kamioni[i]] , Kamioni[i], 0.0, 0.0, 0.5);
    }
    for(new i=0;i<sizeof(Brod);i++)
    {
       format(string, (sizeof string), "%s",VehicleNames[GetVehicleModel(Brod[i])-400]);
	   D3TEXT[Brod[i]] = Create3DTextLabel(string, 0xF0F0F0FF, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	   Attach3DTextLabelToVehicle(D3TEXT[Brod[i]] , Brod[i], 0.0, 0.0, 0.5);
    }
}

enum MainZone{
Zone_Name[28], Float:Zone_Area[6] };
static const SA_GPS_ZONE_NAMES[][MainZone] = {

	{"The Big Ear",	                {-410.00,1403.30,-3.00,-137.90,1681.20,200.00}},
	{"Aldea Malvada",               {-1372.10,2498.50,0.00,-1277.50,2615.30,200.00}},
	{"Angel Pine",                  {-2324.90,-2584.20,-6.10,-1964.20,-2212.10,200.00}},
	{"Arco del Oeste",              {-901.10,2221.80,0.00,-592.00,2571.90,200.00}},
	{"Avispa Country",         {-2646.40,-355.40,0.00,-2270.00,-222.50,200.00}},
	{"Avispa Country",         {-2831.80,-430.20,-6.10,-2646.40,-222.50,200.00}},
	{"Avispa Country",         {-2361.50,-417.10,0.00,-2270.00,-355.40,200.00}},
	{"Avispa Country",         {-2667.80,-302.10,-28.80,-2646.40,-262.30,71.10}},
	{"Avispa Country",         {-2470.00,-355.40,0.00,-2270.00,-318.40,46.10}},
	{"Avispa Country",         {-2550.00,-355.40,0.00,-2470.00,-318.40,39.70}},
	{"Back o Beyond",               {-1166.90,-2641.10,0.00,-321.70,-1856.00,200.00}},
	{"Battery Point",               {-2741.00,1268.40,-4.50,-2533.00,1490.40,200.00}},
	{"Bayside",                     {-2741.00,2175.10,0.00,-2353.10,2722.70,200.00}},
	{"Bayside Marina",              {-2353.10,2275.70,0.00,-2153.10,2475.70,200.00}},
	{"Beacon Hill",                 {-399.60,-1075.50,-1.40,-319.00,-977.50,198.50}},
	{"Blackfield",                  {964.30,1203.20,-89.00,1197.30,1403.20,110.90}},
	{"Blackfield",                  {964.30,1403.20,-89.00,1197.30,1726.20,110.90}},
	{"Blackfield Chapel",           {1375.60,596.30,-89.00,1558.00,823.20,110.90}},
	{"Blackfield Chapel",           {1325.60,596.30,-89.00,1375.60,795.00,110.90}},
	{"Blackfield Section",     {1197.30,1044.60,-89.00,1277.00,1163.30,110.90}},
	{"Blackfield Section",     {1166.50,795.00,-89.00,1375.60,1044.60,110.90}},
	{"Blackfield Section",     {1277.00,1044.60,-89.00,1315.30,1087.60,110.90}},
	{"Blackfield Section",     {1375.60,823.20,-89.00,1457.30,919.40,110.90}},
	{"Blueberry",                   {104.50,-220.10,2.30,349.60,152.20,200.00}},
	{"Blueberry",                   {19.60,-404.10,3.80,349.60,-220.10,200.00}},
	{"Blueberry Acres",             {-319.60,-220.10,0.00,104.50,293.30,200.00}},
	{"Caligula's Palace",           {2087.30,1543.20,-89.00,2437.30,1703.20,110.90}},
	{"Caligula's Palace",           {2137.40,1703.20,-89.00,2437.30,1783.20,110.90}},
	{"Calton Heights",              {-2274.10,744.10,-6.10,-1982.30,1358.90,200.00}},
	{"Chinatown",                   {-2274.10,578.30,-7.60,-2078.60,744.10,200.00}},
	{"City Hall",                   {-2867.80,277.40,-9.10,-2593.40,458.40,200.00}},
	{"Come-A-Lot",                  {2087.30,943.20,-89.00,2623.10,1203.20,110.90}},
	{"Commerce",                    {1323.90,-1842.20,-89.00,1701.90,-1722.20,110.90}},
	{"Commerce",                    {1323.90,-1722.20,-89.00,1440.90,-1577.50,110.90}},
	{"Commerce",                    {1370.80,-1577.50,-89.00,1463.90,-1384.90,110.90}},
	{"Commerce",                    {1463.90,-1577.50,-89.00,1667.90,-1430.80,110.90}},
	{"Commerce",                    {1583.50,-1722.20,-89.00,1758.90,-1577.50,110.90}},
	{"Commerce",                    {1667.90,-1577.50,-89.00,1812.60,-1430.80,110.90}},
	{"Conference Center",           {1046.10,-1804.20,-89.00,1323.90,-1722.20,110.90}},
	{"Conference Center",           {1073.20,-1842.20,-89.00,1323.90,-1804.20,110.90}},
	{"Cranberry Station",           {-2007.80,56.30,0.00,-1922.00,224.70,100.00}},
	{"Creek",                       {2749.90,1937.20,-89.00,2921.60,2669.70,110.90}},
	{"Dillimore",                   {580.70,-674.80,-9.50,861.00,-404.70,200.00}},
	{"Doherty",                     {-2270.00,-324.10,-0.00,-1794.90,-222.50,200.00}},
	{"Doherty",                     {-2173.00,-222.50,-0.00,-1794.90,265.20,200.00}},
	{"Downtown",                    {-1982.30,744.10,-6.10,-1871.70,1274.20,200.00}},
	{"Downtown",                    {-1871.70,1176.40,-4.50,-1620.30,1274.20,200.00}},
	{"Downtown",                    {-1700.00,744.20,-6.10,-1580.00,1176.50,200.00}},
	{"Downtown",                    {-1580.00,744.20,-6.10,-1499.80,1025.90,200.00}},
	{"Downtown",                    {-2078.60,578.30,-7.60,-1499.80,744.20,200.00}},
	{"Downtown",                    {-1993.20,265.20,-9.10,-1794.90,578.30,200.00}},
	{"Downtown Los Santos",         {1463.90,-1430.80,-89.00,1724.70,-1290.80,110.90}},
	{"Downtown Los Santos",         {1724.70,-1430.80,-89.00,1812.60,-1250.90,110.90}},
	{"Downtown Los Santos",         {1463.90,-1290.80,-89.00,1724.70,-1150.80,110.90}},
	{"Downtown Los Santos",         {1370.80,-1384.90,-89.00,1463.90,-1170.80,110.90}},
	{"Downtown Los Santos",         {1724.70,-1250.90,-89.00,1812.60,-1150.80,110.90}},
	{"Downtown Los Santos",         {1370.80,-1170.80,-89.00,1463.90,-1130.80,110.90}},
	{"Downtown Los Santos",         {1378.30,-1130.80,-89.00,1463.90,-1026.30,110.90}},
	{"Downtown Los Santos",         {1391.00,-1026.30,-89.00,1463.90,-926.90,110.90}},
	{"Downtown Los Santos",         {1507.50,-1385.20,110.90,1582.50,-1325.30,335.90}},
	{"East Beach",                  {2632.80,-1852.80,-89.00,2959.30,-1668.10,110.90}},
	{"East Beach",                  {2632.80,-1668.10,-89.00,2747.70,-1393.40,110.90}},
	{"East Beach",                  {2747.70,-1668.10,-89.00,2959.30,-1498.60,110.90}},
	{"East Beach",                  {2747.70,-1498.60,-89.00,2959.30,-1120.00,110.90}},
	{"East Los Santos",             {2421.00,-1628.50,-89.00,2632.80,-1454.30,110.90}},
	{"East Los Santos",             {2222.50,-1628.50,-89.00,2421.00,-1494.00,110.90}},
	{"East Los Santos",             {2266.20,-1494.00,-89.00,2381.60,-1372.00,110.90}},
	{"East Los Santos",             {2381.60,-1494.00,-89.00,2421.00,-1454.30,110.90}},
	{"East Los Santos",             {2281.40,-1372.00,-89.00,2381.60,-1135.00,110.90}},
	{"East Los Santos",             {2381.60,-1454.30,-89.00,2462.10,-1135.00,110.90}},
	{"East Los Santos",             {2462.10,-1454.30,-89.00,2581.70,-1135.00,110.90}},
	{"Easter Basin",                {-1794.90,249.90,-9.10,-1242.90,578.30,200.00}},
	{"Easter Basin",                {-1794.90,-50.00,-0.00,-1499.80,249.90,200.00}},
	{"Easter Bay Airport",          {-1499.80,-50.00,-0.00,-1242.90,249.90,200.00}},
	{"Easter Bay Airport",          {-1794.90,-730.10,-3.00,-1213.90,-50.00,200.00}},
	{"Easter Bay Airport",          {-1213.90,-730.10,0.00,-1132.80,-50.00,200.00}},
	{"Easter Bay Airport",          {-1242.90,-50.00,0.00,-1213.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1213.90,-50.00,-4.50,-947.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1315.40,-405.30,15.40,-1264.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1354.30,-287.30,15.40,-1315.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1490.30,-209.50,15.40,-1264.40,-148.30,25.40}},
	{"Easter Bay Chemicals",        {-1132.80,-768.00,0.00,-956.40,-578.10,200.00}},
	{"Easter Bay Chemicals",        {-1132.80,-787.30,0.00,-956.40,-768.00,200.00}},
	{"El Castillo del",      {-464.50,2217.60,0.00,-208.50,2580.30,200.00}},
	{"El Castillo del",      {-208.50,2123.00,-7.60,114.00,2337.10,200.00}},
	{"El Castillo del",      {-208.50,2337.10,0.00,8.40,2487.10,200.00}},
	{"El Corona",                   {1812.60,-2179.20,-89.00,1970.60,-1852.80,110.90}},
	{"El Corona",                   {1692.60,-2179.20,-89.00,1812.60,-1842.20,110.90}},
	{"El Quebrados",                {-1645.20,2498.50,0.00,-1372.10,2777.80,200.00}},
	{"Esplanade East",              {-1620.30,1176.50,-4.50,-1580.00,1274.20,200.00}},
	{"Esplanade East",              {-1580.00,1025.90,-6.10,-1499.80,1274.20,200.00}},
	{"Esplanade East",              {-1499.80,578.30,-79.60,-1339.80,1274.20,20.30}},
	{"Esplanade North",             {-2533.00,1358.90,-4.50,-1996.60,1501.20,200.00}},
	{"Esplanade North",             {-1996.60,1358.90,-4.50,-1524.20,1592.50,200.00}},
	{"Esplanade North",             {-1982.30,1274.20,-4.50,-1524.20,1358.90,200.00}},
	{"Fallen Tree",                 {-792.20,-698.50,-5.30,-452.40,-380.00,200.00}},
	{"Fallow Bridge",               {434.30,366.50,0.00,603.00,555.60,200.00}},
	{"Fern Ridge",                  {508.10,-139.20,0.00,1306.60,119.50,200.00}},
	{"Financial",                   {-1871.70,744.10,-6.10,-1701.30,1176.40,300.00}},
	{"Fisher's Lagoon",             {1916.90,-233.30,-100.00,2131.70,13.80,200.00}},
	{"Flint Intersection",          {-187.70,-1596.70,-89.00,17.00,-1276.60,110.90}},
	{"Flint Range",                 {-594.10,-1648.50,0.00,-187.70,-1276.60,200.00}},
	{"Fort Carson",                 {-376.20,826.30,-3.00,123.70,1220.40,200.00}},
	{"Foster Valley",               {-2270.00,-430.20,-0.00,-2178.60,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-599.80,-0.00,-1794.90,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-1115.50,0.00,-1794.90,-599.80,200.00}},
	{"Foster Valley",               {-2178.60,-1250.90,0.00,-1794.90,-1115.50,200.00}},
	{"Frederick Bridge",            {2759.20,296.50,0.00,2774.20,594.70,200.00}},
	{"Gant Bridge",                 {-2741.40,1659.60,-6.10,-2616.40,2175.10,200.00}},
	{"Gant Bridge",                 {-2741.00,1490.40,-6.10,-2616.40,1659.60,200.00}},
	{"Ganton",                      {2222.50,-1852.80,-89.00,2632.80,-1722.30,110.90}},
	{"Ganton",                      {2222.50,-1722.30,-89.00,2632.80,-1628.50,110.90}},
	{"Garcia",                      {-2411.20,-222.50,-0.00,-2173.00,265.20,200.00}},
	{"Garcia",                      {-2395.10,-222.50,-5.30,-2354.00,-204.70,200.00}},
	{"Garver Bridge",               {-1339.80,828.10,-89.00,-1213.90,1057.00,110.90}},
	{"Garver Bridge",               {-1213.90,950.00,-89.00,-1087.90,1178.90,110.90}},
	{"Garver Bridge",               {-1499.80,696.40,-179.60,-1339.80,925.30,20.30}},
	{"Glen Park",                   {1812.60,-1449.60,-89.00,1996.90,-1350.70,110.90}},
	{"Glen Park",                   {1812.60,-1100.80,-89.00,1994.30,-973.30,110.90}},
	{"Glen Park",                   {1812.60,-1350.70,-89.00,2056.80,-1100.80,110.90}},
	{"Green Palms",                 {176.50,1305.40,-3.00,338.60,1520.70,200.00}},
	{"Greenglass College",          {964.30,1044.60,-89.00,1197.30,1203.20,110.90}},
	{"Greenglass College",          {964.30,930.80,-89.00,1166.50,1044.60,110.90}},
	{"Hampton Barns",               {603.00,264.30,0.00,761.90,366.50,200.00}},
	{"Hankypanky Point",            {2576.90,62.10,0.00,2759.20,385.50,200.00}},
	{"Harry Gold Parkway",          {1777.30,863.20,-89.00,1817.30,2342.80,110.90}},
	{"Hashbury",                    {-2593.40,-222.50,-0.00,-2411.20,54.70,200.00}},
	{"Hilltop Farm",                {967.30,-450.30,-3.00,1176.70,-217.90,200.00}},
	{"Hunter Quarry",               {337.20,710.80,-115.20,860.50,1031.70,203.70}},
	{"Idlewood",                    {1812.60,-1852.80,-89.00,1971.60,-1742.30,110.90}},
	{"Idlewood",                    {1812.60,-1742.30,-89.00,1951.60,-1602.30,110.90}},
	{"Idlewood",                    {1951.60,-1742.30,-89.00,2124.60,-1602.30,110.90}},
	{"Idlewood",                    {1812.60,-1602.30,-89.00,2124.60,-1449.60,110.90}},
	{"Idlewood",                    {2124.60,-1742.30,-89.00,2222.50,-1494.00,110.90}},
	{"Idlewood",                    {1971.60,-1852.80,-89.00,2222.50,-1742.30,110.90}},
	{"Jefferson",                   {1996.90,-1449.60,-89.00,2056.80,-1350.70,110.90}},
	{"Jefferson",                   {2124.60,-1494.00,-89.00,2266.20,-1449.60,110.90}},
	{"Jefferson",                   {2056.80,-1372.00,-89.00,2281.40,-1210.70,110.90}},
	{"Jefferson",                   {2056.80,-1210.70,-89.00,2185.30,-1126.30,110.90}},
	{"Jefferson",                   {2185.30,-1210.70,-89.00,2281.40,-1154.50,110.90}},
	{"Jefferson",                   {2056.80,-1449.60,-89.00,2266.20,-1372.00,110.90}},
	{"Julius Thruway East",         {2623.10,943.20,-89.00,2749.90,1055.90,110.90}},
	{"Julius Thruway East",         {2685.10,1055.90,-89.00,2749.90,2626.50,110.90}},
	{"Julius Thruway East",         {2536.40,2442.50,-89.00,2685.10,2542.50,110.90}},
	{"Julius Thruway East",         {2625.10,2202.70,-89.00,2685.10,2442.50,110.90}},
	{"Julius Thruway North",        {2498.20,2542.50,-89.00,2685.10,2626.50,110.90}},
	{"Julius Thruway North",        {2237.40,2542.50,-89.00,2498.20,2663.10,110.90}},
	{"Julius Thruway North",        {2121.40,2508.20,-89.00,2237.40,2663.10,110.90}},
	{"Julius Thruway North",        {1938.80,2508.20,-89.00,2121.40,2624.20,110.90}},
	{"Julius Thruway North",        {1534.50,2433.20,-89.00,1848.40,2583.20,110.90}},
	{"Julius Thruway North",        {1848.40,2478.40,-89.00,1938.80,2553.40,110.90}},
	{"Julius Thruway North",        {1704.50,2342.80,-89.00,1848.40,2433.20,110.90}},
	{"Julius Thruway North",        {1377.30,2433.20,-89.00,1534.50,2507.20,110.90}},
	{"Julius Thruway South",        {1457.30,823.20,-89.00,2377.30,863.20,110.90}},
	{"Julius Thruway South",        {2377.30,788.80,-89.00,2537.30,897.90,110.90}},
	{"Julius Thruway West",         {1197.30,1163.30,-89.00,1236.60,2243.20,110.90}},
	{"Julius Thruway West",         {1236.60,2142.80,-89.00,1297.40,2243.20,110.90}},
	{"Juniper Hill",                {-2533.00,578.30,-7.60,-2274.10,968.30,200.00}},
	{"Juniper Hollow",              {-2533.00,968.30,-6.10,-2274.10,1358.90,200.00}},
	{"K.A.C.C. Military",     {2498.20,2626.50,-89.00,2749.90,2861.50,110.90}},
	{"Kincaid Bridge",              {-1339.80,599.20,-89.00,-1213.90,828.10,110.90}},
	{"Kincaid Bridge",              {-1213.90,721.10,-89.00,-1087.90,950.00,110.90}},
	{"Kincaid Bridge",              {-1087.90,855.30,-89.00,-961.90,986.20,110.90}},
	{"King's",                      {-2329.30,458.40,-7.60,-1993.20,578.30,200.00}},
	{"King's",                      {-2411.20,265.20,-9.10,-1993.20,373.50,200.00}},
	{"King's",                      {-2253.50,373.50,-9.10,-1993.20,458.40,200.00}},
	{"LVA Freight Depot",           {1457.30,863.20,-89.00,1777.40,1143.20,110.90}},
	{"LVA Freight Depot",           {1375.60,919.40,-89.00,1457.30,1203.20,110.90}},
	{"LVA Freight Depot",           {1277.00,1087.60,-89.00,1375.60,1203.20,110.90}},
	{"LVA Freight Depot",           {1315.30,1044.60,-89.00,1375.60,1087.60,110.90}},
	{"LVA Freight Depot",           {1236.60,1163.40,-89.00,1277.00,1203.20,110.90}},
	{"Las Barrancas",               {-926.10,1398.70,-3.00,-719.20,1634.60,200.00}},
	{"Las Brujas",                  {-365.10,2123.00,-3.00,-208.50,2217.60,200.00}},
	{"Las Colinas",                 {1994.30,-1100.80,-89.00,2056.80,-920.80,110.90}},
	{"Las Colinas",                 {2056.80,-1126.30,-89.00,2126.80,-920.80,110.90}},
	{"Las Colinas",                 {2185.30,-1154.50,-89.00,2281.40,-934.40,110.90}},
	{"Las Colinas",                 {2126.80,-1126.30,-89.00,2185.30,-934.40,110.90}},
	{"Las Colinas",                 {2747.70,-1120.00,-89.00,2959.30,-945.00,110.90}},
	{"Las Colinas",                 {2632.70,-1135.00,-89.00,2747.70,-945.00,110.90}},
	{"Las Colinas",                 {2281.40,-1135.00,-89.00,2632.70,-945.00,110.90}},
	{"Las Payasadas",               {-354.30,2580.30,2.00,-133.60,2816.80,200.00}},
	{"Las Venturas Airport",        {1236.60,1203.20,-89.00,1457.30,1883.10,110.90}},
	{"Las Venturas Airport",        {1457.30,1203.20,-89.00,1777.30,1883.10,110.90}},
	{"Las Venturas Airport",        {1457.30,1143.20,-89.00,1777.40,1203.20,110.90}},
	{"Las Venturas Airport",        {1515.80,1586.40,-12.50,1729.90,1714.50,87.50}},
	{"Last Dime Motel",             {1823.00,596.30,-89.00,1997.20,823.20,110.90}},
	{"Leafy Hollow",                {-1166.90,-1856.00,0.00,-815.60,-1602.00,200.00}},
	{"Liberty City",                {-1000.00,400.00,1300.00,-700.00,600.00,1400.00}},
	{"Lil' Probe Inn",              {-90.20,1286.80,-3.00,153.80,1554.10,200.00}},
	{"Linden Side",                 {2749.90,943.20,-89.00,2923.30,1198.90,110.90}},
	{"Linden Station",              {2749.90,1198.90,-89.00,2923.30,1548.90,110.90}},
	{"Linden Station",              {2811.20,1229.50,-39.50,2861.20,1407.50,60.40}},
	{"Little SuperNova",               {1701.90,-1842.20,-89.00,1812.60,-1722.20,110.90}},
	{"Little SuperNova",               {1758.90,-1722.20,-89.00,1812.60,-1577.50,110.90}},
	{"Los Flores",                  {2581.70,-1454.30,-89.00,2632.80,-1393.40,110.90}},
	{"Los Flores",                  {2581.70,-1393.40,-89.00,2747.70,-1135.00,110.90}},
	{"Los Santos Airport",    {1249.60,-2394.30,-89.00,1852.00,-2179.20,110.90}},
	{"Los Santos Airport",    {1852.00,-2394.30,-89.00,2089.00,-2179.20,110.90}},
	{"Los Santos Airport",    {1382.70,-2730.80,-89.00,2201.80,-2394.30,110.90}},
	{"Los Santos Airport",    {1974.60,-2394.30,-39.00,2089.00,-2256.50,60.90}},
	{"Los Santos Airport",    {1400.90,-2669.20,-39.00,2189.80,-2597.20,60.90}},
	{"Los Santos Airport ",    {2051.60,-2597.20,-39.00,2152.40,-2394.30,60.90}},
	{"Marina",                      {647.70,-1804.20,-89.00,851.40,-1577.50,110.90}},
	{"Marina",                      {647.70,-1577.50,-89.00,807.90,-1416.20,110.90}},
	{"Marina",                      {807.90,-1577.50,-89.00,926.90,-1416.20,110.90}},
	{"Market",                      {787.40,-1416.20,-89.00,1072.60,-1310.20,110.90}},
	{"Market",                      {952.60,-1310.20,-89.00,1072.60,-1130.80,110.90}},
	{"Market",                      {1072.60,-1416.20,-89.00,1370.80,-1130.80,110.90}},
	{"Market",                      {926.90,-1577.50,-89.00,1370.80,-1416.20,110.90}},
	{"Market Station",              {787.40,-1410.90,-34.10,866.00,-1310.20,65.80}},
	{"Martin Bridge",               {-222.10,293.30,0.00,-122.10,476.40,200.00}},
	{"Missionary Hill",             {-2994.40,-811.20,0.00,-2178.60,-430.20,200.00}},
	{"Montgomery",                  {1119.50,119.50,-3.00,1451.40,493.30,200.00}},
	{"Montgomery",                  {1451.40,347.40,-6.10,1582.40,420.80,200.00}},
	{"Montgomery Section",     {1546.60,208.10,0.00,1745.80,347.40,200.00}},
	{"Montgomery Section",     {1582.40,347.40,0.00,1664.60,401.70,200.00}},
	{"Mulholland",                  {1414.00,-768.00,-89.00,1667.60,-452.40,110.90}},
	{"Mulholland",                  {1281.10,-452.40,-89.00,1641.10,-290.90,110.90}},
	{"Mulholland",                  {1269.10,-768.00,-89.00,1414.00,-452.40,110.90}},
	{"Mulholland",                  {1357.00,-926.90,-89.00,1463.90,-768.00,110.90}},
	{"Mulholland",                  {1318.10,-910.10,-89.00,1357.00,-768.00,110.90}},
	{"Mulholland",                  {1169.10,-910.10,-89.00,1318.10,-768.00,110.90}},
	{"Mulholland",                  {768.60,-954.60,-89.00,952.60,-860.60,110.90}},
	{"Mulholland",                  {687.80,-860.60,-89.00,911.80,-768.00,110.90}},
	{"Mulholland",                  {737.50,-768.00,-89.00,1142.20,-674.80,110.90}},
	{"Mulholland",                  {1096.40,-910.10,-89.00,1169.10,-768.00,110.90}},
	{"Mulholland",                  {952.60,-937.10,-89.00,1096.40,-860.60,110.90}},
	{"Mulholland",                  {911.80,-860.60,-89.00,1096.40,-768.00,110.90}},
	{"Mulholland",                  {861.00,-674.80,-89.00,1156.50,-600.80,110.90}},
	{"Mulholland Section",     {1463.90,-1150.80,-89.00,1812.60,-768.00,110.90}},
	{"North Rock",                  {2285.30,-768.00,0.00,2770.50,-269.70,200.00}},
	{"Ocean Docks",                 {2373.70,-2697.00,-89.00,2809.20,-2330.40,110.90}},
	{"Ocean Docks",                 {2201.80,-2418.30,-89.00,2324.00,-2095.00,110.90}},
	{"Ocean Docks",                 {2324.00,-2302.30,-89.00,2703.50,-2145.10,110.90}},
	{"Ocean Docks",                 {2089.00,-2394.30,-89.00,2201.80,-2235.80,110.90}},
	{"Ocean Docks",                 {2201.80,-2730.80,-89.00,2324.00,-2418.30,110.90}},
	{"Ocean Docks",                 {2703.50,-2302.30,-89.00,2959.30,-2126.90,110.90}},
	{"Ocean Docks",                 {2324.00,-2145.10,-89.00,2703.50,-2059.20,110.90}},
	{"Ocean Flats",                 {-2994.40,277.40,-9.10,-2867.80,458.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-222.50,-0.00,-2593.40,277.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-430.20,-0.00,-2831.80,-222.50,200.00}},
	{"Octane Springs",              {338.60,1228.50,0.00,664.30,1655.00,200.00}},
	{"Old Venturas Strip",          {2162.30,2012.10,-89.00,2685.10,2202.70,110.90}},
	{"Palisades",                   {-2994.40,458.40,-6.10,-2741.00,1339.60,200.00}},
	{"Palomino Creek",              {2160.20,-149.00,0.00,2576.90,228.30,200.00}},
	{"Paradiso",                    {-2741.00,793.40,-6.10,-2533.00,1268.40,200.00}},
	{"Pershing Square",             {1440.90,-1722.20,-89.00,1583.50,-1577.50,110.90}},
	{"Pilgrim",                     {2437.30,1383.20,-89.00,2624.40,1783.20,110.90}},
	{"Pilgrim",                     {2624.40,1383.20,-89.00,2685.10,1783.20,110.90}},
	{"Pilson Intersection",         {1098.30,2243.20,-89.00,1377.30,2507.20,110.90}},
	{"Pirates in Men's Pants",      {1817.30,1469.20,-89.00,2027.40,1703.20,110.90}},
	{"Playa del Seville",           {2703.50,-2126.90,-89.00,2959.30,-1852.80,110.90}},
	{"Prickle Pine",                {1534.50,2583.20,-89.00,1848.40,2863.20,110.90}},
	{"Prickle Pine",                {1117.40,2507.20,-89.00,1534.50,2723.20,110.90}},
	{"Prickle Pine",                {1848.40,2553.40,-89.00,1938.80,2863.20,110.90}},
	{"Prickle Pine",                {1938.80,2624.20,-89.00,2121.40,2861.50,110.90}},
	{"Queens",                      {-2533.00,458.40,0.00,-2329.30,578.30,200.00}},
	{"Queens",                      {-2593.40,54.70,0.00,-2411.20,458.40,200.00}},
	{"Queens",                      {-2411.20,373.50,0.00,-2253.50,458.40,200.00}},
	{"Randolph Industrial",         {1558.00,596.30,-89.00,1823.00,823.20,110.90}},
	{"Redsands East",               {1817.30,2011.80,-89.00,2106.70,2202.70,110.90}},
	{"Redsands East",               {1817.30,2202.70,-89.00,2011.90,2342.80,110.90}},
	{"Redsands East",               {1848.40,2342.80,-89.00,2011.90,2478.40,110.90}},
	{"Redsands West",               {1236.60,1883.10,-89.00,1777.30,2142.80,110.90}},
	{"Redsands West",               {1297.40,2142.80,-89.00,1777.30,2243.20,110.90}},
	{"Redsands West",               {1377.30,2243.20,-89.00,1704.50,2433.20,110.90}},
	{"Redsands West",               {1704.50,2243.20,-89.00,1777.30,2342.80,110.90}},
	{"Regular Tom",                 {-405.70,1712.80,-3.00,-276.70,1892.70,200.00}},
	{"Richman",                     {647.50,-1118.20,-89.00,787.40,-954.60,110.90}},
	{"Richman",                     {647.50,-954.60,-89.00,768.60,-860.60,110.90}},
	{"Richman",                     {225.10,-1369.60,-89.00,334.50,-1292.00,110.90}},
	{"Richman",                     {225.10,-1292.00,-89.00,466.20,-1235.00,110.90}},
	{"Richman",                     {72.60,-1404.90,-89.00,225.10,-1235.00,110.90}},
	{"Richman",                     {72.60,-1235.00,-89.00,321.30,-1008.10,110.90}},
	{"Richman",                     {321.30,-1235.00,-89.00,647.50,-1044.00,110.90}},
	{"Richman",                     {321.30,-1044.00,-89.00,647.50,-860.60,110.90}},
	{"Richman",                     {321.30,-860.60,-89.00,687.80,-768.00,110.90}},
	{"Richman",                     {321.30,-768.00,-89.00,700.70,-674.80,110.90}},
	{"Robada Intersection",         {-1119.00,1178.90,-89.00,-862.00,1351.40,110.90}},
	{"Roca Escalante",              {2237.40,2202.70,-89.00,2536.40,2542.50,110.90}},
	{"Roca Escalante",              {2536.40,2202.70,-89.00,2625.10,2442.50,110.90}},
	{"Rockshore East",              {2537.30,676.50,-89.00,2902.30,943.20,110.90}},
	{"Rockshore West",              {1997.20,596.30,-89.00,2377.30,823.20,110.90}},
	{"Rockshore West",              {2377.30,596.30,-89.00,2537.30,788.80,110.90}},
	{"Rodeo",                       {72.60,-1684.60,-89.00,225.10,-1544.10,110.90}},
	{"Rodeo",                       {72.60,-1544.10,-89.00,225.10,-1404.90,110.90}},
	{"Rodeo",                       {225.10,-1684.60,-89.00,312.80,-1501.90,110.90}},
	{"Rodeo",                       {225.10,-1501.90,-89.00,334.50,-1369.60,110.90}},
	{"Rodeo",                       {334.50,-1501.90,-89.00,422.60,-1406.00,110.90}},
	{"Rodeo",                       {312.80,-1684.60,-89.00,422.60,-1501.90,110.90}},
	{"Rodeo",                       {422.60,-1684.60,-89.00,558.00,-1570.20,110.90}},
	{"Rodeo",                       {558.00,-1684.60,-89.00,647.50,-1384.90,110.90}},
	{"Rodeo",                       {466.20,-1570.20,-89.00,558.00,-1385.00,110.90}},
	{"Rodeo",                       {422.60,-1570.20,-89.00,466.20,-1406.00,110.90}},
	{"Rodeo",                       {466.20,-1385.00,-89.00,647.50,-1235.00,110.90}},
	{"Rodeo",                       {334.50,-1406.00,-89.00,466.20,-1292.00,110.90}},
	{"Royal Casino",                {2087.30,1383.20,-89.00,2437.30,1543.20,110.90}},
	{"San Andreas Sound",           {2450.30,385.50,-100.00,2759.20,562.30,200.00}},
	{"Santa Flora",                 {-2741.00,458.40,-7.60,-2533.00,793.40,200.00}},
	{"Santa Maria Beach",           {342.60,-2173.20,-89.00,647.70,-1684.60,110.90}},
	{"Santa Maria Beach",           {72.60,-2173.20,-89.00,342.60,-1684.60,110.90}},
	{"Shady Cabin",                 {-1632.80,-2263.40,-3.00,-1601.30,-2231.70,200.00}},
	{"Shady Creeks",                {-1820.60,-2643.60,-8.00,-1226.70,-1771.60,200.00}},
	{"Shady Creeks",                {-2030.10,-2174.80,-6.10,-1820.60,-1771.60,200.00}},
	{"Sobell Rail Yards",           {2749.90,1548.90,-89.00,2923.30,1937.20,110.90}},
	{"Spinybed",                    {2121.40,2663.10,-89.00,2498.20,2861.50,110.90}},
	{"Starfish Casino",             {2437.30,1783.20,-89.00,2685.10,2012.10,110.90}},
	{"Starfish Casino",             {2437.30,1858.10,-39.00,2495.00,1970.80,60.90}},
	{"Starfish Casino",             {2162.30,1883.20,-89.00,2437.30,2012.10,110.90}},
	{"Temple",                      {1252.30,-1130.80,-89.00,1378.30,-1026.30,110.90}},
	{"Temple",                      {1252.30,-1026.30,-89.00,1391.00,-926.90,110.90}},
	{"Temple",                      {1252.30,-926.90,-89.00,1357.00,-910.10,110.90}},
	{"Temple",                      {952.60,-1130.80,-89.00,1096.40,-937.10,110.90}},
	{"Temple",                      {1096.40,-1130.80,-89.00,1252.30,-1026.30,110.90}},
	{"Temple",                      {1096.40,-1026.30,-89.00,1252.30,-910.10,110.90}},
	{"The Camel's Toe",             {2087.30,1203.20,-89.00,2640.40,1383.20,110.90}},
	{"The Clown's Pocket",          {2162.30,1783.20,-89.00,2437.30,1883.20,110.90}},
	{"The Emerald Isle",            {2011.90,2202.70,-89.00,2237.40,2508.20,110.90}},
	{"The Farm",                    {-1209.60,-1317.10,114.90,-908.10,-787.30,251.90}},
	{"Four Dragons Casino",         {1817.30,863.20,-89.00,2027.30,1083.20,110.90}},
	{"The High Roller",             {1817.30,1283.20,-89.00,2027.30,1469.20,110.90}},
	{"The Mako Span",               {1664.60,401.70,0.00,1785.10,567.20,200.00}},
	{"The Panopticon",              {-947.90,-304.30,-1.10,-319.60,327.00,200.00}},
	{"The Pink Swan",               {1817.30,1083.20,-89.00,2027.30,1283.20,110.90}},
	{"The Sherman Dam",             {-968.70,1929.40,-3.00,-481.10,2155.20,200.00}},
	{"The Strip",                   {2027.40,863.20,-89.00,2087.30,1703.20,110.90}},
	{"The Strip",                   {2106.70,1863.20,-89.00,2162.30,2202.70,110.90}},
	{"The Strip",                   {2027.40,1783.20,-89.00,2162.30,1863.20,110.90}},
	{"The Strip",                   {2027.40,1703.20,-89.00,2137.40,1783.20,110.90}},
	{"The Visage",                  {1817.30,1863.20,-89.00,2106.70,2011.80,110.90}},
	{"The Visage",                  {1817.30,1703.20,-89.00,2027.40,1863.20,110.90}},
	{"Unity Station",               {1692.60,-1971.80,-20.40,1812.60,-1932.80,79.50}},
	{"Valle Ocultado",              {-936.60,2611.40,2.00,-715.90,2847.90,200.00}},
	{"Verdant Bluffs",              {930.20,-2488.40,-89.00,1249.60,-2006.70,110.90}},
	{"Verdant Bluffs",              {1073.20,-2006.70,-89.00,1249.60,-1842.20,110.90}},
	{"Verdant Bluffs",              {1249.60,-2179.20,-89.00,1692.60,-1842.20,110.90}},
	{"Verdant Meadows",             {37.00,2337.10,-3.00,435.90,2677.90,200.00}},
	{"Verona Beach",                {647.70,-2173.20,-89.00,930.20,-1804.20,110.90}},
	{"Verona Beach",                {930.20,-2006.70,-89.00,1073.20,-1804.20,110.90}},
	{"Verona Beach",                {851.40,-1804.20,-89.00,1046.10,-1577.50,110.90}},
	{"Verona Beach",                {1161.50,-1722.20,-89.00,1323.90,-1577.50,110.90}},
	{"Verona Beach",                {1046.10,-1722.20,-89.00,1161.50,-1577.50,110.90}},
	{"Vinewood",                    {787.40,-1310.20,-89.00,952.60,-1130.80,110.90}},
	{"Vinewood",                    {787.40,-1130.80,-89.00,952.60,-954.60,110.90}},
	{"Vinewood",                    {647.50,-1227.20,-89.00,787.40,-1118.20,110.90}},
	{"Vinewood",                    {647.70,-1416.20,-89.00,787.40,-1227.20,110.90}},
	{"Whitewood Estates",           {883.30,1726.20,-89.00,1098.30,2507.20,110.90}},
	{"Whitewood Estates",           {1098.30,1726.20,-89.00,1197.30,2243.20,110.90}},
	{"Willowfield",                 {1970.60,-2179.20,-89.00,2089.00,-1852.80,110.90}},
	{"Willowfield",                 {2089.00,-2235.80,-89.00,2201.80,-1989.90,110.90}},
	{"Willowfield",                 {2089.00,-1989.90,-89.00,2324.00,-1852.80,110.90}},
	{"Willowfield",                 {2201.80,-2095.00,-89.00,2324.00,-1989.90,110.90}},
	{"Willowfield",                 {2541.70,-1941.40,-89.00,2703.50,-1852.80,110.90}},
	{"Willowfield",                 {2324.00,-2059.20,-89.00,2541.70,-1852.80,110.90}},
	{"Willowfield",                 {2541.70,-2059.20,-89.00,2703.50,-1941.40,110.90}},
	{"Yellow Bell",         {1377.40,2600.40,-21.90,1492.40,2687.30,78.00}},
	// Citys Zones
	{"Los Santos",                  {44.60,-2892.90,-242.90,2997.00,-768.00,900.00}},
	{"Las Venturas",                {869.40,596.30,-242.90,2997.00,2993.80,900.00}},
	{"Bone County",                 {-480.50,596.30,-242.90,869.40,2993.80,900.00}},
	{"Tierra Robada",               {-2997.40,1659.60,-242.90,-480.50,2993.80,900.00}},
	{"Tierra Robada",               {-1213.90,596.30,-242.90,-480.50,1659.60,900.00}},
	{"San Fierro",                  {-2997.40,-1115.50,-242.90,-1213.90,1659.60,900.00}},
	{"Red County",                  {-1213.90,-768.00,-242.90,2997.00,596.30,900.00}},
	{"Flint County",                {-1213.90,-2892.90,-242.90,44.60,-768.00,900.00}},
	{"Whetstone",                   {-2997.40,-2892.90,-242.90,-1213.90,-1115.50,900.00}}
};

Get2DZone(Float:x,Float:y, zone[], len)
{
 	for(new i = 0; i != sizeof(SA_GPS_ZONE_NAMES); i++ ){
	if(x >= SA_GPS_ZONE_NAMES[i][Zone_Area][0] && x <= SA_GPS_ZONE_NAMES[i][Zone_Area][3] && y >= SA_GPS_ZONE_NAMES[i][Zone_Area][1] && y <= SA_GPS_ZONE_NAMES[i][Zone_Area][4]){
	return format(zone, len, SA_GPS_ZONE_NAMES[i][Zone_Name], 0);}
	}
	return 0;
}
