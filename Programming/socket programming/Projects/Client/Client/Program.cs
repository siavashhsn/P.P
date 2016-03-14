using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;


namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            Socket sck = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            IPEndPoint endPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1994);
            sck.Connect(endPoint);

            Console.Write("Enter  : ");
            string msg = Console.ReadLine();
            byte[] msgBuffer = Encoding.Default.GetBytes(msg);
            sck.Send(msgBuffer, 0, msgBuffer.Length, 0);
            byte[] buffer = new byte[255];
            int rec = sck.Receive(buffer, 0, buffer.Length, SocketFlags.None);

            Array.Resize(ref buffer, rec);

            Console.WriteLine("Received: {0}", Encoding.Default.GetString(buffer));

            Console.Read();
        }
    }
}
