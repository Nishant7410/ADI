import java.util.*;
import java.io.*;
import Nishant.ds;

class Playlist
{
    String playlistname;
    String playlistid;
    private static class Songs
    {
        String songname;
        String songid;
        Songs next;
        Songs prev;
        Songs(String name)
        {
            songname=name;
        }
        String getSongname()
        {
            return songname;
        }
        String getSongid()
        {
            return songid;
        }
        void setSong(String name)
        {
            songname=name;
        }
        void setSongid(String id)
        {
            songid=id;
        }
        Songs getNext()
        {
            return next;
        }
        void setNext(Songs next)
        {
            this.next=next;
        }
        Songs getPrev()
        {
            return prev;
        }
        void setPrev(Songs prev)
        {
            this.prev=prev;
        }
    }
    static DoublyLinkedList<Songs> playlistsong;
    DoublyLinkedList<Songs> allplaylist;
   public Playlist(String name)
   {
       playlistname=name;
   }
    public String getPlaylist()
    {
        return playlistname;
    }
    public void setPlaylist(String name)
    {
        playlistname=name;
    }
    public String getPlaylistid()
    {
        return playlistid;
    }
    public void setPlaylistid(String id)
    {
        playlistid=id;
    }
    public static Playlist createPlaylist()
    {
        Scanner sc=new Scanner(System.in);
        String name=sc.nextLine();
        return new Playlist(name);
    }
     void addSong() {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Song name:");
        String songname=sc.nextLine();
        boolean exists=false;
        try {
            BufferedReader in = new BufferedReader(new FileReader("songs.txt"));
            String fileplaylistname=in.readLine();
           // String fileplaylistid;
            if(fileplaylistname==null) {
                System.out.println("Nothing Saved");
                return;
            }
            fileplaylistid=in.readLine();
            while(fileplaylistname!=null) {
                System.out.println(fileplaylistname);
                if(fileplaylistname.equals(songname)) {
                    exists=true;
                    System.out.println("Song named "+fileplaylistname+" added to your playlists");
                    addSongToLinklist(new Song(fileplaylistname));
                    return ;
                }
                fileplaylistname=in.readLine();
                fileplaylistid=in.readLine();
            }
            in.close();
            }catch(Exception e) {
                System.out.println("Error in reading all Songs file");
            }
    }
    void savePlaylistToFile() {

        try {
        ObjectOutputStream os1 = new ObjectOutputStream(new FileOutputStream("playlist.txt",true));
            os1.writeObject(this);
        os1.close();
        }catch(Exception e) {

        }

        
    }
    public static void openplaylistmenu()
    {
       Scanner sc=new Scanner(System.in);
        int a;
        while(true) {

            System.out.println("Choose Your Option :");
            System.out.println(" 1 for Add Song");
            System.out.println(" 2 for Delete Song");
            System.out.println(" 3 for Play Song");
            System.out.println(" 4 for Set Mode");
            System.out.println(" 5 for Save Playlist");
            System.out.println(" 6 for Display All Song");
            System.out.println(" 7 for Back to Main Menu");

             a=sc.nextInt();
    
            switch(a) {
                case 1:
                if(playlistsong==null)
                playlistsong=new DoublyLinkedList<>();
                    addSong();
                break;
                case 2:
                    
                break;
                case 3:

                break;
                case 4:
                    
                break;
                case 5:
                    savePlaylistToFile();
                break;
                case 6:
                    
                break;
                case 7:
                    return;

                default:
    
                break;
            }
        }  
    }
     public static Playlist openplaylist() {
        
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Playlist name :");
        
        String filename=sc.nextLine();
        boolean exists=false;
        try{
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("playlist.txt"));
            Playlist temp=(Playlist)ois.readObject();
            System.out.println(temp.getPlaylist());
            while(temp!=null) {

                if(temp.getPlaylist().equals(filename)) {
                    exists=true;
                    return temp;
                }

                    temp=(Playlist)oi.readObject();
            }
          ois.close();
        }catch(Exception e) {
            System.out.println("Error in open playlist");
        }

        return null;
    }
}
public class Media
{
    public static void main(String ar[])
    {
        Scanner sc=new Scanner(System.in);
        Playlist current;
        while(true)
        {
        System.out.println("Choose Your Option :");
        System.out.println(" 1 for Create Playlist");
        System.out.println(" 2 for Open Playlist");
        System.out.println(" 3 for exit");
        String a=sc.next();        
        switch(a)
        {
            case "1":
            current=Playlist.createPlaylist();
            current.openplaylistmenu();
            break;    
            case "2":
            Playlist.displayallsong();   
            current=Playlist.openplaylist();
            if(current!=null)
            current.openplaylistMenu();
            break;    
            case "3"
            System.exit(0);
            break;
            default:
                break;
                
        }
        }
    }
}