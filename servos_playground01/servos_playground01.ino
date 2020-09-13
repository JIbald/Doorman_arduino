    #include <Servo.h>

    //(S)RE : (Servo) right eye
    //(S)LE : (Servo) left eye
    //vertical : vertical movement
    //horizontal : horizontal movement
    Servo SEyelids;
    Servo SRE_horizontal;
    Servo SLE_horizontal;
    Servo SRE_vertical;
    Servo SLE_vertical;
    
    //pins for servos
    const int eyelids = 10;
    const int RE_horizontal = 5; 
    const int LE_horizontal = 6;
    const int RE_vertical = 3;
    const int LE_vertical = 9; 

    // name new position values here for easier use later
    // depending on servo positioning, this can get a little confusing
    // if you're simple minded like me.
    const int middle = 90;
    const int right = 65;
    const int left = 105;
    const int re_up = 65;
    const int le_up = 115;

    bool le_passed = false;
    bool re_passed = false;
    
    void setup()
    {
      SEyelids.attach(eyelids);
      SRE_horizontal.attach(RE_horizontal);
      SLE_horizontal.attach(LE_horizontal);
      SRE_vertical.attach(RE_vertical);
      SLE_vertical.attach(LE_vertical);

      Serial.begin(9600);
    }

    void loop()
    { 
      //allign the eyes and eyelids
      //SEyelids.write(middle);
      SRE_horizontal.write(middle);
      SLE_horizontal.write(middle);
      SRE_vertical.write(middle);
      SLE_vertical.write(middle);

      //open eyes
      SEyelids.write(40);
      
      delay(500);

      //look right
      SRE_horizontal.write(right);
      SLE_horizontal.write(right);

      delay(1000);

      //look left
      SRE_horizontal.write(left);
      SLE_horizontal.write(left);

      delay(1000);

      //look straight and look up
      SRE_horizontal.write(middle);
      SLE_horizontal.write(middle);
      SRE_vertical.write(re_up);
      SLE_vertical.write(le_up);

      delay(1000);

      //slowly yaw horizontally
      SRE_vertical.write(middle);
      SLE_vertical.write(middle);
      for( int i {65}; i <= 120; ++i)
      {
        SLE_horizontal.write(i);
        SRE_horizontal.write(i);
        delay(100); //this might be too fast/slow
      }

      delay(1000);

      //insert allginment here if you don't want the eyes to face left whilst doing the next movement
      //troll

      //slowly yaw vertically from top to bottom
      //RE needs to be increased
      //LE needs to be decreased
      int j {120};
      for (int i{55}; i <= 120; ++i)
      {
        SRE_vertical.write(i);
        SLE_vertical.write(j);
        --j;
        delay(200);
      }

      //makes downward half circle, so a "U-shape"
    int re_vertical_increment {55};
    int le_vertical_decrement {121};
    for (int i {65}; i <= 120; ++i)
    {
      SLE_horizontal.write(i);
      SRE_horizontal.write(i);
      SLE_vertical.write(le_vertical_decrement);
      SRE_vertical.write(re_vertical_increment);

      //set correct re_vertical increment
      if(re_vertical_increment < 90 && re_passed == false)
      {
        re_vertical_increment += 2;
      }
      if( re_vertical_increment > 90 )
      {
        re_passed = true;
      }
      if (re_passed == true )
      {
        re_vertical_increment -= 2;
      }

      //set correct le_vertical_increment
      if(le_vertical_decrement > 90 && le_passed == false )
      {
        le_vertical_decrement -= 2;
      }
      if ( le_vertical_decrement < 90 )
      {
       le_passed = true;
      }
      if(le_passed == true )
      {
        le_vertical_decrement += 2;
      }
      
      delay(100);
    }
    re_passed = false;
    le_passed = false;
    }
