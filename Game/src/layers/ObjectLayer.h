#include "src/layers/Layer.h"
#include "../objects/Coin.h"
#include "../objects/Spike.h"
#include "../objects/Saw.h"
#include "../objects/Objects.h"
#include <iostream>
#include <vector>

class ObjectLayer : public Layer
{
private:
	static constexpr int m_NumCoins = 16;
	static constexpr int m_NumSpikes = 8;

	std::vector<Coin*> m_Coins;
	std::vector<Spike*> m_Spikes;
	std::vector<Saw*> m_Saws;

public:
	ObjectLayer(const std::string& layerName, SDL_Renderer* renderer);
	~ObjectLayer();
	
	void AddCoins();
	void AddSpikes();
	void AddSaws();

	void Update() override;
	void Render() override;

	inline std::vector<Coin*>& GetCoins() { return m_Coins; }
	inline std::vector<Spike*>& GetSpikes() { return m_Spikes; }
	inline std::vector<Saw*>& GetSaws() { return m_Saws; }
};