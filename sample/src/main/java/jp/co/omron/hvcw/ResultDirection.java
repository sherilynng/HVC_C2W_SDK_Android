/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015 by OMRON Corporation                           */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/
package jp.co.omron.hvcw;

/**
 * 方向
 */
public final class ResultDirection
{
	/** 左右方向 */
	private int nLR;
	/** 上下方向 */
	private int nUD;
	/** 回転方向 */
	private int nRoll;
	/** 信頼度 */
	private int nConfidence;

	/**
	 * コンストラクタ
	 */
	public ResultDirection()
	{
		this.nLR   = 0;
		this.nUD   = 0;
		this.nRoll = 0;
		this.nConfidence = 0;
	}

	/**
	 * コンストラクタ
	 * @param nLR 左右方向
	 * @param nUD 上下方向
	 * @param nRoll 回転方向
	 * @param nConfidence 信頼度
	 */
	public ResultDirection(int nLR, int nUD, int nRoll, int nConfidence)
	{
		this.nLR   = nLR;
		this.nUD   = nUD;
		this.nRoll = nRoll;
		this.nConfidence = nConfidence;
	}

	/**
	 * 左右方向の取得
	 * @return 左右方向
	 */
	public int getLR()
	{
		return this.nLR;
	}

	/**
	 * 上下方向の取得
	 * @return 上下方向
	 */
	public int getUD()
	{
		return this.nUD;
	}

	/**
	 * 回転方向の取得
	 * @return 回転方向
	 */
	public int getRoll()
	{
		return this.nRoll;
	}

	/**
	 * 信頼度の取得
	 * @return 信頼度
	 */
	public int getConfidence()
	{
		return this.nConfidence;
	}

	/**
	 * 左右方向の設定
	 * @param nLR 左右方向
	 */
	public void setLR(int nLR)
	{
		this.nLR = nLR;
	}

	/**
	 * 上下方向の設定
	 * @param nUD 上下方向
	 */
	public void setUD(int nUD)
	{
		this.nUD = nUD;
	}

	/**
	 * 回転方向の設定
	 * @param nRoll 回転方向
	 */
	public void setRoll(int nRoll)
	{
		this.nRoll = nRoll;
	}

	/**
	 * 信頼度の設定
	 * @param nConfidence 信頼度
	 */
	public void setConfidence(int nConfidence)
	{
		this.nConfidence = nConfidence;
	}
}
