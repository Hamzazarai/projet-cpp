// Projet c++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace sf;
using namespace std;
int vitesse_rect = 23;
int vitesse_barre = 28;
float ret = 0.0045;//retard pour empecher la repetition du mouvement sur les diagonales dans la boucle :valeur choisie en testant a chaque fois la vitesse.
float xVelocity = 2.35;
float yVelocity = 2.3;
char key;


int main()
{

    //****************INTRO*****************//
    // Modifier la couleur du texte en rouge
    std::cout << "\033[1;31m";

    // Afficher un texte en rouge
    std::cout << "\n\n\t\t USE UP DOWN LEFT AND RIGHT KEYS.\n\t\t Don't touch the wall or get hit by any of the blocks.\n\n\t\tBe careful... it's addictive!\n\n";
    sf::sleep(sf::milliseconds(800));
    // Réinitialiser la couleur du texte à la valeur par défaut
    std::cout << "\033[0m";
    
    // Afficher un texte avec la couleur par défaut
    std::cout << "\n\n\t\tPRESS ANY KEY TO PLAY \n";
    cin.get(key);
    //********************************************//
    


    char restart;
    //*******audio******
    Music gameMusic, gameover;
    gameMusic.openFromFile("audio/audio.ogg");
    gameMusic.setVolume(10);
    gameMusic.play();
    gameMusic.setLoop(true);
    gameover.openFromFile("audio/gameover.ogg");
    gameover.setVolume(20);
    //********************
      // Game Over Sprite ---------------------------------------
    Texture gameoverTexture;
    gameoverTexture.loadFromFile("images/gameover.png");
    Sprite gameoverSprite(gameoverTexture);
    gameoverSprite.setPosition(350.0f, 300.0f);

    RenderWindow window(VideoMode(900, 800), "Projet c++");

    // Timer
   Font font;
    Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(40);
    timerText.setFillColor(Color::White);
    timerText.setPosition(10.f, 10.f);
    Clock clock;
     Time elapsedTime;
    //joueur:
    RectangleShape rect;
    //barrieres:
    RectangleShape barre1, barre2, barre3, barre4;

    //******position dans la fenetre*********
    Vector2f rectanglePosition(400, 400);
    Vector2f pos_barre1(10, 10);
    Vector2f pos_barre2(790, 780);
    Vector2f pos_barre3(10, 710);
    Vector2f pos_barre4(830, 10);

    rect.setPosition(rectanglePosition);
    rect.setSize(Vector2f(50, 50));
    rect.setFillColor(Color::White);

    barre1.setPosition(pos_barre1);
    barre1.setSize(Vector2f(80, 80));
    barre1.setFillColor(Color::Red);

    barre2.setPosition(pos_barre2);
    barre2.setSize(Vector2f(100, 10));
    barre2.setFillColor(Color::Green);

    barre3.setPosition(pos_barre3);
    barre3.setSize(Vector2f(20, 82));
    barre3.setFillColor(Color::Yellow);

    barre4.setPosition(pos_barre4);
    barre4.setSize(Vector2f(60, 110));
    barre4.setFillColor(Color::Blue);

    // j'ai reglé la position des 4 barres manuellement càd j'ai essayer avec plusieurs valeurs jusqu 'a les placer dans les positions correctes

    float xVelocity[4] = { 0.08f,0.08f,0.08f,0.08f };
    float yVelocity[4] = { 0.08f,0.08f,0.08f,0.08f };
    //*********************//



    


    while (window.isOpen())
    {
        Event event;
       


        while (window.pollEvent(event))
        {


            switch (event.type)
            {
            case Event::Closed:window.close(); break;
            case Event::KeyPressed:
            { //deplacement avec le clavier
                switch (event.key.code)
                {
                case Keyboard::Up:
                    rect.setPosition(Vector2f(rect.getPosition().x, rect.getPosition().y - vitesse_rect)); break;
                case Keyboard::Down:
                    rect.setPosition(Vector2f(rect.getPosition().x, rect.getPosition().y + vitesse_rect)); break;
                case Keyboard::Right:
                    rect.setPosition(Vector2f(rect.getPosition().x + vitesse_rect, rect.getPosition().y)); break;
                case Keyboard::Left:
                    rect.setPosition(Vector2f(rect.getPosition().x - vitesse_rect, rect.getPosition().y)); break;

                } break;
            }

            }//fin switch
            //deplacement  sur les diagonales
        }

        if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
        {
            rect.setPosition(Vector2f(rect.getPosition().x + ret * vitesse_rect, rect.getPosition().y - ret * vitesse_rect));
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
        {
            rect.setPosition(Vector2f(rect.getPosition().x - ret * vitesse_rect, rect.getPosition().y - ret * vitesse_rect));
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
        {
            rect.setPosition(Vector2f(rect.getPosition().x - ret * vitesse_rect, rect.getPosition().y + ret * vitesse_rect));
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
        {
            rect.setPosition(Vector2f(rect.getPosition().x + ret * vitesse_rect, rect.getPosition().y + ret * vitesse_rect));
        }

        //garder les barres dans la fenetre:
        //*****************************//
        if (pos_barre1.x < 0 || pos_barre1.x > 900 - 100) xVelocity[0] *= -1;
        if (pos_barre1.y < 0 || pos_barre1.y > 800 - 100) yVelocity[0] *= -1;

        pos_barre1.x += xVelocity[0];
        pos_barre1.y += yVelocity[0];
        barre1.setPosition(pos_barre1);

        if (pos_barre2.x < 30 || pos_barre2.x > 890) xVelocity[1] *= -1;
        if (pos_barre2.y < 30 || pos_barre2.y > 790) yVelocity[1] *= -1;

        pos_barre2.x += xVelocity[1];
        pos_barre2.y += yVelocity[1];
        barre2.setPosition(pos_barre2);

        if (pos_barre3.x < 10 || pos_barre3.x > 840) xVelocity[2] *= -1;
        if (pos_barre3.y < 20 || pos_barre3.y > 810) yVelocity[2] *= -1;

        pos_barre3.x += xVelocity[2];
        pos_barre3.y += yVelocity[2];
        barre3.setPosition(pos_barre3);

        if (pos_barre4.x < 0 || pos_barre4.x > 850) xVelocity[3] *= -1;
        if (pos_barre4.y < 10 || pos_barre4.y > 750) yVelocity[3] *= -1;

        pos_barre4.x += xVelocity[3];
        pos_barre4.y += yVelocity[3];
        barre4.setPosition(pos_barre4);

        //************************//


        //intersections:
        FloatRect r, b1, b2, b3, b4;
        r = rect.getGlobalBounds();
        b1 = barre1.getGlobalBounds();
        b2 = barre2.getGlobalBounds();
        b3 = barre3.getGlobalBounds();
        b4 = barre4.getGlobalBounds();

      

        // augmentation de la vitesse apres 20s
        static Clock clock;
        if (clock.getElapsedTime().asSeconds() >= 20) {

            vitesse_barre += 1;
        }

        //*****GAME OVER*******//
        if (r.intersects(b1) || r.intersects(b2) || r.intersects(b3) || r.intersects(b4) || r.left<0 || r.top<0 || r.left + r.width > window.getSize().x || r.top + r.height > window.getSize().y)
        {
            gameMusic.stop();
            gameover.play();
            window.clear();
            window.draw(gameoverSprite);
            window.display();
            cout << "press R to replay.";
            sf:: sleep(sf::milliseconds(500));
          //********************//
        
          //************RESTART**************//
            if (window.waitEvent(event)) {
                if (Keyboard::isKeyPressed(Keyboard::R)) 
                {
                    rectanglePosition = (Vector2f(400, 400));
                    pos_barre1 = (Vector2f(10, 10));
                    pos_barre2 = Vector2f(790, 780);
                    pos_barre3 = Vector2f(10, 710);
                    pos_barre4 = Vector2f(830, 10);
                    gameMusic.play();
                    gameMusic.setLoop(true);

                }
                else
                {
                   
                    return 0;
                }
            }
            //****************************************//
       // Mettez à jour le temps écoulé du chronomètre
            elapsedTime = clock.getElapsedTime();

            // Convertir le temps écoulé en minutes, secondes et millisecondes
            int minutes = static_cast<int>(elapsedTime.asSeconds()) / 60;
            int seconds = static_cast<int>(elapsedTime.asSeconds()) % 60;
            int milliseconds = elapsedTime.asMilliseconds() % 1000;

            // Construire la chaîne de caractères du temps écoulé
            stringstream ss;
            ss << setfill('0') << setw(2) << minutes << ":"
                << setfill('0') << setw(2) << seconds << ":"
                << setfill('0') << setw(3) << milliseconds;

            timerText.setString("Elapsed Time: " + ss.str());

        
        }


        
        window.clear();
        
        window.draw(rect);
        window.draw(barre1);
        window.draw(barre2);
        window.draw(barre3);
        window.draw(barre4);
        window.draw(timerText);
        window.display();
    }

    return 0;
}
   
 