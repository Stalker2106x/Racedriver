echo -n "Les librairies et dépendances de Racedriver vont être installees"
echo ""
sudo chmod +x Data/racedriver_a1.2.0
echo "racedriver est maintenant executable"
sudo chmod +x Update/unpack
echo "unpack est maintenant executable"
sudo chmod +x uninstall.sh
echo "uninstall.sh est maintenant executable"
sudo chmod +x launcher.sh
echo "launcher.sh est maintenant executable"
echo "installation de libsfml-system.so.1.6"
sudo cp lib/libsfml-system.so.1.6 /usr/lib/libsfml-system.so.1.6
echo "installation de libsfml-system.so.1.6 reussie"
echo "installation de libboost_system.so.1.48.0"
sudo cp lib/libboost_system.so.1.48.0 /usr/lib/libboost_system.so.1.48.0
echo "installation de libboost_system.so.1.48.0 reussie"
echo "installation de libcurl.so.4.2.0"
sudo cp lib/libcurl.so.4.2.0 /usr/lib/libcurl.so.4.2.0
echo "installation de libcurl.so.4.2.0 reussie"
echo "Installation effectuée avec succes"
read -p "Appuyez sur [Entree] pour quitter." nothing