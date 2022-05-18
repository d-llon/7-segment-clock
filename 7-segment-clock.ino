// This #include statement was automatically added by the Particle IDE.
#include <HttpClient.h>

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_LEDBackpack_RK.h>

// Display setup
Adafruit_7segment matrix_left = Adafruit_7segment();
// Number setup
bool draw_colon = true;

void setup() {
    matrix_left.begin(0x70);  // For some clocks this is 71... figure out which one.

    Time.zone(-4);
}

void loop() {
 matrix_left.print((Time.hourFormat12() * 100) + Time.minute());
    matrix_left.drawColon(draw_colon);
    matrix_left.writeDisplay();
    
    if (draw_colon) {
        draw_colon = false;
    } else {
        draw_colon = true;
    }
    
    delay(1000);
}x