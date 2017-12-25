import java.util.List;

public class LoadBalancer extends NF {
    private RC nowRC;
    private String ClusterID;
    public LoadBalancer(RC newRC, String newClusterID)
    {
        nowRC = newRC;
        ClusterID = newClusterID;
    }
    private String nextServer(String backendList, String tupleof5)
    {
        return "InfiniServer";
    }
    private String updateLoad(String backendList, String server)
    {
        return backendList;
    }
    public void ProcessPacket(Packet P) {
        String tupleof5 = P.Get("5-tuple");
        String status = P.Get("status");
        if (status.equals("SYN")){
            String backendList = nowRC.ReadRC(ClusterID);
            String server = nextServer(backendList, tupleof5);
            backendList = updateLoad(backendList, server);
            nowRC.WriteRC(ClusterID, backendList);
            nowRC.WriteRC(tupleof5, server);
        } else {
            String server = nowRC.ReadRC(tupleof5);
            if (server == null){
                PacketSender.dropPacket(P);
            } else {
                PacketSender.sendPacket(P, server);
            }
        }
    }
}
