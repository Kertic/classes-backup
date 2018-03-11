using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Class1_Intro
{
    public partial class Form1 : Form
    {
        bool[,] universe = new bool[15, 15];

        Color gridColor = Color.Black;
        Color cellColor = Color.Gray;

        Timer timer = new Timer();
        int generations = 0;

        public Form1()
        {
            InitializeComponent();

            //universe[1, 1] = true;

            timer.Enabled = true;
            timer.Interval = 20;
            timer.Tick += Timer_Tick;
        }

        // int CountNeighborsFinite(int x, int y);
        // void NextGeneration()

        private void Timer_Tick(object sender, EventArgs e)
        {
            // NextGeneration()
            generations++;

            toolStripStatusLabelGenerations.Text = "Generations: " + generations.ToString();

            graphicsPanel1.Invalidate();
        }

        private void graphicsPanel1_Paint(object sender, PaintEventArgs e)
        {
            // Change almost everything to floats
            int width = graphicsPanel1.ClientSize.Width / universe.GetLength(0);
            int height = graphicsPanel1.ClientSize.Height / universe.GetLength(1);

            Pen gridPen = new Pen(gridColor, 1);
            Brush cellBrush = new SolidBrush(cellColor);

            for (int y = 0; y < universe.GetLength(1); y++)
            {
                for (int x = 0; x < universe.GetLength(0); x++)
                {
                    // RectangleF floats
                    Rectangle rect = Rectangle.Empty;
                    rect.X = x * width;
                    rect.Y = y * height;
                    rect.Width = width;
                    rect.Height = height;

                    // Is cell alive?
                    if (universe[x, y])
                    {
                        e.Graphics.FillRectangle(cellBrush, rect);
                    }

                    e.Graphics.DrawRectangle(gridPen, rect.X, rect.Y, rect.Width, rect.Height);
                }
            }

            gridPen.Dispose();
            cellBrush.Dispose();


        }

        private void graphicsPanel1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                // Change almost everything to floats
                int width = graphicsPanel1.ClientSize.Width / universe.GetLength(0);
                int height = graphicsPanel1.ClientSize.Height / universe.GetLength(1);

                int x = e.X / width;
                int y = e.Y / height;

                universe[x, y] = !universe[x, y];

                graphicsPanel1.Invalidate();
            }
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            for (int y = 0; y < universe.GetLength(1); y++)
            {
                for (int x = 0; x < universe.GetLength(0); x++)
                {
                    universe[x, y] = false;
                }
            }

            graphicsPanel1.Invalidate();
        }
    }
}
