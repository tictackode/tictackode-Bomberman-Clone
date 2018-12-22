
#include <allegro.h>
#include <time.h>
#include "Glow.h"
#include "functions.h"

int main()
{
    //initializations
    init();
    loadAll();
    initGame();

	LOCK_FUNCTION(incrementaTimer);
	LOCK_VARIABLE(timer);

	LOCK_FUNCTION(incrementaTimerMilisec);
	LOCK_VARIABLE(timerMilisec);

	timer = 0;

	 //tela_inicial();

    //game loop
    while(!key[KEY_ESC])
    {
        install_int_ex(incrementaTimer, MSEC_TO_TIMER(1000));

        install_int_ex(incrementaTimerMilisec, MSEC_TO_TIMER(1));

        // frames per second near 60
        if(timerMilisec-timeAuxMilisec>16)
        {
            paint();
            glow.glow();
            timeAuxMilisec=timerMilisec;
        }

        controle();

        player1.bomb[0].checkExplosion();
        player1.bomb[1].checkExplosion();
        player1.bomb[2].checkExplosion();
        player1.bomb[3].checkExplosion();
        player1.bomb[4].checkExplosion();

        // limpando o buffer
        clear(buffer);

    }

    freeAll();
    return 0;
    deinit();
}
END_OF_MAIN()
