Politické kauzy (programátorská úloha). Politici v rámci predvolebnej kampane vyťahujú rôzne
kauzy. Konkrétne, o každej kauze i vieme jej skrátený názov mi
, od ktorého dňa ai do ktorého dňa b_i bude kauza
aktuálna a jej výbušnosť v_i
. (Pre jednoduchosť môžete predpokladať, že každá kauza má inú výbušnosť.) Novinári každý deň píšu výlučne len o najvýbušnejšej aktuálnej kauze. O čom budú novinári písať počas predvolebnej
kampane?

Vstup. Na prvom riadku vstupu sa nachádza číslo n - počet káuz. Platí, že 1 ≤ n ≤ 100 000. Nasleduje n riadkov.
Každý riadok je tvorený štyroma medzerou oddelenými údajmi: m_i a_i b_i v_i. Platí, že m_i je neprázdny
reťazec, ktorý sa skladá z najviac 50 malých a veľkých písmen anglickej abecedy a neobsahuje medzeru. Tiež platí,
že 0 ≤ a ≤ b ≤ 100 000 a 1 ≤ v ≤ 10 000 000.
Výstup. Na výstup vypíšte niekoľko riadkov formátu nazov a b - najvýbušnejšie kauzy v priebehu kampane od
času 0 po poradí ako boli najvýbušnejšie. V prípade, že v nejakom čase neexistuje žiadna kauza, vypíšte nic a b,
kde a b sú časy odkedy a dokedy sa nič nedeje.
Príklad vstupu:
3
medvede 1 10 3
vodopad 3 6 5
ukradli 4 7 6
Príklad výstupu:
nic 0 0
medvede 1 2
vodopad 3 3
ukradli 4 7
medvede 8 10
Príklad vstupu:
4
medvede 2 4 5
plagaty 2 4 10
dane 7 8 6
uhorky 7 8 1
Príklad výstupu:
nic 0 1
plagaty 2 4
nic 5 6
dane 7 8
