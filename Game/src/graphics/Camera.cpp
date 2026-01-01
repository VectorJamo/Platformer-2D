#include "Camera.h"

float Camera::CamTopLeftX = 0.0f;
float Camera::CamTopLeftY = 0.0f;

void Camera::Update(const vec2& playerPosition, const vec2& playerDimension)
{
	Camera::CamTopLeftX = (playerPosition.x + playerDimension.width / 2) - WindowDimensions::Width / 2;
	Camera::CamTopLeftY = (playerPosition.y + playerDimension.height / 2) - WindowDimensions::Height / 2;

	if (Camera::CamTopLeftX < 0.0f)
		Camera::CamTopLeftX = 0.0f;
	else if (Camera::CamTopLeftX + WindowDimensions::Width > MapConstants::TotalWidth)
		Camera::CamTopLeftX = MapConstants::TotalWidth - WindowDimensions::Width;

	if (Camera::CamTopLeftY < 0.0f)
		Camera::CamTopLeftY = 0.0f;
	else if (Camera::CamTopLeftY + WindowDimensions::Height > MapConstants::TotalHeight)
		Camera::CamTopLeftY = MapConstants::TotalHeight - WindowDimensions::Height;
}
