* TORRENTREMOVER
This automates the removal of .torrent files from my download directory.
To set this up:
1. Move the executable to the ~/bin directory
2. Move the supplied plist file to ~/Library/LaunchAgents
3. Load the LaunchAgent with
    launchctl load ~/Library/LaunchAgents/com.rich.torrentremover.plist