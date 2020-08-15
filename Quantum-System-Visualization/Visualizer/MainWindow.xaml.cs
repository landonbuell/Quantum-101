using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Visualizer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private PagePresetSystem LocalPagePresetSystem;
        private PageCustomSystem LocalPageCustomSystem;
        private PageSettings LocalPageSetting;

    
        public MainWindow()
        {
            InitializeComponent();
            this.LocalPagePresetSystem = new PagePresetSystem();
            this.LocalPageCustomSystem = new PageCustomSystem();
            this.LocalPageSetting = new PageSettings();
        }

        private void btnPresetSystem_Click(object sender, RoutedEventArgs e)
        {
            // Preset Systems Button is Pressed
            frameMenuBottom.Navigate(LocalPagePresetSystem);
        }

        private void btnCustomSystem_Click(object sender, RoutedEventArgs e)
        {
            // Custom System Button is Pressed
            frameMenuBottom.Navigate(LocalPageCustomSystem);
        }

        private void btnSettings_Click(object sender, RoutedEventArgs e)
        {
            // Settings Button is Pressed
            frameMenuBottom.Navigate(LocalPageSetting);
        }
    }
}
