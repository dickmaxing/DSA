#include <iostream>
using namespace std;

struct song
{
    int sid;
    string title;
    string artist;
    float duration;
    song *next;
    song *prev; 
};

    
class playlist
{
    song *header;
    int len;

    void playSong(song *s){
        cout<<"\n"<<s->sid<<"\t"<<s->title<<"\n";
        return;
    }

    public:
    
    playlist(){
        header = NULL;
        len=0;
    }

    void addSong(string tit, int id){
        song *ns = new song;
        if(!ns)
            return;

        ns->title = tit;
        ns->sid = id;
        ns->next = NULL;
        len++;

        if(header == NULL){
            header = ns;
            return;
        }
        
        song *tempf = header;
        while(tempf->next){
            tempf = tempf->next;
        }
        tempf->next = ns;
        ns->prev = tempf; 
    }

    void play(int id){
        song *temp = header;
        while(temp->sid != id)
        {
            temp = temp->next;
        }
        playSong(temp);
    }

    void play(string tit){
        song *temp = header;
        while(tit.compare(temp->title) != 0){
            temp = temp->next;
        }
        playSong(temp);
    }

    void playAll(){
        song *tempf = header;
        while(tempf){
            playSong(tempf);
            tempf = tempf->next;
        }
    }

    void shufflleSong(){

        if(len<=0){
            cout<<"\nEmpty playlist"<<endl;
            return;
        }
        int done[len]  = {0};
        
        int songs_done = 0;
        
        int random_idx = 0;
        
        while(songs_done != len) {
        
            random_idx = rand() % len;
        
            while(done[random_idx] == 1) {
        
                random_idx = rand() % len;
            }
        
            int pos_of_song = 0;
            song* temp = header; 

        
            while(pos_of_song != random_idx && temp != nullptr) {
                temp = temp->next;
                pos_of_song++;
            }

            play(temp->sid);
        
            done[random_idx] = 1;
        
            songs_done++;
        }

    }

    void remSong(int id){
        if(len<1)
            return;
        if(len == 1){
            free(header);
            header = NULL;
            return;
        }
        song *temp = header;
        while(temp->sid != id){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    void remSong(string tit){
        if(len<1)
            return;
        if(len == 1){
            free(header);
            header = NULL;
            return;
        }
        song *temp = header;
        while(temp->title.compare(tit) != 0){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

};

int main()
{
    playlist p;
    
    int choice=0;
    do{
        cout<<"\nChoice: ";
        cin>>choice;
        int id;
        string tit;

        switch (choice)
        {
        case 0:
            cout<<"\nSong ID to add: ";
            cin>>id;

            cout<<"\nSong Title to add: ";
            cin>>tit;

            p.addSong(tit,id);
            break;
        case 1:
            cout<<"\nWhich sonng to play by ID:";
            cin>>id;
            p.play(id);
            break;
        case 2:
            cout<<"\nWhich sonng to play by Title:";
            cin>>tit;
            p.play(tit);
            break;
        case 3:
            cout<<"\nPlaying All songs:";
            p.playAll();
            break;
        case 4:
            cout<<"\nShuffeled Playlist";
            p.shufflleSong();
            break;
        case 5:
            cout<<"\nWhich sonng to Delete by ID:";
            cin>>id;
            p.remSong(id);
            break;
        case 6:
            cout<<"\nWhich sonng to Delete by Title:";
            cin>>tit;
            p.remSong(tit);
            break;
        default:
            break;
        }
    }while(choice != -1);
    return(0);
}
