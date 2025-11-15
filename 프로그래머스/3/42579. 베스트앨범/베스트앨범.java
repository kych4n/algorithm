import java.util.*;
import java.util.stream.*;

class Genre {
    String name;
    int songPlayCount = 0;
    public Genre(String name, int songPlayCount) {
        this.name = name;
        this.songPlayCount = songPlayCount;
    }
}

class Song {
    int id;
    int playCount;
    public Song(int id, int playCount) {
        this.id = id;
        this.playCount = playCount;
    }
}

class Solution {
    static final int songCountPerGenre = 2;
    
    public int[] solution(String[] genres, int[] plays) {
        int songCount = genres.length;
        Map<String, Integer> genreToPlayCount = new HashMap<>();
        for (int i=0; i<songCount; i++) {
            String genre = genres[i];
            int playCount = plays[i];
            genreToPlayCount.put(genre, genreToPlayCount.getOrDefault(genre, 0)+playCount);
        }
        
        int genreCount = genreToPlayCount.keySet().size();
        Queue<Genre> genrePQ = new PriorityQueue<>((a, b) -> {
            return b.songPlayCount - a.songPlayCount;
        });
        for (Map.Entry<String, Integer> entry : genreToPlayCount.entrySet()) {
            genrePQ.add(new Genre(entry.getKey(), entry.getValue()));
        }
        
        Map<String, Queue<Song>> genreToSongs = new HashMap<>();
        for (String genre : genreToPlayCount.keySet()) {
            genreToSongs.put(genre, new PriorityQueue<>((a, b) -> {
                if (a.playCount == b.playCount) {
                    return a.id - b.id;
                }
                return b.playCount - a.playCount;
            }));
        }
        
        for (int i=0; i<songCount; i++) {
            String genre = genres[i];
            int playCount = plays[i];
            genreToSongs.get(genre).add(new Song(i, playCount));
        }
        
        List<Integer> temp = new ArrayList<>();
        while (!genrePQ.isEmpty()) {
            String genre = genrePQ.poll().name;
            Queue<Song> songs = genreToSongs.get(genre);
            for (int count = 0; count < songCountPerGenre; count++) {
                if (songs.isEmpty()) {
                    break;
                }
                temp.add(songs.poll().id);
            }
        }
        
        int[] answer = temp.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}