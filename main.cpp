#include <SFML/Graphics.hpp>
#include <iostream>

sf::Image image;
sf::Texture texture;
sf::Sprite sprite;
float speed = 2.0;
float CurrentFrame = 0;


int main()
{
    setlocale(LC_ALL, "rus");

//    sf::ContextSettings settings;                                                   
//    settings.antialiasingLevel = 6;                                             


    sf::RenderWindow window;                                                        
    window.create(sf::VideoMode(700,600), "Game" /*,sf::Style::Default, settings*/);        
    window.setFramerateLimit(60);



//    sf::CircleShape circle;                                                         
//    circle.setRadius(200);                                                      
//    circle.setFillColor(sf::Color::Cyan);                                           
//    circle.setPosition(175, 20);                                                 
//    circle.setOutlineColor(sf::Color::Blue);
//    circle.setOutlineThickness(10);


//    sf::RectangleShape square;
//    square.setSize(sf::Vector2f(750,370));
//    square.setPosition(1, 225);
//    square.setFillColor(sf::Color::Green);

//    sf::CircleShape square0(80, 4);
//    square0.setPosition(300, 300);
//    square0.setFillColor(sf::Color::Black);
//    square0.rotate(45);


//    sf::ConvexShape cube;
//    cube.setPointCount(5);
//    cube.setFillColor(sf::Color::Red);
//    cube.setPoint(0, sf::Vector2f(0, 0));
//    cube.setPoint(1, sf::Vector2f(150, 10));
//    cube.setPoint(2, sf::Vector2f(120, 90));
//    cube.setPoint(3, sf::Vector2f(30, 100));
//    cube.setPoint(4, sf::Vector2f(0, 50));
//    cube.setPosition(10, 20);
//    cube.setOutlineColor(sf::Color::Green);





    image.loadFromFile("player0.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 96));
    sprite.setPosition(400, 400);



    sf::Clock clock;



    while(window.isOpen())                                                      
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        std::cout<<"Time: "<<time<<std::endl;
        std::cout<<"CurrentFrame: "<<CurrentFrame<<std::endl;


        sf::Event event;                                                            
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }


                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    CurrentFrame += 0.1*time;
                    if(CurrentFrame>4)
                    {
                        CurrentFrame-=4;
                    }
                    sprite.setTextureRect(sf::IntRect(int(CurrentFrame)*64, 96, 64, 96));

                    sprite.move(-speed*time, 0);
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    CurrentFrame += 0.1*time;
                    if(CurrentFrame>4)
                    {
                        CurrentFrame-=4;
                    }
                    sprite.setTextureRect(sf::IntRect(int(CurrentFrame)*64, 192, 64, 96));

                    sprite.move(speed*time, 0);
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    CurrentFrame += 0.1*time;
                    if(CurrentFrame>4)
                    {
                        CurrentFrame-=4;
                    }
                    sprite.setTextureRect(sf::IntRect(int(CurrentFrame)*64, 288, 64, 96));

                    sprite.move(0, -speed*time);
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    CurrentFrame += 0.1*time;
                    if(CurrentFrame>4)
                    {
                        CurrentFrame-=4;
                    }
                    sprite.setTextureRect(sf::IntRect(int(CurrentFrame)*64, 0, 64, 96));

                    sprite.move(0, speed*time);
                }



            window.clear(sf::Color::Black);             

//            window.draw(circle);                    
//            window.draw(square);
//            window.draw(cube);
//            window.draw(square0);
            
            window.draw(sprite);


            window.display();                       


        }
    }





    return 0;
};

