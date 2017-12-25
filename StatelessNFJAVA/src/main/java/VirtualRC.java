import java.util.HashMap;
import java.util.Map;

public class VirtualRC extends RC {
    private Map<String, String> datastore;
    VirtualRC(){
        datastore = new HashMap<String, String>();
    }
    public String ReadRC(String key) {
        if (datastore.containsKey(key)) return datastore.get(key); else return null;
    }

    public void WriteRC(String key, String value) {
        datastore.put(key, value);
    }

    public void DeleteRC(String key) {
        if (datastore.containsKey(key)) datastore.remove(key);
    }
}
