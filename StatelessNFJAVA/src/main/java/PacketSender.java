public class PacketSender {
    public static int sendtime;
    public static int droptime;
    public static void dropPacket(Packet P)
    {
        droptime++;
    }
    public static void sendPacket(Packet P, String server)
    {
        sendtime++;
    }
    public static void sendPacket(Packet P)
    {
        sendtime++;
    }
}
