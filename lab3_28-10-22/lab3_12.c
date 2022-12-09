#include <stdio.h>
#define LEN_CHAR 50

int main()
{
    float v0_ms = 1.00, a_ms2 = 0.10, s_tot_m = 100.00, t_step_s = 10.0, v_ms, t_S, s_m;
    int s_char, i;

    printf("\nINIZIO SIMULAZIONE v0_ms = %.2f, a_ms2 = %.2f, s_tot_m = %.2f, t_step_s = %.2f\n", v0_ms, a_ms2, s_tot_m, t_step_s);

    for(t_s = 0; s_m < s_tot_m; t_s += t_step_s)
    {
        v_ms = v0_ms + a_ms2 * t_s;
        s_m = 1.0 / 2.0 * a_ms2 * (t_s * t_s) + v0_ms * t_s;
        s_char = s_m *(LEN_CHAR / s_tot_m);
        printf("Tempo = %.1f s, Velocita' = %.3f m/s = %.2f km/h, Distanza = %.2f m = %.3f km\n0", t_s, v_ms, v_ms*3.6, s_m, s_m*1000);

    /* for(int i = 0; i < LEN_CHAR; i++)
        {
            if(i == s_char)
                printf("x");
            else
                printf("-");
        }
        printf("%d", s_tot_m); */
    }

    printf("FINE SIMULAZIONE");
}