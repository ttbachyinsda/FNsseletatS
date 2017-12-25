
public class NAT extends NF {
    private RC nowRC;
    private String ClusterID;
    public NAT(RC newRC, String newClusterID)
    {
        nowRC = newRC;
        ClusterID = newClusterID;
    }
    private String select_IP_Port(String listIPPort, String tupleof5)
    {
        return "127.0.0.1:2131";
    }
    private String update(String listIPPort, String IPport)
    {
        return listIPPort;
    }
    private Packet updatePacketHeader(Packet P, String IPport)
    {
        return P;
    }
    public void ProcessPacket(Packet P) {
        String tupleof5 = P.Get("5-tuple");
        String PIPport = P.Get("IPport");
        String IPport = nowRC.ReadRC(tupleof5);
        if (IPport == null)
        {
            String listIPPort = nowRC.ReadRC(ClusterID);
            IPport = select_IP_Port(listIPPort, tupleof5);
            listIPPort = update(listIPPort, IPport);
            nowRC.WriteRC(ClusterID, listIPPort);
            nowRC.WriteRC(tupleof5, IPport);
            String reversetupleof5 = tupleof5;
            nowRC.WriteRC(reversetupleof5, PIPport);
        }
        Packet P1 = updatePacketHeader(P, IPport);
        PacketSender.sendPacket(P1);
    }
}
