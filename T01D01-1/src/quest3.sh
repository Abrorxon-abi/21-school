#!/bin/bash

chmod +x ai_door_management_module.sh
chmod +x ai_door_control.sh

mv door_management_fi door_management_files
cd door_management_files

mkdir door_configuration
mkdir door_map
mkdir door_logs

mv *.conf door_configuration/
mv door_map_1.1 door_map/
mv *.log door_logs/
