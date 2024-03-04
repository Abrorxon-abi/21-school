#!/bin/bash
cd ai_help
chmod +x keygen.sh
chmod +x unifier.sh
./keygen.sh

cd ai_help
cd key

for file in *; do
    if [[ "$file" != *.key ]]; then
        rm "$file"
    fi
done

cd ..
./unifier.sh

mv main.key key/