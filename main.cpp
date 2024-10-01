#include <iostream>
#include <fstream>
#include <sstream>
#include "Songcpp.h"
#include "LinkedListcpp.h"

void testDummyData();
int populateDatabase(LinkedList<Song> &database,SortBy<Song> f);
void testDatabase(LinkedList<Song> & database, SortBy<Song> f);

//GIVEN
int main() {

//test the dummy database 
testDummyData();
//create the song database
LinkedList<Song> database;
// select sort by title so  create the function object with true parameter
SortBy<Song> f(true);
// populate the database and report the steps/complexity
int steps =populateDatabase(database, f);
std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
std::cout<<"Populated the Song Data Base \n";
std::cout<<"Number of steps needed for insert is "<<steps<<"\n";
std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//database.printList();
// put the database through its paces.
testDatabase(database,f);

}
//GIVEN 
int populateDatabase(LinkedList<Song>& database,SortBy<Song> f){
  int steps=0;
  int insertSteps=0;
  std::ifstream input("SongsData.txt");
  std::string line;
  std::string title;
  std::string singer;
  std::string cp;//chart position in string
  int chartPosition=0;
  int dataCount=0;
  Song s;
  if (!input){
    throw new std::string("File Open Error ");
    exit(-1);
  }
  while (std::getline(input,line)){
   // std::getline(input,line);
    std::string token;
      std::istringstream instream(line);
      std::getline(instream,title, ',');
      std::getline(instream, singer, ',');
      std::getline(instream, cp,'\n');
     // std::cout<<cp<<std::endl;
      chartPosition = std::stoi(cp);
       s.setTitle(title);s.setSinger(singer); s.setChartPosition(chartPosition);
      insertSteps=database.insert(s,f);
      //std::cout<<"INSERT STEPS = "<<insertSteps<<"\n";
      steps+=insertSteps;

      }  
 return steps;
}
//GIVEN
void testDatabase(LinkedList<Song> &database,SortBy<Song> f){
  Song newSong("candle in the wind","Purple",500);
  Song found;
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  std::cout<<"INSERTING SONG "<<newSong.toString()<<"\n";
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  database.insert(newSong,f);
  //database.printList();
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  std::cout<<"SEARCH THIS INSERTED SONG "<<newSong.toString()<<"\n";
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  found=database.get(newSong);
  
   std::cout<<"\n results "<<found.toString()<<"\n";
   std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   std::cout<<"SEARCH SONG at INDEX 3 \n ";
   found= database.get(3);
  
   std::cout<<"\n results "<<found.toString()<<"\n";
   std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   std::cout<<"REMOVING THIS SONG IN THE MIDDLE OF THE DATABASE \n ";
   database.remove(found);
    std::cout<<"SEARCH THIS REMOVED SONG "<<found.toString()<<"\n";
    found=database.get(found);
    std::cout<<" \n results "<<found.toString()<<"\n";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout<<"SEARCH SONG at INDEX 0 \n ";
    found=database.get(0);
    std::cout<<" \n results "<<found.toString()<<"\n";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout<<"REMOVING THE FIRST SONG OF THE DATABASE \n ";
    database.remove(found);
    std::cout<<"SEARCH THIS REMOVED SONG \n ";
    found=database.get(found);
    std::cout<<"\n results "<<found.toString()<<"\n";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    database.printList();

}
//GIVEN
void testDummyData(){
 Song one ("One ", "Apple", 1);
 Song two("Two ", "Boy", 2);
 Song three ("Three", "Cat", 3);
 Song four("Four ", "Dog", 4);
 LinkedList<Song> songList;
 SortBy<Song> f(false);
 songList.insert(two,f);
 songList.insert(four,f);
 
 songList.insert(one,f);
 songList.insert(three,f);
 songList.printList();
 std::cout<<"**********************\n";
 std::cout<<"REMOVING from the Start - ONE \n";
 songList.remove(one);
 songList.printList();
 std::cout<<"**********************\n";
 Song result=songList.get(one);
 if (result.getTitle()=="")
    std::cout<<one.getTitle()<< " Not Found\n";
 std::cout<<"ADDING BACK ONE  \n";
 songList.add(one);
 songList.printList();
 std::cout<<"**********************\n";
 std::cout<<"SEARCHING for Song at Index 2  \n";
 result = songList.get(2);
 std::cout<<result.getTitle()<< "\nFound at index position 2 \n";
 std::cout<<"REMOVING from the MIDDLE - THREE \n";
 songList.remove(three);
 songList.printList();
 std::cout<<"**********************\n";
 std::cout<<"REMOVING from the end - FOUR \n";
 songList.remove(four);
 songList.printList();
 std::cout<<"**********************\n";
 std::cout<<"Empty the database -REMOVING  ONE \n";
 songList.remove(one);
 songList.printList();
 std::cout<<"**********************\n";
 std::cout<<"Empty the database -REMOVING  TWO \n";
 songList.remove(two);
 songList.printList();
 std::cout<<"**********************\n";
  std::cout<<"ADDING BACK THREE - to test insert does place in  order  \n";
 songList.insert(three,f);
 songList.printList();
 std::cout<<"**********************\n";
 std::cout<<"ADDING BACK FOUR - to test insert does place in  order  \n";
 songList.add(four);
 songList.printList();
}
