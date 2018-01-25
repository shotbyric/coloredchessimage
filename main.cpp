#include <iostream>
#include <fstream>
#include <vector>
#include <string>


//Global Variables
int column_count = 0;
int rows_count = 0;
int colorflag = 0;
int flag = 0;
int r = 0, g = 0, b = 0;
int R = 0, G = 0, B = 0;

//Function Declarations
void parse_string(std::string hola1);
std::string to_uppercase(std::string str);
void adjust_rgb(std::string mystr1, std::string mystr2);


// Start of Main
int main()
{
    int n {0};
    std::cout << "Enter a number to determine the size of the chess pattern:\nEx: '8' " << std::endl;
    std::cin >> n;

    
    std::cout << "\nChoose 2 of the following colors for the chess pattern: \nBlue, Yellow, Red, Green, Black, White, Orange" << std::endl << "\nEx: 'Black, White'\n" << std::endl;
    
    std::string colors_string = {};
    
    //Wait until user inputs a string
    while(colors_string.empty()!= 0){
        std::getline(std::cin, colors_string);
    }
    
    parse_string(colors_string);
    
    std::cout << std::endl << "Generating a " << n << "x" << n << " chess pattern..." << std::endl;

    
    //Image Set-up
    std::ofstream img ("picture.ppm");
    img << "P3" << std::endl;
    const int width = n*100;
    const int height = n*100;
    img << width << " " << height << std::endl;
    img << "255" << std::endl;
    
    
    // ---- Nested loops for creating the chess pattern ----
    for(int x = 0; x < width; x++)
    {
        if(rows_count == 100){
            colorflag = (colorflag+1)%2;
            rows_count = 0;
            flag = (flag+1)%2;
        }
        if (flag == 0){
            colorflag = (colorflag+1)%2;
        }
        
        
        for(int y = 0; y < height; y++)
        {
            if(column_count == 100){
                colorflag = (colorflag+1)%2;
                column_count = 0;
            }
            
            if(colorflag ==0){
                  img << r << " " << g << " " << b << std::endl;
            }
            else if(colorflag == 1){
                img << R << " " << G << " " << B << std::endl;
            }
            
            column_count++;
        }
        rows_count++;
        if (colorflag == 1 ){
            colorflag = 0;
        }
        
        if (colorflag == 0){
            colorflag = 1;
        }

 
    }
    // ---- end of nested loops ----
    
    
    //Open the Image
    system("open picture.ppm");
 
    return 0;
}
// End of Main




// This function parses a string and assigns colors for the chessboard based on the retrieved words
void parse_string(std::string hola1)
{
    
    //parse string to obtain each color
    std::string delimiter = ",";
    std::string color1 = hola1.substr(0, hola1.find(delimiter));
    std::string color2 = hola1.erase(0, (hola1.find(delimiter))+2);
    
    //convert all char of string to UPPERCASE
    color1 = to_uppercase(color1);
    color2 = to_uppercase(color2);
    
    // assign a color based on the words obtained when parsing the string
    adjust_rgb(color1, color2);

}


//convert char of string to UPPERCASE
std::string to_uppercase(std::string str)
{
    for(char& c : str) {
        if( c >= 'a' && c <= 'z')
        {
           c = c - 32;
        }
    }
    return str;
}


//assign color based on string
void adjust_rgb(std::string mystr1, std::string mystr2){
    if(mystr1 == "WHITE"){
        r = 255;
        g = 255;
        b = 255;
    }else if(mystr1 == "BLACK"){
        r = 0;
        g = 0;
        b = 0;
    }else if(mystr1 == "BLUE"){
        r = 0;
        g = 0;
        b = 255;
    }else if(mystr1 == "RED"){
        r = 255;
        g = 0;
        b = 0;
    }else if(mystr1 == "GREEN"){
        r = 0;
        g = 255;
        b = 0;
    }else if(mystr1 == "YELLOW"){
        r = 255;
        g = 255;
        b = 0;
    }else if(mystr1 == "ORANGE"){
        r = 255;
        g = 153;
        b = 51;
    } else{
        r = 0;
        g = 0;
        b = 0;
    }
    
    
    
    if(mystr2 == "WHITE"){
        R = 255;
        G = 255;
        B = 255;
    }else if(mystr2 == "BLACK"){
        R = 0;
        G = 0;
        B = 0;
    }else if(mystr2 == "BLUE"){
        R = 0;
        G = 0;
        B = 255;
    }else if(mystr2 == "RED"){
        R = 255;
        G = 0;
        B = 0;
    }else if(mystr2 == "GREEN"){
        R = 0;
        G = 255;
        B = 0;
    }else if(mystr2 == "YELLOW"){
        R = 255;
        G = 255;
        B = 0;
    }else if(mystr2 == "ORANGE"){
        R = 255;
        G = 153;
        B = 51;
    }
    else{
        R = 255;
        G = 255;
        B = 255;
    }
}

