//Atributos window
#define pred_window_tamx 1400
#define pred_window_tamy 1000
//Atributos de MAPA
#define pred_mapx_tam 1600   //en este caso la relacion es de 5/4
#define pred_mapy_tam 1600

//Atributos de Areas
#define pred_areas_tamx pred_mapx_tam/pred_areas_numx
#define pred_areas_tamy pred_mapy_tam/pred_areas_numy
#define pred_areas_numx 4   //pd que sean siempre pares de preferencia
#define pred_areas_numy 4

//Atributos de Bloques
#define pred_bloq_tam 100
#define pred_bloq_numx 4
#define pred_bloq_numy 4


//Atributos predeterminados ENEMIGOS
#define pred_enemy_tam 7.5      //RADIO
#define pred_enemy_mov 250
#define pred_enemy_life 100     //faltan agregar estos 3 datos
#define pred_enemy_resistance 20
#define pred_enemy_dmg 15

//Atributos predeterminados Neutrales
#define pred_neutral_tam 7.5    //Faltan agregar la clase neutral
#define pred_neutral_mov 250
#define pred_neutral_life 100   
#define pred_neutral_resistance 30
#define pred_neutral_dmg 20

