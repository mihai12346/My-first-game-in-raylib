
#include "raylib.h"

#include<iostream>  
const int screenWidth = 1000;
    const int screenHeight = 850;
Vector2 ball_speed = { 10.0f,6.5f };
Vector2 pick_position = { (float)screenWidth,(float)screenHeight - 250 };
Rectangle pick_object = { pick_position.x,pick_position.y,170.0f,140.0f };

Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
bool vizibil = true;

class rocket {

public:
    Rectangle enemy = { 700,750 - 100,100.0f,80.0f };
    
    void draw_rockets(int _coord_x_inmaic,int coord_y) {
        enemy.y = coord_y;
        enemy.x = _coord_x_inmaic;
pick_object.x = pick_position.x;
    pick_object.y = pick_position.y;
    if (vizibil && CheckCollisionRecs(enemy, pick_object)) {
        vizibil = false;
    }
    else {
        vizibil = true;
        DrawRectangleRec(enemy, DARKPURPLE);
    }

   
    
        
      if (CheckCollisionCircleRec(ballPosition, 50, enemy) == true && vizibil == true) {
            ballPosition.x = 0.0f;
            ballPosition.y = (float)screenHeight - 100;
        }


    }
};
int main(void)
{
   
   

    InitWindow(screenWidth, screenHeight, "Force Field");
   

   pick_position = { (float)screenWidth,(float)screenHeight - 250 };

   Rectangle celling_position = {0,-5000,(float)screenWidth + 9000, (float)screenHeight };
   Vector2 bullet_speed = {};
   Rectangle ground_position = { 0, (float)screenHeight -100,(float) screenWidth+9000, (float)screenHeight};
   Camera2D camera = { 0 };

   int ground_x =1000 ;
   camera.offset = {screenWidth / 2.0f, screenHeight / 1.3f };
   camera.target = ballPosition;
   camera.zoom = 0.5f;
   SetTargetFPS(60);
                  
    bool stilljump = false;
    bool grounded = false;
   
     
    while (!WindowShouldClose())   
    {
        HideCursor();

         camera.target = ballPosition;
         /*if (CheckCollisionCircleRec(ballPosition, 50, enemy) && vizibil == true) {
             ballPosition.x = 0.0f;
             ballPosition.y = (float)screenHeight - 100;
         }
        */
       // WaitTime(0.001);
        //ballPosition.y += ball_speed.y;
        if (CheckCollisionCircleRec(ballPosition, 50, ground_position)) {
            ballPosition.y = (float)ground_position.y - 50;
            ball_speed.y = 0.0f;
            WaitTime(0.002);
            grounded = true;


            
        }
      
        else if(!CheckCollisionCircleRec(ballPosition, 50, ground_position)) {
            grounded = false;
            ball_speed.y = 6.5f;
            ballPosition.y += ball_speed.y;
        }
        if ( ballPosition.y > 850||IsKeyPressed('O')) {
           ballPosition.x = 0.0f;
          ballPosition.y = (float)screenHeight - 100;
        }

        if (IsKeyPressed('W' )&&grounded==true ) {
            //stilljump = true;
            ball_speed.y = -500.0f;
             ballPosition.y += ball_speed.y;
        }
        if (CheckCollisionCircleRec(ballPosition, 50, celling_position)) {
            ballPosition.y -= celling_position.y ;
        }
        
        if (IsKeyDown('D')) ballPosition.x += ball_speed.x;
        if (IsKeyDown('A')) ballPosition.x -= ball_speed.x;
       
         Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), camera);;
            pick_object = { pick_position.x,pick_position.y,170.0f,140.0f };
      
            pick_position.x = mousePos.x;
            pick_position.y = mousePos.y ;
           pick_object= { pick_position.x,pick_position.y, 170.0f, 140.0f };
           if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
               pick_object = { pick_position.x, pick_position.y, 170.0f, 140.0f };
           }
           if (CheckCollisionRecs(pick_object,ground_position)) {
               pick_object.y = (float)pick_object.y - 50;
               if (pick_object.y > ground_position.y)pick_object.y = ground_position.y - 50;
       }
          if (CheckCollisionCircleRec(ballPosition, 50, pick_object)) {
               ballPosition.y = (float)pick_object.y  ;
               WaitTime(0.02);
               ball_speed.y = 0.0f;
           }

        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(RAYWHITE);
        rocket rocket;
for(int i=0;i<19;i++){
       rocket.draw_rockets(700+i*500,650+i*-17);
       rocket.draw_rockets(700+i*500,650);
       rocket.draw_rockets(700 + i * 500, 650);
       rocket.draw_rockets(700 + i * 500, 650+i*-150);
       rocket.draw_rockets(700 + i * 500, 650+i*-80);
       rocket.draw_rockets(700 + i * 500, 650+i*-400);
       rocket.draw_rockets(700 + i * 500, 650+i*-90);
       rocket.draw_rockets(700 + i * 500, 100);
       rocket.draw_rockets(2000 + i * 500, 650 + i * -30);
       rocket.draw_rockets(700 + i * 500, 650 + i * -250);
       rocket.draw_rockets(700 + i * 700, 650 + i * -500);
}
      /*  rocket.draw_rockets(1200);
        rocket.draw_rockets(700+1000);
        rocket.draw_rockets(700+1500);
        rocket.draw_rockets(700+2000);
        rocket.draw_rockets(700+2500);
        rocket.draw_rockets(700+3000);
        rocket.draw_rockets(700+3500);
        rocket.draw_rockets(700+4000);
        rocket.draw_rockets(700+4500);
        rocket.draw_rockets(700+5000);
        rocket.draw_rockets(700+6000);
        rocket.draw_rockets(800,400);
        rocket.draw_rockets(6200);
        rocket.draw_rockets(7000);
        rocket.draw_rockets(6900);
        */
        DrawRectangleRec(ground_position, DARKGREEN);
        DrawRectangleRec(celling_position,DARKGREEN);

           // if (!CheckCollisionRecs(enemy, pick_object)) {DrawRectangleRec(enemy, YELLOW);
                
                   
           // }
          //  else {
           //     vizibil = false;
          //  }
        
        

       /* for (int i = 0; i < 15; i++) {
           skibidi += 800.0f;
           Rectangle enemies{ skibidi,enemy.y,enemy.width,enemy.height };
       }
       for (float i = 2; i < 50; i++) {

            DrawRectangle((int)ground_x, (int)ground_position.y, podea_width, podea_height, DARKGREEN);


            std::cout << "12";
        }*/
        DrawRectangleRec(pick_object,RED);
        DrawText("Force Field", 100, 100, 90, DARKGRAY);
        DrawText("You win", 10000-100, 100, 90, DARKPURPLE);
        DrawCircleV(ballPosition, 50,BLUE);
        EndMode2D();
        EndDrawing();
       
    }
    CloseWindow();    

    return 0;
}
