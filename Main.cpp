#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "BBTK C++ OOP"); // Create a SFML video 
	ImGui::SFML::Init(window); // Initialize the window.
	
	sf::Clock deltaClock; // Create a clock.

	while (window.isOpen()) // While the window is open.
	{
		sf::Event sfEvent;	// Create an SFML event for user input.
		while (window.pollEvent(sfEvent)) // Event checker
		{
			ImGui::SFML::ProcessEvent(sfEvent); // Process the event
			if (sfEvent.type == sf::Event::Closed) // If the event type is Event.Close
			{
				window.close(); // Close the window
			}
		}// End of event processing loop
		ImGui::SFML::Update(window, deltaClock.restart()); // After processing the events update the window and restart the clock.

		///////////////////////////////////////////////////////////////////////////////






		///////////////////////////////////////////////////////////////////////////////

		window.clear(sf::Color(82, 78, 118)); // Paint the backround to the given RGB color.
		ImGui::SFML::Render(window);	// Render the window
		window.display();	// Display window contens
	}

	ImGui::SFML::Shutdown();	// After the main program loop, shutdown the SFML context.
	return 0;
}