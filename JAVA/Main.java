import java.io.*;
import java.util.*;

interface IFilm {
    void setTitle(String title);
    String getTitle();
    void setDirector(String director);
    String getDirector();
    void setYear(int year);
    int getYear();
}

interface IFilmLibrary {
    void addFilm(IFilm film);
    void removeFilm(String title);
    List<IFilm> getFilms();
    List<IFilm> searchFilms(String query);
    int getTotalFilmCount();
}

class Film implements IFilm {
    private String m_Title;
    private String m_Director;
    private int m_Year;

    public void setTitle(String title) {
        m_Title = title;
    }
    public String getTitle() {
        return m_Title;
    }

    public void setDirector(String director) {
        m_Director = director;
    }
    public String getDirector() {
        return m_Director;
    }

    public void setYear(int year) {
        m_Year = year;
    }
    public int getYear() {
        return m_Year;
    }

}

class FilmLibrary implements IFilmLibrary{
    private List<IFilm> films = new ArrayList<>();

    public void addFilm(IFilm film) {
        films.add(film);
    }
    public void removeFilm(String title) {
        for(int i = 0; i < films.size(); i++) {
            if(films.get(i).getTitle() == title) {
                films.remove(films.get(i));
            }
        }
    }
    public List<IFilm> getFilms() {
        return films;
    }
    public List<IFilm> searchFilms(String query) {
        System.out.println(query); 
        List<IFilm> ans = new ArrayList<>();
        for(int i = 0; i < films.size(); i++) {
            if(films.get(i).getDirector() == query || films.get(i).getTitle() == query) {
                ans.add(films.get(i));
            }
        }
        return ans;
    }
    public int getTotalFilmCount() {
        return films.size();
    }

}

class Main{  
    public static void main(String args[]){ 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        IFilmLibrary filmLibrary = new FilmLibrary();
        List<IFilm> films = new ArrayList<>();
        int fCount = Integer.parseInt(br.readLine().trim());
        for(int i = 1; i <= fCount; i++) {
            String[] a = br.readLine().trim().split(" ");
            IFilm e = new Film();
            e.setTitle(a[0]);
            e.setDirector(a[1]);
            e.setYear(Integer.parseInt(a[2]));

            filmLibrary.addFilm(e);
            films.add(e);
        }
        int totalFilm = filmLibrary.getTotalFilmCount();
        out.println("Total film count: " + totalFilm);
    }  
}  