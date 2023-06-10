#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"

// Renders Direct2D and 3D content on the screen.
namespace osu {
	class OsuGame : public DX::IDeviceNotify {
	public:
		OsuGame(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~OsuGame();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// Rendering loop timer.
		DX::StepTimer m_timer;
	};
}