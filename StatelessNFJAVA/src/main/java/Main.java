import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.Timer;
import java.util.concurrent.ConcurrentLinkedQueue;

class NATThread extends Thread{
    private NF nf;
    private Queue<Packet> packets;
    NATThread(RC rc, String ClusterID, Queue<Packet> packets)
    {
        nf = new NAT(rc,ClusterID);
        this.packets = packets;
    }
    @Override
    public void run() {
        synchronized (packets) {
            while (!packets.isEmpty()) {
                System.out.println(PacketSender.droptime + PacketSender.sendtime);
                Packet P = packets.remove();
                nf.ProcessPacket(P);
            }
        }
    }
}
public class Main {
    public static Queue<Packet> packets;
    public static void main(String[] args){
        packets = new ConcurrentLinkedQueue<Packet>();
        for (int i=0;i<1000000;i++)
        {
            Packet c = new VirtualPacket();
            c.Set("5-tuple", String.valueOf(new Random().nextInt()%20));
            c.Set("IPport", "127.0.0.1:1231");
            packets.add(c);
        }
        RC rc = new VirtualRC();
        for (int i=0;i<15;i++)
        {
            new NATThread(rc, "abcde", packets).start();
        }
        while (!packets.isEmpty());
    }
}
