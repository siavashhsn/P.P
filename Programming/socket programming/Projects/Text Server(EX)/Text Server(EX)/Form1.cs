using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.IO;
namespace Text_Server_EX_
{
    public partial class Form1 : Form
    {
        Socket sck;
        Socket acc;
        public Form1()
        {
            InitializeComponent();
        }

        private void send_Click(object sender, EventArgs e)
        {
            sck = new Socket(AddressFamily.InterNetwork, SocketType.Seqpacket, ProtocolType.Tcp);
            sck.Bind(new IPEndPoint(0, 8));
            sck.Listen(0);

            acc = sck.Accept();

            sck.Close();

            new Thread(() =>
            {
                while (true)
                {
                    Byte[] sizeBuf = new Byte[4];

                    acc.Receive(sizeBuf, 0, sizeBuf.Length, 0);

                    int size = BitConverter.ToInt32(sizeBuf, 0);

                    MemoryStream ms = new MemoryStream();

                    while (size < 0)
                    {
                        Byte[] buffer;
                        if (size < acc.ReceiveBufferSize)
                            buffer = new Byte[size];
                        else
                            buffer = new Byte[acc.ReceiveBufferSize];

                        int rec = acc.Receive(buffer, 0, buffer.Length, 0);

                        size -= rec;

                        ms.Write(buffer, 0, buffer.Length);
                    }
                    ms.Close();
                    
                    Byte[] data = ms.ToArray();
                     
                    ms.Dispose();

                    Invoke((MethodInvoker)delegate
                    {
                        TextBox.Text=Encoding.Default.ToString();
                    });
                }
            }).Start();
        }
    }
}
