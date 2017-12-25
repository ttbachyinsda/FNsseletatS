import java.util.HashMap;
import java.util.Map;

public class VirtualPacket extends Packet {
    private Map<String,String> pkt;
    VirtualPacket()
    {
        pkt = new HashMap<String, String>();
    }
    public void Set(String key,String value)
    {
        pkt.put(key,value);
    }
    public String Get(String key)
    {
        if (pkt.containsKey(key)) return pkt.get(key); else return null;
    }
}