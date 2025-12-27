#include "UIManager.h"
#include "Button.h"
#include "InputBox.h"
#include "input/MouseManager.h"

std::vector<Button*> UIManager::m_TrackedButtons;
std::vector <InputBox*> UIManager::m_TrackedInputBoxes;

bool UIManager::InitializeUI()
{
    if (TTF_Init() != 0)
    {
        std::cout << "Failed to initialize SDL_ttf!" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void UIManager::UpdateUI(SDL_Event* ev)
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

    // Update Buttons
    for (auto& button : m_TrackedButtons)
    {
        button->isMouseOver = false;
        button->wasClicked = false;

        int x = button->GetX();
        int y = button->GetY();
        int width = button->GetWidth();
        int height = button->GetHeight();

        if (mx > x && mx < x + width && my > y && my < y + height)
        {
            button->isMouseOver = true;

            if (MouseManager::IsMouseButtonPressed(SDL_BUTTON_LEFT))
            {
                button->wasClicked = true;
            }
        }
        else {
            button->isMouseOver = false;
        }
    }

    // Update Input Boxes
    for (auto& inputBox : m_TrackedInputBoxes)
    {
        inputBox->Update(ev);
    }
}

void UIManager::AddButton(Button* button)
{
    m_TrackedButtons.push_back(button);
}

void UIManager::AddInputBox(InputBox* inputBox)
{
    m_TrackedInputBoxes.push_back(inputBox);
}

void UIManager::ClearButtons()
{
    m_TrackedButtons.clear();
}

void UIManager::ClearUI()
{
    m_TrackedButtons.clear();
    m_TrackedInputBoxes.clear();
}
