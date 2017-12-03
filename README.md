module add prog/sfml-2-gcc-6
g++17 *.cpp -I${SFML_ROOT}/include -L${SFML_ROOT}/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network

Tower Wars Legacy



 Todo: 
-	Animation for all the entities   // HALF DONE
-	Base Soldier interaction        
-	Tower Select Target + Fire       // DONE, not tested fully
-	Tower, Soldier placement for p2  // DONE
-	Redo Ground to fit in the new grid 
-	Delete Soldier                   
-	Sell Tower
	
