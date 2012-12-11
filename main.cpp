#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
int szer=320,wys=240;
int main()
{
    al_init();
    al_install_keyboard();
	al_init_image_addon();

	ALLEGRO_BITMAP* Image=NULL;
	Image = al_load_bitmap("statek.png");

    ALLEGRO_KEYBOARD_STATE key_state;
    ALLEGRO_DISPLAY *okno = al_create_display( szer, wys);
    al_set_window_title( okno,"Allegro5 klawiatura i czas");
    ALLEGRO_BITMAP *kwadrat = al_create_bitmap(32,32);
    al_set_target_bitmap(kwadrat);
    al_clear_to_color(al_map_rgb(255,255,0));
    al_set_target_bitmap(al_get_backbuffer(okno));
    int x=100,y=100;
	float z=0;
    double czas = al_get_time(); 
	
	
	int u;
	while( true )
    {
        al_get_keyboard_state(&key_state);
        if ( al_get_time() > czas + 0.01)
        {

            if ( al_key_down(&key_state, ALLEGRO_KEY_Z )   && x  <=  szer-32) z=z-0.01 ;
			if ( al_key_down(&key_state, ALLEGRO_KEY_X )   && x  <=  szer-32) z=z+0.01 ;
            if ( al_key_down(&key_state, ALLEGRO_KEY_RIGHT )   && x  <=  szer-32) x=x+1 ;
            if ( al_key_down(&key_state, ALLEGRO_KEY_LEFT  )    && x  >=           0) x=x- 1 ;
            if ( al_key_down(&key_state, ALLEGRO_KEY_DOWN  ) && y <= wys  -32) y=y+1 ;
            if ( al_key_down(&key_state, ALLEGRO_KEY_UP    )      && y  >=           0) y=y- 1 ;
            czas = al_get_time();
        }
        al_clear_to_color(al_map_rgb_f(0.5,0.5,0.5));
		al_convert_mask_to_alpha( Image, al_map_rgb( 255, 0, 255 ) );
		al_draw_rotated_bitmap(Image,15, 25, x, y, z, 0);
        al_flip_display();
        //al_rest(0.001);
    }
    al_destroy_bitmap(kwadrat);
    al_destroy_display(okno);
    return 0;
}