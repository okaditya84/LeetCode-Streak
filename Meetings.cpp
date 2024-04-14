
std::vector<std::pair<int, int>> events;

    // Convert meeting timings to events
    for (const auto& meeting : meetingTimings) {
        events.push_back({meeting[0], 1});  // 1 represents start of meeting
        events.push_back({meeting[1], -1}); // -1 represents end of meeting
    }

    // Sort events based on time, giving priority to start events
    std::sort(events.begin(), events.end());

    int minRooms = 0;
    int currentRooms = 0;

    // Count number of rooms required
    for (const auto& event : events) {
        currentRooms += event.second;
        minRooms = std::max(minRooms, currentRooms);
    }

    return minRooms;