import java.util.LinkedList;

public class HashTable {
    public class Entry{
        private int key;
        private String value;

        public Entry( int key,String value) {
            this.value = value;
            this.key = key;
        }
    }

    private LinkedList<Entry>[] entries = new LinkedList[5];

    public void put(int key, String value){
        var entry = getEntry(key);
        if (entry!= null){
            entry.value = value;
            return;
        }

        getOrCreateBucket(key).add( new Entry(key,value));

    }

    public String get(int key){
        return getEntry(key) == null ? null : getEntry(key).value;
    }

    public void remove(int key){
        var entry = getEntry(key);
        if( entry  == null)
            throw new IllegalStateException();
        getBucket(key).remove(entry);
    }

    private int hash(int key){
        return key % entries.length;
    }

    private LinkedList<Entry> getOrCreateBucket(int key){
        var index = hash(key);
        var bucket = entries[index];
        if (bucket == null) entries[index] = new LinkedList<>();
        return bucket;
    }

    private Entry getEntry(int key){
        var bucket = getBucket(key);
        if(bucket != null) {
            for (var entry : bucket) {
                if (entry.key == key)
                    return entry;
            }
        }
        return null;
    }
    private LinkedList<Entry> getBucket(int key) {
        return entries[hash(key)];

    }

}
