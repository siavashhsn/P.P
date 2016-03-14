using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace server__EX___from_site_
{
    class Program
    {
        static void Main(string[] args)
        {
            TcpListener serverSocket = new TcpListener(8888);
            int requestCount = 0;
            TcpClient clientSocket = default(TcpClient);
            serverSocket.Start();
            Console.WriteLine(" >> Server Started");
            clientSocket = serverSocket.AcceptTcpClient();
            Console.WriteLine(" >> Accepted connection from client");
            requestCount = 0;
            while (true)
            {
                try
                {
                    requestCount++;

                    NetworkStream networkStream = clientSocket.GetStream();

                    byte[] byteFrom = new byte[10025];

                    networkStream.Read(byteFrom, 0, byteFrom.Length);

                    string dataFormClient = Encoding.ASCII.GetString(byteFrom);

                    dataFormClient = dataFormClient.Substring(0,dataFormClient.IndexOf("$"));

                    Console.WriteLine(" >> Data from client - " + dataFormClient);

                    string serverResponse = "Last Message from client - " + dataFormClient;

                    Byte[] sendByte =  Encoding.ASCII.GetBytes(serverResponse);

                    networkStream.Write(sendByte, 0, sendByte.Length);
                    
                    networkStream.Flush();

                    Console.WriteLine(" >> " + serverResponse);

                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }

            clientSocket.Close();
            serverSocket.Stop();
            Console.WriteLine(" >> Exit");

            Console.ReadLine();
        }
    }
}
