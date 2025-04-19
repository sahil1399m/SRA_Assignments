#include "oled.h"
 #include "sra_board.h"
 
 static const char *TAG = "oled_example";
 
 void app_main()
 {
     // Initialising the OLED
     init_oled();
     vTaskDelay(100);
 
     // Clearing the screen
     lv_obj_clean(lv_scr_act());
 
     // Printing the string on screen    
     lv_obj_t *text_msg = lv_label_create(lv_scr_act());
     lv_label_set_text(text_msg, "ENJOYING \nTHE \nASSIGNMENTS");
     lv_obj_align(text_msg, LV_ALIGN_CENTER, 0, 0);
 
     // Refresh Display
     lv_refr_now(NULL);
 
     ESP_LOGI(TAG, "Successfully displayed Hello World on the OLED Screen");
 }
 