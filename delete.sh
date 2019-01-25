DATA[0]="      :::::::::: :::::::::  ::::::::::            :::     :::::::: "
DATA[1]="     :+:        :+:    :+: :+:                  :+:     :+:    :+: "
DATA[2]="    +:+        +:+    +:+ +:+                 +:+ +:+        +:+   "
DATA[3]="   :#::+::#   +#+    +:+ :#::+::#           +#+  +:+      +#+      "
DATA[4]="  +#+        +#+    +#+ +#+               +#+#+#+#+#+  +#+         "
DATA[5]=" #+#        #+#    #+# #+#                     #+#   #+#           "
DATA[6]="###        #########  ###                     ###  ##########      "
DATA[7]="                                                                   "
DATA[8]="                          SUPPRESSION ...                          "
echo

OFFSET_X=$(($((`tput cols` - 56)) / 2))
OFFSET_Y=$(($((`tput lines` - 6)) / 2))

draw_char() {
    V_COORD_X=$1
    V_COORD_Y=$2

    tput cup $((OFFSET_Y + V_COORD_Y)) $((OFFSET_X + V_COORD_X))
    printf %c ${DATA[V_COORD_Y]:V_COORD_X:1}
}

tput civis
clear
while :; do
    for ((c=7; c <= 7; c++)); do
        tput setaf $c
        for ((x=0; x<${#DATA[0]}; x++)); do
            for ((y=0; y<=8; y++)); do
                draw_char $x $y
            done
        done
    done
    sleep 1
    clear
    break
done
