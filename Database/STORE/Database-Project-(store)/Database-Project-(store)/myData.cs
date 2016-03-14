using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Configuration;

namespace Database_Project__store_
{
    class myData
    {
        public string strsql;
        public DataTable showData()
        {
            SqlConnection con1 = new SqlConnection(
                ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString);
            con1.Open();
            SqlDataAdapter da = new SqlDataAdapter(strsql, con1);
            DataTable dt = new DataTable();
            da.Fill(dt);
            con1.Close();
            return (dt);
        }

        public void manData()
        {
            SqlConnection con1 = new SqlConnection(
                ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString);
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.Connection = con1;
            c1.CommandText = strsql;
            try     { c1.ExecuteNonQuery();                  }
            catch   { MessageBox.Show("داده اشکال دارد");   }

            con1.Close();
        }
    }
}
